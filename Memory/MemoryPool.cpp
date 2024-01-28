#include "MemoryPool.h"

MemoryPool::MemoryPool(uint64 allocSize)
	: mAllocSize(allocSize)
	, mPoolAddress(nullptr)
{
	mPoolAddress = ::VirtualAlloc(NULL, mAllocSize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
}

MemoryPool::~MemoryPool()
{
}

auto MemoryPool::AllocateBlock() -> void*
{
	
	return nullptr;
}

auto MemoryPool::ReleaseBlock() -> void
{
}
