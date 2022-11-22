#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;

bool matAdj[MAXN][MAXN]; // matriz de adjacencia
vector<string> componentes(MAXN); // No máximo temos cada letra como uma componente
bool visitado[MAXN];

/*
Vamos armazenar as letras como números, basta fazer umas contas
com base na tabela ASCI
letra - 'a' == qual a letra 1, 2, 3, 4, ...
'a' + num = i-ésima letra
*/

void dfs(int v, int idComponente){
    visitado[v] = true;
    componentes[idComponente].push_back( (char)('a'+v) ); // faz um cast pra char e add no final
        for(int i=0; i<26; i++){
        if(matAdj[v][i] == true && visitado[i] == false)
            dfs(i, idComponente);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n, m, qtdComponete = 0;
    char u, v;
    int testes;
    cin >> testes;
    for(int t=1; t<=testes; t++){
        cin >> n >> m; // qtd letras e relações
        // limpar as variáveis
        for(int i=0; i<MAXN; i++){
            visitado[i] = 0;
            componentes[i].clear();
        }
        qtdComponete = 0;
        memset(matAdj, 0, sizeof(matAdj));

        for(int i=0; i<m; i++){
            cin >> u >> v; // duas letras da relação
            int a = u-'a'; // tranformar pra int
            int b = v-'a'; // tranformar pra int
            matAdj[ a ][ b ] = matAdj[ b ][ a ] = true; // marcamos a relação
        }
        // fazer a dfs em cada letra que ainda não foi visitada
        for(int i=0; i<n; i++){
            if(visitado[i] == false){
                dfs(i, qtdComponete);
                qtdComponete++;
            }
        }
        // Para cada componente vou ordenar suas letra
        for(int i=0; i<qtdComponete; i++)
            sort(componentes[i].begin(), componentes[i].end());
        // Ordenar cada componente
        sort(componentes.begin(), componentes.begin()+qtdComponete);
        // Agora é só imprimir
        cout << "Case #" << t << ":\n";
        for(int i=0; i<qtdComponete; i++){
            for(int j=0; j<componentes[i].size(); j++)
                cout << componentes[i][j] << ',';
            cout << endl;
        }
        cout << qtdComponete <<  " connected components\n\n";
    }
    return 0;
}

