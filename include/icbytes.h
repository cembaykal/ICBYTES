// THIS FILE IS A PART OF ICBYTES LIBRARY BETA VERSION
// WRITTEN BY IBRAHIM CEM BAYKAL
// THE LIBRARY IS PROVIDED AS IS. IF IT CAuSES ANY FINACIAL/DATA/PRESTIGE LOSS HE IS NOT RESPONSIBLE
#pragma once

#include <windows.h>
#include<initializer_list>

#ifdef _DEBUG
#define ICMDEBUG
#endif // _DEBUG

//Activate the following to debug in release mode.
//#define ICMDEBUG 

class ICBYTES
{
    //ICMETA* icb;
    unsigned long type;
    unsigned long dims;
    unsigned long len;
    unsigned long buflen;    
    unsigned long long picb;
public:
    ICBYTES();
    ICBYTES(int id);
    ICBYTES(std::initializer_list<int> l);
    ICBYTES(std::initializer_list<std::initializer_list<int>> l);
    ICBYTES(std::initializer_list<double> l);
    ICBYTES(std::initializer_list<std::initializer_list<double>> l);    
    ~ICBYTES();
    //___________________!!! INTERNAL USE ONLY! DO NOT USE!!! __________________
     unsigned long Gettype() { return type; }
    unsigned long Getbuflen() { return buflen; }
    long long GetMAT();
    unsigned long long Getpicb(){ return picb; }
    long long DataLen(long long datalen = -1);
    //___________________FAST DATA ACCESS / Veriye H�zl� Eri�im__________________
    char** C_=NULL;
    unsigned char** B_ = NULL;
    short** S_ = NULL;
    unsigned short** u_ = NULL;
    int** I_ = NULL;
    unsigned int** U_ = NULL;
    float** F_ = NULL;
    long long** L_ = NULL;
    unsigned long long** O_ = NULL;
    double** D_ = NULL;

    //___________________DATA ACCESS __________________
   

    HBITMAP GetHBitmap();
   
    long long X();
    long long X(long long y);
    long long Y();
    int Z();
    int W();
    //_________ UNSIGNED CHAR (BYTE)ACESS______________
    unsigned char& B(long long x);
    unsigned char& B(long long x, long long y);
    unsigned char& B(long long x, long long y, int z);
    //_________SAFE /SA�LAM UNSIGNED CHAR (BYTE)ACESS______________
    unsigned char& sB(long long x);
    unsigned char& sB(long long x, long long y);
    unsigned char& sB(long long x, long long y, int z);
    //_________  CHAR ACESS ___________________________
    char& C(long long x);
    char& C(long long x, long long y);
    char& C(long long x, long long y, int z);
    //_________ UNSIGNED SHORT ACESS __________________
    unsigned short& u(long long x);
    unsigned short& u(long long x, long long y);
    unsigned short& u(long long x, long long y, int z);
    //_________ SHORT INT ACESS _______________________
    short& S(long long x);
    short& S(long long x, long long y);
    short& S(long long x, long long y, int z);
    //_________ UNSIGNED INT(32) ACESS ________________
    unsigned int& U(long long x);
    unsigned int& U(long long x, long long y);
    unsigned int& U(long long x, long long y, int z);
    //_________ SAFE /SA�LAM UNSIGNED INT(32) ACESS ________________
    unsigned int& sU(long long x);
    unsigned int& sU(long long x, long long y);
    unsigned int& sU(long long x, long long y, int z);
    //_________  INT(32) ACESS ________________________
    int& I(long long x);
    int& I(long long x, long long y);
    int& I(long long x, long long y, int z);
    //_________  UNSIGNED LONG LONG(64) ACESS ____________
    unsigned long long& O(long long x);
    unsigned long long& O(long long x, long long y);
    unsigned long long& O(long long x, long long y, int z);
    //_________  LONG LONG(64) ACESS __________________
    long long& L(long long x);
    long long& L(long long x, long long y);
    long long& L(long long x, long long y, int z);
    //_________  FLOAT ACESS __________________________
    float& F(long long x);
    float& F(long long x, long long y);
    float& F(long long x, long long y, int z);
    //_________  DOUBLE ACESS _________________________
    double& D(long long x);
    double& D(long long x, long long y);
    double& D(long long x, long long y, int z);
  //___________________OPERATORS________________________
        
