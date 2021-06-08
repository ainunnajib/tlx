l = input().lower()
print(sum(['halo dunia'[i]==l[i] for i in range(min(10, len(l)))]))