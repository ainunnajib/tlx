n, q = map(int, input().split())
for _ in range(q):
    ans = 0
    # given x
    x = int(input())

    # cek x mod (n+1)
    if x % (n+1) == 0:
    # kalau 0, kelipatan, g = x/(n+1), n/2 - g + 1
        g = x//(n+1)
        ans += max(0, n//2 - g + 1)
    # kalau nggak, cek ke kanan, cukup nggak?
    else:
        v = x % (n+1)
        # apakah angka v berada di posisi genap?
        if v > (n+1)//2:
            # posisi genap: v = n + 1 - i/2
            # i = 2*(n - v + 1)
            # grup di kanan = (n-i) // 2
            # kalau cukup, jawaban nambah 1
            g = x//(n+1)
            i = 2*(n - v + 1)
            gk = (n-i) // 2
            if gk >= g:
                ans += 1

    # cek x mod (n+2)
    if x % (n+2) == 0:
    # kalau 0, kelipatan, g = x/(n+2), (n-1)/2 - g + 1
        g = x//(n+2)
        ans += max(0, (n-1)//2 - g + 1)
    # kalau nggak, cek ke kanan, cukup nggak?
    else:
        v = x % (n+2)
        # apakah angka v berada di posisi ganjil?
        if v <= n and v <= (n+1)//2:
            # posisi ganjil: v = (i+1)/2
            # i = 2*v - 1
            # grup di kanan = (n-i) // 2
            # kalau cukup, jawaban nambah 1
            g = x//(n+2)
            i = 2*v - 1
            gk = (n-i) // 2
            if gk >= g:
                ans += 1

    print(ans)


# # cara matematika
# #n = 7
# 1 (9) (9) (9)
# 1 7 2 6 3 5 4
# (8) (8) (8) 4

# #n = 8
# 1 (10)(10)(10)5 
# 1 8 2 7 3 6 4 5
# (9) (9) (9) (9)



# possibilities x yang valid
# banyaknya lahan itu genap:
# kombinasi pasangan-pasangan
# 1) kelipatan 9
# 2) kelipatan 10
# banyaknya lahan itu ganjil:
# angka sendirian + kombinasi pasangan-pasangan
# 3) kelipatan 9 + k (1 sampai 8)
# 4) kelipatan 10 + k (1 sampai 8)

