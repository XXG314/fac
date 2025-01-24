def par3(i,w):
    l=[0]*i    
    g=1
    z=0
    for z in range (i):
        g*=w
        l[z]=g
    m = [[0 for _ in range(i)] for _ in range(i)]
    g=w
    f=0
    a=g
    for f in range (w):
        b=a
        g+=-1
        a=g
        o=1
        s=a
        d=1
        k=(s>>1)+(s&1)
        m[f][0]=o*l[s]
        z=0
        while s!=k:
            o=o*b//d
            b=s
            m[f][s]=o*l[z]
            s+=-1
            m[f][d]=o*l[s]
            z=d
            d+=1
        if d==s:
            o=o*b//d
            m[f][s]=o*l[z]
    return m


def fac1(m, n):
    k = (m + 1) * (m + 2)
    j = 4 * m + 10
    n = n - m
    if n & 1:  
        m += n
        n -= 1
    else:
        if n == 0:
            return 1
        m = 1
    i = (n << 2) + j  
    while j != i:
        m *= k
        k += j
        j += 8
    return m
def fac2(m, n):
    z=n-m
    t=z//3
    z=z%3
    m+=2
    k=m*m
    j=27*m
    g=(j<<1)+162  
    j+=9*k+24
    k=k*m-m
    if z==1:
        m=n
    else:
        m=1
        if z==2:
            m=n*(n-1)
    t=g+t*162
    while g!=t:
        m*=k
        k+=j
        j+=g
        g+=162
    return m
def par(a):
    a=a>>2
    a=int(a**0.25)+1
    return a
def par2(m,w,i,n,y,r):
    g=1
    d=w
    v=(i>>1)+r
    for z in range (1,i):
        g*=v
        d+=-1
        for b in range (d,-1,-1):
            m[b][z]*=g        
    l=[0]*i
    b=0
    z=i
    for g in m:
        for d in range (z):
            l[b]+=g[d]
        z+=-1
        b+=1
    s=fac3(y,r)
    for n in range (n):
        s*=l[0]
        for d in range(w):
            l[d]+=l[d+1]
    return s    
def par4(i):    
    m = [[0 for _ in range(i)] for _ in range(i)]    
    m[0][1]=-1
    m[0][3]=1
    g=i+1
    s=-4
    b=-5
    for f in range (5,g,2):
        for h in range (f,1,-2):
            f+=-2
            m[0][h]*=s
            m[0][h]+=m[0][f]
        m[0][1]*=s
        s+=b
        b+=-2
    return m 
def par5(l,m,w):
    f=1
    h=0
    for g in range (w,0,-1):
        a=g
        z=w-a
        for z in range(z,w,1):
            o=m[h][a]
            s=a
            a+=-1
            for s in range (a,-1,-1):
                m[f][s]+=o*l[z][s]
        h=f
        f+=1    
    return m
def par1(i,w):
    l=par3(i,w)
    m=par4(i)
    return par5(l,m,w)
def fac3(y,u):
    r=u-y
    a=r
    if r<4000:
        return fac2(y,u)
    a=a>>2
    a=int(math.sqrt(a))
    a=a>>1
    i=a<<1
    n=i<<2
    a=n*(i-1)
    r=u-a
    w=i-1
    m=par1(i,w)
    return par2(m,w,i,n,y,r)
#以下代码目的为测试上述函数，如果函数值与常规函数计算值一致，则打印成功，多次测试成功可以仅保留上述函数，删除以下测试代码。
import math
import time
import functools
def main():
     # 记录开始时间
    start_time = time.time()
    m = 10
    #每次测试请修改i的值，以验证是否成功。
    i = 1000000
    a = fac3(m,i)
            
        # 记录结束时间
    end_time = time.time()
        # 计算执行时间
    elapsed_time = end_time - start_time
    #print(a)
    print(f"Finished execution of: in {elapsed_time:.6f} seconds")
    start_time = time.time()
    i=math.factorial(i)//math.factorial(m)    
    
        # 记录结束时间
    end_time = time.time()
   
        # 计算执行时间
    elapsed_time = end_time - start_time
    if i==a:
        print("成功")
    print(f"Finished execution of: in {elapsed_time:.6f} seconds")        
if __name__ == "__main__":
     main()


