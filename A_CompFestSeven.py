n = int(input())
l = []
for x in range(1, n+1):
    s = ""
    if x%3 == 0:
        s += "Comp"
    if x%5 == 0:
        s += "Fest"
    if x%7 == 0:
        s += "Seven"
    if s == "":
        s = str(x)
    l.append(s)
print(' '.join(l))