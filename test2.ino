#include<SoftwareSerial.h>
//#include<stdio.h>
SoftwareSerial client(2,3); //RX, TX



int i=0;
void connect_wifi(String cmd, int t)
{
  int temp=0,i=0;
  while(1)
  {
    Serial.println(cmd);
    client.println(cmd); 
    while(client.available())
    {
      if(client.find("OK"))
      i=8;
    }
    delay(t);
    if(i>5)
    break;
    i++;
  }
  if(i==8)
  Serial.println("OK ch");
  else
  Serial.println("Error");
}



 void setup()
 {
   Serial.begin(9600);
   client.begin(115200);
   connect_wifi("AT",100);
   connect_wifi("AT+CWMODE=3",100);
   connect_wifi("AT+CWQAP",100);  
   connect_wifi("AT+CWJAP=\"OnePlus3\",\"surbhi123\"",3000);
   connect_wifi("AT+CIPSTART=\"TCP\",\"192.168.43.139\",2222",7000);
   
   
   
   
 }
 
 void loop()
 {
   client.println("AT+CIPSEND=10");
   delay(1000);
   client.println(i);
   i++;
 }
 

