int hall = A0;
int hall_value = 0;
int led = 2;
int button = 3;
int piezo = 4;
int random_seed = A3;
int random_value = 0;

void setup() {
  srand(analogRead(random_seed));  
  Serial.begin(9600);
  pinMode(hall, INPUT);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  pinMode(piezo, OUTPUT);
  digitalWrite(piezo, HIGH);
}

void loop() {
  if (digitalRead(button) == 1)
  {
    random_value = rand() % 1000;
  }
digitalWrite(piezo, HIGH);
  //Serial.println("Hall: %c,  Rand: %d" % (analogRead(hall), random_value));
  /*Serial.print(random_value);
  Serial.print("    ");
  Serial.println(analogRead(hall));*/
  Serial.print("Button: ");
  Serial.print(digitalRead(button));
  Serial.print("  Piezo: ");
  Serial.println(digitalRead(piezo));

  hall_value = analogRead(hall);
  if (hall_value-5 < random_value && hall_value+5 > random_value)
  {
    digitalWrite(piezo, HIGH);
    digitalWrite(led, HIGH);
  }
  if (digitalRead(button) == LOW ) 
  {
    digitalWrite(piezo, LOW);
    digitalWrite(led, LOW);
  }
}
