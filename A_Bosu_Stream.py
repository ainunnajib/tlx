s = input()
x = 1
ans = 1
for i in range(1, len(s)):
    if s[i-1] != s[i]:
        x += 1
        ans = max(ans, x)
    else:
        x = 1
print(ans)