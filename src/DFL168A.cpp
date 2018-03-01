
#include "Arduino.h"
#include "DFL168A_Async.h"
DFL168A::DFL168A() : J1939(), J1708(),ISO15765(),GPS() {
  /*OnewireID[0]=0;
  OnewireID[1]=0;
  OnewireID[2]=0;
  OnewireID[3]=0;
  OnewireID[4]=0;
  OnewireID[5]=0;
  OnewireID[6]=0;
  OnewireID[7]=0;*/
  //SerialNo=0;
  mySerial=&Serial;
  currentProtocol=AUTO_PROTOCOL;
  TransparentSerialAvailable=false;
  EndTransparentChar=0x1b;
  Timeout=500;  //time out is 500ms;    
  SuccessCurrentProtocol=false;
} 


//DFL168A::DFL168A(HardwareSerial * XX) : J1939(), J1708(),ISO15765(),GPS() {
//  mySerial=XX;
//}

//DFL168A::DFL168A(byte SerialNo, byte currProtocol, int Timeout,long J1939Baudrate, long DEV_Baudrate): J1939(J1939Baudrate),J1708(),ISO15765(),GPS(DEV_Baudrate) {
DFL168A::DFL168A(HardwareSerial * XX, byte currProtocol, int Timeout,long J1939Baudrate, long DEV_Baudrate, int DEV_timeout): J1939(J1939Baudrate,this),J1708(this),ISO15765(this),GPS(DEV_Baudrate,DEV_timeout,this) {
 
  /*OnewireID[0]=0;
  OnewireID[1]=0;
  OnewireID[2]=0;
  OnewireID[3]=0;
  OnewireID[4]=0;
  OnewireID[5]=0;
  OnewireID[6]=0;
  OnewireID[7]=0;*/
  //this->SerialNo=SerialNo;
  this->currentProtocol=currProtocol;
  TransparentSerialAvailable=false;
  EndTransparentChar=0x1b;
  this->Timeout=Timeout;  //time out is 500ms;
  SuccessCurrentProtocol=false;
  mySerial=XX;
  
}

 byte DFL168A::ATCommand(const char * CMD)
 {
    byte temp; 
    static byte ReturnValue=SUCCESS;
    if (WAITING!=ReturnValue) mySerial->println(CMD); 
    if (0==mySerial->available()) {ReturnValue=WAITING; return WAITING;}   
    ReturnStr=mySerial->readStringUntil('>');   
    
    //if  (ReturnStr=="") {ReturnValue=WAITING; return WAITING;}         
    Serial.print(ReturnStr);     //debug     
    temp= (ReturnStr.length());              
    if (temp<6) 
    {
       Serial.println("WRONG:0");
       //SuccessCurrentProtocol=false;         because may return is not OK, such as "ATI"
       ReturnValue=FAIL;
       return ReturnValue;    
    }
    if (ReturnStr.substring(temp-6,temp-4)!="OK")
    {
       Serial.println(ReturnStr.substring(temp-6,temp-4));
      // SuccessCurrentProtocol=false;        
       ReturnValue=FAIL;
       return ReturnValue; 
    }
    else
    {
      Serial.println("correct");  
      ReturnValue=SUCCESS;
      return ReturnValue; 
    }                      
              
    
 }
