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
dolang();
  //E
dolang();
  //L
dodot();
dodot();delay(1000);
dodot();
dolang();
  //L
dodot();
dodot();delay(1000);
dodot();
dolang();
  //O
dodot();delay(1000);
dodot();delay(1000);
dodot();delay(1000);
  //W
dodot();
dodot();delay(1000);
dodot();delay(1000);
  //O
dodot();delay(1000);
dodot();delay(1000);
dodot();delay(1000);
  //R
dodot();
dodot();delay(1000);
dolang();
 //L
dodot();
dodot();delay(1000);
dodot();
dolang();
  //D
dodot();delay(1000);
dodot();
dolang();

  //!
dodot();delay(1000);
dodot();
dodot();delay(1000);
dodot();
dodot();delay(1000);
dodot();delay(1000);

}
