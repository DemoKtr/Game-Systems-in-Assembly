.386
.model flat, stdcall
.stack 4096
ExitProcess proto, dwExitCode: dword

.data
sum DWORD ?

.code
main proc
    mov eax, 2
    add eax, 2
    mov sum, eax

    invoke ExitProcess, 0

main endp
end main