def minTime(files, numCores, limit):
    time = 0
    lim = limit
    isParallelable = []
    for x in files:
        if x % numCores == 0:
            isParallelable.append(x)

    isParallelable.sort(reverse=True)
    parallelable = isParallelable[0:lim]

    for x in files:
        if x in parallelable:
            time += (x/numCores)
        else:
            time += x

    return int(time)


print(minTime([4, 1, 3, 2, 8], 4, 1))