import operator as op
from functools import reduce

def ncr(n,r):
    r=min(r,n-r)
    numer = reduce(op.mul, range(n,n-r,-1),1)
    demon = reduce(op.mul, range(1,r+1),1)
    return numer

n=int(input())
x=int(input())
l=list(map(int,input().split()))
if (x%2 == 0):
    print(ncr(n,x)%1000000007 + 1)
else:
    print(ncr(n,x)%1000000007)
