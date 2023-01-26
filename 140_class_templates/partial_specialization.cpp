#include <iostream>
#include <vector>
//In explicit specialization, all the tempalate parameters are specialized,
// In partial specializetion, only some parameters are specialized
// partial specialization allows you to partially specialize the class based on certain
// arguements of the template class
// smart pointers in the std libray use partial specialization for array types
template<typename T, int columns>
class PrettyPrinter{
    T * m_pData;
public:
    PrettyPrinter(T * data): m_pData(data){

    }

    void Print()
    {
        std::cout<<"Coloumns: "<<columns<<std::endl;
        std::cout<<"{ "<<*m_pData<<" }"<<std::endl;
    } 

    T * GetData()
    {
        return m_pData;
    }
};

template<typename T>
class PrettyPrinter<T, 80>
{
    T * m_pData;
public:
    PrettyPrinter(T * data): m_pData(data){

    }

    void Print()
    {
        std::cout<<"Using 80 columns"<<std::endl;
        std::cout<<"{ "<<*m_pData<<" }"<<std::endl;
    } 

    T * GetData()
    {
        return m_pData;
    }
};


int main()
{
    int val1 = 3;
    PrettyPrinter<int, 80> p1(&val1); // invoked the partially specialized class
    p1.Print();
    return 0;
}