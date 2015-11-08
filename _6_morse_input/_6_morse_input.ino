int led = 8;
int button = 9;
int short_pause = 20;
int long_pause = 40;
int action_time = 40;
int i = 0;
bool pushed = false;
String morse = "";


void to_text(){
    if (morse == ".-")    { Serial.print("a"); return; }
    if (morse == ".-.-")  { Serial.print("ą"); return; }
    if (morse == "-...")  { Serial.print("b"); return; }
    if (morse == "-.-.")  { Serial.print("c"); return; }
    if (morse == "-.-..") { Serial.print("ć"); return; }
    if (morse == "-..")   { Serial.print("d"); return; }
    if (morse == ".")     { Serial.print("e"); return; }
    if (morse == "..-..") { Serial.print("ę"); return; }
    if (morse == "..-.")  { Serial.print("f"); return; }
    if (morse == "--.")   { Serial.print("g"); return; }
    if (morse == "....")  { Serial.print("h"); return; }
    if (morse == "..")    { Serial.print("i"); return; }
    if (morse == ".--")   { Serial.print("j"); return; }
    if (morse == "-.-")   { Serial.print("k"); return; }
    if (morse == ".-..")  { Serial.print("l"); return; }
    if (morse == ".-..-") { Serial.print("ł"); return; }
    if (morse == "--")    { Serial.print("m"); return; }
    if (morse == "-.")    { Serial.print("n"); return; }
    if (morse == "--.--") { Serial.print("ń"); return; }
    if (morse == "---")   { Serial.print("o"); return; }
    if (morse == "---.")  { Serial.print("ó"); return; }
    if (morse == ".--.")  { Serial.print("p"); return; }
    if (morse == "--.")   { Serial.print("q"); return; }
    if (morse == ".-.")   { Serial.print("r"); return; }
    if (morse == "...")   { Serial.print("s"); return; }
    if (morse == "...-..."){Serial.print("ś"); return; }
    if (morse == "-")     { Serial.print("t"); return; }
    if (morse == "..-")   { Serial.print("u"); return; }
    if (morse == "...-")  { Serial.print("v"); return; }
    if (morse == ".--")   { Serial.print("w"); return; }
    if (morse == "-..-")  { Serial.print("x"); return; }
    if (morse == "-.-")   { Serial.print("y"); return; }
    if (morse == "--..")  { Serial.print("z"); return; }
    if (morse == "--..-") { Serial.print("ź"); return; }
    if (morse == "--..-."){ Serial.print("ż"); return; }
    
    if (morse == "-----") { Serial.print("0"); return; }
    if (morse == ".----") { Serial.print("1"); return; }
    if (morse == "..---") { Serial.print("2"); return; }
    if (morse == "...--") { Serial.print("3"); return; }
    if (morse == "....-") { Serial.print("4"); return; }
    if (morse == ".....") { Serial.print("5"); return; }
    if (morse == "-....") { Serial.print("6"); return; }
    if (morse == "--...") { Serial.print("7"); return; }
    if (morse == "---..") { Serial.print("8"); return; }
    if (morse == "----.") { Serial.print("9"); return; }
}

void read_morse() {
  if (action_time < long_pause) {
    morse += ".";
  }
  else {
    morse += "-";
  }
}


/* ========== button actions =========== */
bool button_down() {
  if (digitalRead(button)==HIGH) { 
    if (!pushed) {
      return true; 
    }
  }
  return false;
}

bool button_up() {
  if (digitalRead(button)==LOW) { 
    if (pushed) { 
      return true; 
    }
  }
  return false;
}

bool button_pushed() {
  if (digitalRead(button)==HIGH) { 
    if (pushed) { 
      return true; 
    }
  }
  return false;
}

bool button_free() {
  if (digitalRead(button)==LOW) { 
    if (!pushed) { 
      return true; 
    }
  }
  return false;
}


/* ========== setup =========== */
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

/* ========== loop  =========== */
void loop() {
  if (button_down()) {
    pushed = true;
    action_time = 0;
    digitalWrite(led, HIGH);
  }
  if (button_up()) {
    read_morse();
    pushed = false;
    action_time = 0;
    digitalWrite(led, LOW); 
  }
  if (button_pushed()) {
    action_time ++;
  }
  if (button_free() && action_time < long_pause*2) {
    action_time ++;
    if (action_time == short_pause) {
      to_text();
      morse = "";
    }
    if (action_time == long_pause) { 
      Serial.print("-"); 
    }
  }
  delay(50);
}
