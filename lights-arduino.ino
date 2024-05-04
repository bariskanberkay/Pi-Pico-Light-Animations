#include "IRremote.h"

// Pin tanımları
const int red_1 = 4;
const int blue_1 = 5;
const int white = 13;
const int blue_2 = 12;
const int red_2 = 14;

// Değişkenler
int ledsActive = 1;
int animationIndex = 2;
int brightness = 255;
int timeMs = 100;

// IR alıcısı tanımlaması
String kod, sonkod; 
int sensor = 0; 



unsigned long previousMillis = 0;

// Animasyon fonksiyonları
void animation1();
void animation2();
void animation3();
void animation4();
void animation5();
void animation6();
void animation7();
void animation8();
void animation9();

// IR kumanda butonları
String buton1 = "BA45FF00";
String buton2 = "B946FF00";
String buton3 = "B847FF00";
String buton4 = "BB44FF00";
String buton5 = "BF40FF00";
String buton6 = "BC43FF00";
String buton7 = "F807FF00";
String buton8 = "EA15FF00";
String buton9 = "F609FF00";
String buton0 = "E619FF00";
String buton_yildiz = "E916FF00";
String buton_kare = "F20DFF00";
String buton_yukari = "E718FF00";
String buton_asagi = "AD52FF00";
String buton_sol = "F708FF00";
String buton_sag = "A55AFF00";
String buton_ok = "E31CFF00";

// IR alıcısını başlat

decode_results results;

// Setup fonksiyonu
void setup() {
  Serial.begin(115200);
  IrReceiver.begin(sensor, 0);
  pinMode(red_1, OUTPUT);
  pinMode(blue_1, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(blue_2, OUTPUT);
  pinMode(red_2, OUTPUT);

  toggleLeds(0, 0, 0, 0, 0);
}


// IR kumanda işleme fonksiyonu
void handleIRRemote() {
   if (IrReceiver.decode()) {
    kod = String(IrReceiver.decodedIRData.decodedRawData, HEX);
    kod.toUpperCase();

        if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
            IrReceiver.resume();
        } else {
                if (kod == buton1) {animationIndex = 1;}
                if (kod == buton2) {animationIndex = 2;}
                if (kod == buton3) {animationIndex = 3;}
                if (kod == buton4) {animationIndex = 4;}
                if (kod == buton5) {animationIndex = 5;}
                if (kod == buton6) {animationIndex = 6;}
                if (kod == buton0) {
                  if(ledsActive == 1){
                    ledsActive = 0;
                  }else{
                    ledsActive = 1;
                  }
                }

                if (kod == buton_yukari) {timeMs += 5;}
                if (kod == buton_asagi && timeMs > 0) {timeMs -= 5;}
                if (kod == buton_ok) { 
                    toggleLeds(255, 255, 255, 255, 255);
                    delay(20);
                    toggleLeds(0, 0, 0, 0, 0);
                    delay(20);
                }

                IrReceiver.resume();
        }
       
  



  }
}

void loop() {
 //toggleLeds(255, 0, 0, 0, 0);

  handleIRRemote(); // IR kumanda işleme
  handleAnimation(); // Animasyon işleme
}


void handleAnimation() {
  // Animasyon seçimi
  switch (animationIndex) {
    case 1:
      animation1();
      break;
    case 2:
      animation2();
      break;
    case 3:
      animation3();
      break;
    case 4:
      animation4();
      break;
    case 5:
      animation5();
      break;
    case 6:
      animation6();
      break;
    case 7:
      animation7();
      break;
    case 8:
      animation8();
      break;
    case 9:
      animation9();
      break;
  }
}

// LED'leri kontrol etme fonksiyonu
void toggleLeds(int k1, int b1, int w, int b2, int k2) {
  analogWrite(red_1, k1);
  analogWrite(blue_1, b1);
  analogWrite(white, w);
  analogWrite(blue_2, b2);
  analogWrite(red_2, k2);
}


// Animasyon 1: Sırayla her LED'i yakma ve söndürme
void animation1() {
  if (ledsActive == 0) { // LED'ler pasif durumdaysa, herhangi bir animasyonu çalıştırma
    toggleLeds(0, 0, 0, 0, 0);
    return;
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= timeMs) {
    previousMillis = currentMillis;
    static int step = 0;
    switch (step) {
      case 0:
        toggleLeds(brightness, 0, 0, 0, 0);
        break;
      case 1:
        toggleLeds(0, brightness, 0, 0, 0);
        break;
      case 2:
        toggleLeds(0, 0, brightness, 0, 0);
        break;
      case 3:
        toggleLeds(0, 0, 0, brightness, 0);
        break;
      case 4:
        toggleLeds(0, 0, 0, 0, brightness);
        break;
      case 5:
        toggleLeds(0, 0, 0, brightness, 0);
        break;
      case 6:
        toggleLeds(0, 0, brightness, 0, 0);
        break;
      case 7:
        toggleLeds(0, brightness, 0, 0, 0);
        break;
      case 8:
        toggleLeds(brightness, 0, 0, 0, 0);
        break;
    }
    step++;
    if (step > 8) {
      step = 0;
    }
  }
}

