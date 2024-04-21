d = {
    "Pedro": 10,
    "Ana": 12,
    "Inês": 11,
    "Paulo": 9
}

print(f"Nº Alunos: {len(d)}")
print(f"Idade Pedro: {d["Pedro"]}")

d["Ana"] = 7
print(d.items())

d["António"] = 10
print(d.items())

if "Pedro" in d:
    print("Existe no dicionário")
else:
    print("Não existe no docionário")

del d["Pedro"]

if "Pedro" in d:
    print("Existe no dicionário")
else:
    print("Não existe no docionário")

print(f"Soma idades: {sum(d.values())}")
print(f"Média idades: {sum(d.values())/len(d)}")
