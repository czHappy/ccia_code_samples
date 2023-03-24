#include <thread>

void do_something(int& i)
{
    ++i;
}

struct func
{
    int& i;

    func(int& i_):i(i_){}

    void operator()()
    {
        for(unsigned j=0;j<10000000;++j)
        {
            do_something(i);
        }
    }
};


void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    my_thread.detach(); //分离线程在局部变量销毁后，仍对该变量进行访问
}

int main()
{
    oops();
    return 0;
}

/**
 * @brief 
 * 
 * 分离线程在局部变量销毁后，仍对该变量进行访问,容易出错
 * 
 */