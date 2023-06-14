#pragma once
#include <minwindef.h>
#include <windef.h>
#include "render.h"
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HWND wndClassInit(HINSTANCE hInstance);
HWND createDefaultWindow(HINSTANCE hInstance);
struct pixelParam{
  int x;
  int y;
  COLORREF cr;
};
struct renderCommand{
  char fID;
  void *param;
};
//SetPixel 0
void drawPoint(pt a,COLORREF);
void registerFun();