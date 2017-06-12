#include <time.h>

#include "ansiGraphic2.1.h"

int main() {
  ansigraphic_ivector2_t xy; xy.x=0; xy.y=0;
  ansigraphic_image_t* screen = ansigraphic_newImage(10, 10);
  ansigraphic_image_t* image1 = ansigraphic_newImage(1, 1);
  ansigraphic_pixelSetColor(image1, &xy, "000", "015");
  ansigraphic_image_t* image2 = ansigraphic_newImage(1, 1);
  ansigraphic_pixelSetColor(image2, &xy, "000", "025");
  ansigraphic_image_t* image3 = ansigraphic_newImage(1, 1);
  ansigraphic_pixelSetColor(image3, &xy, "000", "035");
  ansigraphic_animatedSprite_t* aSprite = ansigraphic_newAnimatedSprite();
  aSprite->xy.x = 0;
  aSprite->xy.y = 0;
  aSprite->frameRate = 1000;
  ansigraphic_animatedSprite_pushFrame(aSprite, image1);
  ansigraphic_animatedSprite_pushFrame(aSprite, image2);
  ansigraphic_animatedSprite_pushFrame(aSprite, image3);


  clock_t timer, clocked = 0;
  int delay = 1000 / 30;
  while (42) {
    timer = clocked;
    ansigraphic_imageClear(screen);
    ansigraphic_animatedSpritePrint(screen, aSprite);
    ansigraphic_imagePrint(screen);
    ansigraphic_animatedSprite_tick(aSprite, delay);
    clocked = clock() / CLOCKS_PER_SEC;
    timer = delay - (clocked - timer);
    if (timer > 0)
      usleep(timer * 1000);
  }
  return 0;
}
