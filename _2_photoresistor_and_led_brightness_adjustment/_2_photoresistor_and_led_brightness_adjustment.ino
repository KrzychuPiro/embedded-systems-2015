int lightsens = A0;
int led = 10;
int butMIN = 4;
int butMAX = 2;
int LSValue = 0;
int a = 0;
int b = 255;

void setup() 
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(butMIN, INPUT);
  pinMode(butMAX, INPUT);
}

void loop() 
{
  LSValue = analogRead(lightsens);
  LSValue = map(LSValue, 0, 1023, 0, 255);

  a = b-LSValue;
  a = constrain(a, 30, 255);
  /*
  if(a<30) a=0;
  if(a>255) a=255;*/
  analogWrite(led, a);

  Serial.print(LSValue);
  Serial.print("    ");
  Serial.println(a);
  
  if(digitalRead(butMIN) == HIGH)
  {
    b = LSValue;
  }
  else if(digitalRead(butMAX) == HIGH)
  {
    b = 255+LSValue;
  }
}
