import random

n = 1000000
with open("input.txt", "w") as f:
    f.write(str(n) + "\n")
    for i in range(0, n):
        f.write(str(random.randint(1, 3000000)) + " ")