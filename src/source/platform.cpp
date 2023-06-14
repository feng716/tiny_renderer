#include "platform.h"
#include "render.h"

#include <process.h>
#include <stdio.h>
#include <string.h>
#include <windef.h>
#include <windows.h>
#include <wingdi.h>
#include <vector>
#include <list>

HDC hdc;
//std::vector<void*()> func;
std::list<renderCommand> l_rC;
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam,
                         LPARAM lParam) {
  PAINTSTRUCT ps;
  //HDC hdc;
  switch (message) {
    case WM_PAINT: 
      hdc = BeginPaint(hwnd, &ps);
      line(pt(100,100), pt(120,130), RGB(255,255,255));
      line(pt(120,120), pt(100,0), RGB(255,0,0));
      //TextOut(hdc,0,50,"tiny_renderer",strlen("tiny_renderer"));
      EndPaint(hwnd, &ps);
      break;
    case WM_DESTROY: 
      PostQuitMessage(0);
      break;
    case WM_CLOSE:
      DestroyWindow(hwnd);
      break;
    default:
      return DefWindowProc(hwnd, message, wParam, lParam);
      break;
  }
  return 0;
}
HWND createDefaultWindow(HINSTANCE hInstance) {
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndclass.lpszClassName = "blackWindow";
    if (!RegisterClass(&wndclass)) {
      MessageBox(NULL, TEXT("failed to register"), "register", MB_ICONERROR);
      exit(0);
    }
    hwnd = CreateWindow("blackWindow", TEXT("Tiny Renderer"), WS_OVERLAPPEDWINDOW,
                     CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
                     NULL, NULL, hInstance, NULL);
    return hwnd;
}

void drawPoint(pt a,COLORREF cr){
  SetPixel(hdc, a.x, a.y,cr);
}

void registerFun(){
  auto pSetPixel = SetPixel;
  //func.push_back(pSetPixel);
}