// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
 
void foo() 
{
  // do stuff...
  std::cout<<"foo!"<<"here"<<std::endl;
}

void bar(int x)
{
  // do stuff...
  std::cout<<"bar"<<x<<std::endl;
}
void thread_join(){
  //do nothing
}
int thread_return(int x){
  return x + 1;
}
void increase(int& x){
  for(int i=0; i<10; ++i) x++;
}

class X
{
public:
  void do_lengthy_work(int x){
    std::cout << "x = "<<x<<"\n";
  }
};



int main() 
{
  std::thread first(foo);     // spawn new thread that calls foo()
  std::thread second(bar, 999);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";
  std::thread::id first_id = first.get_id();
  std::thread::id second_id = second.get_id();

  std::cout << "first id: " << first_id << '\n';
  std::cout << "second id: " << second_id << '\n';

  
  
  // synchronize threads: 主线程在这里等待子线程结束
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  // 主线程不干预子线程
  // first.detach();                // pauses until first finishes
  // second.detach();               // pauses until second finishes
  std::cout << "foo and bar completed.\n";


  std::thread third;
  std::thread::id third_id = third.get_id();
  std::cout << "before starting third, joinable: " << third.joinable()<<" id = "<<third_id << '\n';
  third = std::thread(thread_join);
  third_id = third.get_id();
  std::cout << "after starting third, joinable: " << third.joinable()<<" id = "<<third_id << '\n';
  
  third.join();

  third_id = third.get_id();
  std::cout << "after ending third, joinable: " << third.joinable() <<" id = "<<third_id<< '\n';

  int x = 0;
  // std::thread last(increase, x); or std::thread last(increase, &x); 都不行
  std::thread last(&increase, std::ref(x)); //加不加&似乎一样 都是表示函数地址
  std::cout <<"addr = "<<(int*)(&increase)<<std::endl;
  std::cout <<"addr = "<<(int*)(increase)<<std::endl;
  last.join();
  std::cout<<x<<std::endl;

  X my_x;
  int num(0);
  std::thread t(&X::do_lengthy_work, &my_x, num); //这里必须对成员函数加& &my_x表示使用的结构体对象 num为线程函数所需要的参数
  t.join();
  return 0;
}

// "<<"这个操作符是线程不安全的，会造成交替打印字符串问题 可以事先构造好字符串或者使用printf

// g++ thread.cpp -o thread -std=c++11  -pthread 