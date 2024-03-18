; a^12 + a^8 + a

.686P
.model flat, c
.code

procedure		proc x:dword
mov eax, a;  
        imul eax, eax;     
        imul eax, eax;      
        imul eax, eax;       
        imul eax, a;
        imul eax, a;
        imul eax, a;
        imul eax, a;
      
        mov ecx, eax;      

        mov eax, a;          
        imul eax, eax;      
        imul eax, eax;      
        imul eax, eax;       
        add eax, ecx;       
        add eax, a;          
        mov result, eax;
		ret
procedure		endp
end
