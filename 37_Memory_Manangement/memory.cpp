#include <iostream>

int main()
{
    int *p = new int{1};
    std::cout<<*p<<std::endl;
    delete p;

    int *arr = new int[5]{1,2,3,4,5};
    for(int i=0; i<5; ++i)
    {
        std::cout<<arr[i]<<std::endl;
    }
    delete [] arr; 

    // 2D array
    int *p1 =  new int[3];
    int *p2 = new int[3];

    int **pData = new int *[2];
    pData[0] = p1;
    pData[1] = p2;

    delete [] p1;
    delete [] p2;
    delete [] pData;
    
    return 0;
}