#include "Arduino.h"
#include "DFL168A_Async.h"
J1708Class::J1708Class() {
  Pareant=NULL;
}

J1708Class::J1708Class(class DFL168A * Pareant) {
  this->Pareant=Pareant;
}

byte J1708Class::getAirPressure(int &AirPressure)   //0.0 to 1055 kPa,4.14 kPa/bit, PID=7
{
  byte retrnV;
  char cmd[]="07";
  float tempFloat;
  retrnV=getPhysical_float(cmd,tempFloat, /*float scale*/4.14);
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV;  
  AirPressure=(int)(tempFloat+0.5);
  return retrnV;
}
byte J1708Class::getEngineOilPressure(int &EngineOilPressure)  //0.0 to 1020 kPa, 4kpa/bit, PID=19
{
  byte retrnV;
  char cmd[]="13";
  float tempFloat;
  retrnV=getPhysical_float(cmd,tempFloat, /*float scale*/4.00);
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV;  
  EngineOilPressure=(int)(tempFloat+0.5);
  return retrnV;
}
byte J1708Class::getEngineCoolantPressure(int &EngineCoolantPressure)  //0.0 to 510 kPa ,  2 kPa/bit,pid=20
{
  byte retrnV;
  char cmd[]="14";
  float tempFloat;
  retrnV=getPhysical_float(cmd,tempFloat, /*float scale*/2.00);
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV;  
  EngineCoolantPressure=(int)(tempFloat+0.5);
  return retrnV;
}
byte J1708Class::getFuelLevel1(float &FuelLevel1)  //Primary fuel, 0.0 to 127.5% 0.5%/bit pid=96
{
  byte retrnV;
  char cmd[]="60";  
  retrnV=getPhysical_float(cmd,FuelLevel1,  /*float scale*/0.5);  
  return retrnV;
}
byte J1708Class::getFuelLevel2(float &FuelLevel2)   //righ side fuel, 0.0 to 127.5% 0.5%/bit pid=38
{
  byte retrnV;
  char cmd[]="26";  
  retrnV=getPhysical_float(cmd,FuelLevel2, /*float scale*/0.5);  
  return retrnV;
}
byte J1708Class::getBarometricPressure(float &Pressure)  //0.0 to 153.0 kPa, 0.6 kPa/bit, PID=48
{
  byte retrnV;
  char cmd[]="30";  
  retrnV=getPhysical_float(cmd,Pressure,  /*float scale*/0.6);  
  return retrnV;
}
byte J1708Class::getEngineThrottlePos(float &EngineThrottlePos) //0.0 to 102.0%, 0.4%/bit, pid=51
{
  byte retrnV;
  char cmd[]="33";  
  retrnV=getPhysical_float(cmd,EngineThrottlePos, /*float scale*/0.4);  
  return retrnV;
}
byte J1708Class::getWasherFluidLevel(float &WasherFluidLevel)  //0.0 to 127.5%, 0.5%/bit, pid=80
{
  byte retrnV;
  char cmd[]="50";  
  retrnV=getPhysical_float(cmd,WasherFluidLevel, /*float scale*/0.5);  
  return retrnV;
}
byte J1708Class::getVehicleSpeed(float &VehicleSpeed)  //0.0 to 205.2 km/h , 0.805 km/h/bit, pid=84
{
  byte retrnV;
  char cmd[]="54";  
  retrnV=getPhysical_float(cmd,VehicleSpeed,  /*float scale*/0.805);  
  return retrnV;
}
byte J1708Class::getAccelPedalPosi1(float &AccelPedalPosi1)  //0.0 to 102.0%,0.4%/bit, pid=91, If only one is available, please use this one
{
  byte retrnV;
  char cmd[]="5B";  
  retrnV=getPhysical_float(cmd,AccelPedalPosi1,  /*float scale*/0.4);  
  return retrnV;
}
byte J1708Class::getAccelPedalPosi2(float &AccelPedalPosi2)  //0.0 to 102.0%,0.4%/bit, pid=29
{
  byte retrnV;
  char cmd[]="1D";  
  retrnV=getPhysical_float(cmd,AccelPedalPosi2,  /*float scale*/0.4);  
  return retrnV;
}
byte J1708Class::getAccelPedalPosi3(float &AccelPedalPosi3)  //0.0 to 102.0%,0.4%/bit, pid=28
{
  byte retrnV;
  char cmd[]="1C";  
  retrnV=getPhysical_float(cmd,AccelPedalPosi3,/*float scale*/0.4);  
  return retrnV;
}
byte J1708Class::getEngineLoad(float &Percent)//0.0 to 127.5%, 0.5%/bit, pid=92
{
  byte retrnV;
  char cmd[]="5C";  
  retrnV=getPhysical_float(cmd,Percent,/*float scale*/0.5);  
  return retrnV;
}
byte J1708Class::getEngineOilLevel(float &EngineOilLevel)  //0.0 to 127.5%.0.5%/BIT PID=98
{
  byte retrnV;
  char cmd[]="62";  
  retrnV=getPhysical_float(cmd,EngineOilLevel,  /*float scale*/0.5);  
  return retrnV;
}
byte J1708Class::getCoolantTemperature(int &temp)  //We still use °C even though definition: 0.0 to 255.0 °F, 1.0 °F, PID=110
{
  byte retrnV;
  char cmd[]="6E";
  float tempFloat;
  retrnV=getPhysical_float(cmd,tempFloat,  /*float scale*/1.00);
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV;  
  tempFloat=(tempFloat-32)/1.8;
  if (tempFloat>=0) temp=(int)(tempFloat+0.5); else temp=(int)(tempFloat-0.5);
  return retrnV;
}
byte J1708Class::getEngineCoolantLevel(float &EngineCoolantLevel) //0.0 to 127.5%, 0.5%/bit, PID=111
{
  byte retrnV;
  char cmd[]="6F";  
  retrnV=getPhysical_float(cmd,EngineCoolantLevel, /*float scale*/0.5);  
  return retrnV;
}
byte J1708Class::getTransmissionOilLevel(float &Percent)//0.0 to 127.5%, 0.5%/bit, pid=124
{
  byte retrnV;
  char cmd[]="7C";  
  retrnV=getPhysical_float(cmd,Percent,  /*float scale*/0.5);  
  return retrnV;
}
byte J1708Class::getTransmissionOilLevelHighLow(float &HighLow) //–60.6 to 60.1 L,0.473L/bit,PID=125
{  
  byte retrnV;
  char cmd[]="7D";  
  retrnV=getPhysical_float(cmd,HighLow,  /*float scale*/0.473,true);    
  return retrnV;
}
byte J1708Class::getTransmissionOilPressure(float &Pressure) //0.0 to 3516 kPa, 13.8 kPa/bit, pid=127
{
  byte retrnV;
  char cmd[]="7F";  
  retrnV=getPhysical_float(cmd,Pressure,  /*float scale*/13.8);  
  return retrnV;
}
byte J1708Class::getTransmissionOilTemp(float &Temperature) //We still use °C, even though definition: –8192.00 to +8191.75 °F, 0.25 °F, PID=177
{
  byte retrnV;
  char cmd[]="B1";  
  retrnV=getPhysical_float(cmd,Temperature,  /*float scale*/0.25,true);  
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV;  
  Temperature=(Temperature-32)/1.8;
  return retrnV;
}
byte J1708Class::getPowerSpecificInstantFuelEconomy(float &Rate) //0.0 to 129.1 kW·h/L, 1.97 x 10–3 kW·h/L /Bit, PID=130
{
  byte retrnV;
  char cmd[]="82";  
  retrnV=getPhysical_float(cmd,Rate,  /*float scale*/0.00197);  
  return retrnV;
}
byte J1708Class::getAvgFuelRate(float &FuelRate)   //0.0 to 1.07665 L/s , 16.428 x 10–6 L/s/Bit, PID=133
{
  byte retrnV;
  char cmd[]="85";  
  retrnV=getPhysical_float(cmd,FuelRate,  /*float scale*/0.000016428);  
  return retrnV;
}
byte J1708Class::getInstantFuelEconomy(float &InstantFuelEconomy) //0.0 to 108.835 km/L, 1.66072 x 10–3 km/L/Bit, PID=184
{
  byte retrnV;
  char cmd[]="B8";  
  retrnV=getPhysical_float(cmd,InstantFuelEconomy,  /*float scale*/0.00166072);  
  return retrnV;
}
byte J1708Class::getAvgFuelEconomy(float &AvgFuelEconomy) //0.0 to 108.835 km/L, 1.66072 x 10–3 km/L/Bit, PID=185
{
  byte retrnV;
  char cmd[]="B9";  
  retrnV=getPhysical_float(cmd,AvgFuelEconomy,  /*float scale*/0.00166072);  
  return retrnV;
}
byte J1708Class::getElectricalVoltage(float &BatteryVoltage) //0.0 to 3276.75 V, 0.05 V/Bit, PID=158 After switch
{
  byte retrnV;
  char cmd[]="9E";  
  retrnV=getPhysical_float(cmd,BatteryVoltage,  /*float scale*/0.05);  
  return retrnV;
}
byte J1708Class::getRatedEnginePower(float &Power) //0.0 to 48869.4 kW, 0.745 kW/bit, PID=166
{
  byte retrnV;
  char cmd[]="A6";  
  retrnV=getPhysical_float(cmd,Power,  /*float scale*/0.745);  
  return retrnV;
}
byte J1708Class::getBatteryVoltage(float &BatteryVoltage)  //0.0 to 3276.75 V, 0.05V/bit  PID=168
{
  byte retrnV;
  char cmd[]="A8";  
  retrnV=getPhysical_float(cmd,BatteryVoltage,  /*float scale*/0.05);  
  return retrnV;
}
byte J1708Class::getAlternatorVoltage(float &AlternatorVoltage)   //0.0 to 3276.75 V,0.05V/Bit, PID=167
{
  byte retrnV;
  char cmd[]="A7";  
  retrnV=getPhysical_float(cmd,AlternatorVoltage,  /*float scale*/0.05);  
  return retrnV;
}
byte J1708Class::getAmbientTemp(int &AmbientTemp)  //We still use °C, even though definition:–8192.00 to +8191.75 °F,0.25 °F/Bit, PID=171
{
  byte retrnV;
  char cmd[]="AB";  
  float TempFloat;
  retrnV=getPhysical_float(cmd,TempFloat,  /*float scale*/0.25,true);  
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV;  
  TempFloat=(TempFloat-32)/1.8;
  if (TempFloat>=0) AmbientTemp=(int)(TempFloat+0.5); else AmbientTemp=(int)(TempFloat-0.5);
  return retrnV;
}
byte J1708Class::getCargoAmbientTemp(int &CargoTemp)  //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=169
{
  byte retrnV;
  char cmd[]="A9";  
  float TempFloat;
  retrnV=getPhysical_float(cmd,TempFloat,  /*float scale*/0.25,true);  
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV;  
  TempFloat=(TempFloat-32)/1.8;
  if (TempFloat>=0) CargoTemp=(int)(TempFloat+0.5); else CargoTemp=(int)(TempFloat-0.5);
  return retrnV;
}
byte J1708Class::getRoadTemp(int &RoadTemp) //We still use °C, even though definition:–320.0 to +317.5 °F, 2.5 °F/Bit, PID=79
{
  byte retrnV;
  char cmd[]="4F";  
  float TempFloat;
  retrnV=getPhysical_float(cmd,TempFloat,  /*float scale*/2.5,true);  
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV;  
  TempFloat=(TempFloat-32)/1.8;
  if (TempFloat>=0) RoadTemp=(int)(TempFloat+0.5); else RoadTemp=(int)(TempFloat-0.5);
  return retrnV;
}
byte J1708Class::getCabInteriorTemp(int &CabInteriorTemp) //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=170
{
  byte retrnV;
  char cmd[]="AA";  
  float TempFloat;
  retrnV=getPhysical_float(cmd,TempFloat,  /*float scale*/0.25,true);  
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV;  
  TempFloat=(TempFloat-32)/1.8;
  if (TempFloat>=0) CabInteriorTemp=(int)(TempFloat+0.5); else CabInteriorTemp=(int)(TempFloat-0.5);
  return retrnV;
}
byte J1708Class::getInletTemp(int &InletTemp) //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=172
{
  byte retrnV;
  char cmd[]="AC";  
  float TempFloat;
  retrnV=getPhysical_float(cmd,TempFloat,  /*float scale*/0.25,true);  
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV;  
  TempFloat=(TempFloat-32)/1.8;
  if (TempFloat>=0) InletTemp=(int)(TempFloat+0.5); else InletTemp=(int)(TempFloat-0.5);
  return retrnV;
}
byte J1708Class::getFuelTemp(int &temp) //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=174
{
  byte retrnV;
  char cmd[]="AE";  
  float TempFloat;
  retrnV=getPhysical_float(cmd,TempFloat,  /*float scale*/0.25,true);  
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV;  
  TempFloat=(TempFloat-32)/1.8;
  if (TempFloat>=0) temp=(int)(TempFloat+0.5); else temp=(int)(TempFloat-0.5);
  return retrnV;
}
byte J1708Class::getOilTemp(int &temp) //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=175
{
  byte retrnV;
  char cmd[]="AF";  
  float TempFloat;
  retrnV=getPhysical_float(cmd,TempFloat,  /*float scale*/0.25,true); 
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV;  
  TempFloat=(TempFloat-32)/1.8;
  if (TempFloat>=0) temp=(int)(TempFloat+0.5); else temp=(int)(TempFloat-0.5);
  return retrnV;
}
byte J1708Class::getCargoWeight(float &CargoW) //0.0 to 1166056.9 N, 17.792 N/bit PID=181
{
  byte retrnV;
  char cmd[]="B5";  
  retrnV=getPhysical_float(cmd,CargoW,  /*float scale*/17.792);  
  return retrnV;
}
byte J1708Class::getEngineTripFuel(float &EngineTripFuel)  //0.0 to 31009.6 L, 0.473 L/Bit, PID=182
{
  byte retrnV;
  char cmd[]="B6";  
  retrnV=getPhysical_float(cmd,EngineTripFuel,  /*float scale*/0.473);  
  return retrnV;
}
byte J1708Class::getEngineTotalFuelUsed(float &EngineTotalFuelUsed)  //0.0 to 2032277476 L L, 0.473 L L/Bit, PID=250
{
	byte retrnV;
	char cmd[] = "FA";
	retrnV = getPhysical_float(cmd, EngineTotalFuelUsed,  /*float scale*/0.473);
	if (EngineTotalFuelUsed < 0) EngineTotalFuelUsed = EngineTotalFuelUsed + 4294967296 * 0.473;   //because ulong => unsigned long
	return retrnV;
}
byte J1708Class::getFuelRate(float &FuelRate)    //0.0 to 1.07665 L/s , 16.428 x 10–6 L/s/Bit, PID=183
{
  byte retrnV;
  char cmd[]="B7";  
  retrnV=getPhysical_float(cmd,FuelRate,  /*float scale*/0.000016428);  
  return retrnV;
}
byte J1708Class::getRatedEngineSpeed(float &RatedEngineSpeed)   //0.0 to 16383.75 rpm, 0.25 rpm/bit, PID=189
{
  byte retrnV;
  char cmd[]="BD";  
  retrnV=getPhysical_float(cmd,RatedEngineSpeed,  /*float scale*/0.25);  
  return retrnV;
}
byte J1708Class::getEngineSpeed(int &EngineSpeed)   //0.0 to 16383.75 rpm, 0.25rpm/Bit, pid=190
{
  byte retrnV;
  char cmd[]="BE";
  float tempFloat;  
  retrnV=getPhysical_float(cmd,tempFloat,  /*float scale*/0.25);  
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV; 
  EngineSpeed=(int)(tempFloat+0.5);
  return retrnV;
}
byte J1708Class::getIntakeManifoldTemp(int &IntakeManifoldTemp)  ////We still use °C even though definition: 0.0 to 255.0 °F, 1.0 °F/Bit  PID=105
{
  byte retrnV;
  char cmd[]="69";
  float tempFloat;
  retrnV=getPhysical_float(cmd,tempFloat,  /*float scale*/1.00);
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV; 
  tempFloat=(tempFloat-32)/1.8;
  if (tempFloat>=0) IntakeManifoldTemp=(int)(tempFloat+0.5); else IntakeManifoldTemp=(int)(tempFloat-0.5);
  return retrnV;
}
byte J1708Class::getPowerTakeoffStatus(bool &PTOModeActive, bool &ClutchSwitchOn, bool &BrakeSwitchOn, bool &AccelSwitchOn, bool &ResumeSwitchOn, bool &CoastSwitchOn, bool &SetSwitchOn, bool &PTOControlSwitchOn) //Bit-Mapped,PID=89 
{
  byte retrnV;
  char cmd[]="59";
  long tempV; 
  PTOModeActive=false;ClutchSwitchOn=false;BrakeSwitchOn=false;AccelSwitchOn=false;ResumeSwitchOn=false; CoastSwitchOn=false; SetSwitchOn=false;PTOControlSwitchOn=false;  
  retrnV=getbyte(cmd,tempV);
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV; 
  if (tempV&0x80) PTOModeActive=true;
  if (tempV&0x40) ClutchSwitchOn=true;
  if (tempV&0x20) BrakeSwitchOn=true;
  if (tempV&0x10) AccelSwitchOn=true;
  if (tempV&0x08) ResumeSwitchOn=true;
  if (tempV&0x04) CoastSwitchOn=true;
  if (tempV&0x02) SetSwitchOn=true;
  if (tempV&0x01) PTOControlSwitchOn=true;
  return retrnV;
}
byte J1708Class::getTripDistance(float &TripDistance)   //0.0 to 691207984.6 km, 0.160934 km/bit, PID=244
{
  byte retrnV;
  char cmd[]="F4";
  long tempV; 
  retrnV=getbyte(cmd,tempV);
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV; 
  if (tempV<0) 
  {
    TripDistance=4294967296+tempV;  //change to unsigned 
     
  }
  else
  {
    TripDistance=tempV;
  }
  TripDistance=TripDistance*0.160934;   
  return retrnV;
}
byte J1708Class::J1708Class::getTotalDistance(float &TotalDistance) //0.0 to 691207984.6 km, 0.160934 km/bit, PID=245
{
  byte retrnV;
  char cmd[]="F5";
  long tempV; 
  retrnV=getbyte(cmd,tempV);
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV; 
  if (tempV<0) 
  {
    TotalDistance=4294967296+tempV;  //change to unsigned 
     
  } 
  else 
  {
    TotalDistance=tempV;
  }
  TotalDistance=TotalDistance*0.160934; 
  return retrnV; 
}
byte J1708Class::getTotalEngineHours(float &TotalEngineHours) //0.0 to 214748364.8 h, 0.05h/bit, PID=247
{
  byte retrnV;
  char cmd[]="F7";
  long tempV; 
  retrnV=getbyte(cmd,tempV);
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV; 
  if (tempV<0) 
  {
    TotalEngineHours=4294967296+tempV;  //change to unsigned 
     
  }
  else
  {
    TotalEngineHours=tempV;
  }
  TotalEngineHours=TotalEngineHours*0.05;  
  return retrnV;
}
byte J1708Class::getTotalEngineRevolutions(float &TotalEngineRevolutions)  //0 to 4294967295000 r.  1000 r/BIT, PID=249
{
  byte retrnV;
  char cmd[]="F9";
  long tempV; 
  retrnV=getbyte(cmd,tempV);
  if ((WAITING==retrnV)||(FAIL==retrnV)) return retrnV; 
  if (tempV<0) 
  {
    TotalEngineRevolutions=4294967296+tempV;  //change to unsigned 
     
  }
  else
  {
    TotalEngineRevolutions=tempV;
  }
  TotalEngineRevolutions=TotalEngineRevolutions*1000.0;  
  return retrnV;
}


