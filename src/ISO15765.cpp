#include "Arduino.h"
#include "DFL168A_Async.h"
ISO15765Class::ISO15765Class() {
  Pareant=NULL;
  PID_13support=false;
  PID_1DSupport=false;
}
ISO15765Class::ISO15765Class(class DFL168A * Pareant) {
  this->Pareant=Pareant;
  PID_13support=false;
  PID_1DSupport=false;
}


byte ISO15765Class::getVIN(String &VIN)
{
  byte returnV;
  char bufferx[20];
  char HexValue[]="0x00";
  byte i;
  returnV=Pareant->DigitalCommand("09 02");   
  if ((WAITING==returnV)||(FAIL==returnV)) return returnV;  
  
  //if (!Pareant->DigitalCommand("09 02")) {  return false;}    
  Pareant->HandleResponse(Pareant->ReturnStr); 
  Pareant->ReturnStr.trim();    
  if (Pareant->ReturnStr.substring(0,4)!="4902") {  return FAIL;}   
  Pareant->ReturnStr=Pareant->ReturnStr.substring(6); 
  for (i=0;i<(Pareant->ReturnStr.length())/2;i++)
  {
     HexValue[2]=Pareant->ReturnStr.charAt(i*2);
     HexValue[3]=Pareant->ReturnStr.charAt(i*2+1);
     bufferx[i]=strtol(HexValue,NULL,16);
  }
  bufferx[(Pareant->ReturnStr.length())/2]='\0';
  VIN=bufferx;
  return returnV;
}

byte ISO15765Class::clearDTC()
 {
   static byte returnV=SUCCESS; 
   String myStr;
   static unsigned long tick; //only ISO 15765 Needed
   static bool Sent=false; //only ISO 15765 Needed

   if (returnV!=WAITING) {tick=millis(); returnV=WAITING; return returnV;}
   if ((millis()-tick)>149) //142,bad, 146ok
   {
       if (!Sent) { Sent=true;  Pareant->clearRXDBuffer(); Pareant->mySerial->println("04"); }
   }
   
   //if (!Pareant->DigitalCommand("04")) {  return false;}  //Because the response is not digital
   //if (returnV!=WAITING)Pareant->mySerial->println("04");
   if (Pareant->mySerial->available()<=3) {returnV=WAITING; return WAITING;}  
   myStr=Pareant->mySerial->readStringUntil('>'); 
   Sent=false;
   myStr.trim();     
   if (myStr=="NO DATA") { returnV=SUCCESS; return SUCCESS;}  else {returnV=FAIL;return FAIL;}
 }

byte ISO15765Class::getDTC(byte &DTC_Num,String ( &DTC)[8])
{
  byte returnV;
  int i;  
  returnV=Pareant->DigitalCommand("03"); 
  if ((WAITING==returnV)||(FAIL==returnV)) return returnV;  
  //if (!Pareant->DigitalCommand("03")) {  return false;}    
  Pareant->HandleResponse(Pareant->ReturnStr); 
  Pareant->ReturnStr.trim();
  if (Pareant->ReturnStr.substring(0,2)!="43") {  return FAIL;}  
  //Serial.println(Pareant->ReturnStr);   
  DTC_Num=0;
  DTC[0]="";
  DTC[1]="";
  DTC[2]="";
  DTC[3]="";
  DTC[4]="";
  DTC[5]="";
  DTC[6]="";
  DTC[7]="";
  if (Pareant->ReturnStr.substring(2,4)=="00") return SUCCESS;
  for (i=0;i<(Pareant->ReturnStr.length()-2)/4;i++)
  {    
    switch(Pareant->ReturnStr.charAt(4+i*4))
    {
    case '0':
      DTC[DTC_Num]="P0" ;
      break;
    case '1':
      DTC[DTC_Num]="P1" ;
      break;  
    case '2':
      DTC[DTC_Num]="P2" ;
      break;
    case '3':
      DTC[DTC_Num]="P3" ;
      break;    
    case '4':
      DTC[DTC_Num]="C0" ;
      break;
    case '5':
      DTC[DTC_Num]="C1" ;
      break;  
    case '6':
      DTC[DTC_Num]="C2" ;
      break;
    case '7':
      DTC[DTC_Num]="C3" ;
      break;   
    case '8':
      DTC[DTC_Num]="B0" ;
      break;
    case '9':
      DTC[DTC_Num]="B1" ;
      break;  
    case 'A':
      DTC[DTC_Num]="B2" ;
      break;
    case 'B':
      DTC[DTC_Num]="B3" ;
      break;    
    case 'C':
      DTC[DTC_Num]="U0" ;
      break;
    case 'D':
      DTC[DTC_Num]="U1" ;
      break;  
    case 'E':
      DTC[DTC_Num]="U2" ;
      break;
    case 'F':
      DTC[DTC_Num]="U3" ;
      break;           
    }// end of "switch(...."
    DTC[DTC_Num]+=Pareant->ReturnStr.substring(4+i*4+1,2+i*4+6);
    DTC_Num++;
    if (DTC_Num>=8) return SUCCESS;
  }  //end of "for (i=0;i<(Pare...."
  return SUCCESS;
}

