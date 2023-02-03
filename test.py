# print(1000003*1000033*1000037)
import math 
def isPrime(n):
    # Corner case
    if (n <= 1):
        return False
    # Check from 2 to square root of n
    for i in range(2, int(math.sqrt(n)) + 1):
        if (n % i == 0):
            return False
    return True
s = 1
cnt = 0
for i in range(2920200000,20000000000000000000000000000):
    if isPrime(i):
        s = s * i
        cnt+=1
        # print(s)
        # break
        # print(i,end=" ")
        if cnt % 2 ==0:
            print(s)
            s = 1
        if cnt == 100:
            break

def check(n):
    last = -1
    for i in range(1,1000):   
        if isPrime(i) and n%i==0:
            if last !=-1 and last *i ==n:
                print(i, last)
                return True
        if isPrime(i):
            last = i
            
    return False

# Path: test.py
for i in range(1,1000):
    if isPrime(i):
        print(i,end=" true")
    elif check(i):
        print(i,end=" true")
    else:
        print(i,end=" false")
print(check(21))
# print(999999937*1000000007)
# for i in range(1000000):
#     if i%199==0:
#         cnt+=1
        
# print(cnt)

