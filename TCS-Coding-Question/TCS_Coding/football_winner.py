n = int(input())

teamScore=[]
Each_Round_Winner={}

for i in range(n*(n-1)//2):
    teamScore.append(input().split(" "))

for i in teamScore:
    Each_Round_Winner[i[0]]=0
    Each_Round_Winner[i[1]]=0

for i in range(n*(n-1)//2):
    p = teamScore[i][-1].split("-")
    if int(p[0]) > int(p[1]):
        Each_Round_Winner[teamScore[i][0]] +=3
    elif int(p[0]) < int(p[1]):
        Each_Round_Winner[teamScore[i][1]] +=3
    else:
        Each_Round_Winner[teamScore[i][0]] +=1
        Each_Round_Winner[teamScore[i][1]] +=1
win = 0
team = ""
for i,j in Each_Round_Winner.items():
    if j>win:
        win=j
        team = i
print(team,"-",win)