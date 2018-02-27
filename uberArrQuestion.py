arr = [1, 2, 3, 4, 5]

def solution(a):
  retarr = [0] * len(a)
  l = [0] * len(a)
  r = [0] * len(a)

  l[0] = 1
  r[len(a) - 1] = 1

  for i in range(1, len(l)):
    l[i] = a[i - 1] * l[i - 1]

  for i in range(len(r) - 2, -1, -1):
    r[i] = a[i + 1] * r[i + 1]

  for i in range(len(retarr)):
    retarr[i] = l[i] * r[i]

  return retarr
  
print(solution(arr))
