#include "MainBoard.h"
#include "CursorManager.h"

MainBoard::MainBoard() { }
MainBoard::MainBoard(Transform _TransInfo) { }
MainBoard::~MainBoard() { }

int TextureSize = 30;

void MainBoard::Initialize()
{
	strKey = "MainBoard";
}

int MainBoard::Update()
{


	return 0;
}

void MainBoard::Render()
{
	for (int i = 0; i < 30; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(
			20.0f, (float)i, (char*)"¦¢", 15);
	}
}

void MainBoard::Release()
{
	
}