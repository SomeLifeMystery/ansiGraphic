#ifndef ANSIGRAPHIC2_H_
#define ANSIGRAPHIC2_H_

#include <stdint.h>

#ifdef _cplusplus
extern "C" {
#endif

  typedef struct s_ansigraphic_ivector2 {
    int x;
    int y;
  } ansigraphic_ivector2_t;

  typedef struct s_ansigraphic_dvector2 {
    double x;
    double y;
  } ansigraphic_dvector2_t;

  typedef struct s_ansigraphic_pixel {
    char pixel[27];
  } ansigraphic_pixel_t;

  typedef struct s_ansigraphic_pixel_RGB {
    char pixel[43];
  } ansigraphic_pixel_RGB_t;

  typedef char ansigraphic_color_RGB_t[3][3];

  typedef struct s_ansigraphic_image {
    int width;
    int height;
    ansigraphic_pixel_t* pixels;
  } ansigraphic_image_t;

  typedef struct s_ansigraphic_image_RGB {
    int width;
    int height;
    ansigraphic_pixel_RGB_t* pixels;
  } ansigraphic_image_RGB_t;

  typedef struct s_ansigraphic_sprite {
    ansigraphic_image_t* image;
    ansigraphic_ivector2_t xy;
  } ansigraphic_sprite_t;
  
  typedef struct s_ansigraphic_sprite_RGB {
    ansigraphic_image_RGB_t* image;
    ansigraphic_ivector2_t xy;
  } ansigraphic_sprite_RGB_t;

  void ansigraphic_pixelSetColor(ansigraphic_image_t* image,
				 ansigraphic_ivector2_t* xy,
				 char* fgColor,
				 char* bgColor);
  void ansigraphic_pixelSetColor_RGB(ansigraphic_image_RGB_t* image,
				     ansigraphic_ivector2_t* xy,
				     ansigraphic_color_RGB_t* fgColor,
				     ansigraphic_color_RGB_t* bgColor);
  void ansigraphic_pixelGetColor_RGB(ansigraphic_image_RGB_t* image,
				     ansigraphic_ivector2_t* xy,
				     ansigraphic_color_RGB_t* fgColor,
				     ansigraphic_color_RGB_t* bgColor);
  void ansigraphic_pixelSetValue(ansigraphic_image_t* image,
				 ansigraphic_ivector2_t* xy,
				 char value);
  void ansigraphic_pixelSetValue_RGB(ansigraphic_image_RGB_t* image,
				     ansigraphic_ivector2_t* xy,
				     char value);
  void ansigraphic_imagePrint(ansigraphic_image_t* image);
  void ansigraphic_imagePrint_RGB(ansigraphic_image_RGB_t* image);
  void ansigraphic_imageClear(ansigraphic_image_t* image);
  void ansigraphic_imageClear_RGB(ansigraphic_image_RGB_t* image);
  void ansigraphic_imageFill(ansigraphic_image_t* image,
			     char value,
			     char* fgColor,
			     char* bgColor);
  void ansigraphic_imageFill_RGB(ansigraphic_image_RGB_t* image,
				 char value,
				 ansigraphic_color_RGB_t* fgColor,
				 ansigraphic_color_RGB_t* bgColor);
  void ansigraphic_image_reverse(ansigraphic_image_t* image);
  void ansigraphic_image_RGB_reverse(ansigraphic_image_RGB_t* image);
  ansigraphic_image_t* ansigraphic_newImage(int32_t width,
					    int32_t height);
  ansigraphic_image_RGB_t* ansigraphic_newImage_RGB(int32_t width,
						    int32_t height);
  void ansigraphic_deleteImage(ansigraphic_image_t* image);
  void ansigraphic_deleteImage_RGB(ansigraphic_image_RGB_t* image);
  void ansigraphic_color_RGB_set(ansigraphic_color_RGB_t* color,
				 int red,
				 int green,
				 int blue);
  void ansigraphic_color_RGB_reverse(ansigraphic_color_RGB_t* color);
  void ansigraphic_drawLine(ansigraphic_image_t* image,
			    ansigraphic_dvector2_t* start,
			    ansigraphic_dvector2_t* end,
			    char value,
			    char* fgColor,
			    char* bgColor);
  void ansigraphic_drawLine_RGB(ansigraphic_image_RGB_t* image,
				ansigraphic_dvector2_t* start,
				ansigraphic_dvector2_t* end,
				char value,
				ansigraphic_color_RGB_t* fgColor,
				ansigraphic_color_RGB_t* bgColor);
  ansigraphic_image_t* ansigraphic_readBmp(char* fileName);
  ansigraphic_image_RGB_t* ansigraphic_readBmp_RGB(char* fileName);
  void ansigraphic_spritePrint(ansigraphic_image_t* dest,
			       ansigraphic_sprite_t* src);
  void ansigraphic_spritePrint_RGB(ansigraphic_image_RGB_t* dest,
				   ansigraphic_sprite_RGB_t* src);
#ifdef _cplusplus
}
#endif

#endif /* !ANSIGRAPHIC_H_ */

