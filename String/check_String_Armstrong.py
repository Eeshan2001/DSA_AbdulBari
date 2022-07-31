def isArmstrong():
    r=len(str(sum))
    tot=0
    temp = sum
    while temp > 0:
        digit = temp % 10
        tot += digit ** r
        temp //= 10

    # display the result
    if tot == sum:
        return True
    else:
        return False

if __name__=="__main__":
    s = input()
    sum=0
    for i in s:
        sum +=ord(i)
    res = isArmstrong()
    if(res):
        print("Interesting")
    else:
        print("Not Interesting")