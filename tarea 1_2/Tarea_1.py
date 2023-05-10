######punto1


mat = [[11, 23, 76, 34, 11],
[14, 30, 92, 30, 101],
[12, 45, 58, 92, 22],
[74, 56, 49, 56, 100],
[99, 5, 28, 47, 99]]

def verificarDiagonales(mat):
    i = 0
    x = -1
    contador = 0
    while i < len(mat):
        if mat[i][i] == mat[i][x]:
            contador += 1
        i += 1
        x -= 1
    if contador == len(mat):
        ans = True 
    else:
        ans = False       
    return ans
print(verificarDiagonales(mat))


######punto2


lista = ([42, 12, 90, 90, 12, 42])
def esCapicua(lista):
    i = 0
    x = -1
    contador = 0
    while i < len(lista):
        if lista[i] == lista[x]:
            contador += 1
        i += 1
        x -= 1
    if contador == len(lista):
        ans = True
    else:
        ans = False
    return ans
print(esCapicua(lista))


######punto3
###A)


listaA = [40, 10, 22, 12, 33, 33, 33]
listaB = [41, 22, 31, 15, 13, 12, 33, 19]
listaN = []
def diferenciaListas(listaA, listaB):
    i = 0
    x = 0
    while i < len(listaA):
        if listaA[i] in listaB[x]:
            listaB.remove(listaA[i])
            listaN.append(listaA[i])

