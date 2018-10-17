/**
 * @name Jeremy Roa
 * @date 15/10/2018
 * @brief Metodo de Ordenamiento por seleccion con recursividad
*/
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
void selection_sort(int size,int i, int j,T*container,int m,const Compared & a = Compared()){
    if(a(container[j],container[m])){
        m = j;
        return selection_sort(size,i,++j,container,m);
    }
    if(size == (1+j)){
        std::swap(container[m],container[i]);
        ++i;
        return selection_sort(size,i,1+i,container,i);
    }
    if((i+1) == size)
        return;
    return selection_sort(size,i,++j,container,m);
}
int main()
{
    Compare a;
    int *r = new int[10];
    for(int i = 0;i < 10;i++){
        r[i] = i+1;
    }
    r[5] = 0;
    selection_sort(10,0,1,r,0);
    assert(is_sorted(10,0,r));
    delete [] r;
    return 0;
}