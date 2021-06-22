#include <IRremote.h>
const int In1 = 3;
const int In2 = 4;
const int In3 = 7;      
const int In4 = 8;    
int RECV_PIN = 16;   
IRrecv irrecv(RECV_PIN);
decode_results results;
int cur_dir=0;

void setup(){
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);    
   Serial.begin(9600);
   Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  mstop();
}
void loop(){
 if (irrecv.decode(&results)) {
      switch(results.value){
        case 3227921619:mfront();break;
        case 3227954259:mback();break;
        case 3227937939:le();break;
        case 3227970579:ri();break;
        case 4294967295:keep();break;
        }
//    Serial.println(results.value);
    irrecv.resume(); // Receive the next value
  }
}
void mstop(){
  digitalWrite(In1, LOW);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, LOW);
 
}
void mfront(){
  Serial.println("f");
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  cur_dir=1;
  delay(500);
  mstop();
}
void mback(){
  Serial.println("b");
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  cur_dir=2;
  delay(500);
  mstop();
}
void le(){
  Serial.println("l");
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  cur_dir=3;
  delay(500);
  mstop();
}
void ri(){
  Serial.println("r");
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
  cur_dir=4;
  delay(500);
  mstop();
}

void keep()
{
  Serial.print("keep");
  Serial.println(cur_dir);
  switch(cur_dir){
        case 1:mfront();break;
        case 2:mback();break;
        case 3:le();break;
        case 4:ri();break;
        }
}
