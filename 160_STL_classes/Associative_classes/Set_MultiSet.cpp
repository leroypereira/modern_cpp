/**
 * std::set
 * Implemented as a binary tree
 * Elements are stored in a sorted order
 * Value acts as a key
 * Fast search
 * No random access
 * elements cannot be modified directly
 * 
 * By default set uses the comparator less than to sort the elements
 * in ascending order
 * To sort the elements in descending order, use the comparator greater
 * 
 * Set doesnt allow duplicates,
 * 
 * If duplicates are required, it is preferable to use multiset
*/

#include <iostream>
#include <set>
#include <functional>

void Set()
{   
    // Type, comparator and allocator
    std::set<int, std::greater<int>> s{8, 2, 0, 9, 5};

    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(3);

    auto itr = s.begin();
    while(itr != s.end())
    {
        std::cout<< *itr++ << " ";
    }
    s.erase(0);// Erases based on value, the value is the key
    s.erase(s.begin());
    itr = s.find(9);
    if(itr != s.end())
    {
        std::cout<<"\nElement Found\n";
    }
    else
    {
        std::cout<<"\nElement Not Found\n";
    }
}

void MultiSet()
{   
    // Type, comparator and allocator
    std::multiset<int, std::greater<int>> s{8, 2, 0, 9, 5};

    s.insert(1);
    s.insert(3);
    s.insert(3);
    s.insert(3);

    auto itr = s.begin();
    while(itr != s.end())
    {
        std::cout<< *itr++ << " ";
    }
    s.erase(0);// Erases based on value, the value is the key
    s.erase(s.begin());
    itr = s.find(9);
    if(itr != s.end())
    {
        std::cout<<"\nElement Found\n";
    }
    else
    {
        std::cout<<"\nElement Not Found\n";
    }
}

int main()
{
    Set();
    // MultiSet();
    return 0;
}