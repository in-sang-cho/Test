#pragma once
#include "UserInterface.h"

class Object;
class ScoreBoard : public UserInterface
{
private:
	Object* pPlayer;
	Vector3 pPosition;
	Vector3 cPosition;
	Vector3 sPosition;

	int nPlayer = 3;
	int nScore = 0;
	int nCube = 0;

	bool sSwitch;

public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	ScoreBoard();
	ScoreBoard(Transform _TransInfo);
	virtual ~ScoreBoard();
};

