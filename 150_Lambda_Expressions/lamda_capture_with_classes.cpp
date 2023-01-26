/**
 * It is possible to have a lamda expression inside a lamda expression
 * If the lambda expression doesnt specify a capture list, it returns a function pointer.
 * This allows a lambda expression to define function pointers for c functions
*/

#include <iostream>
#include <string>

template<typename T, int size, typename Callback>
void ForEach(T (&arr)[size], Callback operation)
{
    for(int i=0; i<size; ++i)
    {
        operation(arr[i]);
    }
}

class Product{
    std::string name;
    float price;
public:
    Product(const std::string &n, float p): name{n}, price{p}{

    }

    void AssignFinalPrice(){
        float taxes[]{1,2,3};
        float basePrice{price};
        ForEach(taxes,[basePrice, this](float tax){
            float taxedPrice = basePrice * tax/100;
            price += taxedPrice;
        });
    }

    float GetPrice() const{
        return price;
    }
};

int main()
{
    Product p{"Watch", 100};
    p.AssignFinalPrice();
    std::cout<<"Final Price "<<p.GetPrice()<<std::endl;

    [](int x){
        x *=2;
        [](int x){
            std::cout<<x<<std::endl;
        }(x);
    }(2);

    atexit([](){
        std::cout<<"Program is exiting... "<<std::endl;
    });

    return 0;
}