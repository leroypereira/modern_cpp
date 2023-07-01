/**
 * Implemented as binary tree
 * stores a pair that contains a key and value
 * elementes are stored in sorted order based on a key
 * fast search
 * no random access
 * 
 * If no value exists the key value when accessing using the 
 * [] operator then a key is inserted into the map;
 * 
 * Map does't allow for duplicate keys to be inserted into a map
 * Multimap allows duplicate keys to be stored
*/
#include <iostream>
#include <map>
#include <string>
// Key, value, comparator, allocator

void Map()
{
    std::map<int, std::string> m{
        {1, "Superman"},
        {2, "Spiderman"},
        {3, "Batman"}
    };
    m.insert(std::make_pair(8, "Aquaman"));

    m[0] = "Dummy";
    m.erase(1);
    auto itr = m.begin();
    for(auto x:m)
    {
        // std::cout<<itr->first << ":" << itr->second << std::endl;
        std::cout<<x.first << ":" << x.second << std::endl;
    }

    itr = m.find(2);
    if(itr != m.end())
    {
        std::cout<<"Found:" << itr->second << std::endl;
    }
    else{
        std::cout<<"Not Found" << itr->second << std::endl;
    }

    std::multimap<int, std::string> multiM{
        {1, "Superman"},
        {2, "Spiderman"},
        {3, "Batman"}
    };
    multiM.insert(std::make_pair(1,"Flash"));

    auto found  = multiM.equal_range(1);
    while(found.first != found.second)
    {
        std::cout<<found.first->first << ":" << found.first->second << std::endl;
        found.first++;
    }
}

int main()
{
    Map();
    return 0;
}