#include <thread>
#include <atomic> 
#include <iostream>
#include <time.h>
 
using namespace std;
// 全局的结果数据 
long total = 0;
 
// 点击函数
void click(){
    for (int i = 0; i < 10000000; ++i){
        // 对全局数据进行无锁访问 
        total += 1;
    }
}
 
int main(int argc, char* argv[]){
    // 计时开始
    clock_t start = clock();
    // 创建3个线程模拟点击统计
    thread th1(click);
    thread th2(click);
    thread th3(click);
    th1.join();
    th2.join();
    th3.join();
    
    // 计时结束
    clock_t finish = clock();
    // 输出结果
    cout << "result:" << total << endl;
    cout << "duration:" << finish - start << "ms" << endl;
    return 0;
}

/*
output:
result:10117323//应该是30000000才对
duration:149293ms 
*/