    template <class T> ICBYTES& operator = (T a);
    ICBYTES& operator = (ICBYTES& i);
    ICBYTES& operator = (const char*);

    bool operator == (ICBYTES& i);

    template <class T> void operator += (T a);
    void operator += (ICBYTES &i);
    char& operator[](int x);
    double operator()(int x);
    double operator()(int x,int y);
    double operator()(int x, int y,int z);

    template <class T> void operator -= (T a);
    void operator -= (ICBYTES& i);
    template <class T> void operator *= (T a);
    void operator *= (ICBYTES& i);
    template <class T> void operator /= (T a);
    void operator /= (ICBYTES& i);
    
    bool dot(ICBYTES& A, ICBYTES& B);   //C.dot(A,B) --> C=A.B
    bool cross(ICBYTES& A, ICBYTES& B); //C.cross(A,B) --> C=AxB
};

//________________________________________ FUNCTIONS___________________________________
int CreateMatrix(ICBYTES& i, long long x, long long y, int z, int w, int type);
int CreateMatrix(ICBYTES& m, long long x, long long y,int z,int type);
int CreateMatrix(ICBYTES& m, long long x, long long y, int type);
int CreateMatrix(ICBYTES& m, long long x, int type);

int CreateImage(ICBYTES& i, long long x, long long y, long z, unsigned long type);
int CreateImage(ICBYTES& i, long long x, long long y, int type);
int CreateFlippedImage(ICBYTES& i, long long x, long long y, long z, unsigned long type);
int CreateFlippedImage(ICBYTES& i, long long x, long long y, int type);
int IdentityMatrix(ICBYTES& i, long long s, int type);

int RandomUniform(ICBYTES& m, long long x, long long y, int z);
int RandomUniform(ICBYTES& m, long long x, long long y);
int RandomUniform(ICBYTES& m, long long x);

int RandomNormal(double mean, double stdev, ICBYTES& m, long long x, long long y, int z);
int RandomNormal(double mean, double stdev, ICBYTES& m, long long x, long long y);
int RandomNormal(double mean, double stdev, ICBYTES& m, long long x);

int IncreasingMatrix(ICBYTES& i, long long x, long long y, int z, int type);
int IncreasingMatrix(ICBYTES& i, long long x, long long y, int type);
int IncreasingMatrix(ICBYTES& i, long long x, int type);

int Magic(ICBYTES& m, int n);//Create Magic matrix//S�H�RL� MATR�S YARATIR 

//-------------------------------
int CreateVectorList(ICBYTES& v, int type);
void CreatePyramid(ICBYTES& V, long long Y, int type);
bool IsVectorList(ICBYTES& i);
template <typename T> void  push_back(ICBYTES& V, long long y, T i);
void push_back(ICBYTES& V, std::initializer_list<int> l);
void push_back(ICBYTES& V, std::initializer_list<double> l);
void* GetVector(ICBYTES& V, int nth);
void DeleteVector(ICBYTES& V, long long y);
void EraseElem(ICBYTES& V, long long y, long long xstart, long long xend = 0);
template<typename To> void Insert(ICBYTES& V, long long y, long long xstart, To val);
bool JoinVectors(ICBYTES& v, long long head, long long tail);
/*Inserts text string as a new line to vector List
Karakter sicimi vekt�r listesine yeni bir sat�r olarak ekler.*/
bool InsertText2List(ICBYTES& L, const char* text, long long textlen);



template <typename T> void Set(long long X, ICBYTES& i, T n);
template <typename T> void Set(long long X, long long Y, ICBYTES& i, T n);
template <typename T> void Set(long long X, long long Y, int Z, ICBYTES& i, T n);

double Get(long long X, ICBYTES& i);
double Get(long long X, long long Y, ICBYTES& i);
double Get(long long X, long long Y, int Z, ICBYTES& i);