byte DFL168A::DigitalCommand(const char * CMD)
{
   int i, len; 
   char tempChar;  
   static byte ReturnValue=SUCCESS;
   static unsigned long tick; //only ISO 15765 Needed, it's for minimum time interval of request
   static bool Sent=false; //only ISO 15765 Needed

   static unsigned long tick4timeout;    
   
   if (!SuccessCurrentProtocol) {Serial.println("FAIL PROTOCOL"); ReturnStr=""; ReturnValue=FAIL; return ReturnValue;}
   i=0;
   while (CMD[i])
   {
     if (!isHexadecimalDigit(CMD[i])) {
       if (!isSpace(CMD[i])) {Serial.println("WRONG CMD");ReturnStr=""; ReturnValue=FAIL; return ReturnValue;}
     }     
     i++;
   }
   if ((J1939_PROTOCOL==currentProtocol)||(J1708_PROTOCOL==currentProtocol))
   {
      if (WAITING!=ReturnValue) { Serial.print("Digital Cmd ");  Serial.print(CMD); Serial.println( " start, response is:"); tick4timeout=millis(); mySerial->println(CMD); }
   }
   else
   {
      //only ISO15765, Keep request minimum time interval is 150ms.
      if (ReturnValue!=WAITING) {tick=millis(); ReturnValue=WAITING; return ReturnValue;}
      if ((millis()-tick)>149) //142,bad, 146ok
      {
         if (!Sent) { Sent=true; Serial.print("Digital Cmd ");  Serial.print(CMD); Serial.println( " start, response is:"); tick4timeout=millis(); clearRXDBuffer(); mySerial->println(CMD); }
      }
   }  
   
   //if (0==mySerial->available()) {ReturnValue=WAITING; return WAITING;}       
   //if (mySerial->available()<=3) {ReturnValue=WAITING; return WAITING;} 
   if (mySerial->available()<=3)
   {
     if (millis()-tick4timeout<=(Timeout+100))
     {
        ReturnValue=WAITING;
        return WAITING;
     }
     else
     {
        //time out
        while (mySerial->available()) mySerial->read();  //clear buffer
        ReturnValue=FAIL;
        return FAIL;
     }
     
   }      
   ReturnStr=mySerial->readStringUntil('>');       
   //if  (ReturnStr=="") {ReturnValue=WAITING; return ReturnValue; }
   Sent=false;
   Serial.print(ReturnStr);     //debug  
   len=ReturnStr.length();
   for (i=0;i<len;i++)
   {
      tempChar=ReturnStr.charAt(i);
      if (!isHexadecimalDigit(tempChar))
      {
        if ((tempChar!=':') && (!isSpace(tempChar)) && (tempChar!='\r') &&(tempChar!='\n') )
        {
          Serial.println("Digital Cmd fail");
          ReturnStr="";           
          ReturnValue=FAIL; return ReturnValue;
        }
      }
     
   }

   //remove /r/n at begining       
   if (('\n'==ReturnStr.charAt(0))||('\r'==ReturnStr.charAt(0))) ReturnStr.remove(0,1);
   if (('\n'==ReturnStr.charAt(0))||('\r'==ReturnStr.charAt(0))) ReturnStr.remove(0,1);  //secon character become first     
   Serial.println("Digital Cmd success");
   ReturnValue=SUCCESS; return ReturnValue;
}
/*******************************************************************************
 *  It will process Digital command response
 *  Arguments:
 *  Input/output: Resp is response String, no \r\n for begining, but it has \r\n at end
 *                Resp will be putput of handle, It will be pure resonse String no matter long frame or short frame,
 *                And it won't contains any \r\n
 *  Author: Jack Xia, Dafulai Electronics Inc, Dec 28 2017              
 ******************************************************************************/
void DFL168A::HandleResponse(String &Resp)
{
  char tempChar[64];
  String TempStr="";
  char tempChar9[17];
  int i,j,k;
  byte DataLen;
  char HexValue[]="0x000";
  bool longFrame=false;
  Resp.toCharArray(tempChar, 64);

  for (i=0;i<((strlen(tempChar)<23)?strlen(tempChar):23);i++)  //8 hex=16 bytes+2 (\r\n)+3(frame no)+1 (:)=22
  {
    if (':'==tempChar[i]) { longFrame=true; break; }
  }

  if (longFrame=false) 
  {
    for (i=0;i<strlen(tempChar);i++)
    {
      if ('\r'==tempChar[i]||'\n'==tempChar[i])
      {
        tempChar[i]='\0';
        TempStr+=tempChar;
        Resp=TempStr;
        return;
      }
    }
  }
  // so long frame
 HexValue[2]=tempChar[0];
 HexValue[3]=tempChar[1];
 HexValue[4]=tempChar[2];  //HexValue[0]='0' HexValue[1]='x'  HexValue[5]='\0'
 DataLen=strtol(HexValue,NULL,16);

  k=0; //bytes QTY
  j=0;
  for (i=0;i<strlen(tempChar);i++)
  {
    
    if (':'==tempChar[i])
    {
      //find ":"
      while (' '==tempChar[i+1]) 
      {
        i++;
      }  //remove space
      for (j=i+1;j<16+i+1;j++)
      {
        //one row handle
        if (('\r'!=tempChar[j])&&('\n'!=tempChar[j])){
          // NOt the \r\n
          tempChar9[j-(i+1)]=tempChar[j];
          k++;
          if (DataLen*2==k) 
          {
            tempChar9[j-(i+1)+1]='\0';
            TempStr+=tempChar9;
            Resp=TempStr;
            return;
          }
        }
        else
        {
          // \r\n
          tempChar9[j-(i+1)]='\0';
          TempStr+=tempChar9;
          if (DataLen*2==k) 
          {
            Resp=TempStr;
            return;
          } else   break;
        }
        
      }  // end ""one row"           
    }  //end of "find ":""
    
  }
  
}

