; syscall information of sysread
;	%rax	System call	| %rdi				| %rsi			| %rdx	
;	0		sys_read	| unsigned int fd	|	char *buf	| size_t count			
; C prototype : ssize_t	read(int fildes, void *buf, size_t nbyte);
; rdi = pointer to 1st arg inputed in the function
; rsi = pointer to 2nd arg inputed in the function
; rdx = pointer to 3rd arg inputed in the function
; rax is always the return value register
; rax is also use to store the ID of a system function you want to use
; ex : 0x2000003 = ID to call read system function
; So to call it --> mov rax, 0x2000003
;					syscall; It will take inputs in rdi, rsi, rdx
; When using the standard FreeBSD calling convention, the carry flag is cleared 
; upon success, set upon failure.

section .data	; used for declaring initialized data or constants.

section .bss	; used for declarring variables.

section .text	; used for code. must begin with the global _start,
		global _ft_read
		extern ___error

_ft_read:	; entry-point of the file
		mov rax, 0x2000003	; syscall number to call sysread
		syscall				; call read will take the 3 first inputed args
		jc error			; CF (carry flag) is set upon when syscall failed
		ret					; return is already put in the rax reg by sysread

error:
	push rax
	call ___error
    pop qword[rax]
	mov rax, -1; lib.c read return -1 if the read failed
	ret


