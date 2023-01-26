#include <iostream>


void DynArray()
{
    // here the default deleter of the unique pointer will call delete and delete[].
    // this will no free up the entire memory
    std::unique_ptr<int> p1{new int[5]{1,2,3,4,5}};
    // p[0] = 10; // not allowed as []operator is not overloaded by smart pointer
    p1.get()[0] = 10; 

    // partial specialisation for array types
    // operator [] is overloaded and the deleter is defaulted to invoke delete []
    // avoid using dynamic array at runtime, use a container like vector
    std::unique_ptr<int[]> p2{new int[5]{1,2,3,4,5}};
    p2[1] = 2;
}

class Point{
public:
    Point(int x, int y)
    {

    }
};

int main() {
    
    {
        // smart pointers provide global functions to allocate memory without making calls to new and delete 
        std::unique_ptr<int> ptr {new int{5}};

        auto p = std::make_unique<int>(5); // automatically create memory on heap and initialise it with the value
        // make unique is a variadic function template. i.e it can accept arbitiry type and multiple arguements
        auto point = std::make_unique<Point>(3,5);

        auto pArr = std::make_unique<int[]>(5); // here 5 is size of the dynamic array. 
        // make_unique doesnt allow you to intialise the dynamic array.
        // however the dynamic array can be initialised using [] operator
        pArr[0] = 10;
    }

    {
        // smart pointers provide global functions to allocate memory without making calls to new and delete
        // make_shared has knowledge of the internals of the shared pointer, it allocated memory for both the resource
        // and the underlying control block using one new call. 
        // during destruction, only one delete is called to delete both the resource and control block.
        // this saves the number of calls to delete and new.
        // make functions dont allow for a custom deleter.
        // if a custom deleter is required, used the new and delete
        std::unique_ptr<int> ptr {new int{5}};

        auto p = std::make_shared<int>(5); // automatically create memory on heap and initialise it with the value
        // make shared is a variadic function template. i.e it can accept arbitiry type and multiple arguements
        auto point = std::make_shared<Point>(3,5);

        auto pArr = std::make_shared<int[]>(5); // here 5 is size of the dynamic array. 
        // make_shared doesnt allow you to intialise the dynamic array.
        // however the dynamic array can be initialised using [] operator
        pArr[0] = 10;
    }

}