// 2.1 Licznik na dwa przyciski

#define LED_PIN 6
#define GREEN_BUTTON 4
#define RED_BUTTON 2


int counter = 0;
bool lastStateGreen = HIGH;
bool lastStateRed = HIGH;


void setup() {
  Serial.begin(9600);
  pinMode(GREEN_BUTTON, INPUT_PULLUP);
  pinMode(RED_BUTTON, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);


  Serial.println("Wcisnij ktorys przycisk!");
}
void loop() {
  bool currentStateGreen = digitalRead(GREEN_BUTTON);
  bool currentStateRed = digitalRead(RED_BUTTON);




  if (lastStateGreen != currentStateGreen || lastStateRed != currentStateRed) {
    delay(50);


    currentStateGreen = digitalRead(GREEN_BUTTON);
    currentStateRed = digitalRead(RED_BUTTON);


    if (currentStateGreen == LOW && currentStateRed == LOW) {
      Serial.println("Wcisnieto oba przyciski!");
      if (counter > 0) {
        for (int i = 0; i < counter; i++) {
          digitalWrite(LED_PIN, HIGH);   // włączamy diodę LED
          delay(1000);                   // czekamy 2 sekundy
          digitalWrite(LED_PIN, LOW);    // wyłączamy diodę LED
          delay(1000);                   // czekamy 1 sekundę




        }
      }
    }


    else if (currentStateRed == LOW) {


      counter++;
      Serial.print("Licznik = ");
      Serial.println(counter);
    }


    else if (currentStateGreen == LOW) {
      counter--;
      Serial.print("Licznik = ");
      Serial.println(counter);


    }


  }




  lastStateGreen = currentStateGreen;
  lastStateRed = currentStateRed;
}
