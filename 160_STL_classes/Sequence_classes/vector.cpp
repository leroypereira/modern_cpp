/** 
 * Behaves like a dynamic array
 * grows automatically
 * effieicient for addition and removal at the end
 * Provides random acess
 * Not good for inseration and deletion.
 */ 
#include <iostream>
#include <vector>

void Vector()
{
    std::vector<int> vec{1,2,3,4};

    for(int i=0; i < 5; ++i)
    {
        vec.push_back(i * 10);
        std::cout<<vec.size()<<std::endl;
    }
    vec[0] = 100;
    for(auto x:vec)
    {
        std::cout<<x<<" ";
    }

    std::cout<<std::endl;
    // using iterators
    auto itr = vec.begin();
    while(itr != vec.end())
    {
        std::cout<<*itr++<<" ";
    }

    // Functions to delete teh last elements
    vec.erase(vec.end() - 5); //performance issues
    vec.pop_back();

}
int main()
{
    Vector();
    return 0;
}


