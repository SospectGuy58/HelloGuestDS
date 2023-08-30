#include <NEMain.h>
#include "menulevel.h"
#include "level.h"
#include "main.h"

#include "logo_tex_bin.h"
#include "logo_pal_bin.h"
#include "button_tex_bin.h"
#include "button_pal_bin.h"

NE_Camera *Camera;
NE_Sprite *LogoSprite;
NE_Material *LogoMaterial, *ButtonMaterial;
NE_Palette *LogoPalette, *ButtonPalette;
NE_GUIObj *Button;

void MenuLevel_Load() {
    // Allocation
    Camera = NE_CameraCreate();
    LogoSprite = NE_SpriteCreate();
    LogoMaterial = NE_MaterialCreate();
    LogoPalette = NE_PaletteCreate();
    ButtonMaterial = NE_MaterialCreate();
    ButtonPalette = NE_PaletteCreate();
    Button = NE_GUIButtonCreate(0, 192 - 64, 64, 192);

    // Loading
    NE_MaterialTexLoad(LogoMaterial, NE_PAL16, 128, 128, NE_TEXGEN_TEXCOORD,
                       (void *)logo_tex_bin);
    NE_PaletteLoad(LogoPalette, (void *)logo_pal_bin, 16, NE_PAL16);
    NE_MaterialTexLoad(ButtonMaterial, NE_PAL256, 64, 64,
                       NE_TEXGEN_TEXCOORD | NE_TEXTURE_COLOR0_TRANSPARENT,
                       (void *)button_tex_bin);
    NE_PaletteLoad(ButtonPalette, (void *)button_pal_bin, 256, NE_PAL256);

    // Setups
    NE_CameraSetI(Camera,
                  0, 0, 0,
                  1, 0, 0, 
                  0, 1, 0);
    NE_ClippingPlanesSet(10, 10000);
    NE_MaterialSetPalette(LogoMaterial, LogoPalette);
    NE_SpriteSetPos(LogoSprite, 256 / 2 - 108 / 2, 192 / 2 - 128 / 2);
    NE_SpriteSetSize(LogoSprite, 128, 128);
    NE_SpriteSetPriority(LogoSprite, 0);
    NE_SpriteSetMaterial(LogoSprite, LogoMaterial);
    NE_MaterialSetPalette(ButtonMaterial, ButtonPalette);
    NE_GUIButtonConfig(Button,
                       ButtonMaterial, NE_White, 31,
                       ButtonMaterial, NE_Blue, 25);
}

void MenuLevel_DrawMain() {
    NE_2DViewInit();
    NE_GUIDraw();
}

void MenuLevel_DrawSub() {
    NE_2DViewInit();
    NE_SpriteDraw(LogoSprite);
}

void MenuLevel_Update(uint32 keys) {
    if (NE_GUIObjectGetEvent(Button))
        HG_LevelLoad(TestLevel);
}

void MenuLevel_Unload() {
    NE_CameraDelete(Camera);
}