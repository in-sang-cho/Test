#include "SceneManager.h"
#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "Ready.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr) { }
SceneManager::~SceneManager() { Release(); }


void SceneManager::SetScene(SCENEID _SceneState)
{
	if (SceneState != nullptr)
		::Safe_Delete(SceneState);

	switch (_SceneState)
	{
	case SCENEID::LOGO:
		SceneState = new Logo;
		break;
	case SCENEID::MENU:
		SceneState = new Menu;
		break;
	case SCENEID::STAGE:
		SceneState = new Stage;
		SceneSwitch = 0;
		break;
	case SCENEID::READY:
		SceneState = new Ready;
		SceneSwitch = 1;
		break;
	case SCENEID::EXIT:
		exit(NULL);
		break;
	}
	SceneState->Initialize();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{
}