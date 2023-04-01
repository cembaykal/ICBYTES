#include"icb_gui.h"
ICBYTES labirent = { {270, 50, 20, 80},{210, 110, 140, 20},{270, 170, 20,80},
{210, 230, 140, 20},{270, 410, 20, 80}, {210, 470, 140, 20},{150, 170, 80, 20},
{330, 170, 80, 20},{50, 470, 60, 20},{50, 530, 60, 40},{150, 530, 80, 40},
{150, 230, 20, 80},{150, 350, 20, 140},{150, 410, 80, 20},{450, 470, 60, 20},
{450, 530, 60, 40},{330, 530, 80, 40 },{390, 230, 20, 80},{390, 350, 20, 140},
{330, 410, 80, 20},{50, 50, 180, 20},{150, 50, 20, 80},{330, 50, 180, 20},
{390, 50, 20, 80},{90, 110, 20, 80},{50, 170, 60, 20},{450, 110, 20, 80},
{450, 170, 60, 20} };
ICBYTES zindan = { {210, 290, 350, 290},{350, 290, 350, 370},{350,370,300,370},
{300, 370,300,360},{300,360,340,360},{340,360,340,300},{340,300,220,300},
{220,300,220,360},{220,360,260,360},{260,360,260,370},{260,370,210,370},
{210,370,210,290} };
ICBYTES cepheic = { {10,10,550,10},{550,10,550,110},{550,110,510,110},
{510,110,510,130},{510,130,550,130},{550,130,550,230},{550,230,450,230},
{450,230,450,310},{450,310,550,310},{550,310,550,350},{550,350,450,350},
{450,350,450,430},{450,430,550,430},{550,430,550,610},{550,610,290,610},
{290,610,290,530},{290,530,270,530},{270,530,270,610},{270,610,10,610},
{10,610,10,430},{10,430,110,430},{110,430,110,350},{110,350,10,350},
{10,350,10,310},{10,310,110,310},{110,310,110,230},{110,230,10,230},
{10,230,10,130},{10,130,50,130},{50,130,50,110},{50,110,10,110},
{10,110,10,10} };
ICBYTES cephedis = { {5,5,555,5},{555,5,555,235},{555,235,455,235},
{455,235,455,305},{455,305,555,305},{555,305,555,355},{555,355,455,355},
{455,355,455,425},{455,425,555,425},{555,425,555,615},{555,615,5,615},
{5,615,5,425},{5,425,105,425},{105,425,105,355},{105,355,5,355},
{5,355,5,305},{5,305,105,305},{105,305,105,235},{105,235,5,235},
{5,235,5,5} };
void ICGUI_Create()
{
	ICG_MWTitle("Pacman");
	ICG_MWSize(700, 700);
}
int sicim_acik = 0, klavyegirdi = 0;
int FRM1, BTN;
ICBYTES ekran;
void* Pacman(PVOID lpParam)
{
	
	int x = 230, y = 470;
	while (sicim_acik)
	{
		FillCircle(ekran, x - 15, y, 15, 0xffff00);
		HalfRect(ekran, x, y, -15, -15, 0);
		HalfRect(ekran, x, y, -15, 15, 0);
		DisplayImage(FRM1, ekran);
		Sleep(10);
		FillRect(ekran, x - 30, y - 15, 30, 30, 0);
		if (klavyegirdi == 39)//sað ok tuþuna basýldýysa
			x++;
		else if (klavyegirdi == 37)//sol ok tuþuna basýldýysa
			x--;
		else if (klavyegirdi == 38)//aþaðý ok tuþuna basýldýysa
			y--;
		else if (klavyegirdi == 40)//yukarý ok tuþuna basýldýysa
			y++;
	}
	return(NULL);
}
void KlavyeyeBasinca(int k)
{
	klavyegirdi = k;
}
void Baslat()
{
	DWORD dw;
	if (sicim_acik == 0)
	{
		sicim_acik = 1;
		ICG_SetWindowText(BTN, "BÝTÝR");
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Pacman, NULL, 0, &dw);
	}
	else
	{
		sicim_acik = 0;
		ICG_SetWindowText(BTN, "BAÞLAT");
	}
	SetFocus(ICG_GetMainWindow());
}
void ICGUI_main()
{
	static ICBYTES saha;
	int color = 0x2e27ff;
	CreateImage(saha, 560, 620, ICB_UINT);
	
	FRM1 = ICG_FrameMedium(5, 5, 400, 200);
	saha = 0;
	Line(saha, zindan, 0x3080ff);
	Line(saha, cepheic, 0x3080ff);
	Line(saha, cephedis, 0x3080ff);
	FillRect(saha, 260, 365, 40, 5, 0xFADBD8);
	Rect(saha, labirent, 0x3080ff);
	FlipV(saha, ekran);
	DisplayImage(FRM1, ekran);
	BTN = ICG_Button(570, 5, 100, 25, "BAÞLAT", Baslat);
	ICG_SetOnKeyPressed(KlavyeyeBasinca);
}