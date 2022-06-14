; syscall information of sysread
; %rax		| System call | %rdi			| %rsi				| %rdx	
; 0x20000004| sys_write	  | unsigned int fd | const char *buf	| size_t count
; C prototype : ssize_t	write(int fildes, const void *buf, size_t nbyte);
; rdi = pointer to 1st arg inputed in the function
; rsi = pointer to 2nd arg inputed in the function
; rdx = pointer to 3rd arg inputed in the function
; rax is always the return value register
; rax is also use to store the ID of a system function you want to use
; ex : 0x2000004 = ID to call write system function
; So to call it --> mov rax, 0x2000004
;					syscall; It will take inputs in rdi, rsi, rdx
; When using the standard FreeBSD calling convention, the carry flag is cleared 
; upon success, set upon failure.

section .data	; used for declaring initialized data or constants.

section .bss	; used for declarring variables.

section .text	; used for code. must begin with the global _start,
		global _ft_write
		extern ___error

_ft_write:	; entry-point of the file
		mov rax, 0x2000004	; syscall number to call syswrite
		syscall				; call write will take the 3 first inputed args
		jc error			; CF (carry flag) is set upon when syscall failed
		ret					; return is already put in the rax reg by syswrite

error:
	push rax
	call ___error
	pop qword[rax]
	mov rax, -1; lib.c write return -1 if the write failed
	ret

