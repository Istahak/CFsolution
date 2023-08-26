from collections import Counter, defaultdict
from curses import wrapper


N = 300000
di = [[] for _ in range(N)]

def init():
    for i in range(1, N):
        for j in range(i, N, i):
            di[j].append(i)

init()

t=int(input())
for ___ in range(t): 
    n=int(input())
    v=list(map(int,input().split()))
    fr=defaultdict(int)
    for x in v:
        fr[x]+=1
    ans=0
    for x in range(1,n+1):
        cur=0;
        
        for d in di[x]:
            cur+=fr[d]
            
        ans=max(cur,ans)
    print(ans)        
        
    