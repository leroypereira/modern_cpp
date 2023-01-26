/**
 * A literal is a fixed value that appears directly in the code
 * Predefined literals in c++ such as 14u, 62l, 9.2f
 * We can also define our own literals in c++
 * 
 * Temperature temp{32} // Fahrenheit or celsius?
 * Temperature temp{32_C} // used defined literal to enforce type
 * 
 *  <return type> operator ""_<literal>(<arguements>)
 *  <arguements >: can be of following types
 *     integer - unsigned long long
 *     floating point - long double
 *     character - char, wchat_t
 *     string - const char *
 * These are the largest possible types for each combination
 * Literal operator functions cannot be member functions, they will always be global functions
 * It is not possible to redefine the meaning of built in literal suffixes
*/


#include <iostream>

class Distance
{
    long double m_Kilometers;
public:
    Distance(long double km): m_Kilometers{km}{

    }
    long double GetKm() const{
        return m_Kilometers;
    }
    void SetKm(long double val)
    {
        m_Kilometers = val;
    }

};

Distance operator ""_mi(long double val)
{
    return Distance{val * 1.6};
}

Distance operator ""_meters(long double val)
{
    return Distance{val/1000};
}

int main()
{
    Distance dist1{32.0_mi};
    Distance dist2{3100.0_meters};
    std::cout<<dist2.GetKm()<<std::endl;
    return 0;
}