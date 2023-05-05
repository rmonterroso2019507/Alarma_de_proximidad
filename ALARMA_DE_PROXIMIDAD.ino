/*
 * 
 Fundacion Kinal
 Centro Educativo Tecnico Laboral KINAL
 Electronica
 Grado:5to A
 Nombre:Roberto Monterroso
 Carne :2019507
 */
#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#define Direccion_LCD 0x27
#define FILAS 2
#define COLUMNAS 16
#define TRIG A2
#define ECHO A3
#define BUZZ A0
#define D1 2
#define D2 3
#define D3 4
#define D4 5
#define D5 6
#define D6 7
#define D7 8
#define D8 9
#define D9 10
#define D10 11
int DISTANCIA;
int i;

LiquidCrystal_I2C LCD_ROBERTO(Direccion_LCD, COLUMNAS, FILAS);


void setup()
{
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D9, OUTPUT);
  pinMode(D10, OUTPUT);
  for(i=2; i<=11;i++){
  }
  pinMode(BUZZ ,OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  LCD_ROBERTO.init();
  LCD_ROBERTO.backlight();
}


void loop()
{
  MEDIDA();
  ALARMA();
}
int MEDIDA(){
  long T; 
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIG, LOW);
  T = pulseIn(ECHO, HIGH);
  DISTANCIA = T/59;
  delay(50);
  return DISTANCIA;
}
int ALARMA(){
   if( DISTANCIA > 45 && DISTANCIA > 50){
    LCD_ROBERTO.setCursor(0,0);
    LCD_ROBERTO.print("FUERA DE ALCANCE");
    LCD_ROBERTO.setCursor(0,1);
    LCD_ROBERTO.print("ESPACIO PRIVADO ");
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      tone(BUZZ,260);
      delay(5000);
      noTone(BUZZ);
  }
  if( DISTANCIA < 45 && DISTANCIA > 30){
    LCD_ROBERTO.setCursor(0,0);
    LCD_ROBERTO.print(" ACERCANDOSE A  ");
    LCD_ROBERTO.setCursor(0,1);
    LCD_ROBERTO.print("ESPACIO PRIVADO ");
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      tone(BUZZ, 523);
      delay(5000);
      noTone(BUZZ);
  }
  if( DISTANCIA < 30 && DISTANCIA > 15){
    LCD_ROBERTO.setCursor(0,0);
    LCD_ROBERTO.print("   PRECAUCION   ");
    LCD_ROBERTO.setCursor(0,1);
    LCD_ROBERTO.print("ESPACIO PRIVADO ");
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
    tone(BUZZ, 1000);
    delay(5000);
    noTone(BUZZ);
  }


  if( DISTANCIA < 15 && DISTANCIA > 0){
    LCD_ROBERTO.setCursor(0,0);
    LCD_ROBERTO.print("   INVADIENDO   ");
    LCD_ROBERTO.setCursor(0,1);
    LCD_ROBERTO.print("ESPACIO PRIVADO ");
      digitalWrite(3, HIGH);
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
    tone(BUZZ, 3000);
    delay(10000);
    noTone(BUZZ);
 }
    else {
    noTone(BUZZ);
 }
    return 0;
 }
