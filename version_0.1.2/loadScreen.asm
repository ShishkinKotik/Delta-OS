section .data
  message db "[OK] compiling file term.c", 0
  message db "[OK] простой экран загрузки", 0
  message db "[OK] 0101010101010010101010101010100001010111", 0

section .text
  global _start

_start:
  mov eax, 4
  mov ebx, 1
  mov ecx, message
  mov edx, 128

  int 0x80

  mov eax, 1

  xor ebx, ebx

  int 0x80
  
