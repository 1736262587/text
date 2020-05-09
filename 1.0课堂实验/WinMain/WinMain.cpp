#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WinSunProc(
    HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
);
int WINAPI WinMain(
    HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow

)
{
//设计一个窗口类
	WNDCLASS wndcls;
	wndcls.cbClsExtra=0;
	wndcls.cbWndExtra=0;
	wndcls.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH);
	wndcls.hCursor=LoadCursor(NULL,IDC_CROSS);
	wndcls.hIcon=LoadIcon(NULL,IDI_ERROR);
	wndcls.hInstance=hInstance;
	wndcls.lpfnWndProc=WinSunProc;
	wndcls.lpszClassName="sunxin2006";
	wndcls.lpszMenuName=NULL;
	wndcls.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls);

	//创建窗口，定义一个变量用来保存成功创建窗口后返回的句柄
	HWND hwnd;
	hwnd=CreateWindow("sunxin2006","http://www.sunxin.org",WS_OVERLAPPEDWINDOW,0,0,600,400,NULL,NULL,hInstance,NULL);
	
	//显示及刷新窗口
	ShowWindow(hwnd,SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	//定义消息结构体，开始信息循环
	MSG msg;
	BOOL bRet;
	while((bRet=GetMessage(&msg,hwnd,0,0))!=0){
		if(bRet==-1){
		  return -1;
		}
		else{
	    TranslateMessage(&msg);
		DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}

//编写窗口过程函数
LRESULT CALLBACK WinSunProc(
    HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
   switch(uMsg)
   {
   case WM_CHAR:
	   char szChar[20];
	   sprintf(szChar,"char code is %d",wParam);
	   MessageBox(hwnd,szChar,"char",0);
	   break;
   case WM_LBUTTONDOWN:
	   MessageBox(hwnd,"mouse clicked","message",0);
	   HDC hdc;
	   hdc=GetDC(hwnd);
	   TextOut(hdc,0,50,"程序员之家",strlen("程序员之家"));
	   //releaseDC(hwnd,hdc);
	   break;
   case WM_PAINT:
	   HDC hDC;
	   PAINTSTRUCT ps;
	   hDC =BeginPaint(hwnd,&ps);
	   TextOut(hDC,0,0,"http://www.sunxin.org",strlen("http://www.sunxin.org"));
       EndPaint(hwnd,&ps);
	   break;
   case WM_CLOSE:
	   if(IDYES==MessageBox(hwnd,"是否真的结束？","message",MB_YESNO))
	   {
	     DestroyWindow(hwnd);
	   }
	   break;
   case WM_DESTROY:
	   PostQuitMessage(0);
	   break;
   default:
	   return DefWindowProc(hwnd,uMsg,wParam,lParam);
   }
   return 0;

}