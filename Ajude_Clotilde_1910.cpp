#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+5;
int origem, destino, k;
int qtdOperacao[MAXN];
bool visitado[MAXN];

bool isValido(int canal){
	if(canal < 1 || canal > 100000) return 0;
	return (visitado[canal])? 0 : 1;
}

int bfs(){
    int canal, proximo;
    queue<int> fila;
    qtdOperacao[origem]=0;
    visitado[origem] = 1;
    fila.push(origem);
    while(fila.empty() == false){ // enquanto tiver alguém na fila eu processo 
        canal = fila.front();
        fila.pop();
        // não preciso continuar porque já cheguei no canal destinado 
        if(canal == destino) break;
        // agora tento colocar o próximo canal apertando cada um dos botões do controle
        // bem similar a bfs
        proximo = canal-1;
        if(isValido(proximo)){
        	fila.push(proximo);
        	visitado[proximo] = 1;
        	qtdOperacao[proximo] = qtdOperacao[canal] + 1;
        }
        
        proximo = canal+1;
        if(isValido(proximo)){
        	fila.push(proximo);
        	visitado[proximo] = 1;
        	qtdOperacao[proximo] = qtdOperacao[canal] + 1;
        }
        
        proximo = canal*2;
        if(isValido(proximo)){
        	fila.push(proximo);
        	visitado[proximo] = 1;
        	qtdOperacao[proximo] = qtdOperacao[canal] + 1;
        }
        
        proximo = canal*3;
        if(isValido(proximo)){
        	fila.push(proximo);
        	visitado[proximo] = 1;
        	qtdOperacao[proximo] = qtdOperacao[canal] + 1;
        }
        
        proximo = canal/2;
        if(isValido(proximo) && canal%2 == 0){
        	fila.push(proximo);
        	visitado[proximo] = 1;
        	qtdOperacao[proximo] = qtdOperacao[canal] + 1;
        }
    }
    // vejo se consegui chegar no destino 
    return (visitado[destino] == 0)? -1 : qtdOperacao[destino];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int canal;
    while(cin >> origem >> destino >> k && (origem + destino + k) != 0){ // ler entrada, a soma dos valores tem que ser maior que 0
        memset(visitado, 0, sizeof(visitado));
        for(int i=0; i<k; i++){
            cin >> canal; // canal proibido
            // marcando pra nunca entrar na fila
            visitado[canal] = 1;
        }
        cout << bfs() << '\n';
    }
    return 0;
}