byte J1708Class::getDTC(byte &DTC_Num,byte &MID,int (&PID_SID)[8],bool (&IsPID)[8], byte (&FMI)[8],bool (& IsActive)[8],bool (&OccurrenceExist)[8],byte (&OccurrenceCount)[8])   //PID=194
{
  byte returnV,temp;
  byte ByteData[28];
  byte Len;
  char HexValue[]="0x00";
  int i;   
  #if 0  //version1.0.1
  char tryTimes;
  #else
  static char tryTimes = 0;
  static bool DigitalCMD_Running = false;
  #endif
   //AT H1
  //while (!Pareant->ATCommand("AT H1"));
  #if 0  //version1.0.1 
  do {
    while (WAITING==(temp=Pareant->ATCommand("AT H1")));
  } while (FAIL==temp);
  #else
  if (false == DigitalCMD_Running)
  {
	  do {
		  while (WAITING == (temp = Pareant->ATCommand("AT H1")));
	  } while (FAIL == temp);
  }
  #endif
  DTC_Num=0;
  //tryTimes=0;  //version1.0.1
  /*
  while(!Pareant->DigitalCommand("C2"))  //PID=194
  {
    tryTimes++;
    if (tryTimes>=5) {while (!Pareant->ATCommand("AT H0")); return false;}
  }   */
  #if 0  //version1.0.1
  do
  {
    returnV=Pareant->DigitalCommand("C2"); //PID=195
    if (WAITING==returnV) continue;
    tryTimes++;  
    if (tryTimes>=5)
    {
      if (FAIL==returnV)
      {  
        do {
           while (WAITING==(temp=Pareant->ATCommand("AT H0")));
        } while (FAIL==temp);
        return FAIL;
      }
    }
  } while ((WAITING==returnV)||(FAIL==returnV)); 
  #else
  returnV = Pareant->DigitalCommand("C2"); //PID=195
  DigitalCMD_Running = true;
  if (WAITING == returnV)
  {
	  return WAITING;
  }
  //so cmd finish, it may be FAIL, maybe SUCCESS
  if (FAIL == returnV)
  {
	  tryTimes++;
	  if (tryTimes >= 5)
	  {
		  tryTimes = 0;
		  DigitalCMD_Running = false;
		  do {
			  while (WAITING == (temp = Pareant->ATCommand("AT H0")));
		  } while (FAIL == temp);
		  return FAIL;
	  }
	  else
	  {
		  return WAITING;
	  }
  }
  //So cmd SUCCESS
  DigitalCMD_Running = false;
  tryTimes = 0;
  #endif    
  Pareant->HandleResponse(Pareant->ReturnStr); 
  Pareant->ReturnStr.trim();    

  HexValue[2]=Pareant->ReturnStr.charAt(0);
  HexValue[3]=Pareant->ReturnStr.charAt(1);
  MID=strtol(HexValue,NULL,16);  
   
  if (Pareant->ReturnStr.substring(2,4)!="C2")
  { 
    returnV=FAIL;
    do {
      while (WAITING==(temp=Pareant->ATCommand("AT H0")));
    } while (FAIL==temp);
    return returnV;
  }
  HexValue[2]=Pareant->ReturnStr.charAt(4);
  HexValue[3]=Pareant->ReturnStr.charAt(5);
  Len=strtol(HexValue,NULL,16);
  Pareant->ReturnStr=Pareant->ReturnStr.substring(6); 
  if (!Len) 
  {
    do {
      while (WAITING==(temp=Pareant->ATCommand("AT H0")));
    } while (FAIL==temp);
    return returnV;  //success: no fault
  }  //no fault
  if (Len!=(Pareant->ReturnStr.length())/2) 
  { 
    returnV=FAIL;
    do {
      while (WAITING==(temp=Pareant->ATCommand("AT H0")));
    } while (FAIL==temp);
    return returnV;
  }
  //correct data
  for (i=0;i<Len;i++)  //how about Len>20?
  {
    HexValue[2]=Pareant->ReturnStr.charAt(2*i);
    HexValue[3]=Pareant->ReturnStr.charAt(2*i+1);
    ByteData[i]=strtol(HexValue,NULL,16);
    if ((2*i+1)>=55)  break;  //limit because of ByteData[28]    
  }         
  i=0;  //byte Postion of handled Data
  while (true)
  {    
    FMI[DTC_Num]=ByteData[i+1]&0x0f;  //b.4 to b.1
    if (ByteData[i+1]&0x20)   //b.6
    {
       //standard diagnostic code       
       PID_SID[DTC_Num]=ByteData[i];  //a
    }
    else
    {
      //expansion diagnostic code (PID or SID from page 2)      
      PID_SID[DTC_Num]=ByteData[i]+256;  //a
    }
    if (ByteData[i+1]&0x40)   //b.7
    {
      //fault is not active      
      IsActive[DTC_Num]=false;
    }
    else
    {
      //fault is active      
      IsActive[DTC_Num]=true;
    }
    if (ByteData[i+1]&0x10)   //b.5
    {
      //SID
      IsPID[DTC_Num]=false;
    }
    else
    {
      //PID
      IsPID[DTC_Num]=true;
    }
    if (ByteData[i+1]&0x80)   //b.8
    {
       //Occurrence Count included
       OccurrenceExist[DTC_Num]=true; 
       OccurrenceCount[DTC_Num]=ByteData[i+2];  //c
       i=i+3;
    }
    else
    {
      //Occurrence Count NOT included
      OccurrenceExist[DTC_Num]=false;  
      OccurrenceCount[DTC_Num]=0;
      i=i+2;
    }
    DTC_Num++;    
    if (i>=Len-2) break;
    if (i>=26) break;
  }  //end of "while..."
  
  //while(!Pareant->ATCommand("AT H0"));
  do {
    while (WAITING==(temp=Pareant->ATCommand("AT H0")));
  } while (FAIL==temp);
  return returnV;
}

