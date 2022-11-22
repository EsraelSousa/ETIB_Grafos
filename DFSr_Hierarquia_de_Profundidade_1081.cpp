#include <bits/stdc++.h>

using namespace std;

void printEspacos(int qtdEspaco){
    while(qtdEspaco--)
        cout << ' ';
}

void dfs(vector<int>grafo[], int v, int *visitado, int qtdEspaco){ // grafo, vertice, vistados, qtdEspaco pra mostrar
    visitado[v]=1;
    for(int i = 0; i < grafo[v].size(); i++){ // vizinhos do vértice
        if(visitado[grafo[v][i]] == 0){ // visitado a primeira vez
            visitado[grafo[v][i]] = visitado[v];
            printEspacos(qtdEspaco);
            cout << v << "-"<< grafo[v][i] << " pathR(G," << grafo[v][i] << ")\n";
            dfs(grafo, grafo[v][i], visitado, qtdEspaco+2);
        }else{ // já visitei esse vértice
            printEspacos(qtdEspaco);
            cout << v << "-"<< grafo[v][i] << '\n';
        }
    }
}

int main(){
    int n, casos = 1;
    cin >> n;
    while (n--){ // enquanto tiver testes
        int v, e, x, y;
        cin >> v >> e; // vértices e arestas
        
        vector<int> grafo[v]; // listas de adjacência
        int visitado[v];
        // coloco todos como não visitado
        memset(visitado, 0, sizeof(visitado));
        // ler relações do grafo
        for (int i = 0; i < e; i++){
            cin >> x >> y;
            grafo[x].push_back(y);
        }
        
        cout << "Caso " << casos++ << ":\n";
        // vamos ordenar os vizinhos de cada vértice para mostrar a saída corretamente
        for (int i = 0; i < v; i++){
            sort(grafo[i].begin(), grafo[i].end());
        }
        // Fazer 
        for (int i = 0; i < v; i++){
            if(visitado[i] == 0 && grafo[i].size() > 0){ // não visitei o vertice e tem vizinhos
                int qtd = 2;
                dfs(grafo, i, visitado, qtd);
                cout << '\n';
            }
        }
    }
}