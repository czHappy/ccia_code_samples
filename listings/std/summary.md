
### std::decay
- template <class T> struct decay;
- std::decay是C++11的一个模板类，为我们移除类型中的一些特性，比如引用、常量、volatile，但是不包括指针特性，在头文件type_traits（类型萃取）中。
  - 比如std::decay<const StructTest &>::type var; 
  - 采用std::decay类型萃取之后的变量var的类型是StructTest

### std::mem_fn
- template <class Ret, class T>  /* unspecified */ mem_fn (Ret T::* pm);
- 返回一个成员函数的functor，传入依赖的对象和成员函数所需要的参数来调用

### std::for_each
- Applies function fn to each of the elements in the range [first,last).
- equivalent code
  ```c++
  template<class InputIterator, class Function>
    Function for_each(InputIterator first, InputIterator last, Function fn)
  {
    while (first!=last) {
      fn (*first);
      ++first;
    }
    return fn;      // or, since C++11: return move(fn);
  }
  ```

  ### std::accumulate
  - template <class InputIterator, class T>   T accumulate (InputIterator first, InputIterator last, T init);
  - template <class InputIterator, class T, class BinaryOperation>   T accumulate (InputIterator first, InputIterator last, T init, BinaryOperation binary_op);
  - equivalent code
    ```
    template <class InputIterator, class T>
      T accumulate (InputIterator first, InputIterator last, T init)
    {
      while (first!=last) {
        init = init + *first;  // or: init=binary_op(init,*first) for the binary_op version
        ++first;
      }
      return init;
    }
    ```
### std::distance
- Calculates the number of elements between first and last.
- template<class InputIterator>  typename iterator_traits<InputIterator>::difference_type    distance (InputIterator first, InputIterator last);

### std::call_once
- 函数配合std::once_flag可以实现：多个线程同时调用某个函数，它可以保证多个线程对该函数只调用一次,经常用于延迟初始化