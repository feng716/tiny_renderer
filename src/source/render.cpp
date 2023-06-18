#include "render.h"
#include <stdio.h>
#include <fstream>
#include <string>
#include <utility>
#include "platform.h"

void line(pt a, pt b, COLORREF color){
  if(b.x<a.x) std::swap(a, b);
  bool steep=1;
  if(b.x-a.x<b.y-a.y){ std::swap(a.x,a.y);std::swap(b.x,b.y);steep=0;}
  float dx=b.x-a.x,derror=std::abs((float)(b.y-a.y))*2,error=0;
  int y=a.x;
  for(float x=a.x;x<b.x;x++){
    (steep)?drawPoint(pt(x,y), color):drawPoint(pt(y,x),color);
    error+=derror;
    if(error>dx){y+=(b.y>a.y)?1:-1;error-=dx*2;}//2*dx*all value
    //printf("x:%d  y:%d k:%f\n",x,y,error);
  }
}
void objLoader(char* fileName, Model& m){
  std::ifstream in;
  in.open(fileName,std::ifstream::in);
  if(in.fail()) {printf("failed to load");return;}
  printf("successfully loaded");
  std::string line;
  while (!in.eof()) {
    std::getline(in,line);
    
    vec3F p;
    face f;
    switch (line.c_str()[0]) {
    case 'v':
      sscanf(line.c_str(),"v %f %f %f", &p.x, &p.y, &p.z);
      m.vecV.push_back(p);
      break;
    case 'f':
      int t;
      sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d",&f.xI,&t,&t,&f.yI,&t,&t,&f.zI,&t,&t);
      m.faceV.push_back(f);
      break;
    }
  }
}

