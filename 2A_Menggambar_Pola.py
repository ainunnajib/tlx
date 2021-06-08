n, m = map(int, input().split())
for _ in range(n//2):
    print('*$'*(m//2) + '*'*(m%2))
    print('$#'*(m//2) + '$'*(m%2))
if n%2 == 1:
    print('*$'*(m//2) + '*'*(m%2))