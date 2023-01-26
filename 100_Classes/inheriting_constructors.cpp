/*
Inheritance:
class <child class> : <access modifier> <base class name>
If no access modifier is mentioned, then the default modifier is used
if child is a class , the default access modifer is private
if the child is a struct, the default access modifier is public

Object Contruction
- Constructors execute from base to child : THe initialiser list of the child class has to invoke the constructor of the base class
- Destructors execute from child to base
- Base data members will be a part of child object


Inheriting constructors:
If the base class constructors have to be invoked, there is no need to redefine the constructors in the child class.
*/

// e.g of inheriting constructors
#include <iostream>
class Account{
protected: 
    uint32_t mAmount;
public:
    Account(uint32_t amt):mAmount(amt)
    {

    }

};

class Checking: public Account{
public:
    // if the constructor is not defined it throws an error, however this can be overcomes by inheriting the constructors of Accounts
    // constructors of the base class can be inherited if the child class has no attributes that have to be initialised.
    using Account::Account; // no compile errors
    //Checking(uint32_t amt): Account(amt){}
};

int main()
{
    Checking (100);
}