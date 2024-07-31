#include<windows.h>
#include"icb_gui.h"

//#pragma comment (lib,"winmm.lib")

int F1, F2;
ICBYTES Corridor, Agent;
ICBYTES AgentStanding;//Ajan ayakta dururken 
//AJAN KOÞMA KARELERÝ ALTTAKÝ RESÝM DÝZÝNÝNE YÜKLENÝYOR
ICBYTES AgentRun[8]; // <--Agent Running sequence will be uploaded here
void ICGUI_Create()
{
	ICG_MWSize(1200, 830);
	ICG_MWTitle("IMPOSSIBLE MISSION");
}

void LoadAgentRun()
{
	Copy(Agent, 5, 10, 13, 30, AgentStanding);
	PasteNon0(AgentStanding,10, 58, Corridor);
	ICBYTES cordinat{ {45, 9, 13,30},{71,9,16,30},{100,8,20,30},{130,8,23,30},{160,7,25,30},{189,8,22,30},
		{218,8,25,31} };
	for (int i = 1; i <= cordinat.Y(); i++)
	{
		Copy(Agent, cordinat.I(1,i), cordinat.I(2, i), cordinat.I(3, i), cordinat.I(4, i), AgentRun[i-1]);
		PasteNon0(AgentRun[i-1], 33*i, 58, Corridor);
	}
	ICBYTES TV;
	MagnifyX3(Corridor, TV);
	DisplayImage(F1, TV);
	
}

void MakeAgentRun(void *)
{
	int xcor=1, ycor=58;
	ICBYTES TV,back;
	int step[] = { 5,5,5,5,5,8,8 };
	ReadImage("impossible_mission_elevator.bmp", Corridor);
	Copy(Corridor, xcor, ycor, 25, 32, back);
	PasteNon0(AgentStanding, xcor, ycor, Corridor);
	MagnifyX3(Corridor, TV);
	DisplayImage(F1, TV);
	PlaySound("Another_Visitor.wav", NULL, SND_SYNC);
	Paste(back, xcor, ycor, Corridor);
	int i = 0;
	while(true)
	{
		Copy(Corridor, xcor, ycor, 25, 32,back);
		PasteNon0(AgentRun[i%7], xcor, ycor, Corridor);
		MagnifyX3(Corridor, TV);
		DisplayImage(F1, TV);
#ifdef _DEBUG
		Sleep(20);//DEBUG MODU YAVAÞ OLDUÐU ÝÇÝN DAHA AZ BEKLETÝYORUZ
#else
		Sleep(60); //Release mode is fast so we delay more
#endif
		Paste(back, xcor, ycor, Corridor);
		if(i%7==4)PlaySound("Step.wav", NULL, SND_ASYNC);
		xcor += step[i%7];
		i++;
		if (i > 52) {
			xcor = 1; i = 0;
		}
	}
}


void ICGUI_main()
{	
	F1 = ICG_FrameThin(5, 140, 450, 430);
	F2 = ICG_FrameThin(5, 5, 20, 20);
	ICG_Button(400, 5, 160, 55, "Load Agent Run\n1 -----------------------------------\n KOÞAN AJANI YÜKLE", LoadAgentRun);
	ICG_TButton(580, 5, 160, 55, "Make Agent Run\n2 -----------------------------------\n AJANI KOÞTUR", MakeAgentRun,NULL);
	ReadImage("impossible_mission_elevator.bmp", Corridor);
	DisplayImage(F1, Corridor);
	ReadImage("Impossible_Mission Agent.bmp", Agent);
	DisplayImage(F2, Agent);
}