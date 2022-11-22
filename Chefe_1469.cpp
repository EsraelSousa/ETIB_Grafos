#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5*1e2+5;
vector<int> listAdj[MAXN];
int n, m;
int idade[MAXN], valNo[MAXN], pos[MAXN];
int visitado[MAXN], menor;

void dfs(int v){
    visitado[v] = 1;
    for(int i=0; i<listAdj[v].size(); i++){
        if(visitado[ listAdj[v][i] ] == 0){
        	menor = min(menor, idade[ valNo[ listAdj[v][i] ] ]); // pego a menor idade
        	dfs(listAdj[v][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    int q, a, b;
    char op;
    while(cin >> n >> m >> q){ // enquanto tiver leitura
        for(int i=1; i<=n; i++){
            cin >> idade[i]; // ler idades
            valNo[i] = pos[i] = i;
        }
        
        while(m--){
            cin >> a >> b;
            listAdj[b].push_back(a); // salvar grafo inverso
        }

        while(q--){ // operaçẽs no grafo
            cin >> op >> a;
            if(op == 'P'){
                menor = 1000; // um infinito
                memset(visitado, 0, sizeof(visitado)); // resetar os visitados
                
                if(listAdj[ pos[a] ].size()) dfs( pos[a] ); // se o vértice tem filhos faço uma dfs
                
                if(menor < 1000) cout << menor << "\n"; // vejo se encontrei alguém
                else cout << "*\n";
                
            }else{
                cin >> b;
                // faço a troca de informações entre os nós
                swap(valNo[ pos[a] ], valNo[ pos[b] ]);
                swap(pos[a], pos[b]);

            }
        }
        
        for(int i=1; i<=n; i++) listAdj[i].clear(); // limpar a lista de adjacência
    }
    return 0;
}