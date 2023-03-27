// #include <iostream>
// #include <thread>   //线程库
// #include <future>
// #include <mutex>
// #include<numeric>
// std::mutex g_display_mutex;
// void foo()
// {
//     std::thread::id this_id = std::this_thread::get_id();
//     g_display_mutex.lock();
//     std::cout << "thread " << this_id << " sleeping...\n";
//     g_display_mutex.unlock();
//     std::this_thread::sleep_for(std::chrono::seconds(1));
// }
// void threadTest()
// {
//     std::thread t1(foo);
//     std::thread t2(foo);
//     t1.join();
//     t2.join();
// }
// int sum(int &x, int &y)
// {
//     std::cout << std::hex << std::this_thread::get_id() << std::endl;
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     return x + y;
// }
// int sums(int x, int y,int z)
// {
//     std::cout << "in sums function, t_id = 0x"<<std::hex << std::this_thread::get_id() << std::endl;
//     std::this_thread::sleep_for(std::chrono::seconds(1));
//     return x + y + z;
// }
// int main()
// {
//     int x = 3;
//     int y = 4;
//     std::cout << "获取主线程ID:"<<std::hex <<std::this_thread::get_id() << std::endl;
//     std::future<int> fu = std::async(sums, 3, 4, 5);
//     //std::future<int> fu = std::async(sum,std::ref(x),std::ref(y));
//     std::cout << fu.get() << std::endl;
//     //获取当前计算机线程数量
//     std::cout <<"获取当前计算机线程数量:"<< std::thread::hardware_concurrency() << std::endl;
//     //获取当前线程ID
//     std::cout << "获取当前线程ID:"<<std::hex <<std::this_thread::get_id() << std::endl;
//     return 0;
// }


// #include <future>
// #include <iostream>
// #include <thread>
// using namespace std;

// int add(int a, int b)
// {
//     cout << "work thread" << this_thread::get_id() << endl;
//     std::this_thread::sleep_for(std::chrono::seconds(3));
//     return a + b;
// }

// int main()
// {
//     cout << "main thread" << this_thread::get_id() << endl;
//     // future<int> result = async(launch::async, add, 2, 3);// 新建线程立即执行 一共耗时3秒
//     future<int> result = async(launch::deferred, add, 2, 3);// 线程的执行就会推迟到std::future.get()方法时才会启动 也没有新建线程 一共耗时3+3=6秒
//     std::this_thread::sleep_for(std::chrono::seconds(3));
//     cout << result.get() << endl;
// }


#include <chrono>
#include <cstdint>
#include <exception>
#include <future>
#include <iostream>
#include <random>
#include <thread>

namespace {
constexpr int kTimes = 10;
}

int DoSomething(char c) {
    std::cout << "DoSomething thread" << std::this_thread::get_id() << std::endl;
  // random-number generator (use c as seed to get different sequences)
  std::default_random_engine dre(static_cast<std::int_fast32_t>(c));
  std::uniform_int_distribution<int> id(10, 1000);
  for (int i = 0; i < kTimes; ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
    std::cout.put(c).flush();
  }
  return static_cast<int>(c);
}

int main() {
  std::cout << "starting func1() in background"
            << " and func2() in foreground:" << std::endl;
  std::cout << "main thread" << std::this_thread::get_id() << std::endl;
  auto func1 = []() { return DoSomething('.'); };
  auto func2 = []() { return DoSomething('+'); };

  // start func1() asynchronously (now or later or never):
  auto result1 = std::async(std::launch::deferred | std::launch::async, std::move(func1));
  // call func2() synchronously (here and now)
  auto result2 = func2();

  auto result = result1.get() + result2;
  std::cout << "\nresult of func1()+func2(): " << result << std::endl;

  return 0;
}