#include <iostream>
#include <cassert>

class Compare{
public:
    bool operator () (int& a, int& b){
        return a < b;
    }
};
template<class T,class Compared = std::less<T>>
bool is_sorted(int size,int i,T *container,const Compared & a = Compared()){
    if(a(container[i+1],container[i])){
        return false;
    }
    if(size == (1+i)){
        return true;
    }
    return is_sorted(size,++i,container,a);
}
template<class T,class Compared = std::less<T>>
void InsertionSortR(int size,int i,T *container,int j,const Compared &a = Compared()){
    if(i == size){
        return;
    }
    if((j > 0) and (a(container[j],container[j-1]))){
        std::swap(container[j],container[j-1]);
        return InsertionSortR(size,i,container,--j);
    }
    ++i;
    return InsertionSortR(size,i,container,i);

}
int main(){
    Compare a;
    int *r = new int[10];
    for(int i = 0;i < 10;i++){
        r[i] = i+1;
    }
    r[5] = 0;
    InsertionSortR(10,1,r,1);
    assert(is_sorted(10,0,r));
    delete [] r;

    return 0;
}