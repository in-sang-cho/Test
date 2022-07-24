#include "Headers.h"
#include "MainUpdate.h"

int main()
{
	system("title Cube Rush");

	system("mode con cols=120 lines=30");

	MainUpdate Main;
	Main.Initialize();	// �ʱ�ȭ(�θ��� ���� ��)

	ULONGLONG Time = GetTickCount64();

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			Main.Update();	//����
			Main.Render();	//�׸���
		}
	}

	return 0;
}

/*
1) ��ü���� ������ �ľ��� �� �ڡڡڡڡ�
	 - �Լ� ������ ������ �ٽ� �ִ� �ڸ��� ���ư��� ��

2) class Scene;
������ζ�� Scene�̶�� Ŭ������ ��������� �Ǵµ� �̰Ŵ� �ִٰ� ġ�°�.
���� �� ȥ�ڷδ� �����, �ٸ� Ŭ�������� ���Ǹ� ������� ��
Scene* SceneState; �̰�ó��.
���߿� Scene class�� �θ�� ������ �ִ� �ڽ� Class�� ������ ��
�ִٰ� ġ�°� ��¥ �ֳ�? �ϸ鼭 �ش� �ڽ� Class�� ��ü�� �Ѵ�.

3) vector, list, map
vector: �ּҰ��� �����̷� �����ִ�. ���� �����̷� �ְ� ���� ��������, �� �����͸� �ְų� ���� ��ƴ�
list: [�ּ�-������-���� �ּ�] ������ ����ó�� ����Ǿ� ������ �� �����͸� �ְ� ���� ���ϴ�
map: list�� ����ϳ�, key ��� ������Ű�� ������ �ִ�. key ���� find �ϸ� �ش� �����͸� ���� �� �ִ�

4) iterator
�� �Ұž�. �ٵ� ���� ���� ����� �ޱ� �������� ����.
�׷��� = �ڿ� ��¥ ����� ���� ���� �־ �긦 Ȱ��ȭ��Ų��.

*/