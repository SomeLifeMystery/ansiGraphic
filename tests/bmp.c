#include <unistd.h>
#include "ansiGraphic2.h"

int main(int ac, char**av) {
  ansigraphic_image_t* img = ansigraphic_readBmp(av[1]);
  ansigraphic_image_RGB_t* imgrgb = ansigraphic_readBmp_RGB(av[1]);

  while (42) {
    ansigraphic_imagePrint(img);
    usleep(10000);
    ansigraphic_imagePrint_RGB(imgrgb);
    ansigraphic_image_RGB_reverse(imgrgb);
    usleep(10000);
  }
  return 0;
}
