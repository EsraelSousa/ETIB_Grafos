#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > listAdj[10005];
int capacidade, qtdOuro[10005];
bool visitado[10005];

int dfs(int v, int p){ // passo como parâmetros o nó a ser visitado e a distância para visitá-lo.
    visitado[v] = 1;
    int ans=0;
    for(int i=0; i<listAdj[v].size(); i++){
        if(visitado[ listAdj[v][i].first ] == false){
            ans += dfs(listAdj[v][i].first, listAdj[v][i].second); // visitar o nó mais abaixo 
            qtdOuro[v]+=qtdOuro[ listAdj[v][i].first ]; // colocar a qtd de ouro do nó abaixo no cofre da cidade v
        }
    }
    ans += 2*p*ceil(1.0*qtdOuro[v]/capacidade); // calcular a qtd de km necessários
    return ans; // retorna essa qtd de km 
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n, u, v, p;
    cin >> n >> capacidade; // qtd cidade e capacidade máxima de transporte 
    for(int i=1; i<=n; i++) cin >> qtdOuro[i];
    for(int i=1; i<n; i++){
        cin >> u >> v >> p; // relação entre u e v com peso p
        listAdj[u].push_back({v,  p});
        listAdj[v].push_back({u, p});
    }
    cout << dfs(1, 0) << endl; // chamar a dfs do nó 1 com custo 0
    return 0;
}
