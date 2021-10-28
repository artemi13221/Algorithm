d = []

for i in range(500):
  d.append(0)

d[1] = 1;
d[2] = 1;

for i in range(3,500):
  d[i] = d[i-1] + d[i - 2]

a = input().split()

for i in range(500):
  if int(a[0]) <= d[i] <= int(a[1]):
    print(d[i])