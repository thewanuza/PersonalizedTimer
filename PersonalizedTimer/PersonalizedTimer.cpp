/*
PersonalizedTimer.cpp - libreria per un semplice timer
*/

#include "PersonalizedTimer.h"

/* costruttore dell'oggetto*/
PersonalizedTimer::PersonalizedTimer(){
  attivo = false;
}

/* setta il tempo in cui far scattare il timer */
void PersonalizedTimer::set(int trigger){
  delay = trigger;
}

/* Avvia il timer */
void PersonalizedTimer::start(){
  attivo = true;
  t1 = millis();
}

/* verifica se il timer è scattato, in caso ritorna true */
bool PersonalizedTimer::isTriggered(){
  if(attivo){
    dt = millis() - t1;
    if(dt >= delay) {
      t1 = millis();
      return true;
    }
  } return false;
}

void PersonalizedTimer::stop(){
  attivo = false;
}

