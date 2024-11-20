# Blink

A very basic blink program specifically for the [SparkFun Thing Plus - ESP32-C6](https://www.sparkfun.com/products/22924) using Espressif IDF.

__WARNING: The LED on the board is outrageously bright__

## Setup

Initialize the IDF from where you installed

```bash
. /opt/esp-idf/export.sh 
```

## Install

There's an IDF component called `led_strip` that must be installed

```bash
idf.py reconfigure
```

## Build & Flash

Plug in your device and change the port to whichever yours is.

```bash
idf.py build
idf.py -p /dev/ttyACM0 flash
```
