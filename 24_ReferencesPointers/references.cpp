#include "iostream"
/**
 * References always require a lvalue. A reference cannot point to a literal
 * however const references can point to a literal
 * const int &ref = 5;// valid
 * int &ref = 5; // not valid
*/
void swap(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}

int main()
{
    using namespace std;
    int a{5};
    int b{10};
    swap(a,b);
    cout<<"a = "<<a<<" b = "<<b<<endl;
    
    // const references
    int x = 5 ;
    const int MAX = 12 ;
    int &ref_x1 = x ;
    const int &ref_x2 = x ;
    ref_x1 = 10;
    // ref_x2 = 15; // throws an error

    const int *ptr3 = &MAX ;
    int *ptr4 = const_cast<int *>(&MAX);
 
    
    return 0;
}