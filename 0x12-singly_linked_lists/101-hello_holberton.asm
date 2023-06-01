section .data
	hello_msg db 'Hello, Holberton', 0x0A ; 0x0A is the ASCII code for a new line
	fmt db "%s", 0

section .text
	extern printf

global main
main:
	sub rsp, 8     ; Allocate space for 64-bit alignment

	mov rdi, fmt   ; Format string
	mov rsi, hello_msg ; Message to print
	xor eax, eax   ; Clear EAX register
	call printf    ; Call printf function

	add rsp, 8     ; Restore stack

	mov eax, 0x60  ; Exit syscall number
	xor edi, edi   ; Exit status code
	syscall        ; Invoke syscall
