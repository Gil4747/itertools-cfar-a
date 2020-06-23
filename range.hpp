#ifndef Range
#define Range

#include <iostream>
#include<stdio.h>
#include <iterator>
#include <type_traits>

namespace itertools{

class range{

    int start;
    int End;

public:

 range(int a,int b){
     if(a!=b){
        start=a;
        End=b;
     }
     else{
         a=0;
         b=0;
     }
    }
  range(const range &other){
     start=other.start;
     End=other.End;
    }
    
class iterator{
    friend class range;
    int cur;
    
    public:

    iterator(int x) :cur(x) {}

    iterator(const iterator& other) : cur(other.cur) {}
    
    iterator& operator++(){
        ++cur;
        return *this;
    }
    iterator operator++(int){
        iterator temp(cur);
        cur++;
        return temp;
    }
    bool operator==(const iterator& other){
        return cur==other.cur;
    }
    bool operator!=(const iterator& other){
        return !(cur==other.cur);
    }
     int operator*() { return cur; }

    iterator& operator=(iterator& other){
        return other;
    }
    
};

iterator begin(){
    return iterator(start);
}
iterator end(){
    return iterator(End);
} 

typedef int	value_type;

};

};

#endif