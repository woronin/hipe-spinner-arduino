//////////////////////////////////////////////
//     2017.07.18 woronin, darsavelli, umkiedu@gmail.com      //
//////////////////////////////////////////////
 
// определение режима соединения и подключение библиотеки RemoteXY  
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>
#include <RemoteXY.h>
 
 
// настройки соединения  
#define REMOTEXY_SERIAL_RX 7  
#define REMOTEXY_SERIAL_TX 8
#define REMOTEXY_SERIAL_SPEED 9600
#define hollpin 10
#define blink_PIN 13
 
// конфигурация интерфейса   
#pragma pack(push, 1) 
uint8_t RemoteXY_CONF[] = 
  { 255,0,0,22,0,156,0,6,5,0,
  67,4,2,30,37,20,2,11,67,4,
  55,30,38,20,2,11,129,0,0,24,
  99,3,12,208,162,208,181,208,186,209,
  131,209,137,208,176,209,143,32,209,129,
  208,186,208,190,209,128,208,190,209,129,
  209,130,209,140,32,208,178,209,128,208,
  176,209,137,208,181,208,189,208,184,209,
  143,32,32,32,32,32,32,32,208,156,
  208,176,208,186,209,129,208,184,208,188,
  208,176,208,187,209,140,208,189,208,176,
  209,143,32,209,129,208,186,208,190,209,
  128,208,190,209,129,209,130,209,140,32,
  208,178,209,128,208,176,209,137,208,181,
  208,189,208,184,209,143,0,129,0,36,
  3,22,8,9,208,163,208,156,208,154,
  208,152,0 }; 
   
// структура определяет все переменные вашего интерфейса управления  
struct {
 
    // output variable
  char text_1[11];
  char text_2[11];
  int8_t level_1;
    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0
 
} RemoteXY;
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////
void setup()  
{
  RemoteXY_Init ();  
  pinMode(hollpin , INPUT);
  digitalWrite(hollpin , 1);
  Serial.begin(9600);
}
 
void loop()  
{  
static int oborot=0, bufmax=0, bufoborot=0;
int  state = digitalRead(hollpin);
static uint8_t prev_state = 1;
static unsigned long  last_millis=0;
 
 
  RemoteXY_Handler ();
  if (state != prev_state)
  {
      if (state ==1) {digitalWrite(blink_PIN,HIGH); }//  если 1, то горит
      if (state ==0) {digitalWrite(blink_PIN,LOW); }//  если 0 то гаснет
    oborot++;
    prev_state= state;
  }
  if (millis() - last_millis >= 1000)
  {
 
   bufoborot = oborot/2;
   itoa(bufoborot, RemoteXY.text_1, 10);
   if (bufoborot > bufmax)
   {
    bufmax = bufoborot;
    itoa(bufmax,  RemoteXY.text_2, 10);
   }
    oborot=0;
    last_millis = millis();
  }
  // TODO you loop code
  // используйте структуру RemoteXY для передачи данных
}
