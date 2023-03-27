#include <exception>
#include <future>
#include <iostream>
#include <stdexcept>
#include <thread>

int QueryNumber() {
  // read number
  std::cout << "read number: ";
  int num;
  std::cin >> num;
  // throw exception if none
  if (!std::cin) {
    throw std::runtime_error("no number read");
  }
  return num;
}
void DoSomething(char c, std::shared_future<int> f) {
  try {
    // wait for number of characters to print
    int num = f.get();  // get result of queryNumber()
    for (int i = 0; i < num; ++i) {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      std::cout.put(c).flush();
    }
  } catch (const std::exception& e) {
    std::cerr << "EXCEPTION in thread " << std::this_thread::get_id() << ": " << e.what() << std::endl;
  }
}
int main() {
  try {
    // start one thread to query a number
    std::shared_future<int> f = std::async(QueryNumber);
    // start three threads each processing this number in a loop
    auto f1 = async(std::launch::async, DoSomething, '.', f);
    auto f2 = async(std::launch::async, DoSomething, '+', f);
    auto f3 = async(std::launch::async, DoSomething, '*', f);
    // wait for all loops to be finished
    f1.get();
    f2.get();
    f3.get();
  } catch (const std::exception& e) {
    std::cout << "\nEXCEPTION: " << e.what() << std::endl;
  }
  std::cout << "\ndone" << std::endl;
}