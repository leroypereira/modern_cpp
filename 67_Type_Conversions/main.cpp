#include <iostream>

int main()
{
    int a = 5, b = 2;

    // static cast check for the validity of the casts;
    // it doesn't allow for non valid casting
    float f = static_cast<float>(a)/b;

    // char * p1 = static_cast<char *>(&a); // error as it is not permissible

    // reinterpret cast allows you to cast between types while maintaining qualifiers like const
    char * p2 = reinterpret_cast<char *>(&a); 

    const int x = 1;
    // const cast allows you to drop the qualifiers while reinterpret cast will prevent you from doing so.
    int *p3 = const_cast<int *>(&x);
    return 0;
}