// Animasyon 2: Alternatif renklerdeki LED'leri yakma ve söndürme
void animation2() {
  if (ledsActive == 0) { // LED'ler pasif durumdaysa, herhangi bir animasyonu çalıştırma
    toggleLeds(0, 0, 0, 0, 0);
    return;
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= timeMs) {
    previousMillis = currentMillis;
    static int step = 0;
    switch (step) {
      case 0:
        toggleLeds(brightness, 0, brightness, brightness, 0);
        break;
      case 1:
        toggleLeds(0, brightness, 0, 0, brightness);
        break;
      case 2:
        toggleLeds(0, 0, 0, 0, 0);
        break;
    }
    step++;
    if (step > 1) {
      step = 0;
    }
  }
}

// Animasyon 3: Orta LED'leri sırayla yakma ve söndürme
void animation3() {
  if (ledsActive == 0) { // LED'ler pasif durumdaysa, herhangi bir animasyonu çalıştırma
    toggleLeds(0, 0, 0, 0, 0);
    return;
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= timeMs) {
    previousMillis = currentMillis;
    static int step = 0;
    switch (step) {
      case 0:
        toggleLeds(brightness, 0, 0, 0, brightness);
        break;
      case 1:
        toggleLeds(0, 0, 0, 0, 0);
        break;
      case 2:
        toggleLeds(0, brightness, 0, brightness, 0);
        break;
      case 3:
        toggleLeds(0, 0, 0, 0, 0);
        break;
    }
    step++;
    if (step > 3) {
      step = 0;
    }
  }
}

// Animasyon 4: Farklı kombinasyonlarda LED'leri yakma ve söndürme
void animation4() {
  if (ledsActive == 0) { // LED'ler pasif durumdaysa, herhangi bir animasyonu çalıştırma
    toggleLeds(0, 0, 0, 0, 0);
    return;
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= timeMs) {
    previousMillis = currentMillis;
    static int step = 0;
    switch (step) {
      case 0:
        toggleLeds(0, 0, brightness, 0, 0);
        break;
      case 1:
        toggleLeds(0, brightness, brightness, brightness, 0);
        break;
      case 2:
        toggleLeds(0, 0, 0, 0, 0);
        break;
      case 3:
        toggleLeds(brightness, 0, brightness, 0, brightness);
        break;
      case 4:
        toggleLeds(0, 0, 0, 0, 0);
        break;
    }
    step++;
    if (step > 4) {
      step = 0;
    }
  }
}



// Animasyon 5: İki farklı renkteki LED'leri sırayla yakma ve söndürme
void animation5() {
  if (ledsActive == 0) { // LED'ler pasif durumdaysa, herhangi bir animasyonu çalıştırma
    toggleLeds(0, 0, 0, 0, 0);
    return;
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= timeMs) {
    previousMillis = currentMillis;
    static int step = 0;
    switch (step) {
      case 0:
        toggleLeds(brightness, 0, 0, brightness, 0);
        break;
      case 1:
        toggleLeds(0, 0, 0, 0, 0);
        break;
      case 2:
        toggleLeds(brightness, 0, 0, brightness, 0);
        break;
      case 3:
        toggleLeds(0, 0, 0, 0, 0);
        break;
      case 4:
        toggleLeds(brightness, 0, 0, brightness, 0);
        toggleLeds(brightness, 0, brightness, brightness, 0);
        break;
      case 5:
        toggleLeds(0, 0, 0, 0, 0);
        break;
      case 6:
        toggleLeds(0, brightness, 0, 0, brightness);
        break;
      case 7:
        toggleLeds(0, 0, 0, 0, 0);
        break;
      case 8:
        toggleLeds(0, brightness, 0, 0, brightness);
        break;
      case 9:
        toggleLeds(0, 0, 0, 0, 0);
        break;
      case 10:
        toggleLeds(0, brightness, 0, 0, brightness);
        toggleLeds(0, brightness, brightness, 0, brightness);
        break;
      case 11:
        toggleLeds(0, 0, 0, 0, 0);
        break;
    }
    step++;
    if (step > 11) {
      step = 0;
    }
  }
}

// Animasyon 6: Tüm LED'leri aynı anda yakma ve söndürme
void animation6() {
  if (ledsActive == 0) { // LED'ler pasif durumdaysa, herhangi bir animasyonu çalıştırma
    toggleLeds(0, 0, 0, 0, 0);
    return;
  }

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= timeMs) {
    previousMillis = currentMillis;
    static int step = 0;
    switch (step) {
      case 0:
        toggleLeds(brightness, brightness, brightness, brightness, brightness);
        break;
      case 1:
        toggleLeds(0, 0, 0, 0, 0);
        break;
    }
    step++;
    if (step > 1) {
      step = 0;
    }
  }
}

// Animasyon 7: Orta LED'leri sırayla yakma ve söndürme, ardından yanıp sönme
void animation7() {
  toggleLeds(brightness, 0, 0, 0, 0);
}

// Animasyon 8: Orta LED'leri sırayla yakma ve söndürme, ardından farklı kombinasyonlarda yanıp sönme
void animation8() {
  if (ledsActive == 0) { // LED'ler pasif durumdaysa, herhangi bir animasyonu çalıştırma
    toggleLeds(0, 0, 0, 0, 0);
    return;
  }
}

// Animasyon 9: Rastgele LED'leri yakma ve söndürme
void animation9() {
  if (ledsActive == 0) { // LED'ler pasif durumdaysa, herhangi bir animasyonu çalıştırma
    toggleLeds(0, 0, 0, 0, 0);
    return;
  }
}
