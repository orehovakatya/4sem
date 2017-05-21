from math import *

def func(t):
    return exp(-t**2/2)

def funcLegendre(x,n):
    p_prev = 1
    p_curr = x
    if (n == 0):
        return p_prev;
    for i in range(1,n,1):
        res = ((2.0 * i + 1.0) / (i + 1.0)) * x * p_curr - (i / (i + 1.0)) * p_prev
        p_prev = p_curr
        p_curr = res
    return p_curr

def Dihotomy(a, b, alpha,n):
    x = 0
    #print('Dihotomy')
    if (a == b):
        return 1, x
    if ((funcLegendre(a,n)-alpha)*(funcLegendre(b,n)-alpha)> 0):
        #print('Dihotomy')
        return 0, x
    c = 0
    #print('Dihotomy1')
    for i in range(5000):
        c = (a+b)/2
        if (abs(funcLegendre(c,n) - alpha) < 0.000001):
            return 1, c
        if ((funcLegendre(a,n)-alpha)*(funcLegendre(c,n)-alpha) < 0):
            b = c
            continue
        if ((funcLegendre(c,n)-alpha)*(funcLegendre(b,n)-alpha) < 0):
            a = c
    return 0, x

def Legendre(n,alpha):
    parts = n
    roots = []*n
    count = 0
    print('Legendre')
    while count<n:
        count = 0
        parts *= 3 ####Почему на 3?!
        #print(parts)
        step = 2 / parts
        a = -1
        b = a + step
        print(b)
        for i in range(parts):
            p, x = Dihotomy(a, b,alpha,n);
            if p == 1:
                roots.append(x)
                count += 1
            if (count == n):
                break
            a += step
            b += step
        print('count = ', count)
    return roots

def GaussEq_Solve(tcoeffs, answer, n):
    PTemp = []
    Temp = 0

    coef = tcoeffs
    answ = answer

    for k in range(n):
        if (abs(coef[k][k] - 0) < 0.000001):
            Row = 0
            for i in range(n):
                if (abs(coef[i][k] - 0) > 0.000001):
                    Row = i
                    break
            PTemp = coef[Row]
            coef[Row] = coef[k]
            coef[k] = PTemp
            Temp = answ[Row]
            answ[Row] = answ[k]
            answ[k] = Temp
        Temp = coef[k][k]
        for i in range(n):
            coef[k][i] /= Temp
        answ[k] /= Temp
        for i in range(k):
            Temp = coef[i][k]
            for j in range(n):
                coef[i][j] -= coef[k][j]*Temp
            answ[i] -= answ[k]*Temp
        for i in range(k+1,n,1):
            Temp = coef[i][k]
            for j in range(n):
                coef[i][j] -= coef[i][j]*Temp
            answ[i] -= answ[k]*Temp
    return answ

def SearchA(t,n):
    tcoeffs = []
    tcoeffs.append([])
    #print(tcoeffs)
    #print(t)
    answer = []
    for k in range(n):
        tcoeffs.append([])
        for i in range(n):
            tcoeffs[k].append(t[i]**k)
        if (k % 2 == 1):
            answer.append(0)
        else:
            answer.append(2/(k+1))
    return GaussEq_Solve(tcoeffs, answer, n)

def IntegrateByGauss(a, b, n,alpha):
    if (a == b):
        return 0
    print('IntegrateByGauss')
    t = Legendre(n,alpha)
    print('IntegrateByGauss1')
    A = SearchA(t,n)
    print('IntegrateByGauss2')
    integral = 0;
    for i in range(n):
        x_i = (b-a)/2*t[i]+(b+a)/2;
        integral += A[i]*func(x_i)
    integral *= (b-a)/2
    return integral

def MyDichotomy(n, alpha, a, b = 1):
    x = a
    if (alpha == 0):
        return 1, x
    c = b*2
    abs_alpha = abs(alpha)
    for i in range(5000):
        print(i)
        intg = abs(IntegrateByGauss(a , b, n, alpha))
        print(i)
        intg2 = abs(IntegrateByGauss(a , c, n,alpha))
        print(i)
        if abs(intg - abs_alpha) < 0.000001:
            if (alpha < 0):
                b = -b
            x = b
            return 1, x
        if ((intg < abs_alpha)and(intg2 > abs_alpha)):
            b = (b + c)/2
            continue
        if ((intg < abs_alpha)and(intg2 < abs_alpha)):
            b = (b + c)/2
            c = b * 2
            continue
        if ((intg > abs_alpha)and(intg2 > abs_alpha)):
            b = b-(c - b)/2
            c = b*2
            continue
    return 0, x
        



alpha = 0.2
alpha *= 2*pi

n = 2

i, x = MyDichotomy(n, alpha, 0, b = 1)

print(i,x)
