/*--------------- Moises Piñate 

Conexiones al L293D (Puente H integrado con diodos)
 pin 2 Arduino ---> pin 2 del Integrado
 pin 3 Arduino ---> pin 7 del Integrado
 pin 4 Arduino ---> pin 10 del Integrado
 pin 5 Arduino ---> pin 15 del Integrado

 Voltaje externo -> pin 8 del integrado.
 5V Arduino ------> pines 1,9,16 del integrado
 GND Arduino -----> pines 4,5,12,13 del integrado

 Salidas L293D (Puente H integrado con diodos):

 Motor 1 ----> Pines 3 y 6 (Motor de traccion)
 Motor 2 ----> Pines 11 y 14 (Motor de direccion)

 Modulo Bluetooth

 Arduino     Modulo
 Pin 0 -----  RX
 Pin 1 -----  TX
 5V --------  VCC
 GND -------  GND

*/

//#include <SoftwareSerial.h> // NO USÉ ESTA LIBRERIA DABA PROBLEMAS
//SoftwareSerial mySerial(10, 11); // RX, TX Pines 10 y 11 como puertos seriales // ESTO NO VA

int  DatoBluetooth = 'c'; //Comienza detenido (Toma el valor "integer" del caracter de entrada
int  adelante = 2;  //PIN 2 ARDUINO 
int  atras = 3;     //PIN 3 ARDUINO
int  izq = 4;       //PIN 4 ARDUINO
int  der = 5;       //PIN 5 ARDUINO

void setup()
{
  // Abrimos la comunicacion serial del arduino a 9600 baudios (bits/seg)
  Serial.begin(9600);
  //mySerial.begin(9600); // NO USÉ ESTO DABA PROBLEMAS
  //mySerial.println("Conecado a la pc"); //TAMPOCO ESTA 

  pinMode(adelante, OUTPUT); // Configuramos pines como salidas
  pinMode(atras, OUTPUT);
  pinMode(izq, OUTPUT);
  pinMode(der, OUTPUT);
  
}
void loop() //LOOP DE EJECUCIÓN
{
  if (Serial.available()>0){
     DatoBluetooth = Serial.read();
  }
  
  if(DatoBluetooth == 'a'){     // DESPLAZAMIENTO HACIA ADELANTE
    digitalWrite(adelante,HIGH);
    digitalWrite(atras,LOW);    
  }
  if(DatoBluetooth == 'b'){     // DESPLAZAMIENTO HACIA LA IZQUIERDA
    digitalWrite(adelante,HIGH);
    digitalWrite(atras,LOW);
    digitalWrite(izq,HIGH);
    digitalWrite(der,LOW);   
  }
    if(DatoBluetooth == 'c'){     // DETENIDO
    digitalWrite(adelante,LOW);
    digitalWrite(atras,LOW);
    digitalWrite(izq,LOW);
    digitalWrite(der,LOW);
    digitalWrite(A0,HIGH);
    digitalWrite(A1,LOW);     
  }
    if(DatoBluetooth == 'd'){     // DESPLAZAMIENTO HACIA LA DERECHA
    digitalWrite(adelante,HIGH);
    digitalWrite(atras,LOW);
    digitalWrite(izq,LOW);
    digitalWrite(der,HIGH);   
  }
    if(DatoBluetooth == 'e'){     // RETROCESO (NO LA USARE EN AUTÓMATAS SOLO PARA ROBÓTICA)
    digitalWrite(adelante,LOW);
    digitalWrite(atras,HIGH);
    digitalWrite(A1,HIGH);
    digitalWrite(A0,LOW);  
  }  
}
