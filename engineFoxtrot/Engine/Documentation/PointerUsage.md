- Const correctness
 https://www.studytonight.com/cpp/const-keyword.php

- Use references instead of pointers. 
So pointers cant be exceedingly adjustments

- Pointers within this branche
https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-2/

- Auto_ptr DEPRECATED
Wanneer iets een Auto_ptr is blijft er maar 1 eigenaar. Bij het doorpasen van de ptr verliest de vorige pointer zijn eigenschap op deze pointer.
Auto_ptr is deprecated
It takes ownership of the pointer in a way that no two pointers should contain the same object. 
Assignment transfers ownership and resets the rvalue auto pointer to a null pointer. 
Thus, they can’t be used within STL containers due to the aforementioned inability to be copied.

- Unique_ptr
std::unique_ptr was developed in C++11 as a replacement for std::auto_ptr.
It explicitly prevents copying of its contained pointer as would happen with normal assignment i.e. it allows exactly one owner of the underlying pointer.
So, when using unique_ptr there can only be at most one unique_ptr at any one resource and when that unique_ptr is destroyed, the resource is automatically claimed. 
Also, since there can only be one unique_ptr to any resource, so any attempt to make a copy of unique_ptr will cause a compile-time error.
So, it’s best to use unique_ptr when we want a single pointer to an object that will be reclaimed when that single pointer is destroyed.
Use unique_ptr when you want to have single ownership(Exclusive) of the resource. Only one unique_ptr can point to one resource. 
Since there can be one unique_ptr for single resource its not possible to copy one unique_ptr to another.

- Shared_ptr
A shared_ptr is a container for raw pointers. It is a reference counting ownership model i.e. it maintains the reference count of its contained pointer in cooperation with all copies of the shared_ptr.
So, the counter is incremented each time a new pointer points to the resource and decremented when the destructor of the object is called.
Use shared_ptr if you want to share ownership of a resource. Many shared_ptr can point to a single resource.
shared_ptr maintains reference count for this propose. when all shared_ptr’s pointing to resource goes out of scope the resource is destroyed.

- Weak_ptr
A weak_ptr is created as a copy of shared_ptr. It provides access to an object that is owned by one or more shared_ptr instances but does not participate in reference counting.
The existence or destruction of weak_ptr has no effect on the shared_ptr or its other copies. 
It is required in some cases to break circular references between shared_ptr instances.
When you do want to refer to your object from multiple places – 
for those references for which it’s ok to ignoreand deallocate(so they’ll just note the object is gone when you try to dereference).