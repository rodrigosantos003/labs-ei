def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)

def summation(n):
    if n == 0:
        return 0
    else:
        return n + summation(n - 1)

def power(n, x):
    if x == 0:
        return 1
    else:
        return n * power(n, x - 1)

print("Fatorial de 5:", factorial(5))
print("Somatório até 5:", summation(5))
print("2 elevado a 3:", power(2, 3))
