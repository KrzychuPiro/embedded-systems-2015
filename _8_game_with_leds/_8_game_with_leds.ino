#include <Time.h>  

int leds[4] = {9,10,11,12};
int light;
int action_x = 5;
int action_y = 6;
int value_x;
int value_y;

int total_score = 0;
int points = 0;
int base_points = 100;

int start_time = 0;
int base_game_time = 10;

String text = "";

void setup() {
  Serial.begin(9600);
  pinMode(leds[0], OUTPUT);
  pinMode(leds[1], OUTPUT);
  pinMode(leds[2], OUTPUT);
  pinMode(leds[3], OUTPUT);
  pinMode(action_x, INPUT);
  pinMode(action_y, INPUT);
}

void random_led(){
  light = random(0,4);
  digitalWrite(leds[light], HIGH);
}

int catch_led(){
  // TODO
  /* This part is used to test buttons. Remove it if you use a joystick */
  int lx[2] = {1,2};
  int ly[2] = {0,3};
  if (value_x==1 && value_y==0)  { return lx[random(0,2)]; }
  if (value_x==0 && value_y==1)  { return ly[random(0,2)]; }
  /* ========================================================= */
  
  if (value_x==1 && value_y==0)  { return 1; } //right
  if (value_x==-1 && value_y==0) { return 2; } //left
  if (value_x==0 && value_y==1)  { return 3; } //up
  if (value_x==0 && value_y==-1) { return 0; } //down
  return -1;
}

int get_action(int pin){
  // TODO
  /* use this function to return joystick's input mapped to {-1,0,1} */
  return digitalRead(pin);
}

void game(){
  random_led();
  start_time = now();
  points = base_points;
  
  while (now()-start_time < base_game_time) {
    delay(10);
    value_x = get_action(action_x);
    value_y = get_action(action_y);
    
    if (light == catch_led()) {
      digitalWrite(leds[light], LOW);
      Serial.println(points);
      total_score += points;
      points = base_points;
      
      delay(500);
      random_led();
    }
    if (points > 0) { points--; }
  }
  
  digitalWrite(leds[light], LOW);
}

void loop() {
  if(Serial.available() > 0)
    {
        text = Serial.readStringUntil('\n'); 
        text.toLowerCase();
        if (text.startsWith("time:") && isDigit(text.substring(6)[0])) {
          base_game_time = text.substring(5).toInt();
          Serial.print("New time: ");
          Serial.print(base_game_time);
          Serial.println(" seconds");
        }
        else if(text == "start"){
          game();
          Serial.print("Your score: ");
          Serial.println(total_score);
          total_score = 0;
        }
    }
}
