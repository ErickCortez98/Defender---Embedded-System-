; Print.s
; Student names: Jaxon Coward, Erick I. Cortez Valdez
; Last modification date: 4/10/2020
; Runs on LM4F120 or TM4C123
; EE319K lab 7 device driver for any LCD
;
; As part of Lab 7, students need to implement these LCD_OutDec and LCD_OutFix
; This driver assumes two low-level LCD functions
; ST7735_OutChar   outputs a single 8-bit ASCII character
; ST7735_OutString outputs a null-terminated string 

    IMPORT   ST7735_OutChar
    IMPORT   ST7735_OutString
    EXPORT   LCD_OutDec
    EXPORT   LCD_OutFix

    AREA    |.text|, CODE, READONLY, ALIGN=2
    THUMB
;C Code of the recursion function LCD_OutDec in which the assembly function was based on
; void LCD_OutDec1(uint32_t n){
;    char num;
;    if(n < 10){
;		 ST7735_OutChar('0' + n);
;        return;
;    }
;    num = ('0' + (n%10));
;    LCD_OutDec1(n/10);
;		ST7735_OutChar(num);
;} 

;-----------------------LCD_OutDec-----------------------
; Output a 32-bit number in unsigned decimal format
; Input: R0 (call by value) 32-bit unsigned number
; Output: none
; Invariables: This function must not permanently modify registers R4 to R11
; Lab 7 requirement is for at least one local variable on the stack with symbolic binding
charnum EQU 0
	
LCD_OutDec
	PUSH{R4, LR}
	;Base Case
	CMP R0, #10	;If n < 10, we return and do the last case
	BLO return
	;modulo operation n % 10
	MOV R1, #10 	;We'll use R1 = 10 for the modulo operatio
	UDIV R3, R0, R1	; R3 = n / 10
	MUL R2, R3, R1	;R2 = (n/10) * 10
	SUB R2, R0, R2	;R2 = n % 10
	;At this point R2 = n % 10
	ADD R2, #'0'	;Converting result in R2 to ASCII char
	MOV R0, R2
	;Pushing into the stack n
	SUB SP, #8	;Making enough space for two registers, just to even the stack
	STR R0, [SP, #charnum]
	MOV R0, R3	;Moving R3 = n / 10 into R0
	BL LCD_OutDec	;Recursion
	;After coming back from recursion we pop registers out of the stack and print them
	LDR R0, [SP, #charnum]
	ADD SP, #8
	BL ST7735_OutChar
	;We return now
	POP{R4, LR}
	BX LR
return 
	ADD R0, #'0'	;Adding '0' to n just to convert it into an ASCII char
	BL ST7735_OutChar
	POP{R4, LR}
	BX LR
;* * * * * * * * End of LCD_OutDec * * * * * * * *

; -----------------------LCD _OutFix----------------------
; Output characters to LCD display in fixed-point format
; unsigned decimal, resolution 0.01, range 0.00 to 9.99
; Inputs:  R0 is an unsigned 32-bit number
; Outputs: none
; E.g., R0=0,    then output "0.00 "
;       R0=3,    then output "0.03 "
;       R0=89,   then output "0.89 "
;       R0=123,  then output "1.23 "
;       R0=999,  then output "9.99 "
;       R0>999,  then output "*.** "
; Invariables: This function must not permanently modify registers R4 to R11
; Lab 7 requirement is for at least one local variable on the stack with symbolic binding
digit0 EQU 0
digit1 EQU 4

LCD_OutFix
    PUSH{R4,LR}
    MOV R1,#999
    CMP R0,R1
    BHI input_error
    
    SUB SP,#8;allocate 2 local variables
    
    MOV R1,#10
    
    UDIV R2,R0,R1;R2 is R0/10
    MUL R3,R2,R1
    SUB R3,R0,R3;R3 is R0 % 10, which is the first digit
    STR R3,[SP,#digit0];store the first digit
    
    MOV R0,R2;we have the first digit, divide by ten to shift it out
    
    UDIV R2,R0,R1;R2 is R0/100
    MUL R3,R2,R1
    SUB R3,R0,R3;R3 is R0 % 10;R3 is R0 % 10, which is the second digit
    STR R3,[SP,#digit1];store the second digit
    
    MOV R0,R2;we have the second digit, divide by ten to shift it out
    
    UDIV R2,R0,R1;R2 is R0/1000
    MUL R3,R2,R1
    SUB R3,R0,R3;R3 is now the 3rd digit
    
    ;begin output
    MOV R0, R3
    ADD R0,#'0'
    BL ST7735_OutChar
    MOV R0, #'.'
    BL ST7735_OutChar
    LDR R0,[SP,#digit1]
    ADD R0,#'0'
    BL ST7735_OutChar
    LDR R0,[SP,#digit0]
    ADD R0,#'0'
    BL ST7735_OutChar

    
    ADD SP,#8;deallocate local variables
    POP {R4,PC}
    
input_error
    MOV R0, #'*'
    BL ST7735_OutChar
    MOV R0, #'.'
    BL ST7735_OutChar
    MOV R0, #'*'
    BL ST7735_OutChar
    MOV R0, #'*'
    BL ST7735_OutChar
    
    POP {R4,PC}
 
     ALIGN
;* * * * * * * * End of LCD_OutFix * * * * * * * *

     ALIGN          ; make sure the end of this section is aligned
     END            ; end of file
