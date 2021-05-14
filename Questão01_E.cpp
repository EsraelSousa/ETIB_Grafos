#include <iostream>
#include <string>

using namespace std;

void mergeSort(string& pal){ 
    
    if(pal.size() == 1) return; // size() retorna o tamnho da string

    string direita, esquerda; // strings auxiliares

    int meio = (int)pal.size() / 2;

    for(int i=0; i<meio; i++) esquerda.push_back( pal[i] ); // push_back() adiciona um caracter ao
                                                            // final da string
    for(int i=meio; i<pal.size(); i++) direita.push_back( pal[i] );
    
    mergeSort(esquerda);
    mergeSort(direita);
    
    esquerda.push_back('~'); // 
    direita.push_back('~');
    
    int index1 = 0, index2 = 0;

    for(int i=0; i<pal.size(); i++){
        if(esquerda[index1] < direita[index2])
            pal[i] = esquerda[index1], index1++;
        else pal[i] = direita[index2], index2++;
    }

    return;
}

int main(){
    string palavra;
    cout << (('A' < 'Z')? "trues \n" : "falses \n");
    cin >> palavra;
    /* Como não sabemos qual é o tamanho máximo da palavra a ser ordenada
     não vamos usar um algoritmo que tenha um desempenho ruim para entradas grandes
     */
     cout << palavra << "\n";
    mergeSort(palavra);
    cout << palavra << endl;  
    return 0;
}