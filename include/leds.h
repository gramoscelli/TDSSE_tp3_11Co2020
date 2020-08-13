#include <stdint.h>
#include <stdbool.h>


void LedsCreate(uint16_t *flags);

void LedsTurnOn(uint8_t led);

void LedsTurnOff(uint8_t led);

void LedsTurnOnAll(void);

void LedsTurnOffAll(void);

bool LedsIsOn(uint8_t led);

bool LedsIsOff(uint8_t led);