byte ISO15765Class::getCoolantTemperature(int &temp)
{/*
  char Hex1Byte[]="0x00";
  long tempV;
  if (!Pareant->DigitalCommand("01 05")) {  return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  if (Pareant->ReturnStr.substring(0,4)!="4105") return false;
  Hex1Byte[2]=Pareant->ReturnStr.charAt(4);
  Hex1Byte[3]=Pareant->ReturnStr.charAt(5);
  tempV=strtol(Hex1Byte,NULL,16); 
  temp=tempV-40;     
  return true;
  */
  float myFloat;
  byte retr;
  char myCmd[]="0105";
  retr=getPhysicalbyte_float(myCmd,myFloat, /*float offset*/-40.0, /*float scale*/1.0);
  if ((WAITING==retr)||(FAIL==retr)) return retr;
  temp=(int)myFloat;
  return retr;
}
byte ISO15765Class::getEngineSpeed(int &EngineSpeed)
{
  /*
  char Hex1Byte[]="0x0000";
  long tempV;
  float tempFloat;
  if (!Pareant->DigitalCommand("01 0C")) {  return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  if (Pareant->ReturnStr.substring(0,4)!="410C") return false;
  Hex1Byte[2]=Pareant->ReturnStr.charAt(4);
  Hex1Byte[3]=Pareant->ReturnStr.charAt(5);
  Hex1Byte[4]=Pareant->ReturnStr.charAt(6);
  Hex1Byte[5]=Pareant->ReturnStr.charAt(7);
  tempV=strtol(Hex1Byte,NULL,16); 
  tempFloat=tempV*0.25;
  EngineSpeed=(int)(tempFloat+0.5);   //round to integer must consider minus number    
  return true;*/
  float myFloat;
  byte retr;
  char myCmd[]="010C";
  retr=getPhysical2byte_float(myCmd,myFloat, /*float offset*/0.0, /*float scale*/0.25);
  if ((WAITING==retr)||(FAIL==retr)) return retr;
  EngineSpeed=(int)(myFloat+0.5);
  return retr;
}
 byte ISO15765Class::getVehicleSpeed(float &VehicleSpeed)
 {
  /*
  char Hex1Byte[]="0x00";
  long tempV;
  float tempFloat;
  if (!Pareant->DigitalCommand("01 0D")) {  return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  if (Pareant->ReturnStr.substring(0,4)!="410D") return false;
  Hex1Byte[2]=Pareant->ReturnStr.charAt(4);
  Hex1Byte[3]=Pareant->ReturnStr.charAt(5); 
  tempV=strtol(Hex1Byte,NULL,16); 
  tempFloat=tempV;
  VehicleSpeed= tempFloat;   //round to integer must consider minus number    
  return true;
 */
  
  byte retr;
  char myCmd[]="010D";
  retr=getPhysicalbyte_float(myCmd,VehicleSpeed, /*float offset*/0.0, /*float scale*/1.0);
  
  return retr;
  
 }

 byte ISO15765Class::getIntakeManifoldPressure(int &IntakeManifoldPressure)
 {
  float myFloat;
  byte retr;
  char myCmd[]="010B";
  retr=getPhysicalbyte_float(myCmd,myFloat, /*float offset*/0.0, /*float scale*/1.0);
  if ((WAITING==retr)||(FAIL==retr)) return retr;
  IntakeManifoldPressure=(int)myFloat;
  return retr;
 }

 byte ISO15765Class::getFuelSystemStatus(bool &A_Openloop, bool &A_Closedloop,bool &A_OpenloopByDriving_Con,bool &A_OpenloopByFault,bool &A_ClosedloopButFault,
                            bool &B_Openloop, bool &B_Closedloop,bool &B_OpenloopByDriving_Con,bool &B_OpenloopByFault,bool &B_ClosedloopButFault)
{
    byte returnV;
    long Temp;
    char myCmd[]="0103";
    returnV=get2byte(myCmd,Temp);
    if ((WAITING==returnV)||(FAIL==returnV)) return returnV;        
    if (Temp&0x100)  A_Openloop=true; else  A_Openloop=false;
    if (Temp&0x200)  A_Closedloop=true; else  A_Closedloop=false; 
    if (Temp&0x400)  A_OpenloopByDriving_Con=true; else A_OpenloopByDriving_Con=false;  
    if (Temp&0x800)  A_OpenloopByFault=true; else A_OpenloopByFault=false;  
    if (Temp&0x1000)  A_ClosedloopButFault=true; else A_ClosedloopButFault=false;    

    if (Temp&0x001)  B_Openloop=true; else  B_Openloop=false;
    if (Temp&0x002)  B_Closedloop=true; else  B_Closedloop=false; 
    if (Temp&0x004)  B_OpenloopByDriving_Con=true; else B_OpenloopByDriving_Con=false;  
    if (Temp&0x008)  B_OpenloopByFault=true; else B_OpenloopByFault=false;  
    if (Temp&0x0010)  B_ClosedloopButFault=true; else B_ClosedloopButFault=false;      
    return returnV;         
}

