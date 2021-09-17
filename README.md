# MSP430-write-to-flash
Writing data to the protected area of the flash of MSP430 microcontrollers
in the main file, you can call the write_flash funciton as follow
write_flash(0x01, (int *)0x17fc); //Write_flash(hex char, pointer to the address you want to write);
