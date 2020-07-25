#ifndef Range
#define Range

//#include<stdio.h>
//#include <iterator>
#include <type_traits>

namespace itertools{

class range{

    int start;
    int End;

public:
 
 range(int a,int b):start(a), End(b){}
    //  if(a!=b){
    //     start=a;
    //     End=b;
    //  }
    //  else{
    //      start=0;
    //      End=0;
    //  }
    // }
//   range(const range& other){
//      start=other.start;
//      End=other.End;
//     }
    
class iterator{
   
    int cur;
    
    public:

    explicit iterator(int x) :cur(x) {};

    iterator(const iterator& other):cur(other.cur){}

      iterator& operator=(const iterator& other){
        if(this != &other)
         this->cur=other.cur;
        return *this;
    };

    iterator& operator++(){
        ++cur;
        return *this;
    }
    iterator operator++(int){
        iterator temp = *this;
        ++cur;
        return temp;
    }
    bool operator==(const iterator& other) {
        return (cur == other.cur);
    }
    bool operator!=(const iterator& other ) {
        return (cur != other.cur );
    }
     int operator*() { return cur; }
    
};

iterator begin(){
    return iterator(start);
}
iterator end(){
    return iterator(End);
} 
  typedef int      value_type;
};

}

#endif
