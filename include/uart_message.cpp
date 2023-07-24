#include "uart_message.h"

Uart::Uart(uint8_t rx_pin, uint8_t tx_pin, uint64_t sBaudrate, uint64_t sSerialMode):
    uart_rx_pin(rx_pin), uart_tx_pin(tx_pin), baudrate(sBaudrate), serialMode(sSerialMode){
    
}

void Uart::setDirection(byte value){
    direction = value;
}

byte Uart::getDirection(){
    return direction;
}

void Uart::setSpeed(uint16_t value){
    speed = value;
}

uint16_t Uart::getSpeed(){
    return speed;
}

void Uart::setSteering(uint16_t value){
    steering = value;
}

uint16_t Uart::getSteering(){
    return steering;
}

void Uart::setPower(byte value){
    power = value;
}

byte Uart::getPower(){
    return power;
}

void Uart::setDistance(uint16_t value, int number){
    switch (number) {
        case 0:
            distance_1 = value;
            break;
        case 1:
            distance_2 = value;
            break;
        case 2:
            distance_3 = value;
            break;
        default:
        //do nothing!!
    }
}

uint16_t Uart::getDistance(int number){
    switch (number) {
        case 0:
            return distance_1;
        case 1:
            return distance_2;
        case 2: 
            return distance_3;
        default:
            //do nothing and break
            break;
    }
}

void Uart::buildMessage(byte direction, uint16_t speed, uint16_t distance1, uint16_t distance2, 
                        uint16_t distance3, uint16_t steering, byte power){
    //initialize UART Message
    HardwareSerial SerialPort(2); //Use UART2
    SerialPort.begin(baudrate, serialMode, uart_rx_pin, uart_tx_pin);

    //Send out every byte by itself
    SerialPort.write(direction);
    SerialPort.write(speed);
    SerialPort.write(distance1);
    SerialPort.write(distance2);
    SerialPort.write(distance3);
    SerialPort.write(steering);
    SerialPort.write(power);

    //alternative: build one message out of char buffer:
    char msg[]={};
 
    msg[0] = direction;
    msg[1] = speed;
    msg[2] = distance1;
    msg[3] = distance2;
    msg[4] = distance3;
    msg[5] = steering;
    msg[6] = power;
    
    for(int i = 0; i<7; i++){
        msgUartSend += msg[i];
    }
    //to be tested!!
}

void Uart::getMessage(){
    HardwareSerial SerialPort(2);
    SerialPort.begin(baudrate, serialMode, uart_rx_pin, uart_tx_pin);

    while(SerialPort.available() != 0){
        for(int i = 0; i < SerialPort.available(); i++){    
            msgUartReceive += SerialPort.read();
        }
    }
    //oder: 
    char terminator = ',';
    while(SerialPort.available() != 0){
       // setDirection(SerialPort.readBytesUntil(terminator, 1, 16));
        //etc...
    }
}