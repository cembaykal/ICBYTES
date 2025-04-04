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
int CreateDXCam(ICDEVICE& video_source, int device, HWND preview = NULL);


bool WaveOut(ICDEVICE& d, ICBYTES& wave);
unsigned WaveInputDevices(ICBYTES& i);
unsigned WaveOutputDevices(ICBYTES& o);
int WaveOut(ICBYTES& i, int deviceID);
bool CloseDevice(ICDEVICE& d);
int ReadWave(ICBYTES& i, const char* filepath);
bool WaveIn(ICDEVICE& d, ICBYTES& wave);
int GetVideoSourceList(ICBYTES& i);

bool CaptureImage(ICDEVICE& video_source, ICBYTES& frame);
void SystemInfo(ICBYTES& info);
void PeripheralInfo(ICBYTES& info);

//-------------------  FILE DEVICES -------------------------------------
/*READ-ONLY file access / Sadece okunabilir dosya eriþimi*/
bool CreateFileReader(ICDEVICE& file, const char* filepath);
bool CreateExistingFileWriter(ICDEVICE& file, const char* filepath);
//ALWAYS OPENS if nonexistant creates / HEP AÇAR yoksa yaratýr
bool CreateFileDevice(ICDEVICE& file, const char* filepath);
long long GetFileLength(ICDEVICE& file);
HANDLE GetFileHandle(ICDEVICE& file);
int C_RunTimeHandle(ICDEVICE& file);
//writes entire ICBYTES to address
long long WriteICBYTES(ICDEVICE& file, ICBYTES& i, long long to_address);
//reade entire ICBYTES from address
long long ReadICBYTES(ICDEVICE& file, ICBYTES& i, long long from_address);
unsigned ReadIntoMatrix(ICDEVICE& file, ICBYTES& mat);
long long ReadIntoBuffer(ICDEVICE& file, ICBYTES& mat);
unsigned AppendMatrixToFile(ICDEVICE& file, ICBYTES& mat);
int WriteBuffer(ICDEVICE& file, ICBYTES& mat);



void* GetMFReader(ICDEVICE& d);
int CreateMFCam(ICDEVICE& video_source, int device,int width=0, int height=0);
//bool SetMFCamVideoSize(ICDEVICE &d, unsigned int width, unsigned int height);
bool ListCamModesTxt(ICDEVICE& d, ICBYTES& modes);

//Works only in Robot Vision version
int CreateDCTtechRelay(ICDEVICE& r, int device);
int CommandRelay(ICDEVICE& r, int onoff, const char* relay_number);
bool CreateTCPServer(ICDEVICE& dev, int port);
int RecvData(ICDEVICE& dev, ICBYTES& data);
bool CreateTCPClient(ICDEVICE& dev, const char* address, int port);
int SendData(ICDEVICE& dev, ICBYTES& data);


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
void FillRoundRect(ICBYTES& img, int x, int y, int width, int height, int r, int color);
bool FillEllipse(ICBYTES& i, int x1, int y1, int Rx, int Ry, int color);
bool FillCircle(ICBYTES& i, int x, int y, int r, int color);
bool Circle(ICBYTES& i, int x, int y, int r, int color);
bool Ellipse(ICBYTES& icb, int x, int y, int Rx, int Ry, int clr);
void TiltedEllipseArc(ICBYTES& img, int x, int y, int rx, int ry, int angle, int color, int arc_strt = 0, int arc_end = 360);
void FillTiltedEllipse(ICBYTES& img, int x, int y, int r1, int r2, int angle, int color);
bool FillTiltedEllipse(ICBYTES& img, ICBYTES& coor);
void SetPixels(ICBYTES& i, int x, int y, unsigned clr, ICBYTES& o);
void SetPixelsX2(ICBYTES& i, int x, int y, unsigned clr, ICBYTES& o);

int LineGraph(ICBYTES& in, ICBYTES& img, int height, int color, int background=0);

bool ReadImage(const char* filepath, ICBYTES& i);
void MapJPG(ICBYTES& filedata, ICBYTES& result);
bool DecodeJPG(ICBYTES& inp, ICBYTES& outp);
bool ReadJPG(const char* filepath, ICBYTES& i);

unsigned long long* KeyMapTR(ICBYTES& inp, int maps);
unsigned long long* KeyMap(ICBYTES& inp, int maps);
void Impress12x20(ICBYTES& i, int x, int y, const char* txt, unsigned color);
