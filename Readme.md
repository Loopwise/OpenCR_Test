# Uso de OpenCR en Ubuntu
## Instalación
Se seguirán los pasos necesarios en la documentación, con la excepción de que se empleará Arduino 2.0 para el uso de esta placa.  

## Configuración del Puerto USB
Ejecutamos las siguientes líneas de código:
```
wget https://raw.githubusercontent.com/ROBOTIS-GIT/OpenCR/master/99-opencr-cdc.rules
sudo cp ./99-opencr-cdc.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules
sudo udevadm trigger
```
Y finalmente una pequeña línea para el compilador:
```
sudo apt-get install libncurses5-dev:i386
```

## Instalando Arduino IDE 2.0
Descargamos el archivo de Arduino IDE _.AppImage_ y ejecutamos los siguientes comandos:

```
cd Downloads/
chmod a+x <Paquete>.AppImage
./<Paquete>.AppImage
```

Y ya tendremos a Arduino 2.0 ejecutándose.

Añadimos la siguiente dirección al gestor de tarjetas:
```
https://raw.githubusercontent.com/ROBOTIS-GIT/OpenCR/master/arduino/opencr_release/package_opencr_index.json
```
Y nos dirigimos a instalar la placa OpenCR en el gestor de tarjetas.

## Probando el código
Abrimos el código _Hello_World_ que nos servirá para probar que todo esté correctamente instalado, en caso de haber hecho todo bien, el programa debería subirse con normalidad, en caso de que no detecte la placa mantén presionado el SW2 y posteriormente el botón RESET, con la placa conectada al ordenador, eso me sirvió a mí (Para más información consultar la [_documentación_](https://emanual.robotis.com/docs/en/parts/controller/opencr10/)).

## Notas sobre *rosserial_arduino*
Para el uso de *rosserial_arduino* y que no cree incompatibilidades al momento de usar esta librería (Cuando tenemos una instalación de *rosserial* y de la placa OpenCR, creamos una doble instancia de la librería *ros.h*) se recomienda emplear dos instalaciones del Arduino IDE en Ubuntu.
Personalmente, uso Arduino 2.0 para el uso de OpenCR y Arduino 1.8.19 instalado por *snap* para el uso de las *Arduino AVR Boards* y con *rosserial* instalado.
