#include <iostream>

class Integer{
    int m_Value{0};

public:
    Integer() = default; // The compiler will not automatically generate the default constructor since 
    // the parameterised constructor is present
    // With the default keyword the compiler will automatically generate the default constructor
    // {
    //     m_Value = 0; // since the constructor is doing trivial, intialization of the variable is areadly done
    // }

    Integer(int value){
        m_Value = value;
    }

    Integer(const Integer &) = delete; // deletes the Default copy constructor

    void SetValue(int value)
    {
        m_Value = value;
    }
    void SetValue(float) = delete;
};

int main()
{
    Integer i1;
    //Integer i2(i1); // throws an error as the default copy constructor is deleted
    i1.SetValue(5);
    //i1.SetValue(5.5f); // throws an error as the setValue with float has been deleted
    return 0;
}