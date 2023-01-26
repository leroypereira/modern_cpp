/**
 * Constexpr can be applied to expressions that can evaluated at compile time
 * It increases the performance of the code.
 * Constexpr functions should only return literal types to qualify for a constexpr variable.
 *          Literal types void, scalar types(int float, char), references
 * Constexpr can also behave a normal functions
 * Constexpr shoud accept and return literal types only
 * Constexpr in c++11 can have only 1 return statement, however c++14 has relaxed this rule
 * All constexpr variables are const, but not the other way round
 * Use const keyword to indicate the value cannot be modified
 * Use the constexpr to create expressions that can be evaluated at compile time
*/

#include<iostream>

int GetNumber()
{
    return 42;
}

constexpr int GetConstExprNumber(int i)
{
    return i;
}

constexpr int Add(int x, int y){
    return x+y;
}

int main()
{
    constexpr int i1 = 10; // constexpr evaluated at compile time
    // constexpr int i2 = GetNumber(); // error as it is not a constexpr
    constexpr int i3 = GetConstExprNumber(i1); // error as it is not a constexpr
    int arr[i3];

    const int j = 5; // not all const expressions are evaluated at compille time, though this has been evaluated at compile time
    int arr1[j];

    int x = GetNumber(); 

    constexpr int sum1 = Add(3,5); // behaves like a constexpr
    // constexpr int sum2 = Add(x,5); //error, as it requires a constexpr

    //Behaves like a normal function
    int sum3 = Add(3,2);
    return 0;
}