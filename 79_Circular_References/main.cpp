#include <iostream>
class Employee;

class Project{
public:
    // std::shared_ptr<Employee> m_emp;
    std::weak_ptr<Employee> m_emp;
    Project(){
        std::cout<< "Project()"<<std::endl;
    }
    ~Project(){
        std::cout<< "~Project()"<<std::endl;
    }
};

class Employee {
public:
    // std::shared_ptr<Project> m_prj;
    std::weak_ptr<Project> m_prj;

    Employee(){
        std::cout<< "Employee()"<<std::endl;
    }
    ~Employee(){
        std::cout<< "~Employee()"<<std::endl;
    }
};

int main()
{
    std::shared_ptr<Employee> emp{new Employee{}};
    std::shared_ptr<Project> prj{new Project{}};
    emp->m_prj = prj;
    prj->m_emp = emp;

    // destructors of the project and emp are not invoked due to circular references.
    // This results in a memory leak where the underlying reference is not released
    // when the shared pointer of emp and prj are destroyed, the reference count in this ecxample is still 2
    // which is decremented to 1. since the reference count is non zero the underlying memory is not released.
    // circular reference can be overcomed by using a weak pointer.
    // weak pointer dont increment the refernce count. 
    // if the pointers are to be used inside the object, it has to be checked first if it has been expired , if
    // not expired it can be used by putting a lock.
}