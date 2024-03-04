#!/usr/bin/env python3
import sys

sys.setrecursionlimit(10**6)
lp=10**9+7
mem=[1,1,2]

def fac(n):
    while len(mem)<n+1:
        mem.append((mem[-1]*len(mem))%lp)
    return mem[n]

def choose(n,k):
    if k>n:
        return 0
    return (fac(n)*pow(fac(n-k),-1,lp)*pow(fac(k),-1,lp))%lp

memo={}

def dp(n,m,r,p):
    if n==0:
        if r==0:
            return 1
        else:
            return 0
    if m==0:
        if r==0:
            return 1
        else:
            return 0
    if (n,m,r,p) in memo:
        return memo[(n,m,r,p)]
    res=dp(n,m-1,r,p)
    res+=dp(n-1,m,(r-m)%p,p)
    res%=lp
    memo[(n,m,r,p)]=res
    return res

def solv(n,m,p,r):
    if n%p==0 and m%p==0:
        all=choose(n+m,n)
        err=choose((n+m)//p,n//p)
        if r==0:
            return ((all-err)*pow(p,-1,lp)+err)%lp
        else:
            return ((all-err)*pow(p,-1,lp))%lp
        
    all=choose(n+m,n)
    err=choose((n+m)//p,n//p)*choose(n%p+m%p,n%p)
    res= ((all-err)*pow(p,-1,lp))%lp
    return (res+choose((n+m)//p,n//p)*dp(n%p,m%p,r,p))%lp

n, m, p, r = map(int, input().split())
print(solv(n, m, p, r))

