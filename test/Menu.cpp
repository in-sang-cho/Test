#include "Menu.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "CursorManager.h"

Menu::Menu() { }
Menu::~Menu() { }

void Menu::Initialize()
{
}

void Menu::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_ENTER)
		SceneManager::GetInstance()->SetScene(SCENEID::READY);
}

void Menu::Render()
{
	CursorManager::GetInstance()->WriteBuffer(0.0f, 6.0f, (char*)"  :::::::::  :::::::::  :::::::::: ::::::::   ::::::::       :::::::::: ::::    ::: ::::::::::: :::::::::: :::::::::   ");
	CursorManager::GetInstance()->WriteBuffer(0.0f, 7.0f, (char*)"  :+:    :+: :+:    :+: :+:       :+:    :+: :+:    :+:      :+:        :+:+:   :+:     :+:     :+:        :+:    :+:  ");
	CursorManager::GetInstance()->WriteBuffer(0.0f, 8.0f, (char*)"  +:+    +:+ +:+    +:+ +:+       +:+        +:+             +:+        :+:+:+  +:+     +:+     +:+        +:+    +:+  ");
	CursorManager::GetInstance()->WriteBuffer(0.0f, 9.0f, (char*)"  +#++:++#+  +#++:++#:  +#++:++#  +#++:++#++ +#++:++#++      +#++:++#   +#+ +:+ +#+     +#+     +#++:++#   +#++:++#:   ");
	CursorManager::GetInstance()->WriteBuffer(0.0f, 10.0f, (char*)"  +#+        +#+    +#+ +#+              +#+        +#+      +#+        +#+  +#+#+#     +#+     +#+        +#+    +#+  ");
	CursorManager::GetInstance()->WriteBuffer(0.0f, 11.0f, (char*)"  #+#        #+#    #+# #+#       #+#    #+# #+#    #+#      #+#        #+#   #+#+#     #+#     #+#        #+#    #+#  ");
	CursorManager::GetInstance()->WriteBuffer(0.0f, 12.0f, (char*)"  ###        ###    ### ########## ########   ########       ########## ###    ####     ###     ########## ###    ###  ");
	CursorManager::GetInstance()->WriteBuffer(56.0f, 19.0f, (char*)"  EXIT  ");
}

void Menu::Release()
{
}