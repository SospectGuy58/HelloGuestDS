#include <NEMain.h>
#include "menulevel.h"
#include "level.h"
#include "main.h"

#include "logo_tex_bin.h"
#include "logo_pal_bin.h"
#include "button_tex_bin.h"
#include "button_pal_bin.h"
#include "menu_pl_top_tex_bin.h"
#include "menu_pl_bottom_tex_bin.h"
#include "menu_pl_top_pal_bin.h"
#include "menu_pl_bottom_pal_bin.h"

NE_Camera *Camera;
NE_Sprite *LogoSprite, *MenuTopSprite, *MenuBottomSprite;
NE_Material *LogoMaterial, *ButtonMaterial, *MenuTopMaterial, *MenuBottomMaterial;
NE_Palette *LogoPalette, *ButtonPalette, *MenuTopPalette, *MenuBottomPalette;
NE_GUIObj *Button;

void MenuLevel_Load() {
    /*
        Allocation
    */
    Camera = NE_CameraCreate();

    // Logo
    LogoSprite = NE_SpriteCreate();
    LogoMaterial = NE_MaterialCreate();
    LogoPalette = NE_PaletteCreate();

    // MenuTopSprite
    MenuTopSprite = NE_SpriteCreate();
    MenuTopMaterial = NE_MaterialCreate();
    MenuTopPalette = NE_PaletteCreate();

    // MenuBottomSprite
    MenuBottomSprite = NE_SpriteCreate();
    MenuBottomMaterial = NE_MaterialCreate();
    MenuBottomPalette = NE_PaletteCreate();

    // Button
    Button = NE_GUIButtonCreate(0, 192 - 64, 64, 192);
    ButtonMaterial = NE_MaterialCreate();
    ButtonPalette = NE_PaletteCreate();

    /*
        Loading
    */
    // LogoMaterial & MaterialPalette
    NE_MaterialTexLoad(LogoMaterial, NE_PAL16, 128, 128, NE_TEXGEN_TEXCOORD,
                       (void *)logo_tex_bin);
    NE_PaletteLoad(LogoPalette, (void *)logo_pal_bin, 16, NE_PAL16);

    // MenuTopMaterial & MenuTopPalette
    NE_MaterialTexLoad(MenuTopMaterial, NE_PAL256, 256, 256, NE_TEXGEN_TEXCOORD,
                       (void *)menu_pl_top_tex_bin);
    NE_PaletteLoad(MenuTopPalette, (void *)menu_pl_top_pal_bin, 256, NE_PAL256);

    // MenuBottomMaterial && MenuBottomPalette
    NE_MaterialTexLoad(MenuBottomMaterial, NE_PAL256, 256, 256, NE_TEXGEN_TEXCOORD,
                       (void *)menu_pl_bottom_tex_bin);
    NE_PaletteLoad(MenuBottomPalette, (void *)menu_pl_bottom_pal_bin, 256, NE_PAL256);

    // ButtomMaterial & ButtonPalette
    NE_MaterialTexLoad(ButtonMaterial, NE_PAL256, 64, 64,
                       NE_TEXGEN_TEXCOORD | NE_TEXTURE_COLOR0_TRANSPARENT,
                       (void *)button_tex_bin);
    NE_PaletteLoad(ButtonPalette, (void *)button_pal_bin, 256, NE_PAL256);

    /*
        Setups
    */
    // Camera
    NE_CameraSetI(Camera,
                  0, 0, 0,
                  1, 0, 0, 
                  0, 1, 0);
    NE_ClippingPlanesSet(10, 10000);

    // LogoSprite
    NE_MaterialSetPalette(LogoMaterial, LogoPalette);
    NE_SpriteSetMaterial(LogoSprite, LogoMaterial);
    NE_SpriteSetPos(LogoSprite, 256 / 2 - 108 / 2, 192 / 2 - 128 / 2);
    NE_SpriteSetSize(LogoSprite, 128, 128);

    // MenuTopSprite
    NE_MaterialSetPalette(MenuTopMaterial, MenuTopPalette);
    NE_SpriteSetMaterial(MenuTopSprite, MenuTopMaterial);
    NE_SpriteSetSize(MenuTopSprite, 256, 256);

    // MenuBottomSprite
    NE_MaterialSetPalette(MenuBottomMaterial, MenuBottomPalette);
    NE_SpriteSetMaterial(MenuBottomSprite, MenuBottomMaterial);
    NE_SpriteSetSize(MenuBottomSprite, 256, 256);

    // Button
    NE_MaterialSetPalette(ButtonMaterial, ButtonPalette);
    NE_GUIButtonConfig(Button,
                       ButtonMaterial, NE_White, 31,
                       ButtonMaterial, NE_Blue, 25);
}

void MenuLevel_DrawMain() {
    NE_2DViewInit();
    NE_SpriteDraw(MenuTopSprite);
}

void MenuLevel_DrawSub() {
    NE_2DViewInit();
    NE_GUIDraw();
    NE_SpriteDraw(MenuBottomSprite);
}

void MenuLevel_Update(uint32 keys) {
    if (NE_GUIObjectGetEvent(Button))
        HG_LevelLoad(TestLevel);
}

void MenuLevel_Unload() {
    NE_CameraDelete(Camera);
    NE_SpriteDelete(LogoSprite);
    NE_GUIDeleteObject(Button);
    NE_MaterialDelete(LogoMaterial);
    NE_PaletteDelete(LogoPalette);
    NE_MaterialDelete(ButtonMaterial);
    NE_PaletteDelete(ButtonPalette);
}