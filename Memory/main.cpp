#include <iostream>
#include "MultiSizeMemory.h"
#include "FixedSizeMemory.h"

using namespace std;

int main()
{
	FixedSizeMemory<32>* m = new FixedSizeMemory<32>();
	int* ptr = reinterpret_cast<int*>(m->Allocate(sizeof(int)));
	*ptr = 4;
	cout << *ptr << endl;
	m->Release(ptr);
	double* dPtr = reinterpret_cast<double*>(m->Allocate(sizeof(double)));
	*dPtr = 3.141592;
	cout << *dPtr << endl;
}