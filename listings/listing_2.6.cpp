#include <thread>
#include <utility>
#include <iostream>
class scoped_thread
{
    std::thread t;
public:
    explicit scoped_thread(std::thread t_):
        t(std::move(t_))
    {
        if(!t.joinable())
            throw std::logic_error("No thread");
    }
    ~scoped_thread() //析构函数 自动join RAII
    {
        if(t.joinable()) t.join();
    }
    // void set_join(){ //这里试验一下手动join
    //     if(t.joinable()) t.join();
    // }
    scoped_thread(scoped_thread const&)=delete;
    scoped_thread& operator=(scoped_thread const&)=delete;
};

void do_something(int& i)
{
    ++i;
}

struct func
{
    int& i;

    func(int& i_):i(i_){
        std::cout<<"& i addr = "<<&i<<std::endl;
    }

    void operator()()
    {
        for(unsigned j=0;j<1000000;++j)
        {
            do_something(i);
        }
    }
};

void do_something_in_current_thread()
{
    std::cout<<"do_something_in_current_thread"<<std::endl;
}

void f()
{
    int some_local_state = 0;
    std::cout<<"some_local_state addr = "<<&some_local_state<<std::endl;
    scoped_thread t(std::thread(func(std::ref(some_local_state))));
    // scoped_thread t(std::thread(func(some_local_state)));
    
    do_something_in_current_thread();
    // t.set_join();
    std::cout<<some_local_state<<std::endl; //不join则some_local_state的值是随机的 0-1000000之间
}

int main()
{
    f();
    
    return 0;
}
