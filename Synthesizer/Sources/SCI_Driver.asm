          
 ;**************************************************************
;* This stationery serves as the framework for a              *
;* user application. For a more comprehensive program that    *
;* demonstrates the more advanced functionality of this       *
;* processor, please see the demonstration applications       *
;* located in the examples subdirectory of the                *
;* Freescale CodeWarrior for the HC12 Program directory       *
;**************************************************************

; export symbols
            XDEF SCI_Init, SCI_InChar, SCI_OutChar

; Include derivative-specific definitions 
		INCLUDE 'derivative.inc'  		

		    
; variable/data section
    RDRF: EQU $20       ; Receive Data Register Full Bit
    TDRE: EQU $80       ; Transmit Data Register Empty Bit
; Insert here your data definition. For demonstration, temp_byte is used.

; code section
MyCode:     SECTION

;*******

SCI_Init:

            clr SCIBDH
 ;SCIBDL=250000/baudRate, these 5 cases only
 ;baudRate =  2400 bits/sec   SCIBDL=104
 ;baudRate =  4800 bits/sec   SCIBDL=52
 ;baudRate =  9600 bits/sec   SCIBDL=26
 ;baudRate =  19200 bits/sec  SCIBDL=13
 ;baudRate =  250000 bits/sec SCIBDL=1
 ;assumes a module clock frequency of 4 MHz
 ;sets baudRate to 250000 bits/sec if doesn't match one of the above
 baudRate1: cpd  #2400 
            bne  baudRate2
            ldd #2400
            std SCIBDH
            bra break
    
 baudRate2: cpd  #4800 
            bne  baudRate3
            ldd #4800
            std SCIBDH
            bra break
            
 baudRate3: cpd  #9600 
            bne  baudRate4
            ldab #26
            stab SCIBDL
            bra break
            
 baudRate4: cpd  #19200
            bne  baudRate5
            ldd #19200
            std SCIBDL
            bra break
            
 baudRate5: ldd #1
            std SCIBDL
            bra break    
             
; SCICR1 = 0  >> bit value meaning
;    7   0    LOOPS, no looping, normal
;    6   0    WOMS, normal high/low outputs
;    5   0    RSRC, not appliable with LOOPS=0
;    4   0    M, 1 start, 8 data, 1 stop
;    3   0    WAKE, wake by idle (not applicable)
;    2   0    ILT, short idle time (not applicable)
;    1   0    PE, no parity
;    0   0    PT, parity type (not applicable with PE=0) */  

; SCICR2 = 0x0c >> bit value meaning
;    7   0    TIE, no transmit interrupts on TDRE
;    6   0    TCIE, no transmit interrupts on TC
;    5   0    RIE, no receive interrupts on RDRF
;    4   0    ILIE, no interrupts on idle
;    3   1    TE, enable transmitter
;    2   1    RE, enable receiver
;    1   0    RWU, no receiver wakeup
;    0   0    SBK, no send break */ 
 break:     bclr  SCICR1, %11111111
            bset  SCICR2, %00001100
            bclr  SCICR2, %11110011
            rts
 
 
;*******
 
 SCI_InChar: 
 
;//-------------------------SCI_InChar------------------------
;// Wait for new serial port input, busy-waiting synchronization
;// The input is not echoed
;// Input: none
;// Output: ASCII code for key typed
;char SCI_InChar(void){
;  while((SCISR1 & RDRF) == 0){};
;  return(SCIDRL);
;}
           
           brclr  SCISR1, RDRF, SCI_InChar
           ldab   SCIDRL
           rts
 
    
     
 
 
 
;*******
 
                    
SCI_OutChar:   
                   
;//-------------------------SCI_OutChar------------------------
;// Wait for buffer to be empty, output 8-bit to serial port
;// busy-waiting synchronization
;// Input: 8-bit data to be transferred
;// Output: none                   
;void SCI_OutChar(char data){
;  while((SCISR1 & TDRE) == 0){};
;  SCIDRL = data;
;}                            
                   
            brclr  SCISR1,TDRE, SCI_OutChar  
            stab  SCIDRL
            rts
 
 
 
 




















