#include"icb_gui.h"
extern ICBDIAG diag;

int MLE1;
void ICGUI_Create()
{
	ICG_MWTitle("DIAGNOSTiK");
	ICG_MWSize(430, 300);
}
void butonfunc()
{
	ICBYTES a(1);
	CreateMatrix(a, 5, 5, ICB_INT);
	a.I(0, 0) = 5;
	a.C(2, 3) = 4;
	for (int y = 0; y < 50; y++)
	{
		a.I(5, 5 + y) = y;
		ICG_printf(MLE1, "%d ", a.I(5, 5 + y));
	}
}
void ICGUI_main()
{
	ICG_Button(5, 5, 120, 25, "Buton1", butonfunc);
	MLE1 = ICG_MLEditSunken(5, 50, 250, 150, "", SCROLLBAR_V);
	diag.SetOutput(ICG_GetHWND(MLE1));
}