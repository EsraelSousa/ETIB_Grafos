#include <bits/stdc++.h>

using namespace std;

#define piii pair<int, pair<int, int> >
#define f first
#define s second

priority_queue< pair<int, pair<int, int> >,
 vector< pair<int, pair<int, int> > >, 
 greater< pair<int, pair<int, int> > > > fila;
const int IFN = 1e9;
const int MAXN = 5*1e2+5;
int n, m, distancia[MAXN][MAXN], x, y, ans[MAXN][MAXN];
bool visitado[MAXN][MAXN];

int X[] = {-1, 0, 1, 0}, Y[] = {0, 1, 0, -1}; // para ser mais facil olhar as direções

int valida(int xi, int yi){
	if(xi<1 || yi<1 || xi>n || yi>m) return 0;
	return 1;
}

void dijkstra(){
	int xi, yi, D;
	while(!fila.empty()){
		D =fila.top().first, xi = fila.top().second.first, yi=fila.top().second.second; fila.pop();
		if(visitado[xi][yi]) continue;
		visitado[xi][yi]=true;
		for(int d=0; d<4; d++){
            if(valida(xi + X[d], yi + Y[d])){
                if(distancia[xi + X[d] ][ yi+Y[d] ] + D < ans[ xi+X[d] ][ yi+Y[d] ]){
                    ans[ xi+X[d] ][ yi+Y[d] ] = distancia[ xi+X[d] ][ yi+Y[d] ] + D;
                    fila.push({ ans[ xi+X[d] ][ yi+Y[d] ], {xi+X[d], yi+Y[d]}});
                }
            }
        }
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	char c;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> c;
			distancia[i][j] = (c=='#')? IFN : (c>='0' && c<='9')? c-'0' : 0; // coloco os valores de custo de cada célula
			ans[i][j] = IFN;
			if(c=='H') fila.push({0, {i, j}}), ans[i][j]=0; // coloco o inicio já na fila
			if(c=='E') x=i, y=j; // marca qual a posição final
		}
	}
	dijkstra();
	if(ans[x][y] != IFN) cout << ans[x][y] << "\n"; // vejo se consigo chegar ao destino
	else cout << "ARTSKJID\n";
	return 0;
}
