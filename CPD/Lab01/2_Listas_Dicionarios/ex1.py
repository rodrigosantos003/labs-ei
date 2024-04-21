lista = list([1, 4, 9, 10, 23])

print(len(lista))
print(f"Primeiro elemento: {lista[0]}")
print(f"Último elemento: {lista[len(lista) - 1]}")
print(lista[1:3], " - ", lista[-2:])

lista.append(90)
print(lista)

lista.insert(4, 5)
print(lista)

lista.remove(9)
print(lista)

if 9 in lista:
    print("9 está na lista")
else:
    print("9 está na lista")

if 10 in lista:
    print("10 está na lista")
else:
    print("10 não está na lista")

lista.sort()
print(lista)

lista.reverse()
print(lista)