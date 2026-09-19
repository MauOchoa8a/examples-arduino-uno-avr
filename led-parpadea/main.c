#define F_CPU 16000000UL  // Definimos la velocidad del reloj: 16 MHz (Arduino Uno)
#include <avr/io.h>       // Biblioteca estándar para manejo de Entradas/Salidas
#include <util/delay.h>   // Biblioteca para usar funciones de retardo (_delay_ms)

int main(void) {
    // 1. Configurar el Pin 5 del Puerto B como Salida
    // En Arduino, el pin 13 físico corresponde al bit PB5 del ATmega328P
    DDRB |= (1 << PB5);    // Equivale a: pinMode(13, OUTPUT)

    while (1) {           // Bucle infinito, equivale al void loop() de Arduino
        // 2. Encender el LED
        PORTB |= (1 << PB5);   // Pone en ALTO el pin PB5: digitalWrite(13, HIGH)
        _delay_ms(1000);       // Espera 1000 milisegundos

        // 3. Apagar el LED
        PORTB &= ~(1 << PB5);  // Pone en BAJO el pin PB5: digitalWrite(13, LOW)
        _delay_ms(1000);       // Espera 1000 milisegundos
    }

    return 0; // Nunca se alcanza por el bucle while(1)
}
