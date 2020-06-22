#include <iostream>
#include<stdio.h>
#include <iterator>

namespace RangeContiner{
class range{

    int start;
    int end;

    public:

    range(){}

    range(int a,int b){
        start=a;
        end=b;
    }
  range(const range &other){
     start=other.start;
     end=other.end;
    }

    int getStart(){
        return start;
    }

    int getEnd(){
        return end;
    }
    

class Riterator{

    int cur;
    
    public:

    Riterator(int x) :cur(x) {}

    Riterator(const Riterator& other) : cur(other.cur) {}
    
    Riterator& operator++(){
        ++cur;
        return *this;
    }
    Riterator operator++(int){
        Riterator temp(cur);
        cur++;
        return temp;
    }
    bool operator==(const Riterator& other){
        return cur==other.cur;
    }
    bool operator!=(const Riterator& other){
        return !(cur==other.cur);
    }
     int operator*() { return cur; }

    Riterator& operator=(Riterator& other){
        return other;
    }
    
};

Riterator Begin() const{
    return Riterator(start);
}
Riterator End() const{
    return Riterator(end);
} 

};
int main(){
      range A(5,9);
     range::Riterator a= A.Begin();
     range::Riterator b= A.End();

    return 0;
}
}