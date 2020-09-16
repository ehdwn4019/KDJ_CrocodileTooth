#include "stdafx.h"
#include "mainGame.h"

//=============================================================
//	## 초기화 ## init()
//=============================================================
HRESULT mainGame::init()
{
	gameNode::init();
	//이곳에서 초기화를 한다
	//Random.Range(,) => 유니티엔진

	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		find[i] = i;
	}
	
	for (int i = 0; i < 100; i++)
	{
		int index1 = rand() % 10;
		int index2 = rand() % 10;
		int temp = find[index1];
		find[index1] = find[index2];
		find[index2] = temp;
	}
	//사각형의 위치를 랜덤하게
	//_rc = RectMakeCenter(
	//	RANDOM->Range(100, WINSIZEX - 100),
	//	RANDOM->Range(100, WINSIZEY - 100),
	//	100, 100);
	//EllipseMake(hdc, 100, 100, 100, 100);

	x = 255;
	y = 0;
	z = 0;
	
	
	_rc3 = RectMake(50, 150, 600, 450);


	//이빨
	for (int i = 0; i < 5; i++)
	{
		_rc4[i] = RectMake(70 + i * 110, 150, 100, 100);
		
		//if (_rc4[i].right >= _rc3.right)
		//{
		//	_rc4[i] = RectMake(-478 + i * 110, 500, 100, 100);
		//	touch = false;
		//}
	}

	for (int i = 5; i < 10; i++)
	{
		_rc4[i] = RectMake(-475 + i * 110, 500, 100, 100);
	}

	_rc = RectMake(50, 50, 700, 100);
	_rc1 = RectMake(650, 150, 100, 450);
	_rc2 = RectMake(50, 600, 700, 100);

	
	
	brush2 = CreateSolidBrush(RGB(x, y, z));
	brush1 = CreateSolidBrush(RGB(0,0,0));
	brush3 = CreateSolidBrush(WHITE_BRUSH);

	
	

	return S_OK;
}

//=============================================================
//	## 해제 ## release()
//=============================================================
void mainGame::release()
{
	gameNode::release();
	//이미지 클래스를 나갈때까진 사용할 일 없다
	//동적할당 new를 사용했다면 이곳에서 SAFE_DELETE() 사용한다
}

//=============================================================
//	## 업데이트 ## update()
//=============================================================
void mainGame::update()
{
	gameNode::update();
	//이곳에서 계산식, 키보드, 마우스등등 업데이트를 한다
	//간단하게 이곳에서 코딩한다고 생각하면 된다
	//충돌처리
	
	
	if (INPUT->GetKeyDown(VK_LBUTTON))
	{

		
		

		for (int i = 0; i < 5; i++)
		{
			touch = true;
			if (PtInRect(&_rc4[i], _ptMouse) && touch == true)
			{
				
				_rc4[i].bottom -= 70;

				if (_rc4[i].bottom <= _rc3.top)
				{
					_rc4[i].bottom = _rc3.top+30;
					_rc4[i].top = _rc3.top;
				}
				//_rc4[i].top -= 20;

				
				
			}
			//else if (PtInRect(&_rc4[i], _ptMouse) && _rc4[i].top <=130)
			//{
			//	_rc4[i].bottom += 20;
			//	_rc4[i].top += 20;
			//}
			//touch = false;
			//
			//if (touch == false)
			//{
			//	_rc4[i].bottom = _rc4[i].bottom;
			//	_rc4[i].top = _rc4[i].top;
			//}
		}

		for (int i = 5; i < 10; i++)
		{
			if (PtInRect(&_rc4[i], _ptMouse) && touch == true)
			{
				//_rc4[i].bottom += 20;
				_rc4[i].top += 70;

				if (_rc4[i].top >= _rc3.bottom)
				{
					_rc4[i].top = _rc3.bottom - 30;
					_rc4[i].bottom = _rc3.bottom;
				}
			}
		}

		
	
	}
	

	for (int i = 0; i < 10; i++)
	{
		if (PtInRect(&_rc4[i], _ptMouse) && find[i] == 1)
		{
			
		}
	}
	
	//for (int i = 0; i < 10; i++)
		//{
		//	if (PtInRect(&_rc4[i], _ptMouse) && touch==true)
		//	{
		//		_rc4[i].bottom -= 20;
		//		_rc4[i].top -= 20;
		//
		//		touch = false;
		//
		//		if (touch == false)
		//		{
		//			_rc4[i].bottom += 20;
		//			_rc4[i].top += 20;
		//		}
		//	
		//	}
		//
		//	touch = true;
		//
		//	if (PtInRect(&_rc4[i],_ptMouse) && touch == true && i>=5 &&i<=9 )
		//	{
		//		_rc4[5].bottom += 10;
		//		_rc4[5].top += 10;
		//	}
		//	
		//	
		//	
		//}
	

}

//=============================================================
//	## 렌더 ## render()
//=============================================================
void mainGame::render(HDC hdc)
{
	//이곳에서 WM_PAINT에서 했던것을 처리하면 된다
	
	//Rectangle(hdc, _rc);
	//
	
	
	//도형에 색칠하기
	brush = CreateSolidBrush(RGB(0, 200, 0));
	FillRect(hdc, &_rc, brush);
	FillRect(hdc, &_rc1, brush);
	FillRect(hdc, &_rc2, brush);

	HBRUSH old1 = (HBRUSH)SelectObject(hdc, brush2);
	Rectangle(hdc, _rc3);

	

	HBRUSH white = CreateSolidBrush(RGB(255,255,255));
	for (int i = 0; i < 5; i++)
	{
		FillRect(hdc, &_rc4[i], white);
	}

	for (int i = 5; i < 10; i++)
	{
		FillRect(hdc, &_rc4[i], white);
	}

	
	

   
	HBRUSH old = (HBRUSH)SelectObject(hdc, white);
	EllipseMake(hdc, 50, 50, 600, 70);

	HBRUSH old2 = (HBRUSH)SelectObject(hdc, brush1);
	EllipseMake(hdc, 250, 52, 20, 65);
	
	


	
	for (int i = 0; i < 10; i++)
	{
		if (PtInRect(&_rc4[i], _ptMouse) && find[i] == 1 )
		{
			if(INPUT->GetKey(VK_LBUTTON))
			{
				TextOut(hdc, 300, 300, "엌zzzzzzzzzzzzz", strlen("엌zzzzzzzzzzzzz"));
				
			}
			
			//TextOut(hdc, 300, 300, "엌zzzzzzzzzzzzz", strlen("엌zzzzzzzzzzzzz"));
			//MessageBox(hwnd, "엌zzzzzzzzzzzzz", "엌zzzzzzzzzzzzz", MB_OK);
			
		}
		
	}
	
	//TextOut(hdc, 300, 300, "엌zzzzzzzzzzzzz", strlen("엌zzzzzzzzzzzzz"));
	//MessageBox(hwnd, "엌zzzzzzzzzzzzz", "엌zzzzzzzzzzzzz", MB_OK);
	
	
	DeleteObject(brush);
	

	

}
