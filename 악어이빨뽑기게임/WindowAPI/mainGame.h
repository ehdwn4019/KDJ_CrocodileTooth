#pragma once
#include "gameNode.h"

class mainGame : public gameNode
{
private:
	HWND hwnd;
	HDC hdc;
	HBRUSH hbr;
	HBRUSH brush;
	HBRUSH brush1;
	HBRUSH brush2;
	HBRUSH brush3;
		
	//�̰��� ���� ����
	RECT _rc;//����
	RECT _rc1;//����
	RECT _rc2;//�Ʒ�
	RECT _rc3;//�Ծ�
	RECT _rc4[10];//����
	//RECT _rc5[5];//�Ʒ���
	int x, y,z; //�� ���� 
	RECT temp; //�浹 ������ �ӽ� ����
	int find[10]; //���� 
	string str[20];
	int q, w;
	int r, g, b;
	bool touch;

public:
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	//�̰��� �Լ� ����

	mainGame() {}
	~mainGame() {}
};

