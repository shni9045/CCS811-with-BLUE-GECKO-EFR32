/*
 * irq.c -  Source file for implementation of LETIMER0 IRQ Handler
 * Attributes - Prof.David Sluiter IOT and Embedded Firmware Lecture 5 & Lecture 6
 *
 */

#include "irq.h"

/* Function that Implements LETIMER0 IRQ Handler
 * PARAMETERS : NONE
 * RETURNS    : NONE
 */
void LETIMER0_IRQHandler(void){

  // Check if COMP1 Interrupt flag is set
  if (LETIMER0->IF & LETIMER_IF_COMP1){

      // Set the appropriate event in scheduler
      schedulerSetCOMP1Event();

  }

  // Check if Underflow Interrupt flag is set
  else if (LETIMER0->IF & LETIMER_IF_UF){

      // Set the appropriate event in scheduler
      schedulerSetUFEvent();

  }

  // Clear Interrupt Sorces
  LETIMER_IntClear(LETIMER0, LETIMER_IF_COMP0 |LETIMER_IF_COMP1 |LETIMER_IF_UF);


}
