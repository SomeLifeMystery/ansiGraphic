INCLUDE= -I../
COMMON_SRC= ../ansiGraphic2.c

all:
	rm -f test_bmp && gcc -o test_bmp $(INCLUDE) $(COMMON_SRC) bmp.c
	rm -f test_drawLine && gcc -o test_drawLine $(INCLUDE) $(COMMON_SRC) drawLine.c -lm
	rm -f test_drawLine_rgb && gcc -o test_drawLine_rgb $(INCLUDE) $(COMMON_SRC) drawLine_RGB.c -lm
	rm -f test_gol_rgb && gcc -o test_gol_rgb $(INCLUDE) $(COMMON_SRC) gol_RGB.c

clean:
	rm -f test_bmp
	rm -f test_drawLine
	rm -f test_drawLine_rgb
	rm -f test_gol_rgb
