arr = [10,5,7]
count = 0

for i in range(len(arr) - 1):
    if(arr[i] > arr[i + 1]):
        count +=1

if(count > 1):
    print(True)
else:
    print(False)
