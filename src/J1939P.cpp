#include "Arduino.h"
#include "DFL168A_Async.h"
PGN65256Class::PGN65256Class() {
  SuccessFresh=false;
  Pareant=NULL;
}

PGN65256Class::PGN65256Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN65269Class::PGN65269Class() {
  SuccessFresh=false;
  Pareant=NULL;
}

PGN65269Class::PGN65269Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN65257Class::PGN65257Class() {
  SuccessFresh=false;
  Pareant=NULL;
}

PGN65257Class::PGN65257Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN61444Class::PGN61444Class() {
  SuccessFresh=false;
  Pareant=NULL;
}

PGN61444Class::PGN61444Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN61443Class::PGN61443Class() {
  SuccessFresh=false;
  Pareant=NULL;
}

PGN61443Class::PGN61443Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN65270Class::PGN65270Class() {
  SuccessFresh=false;
  Pareant=NULL;
}

PGN65270Class::PGN65270Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN65271Class::PGN65271Class() {
  SuccessFresh=false;
  Pareant=NULL;
}

PGN65271Class::PGN65271Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}
PGN65272Class::PGN65272Class() {
  SuccessFresh=false;
  Pareant=NULL;
}

PGN65272Class::PGN65272Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN65266Class::PGN65266Class() {
  SuccessFresh=false;
  Pareant=NULL;
}
PGN65266Class::PGN65266Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN65263Class::PGN65263Class() {
  SuccessFresh=false;
  Pareant=NULL;
}
PGN65263Class::PGN65263Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN65253Class::PGN65253Class() {
  SuccessFresh=false;
  Pareant=NULL;
}
PGN65253Class::PGN65253Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN65214Class::PGN65214Class() {
  SuccessFresh=false;
  Pareant=NULL;
}
PGN65214Class::PGN65214Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN65248Class::PGN65248Class() {
  SuccessFresh=false;
  Pareant=NULL;
}
PGN65248Class::PGN65248Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN65276Class::PGN65276Class() {
  SuccessFresh=false;
  Pareant=NULL;
}
PGN65276Class::PGN65276Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN65265Class::PGN65265Class() {
  SuccessFresh=false;
  Pareant=NULL;
}
PGN65265Class::PGN65265Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}
PGN57344Class::PGN57344Class() {
  SuccessFresh=false;
  Pareant=NULL;
}
PGN57344Class::PGN57344Class(class DFL168A * Pareant) {
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN65267Class::PGN65267Class() {
  //Latitude=-99000.0;
  //Longitude=-99000.0;
  SuccessFresh=false;
  Pareant=NULL;
}
PGN65267Class::PGN65267Class(class DFL168A * Pareant) {
  //Latitude=-99000.0;
  //Longitude=-99000.0;
  SuccessFresh=false;
  this->Pareant=Pareant;
}

PGN65262Class::PGN65262Class() {
  //CoolantTemp=-32768;
  //FuelTemp=-32768;
  //OilTemp=-32768;
  SuccessFresh=false;
  Pareant=NULL;
}
PGN65262Class::PGN65262Class(class DFL168A * Pareant) {
  //CoolantTemp=-32768;
  //FuelTemp=-32768;
  //OilTemp=-32768;
  SuccessFresh=false;
  this->Pareant=Pareant;
}

//version 1.0.2 add ---start
PGN64996Class::PGN64996Class() {
	SuccessFresh = false;
	Pareant = NULL;
}
PGN64996Class::PGN64996Class(class DFL168A * Pareant) {
	SuccessFresh = false;
	this->Pareant = Pareant;
}
PGN61445Class::PGN61445Class() {
	SuccessFresh = false;
	Pareant = NULL;
}
PGN61445Class::PGN61445Class(class DFL168A * Pareant) {
	SuccessFresh = false;
	this->Pareant = Pareant;
}
//version 1.0.2 add ---end
//version 1.0.2 add ---start
/*
J1939Class::J1939Class():PGN65256(),PGN65269(),PGN65257(),PGN61444(),PGN61443(),PGN65270(),PGN65271(),PGN65272(),PGN65266(),PGN65263(),PGN65253(),PGN65214(),PGN65248(),PGN65276(),PGN65265(),PGN57344(),PGN65267(),PGN65262() {
  Baudrate=250000;  //250k
  Pareant=NULL;
}

J1939Class::J1939Class(long Baudrate,class DFL168A * Pareant):PGN65256(Pareant),PGN65269(Pareant),PGN65257(Pareant),PGN61444(Pareant),PGN61443(Pareant),PGN65270(Pareant),PGN65271(Pareant),PGN65272(Pareant),PGN65266(Pareant),
                                                              PGN65263(Pareant),PGN65253(Pareant),PGN65214(Pareant),PGN65248(Pareant),PGN65276(Pareant),PGN65265(Pareant),PGN57344(Pareant),PGN65267(Pareant),PGN65262(Pareant) {
  this->Baudrate=Baudrate;
  this->Pareant=Pareant;
}*/
J1939Class::J1939Class() :PGN65256(), PGN65269(), PGN65257(), PGN61444(), PGN61443(), PGN65270(), PGN65271(), PGN65272(), PGN65266(), PGN65263(), PGN65253(), PGN65214(), PGN65248(), PGN65276(), PGN65265(), PGN57344(), PGN65267(), PGN65262(), PGN64996(), PGN61445() {
	Baudrate = 250000;  //250k
	Pareant = NULL;
}

J1939Class::J1939Class(long Baudrate, class DFL168A * Pareant) : PGN65256(Pareant), PGN65269(Pareant), PGN65257(Pareant), PGN61444(Pareant), PGN61443(Pareant), PGN65270(Pareant), PGN65271(Pareant), PGN65272(Pareant), PGN65266(Pareant),
PGN65263(Pareant), PGN65253(Pareant), PGN65214(Pareant), PGN65248(Pareant), PGN65276(Pareant), PGN65265(Pareant), PGN57344(Pareant), PGN65267(Pareant), PGN65262(Pareant), PGN64996(Pareant), PGN61445(Pareant) {
	this->Baudrate = Baudrate;
	this->Pareant = Pareant;
}
//version 1.0.2 add ---end
byte J1939Class::getVIN(String &VIN)
{ 
  byte temp;
  char bufferx[20];
  char HexValue[]="0x00";
  byte i;
  temp=Pareant->DigitalCommand("FEEC");
  if (WAITING==temp) {  return WAITING;}
  if (FAIL==temp) {  return FAIL;}
  Pareant->HandleResponse(Pareant->ReturnStr); 
  for (i=0;i<(Pareant->ReturnStr.length())/2;i++)
  {
     HexValue[2]=Pareant->ReturnStr.charAt(i*2);
     HexValue[3]=Pareant->ReturnStr.charAt(i*2+1);
     bufferx[i]=strtol(HexValue,NULL,16);
  }
  bufferx[(Pareant->ReturnStr.length())/2]='\0';
  VIN=bufferx;
  return SUCCESS;
}

byte J1939Class::getDTC(byte &DTC_Num, long  (&SPN)[5], byte (&FMI)[5], byte (&CM)[5],byte (&OC)[5], byte DTCFormat=1 )
{
  byte temp;
  String StrDTC;
  int len,i;
  char HEX4byte[]="0x00000000";
  unsigned long DTC4bytes;
  temp=Pareant->DigitalCommand("FECA");
  if (WAITING==temp) {  return WAITING;}
  if (FAIL==temp) {  return FAIL;}
  Pareant->HandleResponse(Pareant->ReturnStr); 
  StrDTC=Pareant->ReturnStr;
  StrDTC.trim();  
  len=StrDTC.length();    
  DTC_Num=0;
  //DTCFormat only can be 1,2,3,4
  //byte 1 is fault lamp, byte 2 is flash lamp
  if ((('0'==StrDTC.charAt(0))||('3'==StrDTC.charAt(0))||('C'==StrDTC.charAt(0))||('F'==StrDTC.charAt(0)))&&
      (('0'==StrDTC.charAt(1))||('3'==StrDTC.charAt(1))||('C'==StrDTC.charAt(1))||('F'==StrDTC.charAt(1)))&&
      (('0'==StrDTC.charAt(2))||('3'==StrDTC.charAt(2))||('C'==StrDTC.charAt(2))||('F'==StrDTC.charAt(2)))&&
      (('0'==StrDTC.charAt(3))||('3'==StrDTC.charAt(3))||('C'==StrDTC.charAt(3))||('F'==StrDTC.charAt(3))))
  {
      //DTC_Num=0;
      return SUCCESS;
  } 
  
  //has fault
  if (len<12) { return FAIL; }
  for (i=4;i<=len-8;i=i+8)
  {
     HEX4byte[2]=StrDTC.charAt(i);
     HEX4byte[3]=StrDTC.charAt(i+1);  
     HEX4byte[4]=StrDTC.charAt(i+2);  
     HEX4byte[5]=StrDTC.charAt(i+3);  
     HEX4byte[6]=StrDTC.charAt(i+4);
     HEX4byte[7]=StrDTC.charAt(i+5);  
     HEX4byte[8]=StrDTC.charAt(i+6);  
     HEX4byte[9]=StrDTC.charAt(i+7);
     
     DTC4bytes=strtoul(HEX4byte,NULL,16);
     if (0xffffffff==DTC4bytes) return SUCCESS;
     
     OC[DTC_Num]=(byte)(DTC4bytes&0x7f);
     CM[DTC_Num]=(byte)((DTC4bytes>>7)&0X01);
     FMI[DTC_Num]=(byte)((DTC4bytes>>8)&0X1F);
     switch(DTCFormat)
     {
      case 1:
        SPN[DTC_Num]=((DTC4bytes>>13)&0X7ffff);  //19 bits's SPN
        break;
      case 2:
        SPN[DTC_Num]=/*Least significant 3 bit */((DTC4bytes>>13)&0X7)|/*high 8 bit of 16 most sig spn*/((DTC4bytes>>5)&0X07f800)|/*low 8 bit of 16 most sig spn*/((DTC4bytes>>21)&0X07f8);  //19 bits's SPN
        break;
      case 3:
      case 4:
        SPN[DTC_Num]=/*3 most significant 3 bit */((DTC4bytes<<3)&0X70000)|/*high 8 bit of 16 least sig spn*/((DTC4bytes>>8)&0X0ff00)|/*low 8 bit of 16 least sig spn*/((DTC4bytes>>24)&0X0ff);  //19 bits's SPN        
        break;
      default:
        return FAIL;
     }
     DTC_Num++;
     if (DTC_Num>=5) return SUCCESS; //in case over the array max index
     
  }
  
  return SUCCESS;
}

byte J1939Class::clearDTC()
{
  byte temp;
  temp=Pareant->DigitalCommand("FED3");
  if (WAITING==temp) {  return WAITING;}
  if (FAIL==temp) {  return FAIL;}  
  return SUCCESS;
}

byte PGN65262Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEEE");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}

bool  PGN65262Class::getCoolantTemperature(int &temp)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(0);
  Hex1Byte[3]=FreshResultStr.charAt(1);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  //CoolantTemp=tempV-40;
   temp=tempV-40;
  //temp=CoolantTemp;   
  return true;
}

