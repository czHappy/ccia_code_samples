#include <functional>
#include <iostream>
 
struct Foo {
    void display_number(int i) {
        std::cout << "number: " << i << '\n';
    }
    int data = 7;
};
 
int main() {
    Foo f;
    auto print_num = std::mem_fn(&Foo::display_number);
    print_num(f, 42);
 
    auto access_data = std::mem_fn(&Foo::data);//专门获取对象中data值的函数
    std::cout << "data: " << access_data(f) << '\n';//传入对象f，即获取f的data值
}
/*
number: 42
data: 7
*/