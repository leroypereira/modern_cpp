/**
 * Double ended queue
 * Efficient for addition and removal from both ends
 * Grows automatically
 * Used to implement queues

*/

#include <iostream>
#include <deque>

void Deque()
{
    std::deque<int> vec{1,2,3,4};

    for(int i=0; i < 5; ++i)
    {
        vec.push_back(i * 10);
        std::cout<<vec.size()<<std::endl;
    }

    for(int i=0; i < 5; ++i)
    {
        vec.push_front(i * 10);
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
    vec.pop_front();
}

int main()
{
    Deque();
    return 0;
}