bool  PGN65262Class::getFuelTemp(int &temp)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(2);
  Hex1Byte[3]=FreshResultStr.charAt(3);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  temp=tempV-40;  
  return true;
}

bool  PGN65262Class::getOilTemp(int &temp)
{
  char Hex2Byte[]="0x0000";
  long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(6);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(7);
  Hex2Byte[4]=FreshResultStr.charAt(4);
  Hex2Byte[5]=FreshResultStr.charAt(5);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;
  tempFloat=tempV*0.03125-273.0;
  if (tempFloat>=0) temp=(int)(tempFloat+0.5);   //round to integer must consider minus number
  else temp=(int)(tempFloat-0.5);  
  return true;
}

byte PGN65267Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEF3");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}

bool  PGN65267Class::getLatitude(float &Latitude)
{
  char Hex4Byte[]="0x00000000";
  unsigned long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex4Byte[2]=FreshResultStr.charAt(6);  //Littlt endian
  Hex4Byte[3]=FreshResultStr.charAt(7);
  Hex4Byte[4]=FreshResultStr.charAt(4);
  Hex4Byte[5]=FreshResultStr.charAt(5);
  Hex4Byte[6]=FreshResultStr.charAt(2);
  Hex4Byte[7]=FreshResultStr.charAt(3);
  Hex4Byte[8]=FreshResultStr.charAt(0);
  Hex4Byte[9]=FreshResultStr.charAt(1);
  tempV=strtoul(Hex4Byte,NULL,16);
  //Serial.print("latitude:");  Serial.println(tempV);
  if (tempV>0xfaffffff) return false;
  tempFloat=tempV*0.0000001-210.0;
  Latitude=tempFloat;
  return true;
}


