#include "iostream"

int main()
{
    auto i=10;
    auto j{10}; // auto init always requires an initialisation
    
    static auto y=2; //auto works with qualifiers;

    /**
     * Auto is good when working with templates and lamda functions
    */

   const int var =10;
   auto var2 = var; // discards the const qualifier
   
   // ensures that the const qualifier is preserved     
   const auto var3 = var;
   auto &var4 = var;
   auto ptr = &var;

   auto list = {1,2,3, 4}; // initialiser list
    return 0;
}