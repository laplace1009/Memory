#pragma once
#include "Types.h"
#include "Windows.h"
#include <queue>

class MemoryPool
{
	enum
	{
		BLOCK_SIZE = 0x1000,
		MAX_BLOCK_COUNT = 10000,
	};
public:
	MemoryPool(uint64 allocSize);
	~MemoryPool();
	auto AllocateBlock() -> void*;
	auto ReleaseBlock() -> void;

private:
	uint64 mAllocSize;
	void* mPoolAddress;
	std::queue<void*> mMemoryBlocks;
};