bool  PGN65267Class::getLongitude(float &Longitude)
{
  char Hex4Byte[]="0x00000000";
  unsigned long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex4Byte[2]=FreshResultStr.charAt(14);  //Littlt endian
  Hex4Byte[3]=FreshResultStr.charAt(15);
  Hex4Byte[4]=FreshResultStr.charAt(12);
  Hex4Byte[5]=FreshResultStr.charAt(13);
  Hex4Byte[6]=FreshResultStr.charAt(10);
  Hex4Byte[7]=FreshResultStr.charAt(11);
  Hex4Byte[8]=FreshResultStr.charAt(8);
  Hex4Byte[9]=FreshResultStr.charAt(9);
  tempV=strtoul(Hex4Byte,NULL,16);
  //Serial.print("Longitude:");  Serial.println(tempV);
  if (tempV>0xfaffffff) return false;
  tempFloat=tempV*0.0000001-210.0;
  Longitude=tempFloat;
  return true;
}

byte PGN65256Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEE8");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;}  
     
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}

boolean PGN65256Class::getAltitude(float &Altitude)
{
  char Hex2Byte[]="0x0000";
  long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(14);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(15);
  Hex2Byte[4]=FreshResultStr.charAt(12);
  Hex2Byte[5]=FreshResultStr.charAt(13);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;
  tempFloat=tempV*0.125-2500.0;
  Altitude=tempFloat;
  return true;
}

boolean PGN65256Class::getNavBasedSpeed(float &Speed)
{
  char Hex2Byte[]="0x0000";
  long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(6);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(7);
  Hex2Byte[4]=FreshResultStr.charAt(4);
  Hex2Byte[5]=FreshResultStr.charAt(5);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;
  tempFloat=tempV/256.0;
  Speed=tempFloat;
  return true;
}

byte PGN65269Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEF5");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
    
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}

bool PGN65269Class::getBarometricPressure(float &BaroPressure)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(0);
  Hex1Byte[3]=FreshResultStr.charAt(1);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  BaroPressure=tempV*0.5;  //0.5kpa/bit
  return true;
}

