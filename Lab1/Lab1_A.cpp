// Lab1_A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int x, y, z, f;
    std::cout << "Input x=, y=, z=\n";
    std::cin >> x >> y >> z;

   //17. f = (11y + 7x - 2z) / (y + 1);

    _asm {
        mov eax, 11 // ax = 11
        imul y // ax = 11y
        xchg eax, ebx // змінили ах і bx, bx = 11y
        mov eax, 7 //  ax = 7
        imul x // ax = 7x
        xchg eax, ebx // ax = 11y, bx = 7x
        add eax, ebx // ax = 11y + 7x 
        mov ebx, 2 // bx = 2
        xchg eax, ebx // ax = 2, bx = 11y + 7x 
        imul z // ax = 2z
        sub ebx, eax // bx = 11y + 7x - 2z
        mov ecx, y // cs = y
        mov eax, 1 // ax = 1
        add eax, ecx // ax = 1y
        xchg eax, ebx // ax = 11y 7x - 2z, bx = 1y
        idiv ebx // ax = (11y + 7x - 2z) / (1y)
        mov f, eax // f = ax
    }
    std::cout << "f = " << f << endl;
}


