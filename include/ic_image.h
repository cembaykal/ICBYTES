// THIS FILE IS A PART OF ICBYTES LIBRARY BETA VERSION
// WRITTEN BY IBRAHIM CEM BAYKAL
// THE LIBRARY IS PROVIDED AS IS. IF IT CAuSES ANY FINACIAL/DATA/PRESTIGE LOSS HE IS NOT RESPONSIBLE
#pragma once
#include "icbytes.h"

int RGB2YCrCb(ICBYTES& in, ICBYTES& out);
int RGB2HSV(ICBYTES& in, ICBYTES& out);
int RGB2XYZ(ICBYTES& in, ICBYTES& out);

int GrayHisto(ICBYTES& img, ICBYTES& histo);
int Otsu(ICBYTES& img);
void GrayThresh(ICBYTES& in, ICBYTES& out, unsigned char threshold);
void ColorThresh(ICBYTES& in, ICBYTES& out, unsigned int threshold);
void ColorThresh(ICBYTES& in, ICBYTES& out, ICBYTES& range);

bool Canny(ICBYTES& inp, ICBYTES& out);