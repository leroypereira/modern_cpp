/**
 * Function objects allows you to store states as objects are used.
 * When function objects are used, the compiler is able to inline the call to the comparator function during optimization.
 * This is an advantage over the function pointer, making it faster.
*/

#include <iostream>

template<typename T, int size, typename Comparator>
void Sort(T (&arr)[size], Comparator comp)
{
    for(int i=0; i<size-1; ++i)
    {
        for(int j=0; j<size-1; ++j)
        {
            // if(arr[j] > arr[j+1]){
                if(comp(arr[j], arr[j+1])){
                T temp = std::move(arr[j]);
                arr[j] = std::move(arr[j+1]);
                arr[j+1] = std::move(temp);
            }
        }
    }
}

struct Comparator{
    bool operator()(int x, int y){
        return x>y;
    }
};

int main() {
    int arr[]{1,4,6,2,0};
    for( auto &x: arr)
    {
        std::cout<< x << " ";
    }
    Comparator comp; // object of type comparator
    std::cout<<std::endl;
    Sort(arr, comp);
    for( auto &x: arr)
    {
        std::cout<< x << " ";
    }
    std::cout<<std::endl;
    return 0;
}

/**
 *  Function Object
 *  -  Object with overloaded function call operator
 *  -  can be used as a callback instead of function pointers
 *  - more efficient than function pointers.
 *  - Usually implemented as structs
 *  - Static in nature
 * 
 * Function pointer
 *  - Invoked through a pointer
 *  - Dynamic in nature, can be specified at runtime
 *  - Difficult to optimize
 *  - Slow
 *  - Cannot store the state
 * 
 * 
 * */