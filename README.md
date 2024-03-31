# MemoryLibrary
### Windows용 Custom Memory Allocate
#### C++ 20 MSVC
##### BaseAllocators
* MemroyHeader를 만들어서 디버그에 유용하게 만듬
* BaseAllocator는 c스타일을 사용한 malloc과 해제인 free를 이용해서 기본적인 할당을 만듬
* StompAllocator는 Windows 전용 함수인 VirtualAlloc을 이용한 메모리 할당을 하고 할당 크기 이상메모리 주소에 접근 할려고 한다면 Segfault
* FixedSizedMemory는 고정크기로 메모리를 할당을 하고 고정 크기를 넘어가는 할다은 기본적인 할당(new)을 사용
* MultiSizeMemory는 크기에 따라 메모리할당을 다르게 해주고, 맥시멈 크기를 넘어가면 기본적인 할당(new)을 사용

##### MemoryPool
* MemoryPool은 MemoryAlloc은 상당히 비싼 비용의 연산이라서 한번 할당해놓고 계속 사용하는게 오버헤드를 줄이는데 사용
* MemoryPool은 BaseAllocators중 하나를 이용해서 메모리를 할당
* ObjectPool은 한프로젝트에서는 같은 Object를 사용할 일이 많기때문에 같은 Object끼리 계속 할당을 함
