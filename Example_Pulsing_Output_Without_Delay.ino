uint8_t outputPin = PIN_LED1;
uint8_t inputPin = PIN_BTN1;
uint32_t timeKeeperVar = 0; //need a different variable for each output you want to control
void setup() {
  pinMode(outputPin,OUTPUT);
  pinMode(inputPin,INPUT);
}
//This function takes 3 inputs, the pin you want to control, int interval you want between changes in microseconds, 
//and a variable to store the time in between calls (this is a pointer)
void outputTimingFunction(uint8_t inpin, uint32_t interval, uint32_t *timeStore)
{
  uint32_t currentTime = micros();
  if((currentTime-(*timeStore))>interval) //if current time subtract the last time is more than the interval
  {
    *timeStore = currentTime; //store the time for the next call
    digitalWrite(inpin,!digitalRead(inpin)); //read the current state of the pin and write it inverted
  }
}
void loop() {
  if(!digitalRead(inputPin)) //if the input pin is pressed
  {
    //call the timer function if the interval has elapsed it will toggle the output
    outputTimingFunction(outputPin,100000,&timeKeeperVar); //need the & because the variable is modified within the function
  }
}
