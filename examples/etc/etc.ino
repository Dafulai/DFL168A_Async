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
  while (!myDFL168A.setExitTransparentKey(196));
}

void loop() {
  // put your main code here, to run repeatedly:
  String Vin;
  byte ID[7];
  float Analog;
  bool DigitalIn;  
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
        result=myDFL168A.getOnewireID(ID);
        if (WAITING==result) break;
        if (SUCCESS==result)
        {
          Serial.print("One Wire I-Button ID: ");   
          Serial.print(ID[0]);Serial.print(" ");
          Serial.print(ID[1]);Serial.print(" ");
          Serial.print(ID[2]);Serial.print(" ");
          Serial.print(ID[3]);Serial.print(" ");
          Serial.print(ID[4]);Serial.print(" ");
          Serial.print(ID[5]);Serial.print(" ");
          Serial.println(ID[6]);         
        }
        else
        {
          Serial.println("Fail to get One Wire I-Button ID");       
        }
        StateMachine=0;              
    }
    
    
    Analog=myDFL168A.getAnalog();
    Serial.print("Analog input: ");   
    Serial.println(Analog);
    DigitalIn=myDFL168A.getDIN(1);
    Serial.print("Digital input 1: ");   
    (DigitalIn)? Serial.println("Logic HIGH"):Serial.println("Logic LOW");
    myDFL168A.setDOUT(0,HIGH);
    myDFL168A.beginTransparentSerial();
    if (myDFL168A.serialPortAvailable())
    {
       //now Serial1 can be used for dev1 of DFL168A communication directly
       //your code for Serial1 begin

       //your code for Serial1 end
    }
    myDFL168A.endTransparentSerial();
  }  
  //The following firmware will be the other task
 //The other task code start
 Serial.println("The other tasks are running");
 //The other task code end   
}

