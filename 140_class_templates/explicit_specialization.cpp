#include <iostream>
#include <vector>
// explicit specialization is required for the string class
template<typename T>
class PrettyPrinter{
    T * m_pData;
public:
    PrettyPrinter(T * data): m_pData(data){

    }

    void Print()
    {
        std::cout<<"{ "<<*m_pData<<" }"<<std::endl;
    } 

    T * GetData()
    {
        return m_pData;
    }
};

template<>
class PrettyPrinter<char *>{
    char *m_pData;
public:
    PrettyPrinter(char * data): m_pData(data){

    }

    void Print()
    {
        std::cout<<"{ "<<m_pData<<" }"<<std::endl;
    } 

    char * GetData()
    {
        return m_pData;
    }
};
// there is no need to define the entire function, you can define only the function
// that you you want to explicitly specialize
template<>
void PrettyPrinter<std::vector<int>>::Print()
{
    std::cout<<"{ ";
    for(auto &val:*m_pData){
        std::cout<<val<<" ";
    }
    std::cout<<" }"<<std::endl;
}

template<>
void PrettyPrinter<std::vector<std::vector<int>>>::Print()
{
    std::cout<<"{ "<<std::endl;
    for(auto &val:*m_pData){
        std::cout<<"{ ";
        for(auto &i:val){
            std::cout<<i<<" ";
        }
        std::cout<<" }"<<std::endl;
    }
    std::cout<<" }"<<std::endl;
}
// template<>
// class PrettyPrinter<std::vector<int>>{
//     std::vector<int> *m_pData;
// public:
//     PrettyPrinter(std::vector<int> *data): m_pData{data}{

//     }

//     void Print()
//     {
//         std::cout<<"{ ";
//         for(auto &val:*m_pData){
//             std::cout<<val<<" ";
//         }
//         std::cout<<" }"<<std::endl;
//     } 

//     std::vector<int>* GetData()
//     {
//         return &m_pData;
//     }
// };

int main()
{
    int val1 = 3;
    PrettyPrinter<int> p1(&val1);
    p1.Print();
    float val2 = 5.5f;
    PrettyPrinter<float> p2(&val2);
    p2.Print();

    char *p{"Hello World"};
    // PrettyPrinter<char *>p3(p); // if not explicit specialization is mentioned=> compile error, 
    //as the arg becomes T** , i.e a pointer to a ponter
    PrettyPrinter<char *>p3(p); // no compile error with explicit specialization
    p3.Print();

    std::vector<int> v1{1,2,3,4};
    PrettyPrinter<std::vector<int>> p4(&v1);
    p4.Print();

    std::vector<std::vector<int>> v2{{1,2,3,4}, {1,2,3,4}};
    PrettyPrinter<std::vector<std::vector<int>>> p5(&v2);
    p5.Print();
    return 0;
}