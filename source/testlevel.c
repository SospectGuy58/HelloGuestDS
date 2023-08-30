#include <NEMain.h>
#include "testlevel.h"

#include "ground_bin.h"
#include "grass_tex_bin.h"
#include "button_tex_bin.h"
#include "button_pal_bin.h"

NE_Camera *MainCamera;
NE_Model *Landscape;
NE_Material *Mat_Grass;

void TestLevel_Load() {
    // Allocation
    MainCamera = NE_CameraCreate();
    Landscape = NE_ModelCreate(NE_Static);
    Mat_Grass = NE_MaterialCreate();

    // Loading
    NE_ModelLoadStaticMesh(Landscape, (u32 *)ground_bin);
    NE_MaterialTexLoad(Mat_Grass, NE_RGB5, 64, 64,
                       NE_TEXGEN_TEXCOORD | NE_TEXTURE_WRAP_S | NE_TEXTURE_WRAP_T,
                       (u8 *)grass_tex_bin);

    // Setups
    NE_CameraSet(MainCamera,
                 1, 0.3, 0,
                 0, 0.3, 0,
                 0, 1, 0);
    NE_ClippingPlanesSet(0.02, 5000);
    NE_ModelSetMaterial(Landscape, Mat_Grass);
    NE_LightSet(0, NE_White, 0, 0, 1);
}

void TestLevel_DrawMain() {
    NE_CameraUse(MainCamera);
    NE_ModelDraw(Landscape);
}

void TestLevel_DrawSub() {
    
}

void TestLevel_Update(uint32 keys) {
    /*
        Freecam
    */
    // Movement
    if (keys & KEY_UP)
        NE_CameraMoveFreeI(MainCamera, 10, 0, 0);
    if (keys & KEY_DOWN)
        NE_CameraMoveFreeI(MainCamera, -10, 0, 0);
    if (keys & KEY_RIGHT)
        NE_CameraMoveFreeI(MainCamera, 0, 10, 0);
    if (keys & KEY_LEFT)
        NE_CameraMoveFreeI(MainCamera, 0, -10, 0);
    if (keys & KEY_L)
        NE_CameraMoveFreeI(MainCamera, 0, 0, -10);
    if (keys & KEY_R)
        NE_CameraMoveFreeI(MainCamera, 0, 0, 10);
    // Rotation
    if (keys & KEY_X)
        NE_CameraRotateFree(MainCamera, -1, 0, 0);
    if (keys & KEY_B)
        NE_CameraRotateFree(MainCamera, 1, 0, 0);
    if (keys & KEY_A)
        NE_CameraRotateFree(MainCamera, 0, 1, 0);
    if (keys & KEY_Y)
        NE_CameraRotateFree(MainCamera, 0, -1, 0);
}

void TestLevel_Unload() {
    NE_CameraDelete(MainCamera);
    NE_ModelDelete(Landscape);
    NE_MaterialDelete(Mat_Grass);
}