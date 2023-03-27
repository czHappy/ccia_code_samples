#include <iostream>
#include <thread>   //线程库


void some_function(){

}
void some_other_function(){

}

int main(){
    std::thread t1(some_function);
    std::thread t2 = std::move(t1); //ok
    t1 = std::thread(some_other_function); //ok

    std::thread t3;
    t3=std::move(t2);//ok 

    t1=std::move(t3);// ops! t1不是空的，不能通过赋值的方法丢弃t1原先存在的线程
    if(t1.joinable()) t1.join();
    if(t2.joinable()) t2.join();
    if(t3.joinable()) t3.join();
    return 0;
}