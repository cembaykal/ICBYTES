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

#define PROGRESSBAR_DICRETE		0
#define PROGRESSBAR_SMOOTH		1


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

//------------  MOUSE FUNCTIONS -----------------------

void ICG_SetOnMouseMove(void (*MouseFunc)(int, int));
int ICG_GetMouseX();
int ICG_GetMouseY();
void ICG_SetOnMouseLDown(void (*MouseFunc)());
void ICG_SetOnMouseLUp(void (*MouseFunc)());
void ICG_SetOnMouseLDBLClick(void (*MouseFunc)());
//------------  KEYBOARD FUNCTIONS -----------------------
void ICG_SetOnKeyPressed(void(*OnKeyPressedFunc)(int));
void ICG_SetOnKeyUp(void(*OnKeyPressedFunc)(int));
void ICG_SetOnExit(void(*OnExitFunc)(void*), void* t);
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
//_____________Rich EDIT_________________
int ICG_RichEdit(int x, int y, int width, int height, const char* text, int scrollbar);
int ICG_RichEditSunken(int x, int y, int width, int height, const char* text, int scrollbar);
int ICG_RichEditPanel(int x, int y, int width, int height, const char* text, int scrollbar);
int ICG_RichEditThick(int x, int y, int width, int height, const char* text, int scrollbar);
int ICG_RichEditResizable(int x, int y, int width, int height, const char* text, int scrollbar);
void ICG_SetFontColor(int handle, int BGR);
void ICG_SetRichColor(int handle, int BGR);
bool LoadFileToRichEdit(int handle, LPCTSTR pszFile);
void SaveRichEditToFile(int handle, const char* filename);
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
int ICG_TrackBarH(int x, int y, int width, int height, void (*callback)(int));
int ICG_TrackBarV(int x, int y, int width, int height, void (*callback)(int));
int ICG_GetTrackBarPos(int handle);
int ICG_GetTrackBarPos(HWND hwnd);
//_____________PROGRESS BAR_________________
int ICG_ProgressH(int x, int y, int width, int height, int type=0);
int ICG_SetProgressPos(int handle, int pos);
int ICG_SetProgressStep(int handle, int step);
int ICG_SetProgressRange(int handle, int min, int max);
//____________LISTBOX________________________
int ICG_ListBox(int x, int y, int width, int height, void (*callback)(int), bool sort=false);
int ICG_AddToList(int handle, const char* text);
bool ICG_GetListItem(int handle, int index, ICBYTES& i);

bool ICG_AppendMenuItem(HMENU menu, const char* Item, void (*callback)());
char* OpenFileMenu(ICBYTES& path, const char* type);
char* SaveFileMenu(ICBYTES& path, const char* type);
char* OpenDIRMenu(ICBYTES& path);

int ICG_printf(const char* format, ...);
int ICG_printf(int handle, const char* format, ...);
void ICG_SetprintfColor(unsigned int BGR);
void ICG_SetprintfFont(const char* font_name, int font_size = 15);
void ICG_SetprintfStyle(unsigned weight, bool ITALIC = false, bool UNDERLINE = false);
void ICG_ClearText();
void ICG_ClearText(int handle);
int Print(int handle, ICBYTES& i);
int PrintHex(int handle, ICBYTES& i, bool upper_case=false);
void ICG_SetPrintWindow(HWND c);
void ICG_SetPrintWindow(int handle);

void PrintJPGMap(int handle, ICBYTES& map);