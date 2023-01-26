/** 
 * Final keyword can be used to prevent further inheritance of the class.
 * Final keyword can also be added to member functions inorder to prevent it from redefining it in the child class
 * Override function keyword is used by the compiler to check if the function with the same function definition exists within the base class
 * 
 */
#include <iostream>
class Account{
protected: 
    uint32_t mAmount;
public:
    Account(uint32_t amt):mAmount(amt)
    {

    }
    // base class should always have a virtual destructor
    ~Account(){
        std::cout<<"~Account()"<<std::endl;
    }

    virtual void increaseAmt(uint32_t amt){};
    void Print()
    {
        std::cout<<"Balance = "<<mAmount<<std::endl;
    }
};

class Checking final: public Account{
public:
    using Account::Account; 
    void increaseAmt(uint32_t amt) override
    {
        mAmount += amt;
    }

    //compiler will throw an error for the following as a virtual function with this function definition doesn't exist.
    // void increaseAmt(float amt) override
    // {}
    ~Checking(){
       std::cout<<"~Checking()"<<std::endl;
    } 
};

// since this class has been defined as final, we can no longer inherit from this class
class Saving final: public Account{
public:
    using Account::Account;
    void increaseAmt(uint32_t amt) override
    {
        mAmount += amt + 10;
    } 
    ~Saving(){
        std::cout<<"~Saving()"<<std::endl;
    }
};

int main()
{
    // Checking acc(100);
    // Saving ac(1);
    // Transact(&ac);
    Account *acc =  new Saving(100);
    // if the destructor of account was not virtual the destructor of savings is not invoked
    delete acc;
    return 0;

}