byte J1708Class::clearDTC(byte MID,int PID_SID, bool IsPID)  //PID=195, and clear all fault related to MID
{
  byte returnV;
  byte byteD;
  char HexValue[]="0x00";
  #if 0  //version1.0.1
    char tryTimes;
  #else
    static char tryTimes = 0;
  #endif
  char cmd[]="C303000000";
  String tempStr;
  bool ExtendedPID=false;
  if (MID<=15) tempStr+="0";
  tempStr+=String(MID,16);
  cmd[4]=tempStr.charAt(0);
  cmd[5]=tempStr.charAt(1);  //MID
  if (PID_SID>=256)
  {
    ExtendedPID=true;
    PID_SID=PID_SID-256;
  }
  tempStr="";
  if (PID_SID<=15) tempStr+="0";
  tempStr+=String(PID_SID,16);
  cmd[6]=tempStr.charAt(0);
  cmd[7]=tempStr.charAt(1);  //PID
  if (ExtendedPID )
  {
    //Extendt PID/SID
    if (IsPID) cmd[8]='8'; else cmd[8]='9';
  }
  else
  {
    //Standard PID/SID
    if (IsPID) cmd[8]='A'; else cmd[8]='B';
  }
  //tryTimes=0;   //version1.0.1
  /*
  while(!Pareant->DigitalCommand(cmd))  //PID=195
  {
    tryTimes++;
    if (tryTimes>=5) { return false;}
  } */
  #if 0  //version1.0.1
  do
  {
    returnV=Pareant->DigitalCommand(cmd); //PID=195
    if (WAITING==returnV) continue;
    tryTimes++;      
    if (tryTimes>=5) {if (FAIL==returnV) {  return FAIL;}}
  } while ((FAIL==returnV)||(WAITING==returnV));  
  #else
  returnV = Pareant->DigitalCommand(cmd); //PID=195

  if (WAITING == returnV)
  {
	  return WAITING;
  }
  //so cmd finish, it may be FAIL, maybe SUCCESS
  if (FAIL == returnV)
  {
	  tryTimes++;
	  if (tryTimes >= 5)
	  {
		  tryTimes = 0;
		  return FAIL;
	  }
	  else
	  {
		  return WAITING;
	  }
  }
  //So cmd SUCCESS
  tryTimes = 0;
  #endif
  Pareant->HandleResponse(Pareant->ReturnStr); 
  Pareant->ReturnStr.trim();  
  //verify pid=196 which is respond from pid=195
  if (Pareant->ReturnStr.substring(0,2)!="C4") { returnV=FAIL; return returnV;}  
  HexValue[2]=Pareant->ReturnStr.charAt(2);
  HexValue[3]=Pareant->ReturnStr.charAt(3);
  byteD=strtol(HexValue,NULL,16);
  if (byteD<2) {returnV=FAIL; return returnV;} 
  Pareant->ReturnStr=Pareant->ReturnStr.substring(4);   //Data
  HexValue[2]=Pareant->ReturnStr.charAt(2);
  HexValue[3]=Pareant->ReturnStr.charAt(3);
  byteD=strtol(HexValue,NULL,16);
  if ((byteD&0xC0)!=0x80) {returnV=FAIL; return returnV;}
  return returnV;
}

