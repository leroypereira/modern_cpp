/** Virtual functions
 * The c++ compiler creates an a virtual table for account with an array of function pointers
 * which is called as virutal table. The non virtual funcs don't appear in this table
 * The virtual pointer vptr is added by the compiler , as a member of the class and points to the virtual table.
 * At runttime the compiler accesses the vptr to invoke the child class function incase the function is a virtual function.
 * Virtual inheritance is used in diamond inheritiance to ensure that there is only one function definition from the base class
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
    virtual ~Account(){
        std::cout<<"~Account()"<<std::endl;
    }
    // virtual keyword is used to tell the compiler that the child class will redefine increaseAmt and that the definition of
    // of the child class should be used.
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
 * 
*/
void Transact(Account *pAcc)
{
    pAcc->increaseAmt(10);
    pAcc->Print();
    // Downcasting allows you to access TestFunc of the saving class

    Saving *acc = static_cast<Saving *>(pAcc);
    acc->TestFunc();
}
int main()
{
    Checking acc(100);
    Saving ac(1);
    Transact(&acc);
    Account *pAcc =  new Saving(100);
    // if the destructor of account was not virtual the destructor of savings is not invoked
    delete pAcc;
    return 0;

}