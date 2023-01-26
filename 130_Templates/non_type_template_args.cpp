/**
 *  Non type arguements should be constants/ constexpr which can be compiled at compile time
 * If the constant expr is an address, it must be a static address
 * Non type arguements are useful for dealing with arrays in templates
 * Non type arguements are used by the std lib for begin() and end()
*/


#include <iostream>

template <int size>
void Print() {
    char buffer[size];
    // size++;//compile error as size is constant and cannot be modified
    // Hence size can be used to specify size of arrays
    std::cout << size << std::endl;
}

template<typename T>
T sum(T *pArr, int size)
{
    T sum{};
    for(int i=0;i<size; i++)
    {
        sum += pArr[i];
    }
    return sum;
}

// non type arguements are used to specify the types of the array which allow for us to not specify the 
//type when invoking the function
template<typename T, int size>
T ref_sum(T (&arr)[size])
{
    T sum{};
    for(int i=0;i<size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    Print<3>();
    int i1 = 10;
    // Print<i1>(); // compile error
    constexpr auto i2 = 4;
    Print<i2>();


    int arr[]{1,2,3,4};
    std::cout<<"Sum = "<<sum(arr,4)<<std::endl;
    std::cout<<"Sum = "<<ref_sum(arr)<<std::endl;
    
    return 0;
}