import csv

# 1 e 2
with open("file.txt", "a") as f:
    msg = ""

    while True:
        msg = input("Escreva uma palavra: ")
        if msg != "exit":
            f.write(msg)
            f.write("\n")
        else:
            break

# 2 e 3
with open("file.txt", "r") as f:
    lines = f.readlines()

count = 0

for word in lines:
    count += 1
    word = word.strip()
    print(word)

print(f"Numero Linhas: {count}")

# 5
maleCount = 0
femaleCount = 0

with open("people-1000.csv") as f:
    reader = csv.DictReader(f)
    for row in reader:
        if row["Sex"] == "Male":
            maleCount += 1
        else:
            femaleCount += 1

print(f"Pessoas sexo masculino: {maleCount}")
print(f"Pessoas sexo feminino: {femaleCount}")

with open("people-1000.csv") as f:
    reader = csv.DictReader(f)
    for row in reader:
        if row["First Name"] == "Stuart":
            print(row)

with open("people-1000.csv") as f:
    reader = csv.DictReader(f)
    for row in reader:
        if "Engineer" in row["Job Title"]:
            print(row)

with open("people-1000.csv") as f:
    reader = csv.DictReader(f)
    for row in reader:
        date_of_birth = row['Date of birth']
        if date_of_birth.startswith("1982"):
            print(row)

with open("people-1000.csv") as f:
    reader = csv.DictReader(f)
    for row in reader:
        date_of_birth = row['Date of birth']
        if date_of_birth.startswith("198"):
            print(row)

