#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=1e5+5;
int n,m;
int dis[maxn];
bool in[maxn]={0};
struct Edge{
    int u,v,w;
    Edge(int uu,int vv,int ww){
        u = uu,v = vv,w = ww;
    }
};

queue<int> que;
vector<Edge> edge;
vector<int> ve[maxn];

void spfaBfs(int s){
    que.push(s);
    in[s] = true;
    dis[s] = 0;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        in[u] = false;
        // u is this node, and find all the node connected with u
        for(int i = 0; i < ve[u].size(); ++i){
            int e = ve[e][i];    // num of the edge
            int v = edge[e].v;   // num of the node

            // tringle principle
            if(dis[u] + edge[e].w < dis[v]){
                dis[v] = dis[u] + edge[e].w;
                if(!in[v]){
                    que.push(v);
                    in[v] = true;
                }
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    fill(dis + 1, dis + n + 1, inf);
    int u,v,w;

    while(m--){
        scanf("%d%d%d",&u,&v,&w);
        edge.push_back(Edge(u,v,w));
        edge.push_back(Edge(v,u,w));
        ve[u].push_back(edge.size()-2);
        ve[v].push_back(edge.size()-1);
    }

    bfs(1);

    cout<<dis[n]<<endl;
    return 0;
}
