/*
A hashmap is a data structure that stores key-value pairs and allows for efficient retrieval of values based on their corresponding keys. 
It uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

In a typical implementation of a hashmap, the following components are involved:
1. Hash Function: A function that takes a key as input and returns an integer hash code. 
2. Buckets: An array of buckets or slots where the key-value pairs are stored. Each bucket can hold multiple key-value pairs in case of hash collisions.
3. Collision Resolution: A method to handle cases where multiple keys hash to the same index. 
Common techniques include chaining (using linked lists or other data structures to store multiple key-value pairs in the same bucket) 
and open addressing (finding another empty slot in the array).
4. Load Factor: A measure of how full the hashmap is, calculated as the number of key-value pairs divided by the number of buckets. 
When the load factor exceeds a certain threshold, the hashmap may need to be resized to maintain efficient performance.

Hash table powers: 
1. unordered_map: A hash table implementation in C++ that provides average-case O(1) time complexity for insertions, deletions, and lookups.
2. unordered_set: A hash table implementation in C++ that stores unique elements and provides average-case O(1) time complexity for insertions, deletions, and lookups.
3. databases: Many databases use hash tables for indexing and fast data retrieval.
4. Caching: Hash tables are commonly used in caching mechanisms to store and retrieve data quickly based on keys.
5. Symbol Tables: Compilers and interpreters use hash tables to store and retrieve information about variables, functions, and other symbols in programming languages.
6. Networking: Hash tables are used in networking applications for tasks such as routing tables, DNS caching, and load balancing.


core idea:- instead of o(n) time complexity for searching an element in an array,
we can use a hash function to compute an index for the key and directly access the value in O(1) time complexity on average.

index = hash(key) % number_of_buckets

*/

/*
Problem with hashing:
1. Collisions: When two different keys hash to the same index, it can lead to collisions.
eg:
hash("key1") % 10 = 3
hash("key2") % 10 = 3

method to resolve collision:
1. Chaining: Store multiple key-value pairs in the same bucket using a linked list or other data structure.
eg:
bucket[3] -> (key1, value1) -> (key2, value2) -> nullptr

2. Open Addressing: Find another empty slot in the array to store the key-value pair when a collision occurs.
  types of open addressing:
  a. Linear Probing: If a collision occurs, check the next slot in the array until an empty slot is found.
  eg: 
    hash("key1") % 10 = 3 -> bucket[3] is occupied, check bucket[4], if it's empty, store (key1, value1) there.
  b. Quadratic Probing: If a collision occurs, check slots at intervals of 1^2, 2^2, 3^2, etc. until an empty slot is found.
  eg:
    hash("key1") % 10 = 3 -> bucket[3] is occupied, check bucket[4] (1^2), if it's occupied, check bucket[7] (2^2), if it's empty, store (key1, value1) there.
  c. Double Hashing: If a collision occurs, use a second hash function to compute a new index and check that slot for an empty slot.
  eg:
    hash("key1") % 10 = 3 -> bucket[3] is occupied, compute new index using second hash function: hash2("key1") % 10 = 5, check bucket[5], if it's empty, store (key1, value1) there.


2. Load Factor: As the number of key-value pairs increases, the load factor of the hash table increases, which can lead to decreased performance.
To maintain efficient performance, the hash table may need to be resized when the load factor exceeds a certain threshold. 
This typically involves creating a new array of buckets with a larger size, rehashing all existing key-value pairs, and inserting them into the new array.

formula for load factor:
load_factor = number_of_key_value_pairs / number_of_buckets

When load_factor exceeds a certain threshold (e.g., 0.75), the hash table is resized to maintain efficient performance.

element = 7
table_size = 10

load_factor = 7 / 10 = 0.7 (not resized)



*/


#include <iostream>
#include <string>
#include <vector>

template<typename K, typename V>

class Node{
	public:
	    K key;
		V value;
		Node<K, V>* next;
	public:
		Node(K key , V value , Node<K, V>* next){
			this -> key = key;
			this -> value = value;
			this -> next = next;
		}
};

template<typename K, typename V>
// in this we will use linked list to handle collisions in the hashmap
class HashMap{
        private:
		// key - value pair

		std::vector<Node<K, V>*> buckets; // Array of buckets 
		size_t bucket_count; // Number of buckets
		size_t size;

		double resize_threshold = 0.75; // Load factor threshold for resizing


	
	public:
		// Constructor to initialize the hashmap with a specified number of buckets
		HashMap(size_t bucket_count = 10) : bucket_count(bucket_count ), size(0) {
			buckets.resize(bucket_count, nullptr); // Initialize buckets with nullptr
		}
		~HashMap() {
			for(size_t i = 0 ; i < bucket_count; i++) {
				Node<K, V>* current = buckets[i];
				while(current){
					Node<K, V>* temp = current;
					current = current -> next;
					delete temp;
				}
			}
		}
		// Hash function to compute the index for a given key
		size_t hash( K key ) {
			return std::hash<K>{}(key) % bucket_count; // Simple hash function using modulo operator
		}

