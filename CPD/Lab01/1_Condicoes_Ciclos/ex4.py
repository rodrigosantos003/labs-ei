for i in range(6):
    print(i)

for i in range(10, 21, 2):
    print(i)

s = str(input("Introduza uma string: "))
vowels = 0

for i in s:
    i.lower()
    if i == "a" or i == "e" or i == "i" or i == "o" or i == "u":
        vowels += 1

rev = ""
for i in range(len(s) - 1, -1, -1):
    rev += s[i]

print(f"Número vogais: {vowels}")
print(f"Invertida: {rev}")
