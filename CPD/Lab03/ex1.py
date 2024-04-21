# 1
## a)
nums = list([1, 2, 3, 4, 5])


def sqr(n):
    return n ** 2


print(list(map(sqr, nums)))

## b)
temps = list([12.4, 26.4, 32.7])


def convert_temp(t):
    return (t * (9 / 5)) + 32


print(list(map(convert_temp, temps)))

## c)
strs = list(["Olá", "Tudo", "Bem"])

print(list(map(len, strs)))

## d)
print([n**2 for n in nums])

print([convert_temp(t) for t in temps])

print([len(s) for s in strs])


# 2
