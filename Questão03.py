import random
import timeit
import matplotlib.pyplot as plt

#Gera uma lista de números de forma aleatoria no intervalo [1, tamanho] 
def criaListaRand(tamanho):
    random.seed()
    lista = []
    i = 0
    while i < tamanho:
        lista.append(random.randint(1, tamanho))
        i += 1
    return lista

#Gera um número de forma aleatoria no intervalo [1, tamanho]
def geraChaveSearch(tamanho):
    random.seed()
    return random.randint(1, tamanho)

#Função que retorna o maior valor de uma lista
def maximo(lista):
    ans = lista[0]
    
    for i in range(1, len(lista)):
        if lista[i] > ans:
            ans = lista[i]
            
    return ans

#Função para ordenar uma lista de forma linar O(N)
def CountingSort(lista):
    MAX = maximo(lista)
    B = [0 for w in range(len(lista))]
    C = [0 for w in range(MAX+1)]
    for j in range (0, len(lista)):
        C[lista[j]] = C[lista[j]]+1
    for i in range(1, MAX+1):
        C[i] += C[i-1]
    for j in range(len(lista)-1, 0, -1):
        B[ C[lista[j]]-1 ] = lista[j]
        C[lista[j]] = C[lista[j]]-1
    return B;

#Faz a busca de um elemento na lista por meio da busca linaer convencional
def buscaLinearConvenional(lista, x):
    i = 0;
    while i<len(lista) and lista[i]!=x:
        i += 1
    return i if i<len(lista) else -1

#Faz a busca de um elemento na lista por meio da busca linaer com sentinela
def buscaLinearSentinela(lista, x):
    i = 0;
    lista.append(x) # adicionando o elemento no final
    while lista[i]!=x:
        i += 1
    x = lista.pop() # excluindo o elemento
    return i if i<len(lista) else -1

#Faz a busca de um elemento na lista por meio da busca binaria convencional
def buscaBinariaConvencional(lista, x):
    l = 0 
    r = len(lista)-1
    achou = False
    while l<=r and achou==False:
        m = int((l+r)/2)
        if(lista[m] == x):
            achou = True
        elif lista[m] < x:
            l = m+1
        else:
            r = m-1
    return m if achou==True else -1

#Faz a busca de um elemento na lista por meio da busca binaria rapida    
def buscaBinariaRapida(lista, x):
    l = 0 
    r = len(lista)-1
    while l < r:
        m = int((l+r)/2)
        if lista[m] < x:
            l = m+1
        else:
            r = m
    return m if lista[r]==x else -1


tamanhosVetores = [1000, 3000, 6000, 9000, 12000, 15000, 18000, 21000, 24000]

#Tempos da execução dos métodos de buscas
temposBuscaLinearConvencional = []
temposBuscaLinearSentinela = []
temposBuscaBinariaConvencional = []
temposBuscaBinariaRapida = [] 

for tamanho in tamanhosVetores:
    lista = criaListaRand(tamanho)

    x = geraChaveSearch(tamanho)
    
    temposBuscaLinearConvencional.append(timeit.timeit("buscaLinearConvenional({}, {})".format(lista, x),setup="from __main__ import buscaLinearConvenional", number=1))
    
    temposBuscaLinearSentinela.append(timeit.timeit("buscaLinearSentinela({}, {})".format(lista, x),setup="from __main__ import buscaLinearSentinela", number=1))

    # Ordena a lista para fazer as buscas binarias
    lista = CountingSort(lista);
    
    temposBuscaBinariaConvencional.append(timeit.timeit("buscaBinariaConvencional({}, {})".format(lista, x), setup="from __main__ import buscaBinariaConvencional", number=1))

    temposBuscaBinariaRapida.append(timeit.timeit("buscaBinariaRapida({}, {})".format(lista, x), setup="from __main__ import buscaBinariaRapida", number=1))

    
fig, ax = plt.subplots()
#ax.semilogx(tamanhos, temposBurbbleSort, label="Bubble Sort")
#ax.loglog(tamanhos, temposBurbbleSort, label="Bubble Sort")
ax.plot(tamanhosVetores, temposBuscaLinearConvencional, label="Busca Linear Convencional")
ax.plot(tamanhosVetores, temposBuscaLinearSentinela, label="Busca Linear Sentinela")
ax.plot(tamanhosVetores, temposBuscaBinariaConvencional, label="Busca Binaria Convencional")
ax.plot(tamanhosVetores, temposBuscaBinariaRapida, label="Busca Binaria Rapida")

#Configurações do gráfico
plt.ylabel("Tempo")
plt.xlabel("Número de Elementos(N)")
legend = ax.legend(loc='upper center', shadow=True)

frame = legend.get_frame()
frame.set_facecolor('0.90')

for label in legend.get_texts():
    label.set_fontsize('large')

for label in legend.get_lines():
    label.set_linewidth(1.5)

#Exibe o gráfico
plt.show()
