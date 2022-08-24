n,m =  map(int,input().split())
lst = []
c0 = 0
c1 = 0
for i in range(n):
    lst.append(list(map(int,input().split())))
for i in lst:
    c0 += i.count(0)
    c1 += i.count(1)
if(c0 == 0):
    print(0)
else:
    print((c1+2)-c0)