#define           piezo           3
#define           btn_1           5                     // & 1 $ 4 2 5 * 3 # 순
#define           btn_2           6
#define           btn_3           7
#define           btn_4           8
#define           btn_5           9
#define           btn_6           10
#define           btn_7           11
#define           btn_8           12
#define           btn_9           13

#include "LedControl.h"//MAX7219 라이브러리는 첨부

LedControl lc = LedControl(A0, A1, A2, 7);

char key, temp_key;
String num, num1;
int num2;   
int a = 0 , b = 0 , c = 0 , d = 0, k = 0 , p = 0, q = 0;
int s = 0 , t = 0 , v = 0;
int inpin = 31;
int in2pin = 30;
boolean e = true;
boolean f = false;


boolean m = false, o = false;
boolean g(boolean e);
boolean h(boolean e);
boolean i(boolean e);
boolean j(boolean e);
boolean n(boolean m);
boolean w(boolean e);

int tones[] = {  262, 294, 330, 349, 392, 440, 494, 523, 587};
  
void piezoTone(int t) {
  tone(piezo, t);  delay(200);  noTone(piezo);
}

String msg = "";
char recvChar;
int state = 0;

char read_btn(){
  key = 'x';
  if( digitalRead(btn_1) == LOW){
    key = '&';
    Serial.println(key);
    piezoTone(tones[0]);
    delay(1);    while(digitalRead(btn_1)==LOW);    delay(1);
  }
  if( digitalRead(btn_2) == LOW){
    key = '1';
    Serial.println(key);
    piezoTone(tones[0]);
    delay(1);    while(digitalRead(btn_1)==LOW);    delay(1);
  }
  if( digitalRead(btn_3) == LOW){
    key = '$';
    Serial.println(key);
    piezoTone(tones[0]);
    delay(1);    while(digitalRead(btn_1)==LOW);    delay(1);
  }
  if( digitalRead(btn_4) == LOW){
    key = '4';
    Serial.println(key);
    piezoTone(tones[0]);
    delay(1);    while(digitalRead(btn_1)==LOW);    delay(1);
  }
  if( digitalRead(btn_5) == LOW){
    key = '2';
    Serial.println(key);
    piezoTone(tones[0]);
    delay(1);    while(digitalRead(btn_1)==LOW);    delay(1);
  }
  if( digitalRead(btn_6) == LOW){
    key = '5';
    Serial.println(key);
    piezoTone(tones[0]);
    delay(1);    while(digitalRead(btn_1)==LOW);    delay(1);
  }
  if( digitalRead(btn_7) == LOW){
    key = '*';
    Serial.println(key);
    piezoTone(tones[0]);
    delay(1);    while(digitalRead(btn_1)==LOW);    delay(1);
  }
  if( digitalRead(btn_8) == LOW){
    key = '3';
    Serial.println(key);
    piezoTone(tones[0]);
    delay(1);    while(digitalRead(btn_1)==LOW);    delay(1);
  }
  if( digitalRead(btn_9) == LOW){
    key = '#';
    Serial.println(key);
    piezoTone(tones[0]);
    delay(1);    while(digitalRead(btn_1)==LOW);    delay(1);
  }
  return key;
}

void setup() {
  Serial.begin(9600);       Serial1.begin(9600);
      pinMode(inpin, INPUT);
    pinMode(in2pin, INPUT);
  pinMode(piezo, OUTPUT);
  for(int i = 5; i < 14; i++)pinMode(i, INPUT_PULLUP);
  for (num2 = 0; num2 < 7; num2++){
    lc.shutdown(num2, false);lc.setIntensity(num2, 8);lc.clearDisplay(num2);      
  }
  
}

