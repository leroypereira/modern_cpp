/**
 * Unordered containers
 * Associative containers implemented as hash tables
 * Values are hashed and stored in undefined order
 * Fast search, insertion/deletion but may degrade over a period of time
 * unordered_set stores values that act as keys for hashing
 * undorderer_map stores pairs (first is used to compute hash)
 * 
 * When load factor increases, table is rehashed and more keys are attached to the bucket
 * 
 * Elements are not sorted inside the container
*/

#include <iostream>
#include <unordered_set>

void unSet()
{
    std::unordered_set<std::string> coll;
    coll.insert("Leroy");
    coll.insert("Pereira");
    coll.insert("Francisco");

    for(auto x: coll )
    {
        std::cout<<x<<std::endl;
    }

    std::cout << "Bucket Count: "<< coll.bucket_count() << std::endl;
    std::cout << "Size: "<< coll.size() << std::endl;
    std::cout << "Load Factor: "<< coll.load_factor() << std::endl;
}

int main()
{ 
    unSet();
    return 0;
}