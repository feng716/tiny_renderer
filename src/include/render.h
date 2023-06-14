#pragma once
#include <windef.h>
struct pt{
  int x;
  int y;
  pt():x(0),y(0){}
  pt(int a,int b):x(a),y(b){}
};
void line(pt,pt,COLORREF);