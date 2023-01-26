#include <iostream>
#include <string>

const char * Combine(const char *pFirst, const char *pLast)
{
    char *fullName =  new char[20]();
    strcpy(fullName, pFirst);
    strcat(fullName, pLast);
    return fullName;
}

std::string Combine(std::string pFirst, std::string pLast)
{
    return pFirst + pLast;
}

int cStyleStrings(){
    char first[10];
    char last[10];
    std::cin.getline(first,10);
    std::cin.getline(last, 10);

    const char *pFullName = Combine(first, last);
    std::cout<<pFullName<<std::endl;

    return 0;
}

void cppStringFunctions()
{
    std::string s="Hello";
    s = "Hello";

    // access
    s[0] = 'W';
    char c = s[0];

    std::cout << s << std::endl;

    //size
    int len = s.length();

    //Insert and concatenate
    std::string s1{"Hello"}, s2{"World"};
    s = s1 + s2;
    s.insert(6, "World");

    //comparison
    if(s1 == s2)
    {

    }

    //removal
    s.erase();
    s.erase(0,5); // erase first 5 characters

    //search
    if(s.find("World", 0) != std::string::npos)
    {
        //found
    }

    std::string first;
    std::string last;
    std::getline(std::cin, first);
    std::getline(std::cin, last);
    std::string fullName = Combine(first, last);
    std::cout<<fullName <<std::endl;

    // string literals
    using namespace std::string_literals;
    auto sLiteral = "Test"s;

}
int main()
{
    cppStringFunctions();
    return 0;
}