#ifndef ModuleAudio_h
#define ModuleAudio_h

#include "Module.h"
#include "Globals.h"
#define DEFAULT_MUSIC_FADE_TIME 100.0f

typedef struct _Mix_Music Mix_Music;
class ModuleAudio : public Module
{
public:

	ModuleAudio();
	~ModuleAudio();
	bool Init();
	bool CleanUp();
	bool PlayMusic(const char*);
private:
	Mix_Music* music = nullptr;
};

#endif
