#ifndef HELLOGUEST_MENULEVEL_H
#define HELLOGUEST_MENULEVEL_H

#include <NEMain.h>

extern NE_Camera *Camera;
extern NE_Sprite *LogoSprite, *MenuTopSprite, *MenuBottomSprite;
extern NE_Material *LogoMaterial, *ButtonMaterial, *MenuTopMaterial, *MenuBottomMaterial;
extern NE_Palette *LogoPalette, *ButtonPalette, *MenuTopPalette, *MenuBottomPalette;
extern NE_GUIObj *Button;

extern void MenuLevel_Load();
extern void MenuLevel_DrawMain();
extern void MenuLevel_DrawSub();
extern void MenuLevel_Update(uint32 keys);
extern void MenuLevel_Unload();

#endif // HELLOGUEST_MENULEVEL_H