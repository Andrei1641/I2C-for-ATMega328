#include <avr/io.h>
#include <stdlib.h>
#include "i2c.h"

uint8_t start(void)
{
    //START
    TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
    if ((TWSR & 0xF8) != 0x08) //0x08 is start
    {
        return 1;
    }
    return 0;
}

uint8_t setAddressWrite(uint8_t address)
{
    address = address << 1;
    //SLA_W
    TWDR = address;
    TWCR = (1<<TWINT)|(1<<TWEN);	
    while (!(TWCR & (1<<TWINT)));
    if ((TWSR & 0xF8) != 0x18)
    {
        return 1;
    }
    return 0;
}

uint8_t requestRegister(uint8_t reg)
{

    //request address to read
    TWDR = reg;
    TWCR = (1<<TWINT) | (1<<TWEN); 
    while (!(TWCR & (1<<TWINT)));
    if ((TWSR & 0xF8)!= 0x28)
    {
        return 1;
    }
    return 0;
}

uint8_t repeatedStart(void)
{
    //Rs
    TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
    if ((TWSR & 0xF8)!= 0x10)
    {
        return 1;
    }
    return 0;
}

uint8_t setAddressWrite(uint8_t address)
{
    address = address << 1;
    address++;
    //SLA+R
    TWDR = address;
    TWCR = (1<<TWINT)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
    if ((TWSR & 0xF8)!= 0x40)
    {
        return 1;
    }
    return 0;
}

uint8_t readBytes(uint8_t data[] , uint8_t byteCount)
{
    for (uint8_t i = 0; i < byteCount; i++)
    {
        TWCR = (1<<TWINT)|(1<<TWEN);
        while (!(TWCR & (1<<TWINT)));
        if ((TWSR & 0xF8)!= 0x50)
        {
            return 1;
        }
        data[i] = TWDR;
    } 
    //last byte
    TWCR = (1<<TWINT)|(1<<TWEN);
    while (!(TWCR & (1<<TWINT)));
    if ((TWSR & 0xF8)!= 0x58)
    {
        return 1;
    }
    data[byteCount] = TWDR;
    return 0;
}


uint8_t writeBytes(uint8_t data[], uint8_t byteCount)
{
    for(uint8_t i = 0; i < byteCount; i++)
    {
        TWCR = (1<<TWINT)|(1<<TWEN)
            while(!(TWCR & (1<<TWINT)));
        if ((TWST & 0F8)!= 0x28)
        {
            return 1;
        }
    }

    TWCR = (1<<TWINT)|(1<<TWEN)
        while(!(TWCR & (1<<TWINT)));
    if ((TWST & 0F8)!= 0x58)
    {
        return 1;
    }
    return 0;
}
//STOP
void stop(void)
{
    TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}
