#pragma once
#include "Scene.h"

class Object;
class UserInterface;
class Stage : public Scene
{
private:
	UserInterface* pUI1;
	UserInterface* pUI2;
	int Check;

	Object* pPlayer;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	void Enable_UI();

public:
	Stage();
	virtual ~Stage();
};

