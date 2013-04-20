#include <Servo.h>

#define SERVOPIN	(9)
#define VOLUMEPIN	(0)

Servo g_servo;
int iValue = 0;
int i = 0;
char data[] = {225, 289, 243, 189, 208, 204, 209, 262, 191, 200, 209, 220, 231, 198, 197, 237, 210, 215, 227, 205, 214, 217, 207, 225, 233, 228, 207, 196, 218, 191, 225, 237, 227, 239, 215, 216, 214, 253, 205, 200, 171, 181, 167, 168, 199, 198, 218, 265, 227, 226, 240, 214, 211, 212, 235, 212, 222, 229, 223, 224, 218, 202, 196, 207, 200, 187, 201, 207, 189, 183, 191, 228, 235, 212, 188, 190, 196, 202, 196, 185, 175, 173, 176, 190, 207, 201, 183, 183, 183, 180, 184, 196, 220, 220, 204, 188, 196, 208, 214, 201, 182, 166, 183, 211, 220, 231, 283, 316, 212, 241, 206, 204, 202, 237, 193, 198, 211, 221, 244, 222, 213, 248, 225, 217, 209, 210, 228, 225, 214, 194, 225, 212, 192, 170, 184, 220, 316, 181, 215, 247, 195, 215, 218, 203, 227, 211, 210, 216, 236, 235, 212, 207, 226, 235, 216, 198, 196, 195, 209, 222, 213, 206, 213, 198, 198, 204, 208, 203, 195, 212, 232, 217, 200, 194, 202, 230, 367, 265, 229, 195, 241, 225, 187, 178, 191, 194, 239, 222, 198, 218, 241, 301, 238, 244, 196, 221, 227, 189, 264};


void setup() 
{ 

  Serial.begin(9600);
  g_servo.attach(SERVOPIN);
} 

int Map( int iIn, int iIn1, int iIn2, int iOut1, int iOut2, boolean bConstrain = false )
{
	double dValue = (double)(iIn - iIn1) * (iOut2 - iOut1) / (iIn2 - iIn1) + iOut1;
	int iValue = (0 < dValue) ? (int)(dValue + 0.5) : (int)(dValue - 0.5);
	if( bConstrain )
	{
		int iOutMin, iOutMax;
		if( iOut1 < iOut2 )
		{
			iOutMin= iOut1;
			iOutMax= iOut2;
		}
		else
		{
			iOutMin= iOut2;
			iOutMax= iOut1;
		}
		if( iOutMin > iValue )
		{
			return iOutMin;
		}
		if( iOutMax < iValue )
		{
			return iOutMax;
		}
	}
	return iValue;
}

void loop() 
{ 
//	int iValue = analogRead(VOLUMEPIN);
/*  int iAngle = Map(iValue, 0, 360, 0, 380, true);
  g_servo.write(iAngle);
  delay(15);
    if (iValue < 360){
//      iValue = iValue + 20;
  }else{
    iValue = 0;
  }*/

  int iAngle = Map(data[i], 166, 367, 0, 180, true);
  g_servo.write(iAngle);  
//  Serial.println(i);

  i++;
  if(i>10){
    i = 0;
  }
//  Serial.println(i);
  Serial.println(iAngle);
  delay(200);
  
} 

/*
const int analogOutPin = 8;
void setup(){
  Serial.begin(9600); 
}

void loop(){
  //可変抵抗器の値を読み込み４で割る
//  int val=analogRead(0)/4;
  int var = 0;
  if(var < 255)
  {
     analogWrite(analogOutPin,var); //0~255
     var = var +20;
     delay(20);
  }
  //アナログ出力

  //0.05秒ループにする
  delay(20);
}
*/
