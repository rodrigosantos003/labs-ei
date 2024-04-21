# 1
def sum_all(*args):
    print(sum(args))


sum_all(1, 2, 3, 4)


# 2
def get_name(**kwargs):
    print(f"{kwargs['first_name']} {kwargs['last_name']}")


get_name(first_name="Rodrigo", last_name="Santos")

# 3
isEven = lambda n: n % 2 == 0
print(isEven(4))

sumValues = lambda a, b: a + b
print(sumValues(1, 2))

exp = lambda x, y: pow(x, y)
print(exp(2, 3))


# 5
def apply_and_sum(f, *values):
    for x in values:
        f(x)
    return sum(values)


def double(x):
    return x * 2


def sqrt(x):
    return x**2


def sum_ten(x):
    return x + 10


print(apply_and_sum(double, 1, 2, 3, 4))

print(apply_and_sum(sqrt, 1, 2, 3, 4))

print(apply_and_sum(sum_ten, 1, 2, 3, 4))