byte ISO15765Class::getCalculatedLoadValue(int &CalculatedLoad)
{
  float myFloat;
  byte retr;
  char myCmd[]="0104";
  retr=getPhysicalbyte_float(myCmd,myFloat, /*float offset*/0.0, /*float scale*/0.3921568627450980392156862745098);  //scale: 100/255
  if ((WAITING==retr)||(FAIL==retr)) return retr; 
  CalculatedLoad=(int)(myFloat+0.5);
  return retr;
}

byte ISO15765Class::getShortTermFuelTrimBank13(float &Bank1,float &Bank3) //-100 to 99.22%
{
  long myResult;
  byte retr;
  char myCmd[]="0106";
  retr=get2byte( myCmd,myResult);
  if ((WAITING==retr)||(FAIL==retr)) return retr; 
  Bank1= ((myResult>>8)-128)*100/128.0;  
  Bank3= ((myResult&0xff)-128)*100/128.0;  
  return retr;
}

byte ISO15765Class::getLongTermFuelTrimBank13(float &Bank1,float &Bank3) //-100 to 99.22%
{
  long myResult;
  byte retr;
  char myCmd[]="0107";
  retr=get2byte( myCmd,myResult);
  if ((WAITING==retr)||(FAIL==retr)) return retr; 
  Bank1= ((myResult>>8)-128)*100/128.0;  
  Bank3= ((myResult&0xff)-128)*100/128.0;  
  return retr;
}

byte ISO15765Class::getShortTermFuelTrimBank24(float &Bank2,float &Bank4) //-100 to 99.22%
{
  long myResult;
  byte retr;
  char myCmd[]="0108";
  retr=get2byte( myCmd,myResult);
  if ((WAITING==retr)||(FAIL==retr)) return retr; 
  Bank2= ((myResult>>8)-128)*100/128.0;  
  Bank4= ((myResult&0xff)-128)*100/128.0;  
  return retr;
}

byte ISO15765Class::getLongTermFuelTrimBank24(float &Bank2,float &Bank4) //-100 to 99.22%
{
  long myResult;
  byte retr;
  char myCmd[]="0109";
  retr=get2byte( myCmd,myResult);
  if ((WAITING==retr)||(FAIL==retr)) return retr;  
  Bank2= ((myResult>>8)-128)*100/128.0;  
  Bank4= ((myResult&0xff)-128)*100/128.0;  
  return retr;
}

byte ISO15765Class::getIgnitionTimingAdvance(float &Angle)  //-64 63.5 degree
{
  byte retr;
  char myCmd[]="010E";
  retr=getPhysicalbyte_float(myCmd,Angle, /*float offset*/-64.0, /*float scale*/0.5);    
  return retr;
}

byte ISO15765Class::getIntakeAirTemperature(int &temp)
{
  float myFloat;
  byte retr;
  char myCmd[]="010F";
  retr=getPhysicalbyte_float(myCmd,myFloat, /*float offset*/-40.0, /*float scale*/1.0);
  if ((WAITING==retr)||(FAIL==retr)) return retr;  
  temp=(int)myFloat;
  return retr;
}

byte ISO15765Class::getAirFlowRateFrmMAF(float &FlowRate)
{
  byte retr;
  char myCmd[]="0110";
  retr=getPhysical2byte_float(myCmd,FlowRate, /*float offset*/0.0, /*float scale*/0.01);      //unit: g/s
  return retr;
}
byte ISO15765Class::getAbsThrottlePosition(float &Percent)
{
  byte retr;
  char myCmd[]="0111";
  retr=getPhysicalbyte_float(myCmd,Percent, /*float offset*/0.0, /*float scale*/0.3921568627450980392156862745098);      //0 to 100%
  return retr;
}

