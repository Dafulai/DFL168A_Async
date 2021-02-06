#include "Arduino.h"
#include "DFL168A_Async.h"
GPSClass::GPSClass(){
  Baudrate=9600;
  Timeout=500;  //time out is 500ms;
  Pareant=NULL;
}

GPSClass::GPSClass(long Baudrate,int Timeout, class DFL168A * Pareant ){
  this->Baudrate=Baudrate;
  this->Timeout=Timeout;
  this->Pareant=Pareant;
}
byte GPSClass::SendGPSCMD(const char * CMD)
{
  static byte retrnV=SUCCESS;
  //version 1.1.1 Jan 21/2021 modification---------Begin
  //unsigned long tick4timeout;
  static unsigned long tick4timeout;
  static char MyReceiveData[256];
  static int index_MyReceiveData = 0;
  //version 1.1.1 Jan 21/2021 modification---------End
  String StrResult;
 

  if (WAITING!=retrnV) {tick4timeout=millis(); Pareant->mySerial->println(CMD); }
  
  if (-1 == Pareant->mySerial->peek())
  {
	  if (millis() - tick4timeout <= (Timeout + 50))
	  {
		  if (index_MyReceiveData > 1)
		  {
			  goto GotResponseJudge;
		  }
		  retrnV = WAITING; return WAITING;
	  }
	  else
	  {
		  if (index_MyReceiveData > 1)
		  {
			  if ('>' == MyReceiveData[index_MyReceiveData - 1]) goto GotResponseJudge;
		  }
		  while (Pareant->mySerial->available()) Pareant->mySerial->read(); //clear buffer  
		  
		  index_MyReceiveData = 0; //for next time use
		  retrnV = FAIL; return FAIL;
	  }
  }
  else
  {
	  //has char received
	  MyReceiveData[index_MyReceiveData++] = Pareant->mySerial->read();
	  retrnV = WAITING;
	  return WAITING;
  }
GotResponseJudge:
  if ('>' == MyReceiveData[index_MyReceiveData - 1])
  {
	  MyReceiveData[index_MyReceiveData - 1] = '\0';
	  StrResult = String(MyReceiveData);
	  index_MyReceiveData = 0;  //for next time use
  }
  else
  {
	  retrnV = WAITING;
	  return WAITING;
  }
  //StrResult=Pareant->mySerial->readStringUntil('>');
  StrResult.trim(); 
  if ( StrResult=="OK") retrnV=SUCCESS; else retrnV=FAIL;
  
  return  retrnV;
}

