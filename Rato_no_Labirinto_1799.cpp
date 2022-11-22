#include <bits/stdc++.h>

using namespace std;

const int IFN = 1e9;
const int MAXN = 4*1e3+5;
int dist[MAXN];
int visitado[MAXN];
vector<int> listAdj[MAXN];

int dijkistra(int s, int t, int n){
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > fila;
    for(int i=0; i<=n; i++) dist[i]=IFN, visitado[i]=0;
    fila.push({0, s});
    dist[s]=0;
    while(!fila.empty()){
        int v = fila.top().second; fila.pop();
        if(visitado[v]) continue;
        visitado[v]=1;
        for(int i=0; i<listAdj[v].size(); i++){
            if(dist[v]+1 < dist[ listAdj[v][i] ]){ // os pesos são todos 1
                dist[ listAdj[v][i] ]=dist[v]+1;
                fila.push({dist[ listAdj[v][i] ], listAdj[v][i]});
            }
        }
    }
    return dist[t];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    map<string, int> ids;
    string u, v;
    int n, m, id=0, a, b;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> u >> v;
        if(ids.find(u) == ids.end()) ids[u]=++id;
        if(ids.find(v) == ids.end()) ids[v]=++id;
        a=ids[u], b=ids[v];
        listAdj[a].push_back(b);
        listAdj[b].push_back(a);
    }
    cout << dijkistra( ids["Entrada"], ids["*"], n ) + dijkistra( ids["*"], ids["Saida"], n) << "\n";
    return 0;
}