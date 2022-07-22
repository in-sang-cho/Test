#include "Player.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "CursorManager.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

Player::Player() { }
Player::Player(Transform _TransInfo) : Object(_TransInfo) { }
Player::~Player() {}

void Player::Initialize()
{
	strKey = "Player";

	Buffer[0] = (char*)"¦£¦¨¡£";
	Buffer[1] = (char*)"¢²¦ª¡õ";

	TransInfo.Position = Vector3(30.0f, 15.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(6.0f, 2.0f);

	Color = 15;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
		TransInfo.Position.y -= 1;
	if (dwKey & KEY_DOWN)
		TransInfo.Position.y += 1;
	if (dwKey & KEY_LEFT)
		TransInfo.Position.x -= 2;
	if (dwKey & KEY_RIGHT)
		TransInfo.Position.x += 2;

	return 0;
}

void Player::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		TransInfo.Position, Buffer[0], Color);
	CursorManager::GetInstance()->WriteBuffer(
		TransInfo.Position.x, TransInfo.Position.y + 1, Buffer[1], Color);
}

void Player::Release()
{
}