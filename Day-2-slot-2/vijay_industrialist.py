n,k = map(int,input().split())
price = list(map(int,input().split()))
vol = list(map(int,input().split()))
maxi = 0;
for i in range(n-1,-1,-1):
    if k >= price[i]:
        maxi += vol[i]
        k -= price[i]
print(maxi)