def add2(a, b):
    return a + b

def max(a, b):
    if a > b:
        return a
    else:
        return b

def is_divisible(a, b):
    return a % b == 0

def avg(lista):
    if len(lista) == 0:
        return None
    return sum(lista) / len(lista)

def pow(a, b=2):
    return a ** b

print("Soma de 2 e 3:", add2(2, 3))
print("Maior entre 5 e 10:", max(5, 10))
print("É 10 divisível por 5?", is_divisible(10, 5))
print("Média de [1, 2, 3, 4, 5]:", avg([1, 2, 3, 4, 5]))
print("3 elevado a 4:", pow(3, 4))
