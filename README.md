# Ejemplos de codigo C para Arduino Uno con AVR

Este repositorio contiene ejemplos escritos en C puro para la placa Arduino Uno, basada en el microcontrolador **ATmega328P**. El directorio `led-parpadea` contiene el archivo de entrada `main.c` para el ejemplo de parpadeo del LED.

## Requisitos previos

Instala el compilador AVR y la herramienta para cargar programas mediante Homebrew:

```bash
brew install avrdude osx-avr avr-gcc
```

En equipos Mac con Apple Silicon (M1, M2, M3 o posteriores), si aparece el error `bad CPU type`, instala Rosetta 2:

```bash
softwareupdate --install-rosetta --agree-to-license
```

Comprueba que las herramientas estén disponibles:

```bash
avr-gcc --version
avr-objcopy --version
avrdude --version
```

## Compilar y cargar el ejemplo

Desde el directorio del ejemplo:

```bash
cd led-parpadea
```

### 1. Compilar `main.c`

Genera el archivo objeto y después el ejecutable en formato ELF:

```bash
avr-gcc -g -Os -mmcu=atmega328p -DF_CPU=16000000UL -c main.c -o main.o
avr-gcc -g -mmcu=atmega328p main.o -o main.elf
```

Opciones principales:

- `-Os`: optimiza el tamaño del programa para la memoria del microcontrolador.
- `-mmcu=atmega328p`: selecciona el microcontrolador del Arduino Uno.
- `-DF_CPU=16000000UL`: define la frecuencia del reloj en 16 MHz.

### 2. Generar el archivo Intel HEX

El bootloader del Arduino no carga directamente el archivo ELF. Convierte las secciones necesarias a formato Intel HEX:

```bash
avr-objcopy -j .text -j .data -O ihex main.elf main.hex
```

### 3. Identificar el puerto USB

Conecta la placa y lista los puertos serie disponibles:

```bash
ls /dev/cu.*
```

Usa el puerto que corresponda a tu placa. En el ejemplo se utiliza `/dev/cu.usbserial-1240`; debes sustituirlo si tu sistema muestra otro nombre.

### 4. Cargar el programa con `avrdude`

Para una instalación de Homebrew en Apple Silicon:

```bash
avrdude -c arduino -p m328p -P /dev/cu.usbserial-1240 -b 115200 -U flash:w:main.hex:i
```

Parámetros importantes:

- `-c arduino`: selecciona el protocolo del bootloader de Arduino.
- `-p m328p`: selecciona el ATmega328P.
- `-P`: indica el puerto serie de la placa.
- `-b 115200`: establece la velocidad de comunicación.
- `-U flash:w:main.hex:i`: escribe `main.hex` en la memoria flash como Intel HEX.