byte J1708Class::getFaultDescription(byte MID,int PID_SID, bool IsPID,byte FMI, String & FaultDescription) //PID=195,
{
  byte returnV;
  char bufferx[40];
  byte i;
  byte byteD;
  char HexValue[]="0x00";
  #if 0  //version1.0.1
    char tryTimes;
  #else
    static char tryTimes = 0;    
  #endif
  char cmd[]="C303000000";
  String tempStr;
  bool ExtendedPID=false;
  if (MID<=15) tempStr+="0";
  tempStr+=String(MID,16);
  cmd[4]=tempStr.charAt(0);
  cmd[5]=tempStr.charAt(1);  //MID
  if (PID_SID>=256)
  {
    ExtendedPID=true;
    PID_SID=PID_SID-256;
  }
  tempStr="";
  if (PID_SID<=15) tempStr+="0";
  tempStr+=String(PID_SID,16);
  cmd[6]=tempStr.charAt(0);
  cmd[7]=tempStr.charAt(1);  //PID

  byteD=0X0F&FMI;
  if (ExtendedPID )
  {
    //Extendt PID/SID
    if (IsPID) byteD+=0xC0; else byteD+=0xD0;
  }
  else
  {
    //Standard PID/SID
    if (IsPID) byteD+=0xE0; else byteD+=0xF0;
  }
  tempStr==String(byteD,16);
  cmd[8]=tempStr.charAt(0);
  cmd[9]=tempStr.charAt(1);  //c: CONTROL 
  
 
  //tryTimes=0;  //version1.0.1
  /*
  while(!Pareant->DigitalCommand(cmd))  //PID=195
  {
    tryTimes++;
    if (tryTimes>=5) { return false;}
  }   */
  #if 0  //version1.0.1
  do
  {
    returnV=Pareant->DigitalCommand(cmd); //PID=195
    if (WAITING==returnV) continue;
    tryTimes++;  
    if (tryTimes>=5) {if (FAIL==returnV) {  return FAIL;}}
  } while ((FAIL==returnV)||(WAITING==returnV));
  #else
  returnV = Pareant->DigitalCommand(cmd); //PID=195
	
  if (WAITING == returnV)
  {
	  return WAITING;
  }
  //so cmd finish, it may be FAIL, maybe SUCCESS
  if (FAIL == returnV)
  {
	  tryTimes++;
	  if (tryTimes >= 5)
	  {
		  tryTimes = 0;
		  return FAIL;
	  }
	  else
	  {
		  return WAITING;
	  }
  }
  //So cmd SUCCESS
  tryTimes = 0;
  #endif    
  Pareant->HandleResponse(Pareant->ReturnStr); 
  Pareant->ReturnStr.trim();  
  //get pid=196 which is respond from pid=195
  if (Pareant->ReturnStr.substring(0,2)!="C4") {returnV=FAIL; return returnV;}  
  HexValue[2]=Pareant->ReturnStr.charAt(2);
  HexValue[3]=Pareant->ReturnStr.charAt(3);
  byteD=strtol(HexValue,NULL,16);
  if (byteD<3) {returnV=FAIL; return returnV;}; 
  Pareant->ReturnStr=Pareant->ReturnStr.substring(4);   //Data
  HexValue[2]=Pareant->ReturnStr.charAt(0);
  HexValue[3]=Pareant->ReturnStr.charAt(1);
  byteD=strtol(HexValue,NULL,16); //SID
  if (byteD!=PID_SID) {returnV=FAIL; return returnV;}
  //control field
  HexValue[2]=Pareant->ReturnStr.charAt(2);
  HexValue[3]=Pareant->ReturnStr.charAt(3);
  byteD=strtol(HexValue,NULL,16);
  
  if ((byteD&0xC0)!=0xC0) {returnV=FAIL; return returnV;}  //Not: Get DTC description
  if ((byteD&0x0F)!=(FMI&0x0F)) {returnV=FAIL; return returnV;}  //wrong FMI

  for (i=0;i<(Pareant->ReturnStr.length())/2-2;i++)
  {
     HexValue[2]=Pareant->ReturnStr.charAt(i*2+4);
     HexValue[3]=Pareant->ReturnStr.charAt(i*2+5);
     bufferx[i]=strtol(HexValue,NULL,16);
     if (i>=38) break;
  }
  if (((Pareant->ReturnStr.length())/2-2)<=39)  
    bufferx[(Pareant->ReturnStr.length())/2-2]='\0';
  else
    bufferx[39]='\0';  
  FaultDescription=bufferx;
  
  return returnV;
}

