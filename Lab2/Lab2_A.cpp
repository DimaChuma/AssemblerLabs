#include <iostream>
using namespace std ;
int main()
{
	std::cout<<("Input x, y, z")<<endl;
	int x, y, z, f;
	std::cin >> x >> y >> z;
	// 17.
	_asm {
		cmp z, 2
		jl m2 // z < 2
		cmp x, 3 
		jl m2 // x < 3 
		cmp x, 5
		jge m1  // x >= 5
		jmp m3 
		m1 :
			cmp y, 0
			jne m11 // y != 0
			jmp m3
		m11 :
			mov eax, 5
			mov ebx, y
			xor edx, edx // очищення edx регістру
			idiv ebx
			add eax, x
			jmp stop
		m2 :
			mov eax, 4
			imul x
			mov ebx, 3
			xchg eax, ebx
			imul z
			xchg ebx, eax
			sub eax, ebx
			jmp stop
		m3 :
			mov eax, x
			add eax, z
			jmp stop
		stop:
			mov f, eax
	}
	std::cout << "f = " << f << endl;
}