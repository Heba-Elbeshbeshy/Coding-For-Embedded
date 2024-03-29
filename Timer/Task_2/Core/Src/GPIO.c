#include "GPIO.h"

#define _OUTTYPE_MASK ((uint8_t)0x01)
#define _OUTTYPE_SHIFT 0

#define _PUPD_MASK ((uint8_t)0x06)
#define _PUPD_SHIFT 1

unsigned int *LOOKUP[2][5] =
{{GPIOA_MODER, GPIOA_OTYPER, GPIOA_PUPDR, GPIOA_IDR, GPIOA_ODR},
 {GPIOB_MODER, GPIOB_OTYPER, GPIOB_PUPDR,  GPIOB_IDR, GPIOB_ODR}};

void GPIO_EnableClock(uint8_t PortID) {
     *RCC_AHB1ENR |= (0x01 << PortID);
}

void GPIO_Init(uint8_t PortID, uint8_t PinNum, uint8_t PinMode,
               uint8_t DefaultState) {
               
      *LOOKUP[PortID][0] &= ~(0x03 << 2 * PinNum);
      *LOOKUP[PortID][0] |= PinMode << 2 * PinNum;

      *LOOKUP[PortID][1] &= ~(1 << PinNum);
      *LOOKUP[PortID][1] |= ((DefaultState & _OUTTYPE_MASK) >> _OUTTYPE_SHIFT) << PinNum;

      *LOOKUP[PortID][2] &= ~(0x03 << 2 * PinNum);
      *LOOKUP[PortID][2] |= ((DefaultState & _PUPD_MASK) >> _PUPD_SHIFT) << (2 * PinNum); 
}

uint8_t GPIO_WritePin(uint8_t PortID, uint8_t PinNum,
                            uint8_t Data) {
    uint8_t result;
     if (((*LOOKUP[PortID][0] & (0x03 << 2 * PinNum)) >> (2 * PinNum)) == 1) {
        if (Data) {
          *LOOKUP[PortID][4] |= (1 << PinNum);
        } else {
          *LOOKUP[PortID][4] &= ~(1 << PinNum);
        }
        result = OK;
      } else {
        result = NOK;
      }

  return result;
}

uint8_t GPIO_ReadPin(uint8_t PortID, uint8_t PinNum) {
  uint8_t data = 0;

  data = (*LOOKUP[PortID][3] & (1 << PinNum)) >> PinNum;
  return data;
}
