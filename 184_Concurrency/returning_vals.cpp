/**
 * packaged_task is a wrapper to a callable -  member function, function, lamda object
 * specify the signature of the function object that you want to wrap
 * 
 * std::packaged_task blocks the main thread from resumption until the function completes executing
 * packaged_task class doesnt allow copying of its objects, it has to be moved
*/

#include <iostream>
#include <thread>
#include <vector>
#include <future>

int add(int x, int y){
    return x+y;
}

int square(int x){
    return x*x;
}

int compute(const std::vector<int> & data)
{
    using namespace std;
    int sum{};
    for(auto e:data)
    {
        sum += e;
        std::this_thread::sleep_for(1s);
        std::cout<<".";
    }
    return sum;
}

int main()
{
    std::packaged_task<int(int, int)> taskAdd{add};
    //task add is now an alias for the add function
    taskAdd(3,5); // value is not returned, it is returned asynchornisly,
    ///taskAdd will return a future object and the result will be returned through the future object

    std::future<int> ft = taskAdd.get_future();
    std::cout<<"Add result "<<ft.get()<<std::endl;

    std::packaged_task<int(int)> taskSquare{square};
    taskSquare(4);
    std::future<int> ft2 = taskSquare.get_future();
    std::cout<<"Square result "<<ft2.get()<<std::endl;

    std::packaged_task<int (const std::vector<int> &)> taskCompute{compute};
    std::future<int> ftCompute = taskCompute.get_future();
    std::vector<int> data = {1,2,3,4,5};
    std::cout<<"Thread has started"<<std::endl;
    std::thread th{std::move(taskCompute), data};
    th.join();
    std::cout<<"Thread has completed"<<std::endl;
    std::cout<<"Compute result "<<ftCompute.get()<<std::endl;
    return 0;

}

