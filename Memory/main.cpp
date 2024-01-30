#include <iostream>
#include "Memory.h"

using namespace std;

int main()
{
	Memory* m = new Memory();
	int* ptr = static_cast<int*>(m->Allocate(sizeof(int)));
	*ptr = 4;
	cout << *ptr << endl;
}