int ResizeMatrix(ICBYTES& i, long long x, long long y);

bool ConvertType(ICBYTES& i, int type);



double determinant(ICBYTES& i);
bool inv(ICBYTES& i, ICBYTES& o);
bool transpose(ICBYTES& i, ICBYTES& o);

void MaxX(ICBYTES& inp, ICBYTES& max);
void MinX(ICBYTES& inp, ICBYTES& max);
void MaxY(ICBYTES& inp, ICBYTES& max);
void MinY(ICBYTES& inp, ICBYTES& max);
/*Sum of the elements of a matrix.
MATR�STEK� T�M ELEMANLARIN TOPLAMI.*/
double Sum(ICBYTES& inp);
void SumX(ICBYTES& inp, ICBYTES& sumx);
void SumY(ICBYTES& inp, ICBYTES& sumY);

void abs(ICBYTES& inp,ICBYTES &outp, unsigned type=-1);
void square(ICBYTES& inp, ICBYTES& outp, unsigned type=-1);
void sqrt(ICBYTES& inp, ICBYTES& outp, unsigned type);

int ICB_CreateVector(ICBYTES& v, int type);
template <typename T> void ICB_push_back(ICBYTES& v, T i);
void ICB_pop_back(ICBYTES& v);
long long ICB_Vector_Size(ICBYTES& v);
void ICB_Erase(ICBYTES& v);

bool Convert2ImageMatrix(ICBYTES& i);
int ICB_GetColorBits(ICBYTES& i);

int ICB_DisplayImage(HWND frame, ICBYTES& i);
void Reset(ICBYTES& i);
void Free(ICBYTES& m);
int ICB_Expand(ICBYTES& i, long long newsize);
int ICB_Enlarge(ICBYTES& i, long long newsize);
int Bitsize(int icbtype);
int ICB_GetContainerLen(ICBYTES& i);
int ICB_GetContainerLen(int type);
long long* SizeinArray(ICBYTES& i);// returns a long long[4] array (x,y,z,w)
ICBYTES & size(ICBYTES& i);//returns a matrix of size (4,1) (x,y,z,w)
int GetMatrixDims(ICBYTES& i);
//Returns variable trpe: char, int, float, double etc.
unsigned GetType(ICBYTES& i);
int ICB_GetContainerType(ICBYTES& i);
long long GetAddress(ICBYTES& i);
void SetAddress(ICBYTES& i, long long address);
bool IsFloating(ICBYTES& i);
bool IsMatrix(ICBYTES& i);
bool IsImageMatrix(ICBYTES& i);
bool AreDimsEqual(ICBYTES& i, ICBYTES& j);
bool AreEqualImage(ICBYTES& i, ICBYTES& j);
bool FlipV(ICBYTES& source, ICBYTES& destination);
long long GetData(ICBYTES& i);

bool Copy(ICBYTES& i,int x,int y,int w,int h, ICBYTES& o);
bool Paste(ICBYTES& i, int x, int y, ICBYTES& o);
bool PasteNon0(ICBYTES& copy, int x, int y, ICBYTES& to);


void print(ICBYTES& i);
void DisplayMatrix(HWND hwnd, ICBYTES& i);
void DisplayMatrix(ICBYTES& i);
void ICB_SetString(HWND hwnd, ICBYTES& i);

//________________________________________ FILE FUNCTIONS ___________________________________
int ReadAll(const char* filepath, ICBYTES& i);
//___________________BASIC FILTERS___________________________________________________________
void Filter_H(ICBYTES& inp, ICBYTES& outp, ICBYTES& Filter, unsigned output_type = -1, bool out_is_image = false);
void Filter_V(ICBYTES& inp, ICBYTES& outp, ICBYTES& Filter, unsigned output_type=-1, bool out_is_image = false);
void RoundFloat2Byte(ICBYTES& inp, ICBYTES& outp, bool out_is_image = false);
void RoundDouble2Byte(ICBYTES& inp, ICBYTES& outp, bool out_is_image = false);
//________________________________________ DESCRIPTOR DEFINITIONS___________________________________

