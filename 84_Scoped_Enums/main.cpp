//scoped enums prevent type conversion as compared to just enums.

#include <iostream>

enum Color: long {
    RED, 
    GREEN, 
    BLUE
    };



void FillColor(Color color)
{
    if(color == Color::RED)
    {
        //paint with red
        std::cout<<"RED"<<std::endl;
    }
    else if (color == Color::GREEN)
    {
        //paint with green
        std::cout<<"GREEN"<<std::endl;
    }
    else if(color == Color::BLUE)
    {
        std::cout<<"BLUE"<<std::endl;
    }
}

enum class TrafficLights: char {RED='c', GREEN, YELLOW};

void FillColorTrafficLights(TrafficLights color)
{
    if(color == TrafficLights::RED)
    {
        //paint with red
        std::cout<<"RED"<<std::endl;
    }
    else if (color == TrafficLights::GREEN)
    {
        //paint with green
        std::cout<<"GREEN"<<std::endl;
    }
    else if(color == TrafficLights::YELLOW)
    {
        std::cout<<"BLUE"<<std::endl;
    }
}



int main()
{
    //FillColor(2); //error integer cannot implicity convert to an enum type
    // FillColor(RED); //no error when the enums are not scoped, however trafficLights has also red and will cause an error
    // FillColor(Color::RED);
    // FillColor(static_cast<Color>(5)); // undefined behaviour
    int x = Color::RED;
    int x = static_cast<int>(TrafficLights::GREEN); // scoped enums dont allow implicity conversion of the enums to literals
    FillColorTrafficLights(TrafficLights::GREEN);
    return 0;
}

// TrafficLights is hiding the RED GREEN from colors enums. This may cause compile error as both are global variabls
// Define Colors as scoped enum using class keyword
// underlying types of scoped enums are int, however we can change the underlying type to be whatever we want using the : <type>