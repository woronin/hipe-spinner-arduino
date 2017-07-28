#define SENSOR_PIN 10
#define blink_PIN 13

void setup()
{

  pinMode(SENSOR_PIN, INPUT);
  digitalWrite(SENSOR_PIN, HIGH);
  Serial.begin(9600);
}

void loop()
{
 static int  n=0, max_n=0;
 int state = digitalRead(SENSOR_PIN);
 static uint8_t prev_state = 0;
 static unsigned long time1 = 0; // объявление переменной time типа unsigned long
 unsigned long time2; // объявление переменной time типа unsigned long
 

      if (state != prev_state)
      {
      if (state ==1) {digitalWrite(blink_PIN,HIGH); }//  если 1, то горит
      if (state ==0) {digitalWrite(blink_PIN,LOW); }//  если 0 то гаснет
       n++;
       prev_state= state;
     
      }
   time2 = millis();    // передача количества миллисекунд 
       
   if (time2-time1 >= 2000) 
   {

    n=n/2;
    if (n>max_n) {max_n=n; }
      Serial.print( "(Hz)actual=");
      Serial.print(n);
      Serial.print("; max=");
      Serial.print(max_n);      
      Serial.print("\n");      
         n=0;
         time1=millis();
      }
 
}
