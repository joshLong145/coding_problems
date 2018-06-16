arr = [2,4,6,8]

def largerstSum(arr):
    sums = []
    for i in range(len(arr)):
        if(i > 0 and i < len(arr) - 1):
            sums.append(findLargest(arr,i,arr[i -1],arr[i +1]))
        elif i == 0:
            sums.append(findLargest(arr,i,right = arr[i +1]))
        elif i == len(arr) -1:
            sums.append(findLargest(arr,i,left = arr[i -1]))
    print(max(sums))

def findLargest(arr,index, left = None, right = None):
    sum = 0
    for i in range(len(arr)):
        if(i != index and arr[i] != left and arr[i] != right):
            if(sum < sum + arr[i]):
                sum =  arr[index] + arr[i]
                print(sum,arr[index],arr[i])
    return sum

largerstSum(arr)
