#include<SoftwareSerial.h>

int rxPin=0;

int txPin=1;

SoftwareSerial Myserial(rxPin,txPin);

int relay_1=2;

int relay_2=3;

int relay_3=4;

int relay_4=5;

int pirSensor=6;

String Rxdata;

char Buffer;

void setup(){

Myserial.begin(9600);

pinMode(relay_1,OUTPUT);

pinMode(relay_2,OUTPUT);

pinMode(relay_3,OUTPUT);

pinMode(relay_4,OUTPUT);

pinMode(pirSensor,INPUT);

   }
void loop(){

while(Myserial.available()){

Buffer=Myserial.read();

Rxdata+=Buffer;

if(Buffer=='#'){

break;

        }
   }

if(Rxdata=="*Light ON#"){

digitalWrite(relay_1,HIGH);


Myserial.println("#Light On");
  
   }

else

if(Rxdata=="*Light Off#"){

digitalWrite(relay_1,LOW);

Myserial.println("#Light Off");

 }

else 

if(Rxdata=="*Fan ON#"){

digitalWrite(relay_2,HIGH);

Myserial.print("*Fan On#");
  
   }

else 

if(Rxdata=="*Fan Off#"){

digitalWrite(relay_2,LOW);

Myserial.println("#Fan Off");

}

else if(Rxdata=="*Bedroom Light On#")
{

digitalWrite(relay_3,HIGH);

Myserial.println("#Bedroom Light ON");

}
  
else 

if(Rxdata=="*Bedroom Light Off#"){

digitalWrite(relay_3,LOW);

Myserial.println("#Bedroom Light Off");
 }

else
if(Rxdata=="*All Appliances On#"){
digitalWrite(relay_1,HIGH);

digitalWrite(relay_2,HIGH);

digitalWrite(relay_3,HIGH);

Myserial.println("#All Appliances On");

       }

else if(Rxdata=="*All Appliances Off#"){

digitalWrite(relay_1,LOW);

digitalWrite(relay_2,LOW);

digitalWrite(relay_3,LOW);


Myserial.print("#All Appliances Off");

   }
if(digitalRead(pirSensor)==HIGH){

digitalWrite(relay_4,HIGH);

Myserial.print("#");

   }
else{
 
 digitalWrite(relay_4,LOW);


Myserial.print("#");
   }

Rxdata="";
 }
