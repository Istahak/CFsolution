cs=int(input())
for i in range(cs):
    n,k,g=map(int,input().split())
    
    ans=(n-1)*((g-1)//2)
    ans=min(ans,k*g)
    rem=k*g-ans
    rem=rem%g
    if rem*2>=g:
        ans-=(g-rem)
    else:
        ans+=rem
    print(ans)        