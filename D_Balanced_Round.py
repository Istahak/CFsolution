t=int(input())
for ___ in range(t):
    n,k=map(int,input().split())
    v=list(map(int,input().split()))
    v.sort()
    i=0
    ans=0
    while i<n:
        cnt=1
        while i<n-1 and v[i+1]-v[i]<=k:
            i+=1
            cnt+=1
        ans=max(ans,cnt)
        i+=1
    print(n-ans)    
    