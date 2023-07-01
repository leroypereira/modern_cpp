/** 
 * Thin wrapper over c-style static array
 * supports iterators
 * provides random access can be used with c functions
 * cannot grow
 * 
 * Array have iterators:
 * Iterators are pointers like objects
 * used to access elements by their position
 * provide overladed operators such as ++, --, *
 * created through begin() and end() functions in all containers
 * End iterators are also used to indicate success or failure of algos
 * 
 * arr.data() is used to get a pointer so that it is backward compatiable 
 * with c style arrays
 */ 
#include <iostream>
#include <array>

void Array()
{
    std::array<int, 3> arr;
    for(int i=0; i<arr.size(); i++)
    {
        arr[i] = i;
    }
    auto itr = arr.begin();
    for(auto x:arr)
    {
        std::cout<<x<<" ";
    }
}
int main()
{
    Array();
    return 0;
}


