import multiprocessing
import time
import random


def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)



def sequential_fibonacci(numbers):
    fibonacci_values = []

    for num in numbers:
        fibonacci_values.append(fibonacci(num))

    return fibonacci_values


def parallel_fibonacci(numbers):
    with multiprocessing.Pool() as pool:
        results = pool.map(fibonacci, numbers)
        return results


if __name__ == '__main__':
    nums = [random.randint(20, 40) for _ in range(8)]

    start = time.time()

    #print("Fibonnaci: ", sequential_fibonacci(nums))

    print(parallel_fibonacci(nums))

    end = time.time()

    print("Time: ", (end - start), " secs.")
