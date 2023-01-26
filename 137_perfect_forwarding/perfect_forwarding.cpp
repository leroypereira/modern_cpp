/*rather than defining all the combinations of the constructors in order to make use of move semantics
we use templates
If l-values are passed as arguements => name and id remain as lvalues
if r-values are passed as arguements => name and id remain as r-values references
The above only holds true when the templated constructor are defined as r-value references.
it doesnt hold true if they are defined as l-value references 
The types of the of the templates should be preserved so that they can invoke the appropriate constructors
std::forward allows us to preseve the type and invoke the correct constructors
*/
#include "Integer.h"
#include <iostream>
#include <string>

class Employee {
    std::string m_Name;
    Integer m_Id;
public:
    Employee(const std::string &name, const Integer &id):
        m_Name{name},
        m_Id{id}{
        std::cout<<"Employee(string &, Integer &)"<<std::endl;

    }
    // Move constructor to handle r value references
    // This should invoke the move constructor
    Employee(const std::string &&name, Integer &&id):
        m_Name{name},
        m_Id{std::move(id)}{
        std::cout<<"Employee(string &&, Integer &&)"<<std::endl;
    }

    // Templated member function
    template <typename T1, typename T2>
    Employee(T1 &&name, T2 &&id):
        m_Name{std::forward<T1>(name)},
        m_Id{std::forward<T2>(id)}{
        std::cout<<"Employee(T &&, T &&)"<<std::endl;
    }
};
int main(){
    // Since we have both as r values, the move constructor is invoked
    // Employee emp1{"Umar", 100};
    
    std::string name = "Leroy";
    // Here one is a r value and other a l value -> invokes the copy constructor
    //Employee emp2{name, 100};


    // Employee emp3{"Umar", Integer{100}};

    Integer id{100};
    Employee emp4{std::string{"Leroy"}, id}; 
    // copy constructor of Integer is invoked because the info about the type is preserved by std::forward

    return 0;
}