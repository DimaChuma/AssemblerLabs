.386
INCLUDE Irvine32.inc
.model small
.stack 100h

.data
	msg1 db "Input X: ", 0
	msg2 db "Input Y: ", 0
	msg3 db "Input Z: ", 0
	x DWORD 0
	y DWORD 0
	z DWORD 0
	f DWORD 0
.code
main proc

	mov edx, offset msg1
	call writestring   
	call readint   
	
	mov x, eax

	mov edx, offset msg2
	call writestring   
	call readint
	
	mov y, eax

	mov edx, offset msg3
	call writestring   
	call readint   
 
	mov z, eax

	; 17. f = (11y + 7x - 2z) / (y + 1);

	mov eax, 11
	imul y
	xchg eax, ebx
	mov eax, 7
	imul x
	xchg eax, ebx
	add eax, ebx
	mov ebx, 2
	xchg eax, ebx
	imul z
	sub ebx, eax
	mov ecx, y
	mov eax, 1
	add eax, ecx
	xchg eax, ebx
	idiv ebx
	mov f, eax

	call writeint

	invoke exitprocess, 0
main endp
end main