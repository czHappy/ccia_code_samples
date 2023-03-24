#include <exception>
#include <stack>
#include <mutex>
#include <memory>
#include <iostream>
#include <thread>
struct empty_stack: std::exception
{
    const char* what() const throw()
    {
        return "empty stack";
    }
    
};

template<typename T>
class threadsafe_stack
{
private:
    std::stack<T> data;
    mutable std::mutex m;
public:
    threadsafe_stack(){}
    threadsafe_stack(const threadsafe_stack& other)
    {
        std::lock_guard<std::mutex> lock(other.m);
        data=other.data;
    }
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }
    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }
    void pop(T& value)
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        value=data.top();
        data.pop();
    }
    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};
// 一个线程放数字
threadsafe_stack<int> si;
void push_num(){
    for(int i=0; i<20; i++) {
        si.push(i);
        // std::cout<<"push: "<<i<<std::endl;
    }
}
void pop_num(){
    for(int i=0; i<20; i++) {
        int x;
        si.pop(x);
        // std::cout<<"pop: "<<x<<std::endl;
    }
}


// 一个线程取数字
int main()
{
    
    si.push(5);
    si.pop();
    for(int i=0; i<10; ++i) si.push(i);
    while(!si.empty())
    {
        int x;
        si.pop(x);
        std::cout<<x<<std::endl;
    }
    std::thread t1(push_num);
    std::thread t2(pop_num);

    t1.join();
    t2.join(); //当pop空的时候抛出异常
    return 0;
}
