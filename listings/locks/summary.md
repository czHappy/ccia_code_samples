### mutex
- 互斥量
    ```c++
    m.lock();
    ...// 被保护的代码
    m.unlock();
    ```

### std::lock_guard
- template <class Mutex> class lock_guard;
- A lock guard is an object that manages a mutex object by keeping it always locked. On construction, the mutex object is locked by the calling thread, and on destruction, the mutex is unlocked. It is the simplest lock, and is specially useful as an object with automatic duration that lasts until the end of its context. In this way, it guarantees the mutex object is properly unlocked in case an exception is thrown.
- RAII


### std::lock
- template <class Mutex1, class Mutex2, class... Mutexes>  void lock (Mutex1& a, Mutex2& b, Mutexes&... cde);
- Locks all the objects passed as arguments, blocking the calling thread if necessary. The function locks the objects using an unspecified sequence of calls to their members lock, try_lock and unlock that ensures that all arguments are locked on return (without producing any deadlocks). If the function cannot lock all objects (such as because one of its internal calls threw an exception), the function first unlocks all objects it successfully locked (if any) before failing.

### std::scoped_lock
- C++17支持，相当于std::lock_guard扩展到一次性锁多个互斥量，std::scoped_lock guard(lhs.m,rhs.m);并且像std::lock_guard一样支持RAII
### std::adopt_lock
- adopt_lock_t
- 之前已经上锁了，构造时不再上锁
### std::try_to_lock
- try_to_lock_t
- 尝试获得互斥的所有权而不阻塞
### std::defer_lock
- defer_lock_t
- 之前还没有上锁，创建时也暂时不上锁


### std::unique_lock
- template <class Mutex> class unique_lock;
- C++11中的unique_lock使用起来要比lock_guard更灵活，但是效率会第一点，内存的占用也会大一点。同样，unique_lock也是一个类模板，但是比起lock_guard，它有自己的成员函数来更加灵活进行锁的操作。
  - lock_guard不能复制也不能移动，unique_lock可以移动，不可以复制。
  - std::lock_guard只有构造函数和析构函数。简单的来说：当调用构造函数时，会自动调用传入的对象的lock()函数，而当调用析构函数时，自动调用unlock()函数；而unique_lock有自己的成员函数lock unlock，unique_lock可以实现延时锁，随处加锁，多次加锁，并且也可以RAII自动释放锁。
  - unique_lock可以从函数返回传入到另外一个函数

