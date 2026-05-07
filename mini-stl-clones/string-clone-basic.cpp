/*
cpp string 

*/

#include <iostream>

class String{
        private:
                char* data; // Pointer to the dynamic array of characters
                size_t size; // Current size of the string
                size_t capacity; // Current capacity of the string

                size_t str_length(const char* str){
                        size_t count = 0;
                        while(str[count] != '\0'){
                                count++;
                        }
                        return count;
                }

                void str_copy(char* dest, const char* src){
                        size_t i = 0;
                        while(src[i] != '\0'){
                                dest[i] = src[i];
                                i++;
                        }
                        dest[i] = '\0'; // Null-terminate the destination string
                }
        public:
                String(){
                        size = 0;
                        capacity = 1; // Start with a small capacity
                        data = new char[capacity]; // Allocate initial memory
                        data[0] = '\0'; // Null-terminate the string
                }

                String(const char* str){
                        size = str_length(str);
                        capacity = size + 1; // +1 for null terminator
                        data = new char[capacity]; // Allocate memory
                        str_copy(data, str); // Copy the input string to data
                }

                ~String(){
                        delete[] data; // Deallocate memory
                }

                const char& operator[](size_t index) const {
                        if(index >= size){
                                throw std::out_of_range("Index out of range");
                        }
                        return data[index];
                }

                void print(){
                        std::cout << data << std::endl;
                }

                size_t getSize() const {
                        return size;
                }

                size_t getCapacity() const {
                        return capacity;
                }

                void append(const char* str){
                        size_t newSize = size + str_length(str);
                        if(newSize >= capacity){
                                capacity = newSize + 1; // +1 for null terminator
                                char* temp = new char[capacity];

                                str_copy(temp, data); // Copy existing string to new memory
                                str_copy(temp + size, str); // Append new string to temp

                                delete[] data; // Deallocate old memory
                                data = temp; // Update data pointer to new memory
                                size = newSize; // Update size
                        } else {
                                str_copy(data + size, str); // Append new string to existing memory
                                size = newSize; // Update size
                        }
                }

                void clear(){
                        size = 0;
                        data[0] = '\0'; // Null-terminate the string
                }

                void resize(size_t newSize){
                        if(newSize >= capacity){
                                capacity = newSize + 1; // +1 for null terminator
                                char* temp = new char[capacity];

                                str_copy(temp, data); // Copy existing string to new memory

                                delete[] data; // Deallocate old memory
                                data = temp; // Update data pointer to new memory
                        }
                        size = newSize; // Update size
                        data[size] = '\0'; // Null-terminate the string
                }

                void insert(size_t index, const char* str){
                        if(index > size){
                                throw std::out_of_range("Index out of range");
                        }
                        size_t newSize = size + str_length(str);
                        if(newSize >= capacity){
                                capacity = newSize + 1; // +1 for null terminator
                                char* temp = new char[capacity];

                                // Copy part before index
                                for(size_t i = 0; i < index; i++){
                                        temp[i] = data[i];
                                }
                                // Copy new string
                                str_copy(temp + index, str);
                                // Copy part after index
                                for(size_t i = index; i < size; i++){
                                        temp[str_length(str) + i] = data[i];
                                }

                                delete[] data; // Deallocate old memory
                                data = temp; // Update data pointer to new memory
                                size = newSize; // Update size
                        } else {
                                // Shift existing characters to make space for new string
                                for(size_t i = size; i > index; i--){
                                        data[str_length(str) + i - 1] = data[i - 1];
                                }
                                // Copy new string into position
                                str_copy(data + index, str);
                                size = newSize; // Update size
                        }
                }
};

int main(){
        String str("Hello");
        str.print(); // Output: Hello
        std::cout << "Size: " << str.getSize() << std::endl; // Output: Size: 5
        std::cout << "Capacity: " << str.getCapacity() << std::endl; // Output: Capacity: 6

        str.append(", World!");
        str.print(); // Output: Hello, World!
        std::cout << "Size: " << str.getSize() << std::endl; // Output: Size: 13
        std::cout << "Capacity: " << str.getCapacity() << std::endl; // Output: Capacity: 14

        return 0;
}