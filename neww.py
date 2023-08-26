t=int(input())
for __ in range(t):
    N=int(input())
    ans=0
    best=0
    for ind in range(N):  
        a,b=map(int,input().split())
        if(a<=10):
            if(b>=best):
                best=b
                ans=ind+1
    print(ans)      