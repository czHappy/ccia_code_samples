#include <iostream>
#include <thread>   //线程库
#include <future>
#include <mutex>
#include<numeric>
std::mutex g_display_mutex;
void foo()
{
    std::thread::id this_id = std::this_thread::get_id();
    g_display_mutex.lock();
    std::cout << "thread " << this_id << " sleeping...\n";
    g_display_mutex.unlock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
void threadTest()
{
    std::thread t1(foo);
    std::thread t2(foo);
    t1.join();
    t2.join();
}
int sum(int &x, int &y)
{
    std::cout << std::hex << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return x + y;
}
int sums(int x, int y,int z)
{
    std::cout << "in sums function, t_id = 0x"<<std::hex << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return x + y + z;
}
int main()
{
    int x = 3;
    int y = 4;
    std::cout << "获取主线程ID:"<<std::hex <<std::this_thread::get_id() << std::endl;
    std::future<int> fu = std::async(sums, 3, 4, 5);
    //std::future<int> fu = std::async(sum,std::ref(x),std::ref(y));
    std::cout << fu.get() << std::endl;
    //获取当前计算机线程数量
    std::cout <<"获取当前计算机线程数量:"<< std::thread::hardware_concurrency() << std::endl;
    //获取当前线程ID
    std::cout << "获取当前线程ID:"<<std::hex <<std::this_thread::get_id() << std::endl;
    return 0;
}