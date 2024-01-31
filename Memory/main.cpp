#include <iostream>
#include "MultiSizeMemory.h"
#include "FixedSizeMemory.h"

using namespace std;

int main()
{
	FixedSizeMemory* fm = new FixedSizeMemory();
	int* ptr = reinterpret_cast<int*>(fm->Allocate(sizeof(int)));
	*ptr = 4;
	cout << *ptr << endl;
}

//46080