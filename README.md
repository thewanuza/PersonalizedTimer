# PersonalizedTimer

Libreria Arduino per creare timer non bloccanti basati sulla funzione `millis()`. Qui trovi una panoramica pensata per un nuovo arrivato: struttura del progetto, componenti principali e risorse da esplorare in seguito.

## Struttura generale della libreria

```
PersonalizedTimer/
├── PersonalizedTimer.cpp   # Implementazione della classe timer
├── PersonalizedTimer.h     # Interfaccia pubblica della libreria
├── examples/
│   └── oneTimer/
│       └── oneTimer.ino     # Sketch di esempio che mostra l'uso del timer
├── keywords.txt            # Evidenziazione sintattica per l'IDE Arduino
└── library.properties      # Metadati della libreria per l'IDE Arduino
```

* **`PersonalizedTimer.h` / `PersonalizedTimer.cpp`** – definiscono una classe semplice che gestisce lo stato del timer (`start`, `stop`, `set`) e verifica il superamento dell'intervallo configurato con `isTriggered()`.
* **`examples/oneTimer/oneTimer.ino`** – sketch da caricare su una scheda Arduino per vedere la libreria in azione: stampa un messaggio ogni secondo per 10 iterazioni e poi arresta il timer.
* **`keywords.txt`** – migliora la leggibilità del codice nell'IDE Arduino evidenziando classi e metodi della libreria.
* **`library.properties`** – file richiesto dall'IDE Arduino per identificare la libreria (nome, versione, autore, ecc.).

## Utilizzo rapido

Per creare e usare un timer:

```cpp
#include <PersonalizedTimer.h>

PersonalizedTimer timer;

void setup() {
  timer.set(1000);   // intervallo in millisecondi
  timer.start();     // avvio del timer
}

void loop() {
  if (timer.isTriggered()) {
    // azione da ripetere ogni secondo
  }
}

// Per fermare manualmente il timer:
// timer.stop();
```

### Note importanti

* Il timer è non bloccante: puoi usarlo nel loop principale senza impedire l'esecuzione di altro codice.
* `isTriggered()` ritorna `true` solo quando è trascorso il tempo impostato e riavvia internamente il conteggio.
* Ricorda di invocare `start()` dopo `set()` perché il timer di default è disattivato.

## Cosa approfondire dopo

1. **Eventi multipli** – estendere la classe per gestire più timer contemporaneamente o usare più istanze della libreria.
2. **Durata dei timer** – attualmente l'intervallo è memorizzato come `int`; valuta se passare a `unsigned long` per intervalli superiori a ~32 secondi.
3. **Test automatici** – aggiungere test unitari (ad esempio con `ArduinoUnit` o framework simili) per garantire il comportamento in scenari edge-case.
4. **Gestione overflow di `millis()`** – considerare logica di rollover per cicli lunghi.

Approfondendo questi punti potrai evolvere la libreria e adattarla a progetti più complessi.

