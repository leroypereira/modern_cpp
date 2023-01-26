/**
 * Variadic templates
 *  - These templates are functions/classes that can accept arbitary number of arguements
 * 
 * Intializer lists can be used to accept arbitary number of args, however intializer list expects that the all the args 
 * are of the same type else it throws a compile error as it fails the template arguement deduction.
 * Variadic templates are used to overcome this.
 * template <typename ...>   ...-> ellipses
 * 
 * To access the individual arguements in the variadic template, you have to use recursion
 * Base case has to be defined for variadic templates.
 * In the case below, PrintVariadic is invoked recursively decreasing the arguements by 1 every time.
 * We need to stop the recursion when the number of arguements become zero;
 * At compile time the compiler will recursively call the PrintVariadic() function with decreasing args
 * ->PrintVariadic(1, 2.5, 3, "4")
 * ->PrintVariadic(2.5, 3, "4");
 * ->PrintVariadic(3, "4");
 * ->PrintVariadic("4");
 * ->PrintVariadic();
 * 
 * Perfect forwarding can be applied here to allow us to use r-value references
*/
#include <iostream>

template <typename T>
void Print(std::initializer_list<T> args)
{
    for(const auto&x:args){
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
}

// base function which is called in the end of the recursion with no arguements
void PrintVariadic()
{
    std::cout<<std::endl;
}
// template parameter pack
// Params is an alias to a pack of template typenames
// Params => template Parameter pack
template <typename T, typename... Params>
// function parameter pack
void PrintVariadic(T &&a, Params&&... args)
{
    // std::cout<<sizeof...(args)<<std::endl; // sizeof variadic args, can be used to determined number of args
    std::cout<<a;
    if(sizeof...(args) != 0)
    {
        std::cout<<",";
    }
    PrintVariadic(std::forward<Params>(args) ...);
}

int main(){
    Print({1,2,3,4,5});
    // Print({1,2,3.3f,4,5});// compile error, as intiializer list cannot handle it
    PrintVariadic(1, 2.5, 3, "4");
    return 0;
}