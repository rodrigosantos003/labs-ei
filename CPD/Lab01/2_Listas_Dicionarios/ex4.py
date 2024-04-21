s = input("Digite uma string: ")

freq = {}

for l in s:
    # Incrementa a contagem para a letra atual ou inicializa com 1 se não existir
    freq[l] = freq.get(l, 0) + 1

print(freq)

