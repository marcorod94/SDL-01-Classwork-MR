#ifndef ModuleScene_h
#define ModuleScene_h
#include "Module.h"
#include "Globals.h"
class ModuleScene : public Module
{
public:

	ModuleScene();
	~ModuleScene();

	bool Init();
	update_status Update();
	bool CleanUp();
private :
	SDL_Texture* texture = nullptr;
};
#endif
