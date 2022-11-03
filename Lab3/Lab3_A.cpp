#include <iostream>
using namespace std;
int main()
{
    int x,y,z,f;
    std::cout << "Input y:\n";
    std::cin >> y;
    _asm {
        mov x, 10
        mov z, 1
        m2:
            mov z, 1
        m1:
            mov eax, 7
            imul x
            mov ebx, 3 
            imul ebx, y
            sub eax, ebx 
            imul z
            add eax, y  
            sub eax, 1 
            mov ebx, x
            imul ebx, x
            mov ecx, y
            imul ecx, y
            cmp ebx, ecx
            jg stop
            add z, 4
            cmp z, 20
            jle m1
            sub x, 1
            cmp x, 4  // або cmp x, 5
            loopne m2 // jg m2
            jmp stop
        stop:
            mov f, eax
    }
    std::cout << "f: " << f << endl;
}
