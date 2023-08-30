#include <NEMain.h>
#include "level.h"

HG_Level *CurrentLevel = NULL;

HG_Level *HG_CreateLevel(char *name, void *load, void *drawMain, void *drawSub, void *update, void *unload) {
    HG_Level *level = calloc(1, sizeof(HG_Level));
    level->name = name;
    level->load = load;
    level->drawMain = drawMain;
    level->drawSub = drawSub;
    level->update = update;
    level->unload = unload;
    level->loaded = 0;

    return level;
}

void HG_LevelLoad(HG_Level *level) {
    if (level == NULL)
    {
        printf("Cannot load null level!\n");
        return;
    }

    if (CurrentLevel != NULL)
        HG_LevelUnload();
    
    printf("Loading level %s\n", level->name);
    CurrentLevel = level;
    CurrentLevel->load();
    CurrentLevel->loaded = 1;
    printf("Loaded level %s\n", level->name);
}

void HG_LevelDrawMain() {
    if (CurrentLevel && CurrentLevel->loaded)
        CurrentLevel->drawMain();
}

void HG_LevelDrawSub() {
    if (CurrentLevel && CurrentLevel->loaded)
        CurrentLevel->drawSub();
}

void HG_LevelUpdate(uint32 keys) {
    if (CurrentLevel && CurrentLevel->loaded)
        CurrentLevel->update(keys);
}

void HG_LevelUnload() {
    if (CurrentLevel == NULL) {
        printf("No level to unload!\n");
        return;
    }

    printf("Unloading level %s\n", CurrentLevel->name);
    CurrentLevel->loaded = 0;
    CurrentLevel->unload();
    printf("Unloaded level %s\n", CurrentLevel->name);
    CurrentLevel = NULL;
}