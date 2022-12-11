# Arduino Coin Sorting (NodeMCU V3 ESP8266)

## Clone repo
```sh
git clone https://github.com/noonomyen/arduino-coin-sorting
cd ./arduino-coin-sorting
git submodule update --init --recursive
```

## Setup arduino-cli
```
mkdir arduino && cd ./arduino
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | BINDIR=$(pwd)/arduino sh -s 0.29.0
```

## Install ESP8266 Arduino Core
```sh
./arduino/arduino-cli --verbose --config-file arduino-cli.yaml core update-index
./arduino/arduino-cli --verbose --config-file arduino-cli.yaml core install esp8266:esp8266@3.0.2
```

## Compile
```sh
./arduino/arduino-cli --verbose --config-file arduino-cli.yaml compile --fqbn esp8266:esp8266:nodemcuv2
```

## Upload
```sh
./arduino/arduino-cli --verbose --config-file arduino-cli.yaml upload --fqbn esp8266:esp8266:nodemcuv2 --port <PORT>
```
