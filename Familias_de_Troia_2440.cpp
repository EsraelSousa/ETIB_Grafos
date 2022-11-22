#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5*1e4+5; // número máximo de pessoas 
vector<int> listAdj[MAXN];
int visitado[MAXN];

void dfs(int v, int id){
	visitado[v] = id; // id da familia que a pessoa v pertence
	for(int i=0; i<listAdj[v].size(); i++)
		if(visitado[ listAdj[v][i] ] == 0)
			dfs(listAdj[v][i], id);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    int u, v;
    cin >> m >> n;
    for(int i=0; i<n; i++){
    	cin >> u >> v;
     	// coloco a relação na lista de adj.
    	listAdj[u].push_back(v);
    	listAdj[v].push_back(u);
    }
    int qtdFamilia = 0; // inicialmente não tem nenhuma familia
    for(int i=1; i<=m; i++){
    	if(visitado[i] == 0){ // encontrei alguém que não esta em nenhumafamilia
    		qtdFamilia++;
    		dfs(i, qtdFamilia);
    	}
    }
    // agora é so mostrar a qtd de família
    cout << qtdFamilia << endl;
   	return 0;
}
