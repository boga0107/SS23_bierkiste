#include "uart_message.h"

UartMessage::UartMessage(uint8_t rx_pin, uint8_t tx_pin, uint64_t sBaudrate, uint64_t sSerialMode):
    uart_rx_pin(rx_pin), uart_tx_pin(tx_pin), baudrate(sBaudrate), serialMode(sSerialMode){
    
}

void UartMessage::setDirection(byte value){
    direction = value;
}

byte UartMessage::getDirection(){
    return direction;
}

void UartMessage::setSpeed(uint16_t value){
    speed = value;
}

uint16_t UartMessage::getSpeed(){
    return speed;
}

void UartMessage::setSteering(uint16_t value){
    steering = value;
}

uint16_t UartMessage::getSteering(){
    return steering;
}

// void UartMessage::setPower(byte value){
//     power = value;
// }

// byte UartMessage::getPower(){
//     return power;
// }

void UartMessage::setDistance(uint16_t value, int number){
    switch (number) {
        case 0:
            distance_1 = value;
        case 1:
            distance_2 = value;
        case 2:
            distance_3 = value;
        default:
        //do nothing!!
    }
}

uint16_t UartMessage::getDistance(int number){
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

void UartMessage::buildMessage(byte direction, uint16_t speed, uint16_t distance1, uint16_t distance2, 
                        uint16_t distance3){
    //initialize UART Message
    HardwareSerial SerialPort(2); //Use UART2
    SerialPort.begin(baudrate, serialMode, uart_rx_pin, uart_tx_pin);

    //Send out every byte by itself
    SerialPort.write(direction);
    SerialPort.write(speed);
    SerialPort.write(distance1);
    SerialPort.write(distance2);
    SerialPort.write(distance3);

}

void UartMessage::getMessage(){
    HardwareSerial SerialPort(2);
    SerialPort.begin(baudrate, serialMode, uart_rx_pin, uart_tx_pin);

    while(SerialPort.available() != 0){
        for(int i = 0; i < SerialPort.available(); i++){    
            msgUartReceive[i] += SerialPort.read();
        }
    }
    //oder: 
    // char terminator = ',';
    // while(SerialPort.available() != 0){
    //     // setDirection(SerialPort.readBytesUntil(terminator, 1, 16));
    //     //etc...
    // }
}