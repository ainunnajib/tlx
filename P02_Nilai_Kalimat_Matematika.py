s = input()
if '=' in s:
    x = s.index('=')
    s = s[:x] + '=' + s[x:]
s = eval(s)
if type(s) == bool:
    print('benar' if s else 'salah')
else:
    print(s)