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

Integer::Integer(Integer &&obj)
{
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

int Integer::GetValue() const
{
    return *m_pInt;
}

void Integer::SetValue(int val)
{
    if(m_pInt== nullptr)
        m_pInt = new int{};
    *m_pInt = val;
}

Integer Add(const Integer& a, const Integer &b)
{
    Integer temp;
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;
}

#include <iostream>

int main()
{
    Integer a{1}, b{3};
    a.SetValue(Add(a,b).GetValue());

    auto c{a}; // copy constructor is invoked
    auto d{std::move(a)}; // move constructor is invoked
    return 0;
}

/**
 * Copy semantics:
 *  We have to assign a memory to object in order to perform a deep copy,
 *  If we do a shallow copy we would copy the address of the pointer of the object passed to the 
 *  constructor will be copied, hence when the original object is deleted, it would result in a dangling pointer.
 *  We need to perform a deep copy by assigning new memory. This is called copy semantics.
 * 
 * Move semantics:
 *  Rather than assigning memory to a object, we assign the pointer of the object passed to the constructor to a nullptr
 *  and we copy the address of the pointer to the current object. In this case, when the old object is deleted, the destructor will 
 *  be called on a nullptr. This is called as move semantics
 * 
 * // Rule of 5
 * If has class has ownership semantics, you must provide a user-define
 *  : Destructor
 *  : Copy constructor
 *  : Copy assignement operator
 *  : Move constructor
 *  : Move assignement operator
 * 
 *  // Rule of 0
 * If the class has no ownership semantics, all the 5 constructors are defined by the compiler by default.
 * 
 * // Copy elision
 * Integer a = 3; // compiler can expand it as Integer a = Integer(3); // Temporary object is created with 3
 * If the Integer class has a parametersied constructor, the compiler will invoked the parametersied constructor with 3;
 * here the compiler has performed copy elision by omitting the copy constructor. 
 * Use -f-noelide-constructors to turn off copy elision.
 * In move elision, the move constructor is omitted.
 * 
 * // std::move
 * std::move is always used with l-values; It forces the compiler to use the move semantics instead of the copy semantics
 * Once std::move is called on a object, dont read from it as it is in unspecified state. However it is possible to reinitialise it and reuse it
 * A class with non-copyable members should use only move and not be copied
*/
