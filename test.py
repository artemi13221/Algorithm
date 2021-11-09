a = input()
b = 0
c = 0

d = input()
e = 0
f = 0

for i in a:
  if i == 'R':
    b = b + 1
  elif i == 'L':
    b = b - 1
  elif i == 'U':
    c = c + 1
  elif i == 'D':
    c = c - 1

for i in d:
  if i == 'R':
    e = e + 1
  elif i == 'L':
    e = e - 1
  elif i == 'U':
    f = f + 1
  elif i == 'D':
    f = f - 1

print(b, c, e, f)