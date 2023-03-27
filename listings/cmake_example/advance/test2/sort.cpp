#include <iostream>
#include "sort.h"

int main(){
    
	std::vector<int> arr1 = {1,2,5,4,3,-1,0};
	select_sort(arr1);
	for(auto x : arr1) std::cout<<x<<", ";
	std::cout<<std::endl;
	
	std::vector<int> arr2 = {1,2,5,4,3,-1,0};
	insert_sort(arr2);
	for(auto x : arr2) std::cout<<x<<", ";
	std::cout<<std::endl;
	

#ifdef DEBUG
    printf("sort test, open debug macro.\n");
#endif

    return 0;
}