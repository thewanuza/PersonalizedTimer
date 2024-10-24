# PersonalizedTimer
 Semplice Timer non bloccante Arduino

Per creare un timer invocare il costruttore 

timer = PersonalizedTimer();

Per impostare il tempo (in ms)

timer.set(1000);

Il timer sarà spento, è necessario avviarlo per usarlo

timer.start();

Per verificare se è scattato 

timer.isTriggered();

tale metodo ritorna un boolean

Puoi disabilitare il timer

timer.stop();

