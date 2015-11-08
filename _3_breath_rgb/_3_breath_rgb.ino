
float x = 0.1;
int color = 0;
int pin[3] = {9, 10, 11};
int rgb[3] = {150, 0 ,150};

void setup() {
  Serial.begin(9600);
  pinMode(pin[0], OUTPUT);
  pinMode(pin[1], OUTPUT);
  pinMode(pin[2], OUTPUT);
  srand(analogRead(3));  
}

void loop() {
  Serial.print("sin(");
  Serial.print(x);
  Serial.print(") = ");
  Serial.print(sin(x));
  Serial.print(" --- ");
  Serial.println((255-rgb[0])*sin(x));
  
  x += 0.01;
  if (x>3.14) {
    x=0;
    rgb[0] = rand()%255;
    rgb[1] = rand()%255;
    rgb[2] = rand()%255;
    }

  analogWrite(pin[0], (rgb[0])*sin(x));
  analogWrite(pin[1], 255);
  analogWrite(pin[2], 255);
  
}
