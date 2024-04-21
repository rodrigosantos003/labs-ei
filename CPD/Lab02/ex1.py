import math
import random
import os

# 1
print(math.factorial(10))
print(math.gcd(6, 3))
print(math.comb(20, 2))
print(math.perm(10))
print(math.log10(60))
print(math.cos(math.pi))
print(math.dist((0, 0), (10, 10)))


# 2
print(random.randint(1, 10))
print(random.random())
print(random.choice(['a', 'b', 'c', 'd']))
print(random.gauss(90, 5))

# 3
print(os.name)
print(os.getlogin())
print(os.getpid())
print(os.getcwd())
os.chdir("C:/")
print(os.getcwd())
with os.scandir(os.getcwd()) as folders:
    print([folder.name for folder in folders if folder.is_dir()])

# 4
num = random.randint(1, 100)
#print(num)

while True:
    guess = int(input("Introduza um número: "))
    if guess == num:
        print("Acertou no número")
        break
    elif guess > num:
        print("O número é menor")
    else:
        print("O número é maior")
