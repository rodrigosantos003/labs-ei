lista = list([0, 1, 2, 3, 4])

quadrados = [i**2 for i in lista]
print(quadrados)

print(f"Soma: {sum(quadrados)}")
print(f"Média: {sum(lista)/len(lista)}")

lista20 = range(21)
print(f"Soma: {sum(lista20)}")
print(f"Média: {sum(lista20)/len(lista20)}")