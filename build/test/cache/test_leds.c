#include "build/temp/_test_leds.c"
#include "include/leds.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


static uint16_t virtuales;



void setUp(void) {

    LedsCreate(&virtuales);

}





void test_todos_leds_inician_apagados(void) {



    uint16_t virtuales = 0xFFFF;

    LedsCreate(&virtuales);

    UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_INT);

}



void test_encender_un_led(void) {



    LedsTurnOn(1);

    UnityAssertEqualNumber((UNITY_INT)((0x0001)), (UNITY_INT)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

}



void test_encender_y_apapgar_un_led(void) {



    LedsTurnOn(1);

    LedsTurnOff(1);

    UnityAssertEqualNumber((UNITY_INT)((0x0000)), (UNITY_INT)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

}



void test_encender_y_apapgar_varios_leds(void) {



    LedsTurnOn(3);

    LedsTurnOn(5);

    LedsTurnOff(3);

    UnityAssertEqualNumber((UNITY_INT)((0x0010)), (UNITY_INT)((virtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(49), UNITY_DISPLAY_STYLE_INT);

}
