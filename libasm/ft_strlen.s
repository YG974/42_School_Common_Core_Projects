section .data	; used for declaring initialized data or constants.

section .bss	; used for declarring variables.

section .text	; used for code. must begin with the global _start,
		global _ft_strlen

_ft_strlen:		; entry-point of the file
		mov rax, 0	;put the value 0 into the rax register(my counter here)

;BYTE tells the size of the argument (8 bits here)
;rdi = pointer to 1st arg inputed in the function & rax = my counter
;if cmp = 0, compared char = '\0' so it's the end of the string

cmp:
		cmp BYTE [rdi + rax], 0;	compare the value at [rdi+rax] whith 0,
		je end						;if cmp operation is equal to 0, jmp to end
		inc rax						;rax = rax + 1
		jmp cmp						;jump to start of cmp function with rax+1

end:
		ret							;ret return rax value, my lenght here

