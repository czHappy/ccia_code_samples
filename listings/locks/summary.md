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


### std::share_lock
- C++14增加类shared_lock 是通用共享互斥所有权包装器，允许延迟锁定、定时锁定和锁所有权的转移。shared_lock ，会以共享模式锁定关联的共享互斥，所有接口与std::unique_lock一样，区别就是std::unique_lock属于排他性模式锁定。一个共享一个排他。

- 读写锁也叫做“共享-独占锁”，当读写锁以读模式锁住时，它是以共享模式锁住的；当它以写模式锁住时，它是以独占模式锁住的。当读写锁处于写加锁状态时，在其解锁之前，所有尝试对其加锁的线程都会被阻塞；当读写锁处于读加锁状态时，所有试图以读模式对其加锁的线程都可以得到访问权，但是如果想以写模式对其加锁，线程将阻塞。

### std::shared_mutex
  - c++17
  - std::shared_mutex用于管理可转移和共享所有权的互斥对象，适用场景比较特殊：一个或多个读线程同时读取共享资源，且只有一个写线程来修改这个资源，这种情况下才能从shared_mutex获取性能优势
  - shared_lock是read lock。搭配std::shared_mutex使用，被锁后仍允许其他线程执行同样被shared_lock的代码。lock_guard和unique_lock是write lock。被锁后不允许其他线程执行被lock_guard或unique_lock的代码。
    ```
    typedef std::shared_lock<std::shared_mutex> ReadLock;
    typedef std::lock_guard<std::shared_mutex> WriteLock;
    ```


### std::recursive_mutex 
- A recursive mutex is a lockable object, just like mutex, but allows the same thread to acquire multiple levels of ownership over the mutex object.
- This allows to lock (or try-lock) the mutex object from a thread that is already locking it, acquiring a new level of ownership over the mutex object: the mutex object will actually remain locked owning the thread until its member unlock is called as many times as this level of ownership.


### std::condition_variable
- 条件变量用于某个线程需要在某种条件成立时才去保护它将要操作的临界区，这种情况从而避免了线程不断轮询检查该条件是否成立而降低效率的情况，这是实现了效率提高。在条件满足时，自动退出阻塞，再加锁进行操作
- 条件变量常和互斥锁一起使用，条件变量通过允许线程阻塞和等待另一个线程发送信号的方法弥补了互斥锁的不足。使用时，条件变量被用来阻塞一个线程，当条件不满足时，线程往往解开相应的互斥锁并等待条件发生变化。一旦其它的某个线程改变了条件变量，它将通知相应的条件变量唤醒一个或多个正被此条件变量阻塞的线程。这些线程将重新锁定互斥锁并重新测试条件是否满足。