bool PGN65269Class::getAmbientTemp(int &AmbientTemp)
{
  char Hex2Byte[]="0x0000";
  long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(8);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(9);
  Hex2Byte[4]=FreshResultStr.charAt(6);
  Hex2Byte[5]=FreshResultStr.charAt(7);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;
  tempFloat=tempV*0.03125-273.0;
  if (tempFloat>=0) AmbientTemp=(int)(tempFloat+0.5);   //round to integer must consider minus number
  else AmbientTemp=(int)(tempFloat-0.5);  
  return true;
}

bool PGN65269Class::getInletTemp(int &InletTemp)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(10);
  Hex1Byte[3]=FreshResultStr.charAt(11);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  InletTemp=tempV-40;  
  return true;
}

bool PGN65269Class::getRoadTemp(int &RoadTemp)
{
  char Hex2Byte[]="0x0000";
  long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(14);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(15);
  Hex2Byte[4]=FreshResultStr.charAt(12);
  Hex2Byte[5]=FreshResultStr.charAt(13);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;
  tempFloat=tempV*0.03125-273.0;
  if (tempFloat>=0) RoadTemp=(int)(tempFloat+0.5);   //round to integer must consider minus number
  else RoadTemp=(int)(tempFloat-0.5);  
  return true;
}

bool PGN65269Class::getCabInteriorTemp(int &CabInteriorTemp)
{
  char Hex2Byte[]="0x0000";
  long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(4);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(5);
  Hex2Byte[4]=FreshResultStr.charAt(2);
  Hex2Byte[5]=FreshResultStr.charAt(3);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;
  tempFloat=tempV*0.03125-273.0;
  if (tempFloat>=0) CabInteriorTemp=(int)(tempFloat+0.5);   //round to integer must consider minus number
  else CabInteriorTemp=(int)(tempFloat-0.5);  
  return true;
}

byte PGN65257Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEE9");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
   
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}

bool  PGN65257Class::getEngineTripFuel(float &EngineTripFuel)
{
  char Hex4Byte[]="0x00000000";
  unsigned long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex4Byte[2]=FreshResultStr.charAt(6);  //Littlt endian
  Hex4Byte[3]=FreshResultStr.charAt(7);
  Hex4Byte[4]=FreshResultStr.charAt(4);
  Hex4Byte[5]=FreshResultStr.charAt(5);
  Hex4Byte[6]=FreshResultStr.charAt(2);
  Hex4Byte[7]=FreshResultStr.charAt(3);
  Hex4Byte[8]=FreshResultStr.charAt(0);
  Hex4Byte[9]=FreshResultStr.charAt(1);
  tempV=strtoul(Hex4Byte,NULL,16);
  //Serial.print("latitude:");  Serial.println(tempV);
  if (tempV>0xfaffffff) return false;
  tempFloat=tempV*0.5;
  EngineTripFuel=tempFloat;
  return true;
}

bool  PGN65257Class::getEngineTotalFuelUsed(float &EngineTotalFuelUsed)
{
  char Hex4Byte[]="0x00000000";
  unsigned long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex4Byte[2]=FreshResultStr.charAt(14);  //Littlt endian
  Hex4Byte[3]=FreshResultStr.charAt(15);
  Hex4Byte[4]=FreshResultStr.charAt(12);
  Hex4Byte[5]=FreshResultStr.charAt(13);
  Hex4Byte[6]=FreshResultStr.charAt(10);
  Hex4Byte[7]=FreshResultStr.charAt(11);
  Hex4Byte[8]=FreshResultStr.charAt(8);
  Hex4Byte[9]=FreshResultStr.charAt(9);
  tempV=strtoul(Hex4Byte,NULL,16);
  //Serial.print("latitude:");  Serial.println(tempV);
  if (tempV>0xfaffffff) return false;
  tempFloat=tempV*0.5;
  EngineTotalFuelUsed=tempFloat;
  return true;
}

byte PGN61444Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("F004");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
   
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}

bool PGN61444Class::getActualEngineTorque(int &ActualEngineTorque)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(4);
  Hex1Byte[3]=FreshResultStr.charAt(5);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  ActualEngineTorque=tempV-125;  
  return true;
}

bool PGN61444Class::getEngineSpeed(int &EngineSpeed)
{
  char Hex2Byte[]="0x0000";
  long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(8);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(9);
  Hex2Byte[4]=FreshResultStr.charAt(6);
  Hex2Byte[5]=FreshResultStr.charAt(7);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;
  tempFloat=tempV*0.125;
  EngineSpeed=(int)(tempFloat+0.5);   //round to integer must consider minus number 
  return true;
}

byte PGN61443Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("F003");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
  //if (!Pareant->DigitalCommand("F003")) { SuccessFresh=false; return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}
