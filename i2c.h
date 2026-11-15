#if !defined I2C_H
#define I2C_H

uint8_t start(void);
uint8_t repeatedStart(void);
uint8_t readBytes(uint8_t data[], uint8_t byteCount);
uint8_t writeBytes(uint8_t data[], uint8_t byteCount);
uint8_t setAddressWrite(uint8_t address);
uint8_t requestRegister(uint8_t reg);
uint8_t setAddressRead(uint8_t address);
void stop(void);

#endif
