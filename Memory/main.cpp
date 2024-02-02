#include <iostream>
#include "MultiSizeMemory.h"
#include "FixedSizeMemory.h"
#include "ObjectPool.h"

using namespace std;

class A
{

};

int main()
{
	std::shared_ptr<A> spt{ ObjectPool<A>::Pop(), ObjectPool<A>::Push };
}