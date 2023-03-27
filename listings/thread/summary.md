# thread
## 定义
- std::thread
- Class to represent individual threads of execution. A thread of execution is a sequence of instructions that can be executed concurrently with other such sequences in multithreading environments, while sharing a same address space. An initialized thread object represents an active thread of execution; Such a thread object is joinable, and has a unique thread id.

## 初始化
- default constructor
  - Construct a thread object that does not represent any thread of execution.
- initialization constructor
  - Construct a thread object that represents a new joinable thread of execution. The new thread of execution calls fn passing args as arguments (using decay copies of its lvalue or rvalue references).
- copy constructor
  - Deleted constructor form (thread objects cannot be copied).
- move constructor
  - Construct a thread object that acquires the thread of execution represented by x (if any). This operation does not affect the execution of the moved thread in any way, it simply transfers its handler. The x object no longer represents any thread of execution.

## std::thread::get_id

- If the thread object is joinable, the function returns a value that uniquely identifies the thread.

- If the thread object is not joinable, the function returns a default-constructed object of member type thread::id. (of a non-executing thread)

## joinable
- 定义：`
  - A thread object is joinable if it represents a thread of execution. A thread object is not joinable in any of these cases:
    - if it was default-constructed.
    - if it has been moved from (either constructing another thread object, or assigning to it).
    - if either of its members join or detach has been called.

## 期望

### std::future
- template <class T>  future;
- future对象提供访问异步操作结果的机制，很轻松解决从异步任务中返回结果，thread一般没有返回值，或者通过全局变量接收结果。
- 使用get方法获得结果，当调用此方法后 valid() 为 false ，共享状态被释放，即future对象释一次性的事件。
- 唯一期望(unique futures，std::future<>) std::future的实例只能与一个指定事件相关联。
- 共享期望(shared futures)(std::shared_future<>) std::shared_future的实例就能关联多个事件。
### std::async
- template <class Fn, class... Args>  future<typename result_of<Fn(Args...)>::type>    async (Fn&& fn, Args&&... args);
- template <class Fn, class... Args>  future<typename result_of<Fn(Args...)>::type>    async (launch policy, Fn&& fn, Args&&... args);
- Calls fn (with args as arguments) at some point, returning without waiting for the execution of fn to complete. The value returned by fn can be accessed through the future object returned (by calling its member future::get).
- policy
  - launch::async：立即启动新线程执行
  - launch::deferred：延迟执行直到使用get/wait方法获取future对象状态
  - launch::async|launch::deferred：根据系统自动决定

### std::promise
- template <class T>  promise;template <class R&> promise<R&>;
- promise会做出承诺：我将会有一个T类型的值，future是与promise所关联的未来：将来我会通过set_value方法设定计算后的结果，可以从future那里获得承诺的T类型的结果值。


### std::shared_future
- std::future 模型独享同步结果的所有权，并且通过调用get()函数，一次性的获取数据，这 就让并发访问变的毫无意义——只有一个线程可以获取结果值，因为在第一次调用get()后， 就没有值可以再获取了。std::future 是只移动的，所以其所有权可以在不同的实例中互相传递，但是只有一个实例可以获得特定的同步结果。
- std::shared_future 实例是可拷贝的，所以多个对象可以引用同一关联期望值的结果