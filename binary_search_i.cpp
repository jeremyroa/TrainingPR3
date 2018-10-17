/**
 * @name Jeremy Roa
 * @date 17/10/2018
 * @brief Busqueda binaria iterando
*/
#include <iostream>
#include <vector>
#include <cassert>
class Compare{
public:
    bool operator () (int a, int b){
        return a < b;
    }
};
bool binary_search(std::vector<int>& cont,int l, int r,const int k,Compare a){
    while(l < r){
        int m = (l+r) / 2;
        if(a(k,cont[m])){
            r = m - 1;
        }
        else if(a(cont[m],k)){
            l = m + 1;
        }
        if(cont[m] == k)
            return true;
    }
    return false;
}
int main(){
    std::vector<int> r;
    for(int i = 0;i < 10;i++){
        r.push_back(i+1);
    }
    assert(binary_search(r,0,(r.size() - 1),3,Compare()));
}