/**
 * std::thread
 * - Accepts a callable as a constructor arguement
 * - The callable is executed in a separate thread
 * - The constructor does not wait for the thread to start, it returns immediately
 * 
 * 
 * - join is used to wait for the second thread to complete.
 * -.detach() is use to detach the second thread
 * -.joinable() is use to check if the second thread is joinable
 * 0 Detached thread can never be made joinable again
 * 
 * The constructor of the thread function is a variadic function, hence the arguemnts of the 
 * thread object can be specified as parameters of the constructions to the thread object
 * 
 * std::ref is used to pass objects as references to function
 * std::cref is used to pass user defined objects as const references to a function
*/

#include <iostream>
#include <thread>
#include <list>

std::list<int> g_Data;
const int SIZE = 500000;

class String
{
public:
    String()
    {
        std::cout << "String()" << std::endl;
    }

    String(const String &)
    {
        std::cout<<"String(const String&)" <<std::endl;
    }

    String& operator=(const String&) {
        std::cout<<"operator=(const String&)"<<std::endl;
        return *this;
    }

    ~String(){
        std::cout<<"~String()" <<std::endl;
    }
};

void downloadFile(String const& file)
{
    // std::cout<<"[Downloader]Starting download "<<file<< std::endl;
    for(int i=0; i<SIZE; ++i)
    {
        g_Data.push_back(i);
    }
    std::cout<<"[Downloader]Finished download"<<std::endl;

}
int main()
{
    String file;
    std::cout<<"[main]User started an operation"<<std::endl;
    std::thread thDownloader(downloadFile, std::cref(file));
    thDownloader.detach();
    std::cout<<"[main]User started another operation"<<std::endl;
    if(thDownloader.joinable())
        thDownloader.join();
    system("Pause");
    return 0;
}