#include "KeyInputString.h"
#include "Event.h"

const unsigned int RED = GetColor( 255 , 0 , 0 );///<  @brief à–¾
const unsigned int GREEN = GetColor( 0 , 255 , 0 );///<  @brief à–¾
const unsigned int BLUE = GetColor( 0 , 0 , 255 );///<  @brief à–¾
const unsigned int BLACK = GetColor( 0 , 0 , 0 );///<  @brief à–¾
const unsigned int WHITE = GetColor( 255 , 255 , 255 );///<  @brief à–¾
const unsigned int GRAY = GetColor( 128 , 128 , 128 );///<  @brief à–¾
const unsigned int LIGHTBLUE = GetColor( 128 , 128 , 255 );///<  @brief à–¾
const unsigned int LIGHTGREEN = GetColor( 128 , 255 , 128 );///<  @brief à–¾
const unsigned int M_PINK = GetColor( 255 , 128 , 128 );///<  @brief à–¾
const unsigned int YELLOW = GetColor( 255 , 255 , 0);///<  @brief à–¾

unsigned int back = GetColor(255,255,255);
unsigned int frame = GetColor(0,0,0);
int font = NULL;
unsigned int fontColor = GetColor(255,255,255);

void suken::CKeyInputString::Draw(int x, int y, bool activeOnly, int x2, int y2) {
		if (CheckKeyInput(data) == 1) {
			writing = 0;
			if (link == tInt) {
				*intLink = GetKeyInputNumber(data);
			}
			if (link == tStr) {
				GetKeyInputString(mem,data);
				*strLink = mem;
			}
		}
		if(CheckKeyInput(data) == 2){
			writing = 0;
		}
		if (writing == 0 && activeOnly == false) {
			if (link == tInt) {
				if(font == NULL){
					DrawFormatString(x+1, y, fontColor, "%d",*intLink);
				}else{
					DrawFormatStringToHandle(x+1, y, fontColor,font, "%d",*intLink);
				}
			}
			if (link == tStr) {
				if(font == NULL){
					DrawString(x+1, y, strLink->c_str(), fontColor);
				}else{
					DrawStringToHandle(x+1, y, strLink->c_str(), fontColor,font);
				}
			}
		}
		if (writing == 1){
			DrawBox(x, y, x + width, y + height, back, true);
			DrawBox(x, y, x + width, y + height, frame, false);
			DrawKeyInputString(x+1, y,data);
		}
		if(Event.LMouse.GetClick(x, y,x2 == 0 ? x + width : x2,y2 == 0 ? y + height : y2)){
				active();
		}
	}

void suken::SetKeyInputStringColor(unsigned int NmlStr, unsigned int NmlCur, unsigned int back_, unsigned int frame_,int font_,unsigned int fontColor_){
	DxLib::SetKeyInputStringColor(NmlStr,NmlCur,GetColor(50,50,50),RED,WHITE,
		GetColor(100,100,100),WHITE,BLACK,BLACK,BLACK,GRAY,WHITE,
		GetColor(200,200,200),BLACK,BLACK,GetColor(254,254,254),BLACK);
	back = back_;
	frame = frame_;
	font = font_;
	fontColor = fontColor_;
}