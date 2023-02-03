
cnt = 0
cnt1 = 0
check = 1
for i in range(0, 8):
    a = [int(s) for s in input().split()]
    if(a[0] == 1 and a[1] == 8 ) or (a[0] == 8 and a[1] == 1):
        check = 0
        break
    if(a[0] == a[1] and a[0] != 5):
        check = 0
        break
    cnt = a[0] + cnt
    cnt1 = a[1] + cnt1

if(check == 0):
    print("YES")
elif cnt == cnt1 and cnt == 36:
    print("NO")
else:
    print("YES")
