#include <list>
#include <algorithm>
#include <iostream>
#include <future>

void show_list(const std::list<int>& l);


template<typename T>
std::list<T> parallel_quick_sort(std::list<T> input)
{
    if(input.empty())
    {
        return input;
    }
    std::list<T> result;
    result.splice(result.begin(), input, input.begin()); //取第一个元素作为pivot，放在result中
    T const& pivot= *result.begin();
    auto divide_point=std::partition(input.begin(),input.end(),
        [&](T const& t){return t<pivot;}); // t<pivot都在前一半 否则在后一半

    std::list<T> lower_part;
    lower_part.splice(lower_part.end(), input, input.begin(),
        divide_point); //前一半放在lower_part input中现在只保留了后一半
    
    // 分治
    std::future<std::list<T> > new_lower(
        std::async(&parallel_quick_sort<T>, std::move(lower_part)));

    auto new_higher = parallel_quick_sort(std::move(input));
    
    // 拼接
    result.splice(result.end(),new_higher);
    result.splice(result.begin(),new_lower.get());
    return result;
}
void show_list(const std::list<int>& l){
    for(auto x : l)
        std::cout<<x<<", ";
    std::cout<<std::endl;
}
int main(){
    std::list<int> l1 = {9, 1,20,3,41,5,-1};
    show_list(l1);
    std::list<int> l2 = parallel_quick_sort(l1);
    show_list(l2);
    return 0;
}
