#include <DFL168A_Async.h>
DFL168A myDFL168A(&Serial1, J1708_PROTOCOL, 10000,500000, 9600,500); 

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
  float TotalDistance;
  String myDTC[8];
  byte DTCQty;
  byte MID;
  int SID[8];
  bool IsPID[8];
  byte FMI[8];
  bool IsActive[8];
  bool OccurrenceExist[8];
  byte OccurrenceCount[8];  
  static byte StateMachine=0;
  byte result;  
  if (Vehicle_OK)
  {
    switch(StateMachine)
    {
      case 0:
        result=myDFL168A.J1708.getTotalDistance(TotalDistance);
        if (WAITING==result) break;
        if (SUCCESS==result)
        {
          Serial.print("Total distance: ");     
          Serial.print( TotalDistance); Serial.println(" Km"); 
        }
        else
        {
          Serial.println("Fail to get total distance");
        }
        StateMachine=1;
        break;
      case 1:  
        result=myDFL168A.J1708.getDTC(DTCQty,MID,SID,IsPID, FMI,IsActive,OccurrenceExist,OccurrenceCount);
        if (WAITING==result) break;
        if (SUCCESS==result)
        {
          Serial.println("Success in getting DTC:");  
          Serial.print("DTCQty:"); Serial.println(DTCQty);
          if (DTCQty!=0) 
          {
            Serial.print("MID:"); Serial.println(MID); 
            Serial.print("SID[0]:"); Serial.println(SID[0]); 
            Serial.print("Is Pid[0]? :"); Serial.println(IsPID[0]);
            Serial.print("Is Active[0]? :"); Serial.println(IsActive[0]);
            Serial.print("FMI[0]:"); Serial.println(FMI[0]);
            Serial.print("Is OccurrenceExist[0]? : "); (OccurrenceExist[0])?Serial.println("Yes"):Serial.println("No");
            if (OccurrenceExist[0]) {Serial.print("OccurrenceCount[0]:"); Serial.println(OccurrenceCount[0]);}
          }
        }
        else
        {
          Serial.println("Fail to get DTC");   
        }
        StateMachine=0;
    }            
 }
 //The following firmware will be the other task
 //The other task code start
 //Serial.println("The other tasks are running");
 //The other task code end

}
