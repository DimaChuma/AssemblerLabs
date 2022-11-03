#include <iostream>

int main()
{
    std::cout << "Input elements like \"X Y Z\"\n";
    int a [5][3];
    for (int i = 0; i < 5; i++) {
        int x, y, z;
        std::cin>>x>>y>>z;
        a[i][0] = x;
        a[i][1] = y;
        a[i][2] = z;
    }
    
    int min, row, rowMinObj = 0;
    _asm{
        xor ebx, ebx
        xor eax, eax
        mov esi, 0
        mov row, 0
        lea ebx, a
        mov eax, [ebx][esi]
        mov min, eax
        jmp m1
        m: add bx, 12
           mov si, 0
           add row, 1
           cmp row, 5
           je stop
        m1: mov eax, [ebx][esi]
            cmp eax, min
            jge m2
            mov min, eax
            mov eax, row
            mov rowMinObj, eax
        m2: add esi, 4
            cmp esi, 12
            jge m
            jmp m1
       stop:
            add rowMinObj, 1
            
    }
    std::cout << "Min is: " << min << " Row is: " << rowMinObj;
}

