# LED parpadeante

Ejemplo mínimo en C puro para hacer parpadear el LED integrado de un Arduino Uno mediante acceso directo a los registros del ATmega328P.

## Funcionamiento

- Microcontrolador: `ATmega328P`.
- Frecuencia del reloj: `16 MHz`.
- LED utilizado: LED integrado del Arduino Uno.
- Pin utilizado: `PB5`, equivalente al pin digital `13`.
- Tiempo encendido: `1000 ms`.
- Tiempo apagado: `1000 ms`.

El programa configura `PB5` como salida, activa y desactiva el bit correspondiente en `PORTB`, y utiliza `_delay_ms()` para controlar los tiempos.
