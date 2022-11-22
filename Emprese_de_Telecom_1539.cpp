#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2+5;
const int IFN = 1e9;
double distancias[MAXN][MAXN];
double distancia[MAXN];
vector< pair<int, double> > listAdj[MAXN];
bool visitado[MAXN];
bool jaCalculei[MAXN];
int antenas[MAXN][3]; // cada antena tem uma coordenada e um raio

double distanciaAntenas(int i, int j){
    double a = antenas[i][0] - antenas[j][0];
    double b = antenas[i][1] - antenas[j][1];
    return sqrt(a*a + b*b);
}

void dijkstra(int s, int n){
	// crio uma fila de prioridade em que nó que está no topo
	// é menor distância de s para um nó v
	priority_queue< pair<double, int>, vector< pair<double, int> >, greater< pair<double, int> > > fila;
	// vou colocar a distância de todos os vértices como ∞ e marco como não visitado 
	// ∞ é um valor muito alto em nenhum par de vértices tem distância ≥ a ele
	for(int i=0; i<=MAXN; i++) distancia[i] = 1e9, visitado[i] = 0;
	distancia[s] = 0; // a distância de um vértice pra ele mesmo é 0
	fila.push({0, s}); // coloco a distância e o vértice na fila
	int u, v;
	double D, d;
	while(fila.empty() == false){ // enquanto tiver alguém na fila vou processar 
		D = fila.top().first; // a menor distância que está na fila
		u = fila.top().second; // pra qual vértice é essa distância 
		fila.pop(); // retiro o cara topo da fila
		if(visitado[u]) continue; // se o vértice já foi visidato quer dizer que essa distância D é maior do que a que tem no vetor distância 
		visitado[u] = 1; // marco o vértice como visitado 
		for(int i=0; i<listAdj[u].size(); i++){ // vejo todos os seus vizinhos 
			v = listAdj[u][i].first; // o vértice wue tem relação 
			d = listAdj[u][i].second; // o peso da aresta que liga esses vértices 
			if(D + d < distancia[v]){ // vejo se utilizar essa aresta com peso d é melhor pra chegar em v
				// atualizo a distância e coloco na fila 
				distancia[v] = D+d;
				fila.push({D+d, v});
			}
		}
	}

    // vamos copiar as distancias para não recalcular novamente
    for(int i=1; i<=n; i++){
        distancias[s][i] = distancia[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int n, querys, a, b;
    while(cin >> n && n != 0){ // enquanto for possivel ler
        // apagar do teste anterior
        for(int i=1; i<=n; i++)
            for(int j=i; j<=n; j++)
                distancias[i][j] = distancias[j][i] = IFN;
        for(int i=1; i<=n; i++){
            listAdj[i].clear();
            visitado[i] = jaCalculei[i] = 0;
        }
        // faz a leitura dos dados das antenas
        for(int i=1; i<=n; i++)
            for(int j=0; j<3; j++)
                cin >> antenas[i][j];
        // agora vamos ver as conexões possiveis entre antenas
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(distanciaAntenas(i, j) <= antenas[i][2])
                    listAdj[i].push_back({j, distanciaAntenas(i, j)});
        // fazer consulas
        cin >> querys;
        while(querys--){
            cin >> a >> b;
            if(jaCalculei[a] == false) dijkstra(a, n);
            cout << ((distancias[a][b] != IFN)? (int)distancias[a][b] : -1) << '\n'; 
        }
    }
    return 0;
}
