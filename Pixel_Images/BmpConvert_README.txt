To create a 16-bit image for ST7735 displays on LM4F120 or TM4C123G
Jonathan Valvano, 7/18/2013
See BmpConvert.cpp for how it works

PUT A BORDER OF AT LEAST 1 BLACK PIXEL AROUND ALL MOBILE OBJECTS
-Prevents screen tear

To create pixel art:
https://www.pixilart.com/draw
Save png and .pixil file

Convert to 24 bit bmp:
https://online-converting.com/image/convert2bmp


1) Create a bmp file using
   width less than or equal to 128 pixels
   height less than or equal 160 pixels
   save the image as a 24-bit bmp file
   store in same directory as BmpConvert16.exe
2) Execute BmpConvert16.exe
   Type the image name
   E.g., if the file is horse.bmp, then type horse
3) Open the corresponding txt file, select all, copy
4) Open uVision compiler
   paste new image as a data constant
5) Draw the image by calling ST7735_DrawBitmap
   E.g., center a 120x160 image
         ST7735_DrawBitmap(4, 159, Horse, 120, 160);
