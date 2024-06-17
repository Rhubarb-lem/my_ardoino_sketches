void light_off() {
  PORTC &= ~(1 << 0);  //G
  PORTC &= ~(1 << 1);  //F
  PORTC &= ~(1 << 2);  //A
  PORTC &= ~(1 << 3);  //B
  PORTC &= ~(1 << 4);  //E
  PORTC &= ~(1 << 5);  //D
  PORTD &= ~(1 << 2);  //C
}
void char0() {
  PORTC &= ~(1 << 0);  //G
  PORTC |= (1 << 1);   //F
  PORTC |= (1 << 2);   //A
  PORTC |= (1 << 3);   //B
  PORTC |= (1 << 4);   //E
  PORTC |= (1 << 5);   //D
  PORTD |= (1 << 2);   //C
}

void char1() {
  PORTC &= ~(1 << 0);  //G
  PORTC &= ~(1 << 1);  //F
  PORTC &= ~(1 << 2);  //A
  PORTC |= (1 << 3);   //B
  PORTC &= ~(1 << 4);  //E
  PORTC &= ~(1 << 5);  //D
  PORTD |= (1 << 2);   //C
}

void char2() {
  PORTC |= (1 << 0);   //G
  PORTC &= ~(1 << 1);  //F
  PORTC |= (1 << 2);   //A
  PORTC |= (1 << 3);   //B
  PORTC |= (1 << 4);   //E
  PORTC |= (1 << 5);   //D
  PORTD &= ~(1 << 2);  //C
}
void char3() {
  PORTC |= (1 << 0);   //G
  PORTC &= ~(1 << 1);  //F
  PORTC |= (1 << 2);   //A
  PORTC |= (1 << 3);   //B
  PORTC &= ~(1 << 4);  //E
  PORTC |= (1 << 5);   //D
  PORTD |= (1 << 2);   //C
}

void char4() {
  PORTC |= (1 << 0);   //G
  PORTC |= (1 << 1);   //F
  PORTC &= ~(1 << 2);  //A
  PORTC |= (1 << 3);   //B
  PORTC &= ~(1 << 4);  //E
  PORTC &= ~(1 << 5);  //D
  PORTD |= (1 << 2);   //C
}
void char5() {
  PORTC |= (1 << 0);   //G
  PORTC |= (1 << 1);   //F
  PORTC |= (1 << 2);   //A
  PORTC &= ~(1 << 3);  //B
  PORTC &= ~(1 << 4);  //E
  PORTC |= (1 << 5);   //D
  PORTD |= (1 << 2);   //C
}
void char6() {
  PORTC |= (1 << 0);   //G
  PORTC |= (1 << 1);   //F
  PORTC |= (1 << 2);   //A
  PORTC &= ~(1 << 3);  //B
  PORTC |= (1 << 4);   //E
  PORTC |= (1 << 5);   //D
  PORTD |= (1 << 2);   //C
}
void char7() {
  PORTC &= ~(1 << 0);  //G
  PORTC &= ~(1 << 1);  //F
  PORTC |= (1 << 2);   //A
  PORTC |= (1 << 3);   //B
  PORTC &= ~(1 << 4);  //E
  PORTC &= ~(1 << 5);  //D
  PORTD |= (1 << 2);   //C
}
void char8() {
  PORTC |= (1 << 0);  //G
  PORTC |= (1 << 1);  //F
  PORTC |= (1 << 2);  //A
  PORTC |= (1 << 3);  //B
  PORTC |= (1 << 4);  //E
  PORTC |= (1 << 5);  //D
  PORTD |= (1 << 2);  //C
}
void char9() {
  PORTC |= (1 << 0);   //G
  PORTC |= (1 << 1);   //F
  PORTC |= (1 << 2);   //A
  PORTC |= (1 << 3);   //B
  PORTC &= ~(1 << 4);  //E
  PORTC |= (1 << 5);   //D
  PORTD |= (1 << 2);   //C
}
void digtolig(int dig) {
  switch (dig) {
    case 0:
      char0();
      break;
    case 1:
      char1();
      break;
    case 2:
      char2();
      break;
    case 3:
      char3();
      break;
    case 4:
      char4();
      break;
    case 5:
      char5();
      break;
    case 6:
      char6();
      break;
    case 7:
      char7();
      break;
    case 8:
      char8();
      break;
    case 9:
      char9();
      break;
    default:
      light_off();
      break;
  }
}

