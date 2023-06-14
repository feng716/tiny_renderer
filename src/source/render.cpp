#include "render.h"
#include <stdio.h>
#include <utility>
#include "platform.h"

void line(pt a, pt b, COLORREF color){
  if(b.x<a.x) std::swap(a, b);
  for(float x=a.x;x<b.x;x++){
    float k=(float)(b.y-a.y)/(a.x-b.x);
    int y=k*(x-a.x)+b.y;
    printf("x:%d  y:%d k:%f\n",&x,&y,&k);
    drawPoint(pt(x,y), color);
  }
}