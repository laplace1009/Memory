#include "MemoryPool.h"

MemoryPool::MemoryPool(uint32 allocSize)
	: mAllocSize(allocSize)
{
}

MemoryPool::~MemoryPool()
{
	while (mHeaders.empty() == false)
	{
		MemoryHeader* header = mHeaders.front();
		mHeaders.pop();
		::free(header);
	}
}

auto MemoryPool::Push(MemoryHeader* ptr) -> void
{
	std::lock_guard<std::mutex> g{ mLock };
	ptr->SetAllocSize(0);
	mHeaders.emplace(ptr);
	--mAllocCount;
}

auto MemoryPool::Pop() -> MemoryHeader*
{
	MemoryHeader* header = nullptr;

	{
		std::lock_guard<std::mutex> guard{ mLock };
		
		if (mHeaders.empty() == false)
		{
			header = mHeaders.front();
			mHeaders.pop();
		}
		else
		{
			header = reinterpret_cast<MemoryHeader*>(::malloc(mAllocSize));
		}

		if (header->GetAllocSize() == 0)
			CRASH("Invalid Memory Allocate");

		++mAllocCount;
	}
	
	return header;
}
