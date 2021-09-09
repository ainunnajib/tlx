l = list(map(int, input().split()))
if l[-1] == 1:
    x = sorted(l[:-1])
else:
    x = sorted(l[:-1], reverse=True)
print(' '.join([str(c) for c in x]))