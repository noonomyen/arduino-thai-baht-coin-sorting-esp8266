# Arduino Coin Sorting (NodeMCU V3 ESP8266)

## Clone repo
```sh
git clone https://github.com/noonomyen/arduino-coin-sorting
cd ./arduino-coin-sorting
git submodule update --init --recursive
```

## Copy library from submodule
```sh
cp ./LiquidCrystal_I2C/LiquidCrystal_I2C.h .
cp ./LiquidCrystal_I2C/LiquidCrystal_I2C.cpp .
```

## Setup arduino-cli
```
mkdir arduino && cd ./arduino
wget https://github.com/arduino/arduino-cli/releases/download/0.31.0/arduino-cli_0.31.0_Linux_64bit.tar.gz -O arduino-cli_0.31.0_Linux_64bit.tar.gz
tar -xf arduino-cli_0.31.0_Linux_64bit.tar.gz
cd ..
```

## Install ESP8266 Arduino Core
```sh
./arduino/arduino-cli --verbose --config-file arduino-cli.yaml core update-index
./arduino/arduino-cli --verbose --config-file arduino-cli.yaml core install esp8266:esp8266@3.1.2
```

## Compile
```sh
./arduino/arduino-cli --verbose --config-file arduino-cli.yaml compile --fqbn esp8266:esp8266:nodemcuv2
```

## Upload
```sh
./arduino/arduino-cli --verbose --config-file arduino-cli.yaml upload --fqbn esp8266:esp8266:nodemcuv2 --port <PORT>
```