byte J1708Class::getPIDSIDDescription(byte MID,int PID_SID, bool IsPID, String & PID_SID_Description) //PID=195,
{
  byte returnV;
  char bufferx[40];
  byte i;
  byte byteD;
  char HexValue[]="0x00";
  #if 0  //version1.0.1
    char tryTimes;
  #else
    static char tryTimes = 0;    
  #endif
  char cmd[]="C303000000";
  String tempStr;
  bool ExtendedPID=false;
  if (MID<=15) tempStr+="0";
  tempStr+=String(MID,16);
  cmd[4]=tempStr.charAt(0);
  cmd[5]=tempStr.charAt(1);  //MID
  if (PID_SID>=256)
  {
    ExtendedPID=true;
    PID_SID=PID_SID-256;
  }
  tempStr="";
  if (PID_SID<=15) tempStr+="0";
  tempStr+=String(PID_SID,16);
  cmd[6]=tempStr.charAt(0);
  cmd[7]=tempStr.charAt(1);  //PID

  //byteD=0X0F&FMI;
  byteD==0;
  if (ExtendedPID )
  {
    //Extendt PID/SID
    if (IsPID) byteD+=0x00; else byteD+=0x10;
  }
  else
  {
    //Standard PID/SID
    if (IsPID) byteD+=0x20; else byteD+=0x30;
  }
  tempStr==String(byteD,16);
  //version1.0.1 add----start
  if (1 == tempStr.length())
  {
	  tempStr = "0" + tempStr;
  }
  //version1.0.1 add----end
  cmd[8]=tempStr.charAt(0);
  cmd[9]=tempStr.charAt(1);  //c: CONTROL 
  
 
  //tryTimes=0; //version1.0.1
  /*
  while(!Pareant->DigitalCommand(cmd))  //PID=195
  {
    tryTimes++;
    if (tryTimes>=5) { return false;}
  }   */
  #if 0  //version1.0.1
  do
  {
    returnV=Pareant->DigitalCommand(cmd); //PID=195
    if (WAITING==returnV) continue;
    tryTimes++;  
    if (tryTimes>=5) {if (FAIL==returnV) {  return FAIL;}}
  } while ((FAIL==returnV)||(WAITING==returnV));
  #else
  returnV = Pareant->DigitalCommand(cmd); //PID=195

  if (WAITING == returnV)
  {
	  return WAITING;
  }
  //so cmd finish, it may be FAIL, maybe SUCCESS
  
  if (FAIL == returnV)
  {
	  tryTimes++;
	  if (tryTimes >= 5)
	  {
		  tryTimes = 0;
		  return FAIL;
	  }
	  else
	  {
		  return WAITING;
	  }
  }
  //So cmd SUCCESS
  tryTimes = 0;
  #endif     
  Pareant->HandleResponse(Pareant->ReturnStr); 
  Pareant->ReturnStr.trim();  
  //get pid=196 which is respond from pid=195
  if (Pareant->ReturnStr.substring(0,2)!="C4") {returnV=FAIL; return returnV;}  
  HexValue[2]=Pareant->ReturnStr.charAt(2);
  HexValue[3]=Pareant->ReturnStr.charAt(3);
  byteD=strtol(HexValue,NULL,16);
  if (byteD<3) {returnV=FAIL; return returnV; }
  Pareant->ReturnStr=Pareant->ReturnStr.substring(4);   //Data
  HexValue[2]=Pareant->ReturnStr.charAt(0);
  HexValue[3]=Pareant->ReturnStr.charAt(1);
  byteD=strtol(HexValue,NULL,16); //SID
  if (byteD!=PID_SID) {returnV=FAIL; return returnV; }
  //control field
  HexValue[2]=Pareant->ReturnStr.charAt(2);
  HexValue[3]=Pareant->ReturnStr.charAt(3);
  byteD=strtol(HexValue,NULL,16);
  
  if ((byteD&0xC0)!=0x00) {returnV=FAIL; return returnV; }  //Not: Get PID/SID description  

  for (i=0;i<(Pareant->ReturnStr.length())/2-2;i++)
  {
     HexValue[2]=Pareant->ReturnStr.charAt(i*2+4);
     HexValue[3]=Pareant->ReturnStr.charAt(i*2+5);
     bufferx[i]=strtol(HexValue,NULL,16);
     if (i>=38) break;
  }
  if (((Pareant->ReturnStr.length())/2-2)<=39)  
    bufferx[(Pareant->ReturnStr.length())/2-2]='\0';
  else
    bufferx[39]='\0';  
  PID_SID_Description=bufferx;
  
  return returnV;
}

