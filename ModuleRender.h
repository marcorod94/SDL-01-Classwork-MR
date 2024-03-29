#ifndef ModuleRender_h
#define ModuleRender_h

#include "Module.h"
#include "Globals.h"

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section);

	SDL_Renderer* renderer = nullptr;
};

#endif
