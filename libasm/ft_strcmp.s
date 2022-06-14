; C prototype	int		ft_strcmp(const char *s1, const char *s2);
; byte tells the size of the argument (8 bits here)
; rdi = pointer to 1st arg(dest) inputed in the function 
; rsi = pointer to 2nd arg(src) inputed in the function
; rcx = my counter
; rax is always the return value register
; bl is the low byte of the rbx register, here my buffer to save a char
; bh is the hight byte of the rbx register, here my buffer to save a char
; if cmp = 0, compared char = '\0' so it's the end of the string

section .data	; used for declaring initialized data or constants.

section .bss	; used for declarring variables.

section .text	; used for code. must begin with the global _start,
		global _ft_strcmp

_ft_strcmp:	; entry-point of the file
	mov rax, 0	; rax = 0, my return
	mov rbx, 0	; rbx = 0, my buffer to compare the chars
	mov rcx, -1	; rcx = 0, my counter to iterate the strings
inc:
	inc rcx		; rcx = rcx + 1
cmp:
	mov bl, byte [rdi + rcx] ; bl = s1[rcx]
	mov bh, byte [rsi + rcx] ; bh = s2[rcx]
	cmp bl, 0	; if bl=null, end of the string1
	je end		; if end of the string return the diff
	cmp bh, 0	; if bh=null, end of the string2
	je end		; if end of the string return the diff
	cmp bl, bh	; if bl=hl, continue the loop
	je inc		; go to inc segnement

end:
	sub bl, bh	; bl = bl-bh
	movsx rax, bl	; rax = bl = return, movsx used to mov smaller reg in bigger
	ret
