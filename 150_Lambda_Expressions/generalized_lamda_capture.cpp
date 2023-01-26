/**
 * Generalized lambda capture (C++14)
 * - allows creation of new variables in the capture clause
 * - The type of these variables is deduced from the type produced by the expression
 * - These variables must always be initialized
 * Syntax
 *  [var=expression](args)
 *  [&var=expression](args) -> creates a reference
 * 
*/

#include<iostream>
int main()
{
    int x{5};
    auto f = [y=x](int arg){
        return y + arg;
    };

    std::cout<<f(5)<<std::endl;
    return 0;
}