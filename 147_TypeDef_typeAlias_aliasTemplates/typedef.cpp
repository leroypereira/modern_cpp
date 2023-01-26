/**
 * Typedef 
 * Introduces a name for an existing type
 * useful to construct a shorter or more meaninful name for existing types;
 * Simplifies declaration of some type (function pointers & templates)
 * Does not introduce a new type, only a new name for a existing type
 * Allows you to create typedefs for function pointers
 * typedefs cannot be templatized
 * 
 * TypeAlias
 *  Creates a name that is synonym of a existing type
 *  Doesnt introduce a new type
 *  Same as typedef declaration
 *  Uses the using keyword
 *  Alias templates are possible (possible to template a typealias)
*/

#include<iostream>
#include<vector>

// typedef
typedef long long LLONG;
LLONG val = 3;

// type alias
using LONG = long long;
LONG val2{};

using vec = std::vector<int>;
vec v1{};

// templated type aliases
template<typename T>
using myVector = std::vector<T>;

int main()
{
    myVector<int> v1{1,2,3,4};
    return 0;
}