#include <iostream>

using namespace std;

const int maxn = 1e3 + 10;
int fa[maxn];

int find(int x){
    if(fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}

void bing(int a, int b){
    int t1 = find(a);
    int t2 = find(b);
    if(t1 != t2)
        fa[t1] = t2;
}

int main(){
    
}