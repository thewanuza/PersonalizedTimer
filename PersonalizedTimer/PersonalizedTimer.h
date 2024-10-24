#ifndef PersonalizedTimer_h
#define PersonalizedTimer_h

#include "Arduino.h"

class PersonalizedTimer {
  private:
    unsigned long t1, dt;
    bool attivo;
    int delay;

  public:
    PersonalizedTimer();
    void set(int trigger);
    void start();
    bool isTriggered();
    void stop();
};

#endif