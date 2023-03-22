# atomic
## 定义
- std::atomic
- template <class T> struct atomic;
- Atomic Objects of atomic types contain a value of a particular type (T). The main characteristic of atomic objects is that access to this contained value from different threads cannot cause data races (i.e., doing that is well-defined behavior, with accesses properly sequenced). Generally, for all other objects, the possibility of causing a data race for accessing the same object concurrently qualifies the operation as undefined behavior. Additionally, atomic objects have the ability to synchronize access to other non-atomic objects in their threads by specifying different memory orders.
## 作用
- 原子操作std::atomic与互斥量的区别

  - 互斥量：类模板，保护一段共享代码段，可以是一段代码，也可以是一个变量。
  - 原子操作std::atomic：类模板，保护一个变量。

- 为何需要原子操作std::atomic
  - 互斥量保护的数据范围比较大，我们期望更小范围的保护。当共享数据为一个变量时，原子操作std::atomic效率更高。
