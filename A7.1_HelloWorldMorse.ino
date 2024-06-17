eit
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}
#define  LANG 1000
#define  DOT 500

// the loop function runs over and over again forever

  void dodot()
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(DOT);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW); 
  delay(500);
 
}
 void dolang()
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(LANG);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW); 
  delay(500);
 
}
void loop() {

  // H
dodot();
dodot();
dodot();
dodot();
  //E
dodot();
  //L
dodot();
delay(1000);
dolang();
dodot();
dodot();
  //L
dodot();
delay(1000);
dolang();
dodot();
dodot();
  //O
delay(1000);
dolang();
delay(1000);
dolang();
delay(1000);
dolang();
  //W
dodot();
delay(1000);
dolang();
delay(1000);
dolang();
  //O
delay(1000);
dolang();
delay(1000);
dolang();
delay(1000);
dolang();
  //R
dodot();
delay(1000);
dolang();
dodot();
 //L
dodot();
delay(1000);
dolang();
dodot();
dodot();
  //D
delay(1000);
dolang();
dodot();
dodot();

  //!
delay(1000);
dolang();
dodot();
delay(1000);
dolang();
dodot();
delay(1000);
dolang();
delay(1000);
dolang();

}
