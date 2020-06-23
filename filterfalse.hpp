#ifndef Filterfalse
#define Filterfalse

#include <iostream>
#include <iterator>
#include <functional>
#include <vector>


namespace itertools{

template<typename T,typename F>
class filterfalse{

T continer;
F func;

public:

filterfalse(T c,F f): continer(c),func(f){}

class iterator{

typename T::iterator start;
typename T::iterator end;
typename T::value_type cur;
F fun;

public:

iterator(const iterator& other) = default;

explicit iterator(typename T::iterator s,typename T::iterator e,F f):start(s),end(e),fun(f){}

iterator(iterator& other){
    if(this!=other){
        start(other.start);
        end(other.end);
        cur(other.cur);
        fun(other.fun);
    }
}
iterator operator==(const iterator& other){
    return (this->start==other.start && this->end==other.end && this->cur==other.cur && this->func==other.func);
}
iterator operator!=(const iterator& other){
    return !(this->start==other.start && this->end==other.end && this->cur==other.cur && this->func==other.func);
}

iterator& operator=(const iterator& other){
    if(this!=&other){
    start(other.start);
    end(other.end);
    cur(other.cur);
    fun=other.fun;
    }
    return *this;
}

auto operator*(){
    return cur;
}
iterator& operator++(){
    typename T::iterator temp(start,end);
    if(start!=end)
    ++start;
    cur=std::for_each(temp,start,fun);
    return *this;
}

iterator operator++(int){
    typename T::iterator temp(start,end);
    if(start!=end)
    ++start;
    cur=std::for_each(temp,start,fun);
    return *this;
}

};

iterator begin(){
    return iterator(continer.begin(),continer.end());
}
iterator end(){
     return iterator(continer.end(),continer.end());
}

};
 
};
#endif