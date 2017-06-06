#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "ansiGraphic2.h"

int main() {
  const int width = 60;
  const int height = 30;
  ansigraphic_color_RGB_t white;
  ansigraphic_color_RGB_set(&white, 255, 255, 255);
  ansigraphic_image_RGB_t*image=ansigraphic_newImage_RGB(width, height);
  ansigraphic_dvector2_t start, end;
  double alpha = 0;
  double radiusx=width/3;
  double radiusy=height/3;
  
  start.x=width/2;
  start.y=height/2;
  while (alpha < 360) {
    end.x=start.x + radiusx*(cos(alpha*3.14/180.0));
    end.y=start.y + radiusy*(sin(alpha*3.14/180.0));
    ansigraphic_drawLine_RGB(image, &start, &end, ' ', &white, &white);
    alpha+=0.1;
  }
  ansigraphic_imagePrint_RGB(image);
  return 0;
}
