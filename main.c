#include <stdint.h>
#include <stdbool.h>
#include "tm4c123gh6pm.h"

void systick_timer(void);


void GPIO_PORT_F_init(void)
{
    SYSCTL_RCGC2_R |= 0x00000020;            // ENABLE CLOCK TO GPIOF
    GPIO_PORTF_LOCK_R = 0x4C4F434B;          // UNLOCK COMMIT REGISTER
    GPIO_PORTF_CR_R   = 0x1F;                // MAKE PORTF0 CONFIGURABLE
    GPIO_PORTF_DEN_R  = 0x1F;                // SET PORTF DIGITAL ENABLE
    GPIO_PORTF_DIR_R  = 0x0E;                // SET PF0, PF4 as input and PF1, PF2 and PF3 as output
    GPIO_PORTF_PUR_R  = 0x11;                // PORTF PF0 and PF4 IS PULLED UP
