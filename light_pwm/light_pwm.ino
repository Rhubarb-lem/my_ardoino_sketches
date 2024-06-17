int main(){
  //Serial.begin(9600);
  double sec = 0.1;
  DDRB |= (1 << 1);
  TCCR1A = 0;
   //TCCR1A |= (1<<WGM10);
  TCCR1A |= (1<<WGM11);
  //TCCR1A |= (1<<COM1A0);
  TCCR1A |= (1<<COM1A1);
  TCCR1B = 0; 
  TCCR1B |= (1<<WGM12);
  TCCR1B |= (1<<WGM13);
  TCCR1B |= (1 << CS10);
    //TCCR1B |= (1 << CS12);
  //TCCR1B |= (1<<WGM13);
  int Fpwm = 500;
  double top = (Fpwm/(16*1024)) - 1;
  // OCR1A = 65536 - (sec / (6.25 * 1024 * 0.00000001));
  OCR1A = 10;
  OCR1B = 10;
  ICR1 = 1000;

  while(1){
    OCR1A++;
    //OCR1B++;
    //ICR1--;
    //delay(1);
    //Serial.println(sizeof(ICR1));
    if(OCR1A == 1100){
       OCR1A = 10;
    }
    _delay_ms(10);
   // mydelay(1);
   
  }
}
