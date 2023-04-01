#ifndef ICBYTES_IMAGE_HEADER
#define ICBYTES_IMAGE_HEADER
#include <windows.h>
#include "icbytes.h"

// Image Manipulation Functions
// Resim Çizme Fonksiyonlarý


bool ToRGB32(ICBYTES& source, ICBYTES& destination);
bool Luma(ICBYTES& s, ICBYTES& d);
int Quart(ICBYTES& source, ICBYTES& destination);

void MarkPlus(ICBYTES& i, int x, int y, int size, int color);
void MarkVert(ICBYTES& i, int x, int y, int size, int color);
void MarkHorz(ICBYTES& i, int x, int y, int size, int color);
int Line(ICBYTES& i, int x1, int y1, int x2, int y2, int color);
void Line(ICBYTES& img, ICBYTES& lines, int color);
void Rect(ICBYTES& img, ICBYTES& rectangles, int color);
bool Rect(ICBYTES& icb, int x1, int y1, int width, int height, int color);
void FillRect(ICBYTES& img, ICBYTES& rectangles, int color);
void HalfRect(ICBYTES& img, int x, int y, int width, int height, int color);
bool FillRect(ICBYTES& icb, int x1, int y1, int width, int height, int color);
bool FillEllipse(ICBYTES& i, int x1, int y1, int Rx, int Ry, int color);
bool FillCircle(ICBYTES& i, int x, int y, int r, int color);
bool Circle(ICBYTES& i, int x, int y, int r, int color);
bool Ellipse(ICBYTES& icb, int x, int y, int Rx, int Ry, int clr);
bool ReadImage(const char* filepath, ICBYTES& i);
bool DecodeJPG(ICBYTES& inp, ICBYTES& outp);
bool ReadJPG(const char* filepath, ICBYTES& i);


void Impress12x20(ICBYTES& i, int x, int y, const char* txt, unsigned color);
#endif