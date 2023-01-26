#include <iostream>

int main()
{
    using namespace std;
    int arr[] = {1,2,3,4,5};

    // for(const auto &i:arr)
    // {
    //     cout<<i<<endl;
    // }

    for(int *ptr= std::begin(arr); ptr!=std::end(arr); ++ptr)
    {
        cout<<*ptr<<endl;
    }
    return 0;
}