byte ISO15765Class::getOxygenSensorLocation(bool &Bank1_Sensor1Present, bool &Bank1_Sensor2Present, bool &Bank1_Sensor3Present,bool &Bank1_Sensor4Present, bool &Bank3_Sensor1Present,bool &Bank3_Sensor2Present,
                                            bool &Bank2_Sensor1Present, bool &Bank2_Sensor2Present, bool &Bank2_Sensor3Present,bool &Bank2_Sensor4Present, bool &Bank4_Sensor1Present,bool &Bank4_Sensor2Present)
{
    byte returnV;
    long Temp;
    char myCmd1[]="0113";
    char myCmd2[]="011D";
    Bank1_Sensor1Present=false;
    Bank1_Sensor2Present=false;
    Bank1_Sensor3Present=false;
    Bank1_Sensor4Present=false;
    Bank3_Sensor1Present=false;
    Bank3_Sensor2Present=false;
    Bank2_Sensor1Present=false;
    Bank2_Sensor2Present=false;
    Bank2_Sensor3Present=false;
    Bank2_Sensor4Present=false;
    Bank4_Sensor1Present=false;
    Bank4_Sensor2Present=false;

    if (PID_13support) 
    {
      returnV=get1byte(myCmd1,Temp); 
      if ((WAITING==returnV)||(FAIL==returnV)) return returnV;  
      if (Temp&0x001)  Bank1_Sensor1Present=true; 
      if (Temp&0x002)  Bank1_Sensor2Present=true;
      if (Temp&0x004)  Bank1_Sensor3Present=true; 
      if (Temp&0x008)  Bank1_Sensor4Present=true;

      if (Temp&0x0010)  Bank2_Sensor1Present=true;
      if (Temp&0x0020)  Bank2_Sensor2Present=true;
      if (Temp&0x0040)  Bank2_Sensor3Present=true; 
      if (Temp&0x0080)  Bank2_Sensor4Present=true; 
    }
    else if (PID_1DSupport) 
    {
      returnV=get1byte(myCmd2,Temp); 
      if ((WAITING==returnV)||(FAIL==returnV)) return returnV;  
      if (Temp&0x001)  Bank1_Sensor1Present=true; 
      if (Temp&0x002)  Bank1_Sensor2Present=true;
      if (Temp&0x004)  Bank2_Sensor1Present=true; 
      if (Temp&0x008)  Bank2_Sensor2Present=true;

      if (Temp&0x0010)  Bank3_Sensor1Present=true;
      if (Temp&0x0020)  Bank3_Sensor2Present=true;
      if (Temp&0x0040)  Bank4_Sensor1Present=true; 
      if (Temp&0x0080)  Bank4_Sensor2Present=true; 
    }          
          
    return returnV;        
}
byte ISO15765Class::getBank1OSensor1Voltage(float &OutVoltage)  // 0 to 1.275V 
{
  byte retr;
  char myCmd[]="0114";
  retr=getPhysicalbyte_float(myCmd,OutVoltage, /*float offset*/0.0, /*float scale*/0.005);      //0 to 1.275V
  return retr;
}
byte ISO15765Class::getBank1OSensor2Voltage(float &OutVoltage)  // 0 to 1.275V 
{
  byte retr;
  char myCmd[]="0115";
  retr=getPhysicalbyte_float(myCmd,OutVoltage, /*float offset*/0.0, /*float scale*/0.005);      //0 to 1.275V
  return retr;
}
byte ISO15765Class::getBank1OSensor3Voltage(float &OutVoltage)  // 0 to 1.275V 
{
  byte retr;
  char myCmd[]="0116";
  if (!PID_13support) {OutVoltage=0.0; return FAIL;}
  retr=getPhysicalbyte_float(myCmd,OutVoltage, /*float offset*/0.0, /*float scale*/0.005);      //0 to 1.275V
  return retr;
}
byte ISO15765Class::getBank1OSensor4Voltage(float &OutVoltage)  // 0 to 1.275V 
{
  byte retr;
  char myCmd[]="0117";
  if (!PID_13support) {OutVoltage=0.0; return FAIL;}
  retr=getPhysicalbyte_float(myCmd,OutVoltage, /*float offset*/0.0, /*float scale*/0.005);      //0 to 1.275V
  return retr;
}

