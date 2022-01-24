#! /bin/bash

PWD=$(pwd)
echo $PWD
path="$PWD/driver/src"

cd $path/beep/
make
make install


cd $path/fan/
make
make install

cd $path/led
make
make install

cd $path/m74hc595
make
make install

cd /home/ubuntu/hqyj/smart_home/smartHome/driver/src/motor/
cd $path/motor
make
make install

cd /home/ubuntu/hqyj/smart_home/smartHome/driver/src/si7006/
cd $path/si7006
make
make install
