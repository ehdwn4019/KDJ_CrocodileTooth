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
		
	//이곳에 변수 선언
	RECT _rc;//위에
	RECT _rc1;//옆에
	RECT _rc2;//아래
	RECT _rc3;//입안
	RECT _rc4[10];//윗니
	//RECT _rc5[5];//아랫니
	int x, y,z; //눈 색깔 
	RECT temp; //충돌 교집합 임시 변수
	int find[10]; //정답 
	string str[20];
	int q, w;
	int r, g, b;
	bool touch;

public:
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	//이곳에 함수 선언

	mainGame() {}
	~mainGame() {}
};