byte ISO15765Class::getBank2OSensor1Voltage(float &OutVoltage)  // 0 to 1.275V 
{
  byte retr;
  char myCmd1[]="0118";
  char myCmd2[]="0116";
  if (PID_13support) 
     retr=getPhysicalbyte_float(myCmd1,OutVoltage, /*float offset*/0.0, /*float scale*/0.005);      //0 to 1.275V
  else
     retr=getPhysicalbyte_float(myCmd2,OutVoltage, /*float offset*/0.0, /*float scale*/0.005);      //0 to 1.275V
  return retr;
}
byte ISO15765Class::getBank2OSensor2Voltage(float &OutVoltage)  // 0 to 1.275V 
{
  byte retr;
  char myCmd1[]="0119";
  char myCmd2[]="0117";
  if (PID_13support) 
     retr=getPhysicalbyte_float(myCmd1,OutVoltage, /*float offset*/0.0, /*float scale*/0.005);      //0 to 1.275V
  else
     retr=getPhysicalbyte_float(myCmd2,OutVoltage, /*float offset*/0.0, /*float scale*/0.005);      //0 to 1.275V
  return retr;
}
byte ISO15765Class::getBank2OSensor3Voltage(float &OutVoltage)  // 0 to 1.275V 
{
  byte retr;
  char myCmd[]="011A";
   if (!PID_13support) {OutVoltage=0.0; return FAIL;}
  retr=getPhysicalbyte_float(myCmd,OutVoltage, /*float offset*/0.0, /*float scale*/0.005);      //0 to 1.275V
  return retr;
}
byte ISO15765Class::getBank2OSensor4Voltage(float &OutVoltage)  // 0 to 1.275V 
{
  byte retr;
  char myCmd[]="011B";
  if (!PID_13support) {OutVoltage=0.0; return FAIL;}
  retr=getPhysicalbyte_float(myCmd,OutVoltage, /*float offset*/0.0, /*float scale*/0.005);      //0 to 1.275V
  return retr;
}
byte ISO15765Class::getBank3OSensor1Voltage(float &OutVoltage)  // 0 to 1.275V 
{
  byte retr;
  char myCmd[]="0118";
  if (!PID_1DSupport) {OutVoltage=0.0; return FAIL;}
  retr=getPhysicalbyte_float(myCmd,OutVoltage, /*float offset*/0.0, /*float scale*/0.005);      //0 to 1.275V
  return retr;
}
byte ISO15765Class::getBank3OSensor2Voltage(float &OutVoltage)  // 0 to 1.275V 
{
  byte retr;
  char myCmd[]="0119";
  if (!PID_1DSupport) {OutVoltage=0.0; return FAIL;}
  retr=getPhysicalbyte_float(myCmd,OutVoltage, /*float offset*/0.0, /*float scale*/0.005);      //0 to 1.275V
  return retr;
}
byte ISO15765Class::getBank4OSensor1Voltage(float &OutVoltage)  // 0 to 1.275V 
{
  byte retr;
  char myCmd[]="011A";
  if (!PID_1DSupport) {OutVoltage=0.0; return FAIL;}
  retr=getPhysicalbyte_float(myCmd,OutVoltage, /*float offset*/0.0, /*float scale*/0.005);      //0 to 1.275V
  return retr;
}
byte ISO15765Class::getBank4OSensor2Voltage(float &OutVoltage)  // 0 to 1.275V 
{
  byte retr;
  char myCmd[]="011B";
  if (!PID_1DSupport) {OutVoltage=0.0; return FAIL;}
  retr=getPhysicalbyte_float(myCmd,OutVoltage, /*float offset*/0.0, /*float scale*/0.005);      //0 to 1.275V
  return retr;
}
byte ISO15765Class::getOBDCertified(String &OBD)
{
  byte returnV;
  long Temp;
  char myCmd[]="011C";
  returnV=get1byte(myCmd,Temp); 
  if ((WAITING==returnV)||(FAIL==returnV)) return returnV;  
  switch(Temp)
  {
  case 1:
    OBD="OBD II";  
    break;
  case 2:
    OBD="OBD";  
    break;
  case 3:
    OBD="OBD and OBD II";  
    break;
  case 4:
    OBD="OBD I";  
    break;  
  case 5:
    OBD="NO OBD";  
    break;
  case 6:
    OBD="EOBD";  
    break;
  case 7:
    OBD="EOBD and OBD II";  
    break;
  case 8:
    OBD="EOBD and OBD";  
    break;   
  case 9:
    OBD="EOBD, OBD and OBD II";  
    break;
  case 0x0A:
    OBD="JOBD";  
    break;
  case 0x0B:
    OBD="JOBD and OBD II";  
    break;
  case 0x0C:
    OBD="JOBD and EOBD";  
    break;  
  case 0x0D:
    OBD="JOBD, EOBD, and OBD II";  
    break;
  case 0x11:
    OBD="EMD";  
    break;
  case 0x12:
    OBD="EMD+";  
    break;
  case 0x13:
    OBD="HD OBD-C";  
    break;   
  case 0x14:
    OBD="HD OBD";  
    break;
  case 0x15:
    OBD="WWH OBD";  
    break;
  case 0x17:
    OBD="HD EOBD-I";  
    break;  
  case 0x18:
    OBD="HD EOBD-I N";  
    break;
  case 0x19:
    OBD="HD EOBD-II";  
    break;
  case 0x1A:
    OBD="HD EOBD-II N";  
    break;
  case 0x1C:
    OBD="OBDBr-1";  
    break;    
  case 0x1D:
    OBD="OBDBr-2";  
    break; 
  default:
    OBD="";            
  }
  return  returnV;
}
byte ISO15765Class::getTimeSinceEngineStart(unsigned int &TotalTime)
{
  byte returnV;
  long Temp;
  char myCmd[]="011F";
  returnV=get2byte(myCmd,Temp);
  TotalTime=Temp; 
  return  returnV;
}
byte ISO15765Class::getDistanceTraveledMIL(unsigned int &Distance)
{
  byte returnV;
  long Temp;
  char myCmd[]="0121";
  returnV=get2byte(myCmd,Temp);
  Distance=Temp; 
  return  returnV;
}
byte ISO15765Class::getFuelRailPressure(float &Pressure)
{
  byte retr;
  char myCmd[]="0123";
  retr=getPhysical2byte_float(myCmd,Pressure, /*float offset*/0.0, /*float scale*/10.00);      //0 to 655350 kPa
  return retr;
}
byte ISO15765Class::getFuelLevelInput(float &Percent)  //%
{
  byte retr;
  char myCmd[]="012F";
  retr=getPhysicalbyte_float(myCmd,Percent, /*float offset*/0.0, /*float scale*/0.3921568627450980392156862745098);      //0 to 100%
  return retr;
}
byte ISO15765Class::getDistanceTraveledSinceDTC_Clear(unsigned int &Distance)  //Distance traveled since DTCs cleared
{
  byte returnV;
  long Temp;
  char myCmd[]="0131";
  returnV=get2byte(myCmd,Temp);
  Distance=Temp; 
  return  returnV;
}
byte ISO15765Class::getBarometricPressure(int &Pressure)  //0 to 255 kPa
{
  byte returnV;
  long Temp;
  char myCmd[]="0133";
  returnV=get1byte(myCmd,Temp);
  Pressure=Temp; 
  return  returnV;
}
byte ISO15765Class::getControlModuleVoltage(float &Voltage)
{
  byte retr;
  char myCmd[]="0142";
  retr=getPhysical2byte_float(myCmd,Voltage, /*float offset*/0.0, /*float scale*/0.001);      
  return retr;
}
byte ISO15765Class::getRelativeThrottlePosition(float &Percent)  //%
{
  byte retr;
  char myCmd[]="0145";
  retr=getPhysicalbyte_float(myCmd,Percent, /*float offset*/0.0, /*float scale*/0.3921568627450980392156862745098);      
  return retr;
}
byte ISO15765Class::getAmbientTemp(int &AmbientTemp) //C
{
  byte returnV;
  long Temp;
  char myCmd[]="0146";
  returnV=get1byte(myCmd,Temp);
  AmbientTemp=Temp-40; 
  return  returnV;
}
byte ISO15765Class::getCommandedThrottleActuatorControl(float &Percent)  //%
{
  byte retr;
  char myCmd[]="014C";
  retr=getPhysicalbyte_float(myCmd,Percent, /*float offset*/0.0, /*float scale*/0.3921568627450980392156862745098);      
  return retr;
}
byte ISO15765Class::getEngineRunTimeMIL(unsigned int &TotalTime) //Minutes
{
  byte returnV;
  long Temp;
  char myCmd[]="014D";
  returnV=get2byte(myCmd,Temp);
  TotalTime=Temp; 
  return  returnV;
}
byte ISO15765Class::getEngineRunTimeSinceDTC_Clear(unsigned int &TotalTime) //Minutes
{
  byte returnV;
  long Temp;
  char myCmd[]="014E";
  returnV=get2byte(myCmd,Temp);
  TotalTime=Temp; 
  return  returnV;
}
byte ISO15765Class::getTypeOfFuelUsedCurrently(String & FuelType)  //Type of fuel currently being utilized by the vehicle
{
  byte returnV;
  long Temp;
  char myCmd[]="0151";
  returnV=get1byte(myCmd,Temp); 
  if ((WAITING==returnV)||(FAIL==returnV)) return returnV;  
  switch(Temp)
  {
  case 1:
    FuelType="Gasoline/petrol";  
    break;
  case 2:
    FuelType="Methanol";  
    break;
  case 3:
    FuelType="Ethanol";  
    break;
  case 4:
    FuelType="Diesel";  
    break;  
  case 5:
    FuelType="Liquefied Petroleum Gas (LPG)";  
    break;
  case 6:
    FuelType="Compressed Natural Gas (CNG)";  
    break;
  case 7:
    FuelType="Propane";  
    break;
  case 8:
    FuelType="Battery/electric";  
    break;   
  case 9:
    FuelType="Bi-fuel vehicle using gasoline";  
    break;
  case 0x0A:
    FuelType="Bi-fuel vehicle using methanol";  
    break;
  case 0x0B:
    FuelType="Bi-fuel vehicle using ethanol";  
    break;
  case 0x0C:
    FuelType="Bi-fuel vehicle using LPG";  
    break;  
  case 0x0D:
    FuelType="Bi-fuel vehicle using CNG";  
    break;
   case 0x0E:
    FuelType="Bi-fuel vehicle using propane";  
    break;
   case 0x0F:
    FuelType="Bi-fuel vehicle using battery";  
    break;
   case 0x10:
    FuelType="Bi-fuel vehicle using battery and combustion engine";  
    break;      
  case 0x11:
    FuelType="Hybrid vehicle using gasoline engine";  
    break;
  case 0x12:
    FuelType="Hybrid vehicle using gasoline engine on ethanol";  
    break;
  case 0x13:
    FuelType="Hybrid vehicle using diesel engine";  
    break;   
  case 0x14:
    FuelType="Hybrid vehicle using battery";  
    break;
  case 0x15:
    FuelType="Hybrid vehicle using battery and combustion engine";  
    break;
  case 0x16:
    FuelType="Hybrid vehicle in regeneration mode";  
    break;  
  default:
    FuelType="";            
  }
  return  returnV;
}
byte ISO15765Class::getRelativeAcceleratorPedalPosition(float &Percent)  //%
{
  byte retr;
  char myCmd[]="015A";
  retr=getPhysicalbyte_float(myCmd,Percent, /*float offset*/0.0, /*float scale*/0.3921568627450980392156862745098);       
  return retr;
}
byte ISO15765Class::getHybridBatteryPackRemainingLife(float &Percent)  //%
{
  byte retr;
  char myCmd[]="015B";
  retr=getPhysicalbyte_float(myCmd,Percent, /*float offset*/0.0, /*float scale*/0.3921568627450980392156862745098);      
  return retr;
}
byte ISO15765Class::getEngineOilTemperature(int &Tem) //C
{
  byte returnV;
  long Temp;
  char myCmd[]="015C";
  returnV=get1byte(myCmd,Temp);
  if ((WAITING==returnV)||(FAIL==returnV)) return returnV;  
  Tem=Temp-40; 
  return  returnV;
}
byte ISO15765Class::getFuelRate(float &FuelRate)   //Engine Fuel Rate: L/h
{
  byte returnV;
  char myCmd[]="015E";
  returnV=getPhysical2byte_float(myCmd,FuelRate, /*float offset*/0.0, /*float scale*/0.05);   
  if ((WAITING==returnV)||(FAIL==returnV)) return returnV;   
  return returnV;
}
byte ISO15765Class::getActualEngineTorque(int &ActualEngineTorque)  //-125 to +130 (%)
{  byte returnV;
  long Temp;
  char myCmd[]="0162";
  returnV=get1byte(myCmd,Temp);
  if ((WAITING==returnV)||(FAIL==returnV)) return returnV;
  ActualEngineTorque=Temp-125; 
  return  returnV;
}
byte ISO15765Class::getMILStatus(bool &MIL_IS_ON)
{
  byte returnV;
  long Temp;
  char myCmd[]="0101";
  returnV=get1byte(myCmd,Temp);
  if ((WAITING==returnV)||(FAIL==returnV)) return returnV;
  if (Temp&0x08) MIL_IS_ON=true; else MIL_IS_ON=false;
  return  returnV;
}
byte ISO15765Class::getEngineRunTime(unsigned long &TotalEngineRunTime, unsigned long &TotalIdleRunTime,unsigned long &TotalRunTimeWithPTOActive)  //seconds,  PID 7F 
{
  byte Result_RTN;
  char Hex2Byte[]="0x0000";
  char Hex1Byte[]="0x00";
  long X1;
  long X0;
  long Judge;
  char myCmd[]="017F";  
  Result_RTN=Pareant->DigitalCommand(myCmd);
  if (WAITING==Result_RTN) { return Result_RTN;}
  if (FAIL==Result_RTN) { return Result_RTN;}   
  
  //if (!Pareant->DigitalCommand(myCmd)) { TotalEngineRunTime=0; TotalIdleRunTime=0;TotalRunTimeWithPTOActive=0;return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  myCmd[0]='4';
  if (Pareant->ReturnStr.substring(0,4)!=myCmd) {TotalEngineRunTime=0; TotalIdleRunTime=0;TotalRunTimeWithPTOActive=0;return FAIL;}
  
  Hex1Byte[2]=Pareant->ReturnStr.charAt(4);
  Hex1Byte[3]=Pareant->ReturnStr.charAt(5);  
  Judge=strtol(Hex1Byte,NULL,16); 
  if (Judge&0x1)  
  {
    //Supported TotalEngineRunTime  , divided two 16 bits, to avoid overflow ( SIGNED TO Unsigned)
    Hex2Byte[2]=Pareant->ReturnStr.charAt(6);
    Hex2Byte[3]=Pareant->ReturnStr.charAt(7);
    Hex2Byte[4]=Pareant->ReturnStr.charAt(8);
    Hex2Byte[5]=Pareant->ReturnStr.charAt(9);
    X1=strtol(Hex2Byte,NULL,16);   //High 16 Bits
    Hex2Byte[2]=Pareant->ReturnStr.charAt(10);
    Hex2Byte[3]=Pareant->ReturnStr.charAt(11);
    Hex2Byte[4]=Pareant->ReturnStr.charAt(12);
    Hex2Byte[5]=Pareant->ReturnStr.charAt(13);
    X0=strtol(Hex2Byte,NULL,16);   //Low 16 Bits
    TotalEngineRunTime=(unsigned long)X1*65536UL+X0;    
  }
  else
  {
    //Don't Supported TotalEngineRunTime
    TotalEngineRunTime=0;
  }
  if (Judge&0x2)  
  {
    //Supported TotalIdleRunTime  , divided two 16 bits, to avoid overflow ( SIGNED TO Unsigned)
    Hex2Byte[2]=Pareant->ReturnStr.charAt(14);
    Hex2Byte[3]=Pareant->ReturnStr.charAt(15);
    Hex2Byte[4]=Pareant->ReturnStr.charAt(16);
    Hex2Byte[5]=Pareant->ReturnStr.charAt(17);
    X1=strtol(Hex2Byte,NULL,16);   //High 16 Bits
    Hex2Byte[2]=Pareant->ReturnStr.charAt(18);
    Hex2Byte[3]=Pareant->ReturnStr.charAt(19);
    Hex2Byte[4]=Pareant->ReturnStr.charAt(20);
    Hex2Byte[5]=Pareant->ReturnStr.charAt(21);
    X0=strtol(Hex2Byte,NULL,16);   //Low 16 Bits
    TotalIdleRunTime=(unsigned long)X1*65536UL+X0;    
  }
  else
  {
    //Don't Supported TotalIdleRunTime
    TotalIdleRunTime=0;
  }
  if (Judge&0x4)  
  {
    //Supported TotalRunTimeWithPTOActive  , divided two 16 bits, to avoid overflow ( SIGNED TO Unsigned)
    Hex2Byte[2]=Pareant->ReturnStr.charAt(22);
    Hex2Byte[3]=Pareant->ReturnStr.charAt(23);
    Hex2Byte[4]=Pareant->ReturnStr.charAt(24);
    Hex2Byte[5]=Pareant->ReturnStr.charAt(25);
    X1=strtol(Hex2Byte,NULL,16);   //High 16 Bits
    Hex2Byte[2]=Pareant->ReturnStr.charAt(26);
    Hex2Byte[3]=Pareant->ReturnStr.charAt(27);
    Hex2Byte[4]=Pareant->ReturnStr.charAt(28);
    Hex2Byte[5]=Pareant->ReturnStr.charAt(29);
    X0=strtol(Hex2Byte,NULL,16);   //Low 16 Bits
    TotalRunTimeWithPTOActive=(unsigned long)X1*65536UL+X0;    
  }
  else
  {
    //Don't Supported TotalRunTimeWithPTOActive
    TotalRunTimeWithPTOActive=0;
  }
  return Result_RTN;
}


