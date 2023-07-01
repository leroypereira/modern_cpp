/**
 * Implemented as a two way linked list
 * Efficient for insertion and deletion
 * Does not provide random access
 * Insertion and deletion takes constant time hence preferable
 * 
 * Forward List
 * One way linked list
 * Smaller memory footprint
 * Does not provide support for size
 * Elements are added at the front
*/

#include <iostream>
#include <list>
#include <forward_list>

void List()
{
    std::list<int> vec;
    for(int i=0; i < 5; i++)
    {
        vec.push_back(i * 10);
    }  
    auto iter =  vec.begin();
    while(iter != vec.end())
    {
        std::cout<<*iter++<<" ";
    }
}

void ForwardList()
{
    std::forward_list<int> vec;
    for(int i=0; i < 5; i++)
    {
        vec.push_front(i * 10);
    } // elements are always pushed to the front 


    vec.insert_after(vec.begin(), 100);
    // Inserts elements at the second position as the
    // new node is created at the next node after begin
    auto iter =  vec.begin();
    while(iter != vec.end())
    {
        std::cout<<*iter++<<" ";
    }
}

int main()
{
    ForwardList();
    return 0;
}