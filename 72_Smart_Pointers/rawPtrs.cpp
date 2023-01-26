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
    Project *m_Project{};
public:
    void SetProject(Project *prj)
    {
        m_Project = prj;
    }

    const Project  * getProject() const{
        return m_Project;
    }
};

void ShowInfo(Employee const * emp)
{
    std::cout<<"Employee Project details: ";
    emp->getProject()->ShowProjectDetails();
}

int main()
{
    Project *prj = new Project{};
    prj->SetName("Video Decoder");
    Employee *e1 = new Employee{};
    e1->SetProject(prj);
    Employee *e2 = new Employee{};
    e2->SetProject(prj);
    Employee *e3 = new Employee{};
    e3->SetProject(prj);

    ShowInfo(e1);
    ShowInfo(e2);
    ShowInfo(e3);
    prj->ShowProjectDetails();

    delete e1;
    delete e2;
    delete e3;
    delete prj;
}