bool PGN61443Class::getAccelPedalPosi1(float &AccelPedalPosi1)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(2);
  Hex1Byte[3]=FreshResultStr.charAt(3);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  AccelPedalPosi1=tempV*0.4;  
  return true;
}
bool PGN61443Class::getAccelPedalPosi2(float &AccelPedalPosi2)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(8);
  Hex1Byte[3]=FreshResultStr.charAt(9);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  AccelPedalPosi2=tempV*0.4;  
  return true;
}
bool PGN61443Class::getEnginePerLoadAtCurrSpeed(int &EnginePerLoadAtCurrSpeed)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(4);
  Hex1Byte[3]=FreshResultStr.charAt(5);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  EnginePerLoadAtCurrSpeed=tempV;  
  return true;
}

byte PGN65270Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEF6");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
  //if (!Pareant->DigitalCommand("FEF6")) { SuccessFresh=false; return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}
bool PGN65270Class::getIntakeManifoldPressure(int &IntakeManifoldPressure)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(2);
  Hex1Byte[3]=FreshResultStr.charAt(3);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  IntakeManifoldPressure=tempV*2;  
  return true;
}
bool PGN65270Class::getIntakeManifoldTemp(int &IntakeManifoldTemp)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(4);
  Hex1Byte[3]=FreshResultStr.charAt(5);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  IntakeManifoldTemp=tempV-40;  
  return true;
}
bool PGN65270Class::getEngineAirInletPressure(int &EngineAirInletPressure)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(6);
  Hex1Byte[3]=FreshResultStr.charAt(7);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  EngineAirInletPressure=tempV*2;  
  return true;
}
bool PGN65270Class::getEngineExhaustGasTemp(int &EngineExhaustGasTemp)
{
  char Hex2Byte[]="0x0000";
  long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(12);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(13);
  Hex2Byte[4]=FreshResultStr.charAt(10);
  Hex2Byte[5]=FreshResultStr.charAt(11);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;
  tempFloat=tempV*0.03125-273.0;
  if (tempFloat>=0) EngineExhaustGasTemp=(int)(tempFloat+0.5);   //round to integer must consider minus number
  else EngineExhaustGasTemp=(int)(tempFloat-0.5);  
  return true;
}
bool PGN65270Class::getEngineAirFilterDiffPressure(float &EngineAirFilterDiffPressure)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(8);
  Hex1Byte[3]=FreshResultStr.charAt(9);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  EngineAirFilterDiffPressure=tempV*0.05;  
  return true;
}

byte PGN65271Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEF7");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
  //if (!Pareant->DigitalCommand("FEF7")) { SuccessFresh=false; return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}
bool PGN65271Class::getAlternatorVoltage(float &AlternatorVoltage)
{
  char Hex2Byte[]="0x0000";
  long tempV;  
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(6);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(7);
  Hex2Byte[4]=FreshResultStr.charAt(4);
  Hex2Byte[5]=FreshResultStr.charAt(5);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;  
  AlternatorVoltage=tempV*0.05;  
  return true;
}
bool PGN65271Class::getElectricalVoltage(float &ElectricalVoltage)
{
  char Hex2Byte[]="0x0000";
  long tempV;  
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(10);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(11);
  Hex2Byte[4]=FreshResultStr.charAt(8);
  Hex2Byte[5]=FreshResultStr.charAt(9);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;  
  ElectricalVoltage=tempV*0.05;  
  return true;
}
bool PGN65271Class::getBatteryVoltage(float &BatteryVoltage)
{
  char Hex2Byte[]="0x0000";
  long tempV;  
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(14);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(15);
  Hex2Byte[4]=FreshResultStr.charAt(12);
  Hex2Byte[5]=FreshResultStr.charAt(13);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;  
  BatteryVoltage=tempV*0.05;  
  return true;
}

byte PGN65272Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEF8");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
  //if (!Pareant->DigitalCommand("FEF8")) { SuccessFresh=false; return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}
bool PGN65272Class::getTransmissionOilLevel(float &Percent)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(2);
  Hex1Byte[3]=FreshResultStr.charAt(3);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  Percent=tempV*0.4;  
  return true;
}
bool PGN65272Class::getTransmissionOilLevelHighLow(float &HighLow)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(12);
  Hex1Byte[3]=FreshResultStr.charAt(13);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  HighLow=tempV*0.5-62.5;  
  return true;
}
bool PGN65272Class::getTransmissionOilPressure(float &Pressure) //0 to 4000 kPa, 16 kPa/bit, 4th posion
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(6);
  Hex1Byte[3]=FreshResultStr.charAt(7);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  Pressure=tempV*16;  
  return true;
}
bool PGN65272Class::getTransmissionOilTemp(float &Temperature)//-273 to 1734.96875 deg C, 0.03125 deg C/bit, 5th and 6th
{
  char Hex2Byte[]="0x0000";
  long tempV;  
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(10);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(11);
  Hex2Byte[4]=FreshResultStr.charAt(8);
  Hex2Byte[5]=FreshResultStr.charAt(9);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;  
  Temperature=tempV*0.03125-273.0;  
  return true;
}

byte PGN65266Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEF2");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
  //if (!Pareant->DigitalCommand("FEF2")) { SuccessFresh=false; return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}