void loop() {
    int val = digitalRead(inpin);
    int bal = digitalRead(in2pin);
  if (state == 0) {
    if (val == 1){
    char key = read_btn();
    if (key!='x'){     
      Serial.print("key : ");      Serial.println(key); 
      temp_key = key;
      if (temp_key == '1') piezoTone(tones[0]);
      else if (temp_key == '2') piezoTone(tones[1]);
      else if (temp_key == '3') piezoTone(tones[2]);
      else if (temp_key == '4') piezoTone(tones[3]);
      else if (temp_key == '5') piezoTone(tones[4]);
      else if (temp_key == '#') piezoTone(tones[5]);
      else if (temp_key == '*') piezoTone(tones[6]);
      else if (temp_key == '$') piezoTone(tones[7]);
      else if (temp_key == '&') piezoTone(tones[8]);
      temp_key = ' ';

      if (key == '*'  ){    //다음 한글로 넘어가는 키
        a++;        
       if ( a == 1){
        }else if ( a == 2){
          b = 0;          c = 0;
        }else if ( a == 3){
          b = -2;          c = 0;          k = 1;
          p = 2;          q = 3;          s = 5;
          t = 6;
        }else if ( a == 4){
          b = -2;          c = -4;          v = 3;
        }else if ( a == 5){
          d = 3;          b = 0;          c = 0;
          k = 0;          p = 0;          q = 0;
          s = 0;          t = 0;          v = 0;
        }else if ( a == 6){
          b = 0;          c = 0;
        }else if ( a == 7){
          b = -2;          c = 0;          k = 1;
          p = 2;          q = 3;          s = 5;
          t = 6;
        }else if ( a == 8){
          b = -2;          c = -4;          a = 0;
          v = 3;
        }        
        state = 1;
      }else if (key == '&' ){   //지우는 키
        if ( a == 1 ) {
            g(m); //초성  LED
            a = 0;
          }else if ( a == 2 ) {
            h(m); //중성  LED
            a = 1;
          }else if ( a == 3 ) {
            i(m);  // 종1 LED
            k = 0;            b = 0;            c = 0;
            a = 2;
          }else if ( a == 4 ) {
            j(m);  // 종2 LED
            b = -2;            c = 0;            a = 3;
            p = 2;            q = 3;            s = 5;
            t = 6;            v = 0;
          }else if ( a == 5 ) {
            g(m); //두번째초성  LED
            d = 0;            a = 4;            b = -2;
            c = -4;           v = 3;
          }else if ( a == 6 ) {
            h(m); //중성  LED
            b = 0;            c = 0;            k = 0;
            d = 3;            a = 5;            p = 0;
            q = 0;            s = 0;            t = 0;
            v = 0;
          }else if ( a == 7 ) {
            i(m);  // 종1 LED
            b = 0;            c = 0;            a = 6;
          }else if ( a == 8 ) {
            j(m);  // 종2 LED
            b = -2;            c = 0;            a = 7;
            k = 1;            p = 2;            q = 3;
            s = 5;            t = 6;            v = 0;
          }
        state = 1;
      }else if (key == '$' ){
        lc.clearDisplay(0);        lc.clearDisplay(1);        lc.clearDisplay(2);
        lc.clearDisplay(3);        lc.clearDisplay(4);        lc.clearDisplay(5);
        n(m);
        a = 0;        b = 0;        c = 0;
        k = 0;        d = 0;        p = 0;
        q = 0;        s = 0;        t = 0;
        v = 0;
      }else if (key == '#'){
        a = 4;
      }
      else{
        num = key;
        num1.concat(num);
      }
    }
    if (Serial1.available()) {        //블루투스 데이터가 수신되면
      recvChar = Serial1.read();       //recvChar 변수에 데이터를 저장
      Serial.print("recvChar : ");
      Serial.println(recvChar);

      temp_key = recvChar;
      if (temp_key == '1') piezoTone(tones[0]);
      else if (temp_key == '2') piezoTone(tones[1]);
      else if (temp_key == '3') piezoTone(tones[2]);
      else if (temp_key == '4') piezoTone(tones[3]);
      else if (temp_key == '5') piezoTone(tones[4]);
      else if (temp_key == '#') piezoTone(tones[5]);
      else if (temp_key == '*') piezoTone(tones[6]);
      else if (temp_key == '$') piezoTone(tones[7]);
      else if (temp_key == '&') piezoTone(tones[8]);
      temp_key = ' ';
      
      if (recvChar == '*'){ //다음 한글로 넘어가는 키    
        a++;
        if ( a == 1){
        }else if ( a == 2){
          b = 0;          c = 0;
        }else if ( a == 3){
          b = -2;          c = 0;          k = 1;
          p = 2;          q = 3;          s = 5;
          t = 6;
        }else if ( a == 4){
          b = -2;          c = -4;          v = 3;
        }else if ( a == 5){
          d = 3;          b = 0;          c = 0;
          k = 0;          p = 0;          q = 0;
          s = 0;          t = 0;          v = 0;
        }else if ( a == 6){
          b = 0;          c = 0;
        }else if ( a == 7){
          b = -2;          c = 0;          k = 1;
          p = 2;          q = 3;          s = 5;
          t = 6;
        }else if ( a == 8){
          b = -2;          c = -4;          a = 0;
          v = 3;
        }        
        state = 1;
        }else if (recvChar == '&'){    //지우는 키        
          if ( a == 1 ) {
            g(m); //초성  LED
            a = 0;
          }else if ( a == 2 ) {
            h(m); //중성  LED
            a = 1;
          }else if ( a == 3 ) {
            i(m);  // 종1 LED
            k = 0;            b = 0;            c = 0;
            a = 2;
          }else if ( a == 4 ) {
            j(m);  // 종2 LED
            b = -2;            c = 0;            a = 3;
            p = 2;            q = 3;            s = 5;
            t = 6;            v = 0;
          }else if ( a == 5 ) {
            g(m); //두번째초성  LED
            d = 0;            a = 4;            b = -2;
            c = -4;           v = 3;
          }else if ( a == 6 ) {
            h(m); //중성  LED
            b = 0;            c = 0;            k = 0;
            d = 3;            a = 5;            p = 0;
            q = 0;            s = 0;            t = 0;
            v = 0;
          }else if ( a == 7 ) {
            i(m);  // 종1 LED
            b = 0;            c = 0;            a = 6;
          }else if ( a == 8 ) {
            j(m);  // 종2 LED
            b = -2;            c = 0;            a = 7;
            k = 1;            p = 2;            q = 3;
            s = 5;            t = 6;            v = 0;
          }
          state = 1;
        }else if (recvChar == '$')      {
        lc.clearDisplay(0);        lc.clearDisplay(1);        lc.clearDisplay(2);
        lc.clearDisplay(3);        lc.clearDisplay(4);        lc.clearDisplay(5);
          n(m);
          a = 0;        b = 0;        c = 0;
          k = 0;        d = 0;        p = 0;
          q = 0;        s = 0;        t = 0;
          v = 0;
        }else if (recvChar == '#'){
          a = 4;
      }else{
          num = recvChar;        num1.concat(num);
        }
     }
    }
       else if (bal == 1){        //영어일때
    char key = read_btn();
    if (key!='x'){     
      Serial.print("key : ");      Serial.println(key); 
      temp_key = key;
      if (temp_key == '1') piezoTone(tones[0]);
      else if (temp_key == '2') piezoTone(tones[1]);
      else if (temp_key == '3') piezoTone(tones[2]);
      else if (temp_key == '4') piezoTone(tones[3]);
      else if (temp_key == '5') piezoTone(tones[4]);
      else if (temp_key == '#') piezoTone(tones[5]);
      else if (temp_key == '*') piezoTone(tones[6]);
      else if (temp_key == '$') piezoTone(tones[7]);
      else if (temp_key == '&') piezoTone(tones[8]);
      temp_key = ' ';

      if (key == '*'  ){    //다음 영어로 넘어가는 키
        a++;
        if ( a == 1){
        }else if ( a == 2){
          d = 3;          
        }else if ( a == 3){
          b = 0;          c = 0;          k = 1;
          p = 0;          q = 3;          s = 5;
          t = 6;          d = 0;
        }else if ( a == 4){
          b = 0;          c = 0;          k = 1;
          p = 0;          q = 3;          s = 5;
          t = 6;          d = 3;
        }
        state = 1;
      }else if (key == '&' ){   //지우는 키
          if ( a == 1 ) {
            w(m);
            a = 0;
          }else if ( a == 2 ) {
            w(m);
            a = 1;
          }else if ( a == 3 ) {
            w(m);
          d = 0;            a = 5;            p = 0;            q = 3;            s = 5;
          t = 6;            v = 0;
          }else if ( a == 4 ) {
            w(m);
          d = 3;            a = 6;            p = 0;            q = 3;            s = 5;
          t = 6;            v = 0;
          }
        state = 1;
      }else if (key == '$' ){
        lc.clearDisplay(0);        lc.clearDisplay(1);        lc.clearDisplay(2);
        lc.clearDisplay(3);        lc.clearDisplay(4);        lc.clearDisplay(5);
        n(m);
        a = 0;        b = 0;        c = 0;
        k = 0;        d = 0;        p = 0;
        q = 0;        s = 0;        t = 0;
        v = 0;
      }else if (key == '#'){
        if (a=0){
          a=1;
      }else if (a=1){
          a=2;
      }else if (a=2){
          a=3;
      }else if (a=3){
          a=4;
      }
      }else{
        num = key;
        num1.concat(num);
      }
    }
    if (Serial1.available()) {        //블루투스 데이터가 수신되면
      recvChar = Serial1.read();       //recvChar 변수에 데이터를 저장
      Serial.print("recvChar : ");
      Serial.println(recvChar);

      temp_key = recvChar;
      if (temp_key == '1') piezoTone(tones[0]);
      else if (temp_key == '2') piezoTone(tones[1]);
      else if (temp_key == '3') piezoTone(tones[2]);
      else if (temp_key == '4') piezoTone(tones[3]);
      else if (temp_key == '5') piezoTone(tones[4]);
      else if (temp_key == '#') piezoTone(tones[5]);
      else if (temp_key == '*') piezoTone(tones[6]);
      else if (temp_key == '$') piezoTone(tones[7]);
      else if (temp_key == '&') piezoTone(tones[8]);
      temp_key = ' ';
      
      if (recvChar == '*'){ //다음 영어로 넘어가는 키    
        a++;
        if ( a == 1){
        }else if ( a == 2){
          d = 3;          
        }else if ( a == 3){
          b = 0;          c = 0;          k = 1;
          p = 0;          q = 3;          s = 5;
          t = 6;          d = 0;
        }else if ( a == 4){
          b = 0;          c = 0;          k = 1;
          p = 0;          q = 3;          s = 5;
          t = 6;          d = 3;
        }
        state = 1;
        }else if (recvChar == '&'){    //지우는 키        
          if ( a == 1 ) {
            w(m);
            a = 0;
          }else if ( a == 2 ) {
            w(m);
            a = 1;
          }else if ( a == 3 ) {
            w(m);
          d = 0;            a = 5;            p = 0;            q = 3;            s = 5;
          t = 6;            v = 0;
          }else if ( a == 4 ) {
            w(m);
          d = 3;            a = 6;            p = 0;            q = 3;            s = 5;
          t = 6;            v = 0;
          }
          state = 1;
        }else if (recvChar == '$')      {
        lc.clearDisplay(0);        lc.clearDisplay(1);        lc.clearDisplay(2);
        lc.clearDisplay(3);        lc.clearDisplay(4);        lc.clearDisplay(5);
          n(m);
          a = 0;        b = 0;        c = 0;
          k = 0;        d = 0;        p = 0;
          q = 0;        s = 0;        t = 0;
          v = 0;
        }else if (recvChar == '#')      {
        if (a=0){
          a=1;
      }else if (a=1){
          a=2;
      }else if (a=2){
          a=3;
      }else if (a=3){
          a=4;
      }
        }else{
          num = recvChar;        num1.concat(num);
        }
     }
    }
    else {
    char key = read_btn();
    if (key!='x'){     
      Serial.print("key : ");      Serial.println(key); 
      temp_key = key;
      if (temp_key == '1') piezoTone(tones[0]);
      else if (temp_key == '2') piezoTone(tones[1]);
      else if (temp_key == '3') piezoTone(tones[2]);
      else if (temp_key == '4') piezoTone(tones[3]);
      else if (temp_key == '5') piezoTone(tones[4]);
      else if (temp_key == '#') piezoTone(tones[5]);
      else if (temp_key == '*') piezoTone(tones[6]);
      else if (temp_key == '$') piezoTone(tones[7]);
      else if (temp_key == '&') piezoTone(tones[8]);
      temp_key = ' ';

      if (key == '*'  ){    //다음 숫자로 넘어가는 키
        a++;
        if ( a == 1){
        }else if ( a == 2){
          d = 3;          
        }else if ( a == 3){
          b = 0;          c = 0;          k = 1;
          p = 0;          q = 3;          s = 5;
          t = 6;          d = 0;
        }else if ( a == 4){
          b = 0;          c = 0;          k = 1;
          p = 0;          q = 3;          s = 5;
          t = 6;          d = 3;
        }
        state = 1;
      }else if (key == '&' ){   //지우는 키
          if ( a == 1 ) {
            w(m);
            a = 0;
          }else if ( a == 2 ) {
            w(m);
            a = 1;
          }else if ( a == 3 ) {
            w(m);
          d = 0;            a = 5;            p = 0;            q = 3;            s = 5;
          t = 6;            v = 0;
          }else if ( a == 4 ) {
            w(m);
          d = 3;            a = 6;            p = 0;            q = 3;            s = 5;
          t = 6;            v = 0;
          }
        state = 1;
      }else if (key == '$' ){
        lc.clearDisplay(0);        lc.clearDisplay(1);        lc.clearDisplay(2);
        lc.clearDisplay(3);        lc.clearDisplay(4);        lc.clearDisplay(5);
        n(m);
        a = 0;        b = 0;        c = 0;
        k = 0;        d = 0;        p = 0;
        q = 0;        s = 0;        t = 0;
        v = 0;
      }else if (key == '#'){
        if (a=0){
          a=1;
      }else if (a=1){
          a=2;
      }else if (a=2){
          a=3;
      }else if (a=3){
          a=4;
      }
      }else{
        num = key;
        num1.concat(num);
      }
    }
    if (Serial1.available()) {        //블루투스 데이터가 수신되면
      recvChar = Serial1.read();       //recvChar 변수에 데이터를 저장
      Serial.print("recvChar : ");
      Serial.println(recvChar);

      temp_key = recvChar;
      if (temp_key == '1') piezoTone(tones[0]);
      else if (temp_key == '2') piezoTone(tones[1]);
      else if (temp_key == '3') piezoTone(tones[2]);
      else if (temp_key == '4') piezoTone(tones[3]);
      else if (temp_key == '5') piezoTone(tones[4]);
      else if (temp_key == '#') piezoTone(tones[5]);
      else if (temp_key == '*') piezoTone(tones[6]);
      else if (temp_key == '$') piezoTone(tones[7]);
      else if (temp_key == '&') piezoTone(tones[8]);
      temp_key = ' ';
      
      if (recvChar == '*'){ //다음 숫자로 넘어가는 키    
        a++;
        if ( a == 1){
        }else if ( a == 2){
          d = 3;          
        }else if ( a == 3){
          b = 0;          c = 0;          k = 1;
          p = 0;          q = 3;          s = 5;
          t = 6;          d = 0;
        }else if ( a == 4){
          b = 0;          c = 0;          k = 1;
          p = 0;          q = 3;          s = 5;
          t = 6;          d = 3;
        }
        state = 1;
        }else if (recvChar == '&'){    //지우는 키        
          if ( a == 1 ) {
            w(m);
            a = 0;
          }else if ( a == 2 ) {
            w(m);
            a = 1;
          }else if ( a == 3 ) {
            w(m);
          d = 0;            a = 5;            p = 0;            q = 3;            s = 5;
          t = 6;            v = 0;
          }else if ( a == 4 ) {
            w(m);
          d = 3;            a = 6;            p = 0;            q = 3;            s = 5;
          t = 6;            v = 0;
          }
          state = 1;
        }else if (recvChar == '$')      {
        lc.clearDisplay(0);        lc.clearDisplay(1);        lc.clearDisplay(2);
        lc.clearDisplay(3);        lc.clearDisplay(4);        lc.clearDisplay(5);
          n(m);
          a = 0;        b = 0;        c = 0;
          k = 0;        d = 0;        p = 0;
          q = 0;        s = 0;        t = 0;
          v = 0;
        }else if (recvChar == '#')      {
        if (a=0){
          a=1;
      }else if (a=1){
          a=2;
      }else if (a=2){
          a=3;
      }else if (a=3){
          a=4;
      }
        }else{
          num = recvChar;        num1.concat(num);
        }
     }
     }
  }
  if (state == 1) {
    if(val == 1){
    Serial.println(num1);
    if (num1.equals("15") == 1 ){
      Serial.println("r");   // 한글ㄱ
      lc.setLed(d + k, 2 + b, 4 + c, true);      lc.setLed(d + k, 3 + b, 4 + c, true);      lc.setLed(d + k, 4 + b, 4 + c, true);
      lc.setLed(d + k, 5 + b, 4 + c, true);      lc.setLed(d + k, 6 + b, 4 + c, true);      lc.setLed(d + k, 6 + b, 5 + c, true);
      lc.setLed(d + k, 6 + b, 6 + c, true);      lc.setLed(d + k, 6 + b, 7 + c, true);
      Serial.println("r");   // 점자 초성ㄱ
      lc.setLed(d + 2, 0 + s, 1 + p + v, e);
    }else if (num1.equals("43") == 1){
      Serial.println("s");   // 점자 초성ㄴ
      lc.setLed(d + 2, 0 + t, 0 + q + v, e);      lc.setLed(d + 2, 0 + t, 1 + q + v, e);
      Serial.println("s");   // 한글ㄴ
      lc.setLed(d + k, 6 + b, 7 + c, true);      lc.setLed(d + k, 5 + b, 7 + c, true);      lc.setLed(d + k, 4 + b, 7 + c, true);
      lc.setLed(d + k, 3 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 6 + c, true);
      lc.setLed(d + k, 2 + b, 5 + c, true);      lc.setLed(d + k, 2 + b, 4 + c, true);
    }else if (num1.equals("143") == 1){
      Serial.println("e");   // 한글ㄷ
      lc.setLed(d + k, 6 + b, 7 + c, true);      lc.setLed(d + k, 5 + b, 7 + c, true);      lc.setLed(d + k, 4 + b, 7 + c, true);
      lc.setLed(d + k, 3 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 6 + c, true);
      lc.setLed(d + k, 2 + b, 5 + c, true);      lc.setLed(d + k, 2 + b, 4 + c, true);      lc.setLed(d + k, 6 + b, 6 + c, true);
      lc.setLed(d + k, 6 + b, 5 + c, true);      lc.setLed(d + k, 6 + b, 4 + c, true);
      Serial.println("e");   // 점자 초성ㄷ(2)
      lc.setLed(d + 2, 0 + t, 1 + q + v, e);
      lc.setLed(d + 2, 1 + t, 0 + q + v, e);
    }else if (num1.equals("1543") == 1){
      Serial.println("f");   // 한글ㄹ
      lc.setLed(d + k, 6 + b, 7 + c, true);      lc.setLed(d + k, 6 + b, 6 + c, true);      lc.setLed(d + k, 6 + b, 5 + c, true);
      lc.setLed(d + k, 6 + b, 4 + c, true);      lc.setLed(d + k, 5 + b, 4 + c, true);      lc.setLed(d + k, 4 + b, 4 + c, true);
      lc.setLed(d + k, 4 + b, 5 + c, true);      lc.setLed(d + k, 4 + b, 6 + c, true);      lc.setLed(d + k, 4 + b, 7 + c, true);
      lc.setLed(d + k, 3 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 6 + c, true);
      lc.setLed(d + k, 2 + b, 5 + c, true);      lc.setLed(d + k, 2 + b, 4 + c, true);
      Serial.println("f");   // 점자 초성ㄹ
      lc.setLed(d + 2, 1 + s, 1 + p + v, e);
    }else if (num1.equals("4153") == 1){
      Serial.println("a");   // 한글ㅁ
      lc.setLed(d + k, 6 + b, 7 + c, true);      lc.setLed(d + k, 5 + b, 7 + c, true);      lc.setLed(d + k, 4 + b, 7 + c, true);
      lc.setLed(d + k, 3 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 6 + c, true);
      lc.setLed(d + k, 2 + b, 5 + c, true);      lc.setLed(d + k, 2 + b, 4 + c, true);      lc.setLed(d + k, 6 + b, 6 + c, true);
      lc.setLed(d + k, 6 + b, 5 + c, true);      lc.setLed(d + k, 6 + b, 4 + c, true);      lc.setLed(d + k, 5 + b, 4 + c, true);
      lc.setLed(d + k, 4 + b, 4 + c, true);      lc.setLed(d + k, 3 + b, 4 + c, true);
      Serial.println("a");   // 초성 점자 ㅁ
      lc.setLed(d + 2, 0 + t, 0 + q + v, e);
      lc.setLed(d + 2, 1 + t, 1 + q + v, e);
    }else if (num1.equals("4513") == 1){
      Serial.println("q");   // 한글ㅂ
      lc.setLed(d + k, 6 + b, 7 + c, true);      lc.setLed(d + k, 5 + b, 7 + c, true);      lc.setLed(d + k, 4 + b, 7 + c, true);
      lc.setLed(d + k, 3 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 7 + c, true);      lc.setLed(d + k, 6 + b, 4 + c, true);
      lc.setLed(d + k, 5 + b, 4 + c, true);      lc.setLed(d + k, 4 + b, 4 + c, true);      lc.setLed(d + k, 3 + b, 4 + c, true);
      lc.setLed(d + k, 2 + b, 4 + c, true);      lc.setLed(d + k, 4 + b, 6 + c, true);      lc.setLed(d + k, 4 + b, 5 + c, true);
      lc.setLed(d + k, 2 + b, 6 + c, true);      lc.setLed(d + k, 2 + b, 5 + c, true);
      Serial.println("q");   // 점자 초성ㅂ
      lc.setLed(d + 2, 0 + s, 1 + p + v, e);      lc.setLed(d + 2, 1 + s, 1 + p + v, e);
    }else if (num1.equals("145") == 1){
      Serial.println("t");   // 한글ㅅ
      lc.setLed(d + k, 6 + b, 5 + c, true);      lc.setLed(d + k, 5 + b, 5 + c, true);      lc.setLed(d + k, 4 + b, 6 + c, true);
      lc.setLed(d + k, 3 + b, 6 + c, true);      lc.setLed(d + k, 2 + b, 6 + c, true);      lc.setLed(d + k, 4 + b, 4 + c, true);
      lc.setLed(d + k, 3 + b, 4 + c, true);      lc.setLed(d + k, 2 + b, 4 + c, true);
      Serial.println("t");   // 점자 초성ㅅ
      lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }else if (num1.equals("1435") == 1){
      Serial.println("d");   // 한글ㅇ
      lc.setLed(d + k, 5 + b, 7 + c, true);      lc.setLed(d + k, 4 + b, 7 + c, true);      lc.setLed(d + k, 3 + b, 7 + c, true);
      lc.setLed(d + k, 2 + b, 6 + c, true);      lc.setLed(d + k, 2 + b, 5 + c, true);      lc.setLed(d + k, 6 + b, 6 + c, true);
      lc.setLed(d + k, 6 + b, 5 + c, true);      lc.setLed(d + k, 5 + b, 4 + c, true);      lc.setLed(d + k, 4 + b, 4 + c, true);
      lc.setLed(d + k, 3 + b, 4 + c, true);
      Serial.println("d");   // 점자 초성ㅇ
      lc.setLed(d + 2, 1 + s, 0 + q + v, e);      lc.setLed(d + 2, 1 + s, 1 + q + v, e);      lc.setLed(d + 2, 2 + s, 0 + q + v, e);
      lc.setLed(d + 2, 2 + s, 1 + q + v, e);
    }else if (num1.equals("453") == 1){
      Serial.println("w");   // 한글ㅈ
      lc.setLed(d + k, 6 + b, 5 + c, true);      lc.setLed(d + k, 5 + b, 5 + c, true);      lc.setLed(d + k, 4 + b, 6 + c, true);
      lc.setLed(d + k, 3 + b, 6 + c, true);      lc.setLed(d + k, 2 + b, 6 + c, true);      lc.setLed(d + k, 4 + b, 4 + c, true);
      lc.setLed(d + k, 3 + b, 4 + c, true);      lc.setLed(d + k, 2 + b, 4 + c, true);      lc.setLed(d + k, 6 + b, 6 + c, true);
      lc.setLed(d + k, 6 + b, 4 + c, true);
      Serial.println("w");   // 점자 초성ㅈ
      lc.setLed(d + 2, 0 + s + v, 1 + p + v, e);
      lc.setLed(d + 2, 2 + s + v, 1 + p + v, e);
    }else if (num1.equals("2453") == 1){
      Serial.println("c");   // 한글ㅊ
      lc.setLed(d + k, 2 + b, 6 + c, true);      lc.setLed(d + k, 3 + b, 6 + c, true);      lc.setLed(d + k, 2 + b, 4 + c, true);
      lc.setLed(d + k, 3 + b, 4 + c, true);      lc.setLed(d + k, 4 + b, 5 + c, true);      lc.setLed(d + k, 5 + b, 5 + c, true);
      lc.setLed(d + k, 6 + b, 5 + c, true);      lc.setLed(d + k, 5 + b, 6 + c, true);      lc.setLed(d + k, 5 + b, 4 + c, true);
      Serial.println("c");   // 점자 초성ㅊ
      lc.setLed(d + 2, 1 + s, 1 + p + v, e);
      lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }else if (num1.equals("152") == 1){
      Serial.println("z");   // 한글ㅋ
      lc.setLed(d + k, 2 + b, 4 + c, true);      lc.setLed(d + k, 3 + b, 4 + c, true);      lc.setLed(d + k, 4 + b, 4 + c, true);
      lc.setLed(d + k, 5 + b, 4 + c, true);      lc.setLed(d + k, 6 + b, 4 + c, true);      lc.setLed(d + k, 6 + b, 5 + c, true);
      lc.setLed(d + k, 6 + b, 6 + c, true);      lc.setLed(d + k, 6 + b, 7 + c, true);      lc.setLed(d + k, 4 + b, 7 + c, true);
      lc.setLed(d + k, 4 + b, 6 + c, true);      lc.setLed(d + k, 4 + b, 5 + c, true);
      Serial.println("z");   // 점자 초성ㅋ
      lc.setLed(d + 2, 0 + t, 0 + q + v, e);      lc.setLed(d + 2, 1 + t, 0 + q + v, e);      lc.setLed(d + 2, 0 + t, 1 + q + v, e);
    }else if (num1.equals("1453") == 1){
      Serial.println("x");   // 한글ㅌ
      lc.setLed(d + k, 6 + b, 7 + c, true);      lc.setLed(d + k, 5 + b, 7 + c, true);      lc.setLed(d + k, 4 + b, 7 + c, true);
      lc.setLed(d + k, 3 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 6 + c, true);
      lc.setLed(d + k, 2 + b, 5 + c, true);      lc.setLed(d + k, 2 + b, 4 + c, true);      lc.setLed(d + k, 6 + b, 6 + c, true);
      lc.setLed(d + k, 6 + b, 5 + c, true);      lc.setLed(d + k, 6 + b, 4 + c, true);      lc.setLed(d + k, 4 + b, 6 + c, true);
      lc.setLed(d + k, 4 + b, 5 + c, true);      lc.setLed(d + k, 4 + b, 4 + c, true);
      Serial.println("x");   // 점자 초성ㅌ
      lc.setLed(d + 2, 0 + t, 0 + q + v, e);      lc.setLed(d + 2, 1 + t, 0 + q + v, e);      lc.setLed(d + 2, 1 + t, 1 + q + v, e);
    }else if (num1.equals("1432") == 1){
      Serial.println("v");   // 한글ㅍ
      lc.setLed(d + k, 2 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 6 + c, true);      lc.setLed(d + k, 2 + b, 5 + c, true);
      lc.setLed(d + k, 2 + b, 4 + c, true);      lc.setLed(d + k, 2 + b, 3 + c, true);      lc.setLed(d + k, 3 + b, 6 + c, true);
      lc.setLed(d + k, 4 + b, 6 + c, true);      lc.setLed(d + k, 5 + b, 6 + c, true);      lc.setLed(d + k, 5 + b, 7 + c, true);
      lc.setLed(d + k, 3 + b, 4 + c, true);      lc.setLed(d + k, 4 + b, 4 + c, true);      lc.setLed(d + k, 5 + b, 4 + c, true);
      lc.setLed(d + k, 5 + b, 3 + c, true);      lc.setLed(d + k, 5 + b, 5 + c, true);
      Serial.println("v");   // 점자 초성ㅍ
      lc.setLed(d + 2, 0 + t, 0 + q + v, e);      lc.setLed(d + 2, 0 + t, 1 + q + v, e);      lc.setLed(d + 2, 1 + t, 1 + q + v, e);
    }else if (num1.equals("11453") == 1){
      Serial.println("g");   // 점자 초성ㅎ
      lc.setLed(d + 2, 0 + t, 1 + q + v, e);      lc.setLed(d + 2, 1 + t, 1 + q + v, e);      lc.setLed(d + 2, 1 + t, 0 + q + v, e);
      Serial.println("g");   // 한글ㅎ
      lc.setLed(d + k, 6 + b, 5 + c, true);      lc.setLed(d + k, 5 + b, 7 + c, true);      lc.setLed(d + k, 5 + b, 6 + c, true);
      lc.setLed(d + k, 5 + b, 5 + c, true);      lc.setLed(d + k, 5 + b, 4 + c, true);      lc.setLed(d + k, 5 + b, 3 + c, true);
      lc.setLed(d + k, 4 + b, 5 + c, true);      lc.setLed(d + k, 3 + b, 6 + c, true);      lc.setLed(d + k, 2 + b, 5 + c, true);
      lc.setLed(d + k, 3 + b, 4 + c, true);
    }else if (num1.equals("1515") == 1){
      Serial.println("rr");   // 한글ㄲ
      lc.setLed(d + k, 6 + b, 7 + c, true);      lc.setLed(d + k, 6 + b, 6 + c, true);      lc.setLed(d + k, 6 + b, 5 + c, true);
      lc.setLed(d + k, 6 + b, 4 + c, true);      lc.setLed(d + k, 6 + b, 3 + c, true);      lc.setLed(d + k, 5 + b, 5 + c, true);
      lc.setLed(d + k, 4 + b, 5 + c, true);      lc.setLed(d + k, 3 + b, 5 + c, true);      lc.setLed(d + k, 2 + b, 5 + c, true);
      lc.setLed(d + k, 5 + b, 3 + c, true);      lc.setLed(d + k, 4 + b, 3 + c, true);      lc.setLed(d + k, 3 + b, 3 + c, true);
      lc.setLed(d + k, 2 + b, 3 + c, true);
      Serial.println("rr");   // 점자 초성ㄲ
      lc.setLed(d + 2, 0 + s, 4 + p, e);      lc.setLed(d + 2, 2 + s, 1 + q, e);
    }else if (num1.equals("143143") == 1){
      Serial.println("ee");   // 한글ㄸ
      lc.setLed(d + k, 6 + b, 7 + c, true);      lc.setLed(d + k, 6 + b, 6 + c, true);      lc.setLed(d + k, 6 + b, 5 + c, true);
      lc.setLed(d + k, 6 + b, 4 + c, true);      lc.setLed(d + k, 6 + b, 3 + c, true);      lc.setLed(d + k, 2 + b, 7 + c, true);
      lc.setLed(d + k, 2 + b, 6 + c, true);      lc.setLed(d + k, 2 + b, 5 + c, true);      lc.setLed(d + k, 2 + b, 4 + c, true);
      lc.setLed(d + k, 2 + b, 3 + c, true);      lc.setLed(d + k, 5 + b, 7 + c, true);      lc.setLed(d + k, 4 + b, 7 + c, true);
      lc.setLed(d + k, 3 + b, 7 + c, true);      lc.setLed(d + k, 5 + b, 5 + c, true);      lc.setLed(d + k, 4 + b, 5 + c, true);
      lc.setLed(d + k, 3 + b, 5 + c, true);
      Serial.println("ee");   // 점자 초성ㄸ
      lc.setLed(d + 2, 0 + t, 4 + q, e);      lc.setLed(d + 2, 1 + t, 3 + q, e);      lc.setLed(d + 2, 2 + s, 1 + q, e);
    }else if (num1.equals("45134513") == 1){
      Serial.println("qq");   // 한글ㅃ
      lc.setLed(d + k, 6 + b, 7 + c, true);      lc.setLed(d + k, 5 + b, 7 + c, true);      lc.setLed(d + k, 4 + b, 7 + c, true);
      lc.setLed(d + k, 3 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 7 + c, true);      lc.setLed(d + k, 6 + b, 5 + c, true);
      lc.setLed(d + k, 5 + b, 5 + c, true);      lc.setLed(d + k, 4 + b, 5 + c, true);      lc.setLed(d + k, 3 + b, 5 + c, true);
      lc.setLed(d + k, 2 + b, 5 + c, true);      lc.setLed(d + k, 6 + b, 3 + c, true);      lc.setLed(d + k, 5 + b, 3 + c, true);
      lc.setLed(d + k, 4 + b, 3 + c, true);      lc.setLed(d + k, 3 + b, 3 + c, true);      lc.setLed(d + k, 2 + b, 3 + c, true);
      lc.setLed(d + k, 4 + b, 6 + c, true);      lc.setLed(d + k, 2 + b, 6 + c, true);      lc.setLed(d + k, 4 + b, 4 + c, true);
      lc.setLed(d + k, 2 + b, 4 + c, true);
      Serial.println("qq");   // 점자 초성ㅃ
      lc.setLed(d + 2, 0 + s, 4 + p, e);      lc.setLed(d + 2, 1 + s, 4 + p, e);      lc.setLed(d + 2, 2 + s, 1 + q, e);
    }else if (num1.equals("145145") == 1){
      Serial.println("tt");   // 한글ㅆ
      lc.setLed(d + k, 5 + b, 6 + c, true);      lc.setLed(d + k, 4 + b, 6 + c, true);      lc.setLed(d + k, 5 + b, 4 + c, true);
      lc.setLed(d + k, 4 + b, 4 + c, true);      lc.setLed(d + k, 3 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 7 + c, true);
      lc.setLed(d + k, 3 + b, 5 + c, true);      lc.setLed(d + k, 2 + b, 5 + c, true);      lc.setLed(d + k, 3 + b, 3 + c, true);
      lc.setLed(d + k, 2 + b, 3 + c, true);
      Serial.println("tt");   // 점자 초성ㅆ
      lc.setLed(d + 2, 2 + s, 4 + 2, e);      lc.setLed(d + 2, 2 + s, 1 + q, e);
    }else if (num1.equals("453453") == 1){
      Serial.println("ww");   // 한글ㅉ
      lc.setLed(d + k, 5 + b, 6 + c, true);      lc.setLed(d + k, 4 + b, 6 + c, true);      lc.setLed(d + k, 5 + b, 4 + c, true);
      lc.setLed(d + k, 4 + b, 4 + c, true);      lc.setLed(d + k, 3 + b, 7 + c, true);      lc.setLed(d + k, 2 + b, 7 + c, true);
      lc.setLed(d + k, 3 + b, 5 + c, true);      lc.setLed(d + k, 2 + b, 5 + c, true);      lc.setLed(d + k, 3 + b, 3 + c, true);
      lc.setLed(d + k, 2 + b, 3 + c, true);      lc.setLed(d + k, 5 + b, 7 + c, true);      lc.setLed(d + k, 5 + b, 5 + c, true);
      lc.setLed(d + k, 5 + b, 3 + c, true);
      Serial.println("ww");   // 점자 초성ㅉ
      lc.setLed(d + 2, 0 + s, 4 + p, e);      lc.setLed(d + 2, 2 + s, 4 + p, e);      lc.setLed(d + 2, 2 + s, 1 + q, e);
    }else if (num1.equals("42") == 1){
      Serial.println("k");   // 한글ㅏ
      lc.setLed(d, 6, 2, e);      lc.setLed(d, 5, 2, e);      lc.setLed(d, 4, 2, e);
      lc.setLed(d, 3, 2, e);      lc.setLed(d, 2, 2, e);      lc.setLed(d, 1, 2, e);
      lc.setLed(d, 0, 2, e);      lc.setLed(d, 2, 1, e);      lc.setLed(d + 1, 6, 2, e);
      lc.setLed(d + 1, 7, 2, e);
      Serial.println("k");   // 점자 중성ㅏ(1)
      lc.setLed(d + 2, 0, 6, e);      lc.setLed(d + 2, 1, 6, e);      lc.setLed(d + 2, 2, 7, e);
    }else if (num1.equals("422") == 1){
      Serial.println("i");   // 한글ㅑ
      lc.setLed(d, 6, 2, e);      lc.setLed(d, 5, 2, e);      lc.setLed(d, 4, 2, e);
      lc.setLed(d, 3, 2, e);      lc.setLed(d, 2, 2, e);      lc.setLed(d, 1, 2, e);
      lc.setLed(d, 0, 2, e);      lc.setLed(d, 3, 1, e);      lc.setLed(d, 1, 1, e);
      lc.setLed(d + 1, 6, 2, e);      lc.setLed(d + 1, 7, 2, e);
      Serial.println("i");   // 점자 중성ㅑ
      lc.setLed(d + 2, 2, 6, e);      lc.setLed(d + 2, 0, 7, e);      lc.setLed(d + 2, 1, 7, e);
    }else if (num1.equals("25") == 1){
      Serial.println("j");   //한글ㅓ
      lc.setLed(d, 2, 2, e);      lc.setLed(d, 6, 1, e);      lc.setLed(d, 5, 1, e);
      lc.setLed(d, 4, 1, e);      lc.setLed(d, 3, 1, e);      lc.setLed(d, 2, 1, e);
      lc.setLed(d, 1, 1, e);      lc.setLed(d, 0, 1, e);
      lc.setLed(d + 1, 7, 1, e);      lc.setLed(d + 1, 6, 1, e);
      Serial.println("j");   // 점자 중성ㅓ
      lc.setLed(d + 2, 1, 6, e);      lc.setLed(d + 2, 2, 6, e);      lc.setLed(d + 2, 0, 7, e);
    }else if (num1.equals("225") == 1){
      Serial.println("u");   // 한글ㅕ
      lc.setLed(d, 6, 1, e);      lc.setLed(d, 5, 1, e);      lc.setLed(d, 4, 1, e);
      lc.setLed(d, 3, 1, e);      lc.setLed(d, 2, 1, e);      lc.setLed(d, 1, 1, e);
      lc.setLed(d, 0, 1, e);      lc.setLed(d, 3, 2, e);      lc.setLed(d, 1, 2, e);
      lc.setLed(d + 1, 7, 1, e);      lc.setLed(d + 1, 6, 1, e);
      Serial.println("u");   // 점자 중성ㅕ
      lc.setLed(d + 2, 0, 6, e);      lc.setLed(d + 2, 2, 7, e);      lc.setLed(d + 2, 1, 7, e);
    }else if (num1.equals("23") == 1){
      Serial.println("h");   // 한글ㅗ
      lc.setLed(d, 0, 5, e);
      lc.setLed(d + 1, 6, 3, e);      lc.setLed(d + 1, 6, 4, e);      lc.setLed(d + 1, 6, 5, e);
      lc.setLed(d + 1, 6, 6, e);      lc.setLed(d + 1, 6, 7, e);      lc.setLed(d + 1, 7, 5, e);
      Serial.println("h");   // 점자 중성ㅗ
      lc.setLed(d + 2, 0, 6, e);      lc.setLed(d + 2, 2, 6, e);      lc.setLed(d + 2, 2, 7, e);
    }else if (num1.equals("223") == 1){
      Serial.println("y");   // 한글ㅛ
      lc.setLed(d + 1, 6, 3, e);      lc.setLed(d + 1, 6, 4, e);      lc.setLed(d + 1, 6, 5, e);
      lc.setLed(d + 1, 6, 6, e);      lc.setLed(d + 1, 6, 7, e);
      lc.setLed(d, 0, 6, e);      lc.setLed(d, 0, 4, e);
      lc.setLed(d + 1, 6, 6, e);      lc.setLed(d + 1, 6, 7, e);      lc.setLed(d + 1, 7, 6, e);
      lc.setLed(d + 1, 7, 4, e);
      Serial.println("y");   // 점자 중성ㅛ
      lc.setLed(d + 2, 2, 7, e);      lc.setLed(d + 2, 2, 6, e);      lc.setLed(d + 2, 0, 7, e);
    }else if (num1.equals("12") == 1){
      Serial.println("n");   // 한글ㅜ
      lc.setLed(d, 0, 7, e);      lc.setLed(d, 0, 6, e);      lc.setLed(d, 0, 5, e);
      lc.setLed(d, 0, 4, e);      lc.setLed(d, 0, 3, e);
      lc.setLed(d + 1, 7, 5, e);      lc.setLed(d + 1, 6, 5, e);
      Serial.println("n");   // 점자 중성ㅜ
      lc.setLed(d + 2, 0, 6, e);      lc.setLed(d + 2, 0, 7, e);      lc.setLed(d + 2, 2, 6, e);
    }else if (num1.equals("122") == 1){
      Serial.println("b");   // 한글ㅠ
      lc.setLed(d, 0, 7, e);      lc.setLed(d, 0, 6, e);      lc.setLed(d, 0, 5, e);
      lc.setLed(d, 0, 4, e);      lc.setLed(d, 0, 3, e);
      lc.setLed(d + 1, 7, 6, e);      lc.setLed(d + 1, 6, 6, e);      lc.setLed(d + 1, 7, 4, e);
      lc.setLed(d + 1, 6, 4, e);
      Serial.println("b");   // 점자 중성ㅠ
      lc.setLed(d + 2, 0, 6, e);      lc.setLed(d + 2, 0, 7, e);      lc.setLed(d + 2, 2, 7, e);
    }else if (num1.equals("3") == 1){
      Serial.println("m");   // 한글ㅡ
      lc.setLed(d, 0, 7, e);      lc.setLed(d, 0, 6, e);      lc.setLed(d, 0, 5, e);
      lc.setLed(d, 0, 4, e);      lc.setLed(d, 0, 3, e);
      Serial.println("m");   // 점자 중성ㅡ
      lc.setLed(d + 2, 1, 6, e);      lc.setLed(d + 2, 0, 7, e);      lc.setLed(d + 2, 2, 7, e);
    }else if (num1.equals("5") == 1){
      Serial.println("l");   //한글ㅣ
      lc.setLed(d, 6, 2, e);      lc.setLed(d, 5, 2, e);      lc.setLed(d, 4, 2, e);
      lc.setLed(d, 3, 2, e);      lc.setLed(d, 2, 2, e);      lc.setLed(d, 1, 2, e);
      lc.setLed(d, 0, 2, e);
      lc.setLed(d + 1, 6, 2, e);      lc.setLed(d + 1, 7, 2, e);
      Serial.println("l");   // 점자 중성ㅣ
      lc.setLed(d + 2, 0, 6, e);      lc.setLed(d + 2, 1, 7, e);      lc.setLed(d + 2, 2, 6, e);
    }else if (num1.equals("425") == 1){
      Serial.println("o");   // 한글ㅐㅏ+ㅣ
      lc.setLed(d, 6, 2, e);      lc.setLed(d, 5, 2, e);      lc.setLed(d, 4, 2, e);
      lc.setLed(d, 3, 2, e);      lc.setLed(d, 2, 2, e);      lc.setLed(d, 1, 2, e);
      lc.setLed(d, 0, 2, e);      lc.setLed(d, 2, 1, e);      lc.setLed(d, 6, 0, e);
      lc.setLed(d, 5, 0, e);      lc.setLed(d, 4, 0, e);      lc.setLed(d, 3, 0, e);
      lc.setLed(d, 2, 0, e);      lc.setLed(d, 1, 0, e);      lc.setLed(d, 0, 0, e);
      lc.setLed(d + 1, 6, 2, e);      lc.setLed(d + 1, 7, 2, e);      lc.setLed(d + 1, 6, 0, e);
      lc.setLed(d + 1, 7, 0, e);
      Serial.println("o");   // 점자 중성ㅐ
      lc.setLed(d + 2, 0, 6, e);      lc.setLed(d + 2, 1, 7, e);      lc.setLed(d + 2, 1, 6, e);
      lc.setLed(d + 2, 2, 6, e);
    }else if (num1.equals("4225") == 1){
      Serial.println("oo");   // 한글ㅒ ㅑ+ㅣ
      lc.setLed(d, 6, 2, e);      lc.setLed(d, 5, 2, e);      lc.setLed(d, 4, 2, e);
      lc.setLed(d, 3, 2, e);      lc.setLed(d, 2, 2, e);      lc.setLed(d, 1, 2, e);
      lc.setLed(d, 0, 2, e);      lc.setLed(d, 6, 0, e);      lc.setLed(d, 5, 0, e);
      lc.setLed(d, 4, 0, e);      lc.setLed(d, 3, 0, e);      lc.setLed(d, 2, 0, e);
      lc.setLed(d, 1, 0, e);      lc.setLed(d, 0, 0, e);      lc.setLed(d, 3, 1, e);
      lc.setLed(d, 1, 1, e);
      lc.setLed(d + 1, 6, 2, e);      lc.setLed(d + 1, 7, 2, e);      lc.setLed(d + 1, 6, 0, e);
      lc.setLed(d + 1, 7, 0, e);
      Serial.println("oo");   // 점자 중성ㅒ
      lc.setLed(d + 2, 0, 7, e);      lc.setLed(d + 2, 2, 6, e);      lc.setLed(d + 2, 1, 7, e);
      lc.setLed(d + 2, 5, 0, e);      lc.setLed(d + 2, 6, 0, e);      lc.setLed(d + 2, 7, 0, e);
      lc.setLed(d + 2, 6, 1, e);
    }else if (num1.equals("255") == 1){
      Serial.println("p");   // 한글ㅔ
      lc.setLed(d, 2, 2, e);      lc.setLed(d, 6, 1, e);      lc.setLed(d, 5, 1, e);
      lc.setLed(d, 4, 1, e);      lc.setLed(d, 3, 1, e);      lc.setLed(d, 2, 1, e);
      lc.setLed(d, 1, 1, e);      lc.setLed(d, 0, 1, e);
      lc.setLed(d + 1, 7, 1, e);      lc.setLed(d + 1, 6, 1, e);
      lc.setLed(d, 6, 0, e);      lc.setLed(d, 5, 0, e);      lc.setLed(d, 4, 0, e);
      lc.setLed(d, 3, 0, e);      lc.setLed(d, 2, 0, e);      lc.setLed(d, 1, 0, e);
      lc.setLed(d, 0, 0, e);
      lc.setLed(d + 1, 6, 0, e);      lc.setLed(d + 1, 7, 0, e);
      Serial.println("p");   // 점자 중성ㅔ
      lc.setLed(d + 2, 0, 6, e);      lc.setLed(d + 2, 0, 7, e);      lc.setLed(d + 2, 1, 7, e);
      lc.setLed(d + 2, 2, 6, e);
    }
    else if (num1.equals("2255") == 1){
      Serial.println("pp");   // 한글ㅖ
      lc.setLed(d, 6, 1, e);      lc.setLed(d, 5, 1, e);      lc.setLed(d, 4, 1, e);
      lc.setLed(d, 3, 1, e);      lc.setLed(d, 2, 1, e);      lc.setLed(d, 1, 1, e);
      lc.setLed(d, 0, 1, e);      lc.setLed(d, 3, 2, e);      lc.setLed(d, 1, 2, e);
      lc.setLed(d + 1, 7, 1, e);      lc.setLed(d + 1, 6, 1, e);
      lc.setLed(d, 6, 0, e);      lc.setLed(d, 5, 0, e);      lc.setLed(d, 4, 0, e);
      lc.setLed(d, 3, 0, e);      lc.setLed(d, 2, 0, e);      lc.setLed(d, 1, 0, e);
      lc.setLed(d, 0, 0, e);      lc.setLed(d + 1, 6, 0, e);
      lc.setLed(d + 1, 7, 0, e);
      Serial.println("pp");   // 점자 중성ㅖ
      lc.setLed(d + 2, 2, 6, e);      lc.setLed(d + 2, 0, 7, e);
    }else if (num1.equals("235") == 1){
      Serial.println("hl");   // 한글 ㅚ
      lc.setLed(d, 0, 5, e);
      lc.setLed(d + 1, 6, 3, e);      lc.setLed(d + 1, 6, 4, e);      lc.setLed(d + 1, 6, 5, e);
      lc.setLed(d + 1, 6, 6, e);      lc.setLed(d + 1, 6, 7, e);      lc.setLed(d + 1, 7, 5, e);
      lc.setLed(d, 6, 2, e);      lc.setLed(d, 5, 2, e);      lc.setLed(d, 4, 2, e);
      lc.setLed(d, 3, 2, e);      lc.setLed(d, 2, 2, e);      lc.setLed(d, 1, 2, e);
      lc.setLed(d, 0, 2, e);
      lc.setLed(d + 1, 6, 2, e);      lc.setLed(d + 1, 7, 2, e);
      Serial.println("hl");   // 점자 중성ㅚ
      lc.setLed(d + 2, 0, 6, e);      lc.setLed(d + 2, 0, 7, e);      lc.setLed(d + 2, 1, 7, e);
      lc.setLed(d + 2, 2, 6, e);      lc.setLed(d + 2, 2, 7, e);
    }else if (num1.equals("125") == 1){
      Serial.println("nl");   // 한글 ㅟ
      lc.setLed(d, 0, 7, e);      lc.setLed(d, 0, 6, e);      lc.setLed(d, 0, 5, e);
      lc.setLed(d, 0, 4, e);      lc.setLed(d, 0, 3, e);
      lc.setLed(d + 1, 7, 5, e);      lc.setLed(d + 1, 6, 5, e);
      lc.setLed(d, 6, 2, e);      lc.setLed(d, 5, 2, e);      lc.setLed(d, 4, 2, e);
      lc.setLed(d, 3, 2, e);      lc.setLed(d, 2, 2, e);      lc.setLed(d, 1, 2, e);
      lc.setLed(d, 0, 2, e);
      lc.setLed(d + 1, 6, 2, e);      lc.setLed(d + 1, 7, 2, e);
      Serial.println("nl");   // 점자 중성ㅟ
      lc.setLed(d + 2, 0, 6, e);      lc.setLed(d + 2, 0, 7, e);      lc.setLed(d + 2, 2, 6, e);
      lc.setLed(d + 2, 5, 0, e);      lc.setLed(d + 2, 6, 0, e);      lc.setLed(d + 2, 7, 0, e);
      lc.setLed(d + 2, 6, 1, e);
    }else if (num1.equals("35") == 1){
      Serial.println("ml");   // 한글ㅢ
      lc.setLed(d, 0, 7, e);      lc.setLed(d, 0, 6, e);      lc.setLed(d, 0, 5, e);
      lc.setLed(d, 0, 4, e);      lc.setLed(d, 0, 3, e);      lc.setLed(d, 6, 2, e);
      lc.setLed(d, 5, 2, e);      lc.setLed(d, 4, 2, e);      lc.setLed(d, 3, 2, e);
      lc.setLed(d, 2, 2, e);      lc.setLed(d, 1, 2, e);      lc.setLed(d, 0, 2, e);
      lc.setLed(d + 1, 6, 2, e);      lc.setLed(d + 1, 7, 2, e);
      Serial.println("ml");   // 점자 중성ㅢ
      lc.setLed(d + 2, 0, 7, e);      lc.setLed(d + 2, 1, 6, e);      lc.setLed(d + 2, 1, 7, e);
      lc.setLed(d + 2, 2, 7, e);
    }else if (num1.equals("2342") == 1){
      Serial.println("hk");   // 한글ㅘ
      lc.setLed(d, 0, 5, e);
      lc.setLed(d + 1, 6, 3, e);      lc.setLed(d + 1, 6, 4, e);      lc.setLed(d + 1, 6, 5, e);
      lc.setLed(d + 1, 6, 6, e);      lc.setLed(d + 1, 6, 7, e);      lc.setLed(d + 1, 7, 5, e);
      lc.setLed(d, 6, 2, e);      lc.setLed(d, 5, 2, e);      lc.setLed(d, 4, 2, e);
      lc.setLed(d, 3, 2, e);      lc.setLed(d, 2, 2, e);      lc.setLed(d, 1, 2, e);
      lc.setLed(d, 0, 2, e);      lc.setLed(d, 2, 1, e);
      lc.setLed(d + 1, 6, 2, e);      lc.setLed(d + 1, 7, 2, e);
      Serial.println("hk");   // 점자 중성ㅘ
      lc.setLed(d + 2, 0, 6, e);      lc.setLed(d + 2, 1, 6, e);      lc.setLed(d + 2, 2, 7, e);
      lc.setLed(d + 2, 2, 6, e);
    }else if (num1.equals("1225") == 1){
      Serial.println("nj");   // 한글ㅝ
      lc.setLed(d, 0, 7, e);      lc.setLed(d, 0, 6, e);      lc.setLed(d, 0, 5, e);
      lc.setLed(d, 0, 4, e);      lc.setLed(d, 0, 3, e);
      lc.setLed(d + 1, 7, 5, e);      lc.setLed(d + 1, 6, 5, e);
      lc.setLed(d, 6, 1, e);      lc.setLed(d, 5, 1, e);      lc.setLed(d, 4, 1, e);
      lc.setLed(d, 3, 1, e);      lc.setLed(d, 2, 1, e);      lc.setLed(d, 1, 1, e);
      lc.setLed(d, 0, 1, e);
      lc.setLed(d + 1, 7, 1, e);      lc.setLed(d + 1, 6, 1, e);      lc.setLed(d + 1, 5, 1, e);
      lc.setLed(d + 1, 7, 2, e);
      Serial.println("nj");   // 점자 중성ㅝ
      lc.setLed(d + 2, 0, 6, e);      lc.setLed(d + 2, 1, 6, e);      lc.setLed(d + 2, 0, 7, e);
      lc.setLed(d + 2, 2, 6, e);
    }else if (num1.equals("12255") == 1){
      Serial.println("np");   // 한글ㅞ
      lc.setLed(d, 0, 7, e);      lc.setLed(d, 0, 6, e);      lc.setLed(d, 0, 5, e);
      lc.setLed(d, 0, 4, e);      lc.setLed(d, 0, 3, e);
      lc.setLed(d + 1, 7, 5, e);      lc.setLed(d + 1, 6, 5, e);
      lc.setLed(d, 6, 1, e);      lc.setLed(d, 5, 1, e);      lc.setLed(d, 4, 1, e);
      lc.setLed(d, 3, 1, e);      lc.setLed(d, 2, 1, e);      lc.setLed(d, 1, 1, e);
      lc.setLed(d, 0, 1, e);
      lc.setLed(d + 1, 7, 1, e);      lc.setLed(d + 1, 6, 1, e);      lc.setLed(d + 1, 5, 1, e);
      lc.setLed(d + 1, 7, 2, e);      lc.setLed(d, 6, 0, e);
      lc.setLed(d, 5, 0, e);      lc.setLed(d, 4, 0, e);      lc.setLed(d, 3, 0, e);
      lc.setLed(d, 2, 0, e);      lc.setLed(d, 1, 0, e);      lc.setLed(d, 0, 0, e);
      lc.setLed(d + 1, 7, 0, e);      lc.setLed(d + 1, 6, 0, e);      lc.setLed(d + 1, 5, 0, e);
      Serial.println("np");   // 점자 중성ㅞ
      lc.setLed(d + 2, 0, 6, e);      lc.setLed(d + 2, 1, 6, e);      lc.setLed(d + 2, 2, 6, e);
      lc.setLed(d + 2, 0, 7, e);      lc.setLed(d + 2, 5, 0, e);      lc.setLed(d + 2, 6, 0, e);
      lc.setLed(d + 2, 7, 0, e);      lc.setLed(d + 2, 6, 1, e);
    }else if (num1.equals("23425") == 1){
      Serial.println("ho");   // 한글ㅙ
      lc.setLed(d + 1, 6, 3, e);      lc.setLed(d + 1, 6, 4, e);      lc.setLed(d + 1, 6, 5, e);
      lc.setLed(d + 1, 6, 6, e);      lc.setLed(d + 1, 6, 7, e);      lc.setLed(d + 1, 7, 5, e);
      lc.setLed(d + 1, 7, 2, e);      lc.setLed(d + 1, 6, 2, e);
      lc.setLed(d, 0, 5, e);      lc.setLed(d, 6, 2, e);      lc.setLed(d, 5, 2, e);
      lc.setLed(d, 4, 2, e);      lc.setLed(d, 3, 2, e);      lc.setLed(d, 2, 2, e);
      lc.setLed(d, 2, 1, e);      lc.setLed(d, 2, 0, e);      lc.setLed(d, 2, 1, e);
      lc.setLed(d, 6, 0, e);      lc.setLed(d, 5, 0, e);      lc.setLed(d, 4, 0, e);
      lc.setLed(d, 3, 0, e);      lc.setLed(d, 2, 0, e);      lc.setLed(d, 1, 0, e);
      lc.setLed(d, 1, 2, e);      lc.setLed(d, 0, 2, e);      lc.setLed(d, 0, 0, e);
      lc.setLed(d + 1, 6, 0, e);      lc.setLed(d + 1, 7, 0, e);
      Serial.println("ho");   // 점자 중성ㅙ
      lc.setLed(d + 2, 0, 6, e);      lc.setLed(d + 2, 1, 6, e);      lc.setLed(d + 2, 2, 6, e);
      lc.setLed(d + 2, 2, 7, e);      lc.setLed(d + 2, 5, 0, e);      lc.setLed(d + 2, 6, 0, e);
      lc.setLed(d + 2, 7, 0, e);      lc.setLed(d + 2, 6, 1, e);
    }delay(100);
    }
    else if(bal == 1){
       if (num1.equals("51") == 1){
      Serial.println("A");   // 영어A
      lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);                    
      Serial.println("A");   // 점자 A(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("52") == 1){
      Serial.println("B");   // 영어B
     lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("B");   // 점자 B(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("53") == 1){
      Serial.println("C");   // 영어C
      lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("C");   // 점자 C(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("54") == 1){
      Serial.println("D");   // 영어D
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("D");   // 점자 D(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("55") == 1){
      Serial.println("E");   // 영어E
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("E");   // 점자 E(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("511") == 1){
      Serial.println("F");   // 영어F
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
      Serial.println("F");   // 점자 F(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("512") == 1){
      Serial.println("G");   // 영어G
     lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("G");   // 점자 G(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("513") == 1){
      Serial.println("H");   // 영어H
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("H");   // 점자 H(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("514") == 1){
      Serial.println("I");   // 영어I
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 4 + c, true);
lc.setLed(d + k, 5 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 1 + b, 4 + c, true);
lc.setLed(d + k, 1 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("I");   // 점자 I(2)
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("515") == 1){
      Serial.println("J");   // 영어J
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 3 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 3 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
      Serial.println("J");   // 점자 J(2)
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("521") == 1){
      Serial.println("K");   // 영어K
      lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 3 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 3 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);

      Serial.println("K");   // 점자 K(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("522") == 1){
      Serial.println("L");   // 영어L
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("L");   // 점자 L(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("523") == 1){
      Serial.println("M");   // 영어M
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 6 + b, 0 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 4 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 0 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 0 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 0 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 0 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 0 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 0 + c, true);
      Serial.println("M");   // 점자 M(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("524") == 1){
      Serial.println("N");   // 영어N
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 6 + b, 0 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 4 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 0 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 0 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 0 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 0 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 0 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 0 + c, true);
      Serial.println("N");   // 점자 N(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("525") == 1){
      Serial.println("O");   // 영어O
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("O");   // 점자 O(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("531") == 1){
      Serial.println("P");   // 영어P
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
      Serial.println("P");   // 점자 P(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("532") == 1){
      Serial.println("Q");   // 영어Q
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 4 + c, true);
lc.setLed(d + k, 1 + b, 3 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("Q");   // 점자 Q(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("533") == 1){
      Serial.println("R");   // 영어R
 lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 3 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("R");   // 점자 R(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("534") == 1){
      Serial.println("S");   // 영어S
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("S");   // 점자 S(2)
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("535") == 1){
      Serial.println("T");   // 영어T
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 4 + c, true);
lc.setLed(d + k, 5 + b, 3 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 1 + b, 4 + c, true);
lc.setLed(d + k, 1 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
      Serial.println("T");   // 점자 T(2)
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("541") == 1){
      Serial.println("U");   // 영어U
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("U");   // 점자 U(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("542") == 1){
      Serial.println("V");   // 영어V
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 4 + c, true);
lc.setLed(d + k, 1 + b, 3 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
      Serial.println("V");   // 점자 V(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("543") == 1){
      Serial.println("W");   // 영어W
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 6 + b, 0 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 0 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 0 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 0 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 0 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 4 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 0 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 0 + c, true);
      Serial.println("W");   // 점자 W(2)
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("544") == 1){
      Serial.println("X");   // 영어X
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 6 + b, 0 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 0 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 0 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 0 + c, true);
      Serial.println("X");   // 점자 X(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("545") == 1){
      Serial.println("Y");   // 영어Y
