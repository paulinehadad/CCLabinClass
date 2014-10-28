// Uses a PIR sensor to detect movement, buzzes a buzzer
// more info here: http://blog.makezine.com/projects/pir-sensor-arduino-alarm/
// email me, John Park, at jp@jpixl.net
// based upon:
// PIR sensor tester by Limor Fried of Adafruit
// tone code by michael@thegrebs.com


const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;



int counter = 0;


int analogData; 
int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
int pinSpeaker = 10;           //Set up a speaker on a PWM pin (digital 9, 10, or 11)
int micPin = A0;
//int threshold = 500;


void setup() {
  Serial.begin(9600);
  //pinMode(micPin, INPUT);
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(pinSpeaker, OUTPUT);

}

void loop(){
  analogData = analogRead(micPin);
  Serial.println(analogData);
  delay(100);
  
  val = digitalRead(inputPin);  // read input value
  if ((val == HIGH) || (analogData > 0)) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    //Play first section
    firstSection();
    delay(150);



  } 
  else {
    digitalWrite(ledPin, LOW); // turn LED OFF

    delay(300);    

  }
}

void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(pinSpeaker, note, duration);

  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin, HIGH);
    delay(duration);
    digitalWrite(ledPin, LOW);
  }
  else
  {
    digitalWrite(ledPin, HIGH);
    delay(duration);
    digitalWrite(ledPin, LOW);
  }

  //Stop tone on buzzerPin
  noTone(pinSpeaker);

  delay(50);

  //Increment counter
  counter++;
}

void firstSection()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);

  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);

  delay(500);
}

