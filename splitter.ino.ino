#include <IRremote.h>
#define irPin 11
IRrecv irrecv(irPin);
decode_results results;
 
#define sig1 5
#define sig2 4
#define sig3 3
#define sig4 2
unsigned long stan = 0 ;
unsigned long previousMillis = 0;
unsigned long interval = (unsigned long) 1000 * 60 * 60 ;

 
void setup() {
   Serial.begin(9600);
    irrecv.enableIRIn();
 
 for(int i=2;i<6;i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}
 
void loop() {
  unsigned long currentMillis = millis();
  
   if (irrecv.decode(&results)) {
     
      switch (results.value) {
         case 0xE0E036C9: 
         if(stan!=results.value) 
         {
           wylacz_all();
           stan=results.value;
         
              
            digitalWrite(sig1, HIGH);
            delay(250);

            delay(1000);
         }
            break;
            
            case 0xE0E028D7:
         if(stan!=results.value)
         { 
           wylacz_all();
           stan=results.value;
              
            digitalWrite(sig2, HIGH);
            delay(250);
            
            delay(1000);}
            break;
            
             case 0xE0E0A857:
        if(stan!=results.value)
        {
          wylacz_all();
          stan=results.value;
              
            digitalWrite(sig3, HIGH);
            delay(250);
            
            delay(1000);}
            break;
            
             case 0xE0E06897:
        if(stan!=results.value) 
        {
          wylacz_all();
          stan=results.value;
              
            digitalWrite(sig4, HIGH);
            delay(250);
            
            delay(1000);}
            break;
            
         }
 
   irrecv.resume();
   }
     if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
      asm volatile ("  jmp 0");
  }
}

void wylacz_all()
{
                for(int i=2;i<6;i++)
              {
              digitalWrite(i, LOW);
              }
              delay(300);
}
