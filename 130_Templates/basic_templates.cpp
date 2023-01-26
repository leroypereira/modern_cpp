/**
 * Templates are used for generic programming i.e you can write code that is conformant to different datatypes
 * Use 
 * template<typename T> 
 * T function(T arg){
 * //implementation
 * }
 * to define a templated parameter
 * If the template is not invoked, then the compiler doesn't generate the definitions of the function.
 * The compiler determines the type of T at compile time( arguement deduction) and instantiates it with the appropriate type. 
 * Hence no runtime costs are involved templates leads to high performance code.
 * The compile time deduction can be overriding by specifing the type in code
 * eg. Max<int>(3,5)
 * 
 * Template Instantiation
 *  Templates act as a blueprint, which the compiler generates code from the blueprint at compile time
 *  Instantiation occurs during
 *      - a function template is invoked
 *      - taking address of a function template
 *      - using explicit instantion
 *      - creating explicit specialization
 * Templates are always defined in the header file
*/


#include <iostream>

template<typename T>
T Max(T x, T y)
{
    std::cout<<typeid(T).name()<<std::endl;
    return x > y? x : y;
}
template char Max(char x, char y); // explicitly instantiate the Max function for character type

int main()
{
    auto num1 = Max(3, 5); // function template is invoked
    auto num2 = Max(3.3f, 5.8f);
    auto num3 = Max<float>(3, 5.8f);

    int (*pFn)(int, int) =  Max; // address of the max for integer types
    std::cout<<num2<<std::endl;
    return 0;
}