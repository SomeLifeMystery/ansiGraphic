#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include "ansiGraphic2.h"

int main() {
  const int width = 60;
  const int height = 30;
  ansigraphic_image_t*image=ansigraphic_newImage(width, height);
  ansigraphic_dvector2_t start, end;
  double alpha = 0;
  double beta = 0;
  double radiusx=width/3;
  double radiusy=height/3;
  double radiusbx=width/5;
  double radiusby=height/5;
  
  start.x=width/2;
  start.y=height/2;
  while (alpha < 3600) {
    ansigraphic_imageClear(image);
    end.x=start.x + radiusx*(cos(((int)(alpha)%360)*3.14/180.0));
    end.y=start.y + radiusy*(sin(((int)(alpha)%360)*3.14/180.0));
    ansigraphic_drawLine(image, &start, &end, '.', "015", "000");
    ansigraphic_image_reverse(image);
    end.x=start.x + radiusbx*(cos(((int)(beta)%360)*3.14/180.0));
    end.y=start.y + radiusby*(sin(((int)(beta)%360)*3.14/180.0));
    ansigraphic_drawLine(image, &start, &end, '.', "015", "000");
    ansigraphic_image_reverse(image);
    ansigraphic_imagePrint(image);
    alpha+=1;
    beta+=3;
  }
  ansigraphic_deleteImage(image);
  return 0;
}
