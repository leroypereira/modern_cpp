#include <string>
#include <iostream>

class Project {
    std::string m_Name;

public:
    void SetName(const std::string &name)
    {
        m_Name = name;
    }
    void ShowProjectDetails() const {
        std::cout<< "[Project Name]" << m_Name << '\n';
    }
};

class Employee{
    std::shared_ptr<Project> m_Project{};
public:
    void SetProject(std::shared_ptr<Project> &prj)
    {
        m_Project = prj;
    }

    // Pass by reference as the inorder to avoid the copy constructor of the unique_ptr which
    // has been deleted
    const std::shared_ptr<Project>& getProject() const{
        return m_Project;
    }
};

void ShowInfo(const std::unique_ptr<Employee>& emp)
{
    std::cout<<"Employee Project details: ";
    emp->getProject()->ShowProjectDetails();
}

int main()
{
    std::shared_ptr<Project> prj{new Project{}};
    prj->SetName("Video Decoder");
    std::unique_ptr<Employee> e1{new Employee{}};
    e1->SetProject(prj);
    std::unique_ptr<Employee> e2{new Employee{}};
    e2->SetProject(prj);
    std::unique_ptr<Employee> e3{new Employee{}};
    e3->SetProject(prj);
    std::cout<<"Reference count of prj: "<<prj.use_count()<<"\n";
    ShowInfo(e3);
    e3.reset();
    if(e3)
    {
        // e3 contains a valid pointer
    }
    else{
        // not valid
    }

    std::cout<<"Reference count of prj: "<<prj.use_count()<<"\n";

    ShowInfo(e1);
    ShowInfo(e2);
    prj->ShowProjectDetails();
}

// the code will crash as the prj has been moved to e1 and hence cannot be used to set in e2.
// Hence the project should be a shared pointer allowing to be shared with other objects
// Inside the shared ptr, a reference count is maintained which is shared with all the copies
// The underlying pointer is deleted when the reference count becomes zero
// The reference count is automatically decremented whenever a object is deleted