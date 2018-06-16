arr = [['c','b','a'],
       ['d','a','f'],
       ['g','h','i']
]
col_arr = [ [row[i] for row in arr] for i in range(3)]
count = 0
for col in col_arr:
    for i in range(len(col) -1):
        if (col[i] > col[i + 1]):
            count +=1
            break

print(count)
