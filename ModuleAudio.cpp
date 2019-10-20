#include "ModuleAudio.h"
#include "SDL/include/SDL.h"

#include "SDL_mixer/include/SDL_mixer.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

ModuleAudio::ModuleAudio() {

}

ModuleAudio::~ModuleAudio() {

}

bool ModuleAudio::Init() {
	LOG("Init SDL audio system");
	bool ret = true;
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
		LOG("SDL_INIT_AUDIO could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
		LOG("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		ret = false;
	}

	return ret;
}

bool ModuleAudio::CleanUp() {
	LOG("Freeing sound FX, closing Mixer and Audio subsystem");

	if (music != nullptr) {
		Mix_FreeMusic(music);
	}

	Mix_CloseAudio();
	Mix_Quit();
	SDL_QuitSubSystem(SDL_INIT_AUDIO);
	return true;
}

bool ModuleAudio::PlayMusic(const char* path) {
	
	if (music == nullptr) {
		music = Mix_LoadMUS(path);

		if (music == nullptr) {
			LOG("Cannot load music %s. Mix_GetError(): %s\n", path, Mix_GetError());
			return false;
		}
	} else {
		if (Mix_PlayingMusic() == 0) {
			Mix_PlayMusic(music, -1);
			LOG("Successfully playing %s", path);
		}
	}
	return true;
}


