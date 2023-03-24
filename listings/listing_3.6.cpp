#include <mutex>
#include <iostream>
class some_big_object
{
    public:
        some_big_object(int n):num(n){}
        int get_num(){return num;}
    private:
        int num;
};

// void swap(some_big_object& lhs,some_big_object& rhs)
// {
// }

class X
{
private:
    some_big_object some_detail;
    mutable std::mutex m;
public:
    int get_num(){return some_detail.get_num();}
    X(some_big_object const& sd):some_detail(sd){}

    friend void swap(X& lhs, X& rhs)
    {
        if(&lhs==&rhs) return;
        std::lock(lhs.m, rhs.m); //锁住两个锁
        // 没有std::unlock()的用法，所以还是需要用到lock_guard，到析构的时候自动解锁
        std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock);// std::adopt_lock这个标志是个空结构体，仅仅是一个构造函数重载，该构造函数体内不进行上锁
        std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock);
        std::swap(lhs.some_detail, rhs.some_detail);
    }
    // C++17 支持std::scoped_lock
    // void swap(X& lhs, X& rhs){
    //     if(&lhs==&rhs)
    //         return;
    //     std::scoped_lock guard(lhs.m,rhs.m); // 1
    //     swap(lhs.some_detail, rhs.some_detail);
    // }
};

int main()
{
    some_big_object a(1),b(2);
    // swap(a, b);
    // std::cout<<a.get_num()<<" : "<<b.get_num()<<std::endl;
    X x1(a), x2(b);
    swap(x1, x2);
    
    std::cout<<x1.get_num()<<" : "<<x2.get_num()<<std::endl;
    return 0;
}
