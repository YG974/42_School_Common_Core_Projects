; C prototype : void *malloc(size_t size) allocate size bytes & return ptr to it
; if malloc failed or if size = 0 --> return NULL
; C prototype : char * strdup(const char *s1)
; rdi = pointer to 1st arg inputed in the function
; rax is always the return value register
; calling functions can modify scratch registers but not preserved registers
; scratch registers : rax, rdi, rsi, rdx, rcx, r8, r9, r10, r11
; preserved registers : rbx, rbp, r12, r13, r14, r15, r16

section .data	; used for declaring initialized data or constants.

section .bss	; used for declarring variables.

section .text	; used for code. must begin with the global _start,
		global _ft_strdup
		extern _ft_strlen
		extern _ft_strcpy
		extern _malloc
		extern ___error

_ft_strdup:	; entry-point of the file
		push rdi		; push rdi on the top of the stack, because calling a
						; a function can modify it
		call _ft_strlen	; call ft_strlen to count bytes to allocate
		inc rax			; len returned in rax, add 1 byte for \0
		mov rdi, rax	; move len+1 in rdi(arg for malloc) to malloc the array
		call _malloc	; allocate len+1 bytes and return ptr in rax
		jz fail			; if malloc fail, return ptr = NULL;
		pop rdi			; take rdi(src_ptr) back from the stack to input strcpy
		mov rsi, rdi	; move ptr to src in rsi (1st arg for strcpy)
		mov rdi, rax	; move rax to rdi(dst_ptr) rax = return malloc(dst_ptr)
		call _ft_strcpy	; return ptr to dest in rax after copying src in dst
		ret				;

fail:
	push rax
    call ___error
    pop qword[rax]
	mov rax, 0			; put 0 in rax reg because malloc failed
	ret					; return NULL ptr