byte GPSClass::getGPSinfo(float &Latitude,float &Longitude, int &Speed /*Km/h*/, String &Time /*hh:mm::ss*/, String &Date /*dd/mm/yyyy*/)
{
  //byte retrnV;
  static byte retrnV = SUCCESS;
  //unsigned long tick4timeout;
  static unsigned long tick4timeout;
  String StrResult;
  String subStringR;
  int Space_Index;
  float tempF;
  char XXX[15];
  bool Minus_Result;

  static unsigned char stateM = 0;

  static float Latitude_mirror;
  static float Longitude_mirror;
  static int Speed_mirror;
  static String Time_mirror;
    
  static char MyReceiveData[128];
  static int index_MyReceiveData = 0;
  /*
  Pareant->mySerial->setTimeout(Timeout+50);
  if (!Pareant->ATCommand("ATDEV1SIGBSOF1")) {  Pareant->mySerial->setTimeout((Pareant->Timeout)+50); return false;}   //"AT DEV1 SI GB SOF 3" FOR GMC Sentence
  Pareant->mySerial->setTimeout((Pareant->Timeout)+50);
  */
  if (0 == stateM)
  {
	  if (retrnV != WAITING)
	  {
		  tick4timeout = millis();
		  retrnV = SendGPSCMD("ATDEV1SIGBSOF1");
		  return retrnV;
	  }
	  if ((WAITING == retrnV) || (FAIL == retrnV)) {
		  if (FAIL == retrnV)
		  {
			  stateM = 0;
		  }
		  else
		  {
			  retrnV = SendGPSCMD("ATDEV1SIGBSOF1");
		  }
		  return retrnV;
	  }
	  else
	  {
		  retrnV = 100;
		  stateM = 1;
		  return WAITING;
	  }  
  }
  else if (1 == stateM)
  {
	  if (100 == retrnV)
	  {
		  tick4timeout = millis();
		  Pareant->mySerial->println("AT DEV1 LAT");
		  index_MyReceiveData = 0;
		  retrnV = WAITING;
		  return WAITING;
	  }	  
	  if (-1==Pareant->mySerial->peek())
	  {		  

		  if (millis() - tick4timeout<1000)
		  {
			  if (index_MyReceiveData > 1)
			  {
				  goto GotResponseJudge;
			  }
			  retrnV = WAITING; return WAITING;
		  }
		  else
		  {
			  if (index_MyReceiveData > 1)
			  {
				 if ('>'== MyReceiveData[index_MyReceiveData-1]) goto GotResponseJudge;
			  }
			  while (Pareant->mySerial->available()) Pareant->mySerial->read(); //clear buffer  
			  stateM = 0;
			  index_MyReceiveData = 0; //for next time use
			  retrnV = FAIL; return FAIL;
		  }
	  }
	  else
	  {
		  //has char received
		  MyReceiveData[index_MyReceiveData++]= Pareant->mySerial->read();
		  retrnV = WAITING;
		  return WAITING;
	  }
  GotResponseJudge:
	  if ('>' == MyReceiveData[index_MyReceiveData - 1])
	  {
		  MyReceiveData[index_MyReceiveData-1] = '\0';
		  StrResult = String(MyReceiveData);
		  index_MyReceiveData = 0;  //for next time use
	  }
	  else
	  {
		  retrnV = WAITING;
		  return WAITING;
	  }
	  //we got '>'
	  //StrResult = Pareant->mySerial->readStringUntil('>');
	  StrResult.trim();  //"+25 33.456'"
	  if (StrResult == "") { stateM = 0; retrnV = FAIL; return retrnV; }
	  if ('?' == StrResult.charAt(0)) { stateM = 0; retrnV = FAIL; return retrnV; }
	  if ('N' == StrResult.charAt(0)) { stateM = 0; retrnV = FAIL; return retrnV; }

	  if ('-' == StrResult.charAt(0)) Minus_Result = true;  else Minus_Result = false; //in case "-0 22.89'" ,How about ""-78.98'" ? we don't know if it has "0 " before 78.98'  Check 20 0' situation: 20 or 20 0' in DFL168A source code
	  Space_Index = StrResult.indexOf(' ');
	  subStringR = StrResult.substring(0, Space_Index);
	  subStringR.toCharArray(XXX, 15);
	  tempF = atof(XXX);
	  Latitude_mirror = tempF;

	  StrResult = StrResult.substring(Space_Index + 1);
	  Space_Index = StrResult.indexOf('\'');
	  subStringR = StrResult.substring(0, Space_Index);
	  subStringR.toCharArray(XXX, 15);
	  tempF = atof(XXX);
	  tempF = tempF / 60.0;
	  if (Minus_Result) Latitude_mirror -= tempF; else Latitude_mirror += tempF;

	  retrnV = 100;
	  stateM = 2;
	  return WAITING;
  }  
  else if (2 == stateM)
  {
	  if (100 == retrnV)
	  {
		  tick4timeout = millis();
		  Pareant->mySerial->println("AT DEV1 LONG");
		  index_MyReceiveData = 0;
		  retrnV = WAITING;
		  return WAITING;
	  }
	  if (-1 == Pareant->mySerial->peek())
	  {
		  if (millis() - tick4timeout<1000)
		  {
			  if (index_MyReceiveData > 1)
			  {
				  goto GotResponseJudge2;
			  }
			  retrnV = WAITING; return WAITING;
		  }
		  else
		  {
			  if (index_MyReceiveData > 1)
			  {
				  if ('>' == MyReceiveData[index_MyReceiveData - 1]) goto GotResponseJudge2;
			  }
			  while (Pareant->mySerial->available()) Pareant->mySerial->read();   //clear Receiving buffer
			  index_MyReceiveData = 0; //for next time use
			  stateM = 0;
			  retrnV = FAIL; return FAIL;
		  }
	  }
	  else
	  {
		  //has char received
		  MyReceiveData[index_MyReceiveData++] = Pareant->mySerial->read();
		  retrnV = WAITING;
		  return WAITING;
	  }
  GotResponseJudge2:
	  if ('>' == MyReceiveData[index_MyReceiveData - 1])
	  {
		  MyReceiveData[index_MyReceiveData-1] = '\0';
		  StrResult = String(MyReceiveData);
		  index_MyReceiveData = 0;  //for next time use
	  }
	  else
	  {
		  retrnV = WAITING;
		  return WAITING;
	  }
	  //StrResult = Pareant->mySerial->readStringUntil('>');
	  StrResult.trim();  //"+25 33.456'"

	  if (StrResult == "") { stateM = 0; retrnV = FAIL; return retrnV; }
	  if ('?' == StrResult.charAt(0)) { stateM = 0; retrnV = FAIL; return retrnV; }
	  if ('N' == StrResult.charAt(0)) { stateM = 0; retrnV = FAIL; return retrnV; }

	  if ('-' == StrResult.charAt(0)) Minus_Result = true;  else Minus_Result = false;  //in case "-0 22.89'" ,How about ""-78.98'" ? we don't know if it has "0 " before 78.98'
	  Space_Index = StrResult.indexOf(' ');
	  subStringR = StrResult.substring(0, Space_Index);
	  subStringR.toCharArray(XXX, 15);
	  tempF = atof(XXX);
	  Longitude_mirror = tempF;

	  StrResult = StrResult.substring(Space_Index + 1);
	  Space_Index = StrResult.indexOf('\'');
	  subStringR = StrResult.substring(0, Space_Index);
	  subStringR.toCharArray(XXX, 15);
	  tempF = atof(XXX);
	  tempF = tempF / 60.0;
	  if (Minus_Result) Longitude_mirror -= tempF; else Longitude_mirror += tempF;
	  retrnV = 100;
	  stateM = 3;
	  return WAITING;
  }
  else if (3 == stateM)
  {
	  if (100 == retrnV)
	  {
		  tick4timeout = millis();
		  Pareant->mySerial->println("AT DEV1 SPEED");
		  index_MyReceiveData = 0;
		  retrnV = WAITING;
		  return WAITING;
	  }
	  if (-1==Pareant->mySerial->peek())
	  {
		  if (millis() - tick4timeout<1000)
		  {
			  if (index_MyReceiveData > 1)
			  {
				  goto GotResponseJudge3;
			  }
			  retrnV = WAITING; return WAITING;
		  }
		  else
		  {
			  if (index_MyReceiveData > 1)
			  {
				  if ('>' == MyReceiveData[index_MyReceiveData - 1]) goto GotResponseJudge3;
			  }
			  while (Pareant->mySerial->available()) Pareant->mySerial->read();   //clear Receiving buffer
			  index_MyReceiveData = 0; //for next time use
			  stateM = 0;
			  retrnV = FAIL; return FAIL;
		  }
	  }
	  else
	  {
		  //has char received
		  MyReceiveData[index_MyReceiveData++] = Pareant->mySerial->read();
		  retrnV = WAITING;
		  return WAITING;
	  }

  GotResponseJudge3:
	  if ('>' == MyReceiveData[index_MyReceiveData - 1])
	  {
		  MyReceiveData[index_MyReceiveData-1] = '\0';
		  StrResult = String(MyReceiveData);
		  index_MyReceiveData = 0;  //for next time use
	  }
	  else
	  {
		  retrnV = WAITING;
		  return WAITING;
	  }
	  //StrResult = Pareant->mySerial->readStringUntil('>');
	  StrResult.trim();  //"56.7"



	  if (StrResult == "") { stateM = 0; retrnV = FAIL; return retrnV; }
	  if ('?' == StrResult.charAt(0)) { stateM = 0; retrnV = FAIL; return retrnV; }
	  if ('N' == StrResult.charAt(0)) { stateM = 0; retrnV = FAIL; return retrnV; }

	  StrResult.toCharArray(XXX, 15);
	  tempF = atof(XXX);
	  Speed_mirror = tempF * 1.852;
	  retrnV = 100;
	  stateM = 4;
	  return WAITING;
  }
  else if (4 == stateM)
  {
	  if (100 == retrnV)
	  {
		  tick4timeout = millis();
		  Pareant->mySerial->println("AT DEV1 TIME");
		  index_MyReceiveData = 0;
		  retrnV = WAITING;
		  return WAITING;
	  }
	  if (-1==Pareant->mySerial->peek())
	  {
		  if (millis() - tick4timeout<1000)
		  {
			  if (index_MyReceiveData > 1)
			  {
				  goto GotResponseJudge4;
			  }
			  retrnV = WAITING; return WAITING;
		  }
		  else
		  {
			  if (index_MyReceiveData > 1)
			  {
				  if ('>' == MyReceiveData[index_MyReceiveData - 1]) goto GotResponseJudge4;
			  }
			  while (Pareant->mySerial->available()) Pareant->mySerial->read();   //clear Receiving buffer
			  index_MyReceiveData = 0;  //for next time use
			  stateM = 0;
			  retrnV = FAIL; return FAIL;
		  }
	  }
	  else
	  {
		  //has char received
		  MyReceiveData[index_MyReceiveData++] = Pareant->mySerial->read();
		  retrnV = WAITING;
		  return WAITING;
	  }

  GotResponseJudge4:
	  if ('>' == MyReceiveData[index_MyReceiveData - 1])
	  {
		  MyReceiveData[index_MyReceiveData-1] = '\0';
		  StrResult = String(MyReceiveData);
		  index_MyReceiveData = 0;  //for next time use
	  }
	  else
	  {
		  retrnV = WAITING;
		  return WAITING;
	  }


	  //StrResult = Pareant->mySerial->readStringUntil('>');
	  StrResult.trim();  //"20:58:31"
	  if (StrResult == "") { stateM = 0; retrnV = FAIL; return retrnV; }
	  if ('?' == StrResult.charAt(0)) { stateM = 0; retrnV = FAIL; return retrnV; }
	  if ('N' == StrResult.charAt(0)) { stateM = 0; retrnV = FAIL; return retrnV; }
	  Time_mirror = StrResult;
	  retrnV = 100;
	  stateM = 5;
	  return WAITING;
  }
  else if (5 == stateM)
  {
	  if (100 == retrnV)
	  {
		  tick4timeout = millis();
		  Pareant->mySerial->println("AT DEV1 DATE");
		  index_MyReceiveData = 0;
		  retrnV = WAITING;
		  return WAITING;
	  }
	  if (-1==Pareant->mySerial->peek())
	  {
		  if (millis() - tick4timeout<1000)
		  {
			  if (index_MyReceiveData > 1)
			  {
				  goto GotResponseJudge5;
			  }
			  retrnV = WAITING; return WAITING;
		  }
		  else
		  {
			  if (index_MyReceiveData > 1)
			  {
				  if ('>' == MyReceiveData[index_MyReceiveData - 1]) goto GotResponseJudge5;
			  }
			  while (Pareant->mySerial->available()) Pareant->mySerial->read();   //clear Receiving buffer
			  index_MyReceiveData = 0;  //for next time use
			  stateM = 0;
			  retrnV = FAIL; return FAIL;
		  }
	  }
	  else
	  {
		  //has char received
		  MyReceiveData[index_MyReceiveData++] = Pareant->mySerial->read();
		  retrnV = WAITING;
		  return WAITING;
	  }
  GotResponseJudge5:
	  if ('>' == MyReceiveData[index_MyReceiveData - 1])
	  {
		  MyReceiveData[index_MyReceiveData - 1] = '\0';
		  StrResult = String(MyReceiveData);
		  index_MyReceiveData = 0;  //for next time use
	  }
	  else
	  {
		  retrnV = WAITING;
		  return WAITING;
	  }


	  //StrResult = Pareant->mySerial->readStringUntil('>');
	  StrResult.trim();  //"20:58:31"


	  if (StrResult == "") { stateM = 0; retrnV = FAIL; return retrnV; }
	  if ('?' == StrResult.charAt(0)) { stateM = 0; retrnV = FAIL; return retrnV; }
	  if ('N' == StrResult.charAt(0)) { stateM = 0; retrnV = FAIL; return retrnV; }
	  Date = StrResult;

	  Latitude = Latitude_mirror;
	  Longitude = Longitude_mirror;
	  Speed = Speed_mirror;
	  Time = Time_mirror;

	  stateM = 0;
	  retrnV = SUCCESS;
	  return retrnV;
  }  
  
}

