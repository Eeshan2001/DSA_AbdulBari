# String Rotation
# Input: rhdt:246, ghftd:1246
# Output: trhd, ftdgh
# Explanation:
# Here, every string (rhdt : 1246) is associated with a number, separated by semicolon, if sum of
# square of digit is even the rotate the string right by 1 position. If square of digit is odd the rotate
# the string left by 2 position.
# For first case:
# 2*2+4*4+6*6=84 which is even so rotate string, rotate right by 1 so ”rhdt” will be “trhd”
# For second case:
# 1*1+2*2+4*4+6*6=85 which is odd so rotate string left by 2 so “ghftd” will be “ftdgh”

def sumSqrDigit(num):
    X = int(num)
    #rev = 1
    N = 0
    while(X>0):
        rev = X%10
        rev *= rev
        N += rev
        X = X//10
    return N
def rotateRight(string):
    n=''
    x=''
    n+=string[:-1]
    x+=string[-1]
    x+=n
    return x

def rotateLeft(string):
    n=''
    x=''
    n+=string[:2] 
    x+=string[2:]
    x+=n
    return x

series = input().split(':')

for i in series:
    if(i.isdigit()):
        n=i
    else:
        stg=i

if(sumSqrDigit(n)%2==0):
    print(rotateRight(stg))
else:
    print(rotateLeft(stg))