#include <iostream>
class Account{
protected: 
    uint32_t mAmount;
public:
    Account(uint32_t amt):mAmount(amt)
    {

    }
    // base class should always have a virtual destructor
    virtual ~Account(){
        std::cout<<"~Account()"<<std::endl;
    }

    virtual void increaseAmt(uint32_t amt){};
    void Print()
    {
        std::cout<<"Balance = "<<mAmount<<std::endl;
    }
};

class Checking: public Account{
public:
    using Account::Account; 
    void increaseAmt(uint32_t amt)
    {
        mAmount += amt;
    }
    void TestFunc2()
    {
        std::cout<<"TestFunc2()"<<std::endl;
    }
    ~Checking(){
       std::cout<<"~Checking()"<<std::endl;
    } 
};

class Saving: public Account{
public:
    using Account::Account;
    void increaseAmt(uint32_t amt)
    {
        mAmount += amt + 10;
    }
    void TestFunc()
    {
        std::cout<<"TestFunc()"<<std::endl;
    } 
    ~Saving(){
        std::cout<<"~Saving()"<<std::endl;
    }
};
/**
 * Here object slicing occurs when the checking/ savings account is casted to the base class
 * We can no longer access TestFunc() of the savings account, inorder to acesss TestFunc(), we need to downcast
 * Downcasting may lead to bugs, for example if a checking object is passed to Transact, it will downcast it Savings
 * and invoke TestFunc(), which is not good
 * Using typeid helps overcoming the issue
 * TypeId is RTTI - runtime type information
 * It allows the type of an object to be determined by the program execution
*/
void Transact(Account *pAcc)
{
    pAcc->increaseAmt(10);
    pAcc->Print();

    // Type id runs at compile time on non polymorphic types
    // type id runs at runtime on polymorphic types
    if(typeid(*pAcc) == typeid(Saving))
    {   
        // Downcasting allows you to access TestFunc of the saving class
        Saving *acc = static_cast<Saving *>(pAcc);
        acc->TestFunc();
    }

    // dynamic cast allows you to directly check the type of the base class
    Checking *acc = dynamic_cast<Checking *>(pAcc);
    if(acc != nullptr)
    {
        acc->TestFunc2();
    }
}
int main()
{
    Checking acc(100);
    Saving ac(1);
    Account parent(2); // this calls neither TestFunc() or TestFunc2()
    Transact(&parent);
    return 0;

}