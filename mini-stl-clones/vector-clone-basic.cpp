/*
pointer to heap memory 
current size 
current capacity 


if size == capacity 
    allocate new memory with double the capacity 
    copy existing elements to new memory 
    deallocate old memory 
    update capacity



*/

#include <iostream>

using namespace std;

template<typename T>

class Vector{
    private:
        T* data; // Pointer to the dynamic array
        size_t size; // Current number of elements in the vector
        size_t capacity; // Current capacity of the vector
    //why size_t?  -> size_t is an unsigned integer type that is used to represent the size of objects in bytes. 
    // size of vector can never be negative, so using an unsigned type like size_t is appropriate.
    // also size of vector can be very large, and size_t is designed to handle large sizes, while int may not be sufficient.

    /*
    functions to implement:
    1. push_back(const T& value): 
    2. pop_back():
    3. operator[](size_t index): 
    // what is operator[]? -> operator[] is an overloaded operator that allows you to access elements of the vector using array-like syntax.
    4. size() const:
    5. capacity() const:
    6. clear():
    */

    public:
        Vector() {
            size = 0;
            capacity = 1; // Start with a small capacity
            data = new T[capacity]; // Allocate initial memory
        }

        ~Vector() {
            delete[] data; // Deallocate memory
        }

        void push_back(T value){
            if(size == capacity){
                capacity *= 2; 
                T* temp = new T[capacity];

                for(size_t i = 0; i < size; i++){
                    temp[i] = data[i]; // Copy existing elements to new memory
                }

                delete[] data; // Deallocate old memory
                
                data = temp; // Update data pointer to new memory
            }
            data[size] = value; // Add new element
            size++; // Increment size
        }

        void pop_back(){
            if(size > 0){
                size--;
            }
        }

        T& operator[](size_t index){
            if(index >= size){
                throw out_of_range("Index out of range");
            }
            return data[index];
        }

        size_t getSize() const {
            return size;
        }

        size_t getCapacity() const {
            return capacity;
        }
};

int main(){
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    std::cout << "Size: " << vec.getSize() << std::endl;
    std::cout << "Capacity: " << vec.getCapacity() << std::endl;
    for(size_t i = 0; i < vec.getSize(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl; 
}