int led = 9;
int button = 2;
int pushes[100];
int i = 0;
bool a = false;

void setup() 
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() 
{
    if (a)
  {
    if(pushes[i]==0)
    {
      digitalWrite(led, LOW);
    }
    else
    {
      digitalWrite(led, HIGH);
    }
  }
  Serial.print("Button: "); Serial.println(digitalRead(button));
  pushes[i] = digitalRead(button);
  delay(10);
  i++;
  i %= 100;

  if(i == 99)
  {
    a = true;
  }
}
