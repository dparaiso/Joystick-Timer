#ifndef _LED_H_
#define _LED_H_

#define LED0 "/sys/class/leds/beaglebone:green:usr0/brightness"
#define LED1 "/sys/class/leds/beaglebone:green:usr1/brightness"
#define LED2 "/sys/class/leds/beaglebone:green:usr2/brightness"
#define LED3 "/sys/class/leds/beaglebone:green:usr3/brightness"

#define LED_TRIG0 "/sys/class/leds/beaglebone:green:usr0/trigger"
#define LED_TRIG1 "/sys/class/leds/beaglebone:green:usr1/trigger"
#define LED_TRIG2 "/sys/class/leds/beaglebone:green:usr2/trigger"
#define LED_TRIG3 "/sys/class/leds/beaglebone:green:usr3/trigger"

#define LED_DELAY0 "/sys/class/leds/beaglebone:green:usr0/delay_on"
#define LED_DELAY1 "/sys/class/leds/beaglebone:green:usr1/delay_on"
#define LED_DELAY2 "/sys/class/leds/beaglebone:green:usr2/delay_on"
#define LED_DELAY3 "/sys/class/leds/beaglebone:green:usr3/delay_on"

void led_init();
void ledWrite(char *filename, char *param);
#endif