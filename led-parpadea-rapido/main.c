#define F_CPU 16000000UL  // 16 MHz (Arduino Uno)
#include <avr/io.h>       
#include <util/delay.h>   

int main(void) {
    DDRB |= (1 << PB5);    // Configura Pin 13 (PB5) como salida

    while (1) {           
        PORTB |= (1 << PB5);   // Enciende el LED
        _delay_ms(900);        // <--- CAMBIO: Solo 100 milisegundos encendido (destello rápido)

        PORTB &= ~(1 << PB5);  // Apaga el LED
        _delay_ms(100);        // <--- CAMBIO: 900 milisegundos apagado
    }

    return 0; 
}
