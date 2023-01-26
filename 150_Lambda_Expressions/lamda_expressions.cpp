/**
 * Lamda expressions
 * -Defines an anonymous function object
 * -Can be passed as an arguement
 * -Can accept parameters and return values
 * - Encapsulates a few lines of code
 * - can replaces function objects
 * - internally implemented as a nameless function object
 * 
 * syntax 
 * lamda        Arguements      
 * introducer
 * []           (<args>)        <mutable><excp specification> -> <return type>
 * {
 * }
 * A typeconversion operator is synthesized by the compiler for a lambda expression.
 * The typeconversion operator returns a function pointer, which points to a static function -> internally invokes the operator().
*/

#include <iostream>

int main()
{
    auto fn = [](){
        std::cout<<"Welcome to lambda expressions"<<std::endl;
    }; // internally implemented as a function object and overloads the operator()
    fn();

    // lambda expression that return void or return the same type as arguements, no need to specify the return type
    auto sum = [](int x, int y) -> int {
        return x+y;
    };

    //c++14 feature, allowing you to specify a generic type in the lambda expression
    auto sum_generic = [](auto x, auto y) -> int {
        return x+y;
    };
    std::cout<<"Sum of 3 and 5 = "<<sum_generic(3,5)<<std::endl;
    return 0;
}