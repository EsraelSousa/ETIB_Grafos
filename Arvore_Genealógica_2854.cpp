#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3*1e2+5; // número máximo de pessoas 
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
    string u, v, relacao;
    int qtdPessoa = 1;
    map<string, int> idPessoa; // guardar o id das pessoas
    cin >> m >> n;
    for(int i=0; i<n; i++){
    	cin >> u >> relacao >> v;
    	// checar se a primeira pessoa já tem id
    	// se não tiver coloca o id dela no map e aumenta a qtd de pessoas
    	if(idPessoa.find(u) == idPessoa.end()) 
    		idPessoa[u] = qtdPessoa++;
    	// faz o mesmo pra segunda pessoa
    	if(idPessoa.find(v) == idPessoa.end()) 
    		idPessoa[v] = qtdPessoa++;
    	
    	// coloco a relação na lista de adj.
    	listAdj[ idPessoa[u] ].push_back( idPessoa[v] );
    	listAdj[ idPessoa[v] ].push_back( idPessoa[u] );
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
