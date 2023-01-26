#include <iostream>

// returns r-value
int Add(int x)
{
    return x+1;
}
// returns l-value
int& multiply2(int& x)
{
    return x;
}
int main()
{
    int x = 1;
    int &&r1= 10; //R-value reference

    //int &&r3 = x; // error: r value cannot bind to a l-value
    const int &ref2 = 3; // const references of l-value to temporary is allowed
    // x is l value
    // 1 is r value
    return 0;
}

/**
 * L value
 *  has a name, 
 *  all variables ar lvalues
 *  can be assigned values
 *  Persists beyond the expression
 *  Functions that return by reference return l-value
 *  Refernce to l-value(called l-value reference)
 * 
 * Rvalue
 *  Does not have a name
 *  R-value is a temporary value
 *  Cannot be assigned value
 *  Does not persist beyond the expression
 *  Functions that return by value return r-value
 *  Reference to r-value (called r-value reference) -  created with && operator, cannot point to l-value, always bind to temporaries
*/