byte GPSClass::getAltitude(float &Altitude /*Meter*/)
{
  static byte retrnV = SUCCESS;
  static unsigned long tick4timeout;
  static unsigned char stateM = 0;
  String StrResult;  
  char XXX[15];
  
  static char MyReceiveData[128];
  static int index_MyReceiveData = 0;

  //retrnV=SendGPSCMD("ATDEV1SIGBSOF2");
  //if ((WAITING==retrnV)||(FAIL==retrnV)) {return retrnV;}  
  if (0 == stateM)
  {
	  if (retrnV != WAITING)
	  {
		  tick4timeout = millis();
		  retrnV = SendGPSCMD("ATDEV1SIGBSOF2");
		  return retrnV;
	  }
	  if ((WAITING == retrnV) || (FAIL == retrnV)) {
		  if (FAIL == retrnV)
		  {
			  stateM = 0;
		  }
		  else
		  {
			  retrnV = SendGPSCMD("ATDEV1SIGBSOF2");
		  }
		  return retrnV;
	  }
	  else
	  {
		  retrnV = 100;
		  stateM = 1;
		  return WAITING;
	  }
  }
  else if (1 == stateM)
  {
	  if (100 == retrnV)
	  {
		  tick4timeout = millis();
		  Pareant->mySerial->println("AT DEV1 ALT");
		  index_MyReceiveData = 0;
		  retrnV = WAITING;
		  return WAITING;
	  }
	  if (-1==Pareant->mySerial->peek())
	  {
		  if (millis() - tick4timeout<1000)
		  {
			  if (index_MyReceiveData > 1)
			  {
				  goto GotResponseJudge;
			  }
			  retrnV = WAITING; return WAITING;
		  }
		  else
		  {
			  if (index_MyReceiveData > 1)
			  {
				  if ('>' == MyReceiveData[index_MyReceiveData - 1]) goto GotResponseJudge;
			  }
			  while (Pareant->mySerial->available()) Pareant->mySerial->read();   //clear Receiving buffer
			  index_MyReceiveData = 0;  //for next time use
			  stateM = 0;
			  retrnV = FAIL; return FAIL;
		  }
	  }
	  else
	  {
		  //has char received
		  MyReceiveData[index_MyReceiveData++] = Pareant->mySerial->read();
		  retrnV = WAITING;
		  return WAITING;
	  }
  GotResponseJudge:
	  if ('>' == MyReceiveData[index_MyReceiveData - 1])
	  {
		  MyReceiveData[index_MyReceiveData - 1] = '\0';
		  StrResult = String(MyReceiveData);
		  index_MyReceiveData = 0;  //for next time use
	  }
	  else
	  {
		  retrnV = WAITING;
		  return WAITING;
	  }

	  //StrResult = Pareant->mySerial->readStringUntil('>');
	  StrResult.trim();  //"5608"
	  if (StrResult == "") { stateM = 0; retrnV = FAIL; return retrnV; }
	  if ('?' == StrResult.charAt(0)) { stateM = 0; retrnV = FAIL; return retrnV; }
	  if ('N' == StrResult.charAt(0)) { stateM = 0; retrnV = FAIL; return retrnV; }

	  StrResult.toCharArray(XXX, 15);
	  Altitude = atof(XXX);

	  stateM = 0;
	  retrnV = SUCCESS;
	  return retrnV;
  }

}


