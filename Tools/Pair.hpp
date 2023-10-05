#ifndef Pair_hpp
#define Pair_hpp

#include <stdlib.h>
#include <stdbool.h>
#include <Arduino.h>
#include <Vector.h>

template<typename T1, typename T2>
class Pair {
  public:
  	Pair(T1 key, T2 value): Key(key), Value(value) {};
  	T1 Key;
    T2 Value;
};

#endif /* Pair_hpp */