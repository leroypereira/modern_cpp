// Resource acquistion in intialisation
#include <iostream>
#include "Integer.h"
#include <memory>

void Display(Integer *p)
{
    if (!p)
        return;
    std::cout<<p->GetValue()<<std::endl;
}

Integer * GetPointer(int value){
    Integer *p = new Integer{value};
    return p;
}

void Store(std::unique_ptr<Integer> p)
{
    std::cout<<"Storing data into a file: "<<p->GetValue()<<std::endl;
}

void Operator (int value)
{
    Integer *p = GetPointer(value);
    std::unique_ptr<Integer> p_smartPtr{GetPointer(value)};
    std::weak_ptr<int> pInt = std::make_shared<int>(1);
    
    if(p==nullptr)
    {
        p = new Integer{};
    }

    if(p_smartPtr == nullptr)
    {
        // reset deletes the resource already held by the smart pointer and then allocates a new resource to the smart pointer
        p_smartPtr.reset(new Integer{value});
    }


    p->SetValue(100);
    
    Display(p);
    Display(p_smartPtr.get());
    
    delete p;
    p_smartPtr = nullptr; // unique pointer has operloaded assignment operator which accepts nullptr as input.
                          // this simply deltes the resource of the smart pointer
    
    p = new Integer{};
    p_smartPtr.reset(new Integer{});
    
    *p = __LINE__;
    *p_smartPtr = __LINE__; // dereferencing operator is overloaded by the smart pointer
    
    Display(p);
    Display(p_smartPtr.get()); // get is called to get the raw pointer from the smart pointer
    // Store(p_smartPtr); // error as copy of the unique pointer is not allowed
    Store(std::move(p_smartPtr)); // ownership is transferred to the Store function
    delete p;

}

int main()
{
    Operator(5);
}

// Unique pointer has explicit constructors, hence we cannot use the assignement operators to iniatize;
// Hence use direct initialisation