double convtime(double sec) {
  return (sec / (6.25 * 1024 * 0.00000001));
}

void mydelay(double sec) {
  //Serial.begin(9600);
  TCCR1B = 0;
  TCCR1A = 0;
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);
  double div = convtime(sec);

  TCNT1 = 65536 - convtime(sec);

  while (1) {
    if ((TIFR1 & 1 << 1)) {
      TIFR1 |= 1 << 1;
      break;
    }
  }
}

void mysound(double freq, double dur) {
  DDRD |= (1 << 4);
  double timeHigh = (1 / (2 * freq));
  for (int i = 0; i < dur; i++) {
    PORTD &= ~(1 << 4);
    mydelay(timeHigh);
    PORTD |= (1 << 4);
    mydelay(timeHigh);
  }
}
void ligtime(int sec) {
  int cur = sec;
  while (cur >= 0) {
    mydelay(1);
    digtolig(cur);
    cur--;
  }
  mysound(440, 100);
  light_off();
}


int main() {
  DDRB &= ~(1 << 4);
  DDRB &= ~(1 << 3);
  DDRB &= ~(1 << 2);
  DDRB &= ~(1 << 1);
  DDRB |= (1 << 0);
  DDRD |= (1 << 7);
  DDRD |= (1 << 6);
  DDRD |= (1 << 5);
  PORTB |= (1 << 4);
  PORTB |= (1 << 3);
  PORTB |= (1 << 2);
  PORTB |= (1 << 1);
  DDRC |= (1 << 0);  //B
  DDRC |= (1 << 1);  //A
  DDRC |= (1 << 2);  //F
  DDRC |= (1 << 3);  //G
  DDRC |= (1 << 4);  //C
  DDRC |= (1 << 5);  //D
  DDRD |= (1 << 2);  //E
  while (1) {

    int num = 11;
    PORTB &= ~(1 << 0);
    mydelay(0.00001);
    if ((!(PINB & (1 << 4)))) num = 1;
    if ((!(PINB & (1 << 3)))) num = 4;
    if ((!(PINB & (1 << 2)))) num = 7;
    if ((!(PINB & (1 << 1)))) num = 11;  //
    PORTB |= (1 << 0);
    //_delay_ms(50);
    PORTD &= ~(1 << 7);
    mydelay(0.00001);
    if ((!(PINB & (1 << 4)))) num = 2;
    if ((!(PINB & (1 << 3)))) num = 5;
    if ((!(PINB & (1 << 2)))) num = 8;
    if ((!(PINB & (1 << 1)))) num = 0;
    PORTD |= (1 << 7);
    //_delay_ms(50);
    PORTD &= ~(1 << 6);
    mydelay(0.00001);
    if ((!(PINB & (1 << 4)))) num = 3;
    if ((!(PINB & (1 << 3)))) num = 6;
    if ((!(PINB & (1 << 2)))) num = 9;
    if ((!(PINB & (1 << 1)))) num = 10;  //
    PORTD |= (1 << 6);
    //_delay_ms(50);
    PORTD &= ~(1 << 5);
    mydelay(0.00001);
    if ((!(PINB & (1 << 4)))) num = 10;
    if ((!(PINB & (1 << 3)))) num = 10;
    if ((!(PINB & (1 << 2)))) num = 10;
    if ((!(PINB & (1 << 1)))) num = 10;
    PORTD |= (1 << 5);
    if (num <= 9) {
      ligtime(num);
    }
    
  }
}