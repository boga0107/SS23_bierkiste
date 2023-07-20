#include <HardwareSerial.h>
#include <Arduino.h>

class Uart {

private:
    const uint8_t uart_rx_pin;
    const uint8_t uart_tx_pin;
    const uint64_t baudrate;
    const uint64_t serialMode;
    byte direction;
    uint16_t speed;
    uint16_t distance_1;
    uint16_t distance_2;
    uint16_t distance_3;
    uint16_t steering;
    byte power;
    char* msgUartSend;
    char* msgUartReceive;

public:
    Uart(uint8_t rx_pin, uint8_t tx_pin, uint64_t sBaudrate, uint64_t sSerialMode);

    void setDirection(byte value);
    byte getDirection();
    void setSpeed(uint16_t value);
    uint16_t getSpeed();
    void setDistance(uint16_t value, int number);
    uint16_t getDistance(int number);
    void setSteering(uint16_t value);
    uint16_t getSteering();
    void setPower(byte value);
    byte getPower();
    
    void buildMessage(byte direction, uint16_t speed, uint16_t distance1, uint16_t distance2, uint16_t distance3, uint16_t steering, byte power);
    void getMessage();
};