#include <memory>
#include <iostream>

// this is RAII (Resource Acquisition Is Initialization) example, 
// where the Resource class acquires a resource in its constructor and releases it in its destructor. 
// The func() function creates an instance of Resource, 
// which will automatically release the resource when it goes out of scope at the end of the function.

class Resource{
    public:
        Resource(){
            std::cout << "Resource acquired\n";
        }
        ~Resource(){
            std::cout << "Resource destroyed\n";
        }
};

void func(){
    Resource r;
}

int main(){
    func();
    return 0;
}

// types of smart pointers 

// 1. std::unique_ptr: A unique pointer that owns a resource exclusively. 
//It cannot be copied, but can be moved. It automatically deletes the resource when it goes out of scope.

/*
void unique_ptr_example(){
    std::unique_ptr<Resource> ptr1(new Resource()); // Resource acquired
    // std::unique_ptr<Resource> ptr2 = ptr1; // Error: cannot copy unique_ptr
    std::unique_ptr<Resource> ptr2 = std::move(ptr1); // Transfer ownership to ptr2
    // ptr1 is now empty, and ptr2 owns the resource
} // Resource destroyed when ptr2 goes out of scope
*/

// 2. std::shared_ptr: A shared pointer that allows multiple pointers to share ownership of a resource. It uses reference counting to manage the resource, and deletes it when the last shared pointer goes out of scope.
/*
void shared_ptr_example(){
    std::shared_ptr<Resource> ptr1(new Resource()); // Resource acquired
    std::shared_ptr<Resource> ptr2 = ptr1; // Both ptr1 and ptr2 share ownership
    std::cout << "Use count: " << ptr1.use_count() << "\n"; // Use count: 2
} // Resource destroyed when both ptr1 and ptr2 go out of scope
*/

// 3. std::weak_ptr: A weak pointer that holds a non-owning reference to a resource managed by a shared pointer. 
// It does not affect the reference count of the resource, 
// and can be used to check if the resource still exists before accessing it.

/*
void weak_ptr_example(){
    std::shared_ptr<Resource> ptr1(new Resource()); // Resource acquired
    std::weak_ptr<Resource> weakPtr = ptr1; // weakPtr holds a non-owning reference to the resource
    if (auto sharedPtr = weakPtr.lock()) { // Check if the resource still exists
        std::cout << "Resource is still alive\n";
    } else {
        std::cout << "Resource has been destroyed\n";
    }
} // Resource destroyed when ptr1 goes out of scope
*/

/*
weak pointer cyclic reference example:
class Node {
public:
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev; // Use weak_ptr to avoid cyclic reference
};

int main() {
    std::shared_ptr<Node> node1 = std::make_shared<Node>();
    std::shared_ptr<Node> node2 = std::make_shared<Node>();

    node1->next = node2; // node1 owns node2
    node2->prev = node1; // node2 holds a weak reference to node1

    // When main() ends, both node1 and node2 will be destroyed without memory leaks
    return 0;
}

class A {
    std::shared_ptr<B> b;
};

class B {
    std::shared_ptr<A> a;
};

// both class point reach other ref count never become 0 so memory leak happens, 
to avoid this we can use weak pointer in one of the class
*/

/*
better to use shared or unique pointer instead of raw new and delete, 
as they provide automatic memory management and help prevent memory leaks and dangling pointers. 
Unique pointers are ideal when you want exclusive ownership of a resource, 
while shared pointers are suitable when multiple parts of your code need to share ownership of a resource. 
Weak pointers can be used to break cyclic references in shared pointer scenarios. 
Always prefer smart pointers over raw pointers for safer and more maintainable code. 
*/