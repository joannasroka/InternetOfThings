// Zadanie: 2.2Czas wciśnięcia przycisku

#define LED_PIN 6
#define GREEN_BUTTON 4

unsigned long time = 0;
unsigned long timeOn;
unsigned long timeOff;
unsigned long resultTime;


bool lastStateGreen = HIGH;


unsigned long hours = 0;
unsigned long minutes = 0;
unsigned long seconds = 0;


void setup() {
  Serial.begin(9600);
  pinMode(GREEN_BUTTON, INPUT_PULLUP);
  Serial.println("Wcisnij zielony przycisk!");
}
void loop() {
  bool currentStateGreen = digitalRead(GREEN_BUTTON);
  time = millis();


  // if (lastStateGreen != currentStateGreen) {  //wykrywamy zbocze
  // delay(20);




  if (lastStateGreen != currentStateGreen) {
    if (currentStateGreen == LOW) {         //przycisk wcisniety
      timeOn = time;
    }
    if (currentStateGreen == HIGH) {
      timeOff = time;
      resultTime = timeOff - timeOn;
      Serial.println("Przycisk wcisniety przez: ");
      Serial.print(resultTime);
      Serial.print(" ---> ");


      hours = resultTime / 3600000;
      resultTime = resultTime - hours * 3600000;


      minutes = resultTime / 60000;
      resultTime = resultTime - minutes * 60000;


      seconds = resultTime / 1000;
      resultTime = resultTime - seconds * 1000;


      Serial.print(hours);
      Serial.print(":");
      if (minutes < 10) Serial.print("0");
      Serial.print(minutes);
      Serial.print(":");
      if (seconds < 10) Serial.print("0");
      Serial.print(seconds);
      Serial.print(".");
      Serial.print(resultTime);
      Serial.println("");


    }
  }
  // }




  lastStateGreen = currentStateGreen;


}
