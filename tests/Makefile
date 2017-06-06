INCLUDE= -I../
COMMON_SRC= ../ansiGraphic2.c

all:
	rm -f test_bmp && gcc -o test_bmp $(INCLUDE) $(COMMON_SRC) bmp.c
	rm -f test_drawLine && gcc -o test_drawLine $(INCLUDE) $(COMMON_SRC) drawLine.c -lm

clean:
	rm -f test_bmp
	rm -f test_drawLine
