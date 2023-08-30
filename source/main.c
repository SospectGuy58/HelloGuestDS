#include <NEMain.h>
#include "level.h"
#include "menulevel.h"
#include "testlevel.h"

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
    NE_TextureSystemReset(0, 0, NE_VRAM_AB);
	NE_InitConsole();

    /*
        Level creation
    */
    MenuLevel = HG_CreateLevel("menulevel", MenuLevel_Load, MenuLevel_DrawMain, MenuLevel_DrawSub, MenuLevel_Update, MenuLevel_Unload);
    TestLevel = HG_CreateLevel("testlevel", TestLevel_Load, TestLevel_DrawMain, TestLevel_DrawSub, TestLevel_Update, TestLevel_Unload);
	
    /*
        Load initial level
    */
    HG_LevelLoad(MenuLevel);

    while (1)
    {
        NE_WaitForVBL(NE_UPDATE_GUI);

        scanKeys();
        uint32 keys = keysHeld();

        // Update current level
        HG_LevelUpdate(keys);

        NE_ProcessDual(DrawScreenMain, DrawScreenSub);
    }

    return 0;
}
