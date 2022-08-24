
def saveThePrisoner(n, m, s):
    # Write your code here
    last = (s + m - 2) % n + 1
    return n if last==0 else last

T=int(input())
for i in range(T):
    n,m,s = map(int,input().split())
    print(saveThePrisoner(n,m,s))