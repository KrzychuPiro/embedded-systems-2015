int led = 8;
int pause = 300;
int i = 0;
String text = "";
String morse = "";


void to_morse(){
  for(i=0; i<text.length(); i++) {
      if (text.charAt(i)==' ') { morse += "  "; continue; }
      if (text.charAt(i)=='a') { morse += ".- "; continue; }
      if (text.charAt(i)=='ą') { morse += ".-.- "; continue; }
      if (text.charAt(i)=='b') { morse += "-... "; continue; }
      if (text.charAt(i)=='c') { morse += "-.-. "; continue; }
      if (text.charAt(i)=='ć') { morse += "-.-.. "; continue; }
      if (text.charAt(i)=='d') { morse += "-.. "; continue; }
      if (text.charAt(i)=='e') { morse += ". "; continue; }
      if (text.charAt(i)=='ę') { morse += "..-.. "; continue; }
      if (text.charAt(i)=='f') { morse += "..-. "; continue; }
      if (text.charAt(i)=='g') { morse += "--. "; continue; }
      if (text.charAt(i)=='h') { morse += ".... "; continue; }
      if (text.charAt(i)=='i') { morse += ".. "; continue; }
      if (text.charAt(i)=='j') { morse += ".-- "; continue; }
      if (text.charAt(i)=='k') { morse += "-.- "; continue; }
      if (text.charAt(i)=='l') { morse += ".-.. "; continue; }
      if (text.charAt(i)=='ł') { morse += ".-..- "; continue; }
      if (text.charAt(i)=='m') { morse += "-- "; continue; }
      if (text.charAt(i)=='n') { morse += "-. "; continue; }
      if (text.charAt(i)=='ń') { morse += "--.-- "; continue; }
      if (text.charAt(i)=='o') { morse += "--- "; continue; }
      if (text.charAt(i)=='ó') { morse += "---. "; continue; }
      if (text.charAt(i)=='p') { morse += ".--. "; continue; }
      if (text.charAt(i)=='q') { morse += "--. "; continue; }
      if (text.charAt(i)=='r') { morse += ".-. "; continue; }
      if (text.charAt(i)=='s') { morse += "... "; continue; }
      if (text.charAt(i)=='ś') { morse += "...-... "; continue; }
      if (text.charAt(i)=='t') { morse += "- "; continue; }
      if (text.charAt(i)=='u') { morse += "..- "; continue; }
      if (text.charAt(i)=='v') { morse += "...- "; continue; }
      if (text.charAt(i)=='w') { morse += ".-- "; continue; }
      if (text.charAt(i)=='x') { morse += "-..- "; continue; }
      if (text.charAt(i)=='y') { morse += "-.- "; continue; }
      if (text.charAt(i)=='z') { morse += "--.. "; continue; }
      if (text.charAt(i)=='ź') { morse += "--..- "; continue; }
      if (text.charAt(i)=='ż') { morse += "--..-. "; continue; }
      
      if (text.charAt(i)=='0') { morse += "----- "; continue; }
      if (text.charAt(i)=='1') { morse += ".---- "; continue; }
      if (text.charAt(i)=='2') { morse += "..--- "; continue; }
      if (text.charAt(i)=='3') { morse += "...-- "; continue; }
      if (text.charAt(i)=='4') { morse += "....- "; continue; }
      if (text.charAt(i)=='5') { morse += "..... "; continue; }
      if (text.charAt(i)=='6') { morse += "-.... "; continue; }
      if (text.charAt(i)=='7') { morse += "--... "; continue; }
      if (text.charAt(i)=='8') { morse += "---.. "; continue; }
      if (text.charAt(i)=='9') { morse += "----. "; continue; }
    }
}

void show_morse() {
  for(i=0; i<morse.length(); i++) {
    if (morse.charAt(i)=='.') {
      digitalWrite(led, HIGH);
      delay(pause);
      digitalWrite(led, LOW);
    }
    if (morse.charAt(i)=='-') {
      digitalWrite(led, HIGH);
      delay(pause*3);
      digitalWrite(led, LOW);
    }
    if (morse.charAt(i)==' ') {
      delay(pause*3);
    }
    delay(pause);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  if(Serial.available() > 0)
    {
        text = Serial.readStringUntil('\n');   
    }
  if (text != "") 
  {
    text.toLowerCase();
    Serial.println(text);
    to_morse();
    Serial.println(morse);
    show_morse();
    text = morse = "";
  }
}
