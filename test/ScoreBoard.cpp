#include "ScoreBoard.h"
#include "CursorManager.h"
#include "Stage.h"
#include "Player.h"
#include "SceneManager.h"

ScoreBoard::ScoreBoard() { }
ScoreBoard::ScoreBoard(Transform _TransInfo) { }
ScoreBoard::~ScoreBoard() { }

void ScoreBoard::Initialize()
{
	strKey = "ScoreBoard";

	sSwitch = SceneManager::GetInstance()->SceneSwitch;

	pPosition = Vector3(13.0f, 3.0f);

}

int ScoreBoard::Update()
{

	if (sSwitch == 1)
		nPlayer -= 1;

	return 0;
}

void ScoreBoard::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		3.0f, 3.0f, (char*)"Player: ", 15);
	CursorManager::GetInstance()->WriteBuffer(
		3.0f, 5.0f, (char*)"Cubes: ", 15);
	CursorManager::GetInstance()->WriteBuffer(
		3.0f, 7.0f, (char*)"Score: ", 15);

}

void ScoreBoard::Release()
{
}
