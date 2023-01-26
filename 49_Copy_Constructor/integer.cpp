#include "integer.h"

Integer::Integer()
{
    m_pInt = new int{0};
}

Integer::Integer(int val)
{
    m_pInt = new int{val};
}

Integer::Integer(const Integer &obj)
{
    m_pInt = new int(*obj.m_pInt);
}

int Integer::GetValue() const
{
    return *m_pInt;
}

void Integer::SetValue(int val)
{
    *m_pInt = val;
}

#include <iostream>

int main()
{
    int *p1 = new int(5);
    //Shallow copy -  copy the address of the pointer;
    int *p2 = p1;

    //Deep copy -  copy the value at the address of the pointer
    int *p3 = new int(*p1);

    Integer i(5);
    Integer i2(i);
    std::cout<<i2.GetValue()<<std::endl;
    return 0;
}

// Rule of 3
/* If the user has defined any of the following , they have to implement everything else as well
  1. Destructor
  2. Copy constructor
  3. Copy assignment operator*/