		void resize(){
			size_t new_bucket_count = bucket_count * 2;
			std::vector<Node<K, V>*> new_buckets(new_bucket_count , nullptr);
			for(size_t i = 0 ;i < bucket_count ; i++){
				Node<K, V>* curr = buckets[i];
				while(curr != nullptr){
					size_t new_index = hash(curr -> key) % new_bucket_count;
					Node<K, V>* newNode = new Node<K, V>(curr -> key , curr -> value , nullptr);
					if(new_buckets[new_index] == nullptr){
						new_buckets[new_index] = newNode;
					}
					else{
						Node<K, V>* currentNode = new_buckets[new_index];
						while(currentNode -> next != nullptr){
							currentNode = currentNode -> next;
						}
						currentNode -> next = newNode;
					}
					curr = curr -> next;
				}
			}
			buckets = new_buckets;
			bucket_count = new_bucket_count;
		}

		// function to insert a key-value pair into the hashmap
		void insert(K key , V value){
			
			double load_factor = static_cast<double>(size) / bucket_count;

			if(load_factor > resize_threshold){
				resize();
			}
			
			size_t index = hash(key);
			Node<K, V>* newNode = new Node<K, V>(key , value , nullptr);
			Node<K, V>* curr = buckets[index];
			if(curr == nullptr){
				buckets[index] = newNode;
				size++;
				return;
			}
			else if(curr != nullptr){
				Node<K, V>* currentNode = curr;
				while(currentNode->next != nullptr){
					currentNode = currentNode -> next;
				}
				currentNode -> next = newNode;
				size++;
				return;
			}
		}
		
		Node<K, V>* search(K key){
			size_t index = hash(key);
			Node<K, V>* curr = buckets[index];
			while(curr != nullptr){
				if(curr -> key == key){
					return curr;
				}
				curr = curr -> next;
			}
			return nullptr;
		}

		void remove(K key){
			size_t index = hash(key);
			Node<K, V>* curr = buckets[index];
			// delete a node
			Node<K, V>* prev = nullptr;
			while(curr != nullptr){
				
				if(curr -> key == key){
					// then we have to remove this key
					// delete a node 
					// if its the first node
					if(prev == nullptr){
						buckets[index] = curr -> next;
						delete curr;
						size--;
						return;
					}
					else{
						prev -> next = curr -> next;
						size--;
						delete curr;
						return;
					}

				}
				prev = curr;
				curr = curr -> next;
			}
		}

		void display(){
			for(size_t i = 0 ;i < bucket_count ; i++){
				Node<K, V>* curr = buckets[i];
				while(curr != nullptr){
					std::cout << "Key: "<< curr->key <<" Value: "<<curr -> value << std::endl;
					curr = curr -> next; 
				}
			} 
		}

		bool isEmpty(){
			return size == 0;
		}
		
		void clear(){
			for(size_t i = 0 ; i< bucket_count ;i++){
				Node<K, V>* curr = buckets[i];
				while(curr != nullptr){
					Node<K, V>* temp = curr;
					curr = curr -> next;
					delete temp;
				}
				buckets[i] = nullptr;
			}
			size = 0;
		}

		void print(){
			for(size_t i = 0 ;i < bucket_count ; i++){
				Node<K, V>* curr = buckets[i];
				while(curr != nullptr){
					std::cout << "Key: "<< curr->key <<" Value: "<<curr -> value << std::endl;
					curr = curr -> next;
				}
			}
		}

		// 

};


int main(){
	HashMap<int, int> hashmap;
	hashmap.insert(1 , 10);
	hashmap.insert(2 , 20);
	hashmap.insert(3 , 30);
	hashmap.insert(4 , 40);
	hashmap.insert(5 , 50);
	hashmap.insert(6 , 60);
	hashmap.insert(7 , 70);
	hashmap.insert(8 , 80);
	hashmap.insert(9 , 90);
	hashmap.insert(10 , 100);
	hashmap.insert(11 , 110);

	std::cout << "HashMap contents:" << std::endl;
	hashmap.display();

	std::cout << "Search for key 5: " << hashmap.search(5)->value << std::endl;

	std::cout << "Removing key 5" << std::endl;
	hashmap.remove(5);

	std::cout << "Search for key 5 after removal: " << (hashmap.search(5) == nullptr ? "Not found" : std::to_string(hashmap.search(5)->value)) << std::endl;
	hashmap.print();

	return 0;
}



