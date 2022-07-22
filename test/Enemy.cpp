#include "Enemy.h"
#include "CursorManager.h"

Enemy::Enemy() { }
Enemy::Enemy(Transform _TransInfo) { }
Enemy::~Enemy() { }

void Enemy::Initialize()
{
	strKey = "Enemy";

	Buffer[0] = (char*)"бр";

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Rotation = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(2.0f, 1.0f);
}

int Enemy::Update()
{
	TransInfo.Position.x -= 2;

	if (TransInfo.Position.x <= 23)
	{
		srand(29);
		TransInfo.Position.x = 119;
		TransInfo.Position.x -= 2;
		for (int i = 0; i < 30; ++i)
		{
			if (TransInfo.Position.x <= 23)
				TransInfo.Position.y = rand() % i;
		}
	}

	return 0;
}

void Enemy::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		TransInfo.Position, Buffer[0], 15);
}

void Enemy::Release()
{
}