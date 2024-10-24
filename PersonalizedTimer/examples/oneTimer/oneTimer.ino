#include <PersonalizedTimer.h>

PersonalizedTimer timer = PersonalizedTimer();
int n;

void setup() {
  Serial.begin(9600);
  timer.set(1000);
  timer.start();
}

void loop() {
  
  if(timer.isTriggered()){
    Serial.println("Timer Triggered");
    n++;
  }

  if(n == 10) {
    timer.stop();
    Serial.println("Timer Stopped");
    n++;
  }

}