lc.setLed(d + k, 6 + b, 6 + c, true);      
lc.setLed(d + k, 6 + b, 5 + c, true);      
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);      
lc.setLed(d + k, 5 + b, 6 + c, true);      
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);      
lc.setLed(d + k, 5 + b, 1 + c, true);      
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);      
lc.setLed(d + k, 4 + b, 2 + c, true);      
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 4 + c, true);      
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 2 + b, 4 + c, true);      
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 1 + b, 4 + c, true);      
lc.setLed(d + k, 1 + b, 3 + c, true);      
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
      Serial.println("Y");   // 점자 Y(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("551") == 1){
      Serial.println("Z");   // 영어Z
lc.setLed(d + k, 6 + b, 6 + c, true);      
lc.setLed(d + k, 6 + b, 5 + c, true);      
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);      
lc.setLed(d + k, 6 + b, 2 + c, true);      
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);      
lc.setLed(d + k, 4 + b, 3 + c, true);      
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);      
lc.setLed(d + k, 3 + b, 3 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 4 + c, true);      
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);      
lc.setLed(d + k, 1 + b, 6 + c, true);      
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);      
lc.setLed(d + k, 0 + b, 5 + c, true);      
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);      
lc.setLed(d + k, 0 + b, 2 + c, true);      
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("Z");   // 점자 Z(2)
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
        else if (num1.equals("41") == 1){
      Serial.println("a");   // 영어a
lc.setLed(d + k, 4 + b, 5 + c, true);      
lc.setLed(d + k, 4 + b, 4 + c, true);      
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);      
lc.setLed(d + k, 2 + b, 4 + c, true);      
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);      
lc.setLed(d + k, 2 + b, 1 + c, true);      
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);      
lc.setLed(d + k, 1 + b, 2 + c, true);      
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);      
lc.setLed(d + k, 0 + b, 4 + c, true);      
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);      
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("a");   // 점자a(2)
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
    }
        else if (num1.equals("42") == 1){
      Serial.println("b");   // 영어b
lc.setLed(d + k, 6 + b, 6 + c, true);      
lc.setLed(d + k, 6 + b, 5 + c, true);      
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);      
lc.setLed(d + k, 4 + b, 6 + c, true);      
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 4 + c, true);      
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 2 + b, 6 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);      
lc.setLed(d + k, 2 + b, 1 + c, true);      
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);      
lc.setLed(d + k, 1 + b, 2 + c, true);      
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);     
lc.setLed(d + k, 0 + b, 5 + c, true);      
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);      
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("b");   // 점자 b)
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
    }
        else if (num1.equals("43") == 1){
      Serial.println("c");   // 영어c
lc.setLed(d + k, 4 + b, 5 + c, true);      
lc.setLed(d + k, 4 + b, 4 + c, true);      
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 6 + c, true);      
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 1 + c, true);      
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);      
lc.setLed(d + k, 1 + b, 6 + c, true);      
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);      
lc.setLed(d + k, 1 + b, 1 + c, true);      
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);      
lc.setLed(d + k, 0 + b, 3 + c, true);      
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("c");   // 점자 c
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
    }
        else if (num1.equals("44") == 1){
      Serial.println("d");   // 영어d
lc.setLed(d + k, 6 + b, 2 + c, true);      
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);      
lc.setLed(d + k, 5 + b, 1 + c, true);      
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);      
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);      
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);      
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);      
lc.setLed(d + k, 1 + b, 6 + c, true);      
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);     
lc.setLed(d + k, 1 + b, 1 + c, true);      
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);      
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);      
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("d");   // 점자 d
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
        else if (num1.equals("45") == 1){
      Serial.println("e");   // 영어e
lc.setLed(d + k, 4 + b, 5 + c, true);      
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);      
lc.setLed(d + k, 4 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);      
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);      
lc.setLed(d + k, 2 + b, 2 + c, true);      
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);      
lc.setLed(d + k, 1 + b, 5 + c, true);      
lc.setLed(d + k, 0 + b, 5 + c, true);   
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);      
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("e");   // 점자 e
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
    }
        else if (num1.equals("411") == 1){
      Serial.println("f");   // 영어f
lc.setLed(d + k, 6 + b, 4 + c, true);      
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);      
lc.setLed(d + k, 5 + b, 5 + c, true);      
lc.setLed(d + k, 5 + b, 4 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);      
lc.setLed(d + k, 5 + b, 1 + c, true);      
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);      
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);      
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);      
lc.setLed(d + k, 2 + b, 2 + c, true);      
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 4 + c, true);     
lc.setLed(d + k, 0 + b, 5 + c, true);      
lc.setLed(d + k, 0 + b, 4 + c, true);
      Serial.println("f");   // 점자 f
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
    }
        else if (num1.equals("412") == 1){
      Serial.println("g");   // 영어g
lc.setLed(d + k, 5 + b, 5 + c, true);      
lc.setLed(d + k, 5 + b, 4 + c, true);
lc.setLed(d + k, 5 + b, 3 + c, true);      
lc.setLed(d + k, 5 + b, 2 + c, true);      
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);      
lc.setLed(d + k, 4 + b, 5 + c, true);      
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);      
lc.setLed(d + k, 3 + b, 6 + c, true);      
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 1 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);      
lc.setLed(d + k, 2 + b, 3 + c, true);      
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);     
lc.setLed(d + k, 1 + b, 2 + c, true);      
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);      
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);      
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("g");   // 점자 g
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
    }
        else if (num1.equals("413") == 1){
      Serial.println("h");   // 영어h
lc.setLed(d + k, 6 + b, 6 + c, true);      
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);      
lc.setLed(d + k, 5 + b, 5 + c, true);      
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 6 + c, true);      
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);      
lc.setLed(d + k, 3 + b, 3 + c, true);      
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);      
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);      
lc.setLed(d + k, 1 + b, 6 + c, true);      
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);     
lc.setLed(d + k, 1 + b, 1 + c, true);      
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);      
lc.setLed(d + k, 0 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("h");   // 점자 h
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
    }
        else if (num1.equals("414") == 1){
      Serial.println("i");   // 영어i
lc.setLed(d + k, 5 + b, 4 + c, true);      
lc.setLed(d + k, 5 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);      
lc.setLed(d + k, 3 + b, 3 + c, true);      
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);      
lc.setLed(d + k, 1 + b, 4 + c, true);      
lc.setLed(d + k, 1 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);      
lc.setLed(d + k, 0 + b, 4 + c, true);      
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true); 
      Serial.println("i");   // 점자 i
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
    }
        else if (num1.equals("415") == 1){
      Serial.println("j");   // 영어j
lc.setLed(d + k, 6 + b, 3 + c, true);      
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);      
lc.setLed(d + k, 4 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 2 + b, 6 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);      
lc.setLed(d + k, 2 + b, 2 + c, true);      
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);      
lc.setLed(d + k, 1 + b, 3 + c, true);      
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);      
lc.setLed(d + k, 0 + b, 4 + c, true);      
lc.setLed(d + k, 0 + b, 3 + c, true);
      Serial.println("j");   // 점자 j
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
    }
        else if (num1.equals("421") == 1){
      Serial.println("k");   // 영어k
lc.setLed(d + k, 6 + b, 6 + c, true);      
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);      
lc.setLed(d + k, 5 + b, 5 + c, true);      
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);      
lc.setLed(d + k, 4 + b, 2 + c, true);      
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);      
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 2 + b, 6 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);      
lc.setLed(d + k, 2 + b, 3 + c, true);      
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);     
lc.setLed(d + k, 1 + b, 3 + c, true);      
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);      
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);      
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("k");   // 점자 k
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
    }
        else if (num1.equals("422") == 1){
      Serial.println("l");   // 영어l
lc.setLed(d + k, 6 + b, 4 + c, true);      
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 5 + b, 4 + c, true);      
lc.setLed(d + k, 5 + b, 3 + c, true);      
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);      
lc.setLed(d + k, 3 + b, 4 + c, true);      
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);      
lc.setLed(d + k, 2 + b, 3 + c, true);      
lc.setLed(d + k, 1 + b, 4 + c, true);
lc.setLed(d + k, 1 + b, 3 + c, true);      
lc.setLed(d + k, 0 + b, 4 + c, true);      
lc.setLed(d + k, 0 + b, 3 + c, true);
      Serial.println("l");   // 점자 l
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
    }
        else if (num1.equals("423") == 1){
      Serial.println("m");   // 영어m
lc.setLed(d + k, 4 + b, 6 + c, true);      
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);      
lc.setLed(d + k, 4 + b, 0 + c, true);      
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 4 + c, true);      
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);      
lc.setLed(d + k, 3 + b, 0 + c, true);      
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);      
lc.setLed(d + k, 2 + b, 4 + c, true);      
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);      
lc.setLed(d + k, 2 + b, 1 + c, true);      
lc.setLed(d + k, 2 + b, 0 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);     
lc.setLed(d + k, 1 + b, 5 + c, true);      
lc.setLed(d + k, 1 + b, 3 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);      
lc.setLed(d + k, 1 + b, 0 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);      
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);      
lc.setLed(d + k, 0 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 0 + c, true);     
      Serial.println("m");   // 점자 m
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
    }
        else if (num1.equals("424") == 1){
      Serial.println("n");   // 영어n
lc.setLed(d + k, 4 + b, 6 + c, true);      
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);      
lc.setLed(d + k, 4 + b, 3 + c, true);      
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);      
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);      
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);      
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);      
lc.setLed(d + k, 1 + b, 6 + c, true);      
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);     
lc.setLed(d + k, 1 + b, 1 + c, true);      
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);      
lc.setLed(d + k, 0 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("n");   // 점자 n
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
    }
        else if (num1.equals("425") == 1){
      Serial.println("o");   // 영어o
lc.setLed(d + k, 4 + b, 5 + c, true);      
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);      
lc.setLed(d + k, 4 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);      
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);      
lc.setLed(d + k, 1 + b, 6 + c, true);      
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);      
lc.setLed(d + k, 1 + b, 1 + c, true);      
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);     
lc.setLed(d + k, 0 + b, 3 + c, true);      
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("o");   // 점자 o
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
    }
        else if (num1.equals("431") == 1){
      Serial.println("p");   // 영어p
lc.setLed(d + k, 5 + b, 6 + c, true);      
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 4 + c, true);      
lc.setLed(d + k, 5 + b, 3 + c, true);      
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);      
lc.setLed(d + k, 4 + b, 5 + c, true);      
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);      
lc.setLed(d + k, 3 + b, 6 + c, true);      
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 1 + c, true);      
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);      
lc.setLed(d + k, 2 + b, 4 + c, true);      
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);     
lc.setLed(d + k, 1 + b, 6 + c, true);      
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);      
lc.setLed(d + k, 0 + b, 5 + c, true);
      Serial.println("p");   // 점자 p
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
    }
        else if (num1.equals("432") == 1){
      Serial.println("q");   // 영어q
lc.setLed(d + k, 5 + b, 5 + c, true);      
lc.setLed(d + k, 5 + b, 4 + c, true);
lc.setLed(d + k, 5 + b, 3 + c, true);      
lc.setLed(d + k, 5 + b, 2 + c, true);      
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);      
lc.setLed(d + k, 4 + b, 5 + c, true);      
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);      
lc.setLed(d + k, 3 + b, 6 + c, true);      
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 1 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);      
lc.setLed(d + k, 2 + b, 3 + c, true);      
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);     
lc.setLed(d + k, 1 + b, 2 + c, true);      
lc.setLed(d + k, 1 + b, 1 + c, true);   
lc.setLed(d + k, 0 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("q");   // 점자 q
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
    }
        else if (num1.equals("433") == 1){
      Serial.println("r");   // 영어r
lc.setLed(d + k, 4 + b, 6 + c, true);      
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);      
lc.setLed(d + k, 4 + b, 3 + c, true);      
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);      
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);      
lc.setLed(d + k, 2 + b, 6 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);      
lc.setLed(d + k, 2 + b, 1 + c, true);      
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);     
lc.setLed(d + k, 0 + b, 6 + c, true);      
lc.setLed(d + k, 0 + b, 5 + c, true);   
      Serial.println("r");   // 점자 r
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
    }
        else if (num1.equals("434") == 1){
      Serial.println("s");   // 영어s
lc.setLed(d + k, 4 + b, 5 + c, true);      
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);      
lc.setLed(d + k, 4 + b, 2 + c, true);      
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);      
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);      
lc.setLed(d + k, 2 + b, 2 + c, true);      
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);      
lc.setLed(d + k, 0 + b, 5 + c, true);      
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);     
lc.setLed(d + k, 0 + b, 2 + c, true);      
      Serial.println("s");   // 점자 s
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
    }
        else if (num1.equals("435") == 1){
      Serial.println("t");   // 영어t
lc.setLed(d + k, 5 + b, 4 + c, true);      
lc.setLed(d + k, 5 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);      
lc.setLed(d + k, 4 + b, 3 + c, true);      
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 4 + c, true);      
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 1 + c, true);      
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);      
lc.setLed(d + k, 1 + b, 4 + c, true);      
lc.setLed(d + k, 1 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);   
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("t");   // 점자 t
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
    }
        else if (num1.equals("441") == 1){
      Serial.println("u");   // 영어u
lc.setLed(d + k, 4 + b, 6 + c, true);      
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);      
lc.setLed(d + k, 4 + b, 1 + c, true);      
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);      
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);      
lc.setLed(d + k, 1 + b, 5 + c, true);      
lc.setLed(d + k, 1 + b, 4 + c, true);
lc.setLed(d + k, 1 + b, 3 + c, true);     
lc.setLed(d + k, 1 + b, 2 + c, true);      
lc.setLed(d + k, 1 + b, 1 + c, true);   
      Serial.println("u");   // 점자 u
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
    }
        else if (num1.equals("442") == 1){
      Serial.println("v");   // 영어v
lc.setLed(d + k, 4 + b, 6 + c, true);      
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);      
lc.setLed(d + k, 4 + b, 1 + c, true);      
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);      
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);      
lc.setLed(d + k, 1 + b, 5 + c, true);      
lc.setLed(d + k, 1 + b, 4 + c, true);
lc.setLed(d + k, 1 + b, 3 + c, true);     
lc.setLed(d + k, 1 + b, 2 + c, true);      
lc.setLed(d + k, 0 + b, 4 + c, true);   
lc.setLed(d + k, 0 + b, 3 + c, true);   
      Serial.println("v");   // 점자 v
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
        else if (num1.equals("443") == 1){
      Serial.println("w");   // 영어w
lc.setLed(d + k, 4 + b, 6 + c, true);      
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);      
lc.setLed(d + k, 4 + b, 0 + c, true);      
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 3 + c, true);      
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 0 + c, true);      
lc.setLed(d + k, 2 + b, 6 + c, true);      
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);      
lc.setLed(d + k, 2 + b, 1 + c, true);      
lc.setLed(d + k, 2 + b, 0 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);     
lc.setLed(d + k, 1 + b, 5 + c, true);      
lc.setLed(d + k, 1 + b, 3 + c, true);   
lc.setLed(d + k, 1 + b, 1 + c, true);   
lc.setLed(d + k, 1 + b, 0 + c, true);      
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);     
lc.setLed(d + k, 0 + b, 3 + c, true);      
lc.setLed(d + k, 0 + b, 2 + c, true);   
lc.setLed(d + k, 0 + b, 1 + c, true);  
      Serial.println("w");   // 점자 w
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
        else if (num1.equals("444") == 1){
      Serial.println("x");   // 영어x
lc.setLed(d + k, 4 + b, 6 + c, true);      
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);      
lc.setLed(d + k, 4 + b, 1 + c, true);      
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);      
lc.setLed(d + k, 3 + b, 3 + c, true);      
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);      
lc.setLed(d + k, 2 + b, 3 + c, true);      
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 4 + c, true);      
lc.setLed(d + k, 1 + b, 3 + c, true);      
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);     
lc.setLed(d + k, 0 + b, 5 + c, true);      
lc.setLed(d + k, 0 + b, 2 + c, true);   
lc.setLed(d + k, 0 + b, 1 + c, true);   
      Serial.println("x");   // 점자 x
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
        else if (num1.equals("445") == 1){
      Serial.println("y");   // 영어y
lc.setLed(d + k, 4 + b, 6 + c, true);      
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);      
lc.setLed(d + k, 4 + b, 1 + c, true);      
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);      
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);      
lc.setLed(d + k, 2 + b, 4 + c, true);      
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);      
lc.setLed(d + k, 2 + b, 1 + c, true);      
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);     
lc.setLed(d + k, 0 + b, 5 + c, true);      
lc.setLed(d + k, 0 + b, 4 + c, true);   
lc.setLed(d + k, 0 + b, 3 + c, true);   
lc.setLed(d + k, 0 + b, 2 + c, true);      
      Serial.println("y");   // 점자 y
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
        else if (num1.equals("451") == 1){
      Serial.println("z");   // 영어z
lc.setLed(d + k, 4 + b, 5 + c, true);      
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);      
lc.setLed(d + k, 4 + b, 2 + c, true);      
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);      
lc.setLed(d + k, 2 + b, 4 + c, true);      
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);      
lc.setLed(d + k, 1 + b, 4 + c, true);      
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);      
lc.setLed(d + k, 0 + b, 3 + c, true);      
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("z");   // 점자 z
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    delay(100);
    }
   else  {
       if (num1.equals("1") == 1){
      Serial.println("1");   // 1
      lc.setLed(d + k, 6 + b, 4 + c, true);      lc.setLed(d + k, 6 + b, 3 + c, true);      lc.setLed(d + k, 5 + b, 4 + c, true);
      lc.setLed(d + k, 5 + b, 3 + c, true);      lc.setLed(d + k, 4 + b, 4 + c, true);      lc.setLed(d + k, 4 + b, 3 + c, true);
      lc.setLed(d + k, 3 + b, 4 + c, true);      lc.setLed(d + k, 3 + b, 3 + c, true);      lc.setLed(d + k, 2 + b, 4 + c, true);
      lc.setLed(d + k, 2 + b, 3 + c, true);      lc.setLed(d + k, 1 + b, 4 + c, true);      lc.setLed(d + k, 1 + b, 3 + c, true);
      lc.setLed(d + k, 0 + b, 4 + c, true);      lc.setLed(d + k, 0 + b, 3 + c, true);      lc.setLed(d + k, 0 + b, 6 + c, true);
      lc.setLed(d + k, 0 + b, 5 + c, true);      lc.setLed(d + k, 0 + b, 2 + c, true);      lc.setLed(d + k, 0 + b, 1 + c, true);
      lc.setLed(d + k, 4 + b, 5 + c, true);                    
      Serial.println("1");   // 점자 1
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("2") == 1){
      Serial.println("2");   // 2
 lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 6 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("2");   // 점자 2
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("3") == 1){
      Serial.println("3");   // 3
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("3");   // 점자 3
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("4") == 1){
      Serial.println("4");   // 4
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 4 + c, true);
lc.setLed(d + k, 5 + b, 3 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 3 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("4");   // 점자 4
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("5") == 1){
      Serial.println("5");   // 5
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("5");   // 점자 5
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("51") == 1){
      Serial.println("6");   // 6
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("6");   // 점자 6
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("52") == 1){
      Serial.println("7");   // 7
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 1 + b, 4 + c, true);
lc.setLed(d + k, 1 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
      Serial.println("7");   // 점자 7
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
        else if (num1.equals("53") == 1){
      Serial.println("8");   // 8
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("8");   // 점자 8
lc.setLed(d + 2, 0 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
        else if (num1.equals("54") == 1){
      Serial.println("9");   // 9
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("9");   // 점자 9
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
        else if (num1.equals("55") == 1){
      Serial.println("0");   // 0
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 4 + b, 6 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
      Serial.println("0");   // 점자 0
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
else if (num1.equals("125") == 1){
      Serial.println("+");   // +
lc.setLed(d + k, 1 + b, 3 + c, true);         
lc.setLed(d + k, 2 + b, 3 + c, true);    
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 5 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
      Serial.println("+");   // 점자 +
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
else if (num1.equals("124") == 1){
      Serial.println("-");   // -
lc.setLed(d + k, 3 + b, 5 + c, true);                
lc.setLed(d + k, 3 + b, 4 + c, true);                
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
      Serial.println("-");   // 점자 -
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
    }
    else if (num1.equals("325") == 1){
      Serial.println("*");   // *
lc.setLed(d + k, 1 + b, 1 + c, true);                 
lc.setLed(d + k, 1 + b, 2 + c, true);                 
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 1 + b, 4 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 6 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 3 + b, 1 + c, true);
lc.setLed(d + k, 3 + b, 0 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 4 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
      Serial.println("*");   // 점자 *
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("555") == 1){
      Serial.println("/");   // /
lc.setLed(d + k, 1 + b, 6 + c, true);                 
lc.setLed(d + k, 1 + b, 5 + c, true);                  
lc.setLed(d + k, 2 + b, 5 + c, true);                
lc.setLed(d + k, 2 + b, 4 + c, true);                 
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
      Serial.println("/");   // 점자 /
lc.setLed(d + k, 0 + b, 1 + c, true);                 
lc.setLed(d + k, 1 + b, 1 + c, true);                  
lc.setLed(d + k, 2 + b, 1 + c, true);                
lc.setLed(d + k, 0 + b, 4 + c, true);                 
lc.setLed(d + k, 2 + b, 3 + c, true);
    }
    else if (num1.equals("324") == 1){
      Serial.println("%");   // %
lc.setLed(d + k, 6 + b, 6 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
      Serial.println("%");   // 점자 %
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 0 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
    }
    else if (num1.equals("425") == 1){
      Serial.println("=");   // =
lc.setLed(d + k, 4 + b, 5 + c, true);                   
lc.setLed(d + k, 4 + b, 4 + c, true);                 
lc.setLed(d + k, 4 + b, 3 + c, true);                  
lc.setLed(d + k, 4 + b, 2 + c, true);                  
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
      Serial.println("=");   // 점자 =
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
    }
    else if (num1.equals("143") == 1){
      Serial.println("<");   // <
lc.setLed(d + k, 0 + b, 2 + c, true);                
lc.setLed(d + k, 0 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 5 + b, 3 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 1 + c, true);
      Serial.println("<");   // 점자 <
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 4 + p + v, e);
    }
    else if (num1.equals("153") == 1){
      Serial.println(">");   // >
lc.setLed(d + k, 0 + b, 6 + c, true);               
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 4 + c, true);
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 5 + b, 4 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 6 + c, true);
      Serial.println(">");   // 점자 >
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
    }
    else if (num1.equals("12") == 1){
      Serial.println("!");   // !
lc.setLed(d + k, 0 + b, 4 + c, true);             
lc.setLed(d + k, 0 + b, 3 + c, true);              
lc.setLed(d + k, 2 + b, 4 + c, true);                
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 4 + c, true);
lc.setLed(d + k, 5 + b, 3 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
      Serial.println("!");   // 점자 !
lc.setLed(d + 2, 1 + s, 3 + p + v, e);
lc.setLed(d + 2, 1 + s, 4 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 3 + p + v, e);
    }
    else if (num1.equals("123") == 1){
      Serial.println("?");   // ?
lc.setLed(d + k, 0 + b, 4 + c, true);               
lc.setLed(d + k, 0 + b, 3 + c, true);                
lc.setLed(d + k, 2 + b, 4 + c, true);                 
lc.setLed(d + k, 2 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 4 + c, true);
lc.setLed(d + k, 3 + b, 3 + c, true);
lc.setLed(d + k, 3 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 4 + b, 1 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
      Serial.println("?");   // 점자 ?
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("33") == 1){
      Serial.println(".");   // .
lc.setLed(d + k, 0 + b, 6 + c, true);              
lc.setLed(d + k, 0 + b, 5 + c, true);               
lc.setLed(d + k, 1 + b, 6 + c, true);              
lc.setLed(d + k, 1 + b, 5 + c, true);

      Serial.println(".");   // 점자 .
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 1 + s, 1 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    else if (num1.equals("525") == 1){
      Serial.println("&");   // &
lc.setLed(d + k, 0 + b, 0 + c, true);
lc.setLed(d + k, 0 + b, 1 + c, true);
lc.setLed(d + k, 0 + b, 2 + c, true);
lc.setLed(d + k, 0 + b, 3 + c, true);
lc.setLed(d + k, 0 + b, 4 + c, true);
lc.setLed(d + k, 0 + b, 5 + c, true);
lc.setLed(d + k, 1 + b, 1 + c, true);
lc.setLed(d + k, 1 + b, 2 + c, true);
lc.setLed(d + k, 2 + b, 0 + c, true);
lc.setLed(d + k, 2 + b, 2 + c, true);
lc.setLed(d + k, 1 + b, 6 + c, true);
lc.setLed(d + k, 1 + b, 5 + c, true);
lc.setLed(d + k, 2 + b, 6 + c, true);
lc.setLed(d + k, 2 + b, 5 + c, true);
lc.setLed(d + k, 3 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 5 + c, true);
lc.setLed(d + k, 4 + b, 4 + c, true);
lc.setLed(d + k, 4 + b, 3 + c, true);
lc.setLed(d + k, 4 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 6 + c, true);
lc.setLed(d + k, 5 + b, 5 + c, true);
lc.setLed(d + k, 5 + b, 2 + c, true);
lc.setLed(d + k, 5 + b, 1 + c, true);
lc.setLed(d + k, 6 + b, 5 + c, true);
lc.setLed(d + k, 6 + b, 4 + c, true);
lc.setLed(d + k, 6 + b, 3 + c, true);
lc.setLed(d + k, 6 + b, 2 + c, true);

      Serial.println("&");   // 점자 and
lc.setLed(d + 2, 0 + s, 0 + p + v, e);
lc.setLed(d + 2, 0 + s, 1 + p + v, e);
lc.setLed(d + 2, 1 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 0 + p + v, e);
lc.setLed(d + 2, 2 + s, 1 + p + v, e);
    }
    }
    delay(100);
    num1 = "";
} 
  state = 0;
}

boolean g(boolean e) {
  //초성 한글부분
  lc.setLed(d, 6, 7, e);  lc.setLed(d, 5, 7, e);  lc.setLed(d, 4, 7, e);
  lc.setLed(d, 3, 7, e);  lc.setLed(d, 2, 7, e);  lc.setLed(d, 6, 6, e);
  lc.setLed(d, 5, 6, e);  lc.setLed(d, 4, 6, e);  lc.setLed(d, 3, 6, e);
  lc.setLed(d, 2, 6, e);  lc.setLed(d, 6, 5, e);  lc.setLed(d, 5, 5, e);
  lc.setLed(d, 4, 5, e);  lc.setLed(d, 3, 5, e);  lc.setLed(d, 2, 5, e);
  lc.setLed(d, 6, 4, e);  lc.setLed(d, 5, 4, e);  lc.setLed(d, 4, 4, e);
  lc.setLed(d, 3, 4, e);  lc.setLed(d, 2, 4, e);  lc.setLed(d, 6, 3, e);
  lc.setLed(d, 5, 3, e);  lc.setLed(d, 4, 3, e);  lc.setLed(d, 3, 3, e);
  lc.setLed(d, 2, 3, e);
  //초성 점자부분
  lc.setLed(d + 2, 0, 0, e);  lc.setLed(d + 2, 0, 1, e);  lc.setLed(d + 2, 1, 0, e);
  lc.setLed(d + 2, 1, 1, e);  lc.setLed(d + 2, 2, 0, e);  lc.setLed(d + 2, 2, 1, e);
  lc.setLed(d + 2, 0, 3, e);  lc.setLed(d + 2, 0, 4, e);  lc.setLed(d + 2, 1, 3, e);
  lc.setLed(d + 2, 1, 4, e);  lc.setLed(d + 2, 2, 3, e);  lc.setLed(d + 2, 2, 4, e);
}
boolean h(boolean e) {
  //중성 한글부분
  lc.setLed(d, 0, 7, e);  lc.setLed(d, 0, 6, e);  lc.setLed(d, 0, 5, e);
  lc.setLed(d, 0, 4, e);  lc.setLed(d, 0, 3, e);  lc.setLed(d, 0, 2, e);
  lc.setLed(d, 0, 1, e);  lc.setLed(d, 0, 0, e);  lc.setLed(d, 1, 2, e);
  lc.setLed(d, 1, 1, e);  lc.setLed(d, 1, 0, e);  lc.setLed(d, 2, 2, e);
  lc.setLed(d, 2, 1, e);  lc.setLed(d, 2, 0, e);  lc.setLed(d, 3, 2, e);
  lc.setLed(d, 3, 1, e);  lc.setLed(d, 3, 0, e);  lc.setLed(d, 4, 2, e);
  lc.setLed(d, 4, 1, e);  lc.setLed(d, 4, 0, e);  lc.setLed(d, 5, 2, e);
  lc.setLed(d, 5, 1, e);  lc.setLed(d, 5, 0, e);  lc.setLed(d, 6, 2, e);
  lc.setLed(d, 6, 1, e);  lc.setLed(d, 6, 0, e);
  lc.setLed(d + 1, 7, 7, e);  lc.setLed(d + 1, 6, 7, e);  lc.setLed(d + 1, 7, 6, e);
  lc.setLed(d + 1, 6, 6, e);  lc.setLed(d + 1, 7, 5, e);  lc.setLed(d + 1, 6, 5, e);
  lc.setLed(d + 1, 7, 4, e);  lc.setLed(d + 1, 6, 4, e);  lc.setLed(d + 1, 7, 3, e);
  lc.setLed(d + 1, 6, 3, e);  lc.setLed(d + 1, 7, 2, e);  lc.setLed(d + 1, 6, 2, e);
  lc.setLed(d + 1, 7, 1, e);  lc.setLed(d + 1, 6, 1, e);  lc.setLed(d + 1, 7, 0, e);
  lc.setLed(d + 1, 6, 0, e);  lc.setLed(d + 1, 5, 2, e);  lc.setLed(d + 1, 5, 1, e);
  lc.setLed(d + 1, 5, 0, e);
  //중성 점자부분
  lc.setLed(d + 2, 0, 6, e);  lc.setLed(d + 2, 0, 7, e);  lc.setLed(d + 2, 1, 6, e);
  lc.setLed(d + 2, 1, 7, e);  lc.setLed(d + 2, 2, 6, e);  lc.setLed(d + 2, 2, 7, e);
  lc.setLed(d + 2, 5, 0, e);  lc.setLed(d + 2, 5, 1, e);  lc.setLed(d + 2, 6, 0, e);
  lc.setLed(d + 2, 6, 1, e);  lc.setLed(d + 2, 7, 0, e);  lc.setLed(d + 2, 7, 1, e);
}
boolean i(boolean e) {
  // 종성1 한글부분
  lc.setLed(d + 1, 4, 7, e);  lc.setLed(d + 1, 4, 6, e);  lc.setLed(d + 1, 4, 5, e);
  lc.setLed(d + 1, 4, 4, e);  lc.setLed(d + 1, 3, 7, e);  lc.setLed(d + 1, 3, 6, e);
  lc.setLed(d + 1, 3, 5, e);  lc.setLed(d + 1, 3, 4, e);  lc.setLed(d + 1, 2, 7, e);
  lc.setLed(d + 1, 2, 6, e);  lc.setLed(d + 1, 2, 5, e);  lc.setLed(d + 1, 2, 4, e);
  lc.setLed(d + 1, 1, 7, e);  lc.setLed(d + 1, 1, 6, e);  lc.setLed(d + 1, 1, 5, e);
  lc.setLed(d + 1, 1, 4, e);  lc.setLed(d + 1, 0, 7, e);  lc.setLed(d + 1, 0, 6, e);
  lc.setLed(d + 1, 0, 5, e);  lc.setLed(d + 1, 0, 4, e);
  //종성1 점자부분
  lc.setLed(d + 2, 5, 3, e);  lc.setLed(d + 2, 5, 4, e);  lc.setLed(d + 2, 6, 3, e);
  lc.setLed(d + 2, 6, 4, e);  lc.setLed(d + 2, 7, 3, e);  lc.setLed(d + 2, 7, 4, e);
}
boolean j(boolean e) {
  //종성2 한글부분
  lc.setLed(d + 1, 4, 3, e);  lc.setLed(d + 1, 4, 2, e);  lc.setLed(d + 1, 4, 1, e);
  lc.setLed(d + 1, 4, 0, e);  lc.setLed(d + 1, 3, 3, e);  lc.setLed(d + 1, 3, 2, e);
  lc.setLed(d + 1, 3, 1, e);  lc.setLed(d + 1, 3, 0, e);  lc.setLed(d + 1, 2, 3, e);
  lc.setLed(d + 1, 2, 2, e);  lc.setLed(d + 1, 2, 1, e);  lc.setLed(d + 1, 2, 0, e);
  lc.setLed(d + 1, 1, 3, e);  lc.setLed(d + 1, 1, 2, e);  lc.setLed(d + 1, 1, 1, e);
  lc.setLed(d + 1, 1, 0, e);  lc.setLed(d + 1, 0, 3, e);  lc.setLed(d + 1, 0, 2, e);
  lc.setLed(d + 1, 0, 1, e);  lc.setLed(d + 1, 0, 0, e);
  //종성2 점자부분
  lc.setLed(d + 2, 5, 6, e);  lc.setLed(d + 2, 5, 7, e);  lc.setLed(d + 2, 6, 6, e);
  lc.setLed(d + 2, 6, 7, e);  lc.setLed(d + 2, 7, 6, e);  lc.setLed(d + 2, 7, 7, e);
}
boolean n(boolean m) {
  //종성 점자부분 지우기용
  lc.setLed(5, 5, 6, m);  lc.setLed(5, 5, 7, m);  lc.setLed(5, 6, 6, m);
  lc.setLed(5, 6, 7, m);  lc.setLed(5, 7, 6, m);  lc.setLed(5, 7, 7, m);
  lc.setLed(5, 5, 3, m);  lc.setLed(5, 5, 4, m);  lc.setLed(5, 6, 3, m);
  lc.setLed(5, 6, 4, m);  lc.setLed(5, 7, 3, m);  lc.setLed(5, 7, 4, m);
}
boolean w(boolean e) {
  //첫글자 영어부분
  lc.setLed(d, 7, 7, e);  lc.setLed(d, 7, 6, e);  lc.setLed(d, 7, 5, e); lc.setLed(d, 7, 4, e); lc.setLed(d, 7, 3, e); lc.setLed(d, 7, 2, e); lc.setLed(d, 7, 1, e); lc.setLed(d, 7, 0, e);
  lc.setLed(d, 6, 7, e);  lc.setLed(d, 6, 6, e);  lc.setLed(d, 6, 5, e); lc.setLed(d, 6, 4, e); lc.setLed(d, 6, 3, e); lc.setLed(d, 6, 2, e); lc.setLed(d, 6, 1, e); lc.setLed(d, 6, 0, e);
  lc.setLed(d, 5, 7, e);  lc.setLed(d, 5, 6, e);  lc.setLed(d, 5, 5, e); lc.setLed(d, 5, 4, e); lc.setLed(d, 5, 3, e); lc.setLed(d, 5, 2, e); lc.setLed(d, 5, 1, e); lc.setLed(d, 5, 0, e);
  lc.setLed(d, 4, 7, e);  lc.setLed(d, 4, 6, e);  lc.setLed(d, 4, 5, e); lc.setLed(d, 4, 4, e); lc.setLed(d, 4, 3, e); lc.setLed(d, 4, 2, e); lc.setLed(d, 4, 1, e); lc.setLed(d, 4, 0, e);
  lc.setLed(d, 3, 7, e);  lc.setLed(d, 3, 6, e);  lc.setLed(d, 3, 5, e); lc.setLed(d, 3, 4, e); lc.setLed(d, 3, 3, e); lc.setLed(d, 3, 2, e); lc.setLed(d, 3, 1, e); lc.setLed(d, 3, 0, e);
  lc.setLed(d, 2, 7, e);  lc.setLed(d, 2, 6, e);  lc.setLed(d, 2, 5, e); lc.setLed(d, 2, 4, e); lc.setLed(d, 2, 3, e); lc.setLed(d, 2, 2, e); lc.setLed(d, 2, 1, e); lc.setLed(d, 2, 0, e);
  lc.setLed(d, 1, 7, e);  lc.setLed(d, 1, 6, e);  lc.setLed(d, 1, 5, e); lc.setLed(d, 1, 4, e); lc.setLed(d, 1, 3, e); lc.setLed(d, 1, 2, e); lc.setLed(d, 1, 1, e); lc.setLed(d, 1, 0, e);
  lc.setLed(d, 0, 7, e);  lc.setLed(d, 0, 6, e);  lc.setLed(d, 0, 5, e); lc.setLed(d, 0, 4, e); lc.setLed(d, 0, 3, e); lc.setLed(d, 0, 2, e); lc.setLed(d, 0, 1, e); lc.setLed(d, 0, 0, e);
  //첫글자 점자부분
  lc.setLed(d + 2, 0, 0, e);  lc.setLed(d + 2, 0, 1, e);  lc.setLed(d + 2, 1, 0, e);
  lc.setLed(d + 2, 1, 1, e);  lc.setLed(d + 2, 2, 0, e);  lc.setLed(d + 2, 2, 1, e);
  lc.setLed(d + 2, 0, 3, e);  lc.setLed(d + 2, 0, 4, e);  lc.setLed(d + 2, 1, 3, e);
  lc.setLed(d + 2, 1, 4, e);  lc.setLed(d + 2, 2, 3, e);  lc.setLed(d + 2, 2, 4, e);
  lc.setLed(d + 2, 0, 6, e);  lc.setLed(d + 2, 0, 7, e);  lc.setLed(d + 2, 1, 6, e);
  lc.setLed(d + 2, 1, 7, e);  lc.setLed(d + 2, 2, 6, e);  lc.setLed(d + 2, 2, 7, e);
}
