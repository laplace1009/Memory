#pragma once
#include "Types.h"
#include "Windows.h"
#include "MemoryHeader.h"
#include <queue>
#include <mutex>

class MemoryPool
{

public:
	MemoryPool(uint32 allocSize);
	~MemoryPool();
	
	auto Push(MemoryHeader* ptr) -> void;
	auto Pop() -> MemoryHeader*;

private:
	uint32 mAllocSize = 0;
	uint32 mAllocCount = 0;

	std::queue<MemoryHeader*> mHeaders;
	std::mutex mLock;
};

