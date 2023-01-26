/**
 * In order to generalize the sort function we use a comparator function pointer
 * The comparator is called a predicate, which is used to return a boolean value
 * Disadvantage of using function pointer:
 * 1. since we are passing the comparator as a function pointer, the compiler cannot inline the function as it invoked
 * through its address.
 * 2. They point to global functions. Global functions cannot have a state.However if function objects are used, the state can be stored
*/

#include <iostream>

using Comparator = bool(*)(int, int);

template<typename T, int size>
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

bool comp1(int x, int y)
{
    return x>y;
}

bool comp2(int x, int y)
{
    return x<y;
}
int main() {
    int arr[]{1,4,6,2,0};
    for( auto &x: arr)
    {
        std::cout<< x << " ";
    }
    std::cout<<std::endl;
    Sort(arr, comp2);
    for( auto &x: arr)
    {
        std::cout<< x << " ";
    }
    std::cout<<std::endl;
    return 0;
}