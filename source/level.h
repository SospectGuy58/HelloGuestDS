#ifndef HELLOGUEST_LEVEL_H
#define HELLOGUEST_LEVEL_H

// Level data
typedef struct {
    char *name;                 // Readable name
    void (*load) (void);        // Load function
    void (*drawMain) (void);    // Draw main screen function
    void (*drawSub) (void);     // Draw sub screen function
    void (*update) (uint32);    // Update function
    void (*unload) (void);      // Unload function
    int loaded;
}HG_Level;

// Currently loaded level
extern HG_Level *CurrentLevel;

// Creates level data
extern HG_Level *HG_CreateLevel(char *name, void *load, void *drawMain, void *drawSub, void *update, void *unload);
// Loads a level into the world, unloads previous level if it exists
extern void HG_LevelLoad(HG_Level *level);
// Draws the current level's main screen scene
extern void HG_LevelDrawMain();
// Draws the current level's sub screen scene
extern void HG_LevelDrawSub();
// Runs a level update, provides current input
extern void HG_LevelUpdate(uint32 keys);
// Unloads the currently loaded level
extern void HG_LevelUnload();

#endif // HELLOGUEST_LEVEL_H