bool DFL168A::begin(bool intrude=true,bool Fast=false) {
    char bufferx[50];
    byte temp;
    char i;
    String TempStr;
    String ResponseStr;
    long MyLong;
    Serial.begin(57600);  //debug 
    delay(75);  // wait for "searing and version pass"

    mySerial->begin(57600);
    mySerial->setTimeout(Timeout+50);
    mySerial->setTimeout(50);
    while (mySerial->available()) mySerial->read();
   
    while (WAITING==ATCommand("ATi"));
    temp=ReturnStr.length();
    if ((temp<17)||(ReturnStr.substring(temp-17,temp-10)!="DFL168A"))
    {    
        //Only DFL168A working   
        SuccessCurrentProtocol=false;
        return false;     
    }
    if (Fast)
    {
       Serial.println("Fast begin!");
       SuccessCurrentProtocol=true;
       if (!intrude)
       {
           while(ATCommand("AT INTRUDE 0")!=SUCCESS);
       }
       if ((AUTO_PROTOCOL==currentProtocol)||
        (ISO15765_11_500_PROTOCOL==currentProtocol)||
        (ISO15765_29_500_PROTOCOL==currentProtocol)||
        (ISO15765_11_250_PROTOCOL==currentProtocol)||
        (ISO15765_29_250_PROTOCOL==currentProtocol)) {
        bufferx[0]='0';
        bufferx[1]='1'; 
        bufferx[2]='0';
        bufferx[3]='0'; 
        bufferx[4]='\0';
        if (ISO15765.get2byte(/*char cmd[]*/bufferx,/*long &Out2byte*/MyLong)) //"0100" Command
        {
          if (MyLong&0x00002000) ISO15765.PID_13support=true; else ISO15765.PID_13support=false;  //PID 13 (Hex19) support, Bit31 is PID1, Bit 30 is PID2,..., Bit 0 is PID 32
          if (MyLong&0x00000008) ISO15765.PID_1DSupport=true; else ISO15765.PID_1DSupport=false;  //PID 1D (Hex29) support, Bit31 is PID1, Bit 30 is PID2,..., Bit 0 is PID 32
        }
       }
       //mySerial->setTimeout(1);
       return true;
    }
    TempStr=String("AT SP");
    if ((currentProtocol!=J1939_PROTOCOL)||((J1939_PROTOCOL==currentProtocol)&&(250000==J1939.Baudrate))) {

        TempStr+=String(currentProtocol,16);
        TempStr.toCharArray(bufferx, 50);
        while (WAITING==(temp=ATCommand(bufferx)));
        if (FAIL==temp)            
        {          
           SuccessCurrentProtocol=false;
           Serial.println("Fail  to AT SP");
           return false;  
        }
    }
    else {
        //J1939 but baudrate is not 250000
        TempStr+="B";
        TempStr.toCharArray(bufferx, 50);
        while (WAITING==(temp=ATCommand(bufferx)));
        if (FAIL==temp)            
        {
           SuccessCurrentProtocol=false;
           return false;  
        }
        //set baud rate
        TempStr=String("AT PP 34 SV"); ////////xcdddddddddddddddddddddddddddddd
        //set baud rate
        //Baud rate=500k/setting value, so setting value=500000/baud rate
        temp=(byte)(500000/J1939.Baudrate);
        if (temp<=15) 
        {
          TempStr+="0";
        }
        //Serial1.print(temp,HEX);        
        //Serial1.println();  
        TempStr+=String(temp,16);
        TempStr.toCharArray(bufferx, 50);
        while (WAITING==(temp=ATCommand(bufferx)));
        if (FAIL==temp)            
        {
           SuccessCurrentProtocol=false;
           return false;  
        }
        while (WAITING==(temp=ATCommand("AT PP 34 ON")));
        if (FAIL==temp)             
        {
           SuccessCurrentProtocol=false;
           return false;  
        }   
        while (WAITING==(temp=ATCommand("AT PP 33 SV 02")));  //j1939 format   
        if (FAIL==temp)
        {
           SuccessCurrentProtocol=false;
           return false;  
        }   
        while (WAITING==(temp=ATCommand("AT PP 33 ON")));   
        if (FAIL==temp)
        {
           SuccessCurrentProtocol=false;
           return false;  
        } 
        while (WAITING==(temp=ATCommand("AT PPP")));   
        if (FAIL==temp)  
        {
           SuccessCurrentProtocol=false;
           return false;  
        }              
       
    }
    //re-power on
     while (WAITING==(ATCommand("AT Z")));
    //temp=ReturnStr.length();
    delay(5);
    /*
    if ((temp<20)||(ReturnStr.substring(6,13)!="Dafulai"))
    {    
          //Only DFL168A working  
          Serial.println(ReturnStr.substring(6,13)) ;
          SuccessCurrentProtocol=false;
          return false;     
    }*/

    while (WAITING==(temp=ATCommand("AT E 0")));
    if (FAIL==temp)            
    {
       SuccessCurrentProtocol=false;
       return false;  
    }  
    //delay(70);
    delay(350);//200,250, 297 not good, 298:ok 350:ok,300:ok, 500:ok
    //clear " Search... cannot connect "
    while (mySerial->available()) mySerial->read();
    //Wait for "Sleep warning"
    Serial.println("We are waiting for warning!");
    //delay(3900);
    delay(4620);  //4567: not good, 4568, 4600, 4900:ok
    ResponseStr=mySerial->readString();
    
    Serial.println(ResponseStr);
   
    if (ResponseStr.substring(2,9)=="Warning")
    {
       SuccessCurrentProtocol=false;
       Serial.println("I got warining");
       return false;  
    }
    Serial.println("end waiting for warning");
    Serial.println(ResponseStr.substring(2,9));
    
    TempStr=String("AT ST"); 
    if (Timeout<=1000){
        temp=Timeout/4;
       if (temp<=15) {
          TempStr+="0";
          TempStr+=String(temp,16);          
        }
        else {
          TempStr+=String(temp,16);            
        }
        TempStr.toCharArray(bufferx, 50);
        while (WAITING==(temp=ATCommand(bufferx)));
        if (FAIL==temp)            
        {
           Serial.println("Fail to AT ST <=1000");
           SuccessCurrentProtocol=false;
           return false;  
        }
    }       
    else if (Timeout<=2000) {
        while (WAITING==(temp=ATCommand("AT ST FB")));
        if (FAIL==temp)  {
           SuccessCurrentProtocol=false;
           return false;  
        }
        
    } else if (Timeout<=4000) {
         while (WAITING==(temp=ATCommand("AT ST FC")));
         if (FAIL==temp)  {
           SuccessCurrentProtocol=false;
           return false;  
        }
    } else if (Timeout<=6000) {
        while (WAITING==(temp=ATCommand("AT ST FD")));
        if (FAIL==temp)  {
           SuccessCurrentProtocol=false;
           return false;  
        }
    } else if (Timeout<=8000) {
        while (WAITING==(temp=ATCommand("AT ST FE")));
        if (FAIL==temp)  {
           SuccessCurrentProtocol=false;
           return false;  
        }
    } else  {
        while (WAITING==(temp=ATCommand("AT ST FF")));
        if (FAIL==temp)  {
           SuccessCurrentProtocol=false;
           return false;  
        }
    }

    //AT S 
    do {
       while (WAITING==(temp=ATCommand("AT S 0")));
    } while (FAIL==temp) ;    
    
    
    //AT DEV1 PC
    while (WAITING==(temp=ATCommand("AT DEV1 PC")));
    if (FAIL==temp)  {
       SuccessCurrentProtocol=false;
       return false;  
    }
        
    //Change DEV1 baud rate:  DEV1 BRD  hh
    TempStr=String("AT DEV1 BRD");
    if (4800==GPS.Baudrate) TempStr+="01";
    else if (2400==GPS.Baudrate) TempStr+="02";
    else if (9600==GPS.Baudrate) TempStr+="00";
    else {
      temp=(byte)(5000000/GPS.Baudrate);
      if (temp<=15) 
      {
          TempStr+="0";
      }
      TempStr+=String(temp,16);      
    }
    TempStr.toCharArray(bufferx, 50);
    do {
       while (WAITING==(temp=ATCommand(bufferx)));
    } while (FAIL==temp) ;     
    
    
    //Time out= 500ms for gps
    TempStr=String("AT DEV1 ST"); 
    if (500==GPS.Timeout){
      do {
       while (WAITING==(temp=ATCommand("AT DEV1 ST 00")));
      } while (FAIL==temp) ;  
      
    }
    else if (GPS.Timeout<=1000){
      temp=GPS.Timeout/4;
      if (temp<=15) {
          TempStr+="0";
          TempStr+=String(temp,16);          
      }
      else {
          TempStr+=String(temp,16);            
      }
      TempStr.toCharArray(bufferx, 50);
      do {
       while (WAITING==(temp=ATCommand(bufferx)));
      } while (FAIL==temp) ;   
             
      
    }       
    else if (GPS.Timeout<=2000) {
      do {
       while (WAITING==(temp=ATCommand("AT DEV1 ST FB")));
      } while (FAIL==temp) ; 
            
    } else if (GPS.Timeout<=4000) {
      do {
       while (WAITING==(temp=ATCommand("AT DEV1 ST FC")));
      } while (FAIL==temp) ; 
           
    } else if (GPS.Timeout<=6000) {
      do {
       while (WAITING==(temp=ATCommand("AT DEV1 ST FD")));
      } while (FAIL==temp) ;
      
    } else if (GPS.Timeout<=8000) {
      do {
       while (WAITING==(temp=ATCommand("AT DEV1 ST FE")));
      } while (FAIL==temp) ;
      
    } else  {
      do {
       while (WAITING==(temp=ATCommand("AT DEV1 ST FF")));
      } while (FAIL==temp) ; 
     
    }

    
    //at DEV1 TPT 0: Disable exit transparant by timeout
    do {
       while (WAITING==(temp=ATCommand("AT DEV1 TPT 0")));
    } while (FAIL==temp) ;
    
    //at dev1 tp 6  : GPS
    do {
       while (WAITING==(temp=ATCommand("AT DEV1 TP 6")));
    } while (FAIL==temp) ;
    
    if (!intrude)
    {
       do {
         while (WAITING==(temp=ATCommand("AT INTRUDE 0")));
       } while (FAIL==temp) ;       
    } 
    SuccessCurrentProtocol=true;
    
    if ((AUTO_PROTOCOL==currentProtocol)||
        (ISO15765_11_500_PROTOCOL==currentProtocol)||
        (ISO15765_29_500_PROTOCOL==currentProtocol)||
        (ISO15765_11_250_PROTOCOL==currentProtocol)||
        (ISO15765_29_250_PROTOCOL==currentProtocol)) {
        bufferx[0]='0';
        bufferx[1]='1'; 
        bufferx[2]='0';
        bufferx[3]='0'; 
        bufferx[4]='\0';
       
        while (WAITING==(temp=ISO15765.get2byte(/*char cmd[]*/bufferx,/*long &Out2byte*/MyLong)));
        if (SUCCESS==temp) //"0100" Command
        {
          if (MyLong&0x00002000) ISO15765.PID_13support=true; else ISO15765.PID_13support=false;  //PID 13 (Hex19) support, Bit31 is PID1, Bit 30 is PID2,..., Bit 0 is PID 32
          if (MyLong&0x00000008) ISO15765.PID_1DSupport=true; else ISO15765.PID_1DSupport=false;  //PID 1D (Hex29) support, Bit31 is PID1, Bit 30 is PID2,..., Bit 0 is PID 32
         
        }
        delay(140);//130 not good, 140:ok
        
    }
    
    delay(10);    
    //clear all data received
    while (mySerial->available()) mySerial->read();


    

   //SuccessCurrentProtocol=true;   
   return true;
}

