section .data
    hello_msg db "Hello, Holberton", 0

section .text
    global main
    extern printf

main:
    mov rdi, hello_msg
    call printf

    xor rdi, rdi
    call printf

    ret

