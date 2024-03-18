;(x^5 + 2 * (x^2 - 4) + x) / x^3
.686P
.model flat, c
.code

procedure		proc x:dword
		 mov eax, x;
        imul eax, x;
        sub eax, 4;
        imul eax, 2; eax = (x * x - 4) * 2

        mov ebx, x;
        imul ebx, x;
        imul ebx, x;
        imul ebx, x;
        imul ebx, x;

        add eax, ebx;
        add eax, x;

        mov ebx, x;
        imul ebx, x;
        imul ebx, x;

        cdq
        idiv ebx;
        mov result, eax;
		ret
procedure		endp
end
