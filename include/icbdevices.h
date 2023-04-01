#pragma once
#include "icbytes.h"

#define ICB_WAVEOUT  44
#define ICB_WAVEIN   45

class DEVICE;

class ICDEVICE
{
public:
	void* driver=NULL;
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