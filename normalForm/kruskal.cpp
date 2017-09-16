#include <iostream>
using namespace std;
const int maxn = 1e5;
int fa[maxn];

int findset(int x){
    if(fa[x] == x) return fa[x];
    return fa[x] = findset(fa[x]);
}

struct Edge{
    int u, v, w;
    friend bool operator < (Edge a, Edge b){
        return a.w < b.w;
    }
}e[2 * maxn];

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 1; i <= n; ++i)
        fa[i] = i;


    for(int i = 0; i < m; ++i)
        cin>>e[i].u>>e[i].v>>e[i].w;

    sort(e, e + m);
    for(int i = 0; i < m; ++i){
        int x = findset(e[i].u);
        int y = findset(e[i].v);
        if(x != y){
            fa[x] = y;
            cout<<"Connect "<<e[i].u<<" and "<<e[i].v<<endl;
        }
    }
    return 0;
}