byte J1708Class::getVIN(String &VIN)
{
  byte returnV;
  char bufferx[30];
  char HexValue[]="0x00";
  byte i;
  #if 0  //version1.0.1
    char tryTimes;
    tryTimes = 0;
  #else
    static char tryTimes = 0;    
  #endif
  /*
  while(!Pareant->DigitalCommand("ED"))  //PID=237
  {
    tryTimes++;
    if (tryTimes>=5) {VIN="";  return false;}
  }  */
  #if 0  //version1.0.1
  do
  {
    returnV=Pareant->DigitalCommand("ED"); //PID=237
    if (WAITING==returnV) continue;
    tryTimes++;  
    if (tryTimes>=5) {if (FAIL==returnV) {VIN="";  return FAIL;}}
  } while ((FAIL==returnV)||(WAITING==returnV));
  #else
	returnV = Pareant->DigitalCommand("ED"); //PID=237	
	if (WAITING == returnV)
	{
		return WAITING;
	}
	//so cmd finish, it may be FAIL, maybe SUCCESS
	if (FAIL == returnV)
	{
		tryTimes++;
		if (tryTimes >= 5)
		{
			tryTimes = 0;
			return FAIL;
		}
		else
		{
			return WAITING;
		}
	}
	//So cmd SUCCESS
	tryTimes = 0;
  #endif    

  Pareant->HandleResponse(Pareant->ReturnStr); 
  Pareant->ReturnStr.trim();    
  if (Pareant->ReturnStr.substring(0,2)!="ED") { VIN=""; returnV=FAIL; return returnV;} 
    
  Pareant->ReturnStr=Pareant->ReturnStr.substring(4); 
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

// cmd= pid. pid mus be <=254  When 4 byte, No matter what Signed is false or true, Out1byte always is  signed
byte J1708Class::getbyte(char cmd[],long &Out1byte, bool Signed=false)
{
  byte Result_RTN;
  char Hex1Byte[]="0x00";
  char Hex2Byte[]="0x0000";  
  char Hex4Byte[]="0x00000000";    
  long temp;
  unsigned long temp2;
  #if 0  //version1.0.1
    char tryTimes;
    tryTimes = 0;
  #else
    static char tryTimes = 0;    
  #endif
  /*
  while(!Pareant->DigitalCommand(cmd))
  {
    tryTimes++;
    if (tryTimes>=5) {Out1byte=0;  return false;}
  }  */
  #if 0  //version1.0.1
  do
  {
    Result_RTN=Pareant->DigitalCommand(cmd);
    if (WAITING==Result_RTN) continue;
    tryTimes++;  
    if (tryTimes>=5) {if (FAIL==Result_RTN) {Out1byte=0;  return FAIL;} }
  } while ((FAIL==Result_RTN)||(WAITING==Result_RTN));
  #else
	Result_RTN = Pareant->DigitalCommand(cmd);
	if (WAITING == Result_RTN)
	{
		return WAITING;
	}
	//so cmd has finished, result is SUCCESS OR FAIL
	if (FAIL == Result_RTN)
	{
		tryTimes++;
		if (tryTimes >= 5)
		{
			Out1byte = 0;
			tryTimes = 0;
			return FAIL;
		}
		else
		{
			return WAITING;
		}
	}
	//So success  
	tryTimes = 0;
  #endif
  Pareant->HandleResponse(Pareant->ReturnStr);  
  (Pareant->ReturnStr).trim();  
  if (Pareant->ReturnStr.substring(0,2)!=cmd) {Out1byte=0; Result_RTN=FAIL; return Result_RTN;}

  Hex1Byte[2]=Pareant->ReturnStr.charAt(0);
  Hex1Byte[3]=Pareant->ReturnStr.charAt(1);  
  temp=strtol(Hex1Byte,NULL,16);       
  if (temp<128)
  {
    //single byte
    Hex1Byte[2]=Pareant->ReturnStr.charAt(2);
    Hex1Byte[3]=Pareant->ReturnStr.charAt(3);  
    Out1byte=strtol(Hex1Byte,NULL,16);   
    if (Signed)
    {
      if (Out1byte>=128) Out1byte=Out1byte-256;
    }
  } 
  else if (temp<192)
  {
    // 2 bytes
    Hex2Byte[2]=Pareant->ReturnStr.charAt(4);
    Hex2Byte[3]=Pareant->ReturnStr.charAt(5);  
    Hex2Byte[4]=Pareant->ReturnStr.charAt(2);
    Hex2Byte[5]=Pareant->ReturnStr.charAt(3);  
    Out1byte=strtol(Hex2Byte,NULL,16);      
    if (Signed)
    {
      if (Out1byte>=32768) Out1byte=Out1byte-65536;
    }    
  }
  else 
  {
    //variable bytes (in geberal, more than 2 bytes)
    Hex1Byte[2]=Pareant->ReturnStr.charAt(2);
    Hex1Byte[3]=Pareant->ReturnStr.charAt(3);  
    temp=strtol(Hex1Byte,NULL,16); 
    if (1==temp)
    {
      //single byte
      Hex1Byte[2]=Pareant->ReturnStr.charAt(4);
      Hex1Byte[3]=Pareant->ReturnStr.charAt(5);  
      Out1byte=strtol(Hex1Byte,NULL,16);   
      if (Signed)
      {
        if (Out1byte>=128) Out1byte=Out1byte-256;
      }
    }
    else if (2==temp)
    {
      // 2 bytes
      Hex2Byte[2]=Pareant->ReturnStr.charAt(6);
      Hex2Byte[3]=Pareant->ReturnStr.charAt(7);  
      Hex2Byte[4]=Pareant->ReturnStr.charAt(4);
      Hex2Byte[5]=Pareant->ReturnStr.charAt(5);  
      Out1byte=strtol(Hex2Byte,NULL,16);      
      if (Signed)
      {
        if (Out1byte>=32768) Out1byte=Out1byte-65536;
      }    
    }
    else if (4==temp)
    {
      // 4 bytes      
      //High 16 bit
      Hex4Byte[2]=Pareant->ReturnStr.charAt(10);
      Hex4Byte[3]=Pareant->ReturnStr.charAt(11);  
      Hex4Byte[4]=Pareant->ReturnStr.charAt(8);
      Hex4Byte[5]=Pareant->ReturnStr.charAt(9); 
      temp=strtol(Hex4Byte,NULL,16);
      temp2=temp;
      //Low 16 bit 
      Hex4Byte[6]=Pareant->ReturnStr.charAt(6);
      Hex4Byte[7]=Pareant->ReturnStr.charAt(7);  
      Hex4Byte[8]=Pareant->ReturnStr.charAt(4);
      Hex4Byte[9]=Pareant->ReturnStr.charAt(5);  
      temp=strtol(Hex4Byte,NULL,16);    
      temp2=(temp2<<16)+temp;

      //changed to Signed long
      if (temp2>=2147483648) 
        Out1byte=temp2-4294967296;   
      else
        Out1byte=temp2;     
      //Serial.print("Data:"); Serial.println(Out1byte);      
    }
    else
    {     
      Result_RTN=FAIL; 
      return Result_RTN;
    }
    
    
          
  }
  return Result_RTN;
}

//We cannot use it when 4 bytes, and unsigned long for respond result
 byte J1708Class::getPhysical_float(char cmd[],float &OutFloat, float scale,bool Signed=false)
 {
  byte returnV;
  long tempV; 
  returnV=getbyte(cmd,tempV,Signed);
  if ((WAITING==returnV)||(FAIL==returnV)) return returnV;
  OutFloat=tempV*scale;  
  return returnV;
 }


