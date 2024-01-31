#include "FixedSizeMemory.h"
#include "TLS.h"

FixedSizeMemory::FixedSizeMemory()
{
	for (size_t i = 0; i < MEMORY_POOL_COUNT; ++i)
	{
		mPools.emplace_back(new MemoryPool(MEMORY_POOL_FIXED_SIZE));
	}
}

FixedSizeMemory::~FixedSizeMemory() noexcept
{
	for (auto& pool : mPools)
		delete pool;
	mPools.clear();
}

auto FixedSizeMemory::Allocate(uint32 size) -> void*
{
	MemoryHeader* header = nullptr;
	uint32 allocSize = size + sizeof(MemoryHeader);
	if (allocSize > MAX_ALLOCATE_SIZE)
	{
		header = reinterpret_cast<MemoryHeader*>(::malloc(size));
	}
	else
		header = mPools[LThreadId]->Pop();
	
	return MemoryHeader::AttachHeader(header, allocSize);
}

auto FixedSizeMemory::Release(void* ptr) -> void
{
	MemoryHeader* header = MemoryHeader::DetachHeader(ptr);

	const uint32 allocSize = header->GetAllocSize();

	ASSERT_CRASH(allocSize > 0);

	if (allocSize > MAX_ALLOCATE_SIZE)
		::free(header);
	else
		mPools[LThreadId]->Push(header);
}
