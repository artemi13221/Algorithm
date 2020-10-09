num = int(input())
result = []

for i in range(num) :
    iList = list(input().split(' '))
    result.append('')
    for j in range(len(iList[1])) :
        result[i] += iList[1][j] * int(iList[0])
    
for i in range(num) :
    print(result[i])
