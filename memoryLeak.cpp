// example code for memory leak
#include <memory>
#include <iostream>

using namespace std;

void memoryLeak(){
    int* ptr = new int(5); // Memory allocated on the heap
    cout << "Value: " << *ptr << endl; // Output: Value: 5
    // Memory leak occurs here as we forgot to delete the allocated memory
}

int main(){

}


/*
double delete example:
void doubleDelete(){
    int* ptr = new int(5); // Memory allocated on the heap
    cout << "Value: " << *ptr << endl; // Output: Value: 5
    delete ptr; // Memory deallocated
    delete ptr; // Double delete, undefined behavior
}
double delete can lead to undefined behavior, including crashes or corruption of the heap.

wild pointer
void wildPointer(){
    int* ptr; // Uninitialized pointer, points to an unknown location
    cout << "Value: " << *ptr << endl; // Accessing wild pointer, undefined behavior
}

why use smart pointers:
frequent allocation and deallocation of memory can lead to memory leaks if not handled properly. 
Aso can create fragmentation of the heap, which can degrade performance over time.

remembre:
new -> delete 
new[] -> delete[]

*/