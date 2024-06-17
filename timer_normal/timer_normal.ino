int main(){
    Serial.begin(9600);
    double sec = 3
    TCCR1B = 0;
    TCCR1A = 0;
    TCCR1B |= (1 << CS10);
    TCCR1B |= (1 << CS12);
    double sub = sec / (6.25 * 1024 * 0.00000001);

    TCNT1 = 65536 - sub;

    while (1)
    {
        if ((TIFR1 & 1 << 1))
        { 
            Serial.println("time over");
            TIFR1 |= 1 << 1;
            TCNT1 = 65536 - sub;
            
        }
    }
}
