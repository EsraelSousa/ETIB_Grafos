#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3+5;

char mapa[MAXN][MAXN];
bool visitado[MAXN][MAXN];
int n, m;
int qtdCosta = 0;

/*
faço um vetor que guarda a ordem das células 
adjacentes da posição i,j no sentido horário 
isso evita erros durante o código e é mais fácil de debugar
*/
vector<int> X = {-1, 0, 1, 0};
vector<int> Y = {0, 1, 0, -1};

bool isValido(int i, int j){
	if(i<0 || i>=n || j<0 || j>=m) return false; // essa posição sai do mapa, logo é inválida 
	if(mapa[i][j] == '.' || visitado[i][j] == true) return false; // essa posição é mar ou já foi visitada, não precisa ir
	return true; // posso ir para aquela posição 
}

int isCosta(int i, int j){
	if(i == 0 || i == n-1 || j == 0 || j == m-1) return 1; // se é uma borda da matriz já é costa
	int qtd = 0;
	for(int d=0; d<4; d++) // contar a qtd células adjacentes que são terra
		qtd += (mapa[ i+X[d] ][ j+Y[d] ] == '#'); 
	return (qtd == 4)? 0 : 1; // faço um operador ternário, se as 4 células adjacentes são terra ela não é costa
}

void bfs(int i, int j){
	queue< pair<int, int> > fila; 
	fila.push({i, j}); // coloco na fila a célula inicial
	while(fila.empty() == false){ // enquanto tiver alguém na fila
		i = fila.front().first;
		j = fila.front().second;
		fila.pop(); // retiro da fila
		visitado[i][j] = true;  // marco a célula como visitada
		// ver se a célula é costa e incrementa 
		qtdCosta += isCosta(i, j); 
		
		for(int d=0; d<4; d++){ // olhar as 4 direções 
			if(isValido(i + X[d], j + Y[d])){ // verifica a célula adjacente na direção d
				// é uma posição válida, então coloco na fila
				visitado[ i+X[d] ][ j+Y[d] ] = true; // já marco como visitada pra não entrar  na fila novamente
				fila.push({i + X[d], j + Y[d]});
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m; // qtd linhas e colunas
    for(int i=0; i<n; i++)
    		cin >> mapa[i]; // leitura de  cada linha iniciando na coluna 0

    for(int i=0; i<n; i++){
    	for(int j=0; j<m; j++){
    		if(mapa[i][j] == '#' && visitado[i][j] == false){ // essa posição é Terra e ainda não foi explorada 
    			bfs(i, j);
    		}
    	}
    }
    // printar a resposta
    cout << qtdCosta << '\n';
   	return 0;
}
// tente fazer sem usar bfs tbm
