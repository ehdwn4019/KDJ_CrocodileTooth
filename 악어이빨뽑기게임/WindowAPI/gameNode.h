#pragma once

class gameNode
{
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	LRESULT CALLBACK MainProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	gameNode() {}
	virtual ~gameNode() {}
};