//_______SIGN_________bit 1_________
#define ICB_SIGNED		0
#define ICB_UNSIGNED	1


//_______FIX/FLOAT_____bit 2________
#define ICB_FIXED_POINT	    0
#define ICB_FLOATING_POINT	2

//__CONTAINERS_______bit 3-4-5__
#define ICB_CBIT		0
#define ICB_CBYTE		4
#define ICB_CWORD		8
#define ICB_C24			12
#define ICB_CDWORD		16
#define ICB_C40			20
#define ICB_C64			24
#define ICB_C128		28
//__BIT LENGTH_______bits 6-7-8___________
#define ICB_FULL		0		//entire container
#define ICB_1BIT		32
#define ICB_2BIT		64
#define ICB_3BIT		96
#define ICB_4BIT		128
#define ICB_5BIT		160
#define ICB_6BIT		192
#define ICB_7BIT		224
#define ICB_8BIT		256		//entire container
#define ICB_9BIT		288
#define ICB_10BIT		320
#define ICB_11BIT		352
#define ICB_12BIT		384
#define ICB_13BIT		416
#define ICB_14BIT		448
#define ICB_15BIT		480




//#define ICB_SINGLE_BIT_BUNCH    512  //Normally, container of 8 bit contains 4 consecutive ICB_2BIT (ie)
                                     //if you use this, there will be only 2 bits in 8 bit container.

#define ICB_CHAR			4
#define ICB_UCHAR			5
#define ICB_BYTE			5
#define ICB_SHORT			8
#define ICB_USHORT			9
#define ICB_I24		    	12      //NOT IMPLEMENTED YET
#define ICB_UI24			13      //NOT IMPLEMENTED YET
#define ICB_INT				16
#define ICB_UINT			17
#define ICB_FLOAT			18
#define ICB_I40 			20      //NOT IMPLEMENTED YET
#define ICB_UI40			21      //NOT IMPLEMENTED YET
#define ICB_LONGLONG		24
#define ICB_ULONGLONG		25
#define ICB_DOUBLE			26
#define ICB_I128 			28      //NOT IMPLEMENTED YET
#define ICB_UI128			29      //NOT IMPLEMENTED YET




//a�a��dakiler int ICB_GetMatrixDims(ICBYTES& i) fonksiyonu taraf�ndan d�d�r�l�r.
#define ICB_HAS_X           1
#define ICB_HAS_Y           2
#define ICB_HAS_XY          3
#define ICB_HAS_Z           4
#define ICB_HAS_XZ          5
#define ICB_HAS_YZ          6
#define ICB_HAS_XYZ         7
#define ICB_HAS_W           8
#define ICB_HAS_XW          9
#define ICB_HAS_YW          10
#define ICB_HAS_XYW         11
#define ICB_HAS_ZW          12
#define ICB_HAS_XZW         13
#define ICB_HAS_YZW         14
#define ICB_HAS_XYZW        15
//______________________________________
#define ICB_TEXT             8192
#define ICB_CSTRING          ICB_TEXT|ICB_CHAR
#define ICB_WSTRING          ICB_TEXT|ICB_USHORT
//#define ICB_HUMAN_NAME       ICB_TEXT+1
//#define ICB_FILEPATH         ICB_TEXT+2
//raw image extraints[0]contains bytesperpix,[1]x size [2]y size.
#define ICB_PICTURE          262144
#define ICB_BMP              262145
#define ICB_JPEG             262146
#define ICB_GRAY             262147

#define ICB_SPECIFIC         0X80000
#define SCANM(M)    for(int y=1;y<=M.Y();y++){for(int x=1;x<=M.X();x++){
//-------------------------------------------------------
//-------------------- DIAGNOSTICS -----------------------------
class ICBDIAG
{
public:
    HWND outwin = 0;
    void SetError(ICBYTES& i, int error, long long indx);
    void SetError(int mdid, int error);
    void SetError(int mdid, int error, long long indx);
    void SetOutput(HWND c) { outwin = c; }
};
