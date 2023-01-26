/**
 *  s prints A, which is incorrect, this happens because the addresses of the strings are compared in the Max function
 *  which is incorrect. This is overcomed by using explicit specialization
 * 
 * Explicit Instialization
 *  Template specializer for a particular type 
 *  We can implement a more optimal algorithm for a specific type
 *  Explicitly specialized functions must be defined in a .cpp file to prevent violation of 1 definition rule
*/


#include <iostream>

template<typename T>
T Max(T x, T y)
{
    std::cout<<typeid(T).name()<<std::endl;
    return x > y? x : y;
}

// explicit instantiation
template char Max(char x, char y);

// explicitly specialized template
template<>
const char * Max(const char *x, const char *y)
{
    std::cout<<"Max<const char *>()"<<std::endl;
    return strcmp(x,y)>0?x:y;
}
int main()
{
    const char *b{"B"};
    const char *a{"A"};
    auto s = Max(a,b); 
    std::cout<<s<<std::endl;
    return 0;
}