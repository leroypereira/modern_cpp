/**
 * Initializer list is used to store a array of objects
 * Intiializer list is commonly used in container classes-> classes that hold other objects;
 * Any class that has a intializer list in its constructor needs to be respectful of the following
 *  - If using uniform intialization on the object, the constructor with the intializer list
 *      has higher precedance than parameterized constructors.
 *       
*/

#include <iostream>
#include <initializer_list>
#include <cassert>
class Bag{
    int arr[10];
    int mSize{};
public:
    Bag(std::initializer_list<int> values)
    {
        std::cout<<"Intializer list"<<std::endl;
        assert(values.size() < 10);
        auto it = values.begin();
        while (it != values.end())
        {
            Add(*it);
            ++it;
        }
    }
    Bag(int val, int val2)
    {
        std::cout<<"Parameterized constructor"<<std::endl;
    }
    void Add(int value)
    {
        assert(mSize < 10);
        arr[mSize++] = value;
    }
    void Remove()
    {
        --mSize;
    }
    int operator[](int index){
        assert(index < 10);
       return arr[index]; 
    }
    int GetSize() const {
        return mSize;
    }
};

int main()
{
    int x{0};
    std::initializer_list<int> data = {1,2,3,4};
    auto values = {1,2,3,4};// initializer list used to intialize values


    Bag b{1,2}; // invokes intializer list constructor
    Bag b2({1, 2, 3});// invokes intializer list constructor
    Bag b3(1,2); // invokes the parameterized constructor
    // b.Add(1);
    // b.Add(2);
    // b.Add(3);

    for(int i=0; i<b.GetSize(); ++i)
    {
        std::cout<<b[i]<<" ";
    }
    std::cout<<std::endl;
    return 0; 
}