byte DFL168A::getOnewireID(byte (&ID)[7])
{
  byte Ret;
  char Hex1Byte[]="0x00";
  long tempV;
  char i;
  //Serial.println("WireWireStart2");
  Ret=ATCommand("AT OW RD");
  if (WAITING==Ret) {return Ret; }
  ReturnStr.trim();
  if (ReturnStr!="No Device Connected") 
  {
    //Serial.println("correct ONE WIRE:" + ReturnStr);
    for (i=0;i<7;i++)
    {
      Hex1Byte[2]=ReturnStr.charAt(2*i);
      Hex1Byte[3]=ReturnStr.charAt(2*i+1);
      if (!isHexadecimalDigit(Hex1Byte[2])) return FAIL;
      if (!isHexadecimalDigit(Hex1Byte[3])) return FAIL;
      tempV=strtol(Hex1Byte,NULL,16);
      ID[i]=(byte)tempV;
    }    
    return SUCCESS;
  }
  else
  {
    //Serial.println("WRONG ONE WIRE");
    return FAIL;
  }
}

boolean DFL168A::getDIN(int portNo)
{
  String TempStr;
  char bufferx[15];
  TempStr="AT RD";
  TempStr+=String(portNo,16);
  TempStr.toCharArray(bufferx, 15);
  while (WAITING==ATCommand(bufferx));
  ReturnStr.trim();
  if (ReturnStr=="1") return HIGH;
  if (ReturnStr=="0") return LOW;
  return LOW;
}

