#pragma once
#include "Types.h"
#include "Macro.h"
#include <Windows.h>

class StompAllocator
{
	// �⺻������ os���� ���μ����� �޸𸮸� �Ҵ��ϴ� ����(page)�� 4kb
	// Windows VirtualAlloc�� �޸𸮸� ������ ������ �Ҵ��ϱ� ����
	static constexpr uint64 PAGE_SIZE = 0x1000;

public:
	static auto Allocate(uint64 size) -> void*;
	static auto Release(void* ptr) -> void;

};

