#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleTextures.h"
#include "ModuleScene.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"

ModuleScene::ModuleScene() {
}

ModuleScene::~ModuleScene() {
}

bool ModuleScene::Init() {
	return true;
}

update_status ModuleScene::Update() {
	if (texture == nullptr) {
		texture = App->textures->Load("sprites.png");
		if (texture == nullptr) {
			return UPDATE_ERROR;
		}
	}
	App->audio->PlayMusic("beat.wav");
	SDL_RenderCopy(App->renderer->renderer, texture, NULL, NULL);
	return UPDATE_CONTINUE;
}

bool ModuleScene::CleanUp() {
	return false;
}
