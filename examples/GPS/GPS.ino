#include <DFL168A_Async.h>
DFL168A myDFL168A(&Serial1, J1939_PROTOCOL, 1000,250000, 9600,500);  //GPS baudrate is 9600, GPS time out is 500ms
bool Vehicle_OK;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
  Vehicle_OK=myDFL168A.begin();
  if (Vehicle_OK) digitalWrite(13,HIGH); else Serial.println("Vehicle is not ready!");
}

void loop() {
  // put your main code here, to run repeatedly:
  String Vin;
  float VehicleSpeed;
  float Latitude;
  float Longitude;
  int Speed;
  String Time;
  String Date;
  float Altitude;  
  static byte StateMachine=0;
  byte result;
  if (Vehicle_OK)
  {
    switch(StateMachine)
    {
      case 0:
        result=myDFL168A.J1939.getVIN(Vin);
        if (WAITING==result) break;
        if (SUCCESS==result)
        {
          Serial.print("Vehicle Identification Number: ");   
          Serial.println(Vin);          
        }
        else
        {
          Serial.println("Fail to get VIN");          
        }
        StateMachine=1;
        break;
      case 1:
        result=myDFL168A.GPS.getGPSinfo(Latitude /*degree*/,Longitude, Speed/*Km/h*/, Time /*hh:mm::ss*/, Date /*dd/mm/yyyy*/);
        if (WAITING==result) break;
        if (SUCCESS==result)
        {
          Serial.println("GPS information: ");   
          Serial.print("Latitude: ");Serial.print(Latitude);Serial.println(" degree");
          Serial.print("Longitude: ");Serial.print(Longitude);Serial.println(" degree");
          Serial.print("Vehicle Speed: ");Serial.print(Speed);Serial.println(" Km/h");
          Serial.print("Time: ");Serial.println(Time);
          Serial.print("Date: ");Serial.println(Date);      
        }
        else
        {
          Serial.println("Fail to get GPS info");        
        }
        StateMachine=2;  
        break;
      case 2:
        result=myDFL168A.GPS.getAltitude(Altitude /*Meter*/);
        if (WAITING==result) break;
        if (SUCCESS==result)
        {
          Serial.print("Altitude: ");Serial.print(Altitude);Serial.println(" Meter");     
        }
        else
        {
          Serial.println("Fail to get Altitude");    
        }
        StateMachine=0;   
    }        
 }
 //The following firmware will be the other task
 //The other task code start
 Serial.println("The other tasks are running");
 //The other task code end
}
