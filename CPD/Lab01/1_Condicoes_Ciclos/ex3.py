i = 1
while i <= 10:
    print(i)
    i += 1

n = int(input("Introduza um número: "))

j = 1
soma = 0
while j <= n:
    soma += j
    j += 1

print(soma)

num = int(input("Introduza um número: "))
rev = 0

while num > 0:
    last = num % 10
    rev = (rev * 10) + last
    num = num // 10

print(f"{num} -> {rev}")