bool PGN65266Class::getFuelRate(float &FuelRate)
{
  char Hex2Byte[]="0x0000";
  long tempV;  
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(2);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(3);
  Hex2Byte[4]=FreshResultStr.charAt(0);
  Hex2Byte[5]=FreshResultStr.charAt(1);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;  
 FuelRate=tempV*0.05;  
  return true;
}
bool PGN65266Class::getInstantFuelEconomy(float &InstantFuelEconomy)
{
  char Hex2Byte[]="0x0000";
  long tempV;  
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(6);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(7);
  Hex2Byte[4]=FreshResultStr.charAt(4);
  Hex2Byte[5]=FreshResultStr.charAt(5);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;  
 InstantFuelEconomy=tempV/512.0;  
  return true;
}
bool PGN65266Class::getAvgFuelEconomy(float &AvgFuelEconomy)
{
  char Hex2Byte[]="0x0000";
  long tempV;  
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(10);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(11);
  Hex2Byte[4]=FreshResultStr.charAt(8);
  Hex2Byte[5]=FreshResultStr.charAt(9);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;  
  AvgFuelEconomy=tempV/512.0;  
  return true;
}
bool PGN65266Class::getEngineThrottlePos(float &EngineThrottlePos)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(12);
  Hex1Byte[3]=FreshResultStr.charAt(13);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  EngineThrottlePos=tempV*0.4;  //%
  return true;
}

byte PGN65263Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEEF");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
  //if (!Pareant->DigitalCommand("FEEF")) { SuccessFresh=false; return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}
bool PGN65263Class::getFueDeliveryPressure(int &FueDeliveryPressure)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(0);
  Hex1Byte[3]=FreshResultStr.charAt(1);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  FueDeliveryPressure=tempV*4;  
  return true;
}
bool PGN65263Class::getEngineOilLevel(float &EngineOilLevel)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(4);
  Hex1Byte[3]=FreshResultStr.charAt(5);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  EngineOilLevel=tempV*0.4;  //%
  return true;
}
bool PGN65263Class::getEngineOilPressure(int &EngineOilPressure)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(6);
  Hex1Byte[3]=FreshResultStr.charAt(7);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  EngineOilPressure=tempV*4;  
  return true;
}
bool PGN65263Class::getEngineCoolantPressure(int &EngineCoolantPressure)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(12);
  Hex1Byte[3]=FreshResultStr.charAt(13);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  EngineCoolantPressure=tempV*2;  
  return true;
}
bool PGN65263Class::getEngineCoolantLevel(float &EngineCoolantLevel)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(14);
  Hex1Byte[3]=FreshResultStr.charAt(15);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  EngineCoolantLevel=tempV*0.4;  //%
  return true;
}

byte PGN65253Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEE5");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
  //if (!Pareant->DigitalCommand("FEE5")) { SuccessFresh=false; return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}
bool  PGN65253Class::getTotalEngineHours(float &TotalEngineHours)
{
  char Hex4Byte[]="0x00000000";
  unsigned long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex4Byte[2]=FreshResultStr.charAt(6);  //Littlt endian
  Hex4Byte[3]=FreshResultStr.charAt(7);
  Hex4Byte[4]=FreshResultStr.charAt(4);
  Hex4Byte[5]=FreshResultStr.charAt(5);
  Hex4Byte[6]=FreshResultStr.charAt(2);
  Hex4Byte[7]=FreshResultStr.charAt(3);
  Hex4Byte[8]=FreshResultStr.charAt(0);
  Hex4Byte[9]=FreshResultStr.charAt(1);
  tempV=strtoul(Hex4Byte,NULL,16);
  //Serial.print("latitude:");  Serial.println(tempV);
  if (tempV>0xfaffffff) return false;
  tempFloat=tempV*0.05;
  TotalEngineHours=tempFloat;
  return true;
}
bool  PGN65253Class::getTotalEngineRevolutions(float &TotalEngineRevolutions)
{
  char Hex4Byte[]="0x00000000";
  unsigned long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex4Byte[2]=FreshResultStr.charAt(14);  //Littlt endian
  Hex4Byte[3]=FreshResultStr.charAt(15);
  Hex4Byte[4]=FreshResultStr.charAt(12);
  Hex4Byte[5]=FreshResultStr.charAt(13);
  Hex4Byte[6]=FreshResultStr.charAt(10);
  Hex4Byte[7]=FreshResultStr.charAt(11);
  Hex4Byte[8]=FreshResultStr.charAt(8);
  Hex4Byte[9]=FreshResultStr.charAt(9);
  tempV=strtoul(Hex4Byte,NULL,16);
  //Serial.print("latitude:");  Serial.println(tempV);
  if (tempV>0xfaffffff) return false;
  tempFloat=tempV*1000.0;
  TotalEngineRevolutions=tempFloat;
  return true;
}

byte PGN65214Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEBE");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
  //if (!Pareant->DigitalCommand("FEBE")) { SuccessFresh=false; return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}
