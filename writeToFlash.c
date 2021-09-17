#include <msp430.h>
#include <stdint.h>

#include "writeToFlash.h"

void write_flash(char data, int *addr){ //Writes data in address
    SYSBSLC &= ~SYSBSLPE;               // Unprotect BSL
    while(BUSY & FCTL3);                //wait for flash memory to be ready
    FCTL1 = 0xA500 | WRT;               //enable write
    FCTL3 = 0xA500 | LOCKA;             //locks segment A, which contain important information
    while(BUSY & FCTL3);                //wait for flash memory to be ready
    *addr = data;                       //write data in addr
    while(BUSY & FCTL3);                //wait for flash memory to be ready
    FCTL1 = 0xA500;                     //lock writing
    FCTL3 = 0xA500 | LOCK;
    SYSBSLC = SYSBSLPE + SYSBSLSIZE0 + SYSBSLSIZE1;  // Protect the BSL
}
