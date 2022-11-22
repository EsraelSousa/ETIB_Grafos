#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3+30;

char mapa[MAXN][MAXN];
int cor[MAXN][MAXN];
int n, m;

/*
faço um vetor que guarda a ordem das células 
adjacentes da posição i,j no sentido horário 
isso evita erros durante o código e é mais fácil de debugar
*/
vector<int> X = {-1, 0, 1, 0};
vector<int> Y = {0, 1, 0, -1};

bool isValido(int i, int j){
	if(i<0 || i>=n || j<0 || j>=m) return false; // essa posição sai do mapa, logo é inválida 
	if(mapa[i][j] == 'o' || cor[i][j] > 0) return false; // essa posição é mar ou já foi visitada, não precisa ir
	return true; // posso ir para aquela posição 
}

void bfs(int i, int j, int corPintar){
	queue< pair<int, int> > fila; 
	fila.push({i, j}); // coloco na fila a célula inicial
	while(fila.empty() == false){ // enquanto tiver alguém na fila
		i = fila.front().first;
		j = fila.front().second;
		fila.pop(); // retiro da fila
		cor[i][j] = corPintar;  // marco a célula como pintada
		
		for(int d=0; d<4; d++){ // olhar as 4 direções 
			if(isValido(i + X[d], j + Y[d])){ // verifica a célula adjacente na direção d
				// é uma posição válida, então coloco na fila
				cor[ i+X[d] ][ j+Y[d] ] = corPintar; // já marco pinto a célula pra não entrar  na fila novamente
				fila.push({i + X[d], j + Y[d]});
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m; // qtd linhas e colunas
    int qtdCores = 0;
    for(int i=0; i<n; i++)
    		cin >> mapa[i]; // leitura de  cada linha iniciando na coluna 0

    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
    		if(mapa[i][j] == '.' && cor[i][j] == 0){ // essa posição é branca e ainda não foi explorada 
    			qtdCores++; // aumentoa qtd de cor
                bfs(i, j, qtdCores);
    		}
    	}
    }
    // printar a resposta
    cout << qtdCores << '\n';
   	return 0;
}