a = "1"
b = []
while (a):
  try:
    a = list(input())
    b += a
    if b[-1] == '.' :
      b.append("\n")
    elif b[-1] == ' ' and b[-2] == '.' :
      b.append("\n")
  except:
    break

c = ""
for i in range(len(b)):
  c += str(b[i]) 
print(c)