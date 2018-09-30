#include <iostream>

#include "ThreadPool.h"

extern "C" __attribute__ ((visibility("default"))) void initFunction()
{
  ThreadPool * x = new ThreadPool(3);

  std::cout << "Threadpool Initialized!" << std::endl;

  delete x;

  std::cout << "Threadpool Destroyed!" << std::endl;
}
