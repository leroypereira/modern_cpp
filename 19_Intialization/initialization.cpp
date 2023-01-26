
#include <iostream>
class A{
public:
    A() = default;
};
void main()
{
    int a1 = 0; //Copy Initialisation
    int a2; //uinitialised variable

    int a3(5); // Direct Initialisation

    char d1[8] = {'\0'}; // Aggregrate Initialisation
    char d2[8] = {"abcd"}; //Copy Initialisation

    int b1{}; //Value Initialisation
    int b2(); //Most vexing parse
    int b3{5}; // Direct Initialisation

    char e1[8]{};
    char e2[8]{"Direct"};

    char *p1 = new char[8]{};
    char *p2 = new char[8]{"Hello"};

    // A obj1(); // most vexing parse , the compiler thinks this is a function
    A obj2{}; // this defines an object of type A

    int arr[]{1,2,3,4,5};

    // int val1{2.2f};// compiler error, narrowing conversion

    // For Primitive types use assignment
    // for user defined types always use uniform intiialisation

    /*
    Value Initilisation => T{};
    Direct Initialisation => T{v};
    Copy Initialisation => T obj = v;
    */

   /*
   Pro's of uniform initialisation
   1. Prevents narrowing types conversion
   2. It forces intialisation
   3. You can use direct initialisation for arrays
   4. Uniform syntax for all types
   */
}