#define Knopka_PIN 11
#define blink_PIN 13
void setup()
{

  pinMode(Knopka_PIN, INPUT);
  digitalWrite(Knopka_PIN, HIGH);
 Serial.begin(9600);
}

void loop()
{
 
 int state = digitalRead(Knopka_PIN);

// Serial.println( state);
if (state == 1)
{
  digitalWrite(blink_PIN, HIGH);
}
else 
{
  digitalWrite(blink_PIN, LOW);
}


 
}
