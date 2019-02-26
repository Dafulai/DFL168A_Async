#ifndef DFL168A_Async_h
#define DFL168A_Async_h
#define AUTO_PROTOCOL 0
#define ISO15765_11_500_PROTOCOL 6
#define ISO15765_29_500_PROTOCOL 7
#define ISO15765_11_250_PROTOCOL 8
#define ISO15765_29_250_PROTOCOL 9
#define J1939_PROTOCOL 10
#define USER1_PROTOCOL 11
#define USER2_PROTOCOL 12
#define J1708_PROTOCOL 13

#define WAITING 1
#define SUCCESS 2
#define FAIL 0

class PGN65256Class
{
  public:
   class DFL168A * Pareant;
   PGN65256Class();
   PGN65256Class(class DFL168A * Pareant);
   byte refresh();
   bool getAltitude(float &Altitude);
   bool getNavBasedSpeed(float &Speed);
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65269Class
{
  public:
   class DFL168A * Pareant;
   PGN65269Class();
   PGN65269Class(class DFL168A * Pareant);
   byte refresh();   
   bool getBarometricPressure(float &BaroPressure);
   bool getAmbientTemp(int &AmbientTemp);
   bool getInletTemp(int &InletTemp);
   bool getRoadTemp(int &RoadTemp);
   bool getCabInteriorTemp(int &CabInteriorTemp);
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65257Class
{
  public:
   class DFL168A * Pareant;
   PGN65257Class();
   PGN65257Class(class DFL168A * Pareant);
   byte refresh();
   bool getEngineTripFuel(float &EngineTripFuel);
   bool getEngineTotalFuelUsed(float &EngineTotalFuelUsed);
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN61444Class
{
  public:
   class DFL168A * Pareant;
   PGN61444Class();
   PGN61444Class(class DFL168A * Pareant);
   byte refresh();
   bool getActualEngineTorque(int &ActualEngineTorque);  //-125 to +125 (%)
   bool getEngineSpeed(int &EngineSpeed);
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN61443Class
{
  public:
   class DFL168A * Pareant;
   PGN61443Class();
   PGN61443Class(class DFL168A * Pareant);
   byte refresh();
   bool getAccelPedalPosi1(float &AccelPedalPosi1);  //0 to 100 (%)
   bool getAccelPedalPosi2(float &AccelPedalPosi2);  //0 to 100 (%)
   bool getEnginePerLoadAtCurrSpeed(int &EnginePerLoadAtCurrSpeed);  //0 to 125 (%)
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65270Class
{
  public:
   class DFL168A * Pareant;
   PGN65270Class();
   PGN65270Class(class DFL168A * Pareant);
   byte refresh();
   bool getIntakeManifoldPressure(int &IntakeManifoldPressure);   //0-500kpa 2kPa/Bit, BoostPressure=IntakeManifold1# pressure
   bool getIntakeManifoldTemp(int &IntakeManifoldTemp);  //-40 to 210, 1 degree c/bit
   bool getEngineAirInletPressure(int &EngineAirInletPressure);  //0-500kPa, 2kPa/bit
   bool getEngineExhaustGasTemp(int &EngineExhaustGasTemp);  //-273 to 1734.96875  0.03125C/bit
   bool getEngineAirFilterDiffPressure(float &EngineAirFilterDiffPressure);  //0 to 12.5kPa, 0.05kPa/bit (%)
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};
class PGN65271Class
{
  public:
   class DFL168A * Pareant;
   PGN65271Class();
   PGN65271Class(class DFL168A * Pareant);
   byte refresh();
   bool getAlternatorVoltage(float &AlternatorVoltage);   //0.05V/Bit
   bool getElectricalVoltage(float &ElectricalVoltage);  
   bool getBatteryVoltage(float &BatteryVoltage); 
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};
class PGN65272Class
{
  public:
   class DFL168A * Pareant;
   PGN65272Class();
   PGN65272Class(class DFL168A * Pareant);
   byte refresh();
   bool getTransmissionOilLevel(float &Percent);
   bool getTransmissionOilLevelHighLow(float &HighLow);
   bool getTransmissionOilPressure(float &Pressure); //0 to 4000 kPa, 16 kPa/bit, 4th posion
   bool getTransmissionOilTemp(float &Temperature);//-273 to 1734.96875 deg C, 0.03125 deg C/bit, 5th and 6th
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};
class PGN65266Class
{
  public:
   class DFL168A * Pareant;
   PGN65266Class();
   PGN65266Class(class DFL168A * Pareant);
   byte refresh();
   bool getFuelRate(float &FuelRate);   
   bool getInstantFuelEconomy(float &InstantFuelEconomy);  
   bool getAvgFuelEconomy(float &AvgFuelEconomy); 
   bool getEngineThrottlePos(float &EngineThrottlePos); 
   
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65263Class
{
  public:
   class DFL168A * Pareant;
   PGN65263Class();
   PGN65263Class(class DFL168A * Pareant);
   byte refresh();
   bool getFueDeliveryPressure(int &FueDeliveryPressure);   
   bool getEngineOilLevel(float &EngineOilLevel);  
   bool getEngineOilPressure(int &EngineOilPressure); 
   bool getEngineCoolantPressure(int &EngineCoolantPressure); 
   bool getEngineCoolantLevel(float &EngineCoolantLevel); 
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65253Class
{
  public:
   class DFL168A * Pareant;
   PGN65253Class();
   PGN65253Class(class DFL168A * Pareant);
   byte refresh();
   bool getTotalEngineHours(float &TotalEngineHours);   
   bool getTotalEngineRevolutions(float &TotalEngineRevolutions);     
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65214Class
{
  public:
   class DFL168A * Pareant;
   PGN65214Class();
   PGN65214Class(class DFL168A * Pareant);
   byte refresh();
   bool getRatedEngineSpeed(float &RatedEngineSpeed);      
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65248Class
{
  public:
   class DFL168A * Pareant;
   PGN65248Class();
   PGN65248Class(class DFL168A * Pareant);
   byte refresh();
   bool getTripDistance(float &TripDistance);   
   bool getTotalDistance(float &TotalDistance);      
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65276Class
{
  public:
   class DFL168A * Pareant;
   PGN65276Class();
   PGN65276Class(class DFL168A * Pareant);
   byte refresh();
   bool getWasherFluidLevel(float &WasherFluidLevel);   
   bool getFuelLevel1(float &FuelLevel1);  
   bool getFuelLevel2(float &FuelLevel2);      
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};

class PGN65265Class
{
  public:
   class DFL168A * Pareant;
   PGN65265Class();
   PGN65265Class(class DFL168A * Pareant);
   byte refresh();
   bool getWheelBasedVehicleSpeed(float &WheelBasedVehicleSpeed);          
  private:
   boolean SuccessFresh;   
   String FreshResultStr;
};
class PGN57344Class
{
 public:
   class DFL168A * Pareant;
   PGN57344Class();
   PGN57344Class(class DFL168A * Pareant);
   byte refresh();
   bool getSeatBelt(bool buckled);        
 private:
   boolean SuccessFresh;   
   String FreshResultStr;
};
//*********************************************

class PGN65267Class
{
  public:
   class DFL168A * Pareant;
   PGN65267Class();
   PGN65267Class(class DFL168A * Pareant);
   byte refresh();
   bool getLatitude(float &Latitude);
   bool getLongitude(float &Longitude);
  private:
   boolean SuccessFresh;
   //float Latitude; 
   //float Longitude;
   String FreshResultStr;
};

class PGN65262Class
{
  public:  
   class DFL168A * Pareant;
   PGN65262Class();
   PGN65262Class(class DFL168A * Pareant);
   byte refresh();
   bool getCoolantTemperature(int &temp);
   bool getFuelTemp(int &temp);
   bool getOilTemp(int &temp);
  private:
   boolean SuccessFresh;
   //int CoolantTemp; 
   //int FuelTemp;
   //int OilTemp;
   String FreshResultStr;
};

//version 1.0.2 add ---start
class PGN64996Class
{
public:
	class DFL168A * Pareant;
	PGN64996Class();
	PGN64996Class(class DFL168A * Pareant);
	byte refresh();
	bool getPayLoad(int &PayLoad);	  //0 to 250%, 1%/bit, 0 offset
private:
	boolean SuccessFresh;
	String FreshResultStr;
};

class PGN61445Class
{
public:
	class DFL168A * Pareant;
	PGN61445Class();
	PGN61445Class(class DFL168A * Pareant);
	byte refresh();
	bool getCurrentGear(int &CurrentGear);   //-125 to 125 and 251,  1 gear value/bit, -125 offset, negative values are reverse gears, positive values are forward gears, zero is neutral. 251(0xFB) is park. 251 actual= 126, but I still use "251" for matching spec
	bool getSelectedGear(int &SelectedGear);   //-125 to 125 and 251,  1 gear value/bit, -125 offset, negative values are reverse gears, positive values are forward gears, zero is neutral. 251(0xFB) is park. 251 actual= 126, but I still use "251" for matching spec
private:
	boolean SuccessFresh;
	String FreshResultStr;
};
//version 1.0.2 add ----end


class J1939Class
{
  friend class DFL168A;
  public:
   class DFL168A * Pareant;
   J1939Class();
   J1939Class(long Baudrate,class DFL168A * Pareant );
   PGN65267Class PGN65267;
   PGN65262Class PGN65262;
   PGN65256Class PGN65256;
   PGN65269Class PGN65269;
   PGN65257Class PGN65257;
   PGN61444Class PGN61444;
   PGN61443Class PGN61443;
   PGN65270Class PGN65270;
   PGN65271Class PGN65271;
   PGN65272Class PGN65272;
   PGN65266Class PGN65266;
   PGN65263Class PGN65263;
   PGN65253Class PGN65253;
   PGN65214Class PGN65214;
   PGN65248Class PGN65248;
   PGN65276Class PGN65276;
   PGN65265Class PGN65265;
   PGN57344Class PGN57344;
   PGN64996Class PGN64996;//version 1.0.2 add
   PGN61445Class PGN61445;//version 1.0.2 add

   byte getVIN(String &VIN);  
   //bool GetDTC(String &DTC);
   byte getDTC(byte &DTC_Num, long  (&SPN)[5], byte (&FMI)[5], byte (&CM)[5],byte (&OC)[5], byte DTCFormat=1 );
   byte clearDTC();
  private:
    long Baudrate;
    //char VIN[18];
    //char DTC[8]; 
};

class J1708Class
{
  public:
   class DFL168A * Pareant;
   J1708Class();
   J1708Class(class DFL168A * Pareant);
   byte getAirPressure(int &AirPressure);   //0.0 to 1055 kPa,4.14 kPa/bit, PID=7
   byte getEngineOilPressure(int &EngineOilPressure);  //0.0 to 1020 kPa, 4kpa/bit, PID=19
   byte getEngineCoolantPressure(int &EngineCoolantPressure);  //0.0 to 510 kPa ,  2 kPa/bit,pid=20
   byte getFuelLevel1(float &FuelLevel1);  //Primary fuel, 0.0 to 127.5% 0.5%/bit pid=96
   byte getFuelLevel2(float &FuelLevel2);   //righ side fuel, 0.0 to 127.5% 0.5%/bit pid=38
   byte getBarometricPressure(float &Pressure);  //0.0 to 153.0 kPa, 0.6 kPa/bit, PID=48
   byte getEngineThrottlePos(float &EngineThrottlePos); //0.0 to 102.0%, 0.4%/bit, pid=51
   byte getWasherFluidLevel(float &WasherFluidLevel);  //0.0 to 127.5%, 0.5%/bit, pid=80
   byte getVehicleSpeed(float &VehicleSpeed);  //0.0 to 205.2 km/h , 0.805 km/h/bit, pid=84
   byte getAccelPedalPosi1(float &AccelPedalPosi1);  //0.0 to 102.0%,0.4%/bit, pid=91  If only one is available, please use this one
   byte getAccelPedalPosi2(float &AccelPedalPosi2);  //0.0 to 102.0%,0.4%/bit, pid=29  
   byte getAccelPedalPosi3(float &AccelPedalPosi3);  //0.0 to 102.0%,0.4%/bit, pid=28  
   byte getEngineLoad(float &Percent);//0.0 to 127.5%, 0.5%/bit, pid=92
   byte getEngineOilLevel(float &EngineOilLevel);  //0.0 to 127.5%.0.5%/BIT PID=98
   byte getCoolantTemperature(int &temp);  //We still use °C even though definition: 0.0 to 255.0 °F, 1.0 °F, PID=110
   byte getEngineCoolantLevel(float &EngineCoolantLevel); //0.0 to 127.5%, 0.5%/bit, PID=111
   byte getTransmissionOilLevel(float &Percent);//0.0 to 127.5%, 0.5%/bit, pid=124
   byte getTransmissionOilLevelHighLow(float &HighLow);//–60.6 to 60.1 L,0.473L/bit,PID=125
   byte getTransmissionOilPressure(float &Pressure);//0.0 to 3516 kPa, 13.8 kPa/bit, pid=127
   byte getTransmissionOilTemp(float &Temperature); //We still use °C, even though definition: –8192.00 to +8191.75 °F, 0.25 °F, PID=177
   byte getPowerSpecificInstantFuelEconomy(float &Rate); //0.0 to 129.1 kW·h/L, 1.97 x 10–3 kW·h/L /Bit, PID=130
   byte getAvgFuelRate(float &FuelRate);    //0.0 to 1.07665 L/s , 16.428 x 10–6 L/s/Bit, PID=133
   byte getInstantFuelEconomy(float &InstantFuelEconomy); //0.0 to 108.835 km/L, 1.66072 x 10–3 km/L/Bit, PID=184
   byte getAvgFuelEconomy(float &AvgFuelEconomy); //0.0 to 108.835 km/L, 1.66072 x 10–3 km/L/Bit, PID=185
   byte getElectricalVoltage(float &BatteryVoltage); //0.0 to 3276.75 V, 0.05 V/Bit, PID=158, after switch
   byte getRatedEnginePower(float &Power); //0.0 to 48869.4 kW, 0.745 kW/bit, PID=166      
   byte getBatteryVoltage(float &BatteryVoltage);  //0.0 to 3276.75 V, 0.05V/bit  PID=168
   byte getAlternatorVoltage(float &AlternatorVoltage);   //0.0 to 3276.75 V,0.05V/Bit, PID=167
   byte getAmbientTemp(int &AmbientTemp);  //We still use °C, even though definition:–8192.00 to +8191.75 °F,0.25 °F/Bit, PID=171
   byte getCargoAmbientTemp(int &CargoTemp);  //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=169
   byte getRoadTemp(int &RoadTemp);//We still use °C, even though definition:–320.0 to +317.5 °F, 2.5 °F/Bit, PID=79
   byte getCabInteriorTemp(int &CabInteriorTemp);//We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=170
   byte getInletTemp(int &InletTemp);//We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=172
   byte getFuelTemp(int &temp); //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=174
   byte getOilTemp(int &temp); //We still use °C, even though definition:–8192.00 to +8191.75 °F, 0.25 °F, PID=175
   byte getCargoWeight(float &CargoW); //0.0 to 1166056.9 N, 17.792 N/bit PID=181
   byte getEngineTripFuel(float &EngineTripFuel);  //0.0 to 31009.6 L, 0.473 L/Bit, PID=182
   byte getEngineTotalFuelUsed(float &EngineTotalFuelUsed);
   byte getFuelRate(float &FuelRate);    //0.0 to 1.07665 L/s , 16.428 x 10–6 L/s/Bit, PID=183
   byte getRatedEngineSpeed(float &RatedEngineSpeed);   //0.0 to 16383.75 rpm, 0.25 rpm/bit, PID=189   
   byte getEngineSpeed(int &EngineSpeed);   //0.0 to 16383.75 rpm, 0.25rpm/Bit, pid=190
   
   byte getIntakeManifoldTemp(int &IntakeManifoldTemp);  //We still use °C even though definition: 0.0 to 255.0 °F, 1.0 °F/Bit  PID=105
   byte getPowerTakeoffStatus(bool &PTOModeActive, bool &ClutchSwitchOn, bool &BrakeSwitchOn, bool &AccelSwitchOn, bool &ResumeSwitchOn, bool &CoastSwitchOn, bool &SetSwitchOn, bool &PTOControlSwitchOn); //Bit-Mapped,PID=89
   byte getTripDistance(float &TripDistance);   //0.0 to 691207984.6 km, 0.160934 km/bit, PID=244
   byte getTotalDistance(float &TotalDistance); //0.0 to 691207984.6 km, 0.160934 km/bit, PID=245
   byte getTotalEngineHours(float &TotalEngineHours); //0.0 to 214748364.8 h, 0.05h/bit, PID=247
   byte getTotalEngineRevolutions(float &TotalEngineRevolutions);   //0 to 4294967295000 r.  1000 r/BIT, PID=249  
   
     
   
   byte getVIN(String &VIN);  
   byte getDTC(byte &DTC_Num,byte &MID,int (&PID_SID)[8],bool (&IsPID)[8], byte (&FMI)[8],bool (& IsActive)[8],bool (&OccurrenceExist)[8],byte (&OccurrenceCount)[8]);  //PID=194
   byte clearDTC(byte MID,int PID_SID, bool IsPID);  //PID=195, and clear all fault related to MID,and PID or SID
   byte getFaultDescription(byte MID,int PID_SID, bool IsPID,byte FMI, String & FaultDescription); //PID=195,
   byte getPIDSIDDescription(byte MID,int PID_SID, bool IsPID, String & PID_SID_Description); //PID=195,
 private:
   byte MID4Vehicle;
   byte getbyte(char cmd[],long &Out1byte, bool Signed=false);   
   byte getPhysical_float(char cmd[],float &OutFloat, float scale,bool Signed=false);   
   //char VIN[18];
   //char DTC[8]; 
};

class ISO15765Class
{
  friend class DFL168A;
  public:
   class  DFL168A * Pareant;
   ISO15765Class();
   ISO15765Class(class  DFL168A * Pareant);  
   byte getCoolantTemperature(int &temp); 
   byte getEngineSpeed(int &EngineSpeed);
   byte getVehicleSpeed(float &VehicleSpeed); 
   byte getIntakeManifoldPressure(int &IntakeManifoldPressure);   //0-255kpa 1kPa/Bit, 
   byte getFuelSystemStatus(bool &A_Openloop, bool &A_Closedloop,bool &A_OpenloopByDriving_Con,bool &A_OpenloopByFault,bool &A_ClosedloopButFault,
                            bool &B_Openloop, bool &B_Closedloop,bool &B_OpenloopByDriving_Con,bool &B_OpenloopByFault,bool &B_ClosedloopButFault);
   byte getCalculatedLoadValue(int &CalculatedLoad);  //0 to 100%
   byte getShortTermFuelTrimBank13(float &Bank1,float &Bank3); //-100 to 99.22%
   byte getLongTermFuelTrimBank13(float &Bank1,float &Bank3); //-100 to 99.22%
   byte getShortTermFuelTrimBank24(float &Bank2,float &Bank4); //-100 to 99.22%
   byte getLongTermFuelTrimBank24(float &Bank2,float &Bank4); //-100 to 99.22%
   byte getIgnitionTimingAdvance(float &Angle);  //-64 63.5 degree
   byte getIntakeAirTemperature(int &temp); 
   byte getAirFlowRateFrmMAF(float &FlowRate);   //unit: g/s
   byte getAbsThrottlePosition(float &Percent); //0 to 100%
   byte getOxygenSensorLocation(bool &Bank1_Sensor1Present, bool &Bank1_Sensor2Present, bool &Bank1_Sensor3Present,bool &Bank1_Sensor4Present, bool &Bank3_Sensor1Present,bool &Bank3_Sensor2Present,
                                bool &Bank2_Sensor1Present, bool &Bank2_Sensor2Present, bool &Bank2_Sensor3Present,bool &Bank2_Sensor4Present, bool &Bank4_Sensor1Present,bool &Bank4_Sensor2Present);
   byte getBank1OSensor1Voltage(float &OutVoltage);  // 0 to 1.275V   
   byte getBank1OSensor2Voltage(float &OutVoltage);  // 0 to 1.275V  
   byte getBank1OSensor3Voltage(float &OutVoltage);  // 0 to 1.275V 
   byte getBank1OSensor4Voltage(float &OutVoltage);  // 0 to 1.275V  
   byte getBank2OSensor1Voltage(float &OutVoltage);  // 0 to 1.275V
   byte getBank2OSensor2Voltage(float &OutVoltage);  // 0 to 1.275V  
   byte getBank2OSensor3Voltage(float &OutVoltage);  // 0 to 1.275V 
   byte getBank2OSensor4Voltage(float &OutVoltage);  // 0 to 1.275V      
   byte getBank3OSensor1Voltage(float &OutVoltage);  // 0 to 1.275V  
   byte getBank3OSensor2Voltage(float &OutVoltage);  // 0 to 1.275V 
   byte getBank4OSensor1Voltage(float &OutVoltage);  // 0 to 1.275V  
   byte getBank4OSensor2Voltage(float &OutVoltage);  // 0 to 1.275V    
   byte getOBDCertified(String &OBD);  
   byte getTimeSinceEngineStart(unsigned int &TotalTime);  
   byte getDistanceTraveledMIL(unsigned int &Distance);    //Distance Traveled While MIL is  Activated  
   byte getFuelRailPressure(float &Pressure);    //kPa
   byte getFuelLevelInput(float &Percent);  //%
   byte getDistanceTraveledSinceDTC_Clear(unsigned int &Distance);  //Distance traveled since DTCs cleared
   byte getBarometricPressure(int &Pressure);  //0 to 255 kPa
   byte getControlModuleVoltage(float &Voltage);  
   byte getRelativeThrottlePosition(float &Percent);  //% 
   byte getAmbientTemp(int &AmbientTemp); //C
   byte getCommandedThrottleActuatorControl(float &Percent);  //%
   byte getEngineRunTimeMIL(unsigned int &TotalTime); //Minutes
   byte getEngineRunTimeSinceDTC_Clear(unsigned int &TotalTime); //Minutes
   byte getTypeOfFuelUsedCurrently(String & FuelType);  //Type of fuel currently being utilized by the vehicle
   byte getRelativeAcceleratorPedalPosition(float &Percent);  //%
   byte getHybridBatteryPackRemainingLife(float &Percent);  //%
   byte getEngineOilTemperature(int &Tem); //C
   byte getFuelRate(float &FuelRate);    //Engine Fuel Rate: L/h
   byte getActualEngineTorque(int &ActualEngineTorque);  //-125 to +130 (%)
   byte getMILStatus(bool &MIL_IS_ON);
   byte getEngineRunTime(unsigned long &TotalEngineRunTime, unsigned long &TotalIdleRunTime,unsigned long &TotalRunTimeWithPTOActive);  //Time unit: Seconds,  PID 7F, their value must not zero, it means it does not support if zero
    
   byte getVIN(String &VIN);  
   byte getDTC(byte &DTC_Num,String ( &DTC)[8]);
   byte clearDTC(); 
  private:
   //bool DigitalCommand(const char * DigitalCMD);
    //int Baudrate; 
    //char VIN[18]; 
    //char DTC[8]; 
    bool PID_13support;
    bool PID_1DSupport;
    byte get1byte(char cmd[],long &Out1byte);
    byte get2byte(char cmd[],long &Out2byte);
    byte getPhysical2byte_float(char cmd[],float &OutFloat, float offset, float scale);
    byte getPhysicalbyte_float(char cmd[],float &OutFloat, float offset, float scale);
};

class GPSClass
{
  friend class DFL168A;
  public:
   class DFL168A * Pareant;
   GPSClass();
   GPSClass(long Baudrate, int Timeout,class DFL168A * Pareant );    
   byte getGPSinfo(float &Latitude /*degree*/,float &Longitude, int &Speed/*Km/h*/, String &Time /*hh:mm::ss*/, String &Date /*dd/mm/yyyy*/);
   byte getAltitude(float &Altitude /*Meter*/);   
  
  private:
    byte SendGPSCMD(const char * CMD);
    long Baudrate;
    int Timeout;   
      
};

class DFL168A
{
   friend class GPSClass;
   friend class ISO15765Class;
   friend class J1708Class;
   friend class J1939Class;
   friend class PGN65267Class;
   friend class PGN65262Class;
   friend class PGN65256Class;
   friend class PGN65269Class;
   friend class PGN65257Class;  
   friend class PGN61444Class; 
   friend class PGN61443Class; 
   friend class PGN65270Class;
   friend class PGN65271Class;
   friend class PGN65272Class;
   friend class PGN65266Class;
   friend class PGN65263Class;
   friend class PGN65253Class;
   friend class PGN65214Class;
   friend class PGN65248Class;
   friend class PGN65276Class;
   friend class PGN65265Class;
   friend class PGN57344Class;
   friend class PGN64996Class;   //version 1.0.2 add
   friend class PGN61445Class;    //version 1.0.2 add
   public:
    DFL168A();
    //DFL168A(byte SerialNo, byte currProtocol,int Timeout, long J1939Baudrate, long DEV_Baudrate);
    DFL168A(HardwareSerial * XX, byte currProtocol,int Timeout, long J1939Baudrate, long DEV_Baudrate, int DEV_timeout);
    bool begin(bool intrude=true,bool Fast=false);
    void end();
    J1939Class J1939;
    J1708Class J1708;
    ISO15765Class ISO15765;
    GPSClass GPS; 
   
    byte getOnewireID(byte (&ID)[7]);
    boolean getDIN(int portNo);
    void setDOUT(int portNo, bool Value);
    float getAnalog(); //0.0 to 999.00
    void beginTransparentSerial();
    void endTransparentSerial();
    bool setExitTransparentKey(byte EndTransparentChar);  //must after begin()
    bool serialPortAvailable();  //if TransparentSerialAvailable is true, it will return true

	//version1.0.1 add--start
	bool setSleepDelay(unsigned int SleepDelayms);
	//version1.0.1 add--End

    //    bool DigitalCommand(const char * CMD);
   private:
    HardwareSerial * mySerial;
    byte ATCommand(const char * CMD);
    void HandleResponse(String &Resp);
    byte DigitalCommand(const char * CMD);
    void clearRXDBuffer();
   //byte SerialNo;
    //byte OnewireID[8];
    byte currentProtocol;
    bool TransparentSerialAvailable;  
    byte EndTransparentChar;     
    int Timeout;    
    boolean SuccessCurrentProtocol;  // it is true When  begin() return true,Or  setCuurentProtocol(byte cuurProtocol)return true  
    String ReturnStr;
};
#endif


