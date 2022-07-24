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

/*
1) 전체적인 구조를 파악할 것 ★★★★★
	 - 함수 실행이 끝나면 다시 있던 자리로 돌아간다 ☆

2) class Scene;
원래대로라면 Scene이라는 클래스를 정의해줘야 되는데 이거는 있다고만 치는거.
따라서 얘 혼자로는 힘들고, 다른 클래스에서 정의를 내려줘야 함
Scene* SceneState; 이거처럼.
나중에 Scene class를 부모로 가지고 있는 자식 Class를 만났을 때
있다고 치는게 진짜 있네? 하면서 해당 자식 Class랑 합체를 한다.

3) vector, list, map
vector: 주소값이 뭉탱이로 묶여있다. 따라서 뭉탱이로 넣고 빼기 편하지만, 각 데이터를 넣거나 빼기 어렵다
list: [주소-데이터-다음 주소] 구조로 기차처럼 연결되어 있으며 각 데이터를 넣고 빼기 편하다
map: list랑 비슷하나, key 라는 마스터키를 가지고 있다. key 값을 find 하면 해당 데이터를 들고올 수 있다

4) iterator
뭐 할거야. 근데 내가 다음 명령을 받기 전까지는 몰라.
그래서 = 뒤에 진짜 명령을 내릴 것을 넣어서 얘를 활성화시킨다.

*/