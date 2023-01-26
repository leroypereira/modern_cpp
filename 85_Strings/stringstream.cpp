#include <iostream>
#include <sstream>

int main()
{
    int a{4}, b{5};

    int sum = a+b;
    std::cout<<"Sum of "<<a<<" & "<< b << " is: "<<sum<<std::endl;
    std::stringstream ss;
    std::istringstream is; // provides extraction operator
    std::ostringstream os; // provides inseration operator

    ss << "Sum of "<<a<<" & "<< b << " is: "<<sum<<std::endl;
    std::cout<<ss.str()<<std::endl; // enables you to create formated strings

    std::string data = "12 89 21";
    int a1;
    std::stringstream stream;
    stream.str(data);
    while(stream>>a1)
    {
        std::cout<<a1<<std::endl;
    }

    // convert an string to integer
    int x = std::stoi("12");
    
}