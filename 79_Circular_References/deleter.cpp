#include <iostream>

struct Free{
    void operator()(int *p)
    {
        free(p);
        std::cout<<"Pointer freed\n";
    }
};

void MallocFree(int *p)
{
    free(p);
    std::cout<<"Pointer freed\n";
}

// smart pointers on legacy code will result in undefined behaviour
// as memory cannot be deleted in legacy code.. **  Free has to be used
// smart pointers invokes a deleter which is used to release a shared resource.
// the default deleter calls delete which is not valid for legacy c code;

// Function pointers increase the size of the unique pointer.
// preference to use function objects instead
void UniquePtrsDeleter()
{
    // std::unique_ptr<int, Free> p{(int *) malloc(4), Free{}};
    std::unique_ptr<int, void (*)(int *)> p{(int *) malloc(4),  MallocFree};
    *p = 100;
    std::cout<<*p<<"\n";
    
}

// no need to specify the function type in the pointer template
void SharedPtrsDeleter()
{
    // std::shared_ptr<int> p{(int *) malloc(4), Free{}};
    std::shared_ptr<int> p{(int *) malloc(4),  MallocFree};
    *p = 100;
    std::cout<<*p<<"\n";   
}

int main()
{
    UniquePtrsDeleter();
    SharedPtrsDeleter();
    return 0;
}