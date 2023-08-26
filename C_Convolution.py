n,m=map(int,input().split())
a=list(map(int,input().split()))
ss=sum(a)
b=list(map(int,input().split()))
ans=0
for x in b:
    ans+=ss*x
print(ans)    

