#ifndef HELLOGUEST_TESTLEVEL_H
#define HELLOGUEST_TESTLEVEL_H

#include <NEMain.h>

extern NE_Camera *MainCamera;
extern NE_Model *Landscape;
extern NE_Material *Mat_Grass;

extern void TestLevel_Load();
extern void TestLevel_DrawMain();
extern void TestLevel_DrawSub();
extern void TestLevel_Update(uint32 keys);
extern void TestLevel_Unload();

#endif // HELLOGUEST_TESTLEVEL_H