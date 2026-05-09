/*
in basics we implemented a simple vector class with basic functionalities like push_back, operator[], getSize, getCapacity, and destructor.
In this advanced version, we will add more functionalities like pop_back, etc
also we will implement manual destructor, copy constructor, and move constructor for better memory management and performance.
and use placement new for better performance and to avoid unnecessary copying of elements when resizing the vector.

and instead of new T[capacity]
we will use operator new(capacity * sizeof(T)) to allocate raw memory, and then use placement new to construct objects in that memory.
also we will implement move semantics for better performance when moving vectors instead of copying them.
*/