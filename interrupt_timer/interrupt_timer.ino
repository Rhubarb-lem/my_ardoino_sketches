int main(){
  Serial.begin(9600);
  TCCR1B = 0;
  
  TCCR1A = 0;
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);
  TCNT1 = 18565;
  SREG |= (1<<7);//Глобальные прерывания
  TIMSK1 |= (1<<TOV1);//Прерывания от таймера
  while(1){ 
    
  }
}
 ISR(TIMER1_OVF_vect){
    Serial.println("Time over!");
    TCNT1 = 18565;
    //TIFR1 |= 1;
}