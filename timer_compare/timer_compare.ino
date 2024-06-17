int main(){
  Serial.begin(9600);

  TCCR1B = 0;
  TCCR1B |= (1 << WGM12);
  TCCR1A = 0;
  TCCR1B |= (1 << CS10);
  TCCR1B |= (1 << CS12);
  OCR1A = 46801;
  while(1){
    
    if((TIFR1 & 1<<1)){
        Serial.println("Time over!");

        TIFR1 |= 1<<1;
    }
      
    }
}
 
