; Prototype :char * stpcpy(char * dst, const char * src) return *dest;
; BYTE tells the size of the argument (8 bits here)
; rdi = pointer to 1st arg(dest) inputed in the function 
; rsi = pointer to 2nd arg(src) inputed in the function
; rcx = my counter
; bl is the low byte of the rbx register, here my buffer to save a char
; if cmp = 0, compared char = '\0' so it's the end of the string

section .data	; used for declaring initialized data or constants.

section .bss	; used for declarring variables.

section .text	; used for code. must begin with the global _start,
		global _ft_strcpy

_ft_strcpy:		; entry-point of the file
		mov rcx, 0	;put the value 0 into the rcx register(my counter here)


cp:
		mov bl, byte [rsi + rcx]	; bl = rsi[rcx]
		mov byte [rdi + rcx], bl	; rdi[rcx] = bl
		cmp bl, 0					; cmp cl(copied char) to 0
		je end						; jmp to end if cl = 0
		inc rcx						; rcx = rcx + 1
		jmp cp;						; jmp to copy function with rcx + 1

end:
		mov rax, rdi				;rax = rdi(pointer to dest)
		ret							;ret return rax value, my lenght here
