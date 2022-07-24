#include "Headers.h"
#include "MainUpdate.h"

int main()
{
	system("title Cube Rush");

	system("mode con cols=120 lines=30");

	MainUpdate Main;
	Main.Initialize();	// 초기화(부르고 나면 끝)

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			Main.Update();	//갱신
			Main.Render();	//그리기
		}
	}

	return 0;
}