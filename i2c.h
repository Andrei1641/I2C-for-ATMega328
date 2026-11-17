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

uint8_t read(uint8_t *returnInfo, uint32_t countOfReturnBytes, uint8_t moduleAddress, uint32_t requestReg);
uint8_t write(uint8_t *sendInfo, uint32_t countOfSendBytes, uint8_t moduleAddress, uint32_t requestReg);

#endif
