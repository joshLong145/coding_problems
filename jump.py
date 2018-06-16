arr = [0,1,2,1,1,0]

jumps = 0

i = 1

made_it = True
jumps += arr[0]
while jumps > 0:
    jumps -=1
    if i < len(arr) -1:
        i+=1
    jumps += arr[i]

print(jumps,i)
if jumps <= 0 and i < len(arr) - 1:
    made_it = not made_it

print(made_it)