void DFL168A::setDOUT(int portNo, bool Value)
{
  String TempStr;
  char bufferx[15];
  TempStr="AT WD";
  TempStr+=String(portNo,16);
  if (Value) TempStr+="1";
  else TempStr+="0";
  TempStr.toCharArray(bufferx, 15);
  while (WAITING==ATCommand(bufferx));    
}

float DFL168A::getAnalog()
{
  
  while (WAITING==ATCommand("AT RV"));
  ReturnStr.trim();
 
  return ReturnStr.toFloat();  //0.0 to 999.000
}

bool DFL168A::setExitTransparentKey(byte EndTransparentChar)  //must after begin()
{
  byte temp;
  String TempStr;
  char bufferx[20];
  TempStr="ATDEV1EXITT";  //AT DEV1 EXIT T hh
  if (EndTransparentChar<=0x0f) TempStr+="0";
  TempStr+=String(EndTransparentChar,16);  
  TempStr.toCharArray(bufferx, 20);
  while (WAITING==(temp=ATCommand(bufferx)));
  if (SUCCESS==temp)
  {
    this->EndTransparentChar=EndTransparentChar; 
    return true;   
  }
  return false;
}

void DFL168A::beginTransparentSerial()
{
  mySerial->println("ATDEV1TRANSP");  //AT DEV1 TransP
  TransparentSerialAvailable=true;
}

void DFL168A::endTransparentSerial()
{
  String myStr;
  if (TransparentSerialAvailable)
  {
    mySerial->write(EndTransparentChar);
    myStr=mySerial->readStringUntil('>');   
    myStr.trim();    
    if (myStr=="") 
    {
      TransparentSerialAvailable=false;
    }
  }
  
}

bool DFL168A::serialPortAvailable()
{
  return TransparentSerialAvailable;
}

 void DFL168A::clearRXDBuffer()
 {
  while (mySerial->available()) mySerial->read();
 }

void DFL168A::end(void)
{
  //execute "AT PC" and then delay 10ms
  //ATCommand("AT PC");    
  //delay(10);
  mySerial->end();
}
