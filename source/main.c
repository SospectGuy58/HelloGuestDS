// SPDX-License-Identifier: CC0-1.0
//
// SPDX-FileContributor: Antonio Niño Díaz, 2008-2011, 2019, 2022-2023
//
// This file is part of Nitro Engine

#include <NEMain.h>
#include "level.h"
#include "levels/menulevel.h"
#include "levels/testlevel.h"

HG_Level *MenuLevel;
HG_Level *TestLevel;

void DrawScreenMain(void)
{
    HG_LevelDrawMain();
}

void DrawScreenSub(void)
{
    HG_LevelDrawSub();
}

int main(void)
{
    irqEnable(IRQ_HBLANK);
    irqSet(IRQ_VBLANK, NE_VBLFunc);
    irqSet(IRQ_HBLANK, NE_HBLFunc);

	/*
		Init
	*/
    NE_InitDual3D();
    NE_MainScreenSetOnBottom();
	// NE_InitConsole();

    /*
        Levels
    */
    MenuLevel = HG_CreateLevel("menulevel", MenuLevel_Load, MenuLevel_DrawMain, MenuLevel_DrawSub, MenuLevel_Update, MenuLevel_Unload);
    TestLevel = HG_CreateLevel("testlevel", TestLevel_Load, TestLevel_DrawMain, TestLevel_DrawSub, TestLevel_Update, TestLevel_Unload);
	
    HG_LevelLoad(MenuLevel);

    while (1)
    {
        NE_WaitForVBL(NE_UPDATE_GUI);

        scanKeys();
        uint32 keys = keysHeld();

        HG_LevelUpdate(keys);

        NE_ProcessDual(DrawScreenMain, DrawScreenSub);
    }

    return 0;
}
