#include "StompAllocator.h"

auto StompAllocator::Allocate(uint64 size) -> void*
{
	const uint64 pageCount = (size + PAGE_SIZE - 1) / PAGE_SIZE;
	const uint64 offset = pageCount * PAGE_SIZE - size;
	void* address = ::VirtualAlloc(NULL, pageCount * PAGE_SIZE, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (address == NULL) CRASH("Failure Memory Allocate");
	
	return static_cast<void*>(static_cast<BYTE*>(address) + offset);
}

auto StompAllocator::Release(void* ptr) -> void
{
	const int64 address = reinterpret_cast<int64>(ptr);
	const int64 baseAddress = address - (address % PAGE_SIZE);
	if (::VirtualFree(reinterpret_cast<void*>(baseAddress), 0, MEM_RELEASE) == 0)
		CRASH("Failure Memory Release");
}