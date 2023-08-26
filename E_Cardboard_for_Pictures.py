import math
t=int(input())
for ____ in range(t):
    n,c=map(int,input().split())
    v=list(map(int,input().split()))
    l=1
    r=int(math.sqrt(c)) 
    ans=-1
    while l<=r:
        mid=(l+r)//2
        cur=0;
        for x in v:
            cur=cur+(x+2*mid)*(x+2*mid)
        
        if(cur<=c):
            ans=mid
            l=mid+1
        else:
            r=mid-1
    print(ans)                