bool PGN65214Class::getRatedEngineSpeed(float &RatedEngineSpeed)
{
  char Hex2Byte[]="0x0000";
  long tempV;  
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(6);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(7);
  Hex2Byte[4]=FreshResultStr.charAt(4);
  Hex2Byte[5]=FreshResultStr.charAt(5);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;  
  RatedEngineSpeed=tempV*0.125;  
  return true;
}

byte PGN65248Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEE0");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
  //if (!Pareant->DigitalCommand("FEE0")) { SuccessFresh=false; return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}
bool  PGN65248Class::getTripDistance(float &TripDistance)
{
  char Hex4Byte[]="0x00000000";
  unsigned long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex4Byte[2]=FreshResultStr.charAt(6);  //Littlt endian
  Hex4Byte[3]=FreshResultStr.charAt(7);
  Hex4Byte[4]=FreshResultStr.charAt(4);
  Hex4Byte[5]=FreshResultStr.charAt(5);
  Hex4Byte[6]=FreshResultStr.charAt(2);
  Hex4Byte[7]=FreshResultStr.charAt(3);
  Hex4Byte[8]=FreshResultStr.charAt(0);
  Hex4Byte[9]=FreshResultStr.charAt(1);
  tempV=strtoul(Hex4Byte,NULL,16);
  //Serial.print("latitude:");  Serial.println(tempV);
  if (tempV>0xfaffffff) return false;
  tempFloat=tempV*0.125;
  TripDistance=tempFloat;
  return true;
}
bool  PGN65248Class::getTotalDistance(float &TotalDistance)
{
  char Hex4Byte[]="0x00000000";
  unsigned long tempV;
  float tempFloat;
  if (!SuccessFresh) return false;
  Hex4Byte[2]=FreshResultStr.charAt(14);  //Littlt endian
  Hex4Byte[3]=FreshResultStr.charAt(15);
  Hex4Byte[4]=FreshResultStr.charAt(12);
  Hex4Byte[5]=FreshResultStr.charAt(13);
  Hex4Byte[6]=FreshResultStr.charAt(10);
  Hex4Byte[7]=FreshResultStr.charAt(11);
  Hex4Byte[8]=FreshResultStr.charAt(8);
  Hex4Byte[9]=FreshResultStr.charAt(9);
  tempV=strtoul(Hex4Byte,NULL,16);
  //Serial.print("latitude:");  Serial.println(tempV);
  if (tempV>0xfaffffff) return false;
  tempFloat=tempV*0.125;
  TotalDistance=tempFloat;
  return true;
}

byte PGN65276Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEFC");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
  //if (!Pareant->DigitalCommand("FEFC")) { SuccessFresh=false; return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}
bool PGN65276Class::getWasherFluidLevel(float &WasherFluidLevel)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(0);
  Hex1Byte[3]=FreshResultStr.charAt(1);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  WasherFluidLevel=tempV*0.4;  //%
  return true;
}
bool PGN65276Class::getFuelLevel1(float &FuelLevel1)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(2);
  Hex1Byte[3]=FreshResultStr.charAt(3);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  FuelLevel1=tempV*0.4;  //%
  return true;
}
bool PGN65276Class::getFuelLevel2(float &WasherFluidLevel2)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(12);
  Hex1Byte[3]=FreshResultStr.charAt(13);
  tempV=strtol(Hex1Byte,NULL,16);
  if (tempV>0xfa) return false;
  WasherFluidLevel2=tempV*0.4;  //%
  return true;
}

byte PGN65265Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("FEF1");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
  //if (!Pareant->DigitalCommand("FEF1")) { SuccessFresh=false; return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}
