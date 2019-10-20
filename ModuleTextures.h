#ifndef ModuleTextures_h
#define ModuleTextures_h

#include<list>
#include "Module.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleTextures : public Module
{
public:
	ModuleTextures();
	~ModuleTextures();

	bool Init();
	bool CleanUp();

	SDL_Texture* const Load(const char* path);

private:
	std::list<SDL_Texture*> textures;
};

#endif
