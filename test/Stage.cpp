#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "MainBoard.h"
#include "ScoreBoard.h"
#include "SceneManager.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"
#include "ObjectFactory.h"

Stage::Stage() : Check(0) { }
Stage::~Stage() { Release(); }

void Stage::Initialize()
{
	Check = 0;

	Object* pEnemyProto = ObjectFactory<Enemy>::CreateObject();

	pUI1 = new MainBoard;
	pUI1->Initialize();
	pUI2 = new ScoreBoard;
	pUI2->Initialize();

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			Object* pEnemy = pEnemyProto->Clone();
			srand(DWORD(GetTickCount64() * (i + 1)));
			pEnemy->SetPosition(float(rand() % 25 + 90), float(rand() % 30));
			ObjectManager::GetInstance()->AddObject(pEnemy);
		}
	}
}

void Stage::Update()
{

	Enable_UI();

	ObjectManager::GetInstance()->Update();

	Object* pPlayer = ObjectManager::GetInstance()->GetObjectList("Player")->front();
	list<Object*>* pEnemyList = ObjectManager::GetInstance()->GetObjectList("Enemy");

	if (pPlayer != nullptr)
	{
		if (pEnemyList != nullptr)
		{
			for (list<Object*>::iterator Enemyiter = pEnemyList->begin();
				Enemyiter != pEnemyList->end(); ++Enemyiter)
			{
				if (CollisionManager::Collision(pPlayer, *Enemyiter) || pPlayer->GetPosition().x <= 22)
				{
					pUI1 = new MainBoard;
					pUI2 = new ScoreBoard;

					SceneManager::GetInstance()->SetScene(SCENEID::READY);

					CursorManager::GetInstance()->ClearBuffer();
				}
			}
		}
	}

	if (Check)
	{
		pUI1->Update();
		pUI2->Update();
	}
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();

	if (Check)
	{
		pUI1->Render();
		pUI2->Render();
	}
}

void Stage::Release()
{

}

void Stage::Enable_UI()
{
	if (!Check)
		Check = !Check;
}
