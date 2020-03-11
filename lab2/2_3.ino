// Zadanie: 2.3. Sterowanie LED z terminala

#define LED_PIN 6


String msg = "";
int blinkingTime = 1000;
bool blinking = false;


void setup() {
  Serial.begin(9600);


  pinMode(LED_PIN, OUTPUT);


  Serial.println("LED ON  wlacza diode LED");
  Serial.println("LED OFF  wylacza diode LED");
  Serial.println("LED BLINK <czas_ms>  miga dioda LED");
  Serial.println("LED BLINK  miga dioda LED z ostatnio uzyta predkoscia");
}
void loop() {


  if (Serial.available() > 0) {
    msg = Serial.readStringUntil('\n');
    msg.toUpperCase();
    if (msg.equals("LED ON")) {
      Serial.println("Wlaczam diode. ");


      digitalWrite(LED_PIN, HIGH);   // włączamy diodę LED
      blinking = false;
    }
    else if (msg.equals("LED OFF")) {
      Serial.println("Wylaczam diode");


      digitalWrite(LED_PIN, LOW);
      blinking = false;
    }
    else if (msg.equals("LED BLINK")) {
      Serial.println("Wlaczam miganie. ");


      blinking = true;
    }
    else if (msg.startsWith("LED BLINK <")) {
      msg.remove(0, 11);
      msg.remove(msg.length() - 1);


      if (msg.toInt() > 0) {
        Serial.print("Wlaczam miganie z czasem w ms: ");
        Serial.println(msg);


        blinkingTime = msg.toInt();
        blinking = true;
      }
      else {
        Serial.println("Zly czas mrugania. ");
      }


    }
    else {
      Serial.println("Zla komenda.");
    }




  }


  if (blinking) {
    digitalWrite(LED_PIN, HIGH);   // włączamy diodę LED
    delay(blinkingTime);                   // czekamy 2 sekundy
    digitalWrite(LED_PIN, LOW);    // wyłączamy diodę LED
    delay(blinkingTime);                   // czekamy 1 sekundę
  }


}
