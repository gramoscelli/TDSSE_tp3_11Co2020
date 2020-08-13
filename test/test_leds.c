/*
* DONE Todos los leds empiezan apagados 
* DONE Encender un led 
* DONE Prender y apagar un led 
* DONE Prender y apagar algunos leds
* DONE Asegurarse que un led no afecta los demas
* DONE Prender todos los leds simultáneamente
* DONE Apagar todos los leds simultáneamente
* DONE Consultar el estado de un led
* TODO Parámentros son inválidos
* TODO Parámentros en valores de borde
*/

#include "unity.h"
#include "leds.h"

static uint16_t virtuales;

void setUp(void) {
    LedsCreate(&virtuales);
}

//! @test Todos los leds arrancan apagados
void test_todos_leds_inician_apagados(void) {
    //TEST_FAIL_MESSAGE("arrancamos amigo...");
    uint16_t virtuales  = 0xFFFF;
    LedsCreate(&virtuales);
    TEST_ASSERT_EQUAL(0x0000, virtuales);
}

void test_encender_un_led(void) {
    //TEST_FAIL_MESSAGE("falla adrede...");
    LedsTurnOn(1);
    TEST_ASSERT_EQUAL(0x0001, virtuales);
}

void test_encender_y_apapgar_un_led(void) {
    //TEST_FAIL_MESSAGE("falla adrede...");
    LedsTurnOn(1);
    LedsTurnOff(1);
    TEST_ASSERT_EQUAL(0x0000, virtuales);
}

void test_encender_y_apapgar_varios_leds(void) {
    //TEST_FAIL_MESSAGE("falla adrede...");
    LedsTurnOn(3);
    LedsTurnOn(5);
    LedsTurnOff(3);
    TEST_ASSERT_EQUAL(0x0010, virtuales);
}

void test_encender_todos_los_leds(void) {
    //TEST_FAIL_MESSAGE("falla adrede...");
    LedsTurnOnAll();
    TEST_ASSERT_EQUAL(0xFFFF, virtuales);
}

void test_apagar_todos_los_leds_version_1(void) {
    //TEST_FAIL_MESSAGE("falla adrede...");
    LedsTurnOn(3);
    LedsTurnOn(5);
    LedsTurnOffAll();
    TEST_ASSERT_EQUAL(0x0000, virtuales);
}

void test_apagar_todos_los_leds_version_2(void) {
    //TEST_FAIL_MESSAGE("falla adrede...");
    LedsTurnOnAll();
    LedsTurnOffAll();
    TEST_ASSERT_EQUAL(0x0000, virtuales);
}
