// THIS FILE IS A PART OF ICBYTES LIBRARY BETA VERSION
// WRITTEN BY IBRAHIM CEM BAYKAL
// THE LIBRARY IS PROVIDED AS IS. IF IT CAuSES ANY FINACIAL/DATA/PRESTIGE LOSS HE IS NOT RESPONSIBLE
#pragma once
#include "icbytes.h"
#include "ic_media.h"


#define SCROLLBAR_0		0
#define SCROLLBAR_V		1
#define SCROLLBAR_H		2
#define SCROLLBAR_HV	3


HWND ICG_GetMainWindow();
HINSTANCE GetInstance();
void ICGUI_Create();
void ICGUI_main();
void ICG_MWSize(int width, int height);
void ICG_MWPosition(int X, int Y);
void ICG_MWTitle(const TCHAR* title);
void ICG_MWColor(unsigned R, unsigned G, unsigned B);
void ICG_MW_RemoveTitleBar();

HWND ICG_GetHWND(int handle);

bool ICG_SetFont(int H, int W, const char* fontname);
void ICG_SetSystemFont();

void ICG_DestroyWidget(int handle);
bool ICG_SetWindowText(int handle, const char* string);
void ICG_SetOnMouseMove(void (*MouseFunc)(int, int));
int ICG_GetMouseX();
int ICG_GetMouseY();
void ICG_SetOnMouseLDown(void (*MouseFunc)());
void ICG_SetOnMouseLUp(void (*MouseFunc)());
void ICG_SetOnMouseLDBLClick(void (*MouseFunc)());
void ICG_SetOnKeyPressed(void(*OnKeyPressedFunc)(int));
int ICG_LastKeyPressed();
void SetText(int handle, ICBYTES& m);
void GetText(int handle, ICBYTES& m);
void DisplayMatrix(int handle, ICBYTES& m);
void DisplayImage(int handle, ICBYTES& m);
void ICG_SetMenu(HMENU menu);



//Button with parameterless function
int ICG_Button(int x, int y, int width, int height, const char* text,void (*callback)());
//Button with parameter function
int ICG_Button(int x, int y, int width, int height, const char* text, void (*callback)(void* v),void *v);
//Bitmap Button with parameterless function
int ICG_BitmapButton(int x, int y, int width, int height, void (*callback)());
//Bitmap Button with parameter function
int ICG_BitmapButton(int x, int y, int width, int height, void (*callback)(void* v), void* v);
bool SetButtonBitmap(int handle, ICBYTES& i);
//_____________CHECKBOX_________________
int ICG_CheckBox(int x, int y, int width, int height, const char* text, void (*callback)(int)=NULL);
bool ICG_CheckBoxState(int handle);
//______________TBUTTON_________________
int ICG_TButton(int x, int y, int width, int height, const char* text, void (*callback)(void* v), void* v);
//_____________ML EDIT_________________
int ICG_MLEdit(int x, int y, int width, int height, const char* text, int scrollbar);
int ICG_MLEditSunken(int x, int y, int width, int height, const char* text, int scrollbar);
int ICG_MLEditThick(int x, int y, int width, int height, const char* text, int scrollbar);
int ICG_MLEditResizable(int x, int y, int width, int height, const char* text, int scrollbar);
//_____________SL EDIT_________________
//Plain single line edit
int ICG_SLEdit(int x, int y, int width, int height, const char* text);
//Single line edit with border
int ICG_SLEditBorder(int x, int y, int width, int height, const char* text);
int ICG_SLEditThick(int x, int y, int width, int height, const char* text);
//Single line edit with sunken border
int ICG_SLEditSunken(int x, int y, int width, int height, const char* text);
//Single line password with border
int ICG_SLPasswordB(int x, int y, int width, int height);
//Single line passwword with sunken border
int ICG_SLPasswordSunken(int x, int y, int width, int height);
//_____________IP ADDRESS____________
int ICG_IPAddressSunken(int x, int y, int width, int height, unsigned long ip);
int ICG_IPAddressThick(int x, int y, int width, int height, unsigned long ip);
//_____________FRAME_________________
int ICG_FramePanel(int x, int y, int width, int height);
int ICG_Frameless(int x, int y, int width, int height);
int ICG_FrameThin(int x, int y, int width, int height);
int ICG_FrameMedium(int x, int y, int width, int height);
int ICG_FrameThick(int x, int y, int width, int height);
int ICG_FrameSunken(int x, int y, int width, int height);
int ICG_FrameDeep(int x, int y, int width, int height);

//_____________STATIC_________________
int ICG_Static(int x, int y, int width, int height, const char* text);
int ICG_StaticBorder(int x, int y, int width, int height, const char* text);
int ICG_StaticSunken(int x, int y, int width, int height, const char* text);
int ICG_StaticPanel(int x, int y, int width, int height, const char* text);
int ICG_StaticThick(int x, int y, int width, int height, const char* text);
int ICG_MLStatic(int x, int y, int width, int height, const char* text);
int ICG_MLStaticBorder(int x, int y, int width, int height, const char* text);
int ICG_MLStaticPanel(int x, int y, int width, int height, const char* text);
int ICG_MLStaticSunken(int x, int y, int width, int height, const char* text);
int ICG_MLStaticThick(int x, int y, int width, int height, const char* text);
//_____________TRACKBAR_________________
int ICG_TrackBarH(int x, int y, int width, int height, const char* text, void (*callback)(int));
int ICG_GetTrackBarPos(HWND hwnd);

//____________LISTBOX________________________
int ICG_ListBox(int x, int y, int width, int height, void (*callback)(int), bool sort=false);
int ICG_AddToList(int handle, const char* text);
bool ICG_GetListItem(int handle, int index, ICBYTES& i);

bool ICG_AppendMenuItem(HMENU menu, const char* Item, void (*callback)());
char* OpenFileMenu(ICBYTES& path, const char* type);

int ICG_printf(const char* format, ...);
int ICG_printf(int handle, const char* format, ...);
void ICG_ClearText();
void ICG_ClearText(int handle);
int Print(int handle, ICBYTES& i);
void ICG_SetPrintWindow(HWND c);
void ICG_SetPrintWindow(int handle);