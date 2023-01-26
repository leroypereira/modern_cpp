/**
 * lambda expressions makes the code more readable as the user can see the functionality within the code
 * capture allows you to access variables either by value or reference
 * If the variable is captured by copy, the variable cannot be modified inside the lambda expression,
 * this is because the lambda function implicity creates an operator void operator()(T &x) const{} 
 * which doesnt allow you to modify the member variables. We can use the keyword mutable to remove the constaness of the 
 * function call operator inside the lamda expression
 * If lambda expression has to capture all the variables in the enclosing scope by reference, just specify a [&] in the capture list 
 * If lambda expression has to capture all the variables in the enclosing scope by value, just specify a [=] in the capture list 
 * The capture list can only capture the variables that are defined before the lambda expression and not the variables that are defined post;
 * Combination of capturing by value and reference is also possible [=offset, &sum]
 * [=] -> enclosing scope variables by value
 * [&] -> enclosing scope variables by ref
 * [=, &var] -> enclosing scope variables by value except var which is capture by reference
 * [&, var] -> enclosing scope variables by reference except var which is capture by value
 * [this] ->captures all member variables
 * 
 * Capture list is only required for local variables, global and static variables are automatically captured
*/
#include <iostream>
#include <string>

template<typename T, int size, typename Comparator>
void Sort(T (&arr)[size], Comparator comp)
{
    for(int i=0; i<size; ++i)
    {
        for(int j=0; j<size; ++j)
        {
            // if(arr[j] > arr[j+1]){
                if(comp(arr[j], arr[j+1])){
                T temp = std::move(arr[j]);
                arr[j] = std::move(arr[j+1]);
                arr[j+1] = std::move(temp);
            }
        }
    }
}

void SortArray()
{
    int arr[]{1,4,6,2,0};
    for( auto &x: arr)
    {
        std::cout<< x << " ";
    }
    std::cout<<std::endl;
    auto comp = [](auto x, auto y) -> bool
    {
        return x>y;
    };

    Sort(arr, comp);
    for( auto &x: arr)
    {
        std::cout<< x << " ";
    }
    std::cout<<std::endl;
}

template<typename T, int size, typename Callback>
void ForEach(T (&arr)[size], Callback operation)
{
    for(int i=0; i<size; ++i)
    {
        operation(arr[i]);
    }
}


int main() {
    // SortArray();
    int arr[]{1,4,6,2,0};
    ForEach(arr, [](auto x){std::cout<< x <<" "; });
    std::cout<<std::endl;

    int offset = 5;
    ForEach(arr, [&offset](auto &x){x+=offset; });
    ForEach(arr, [](auto &x){std::cout<< x <<" "; });
    std::cout<<std::endl;

    int sum{};
    ForEach(arr, [&sum, &offset](auto &x){ sum+=x + offset; });
    std::cout<<"Sum "<<sum<<std::endl;
    return 0;
}