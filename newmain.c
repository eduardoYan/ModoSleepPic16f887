
// PIC16F887 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1

#ifndef __bool_true_and_false_are_defined
#define __bool_true_and_false_are_defined

typedef unsigned char bool;

#define true 1
#define false 0
#endif
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR enabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = ON         // Low Voltage Programming Enable bit (RB3/PGM pin has PGM function, low voltage programming enabled)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#define _XTAL_FREQ 4000000
#include <xc.h>

int controle;

void __interrupt() MinhaRotina() {

    if(INTF==1){
        INTF=0;
        
        if(controle==1){
            controle=0;
        }else{
            controle=1;
        }
        
        if(controle==1){
            RC1=1;
            SLEEP();
        }else{
            RC1=0;
        }
    }
}



void main() {
    OPTION_REG=0x80;
    ANSELH = 0;
    GIE=1;
    PEIE=0;
    INTE=1;
    TRISB=0xFF;
    
    TRISC=0b00000000;
    PORTC=0;
    controle=0;
    
    while(1){
        RC0=1;
        __delay_ms(500);
        RC0=0;
        __delay_ms(500);
        
        
    }
    
}
