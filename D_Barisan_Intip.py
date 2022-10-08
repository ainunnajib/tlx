n = int(input())
h = []
for _ in range(n):
    h.append(int(input()))

blocker = {}
stack = []
stack.append(n-1)
for i in range(n-2, -1, -1):
    while len(stack) > 0 and h[i] > h[stack[-1]]:
        blocker[stack.pop()] = i
    stack.append(i)

ans = 0
for i in range(n):
    if i in blocker:
        ans += i - blocker[i]
    else:
        ans += i + 1
print(ans)