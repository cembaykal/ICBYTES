#include"icb_gui.h"


int MLE,FRM;
unsigned char ii[67] = { 139,131,127,108,108,96,67,84,54,31,40,18,9,11,5,11,12,30,37,54,74,
		91,103,127,139,147,164,176,194,202,218,230,230,244,250,248,237,226,225,201,182,171,
		139,117,98,74,56,37,26,24,9,9,11,16,24,37,43,58,75,84,84,103,108,122,124,138,141 };
ICBYTES wav;
void ICGUI_Create()
{
	ICG_MWTitle("WAV FORMAT");
	ICG_MWSize(1250, 620);
}
void GirisCihazlar()
{
	ICBYTES girdi;
	ICG_printf(MLE, "Ses Giriþ Cihaz Sayýsý: %d\n", WaveInputDevices(girdi));
	Print(MLE, girdi);
	ICG_printf(MLE, "\n");
}
void CikisCihazlar()
{
	ICBYTES cikis;
	ICG_printf(MLE, "Ses Çýkýþ Cihaz Sayýsý: %d\n", WaveOutputDevices(cikis));
	Print(MLE, cikis);
	ICG_printf(MLE, "\n");
}

void iiiii()
{
	ICDEVICE d;
	ICBYTES i;
	if (CreateSound(i, 1, 3000, ICB_UCHAR, 8000) == 0)
	{
		for (int y = 0; y < 3000; y++) i.B(1, y) = ii[y % 61];
	}
	if (!CreateCompatibleDevice(d, ICB_WAVEOUT, 0, i))
		ICG_printf(MLE, "Ses Kartý Eriþilemedi!\n");
	if (!WaveOut(d, i))
		ICG_printf(MLE, "Cihaz bu sesi Çýkartmýyor!\n");
	Sleep(400);
	WaveOut(d, i);
	CloseDevice(d);
}
void openwav()
{
	ICG_printf("You can open one of the files in \"Files_WAV_Dosyalar\" directory\n");
	ICG_printf("\n");
	ICG_printf("\"Files_WAV_Dosyalar\" klasöründeki dosyalardan birini açabilirsiniz.\n");
	ICG_printf("\n");
	ICBYTES path;
	if (ReadWave(wav, OpenFileMenu(path,"*")) < 0) ICG_printf(MLE,"file error!\n");
	WaveOut(wav, 0);
	Sleep(1000);
}
void PlotWave()
{
	ICBYTES& i = wav;
	ICBYTES frame;
	CreateImage(frame, 940, 512, ICB_UINT);
	
	int x, y = 1;
	
	ICG_printf("samples: %d\n", (int)wav.Y());
	if (GetType(i) == ICB_SHORT)
	{
		ICG_printf("16 bit\n");
		
		for (x = 2; x < frame.X(); x++)
		{
			y = i.S(1, x*2) / 128 + frame.Y()/ 2;			
			frame.sU(x, y) = 0x00ff00;
			
		}
	}
	if (GetType(i) == ICB_UCHAR)
	{
		ICG_printf("8 bit\n");
		
		for (x = 1; x < frame.X(); x++)
		{
			y = i.B(1,x*3)*2;
			frame.sU(x, y) = 0x00ff00;
		}
	}
	DisplayImage(FRM, frame);
	return;
}

void ICGUI_main()
{
	ICG_Button(15, 5, 150, 25, "WAV HARDWARE (IN)", GirisCihazlar);
	ICG_Button(167, 5, 170, 25, "WAV HARDWARE (OUT)", CikisCihazlar);
	ICG_Button(350, 5, 100, 25, "iiiiiiii", iiiii);
	ICG_Button(470, 5, 150, 25, "Open WAV  -->", openwav);
	ICG_Button(620, 5, 150, 25, "Plot WAV", PlotWave);
	FRM = ICG_FrameMedium(280, 40, 940, 512);
	MLE = ICG_MLEdit(15, 40, 250, 500, "", SCROLLBAR_V);
	ICG_SetPrintWindow(MLE);
}