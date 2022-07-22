#pragma once
#include "Scene.h"

class Ready : public Scene
{
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public:
	Ready();
	virtual ~Ready();
};
