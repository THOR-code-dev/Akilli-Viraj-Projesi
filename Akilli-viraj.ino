const int trigPin = 9;
const int echopin = 10; 
const int ledPin = 13; // Ultrasonik sensörün trig pin'i // Ultrasonik sensörun echo pin'i // LD'in bağlı olduğu pin
const int kirmiziPin = 12;

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echopin, INPUT); 
  pinMode(ledPin, OUTPUT);
  pinMode(kirmiziPin, OUTPUT);
}

void loop(){

//Ultrasonik sensorle mesate alçümu 
digitalWrite(trigPin, LOW); 
delayMicroseconds (1); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds (10); 
digitalWrite(trigPin, LOW);

long duration = pulseIn(echopin, HIGH);

// inaafe hesaplama (cm cinsindon) 
int distance = duration * 0.034 / 2;

Serial.print ("Mesafe: ");
Serial.print (distance);
Serial.println(" cm ");

// Mesafe 20 cm'den azsa LFD'i yak

  if (distance > 20) { 
    digitalWrite(ledPin, HIGH); 
    digitalWrite(kirmiziPin, LOW);
  } else{
    digitalWrite(ledPin, LOW);
    digitalWrite(kirmiziPin, HIGH);
  }


  delay(500);
}