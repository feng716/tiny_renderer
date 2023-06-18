#pragma once
#include <windef.h>
#include <vector>
struct pt{
  int x;
  int y;
  pt():x(0),y(0){}
  pt(int a,int b):x(a),y(b){}
};
struct vec3F{
  float x;
  float y;
  float z;
  vec3F(float ix,float iy,float iz):x(ix),y(iy),z(iz){}
  vec3F(){}
};
struct face{
  int xI;
  int yI;
  int zI;
  face(float ix,float iy,float iz):xI(ix),yI(iy),zI(iz){}
  face(){}
};
struct Model{
  std::vector<vec3F> vecV;
  std::vector<face> faceV;
};
void line(pt,pt,COLORREF);
void objLoader(char* fileName,Model&);
