if input() == 'PAS':
    print('var data:array[1..10000] of longint;')
    print('    n,i,j,temp:longint;')
    print('begin')
    print('  readln(n);')
    print('  for i:=1 to n do readln(data[i]);')
    print('  for i:=1 to n-1 do')
    print('    for j:=i+1 to n do')
    print('      if (data[i]>data[j]) then')
    print('      begin')
    print('        temp:=data[i];')
    print('        data[i]:=data[j];')
    print('        data[j]:=temp;')
    print('      end;')
    print('  for i:=1 to n do writeln(data[i]);')
    print('end.')
else:
    print('int data[10001];')
    print('int n,i,j,temp;')
    print('int main(){')
    print('  scanf("%d",&n);')
    print('  for (i=1;i<=n;i++) scanf("%d",data[i]);')
    print('  for (i=1;i<=n-1;i++)')
    print('    for (j=i+1;j<=n;j++)')
    print('      if (data[i]>data[j]){')
    print('        temp=data[i];')
    print('        data[i]=data[j];')
    print('        data[j]=temp;')
    print('      }')
    print('  for (i=1;i<=n;i++) printf("%d\\n",data[i]);')
    print('  return 0;')
    print('}')