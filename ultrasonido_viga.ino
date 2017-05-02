#include <SoftwareSerial.h>

#define rxPin 1
#define txPin 2

SoftwareSerial BTSerial (rxPin, txPin);

int distancia;
int distancia_enviar;
float tiempo;

int iteracion1=150;
int iteracion2=0;
//int iteracion3=0;

void setup(){
  Serial.begin(9600);
  BTSerial.begin(9600);
  
  pinMode(9, OUTPUT); /*activación del pin 9 como salida: para el pulso ultrasónico*/
  pinMode(8, INPUT); /*activación del pin 8 como entrada: tiempo del rebote del ultrasonido*/
}

void loop(){
  digitalWrite(9,LOW); /* Por cuestión de estabilización del sensor*/
  delayMicroseconds(5);
  digitalWrite(9, HIGH); /* envío del pulso ultrasónico*/
  delayMicroseconds(10);
  tiempo=pulseIn(8, HIGH); /* Función para medir la longitud del pulso entrante. Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, es decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  //distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
    distancia= round(0.17*tiempo);

//iteracion3=iteracion2;
iteracion2=iteracion1;
iteracion1=distancia;



if(iteracion1==iteracion2){ //&& iteracion2==iteracion3){
  distancia_enviar=(iteracion2);
}
//distancia_enviar=distancia;


if(distancia_enviar<100 || distancia_enviar>200){
    distancia_enviar =150;
}



Serial.println(distancia_enviar);
  delay(600);
}
