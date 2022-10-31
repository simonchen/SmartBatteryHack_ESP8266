#ifndef _KUNDARSA_SBS_H
#define _KUNDARSA_SBS_H

#ifndef Arduino_h
#include "Arduino.h"
#endif

#include <Wire.h>

class SBS {
public:
  struct commandSet{
    String slaveFunction;
    uint8_t code;
    bool writeable;
    int bytes; //make enum
    String type;
  } commands[38];
  
  /* enum type : uint8_t {
    a = 1,
    b = 2
  };
 */
  SBS(uint8_t address, char sda, char scl);
  byte sbsReadByte(uint8_t command);
  byte sbsWriteByte(uint8_t command, byte data);
  uint16_t sbsReadInt(uint8_t command, bool reverse = true);
  uint8_t sbsWriteInt(uint8_t command, uint16_t data, bool reverse = true);
  uint8_t sbsReadStringSize(uint8_t command);
  uint8_t sbsReadString(char str[], uint8_t command);
  uint8_t sbsWriteString(uint8_t command, char str[], uint8_t block_buffer_length);
private:
};


#endif
