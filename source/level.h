#ifndef HELLOGUEST_LEVEL_H
#define HELLOGUEST_LEVEL_H

typedef struct {
    char *name;
    void (*load) (void);
    void (*drawMain) (void);
    void (*drawSub) (void);
    void (*update) (uint32);
    void (*unload) (void);
    int loaded;
}HG_Level;

extern HG_Level *CurrentLevel;

extern HG_Level *HG_CreateLevel(char *name, void *load, void *drawMain, void *drawSub, void *update, void *unload);
extern void HG_LevelLoad(HG_Level *level);
extern void HG_LevelDrawMain();
extern void HG_LevelDrawSub();
extern void HG_LevelUpdate(uint32 keys);
extern void HG_LevelUnload();

#endif // HELLOGUEST_LEVEL_H