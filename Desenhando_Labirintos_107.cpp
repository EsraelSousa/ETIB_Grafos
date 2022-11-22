#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5*1e1+5;
vector<int> listAdj[MAXN];
bool visitado[MAXN];

int dfs(int v){ 
	visitado[v] = 1;
	int qtdVisita = 1; // visitei o vertice v, então precisei usar uma aresta
	for(int i=0; i<listAdj[v].size(); i++)
		if(visitado[ listAdj[v][i] ] == 0)
			qtdVisita += dfs(listAdj[v][i]); // os vizinhos de v que não foram visidatos vou visitar e aumento a qtd de vértices visitados 
	return qtdVisita; // return a qtd de vértices visitados 
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int testes;
    int n, m, iniciar, u, v;
    cin >> testes;
    while(testes--){ // 
    	cin >> iniciar; // vértice que inicia a busca 
    	cin >> n >> m; // qtd de vértice e aresta
    	// limpar as variáveis do teste anterior  
    	for(int i=0; i<=n; i++)
    		visitado[i] = 0, listAdj[i].clear();
    	
    	while(m--){
    		cin >> u >> v;
    		// coloco a relação na lista de adjacência 
    		listAdj[u].push_back(v);
    		listAdj[v].push_back(u);
    	}
    	// uma árvore com N vértices possui N-1 arestas 
    	cout << 2 * (dfs(iniciar) -1) << '\n';
    }
    return 0;
}
