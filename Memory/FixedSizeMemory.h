#pragma once
#include "Types.h"
#include "MemoryHeader.h"
#include "MemoryPool.h"

class alignas(16) FixedSizeMemory
{
	enum
	{
		MEMORY_POOL_FIXED_SIZE = 32,
		MEMORY_POOL_COUNT = 32,
		MAX_ALLOCATE_SIZE = 4096,
	};

public:
	FixedSizeMemory();
	~FixedSizeMemory() noexcept;

	auto Allocate(uint32 size) -> void*;
	auto Release(void* ptr) -> void;

private:
	std::vector<MemoryPool*> mPools;
};