byte ISO15765Class::get1byte(char cmd[],long &Out1byte)
{
  byte Result_RTN;
  char Hex1Byte[]="0x00";  
  Result_RTN=Pareant->DigitalCommand(cmd);
  if (WAITING==Result_RTN) {Out1byte=0; return Result_RTN;}
  if (FAIL==Result_RTN) {Out1byte=0; return Result_RTN;}  
 
  //if (!Pareant->DigitalCommand(cmd)) {Out1byte=0;  return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  cmd[0]='4';
  if (Pareant->ReturnStr.substring(0,4)!=cmd) {Out1byte=0; return FAIL;}
  Hex1Byte[2]=Pareant->ReturnStr.charAt(4);
  Hex1Byte[3]=Pareant->ReturnStr.charAt(5);  
  Out1byte=strtol(Hex1Byte,NULL,16);     
  return Result_RTN;
}

byte ISO15765Class::get2byte(char cmd[],long &Out2byte)
{
  byte Result_RTN;
  char Hex1Byte[]="0x0000";  
  Result_RTN=Pareant->DigitalCommand(cmd);
  if (WAITING==Result_RTN) {Out2byte=0; return Result_RTN;}
  if (FAIL==Result_RTN) {Out2byte=0; return Result_RTN;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  cmd[0]='4';
  if (Pareant->ReturnStr.substring(0,4)!=cmd) {Out2byte=0; return FAIL;}
  Hex1Byte[2]=Pareant->ReturnStr.charAt(4);
  Hex1Byte[3]=Pareant->ReturnStr.charAt(5);
  Hex1Byte[4]=Pareant->ReturnStr.charAt(6);
  Hex1Byte[5]=Pareant->ReturnStr.charAt(7);
  Out2byte=strtol(Hex1Byte,NULL,16);  
  return Result_RTN;
}

 byte ISO15765Class::getPhysical2byte_float(char cmd[],float &OutFloat, float offset, float scale)
 {
  /*
  char Hex1Byte[]="0x0000";
  long tempV;  
  if (!Pareant->DigitalCommand(cmd)) { OutFloat=0.0; return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  cmd[0]='4';
  if (Pareant->ReturnStr.substring(0,4)!=cmd) {OutFloat=0.0; return false;}
  Hex1Byte[2]=Pareant->ReturnStr.charAt(4);
  Hex1Byte[3]=Pareant->ReturnStr.charAt(5);
  Hex1Byte[4]=Pareant->ReturnStr.charAt(6);
  Hex1Byte[5]=Pareant->ReturnStr.charAt(7);
  tempV=strtol(Hex1Byte,NULL,16); 
  OutFloat=tempV*scale+offset;   
  return true;*/  
  byte returnV;
  long tempV; 
  returnV=get2byte(cmd,tempV);
  if (WAITING==returnV) {return WAITING; }
  if (FAIL==returnV) {return FAIL ;}
  OutFloat=tempV*scale+offset;  
  return returnV;
 }
 byte ISO15765Class::getPhysicalbyte_float(char cmd[],float &OutFloat, float offset, float scale)
 {
  /*
  char Hex1Byte[]="0x00";
  long tempV;  
  if (!Pareant->DigitalCommand(cmd)) {OutFloat=0.0;  return false;}  
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();
  cmd[0]='4';
  if (Pareant->ReturnStr.substring(0,4)!=cmd) {OutFloat=0.0; return false;}
  Hex1Byte[2]=Pareant->ReturnStr.charAt(4);
  Hex1Byte[3]=Pareant->ReturnStr.charAt(5);  
  tempV=strtol(Hex1Byte,NULL,16); 
  OutFloat=tempV*scale+offset;   
  return true;*/

  byte returnV;
  long tempV; 
  returnV=get1byte(cmd,tempV);
  if (WAITING==returnV) {return WAITING; }
  if (FAIL==returnV) {return FAIL ;}
  OutFloat=tempV*scale+offset;  
  return returnV;
 }


