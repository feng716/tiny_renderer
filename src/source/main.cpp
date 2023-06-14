#include <iostream>
#include <windef.h>
#include <windows.h>
#include <wingdi.h>
#include "platform.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow){
    HWND hwnd=createDefaultWindow(hInstance);
    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);
    MSG msg;
    while(GetMessage(&msg,hwnd,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
