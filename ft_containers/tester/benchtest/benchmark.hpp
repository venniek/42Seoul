#ifndef _BENCHMARK_HPP_
#define _BENCHMARK_HPP_

#include <ctime>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include "../../map.hpp"
#include "../../stack.hpp"
#include "../../vector.hpp"

class Timer {
 private:
  std::clock_t __start;

 public:
  Timer(void);
  Timer(const Timer& t);
  ~Timer(void);
  Timer& operator=(const Timer& t);

  void start(void);
  std::clock_t stop(void);
};

template <class Map>
std::clock_t map_insert_growing(std::size_t times, Map map) {
  Timer t;
  t.start();
  /* insert & find test */
  for (std::size_t i = 0 ; i < times ; i++) {
    map[i] = true;
    map.find(i);
  }
  /* copy constructor & destructor test */
  {
    Map tmp(map);
  }
  return t.stop();
}


template <class Stack>
std::clock_t stack_insert_growing(std::size_t times, Stack stack) {
  Timer t;
  t.start();
  /* insert test */
  for (std::size_t i =  0 ; i < times ; i++) {
    stack.push(i);
  }
  /* copy constructor & destructor test */
  {
    Stack tmp(stack);
  }
  /* find & erase test */
  for (std::size_t i = 0 ; i < times ; i++) {
    (void)stack.top();
    stack.pop();
  }
  return t.stop();
}

template <class Vector>
std::clock_t vector_insert_growing(std::size_t times, Vector vector) {
  Timer t;
  t.start();
  /* insert & find test */
  for (std::size_t i = 0 ; i < times ; i++) {
    vector.push_back(i);
    (void)vector[i];
  }
  /* copy constructor & destructor test */
  {
    Vector tmp(vector);
  }
  /* erase test */
  vector.erase(vector.begin(), vector.end());
  return t.stop();
}

void benchmark_map(void);
void benchmark_stack(void);
void benchmark_vector(void);

#endif 