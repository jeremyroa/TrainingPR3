#include <iostream>
#include <algorithm>
#include <vector>
int sumatoria(std::vector<int>&s){
    int size = s.size();
    int o;
    for(int i = 0;i < size; ++i){
        if(i == 0)
            o = s[i];
        else
            o+=s[i];
    }
    return o;
}
int EncontrarCant(int& r,int& cant,std::vector<int>&conjunto){
    int aux = sumatoria(conjunto);
    for(int i = 1; i <= cant;++i){
        if((aux * i) == r){
            return i;
        }
        if((aux * i) > r)
            break;
    }
    return 0;
}
std::vector<int> comparar2(int r, int cant, std::vector<int>& shop, int i, int j){
    if((r < 1) or (r > 20000) or (cant < 1) or (cant > 100) or (i >= cant)){
        std::vector<int>a = {0};
        if(shop[cant-1] == 1){
            a = {1,1};
            return a;
        }
        return a;
    }
    if(shop[cant-1] == 1){
        std::vector<int> d = {1,1};
        return d;
    }
    std::vector<int> a(shop.begin()+i,shop.begin()+j);
    int c = EncontrarCant(r,cant,a);
    if(c != 0){
        std::sort(a.begin(),a.end());
        if(a.size() == 1){
            a.emplace(a.begin(),1);
            return a;
        }
        a.emplace(a.begin(),c);
        return a;
    }
    if(j == cant){
        ++i;
        j = i +1;
        return comparar2(r,cant,shop,i,j);
    }
    return comparar2(r,cant,shop,i,++j);
}

bool b(int a, int b){
    return b < a;
}
int main(){
    std::vector<int> shop;
    int aux,r,cant;
    std::cin >> r;
    std::cin >> cant;
    for(int i = 0; i < cant; i++){
        std::cin >> aux;
        shop.push_back(aux);
    }
    std::sort(shop.begin(),shop.end(),b);

    for(int i = 1; i < cant; i++){
        if(shop[i-1] == shop[i]){
            return 0;
        }
        if((shop[i] < 1) or (shop[i] > 20000))
            return 0;
    }
    auto m = comparar2(r,cant,shop,0,1);
    auto size = m.size();
    if(m.size() == 1)
        return 0;

    for(int i = 0; i < size;i++){
        std::cout << m[i] << " ";
    }

    return 0;
}
