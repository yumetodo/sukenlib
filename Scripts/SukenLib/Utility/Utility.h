#pragma once
#include"../Manager.h"
#include "DxLib.h"
#include <string>

namespace megademo  // http://www.demoscene.jp/?p=1460
{
	struct RGB
	{
	//	RGB(){}

	//	RGB( float r_, float g_, float b_ ) : r(r_),g(g_),b(b_){}

		float r,g,b;	// [0.0f, 1.0f]
	};

}

extern megademo::RGB rgb;

namespace suken{

const unsigned int RED = GetColor( 255 , 0 , 0 );///<  @brief ����
const unsigned int GREEN = GetColor( 0 , 255 , 0 );///<  @brief ����
const unsigned int BLUE = GetColor( 0 , 0 , 255 );///<  @brief ����
const unsigned int BLACK = GetColor( 0 , 0 , 0 );///<  @brief ����
const unsigned int WHITE = GetColor( 255 , 255 , 255 );///<  @brief ����
const unsigned int GRAY = GetColor( 128 , 128 , 128 );///<  @brief ����
const unsigned int LIGHTBLUE = GetColor( 128 , 128 , 255 );///<  @brief ����
const unsigned int LIGHTGREEN = GetColor( 128 , 255 , 128 );///<  @brief ����
const unsigned int M_PINK = GetColor( 255 , 128 , 128 );///<  @brief ����
const unsigned int YELLOW = GetColor( 255 , 255 , 0);///<  @brief ����

const int SHUIRO = GetColor(221,72,39);
const int ORANGE= GetColor(230,121,40);
const int HIIRO= GetColor(199,60,46);
const int KIMIDORI= GetColor(170,204,59);
const int NAVY= GetColor(23,37,64);
const int SCARLET= GetColor(223,84,69);
const int WAKAKUSA= GetColor(187,211,71);
const int KONNIRO= GetColor(29,49,86);
const int KURENAI= GetColor(189,66,90);
const int ROSE= GetColor(220,67,95);
const int AOMIDORI= GetColor(0,163,136);
const int SHIONIRO= GetColor(89,71,140);
const int CYAN= GetColor(0,163,219);
const int SKYBLUE= GetColor(142,209,224);
const int MIIRO= GetColor(5,102,184);
const int SAKURAIRO= GetColor(252,238,235);
const int SAKURA= GetColor(255,234,250);

int RainBow(int time=0);

#define RAINBOW RainBow()

#define RAINBOW_RGB (RainBow(),rgb.r*255),rgb.g*255,rgb.b*255

#define RAINBOW_RGB_TIME(time) (RainBow( time ),rgb.r*255),rgb.g*255,rgb.b*255

unsigned int GetColorHSV(int h,int s,int v);

#define HSV_TO_RGB(h,s,v) (GetColorHSV( h , s , v ),rgb.r*255),rgb.g*255rgb.b*255

/**
*	@brief �_�C�A���O���J���āA�B
*	�}�b�v�G�f�B�^�Ȃǂ������Ƃ��ɕ֗�����
*	@param  filename �J�������t�@�C�������i�[����������
*	@param filetype ���ݖ���
* @return true
*/
bool SelectOpenFile(  char* filename ,  char* filetype = "all file(*.*)\0*.*\0\0");
/**
*	@brief �_�C�A���O���J���āA�t�@�C�����ۑ������B
*	�}�b�v�G�f�B�^�Ȃǂ������Ƃ��ɕ֗�����
*	@param  filename �ۑ��������t�@�C�������i�[����������
*	@param filetype ���ݖ���
* @return true
*/
bool SaveFile( char* filename , char* filetype =  "all file(*.*)\0*.*\0\0");
/*
�����s���G���[�̂��߃R�����g�A�E�g
void GetHttpFile(std::string &Buf,std::string Http,unsigned long ReadSize = 65536);
*/



/////FROM NUNULIB
//���ݎ����擾�֐�///////////////////////////////////////////

/**
*	@brief ����
* @return �߂��l
*/
SYSTEMTIME GetNowSystemTime();  //SYSTEMTIME�^�œ��{�������擾

/**
*	@brief ����
* @return �߂��l
*/
std::string GetNowSystemTimeString();  //string�^(00/00/00 00:00:00 000)�Ō��ݓ��{�������擾

/**
*	@brief ����
*	@param value ����
* @return �߂��l
*/
inline int DrawCenterString(int cx, int y, const TCHAR *String, unsigned int color, bool centerY=false)
{ //x�����E�̒��S�ɂ���DrawString�ŕ����`���i��y�͏㉺���S�ł͂Ȃ����Ӂj
    if (centerY){
        return DxLib::DrawString(cx-GetDrawStringWidth(String, strlen(String))/2, y-GetFontSize()/2, String, color);    //�����܂Ŗڈ� 
    }else{
        return DxLib::DrawString(cx-GetDrawStringWidth(String, strlen(String))/2, y, String, color); 
    }
}

/**
*	@brief ����
*	@param value ����
* @return �߂��l
*/
int DrawCenterString(int cx, int y, unsigned int color, const TCHAR* format, ...);

/**
*	@brief ����
*	@param value ����
* @return �߂��l
*/
int DrawCenterString(int cx, int y, unsigned int color, bool centerY, const TCHAR* format, ...);

/////////////////////////////////////////////////////////////

//////////////////////////////////////

/**
*	@brief ����
*	@param value ����
*/
void AddFontFromPath(std::string path);

/**
*	@brief ����
*	@param value ����
*/
void SukenExecute(std::string URL);


/**
*	@brief ����
*	@param value ����
* @return �߂��l
*/
unsigned int fanctorial(unsigned int num);			//

/**
*	@brief ����
*	@param value ����
* @return �߂��l
*/
unsigned int combination(unsigned int n , unsigned int r);					//nCr�Ƃ����邠���B�g�ݍ��킹


}
