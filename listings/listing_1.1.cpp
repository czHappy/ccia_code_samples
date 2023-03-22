#include <iostream>
#include <thread>
#include <string>
void hello(std::string s)
{
    std::cout<<"Hello Concurrent World! <<s<<"\n";
}

int main()
{
    std::thread t(hello);
    t.join();
    std::cout<<"return 0."<<std::endl;
}
