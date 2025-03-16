import random as r

def writeRandFile(nome, n: int, ordered = False):
    list = []

    for i in range(n):
       list.append(r.randrange(n))

    if(ordered):
        list.sort()
        path = "../rand_files/ordered/"
        nome = path + nome
    else:
        path = "../rand_files/"
        nome = path + nome

    with open(nome, 'x') as file:
        for x in range(n):
            file.write("%d\n" % list[x])
        file.close()


def autoGen(ordered = False):
    fileNames = ["100.txt", "1_000.txt", "10_000.txt", "100_000.txt", "1_000_000.txt"]

    for f in fileNames:
        print(f)
        writeRandFile(f, 10 ** (fileNames.index(f) + 2), ordered)
