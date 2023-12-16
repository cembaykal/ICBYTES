// THIS FILE IS A PART OF ICBYTES LIBRARY BETA VERSION
// WRITTEN BY IBRAHIM CEM BAYKAL
// THE LIBRARY IS PROVIDED AS IS. IF IT CAuSES ANY FINACIAL/DATA/PRESTIGE LOSS HE IS NOT RESPONSIBLE
#pragma once
#include <windows.h>
#include "icbytes.h"
#define ICB_WAVEOUT  44
#define ICB_WAVEIN   45

class DEVICE;

class ICDEVICE
{
public:
	void* driver = NULL;
	ICDEVICE();
	~ICDEVICE();
};


int CreateSound(ICBYTES& i, long long channels, long long sample_size, int type, int SamplesPerSec);
bool CreateCompatibleDevice(ICDEVICE& d, int device_type, int device_id, ICBYTES& compatiblewith);
bool WaveOut(ICDEVICE& d, ICBYTES& wave);
unsigned WaveInputDevices(ICBYTES& i);
unsigned WaveOutputDevices(ICBYTES& o);
int WaveOut(ICBYTES& i, int deviceID);
void CloseDevice(ICDEVICE& d);
int ReadWave(ICBYTES& i, const char* filepath);
bool WaveIn(ICDEVICE& d, ICBYTES& wave);
int GetVideoSourceList(ICBYTES& i);
int CreateDXCam(ICDEVICE& video_source, int device, HWND preview = NULL);
bool CaptureImage(ICDEVICE& video_source, ICBYTES& frame);
void SystemInfo(ICBYTES& info);
bool CreateFileReader(ICDEVICE& file, const char* filepath);
unsigned ReadIntoMatrix(ICDEVICE& file, ICBYTES& mat);



// Image Manipulation Functions
// Resim Çizme Fonksiyonlarý

bool ToRGB24(ICBYTES& source, ICBYTES& destination);
bool ToRGB32(ICBYTES& source, ICBYTES& destination);
bool Luma(ICBYTES& s, ICBYTES& d);
int Quart(ICBYTES& source, ICBYTES& destination);
int MagnifyX3(ICBYTES& i, ICBYTES& o);
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
void SetPixels(ICBYTES& i, int x, int y, unsigned clr, ICBYTES& o);
void SetPixelsX2(ICBYTES& i, int x, int y, unsigned clr, ICBYTES& o);

int LineGraph(ICBYTES& in, ICBYTES& img, int height, int color, int background=0);

bool ReadImage(const char* filepath, ICBYTES& i);
bool DecodeJPG(ICBYTES& inp, ICBYTES& outp);
bool ReadJPG(const char* filepath, ICBYTES& i);


void Impress12x20(ICBYTES& i, int x, int y, const char* txt, unsigned color);
