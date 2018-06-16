def valid(M):
    for k in M.values():
        if k == 0:
            return False
    return True

seq = input(str("please input a string: "))
print(seq)
S = set(['a', 'b', 'c'])
M = dict()


for i in S:
    #initlize each position within the Dict to 0
    M[i] = 0


i = 0
j = 0

n = len(seq)
length = n + 1

while j < n:
    if seq[j] in S:
        M[seq[j]] += 1

    if valid(M) and (j - i + 1) < length:
        length = j - i + 1

    while valid(M):
        if seq[i] in S:
            if M[seq[i]] == 1:
                break
            M[seq[i]] -= 1

        i += 1

        if (j - i + 1) < length:
            print(seq[i:j+1])
            length = j - i +1

    j += 1

print(length)
