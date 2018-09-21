;NOTE(Alex): First asm 
COMMENT delimiter NOTE(Alex): C Calling convention specifies that calling func pushes and pops RSP , parameters are passed through rbx, rcx, r8d, r9d when possible and if more, parameters get pushed on the stack

IFDEF FIBONACCI_TEST
;OPTION NOKEYWORD:<STR MASK NAME>
	.data
	char   TYPEDEF SBYTE
	long   TYPEDEF DWORD
	float  TYPEDEF REAL4
	double TYPEDEF REAL8
	pchar  TYPEDEF PTR char

	BUFFER_SIZE EQU 24
	Format char 25h, 69h, 0ah, 00h  ; Format of string
	Buffer char BUFFER_SIZE DUP (?) ; Unitialized buffer
  
	Num0 DWORD 0
	Num1 DWORD 1
	Temp DWORD 0
	Max DWORD 30
	Count DWORD 0

	extrn OutputDebugStringA : PROC 
	extrn _snprintf_s : PROC 
	extrn __xt_z : PTR
	
	.code 
	PUBLIC PrintFibonacciRangeB
	PrintFibonacciRangeB PROC

	mov dword ptr [Num0], r8d
	mov dword ptr [Num1], r9d
	mov eax, dword ptr [rsp + 28h]
	mov dword ptr [Temp], eax
	sub rsp, 48h

	jmp comparison

	increment: 
	mov eax, dword ptr[Count]
	inc  eax
	mov dword ptr[Count], eax

	comparison:
	mov eax, dword ptr[Count]			
	cmp eax, dword ptr[Max]
	jae endloop

	;_snprintf_s(Buffer, BUFFER_SIZE, BUFFER_SIZE,  "%i\n", Num1); 

	mov eax, dword ptr [Num1]
	mov dword ptr [rsp + 20h], eax
	;lea r9, BYTE PTR [__xt_z + 8h]
	lea r9, BYTE PTR [Format]
	mov r8d, BUFFER_SIZE	
	mov edx, BUFFER_SIZE
	lea rcx, BYTE ptr [Buffer]
	call _snprintf_s  

	lea rcx, BYTE ptr [Buffer]
	call OutputDebugStringA

	mov  ebx, dword ptr[Num1]
	mov  eax, dword ptr[Num0]
	mov dword ptr[Temp], ebx
	add ebx, eax
	mov eax, ebx
	mov dword ptr[Num1], eax
	mov eax, dword ptr[Temp]
	mov dword ptr[Num0], eax 
	jmp increment
	
	endloop:
	add rsp, 48h
	ret 

	PrintFibonacciRangeB ENDP

ELSEIFDEF COMBVAL_TEST
	.data
	RealVal Real8 +4.0 ;Sets a 8byte floating point value 

	.code
	PUBLIC CombineValuesB
	CombineValuesB PROC
	add ecx, r8d
	add ecx, edx
	mov eax, ecx
	cvtsi2sd xmm1, rax
	divsd xmm1, xmm3
	movsd xmm0, xmm1
	RET

	CombineValuesB ENDP

ELSEIFDEF MESSAGEBOX_TEST

	.data
	extrn ExitProcess: PROC
	extrn MessageBoxA: PROC

	caption db '64-bit Hello', 0
	message db 'Hello World', 0
	
	.code
	START PROC

	sub rsp, 28h     ;Shadow space, align instruction pointer 
	;cvtqd2pd xmm1, xmm2 

	mov [rax * 2 + rbx + 5], 8 
	mov rcx, 0 	  ;HWND = 0 
	lea rdx, caption ;LPCSTR lpText 
	lea r8, message  ;LPCStr lpCaption
	mov r9d, 0 	  ;uType = MB_OK
	call MessageBoxA ;Call MessageBox API function
	mov ecx, eax     ;uExitCode = MessageBox()

	call ExitProcess

	START ENDP

ELSEIFDEF OPCODE_ENCODING
	.data
	extrn ExitProcess: PROC
	value DWORD 28

	.code
	START PROC
	XOR EAX, EAX
	ADD EAX, value
	call ExitProcess
	START ENDP



; speculative execution could store the value pointed to by F000H before being modified into rbx!, thats why we put a serializing instruction such as SFENCE 
;mov rax, cr3
;mov cr3, rax
;mov qword ptr [F0000000h], A000h
;sfence
;mov rbx, qword ptr [F0000000h]

ENDIF
END

