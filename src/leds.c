#include "leds.h"

#define LEDS_ALL_OFF        0x0000
#define LEDS_TO_BITS_OFFSET 1
#define LEDS_BIT_ON         1

static uint16_t * port;

uint8_t LedToBit(uint8_t led) {
    return (led - LEDS_TO_BITS_OFFSET);
}

uint8_t BitMask(uint8_t bit) {
    return (1 << bit);
}

void LedsCreate(uint16_t *flags) {
    port = flags;
    *flags = 0x0000;
}

void LedsTurnOn(uint8_t led) {
    *port |= BitMask(LedToBit(led));
}

void LedsTurnOff(uint8_t led) {
    *port &= ~BitMask(LedToBit(led));
}