bool PGN65265Class::getWheelBasedVehicleSpeed(float &WheelBasedVehicleSpeed)
{
  char Hex2Byte[]="0x0000";
  long tempV;  
  if (!SuccessFresh) return false;
  Hex2Byte[2]=FreshResultStr.charAt(4);  //Littlt endian
  Hex2Byte[3]=FreshResultStr.charAt(5);
  Hex2Byte[4]=FreshResultStr.charAt(2);
  Hex2Byte[5]=FreshResultStr.charAt(3);
  tempV=strtol(Hex2Byte,NULL,16);  
  if (tempV>0xfaff) return false;  
  WheelBasedVehicleSpeed=tempV/256.0;  
  return true;
}
//Mar07 2019 add SPN70 and SPN597 start
bool PGN65265Class::getParkingBrake(bool &ParkingBreakSet)
{
	char Hex1Byte[] = "0x00";
	long tempV;
	if (!SuccessFresh) return false;
	Hex1Byte[2] = FreshResultStr.charAt(0);
	Hex1Byte[3] = FreshResultStr.charAt(1);
	tempV = strtol(Hex1Byte, NULL, 16);
	tempV = (tempV >> 2) & 0x3;
	if (0b01 == tempV) ParkingBreakSet = true;
	else if (0b00 == tempV) ParkingBreakSet = false;
	else
	{
		ParkingBreakSet = false;
		return false;
	}
	return true;
}
bool PGN65265Class::getBrake(bool &BreakPedalDepressed)
{
	char Hex1Byte[] = "0x00";
	long tempV;
	if (!SuccessFresh) return false;
	Hex1Byte[2] = FreshResultStr.charAt(6);
	Hex1Byte[3] = FreshResultStr.charAt(7);
	tempV = strtol(Hex1Byte, NULL, 16);
	tempV = (tempV >> 4) & 0x3;
	if (0b01 == tempV) BreakPedalDepressed = true;
	else if (0b00 == tempV) BreakPedalDepressed = false;
	else
	{
		BreakPedalDepressed = false;
		return false;
	}
	return true;
}
//Mar07 2019 add SPN70 and SPN597 end
byte PGN57344Class::refresh()
{
  byte temp;
  temp=Pareant->DigitalCommand("E000");
  if (WAITING==temp) {  SuccessFresh=false; return WAITING;}
  if (FAIL==temp) {  SuccessFresh=false; return FAIL;} 
  //if (!Pareant->DigitalCommand("E000")) { SuccessFresh=false; return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  FreshResultStr=(Pareant->ReturnStr);
  SuccessFresh=true;
  return SUCCESS;
}
//bool PGN57344Class::getSeatBelt(bool buckled)  //fix bug Mar 07 2019
bool PGN57344Class::getSeatBelt(bool &buckled)
{
  char Hex1Byte[]="0x00";
  long tempV;
  if (!SuccessFresh) return false;
  Hex1Byte[2]=FreshResultStr.charAt(6);
  Hex1Byte[3]=FreshResultStr.charAt(7);
  tempV=strtol(Hex1Byte,NULL,16);
  tempV=tempV>>6;
  if (0b01==tempV) buckled=true;
  else if (0b00==tempV) buckled=false;
  else
  {
    buckled=false;
    return false;
  }
  return true;
}
//version 1.0.2 add ---start
byte PGN64996Class::refresh()
{
	byte temp;
	temp = Pareant->DigitalCommand("FDE4");
	if (WAITING == temp) { SuccessFresh = false; return WAITING; }
	if (FAIL == temp) { SuccessFresh = false; return FAIL; }
	//if (!Pareant->DigitalCommand("E000")) { SuccessFresh=false; return false;}  
	Pareant->HandleResponse(Pareant->ReturnStr);
	(Pareant->ReturnStr).trim();
	FreshResultStr = (Pareant->ReturnStr);
	SuccessFresh = true;
	return SUCCESS;
}
bool PGN64996Class::getPayLoad(int &PayLoad)	  //0 to 250%, 1%/bit, 0 offset
{
	char Hex1Byte[] = "0x00";
	long tempV;
	if (!SuccessFresh) return false;
	Hex1Byte[2] = FreshResultStr.charAt(0);
	Hex1Byte[3] = FreshResultStr.charAt(1);
	tempV = strtol(Hex1Byte, NULL, 16);
	if (tempV>0xfa) return false;
	PayLoad = tempV - 0;
	return true;
}

byte PGN61445Class::refresh()
{
	byte temp;
	temp = Pareant->DigitalCommand("F005");
	if (WAITING == temp) { SuccessFresh = false; return WAITING; }
	if (FAIL == temp) { SuccessFresh = false; return FAIL; }
	//if (!Pareant->DigitalCommand("E000")) { SuccessFresh=false; return false;}  
	Pareant->HandleResponse(Pareant->ReturnStr);
	(Pareant->ReturnStr).trim();
	FreshResultStr = (Pareant->ReturnStr);
	SuccessFresh = true;
	return SUCCESS;
}
bool PGN61445Class::getCurrentGear(int &CurrentGear)   //-125 to 125 and 251,  1 gear value/bit, -125 offset, negative values are reverse gears, positive values are forward gears, zero is neutral. 251(0xFB) is park. 251 actual= 126, but I still use "251" for matching spec
{
	char Hex1Byte[] = "0x00";
	long tempV;
	if (!SuccessFresh) return false;
	Hex1Byte[2] = FreshResultStr.charAt(6);
	Hex1Byte[3] = FreshResultStr.charAt(7);
	tempV = strtol(Hex1Byte, NULL, 16);
	if (tempV>0xfb) return false;
	CurrentGear = tempV - 125;
	if (126 == CurrentGear) CurrentGear = 251;
	return true;
}
bool PGN61445Class::getSelectedGear(int &SelectedGear)   //-125 to 125 and 251,  1 gear value/bit, -125 offset, negative values are reverse gears, positive values are forward gears, zero is neutral. 251(0xFB) is park. 251 actual= 126, but I still use "251" for matching spec
{
	char Hex1Byte[] = "0x00";
	long tempV;
	if (!SuccessFresh) return false;
	Hex1Byte[2] = FreshResultStr.charAt(0);
	Hex1Byte[3] = FreshResultStr.charAt(1);
	tempV = strtol(Hex1Byte, NULL, 16);
	if (tempV>0xfb) return false;
	SelectedGear = tempV - 125;
	if (126 == SelectedGear) SelectedGear = 251;
	return true;
}


//version 1.0.2 add ---end
