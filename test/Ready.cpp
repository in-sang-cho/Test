#include "Ready.h"
#include "Stage.h"
#include "Player.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"

Ready::Ready() { }
Ready::~Ready() { }

void Ready::Initialize()
{
}

void Ready::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	

	if (dwKey & KEY_ENTER)
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
}

void Ready::Render()
{
	CursorManager::GetInstance()->WriteBuffer(0.0f, 6.0f, (char*)" Ready ");
}

void Ready::Release()
{
}
