#pragma once
#include "UserInterface.h"

class MainBoard : public UserInterface
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	MainBoard();
	MainBoard(Transform _TransInfo);
	virtual ~MainBoard();
};

