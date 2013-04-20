#include <Servo.h>

#define SERVOPIN	(9)
#define VOLUMEPIN	(0)

Servo g_servo;
int iValue = 0;
int i = 0;

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
  int data[]={0,60,120,180,120,60};
  int iAngle = Map(data[i], 0, 180, 0, 180, true);
  g_servo.write(iAngle);  
//  Serial.println(i);

  i++;
  if(i>5){
    i = 0;
  }
//  Serial.println(i);
  Serial.println(iAngle);
  delay(1000);
  
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
