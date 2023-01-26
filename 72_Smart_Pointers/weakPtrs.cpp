#include <iostream>

class Printer{
    int *m_pValue{};
public:
    void SetValue(int *p)
    {
        m_pValue = p;
    }

    void Print() const
    {
        std::cout<<"Value is: "<< *m_pValue<<std::endl;
    }
};

class PrinterShared{
    std::shared_ptr<int> m_pValue{};
public:
    void SetValue(std::shared_ptr<int>& p)
    {
        m_pValue = p;
    }

    void Print() const
    {
        std::cout<<"Value is: "<< *m_pValue<<std::endl;
    }
};

class PrinterWeak{
    std::weak_ptr<int> m_pValue{};
public:
    void SetValue(std::weak_ptr<int> p)
    {
        m_pValue = p;
    }

    void Print() const
    {
        if(!m_pValue.expired()){
            std::cout<<"Value is: "<< *m_pValue.lock()<<std::endl;
            std::cout<<"Ref count: "<< m_pValue.use_count()<<std::endl;
        }
        else
            std::cout<<"Memory has already been released \n";
    }
};

int main()
{
    Printer prn;
    PrinterShared prnShared;
    PrinterWeak prnWeak;
    
    int num{5};
    int *p = new int{num};
    std::shared_ptr<int> pShared {new int{num}};
    std::shared_ptr<int> pSharedWeak {new int{num}};
    std::weak_ptr<int> pWeak = pSharedWeak; // Weak pointer is always intiailised with the shared pointer.
    // the control block of the ptr is destroyed when the weak_ptr is destroyed. This means that you can have multiple weak pointers
    // pointing to the same shared pointer. Hence the control block is only destroyed when the weak count becomes zero.
    // memember function expired is used to check if the reference count and the underlying memory has been destroyed.
    // expired returns true if reference count is zero, and false if the reference count is non zero.
    prn.SetValue(p);
    prnShared.SetValue(pShared);
    prnWeak.SetValue(pWeak);

    // the pointer maybe deleted here (due to some conditions)
    // hence the printer will print some junk values
    if(*p > 4)
    {
        delete p;
        p = nullptr;
        pShared.reset(); 
        pSharedWeak.reset(); 
    }
    // here p has been deleted in the main code, however Printer is unaware that the memory has been
    // deleted. Hence we cant just m_pValue == nullptr in Print()
    prn.Print();
    prnShared.Print(); // pShared memory is not released as prnShared holds a reference.
    prnWeak.Print(); // the shared memory is released, hence it can be verified 

    delete p;
}