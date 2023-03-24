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
