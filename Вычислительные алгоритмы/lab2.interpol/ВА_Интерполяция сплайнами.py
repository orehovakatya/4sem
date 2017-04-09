#Интерполяция сплайнами
#Система уравнений
from math import *

def func(x, y): #Неявнозаданная функция
    f = exp(x**3)-(exp(y))*(x**6 - 2*(x**3)*y - 2*(x**3) + y**2 + 2*y +2)
    return f

def func2(x, y):
    f = exp(2*log(x)-y) + y*exp(-y) - (exp(x**2))*log(x**2+y)
    return f

def found_y(x, eps = 1e-3):
    y_left = -0.1
    y_right = 0.1
    while (func(x, y_left)*func(x, y_right) > 0):
        y_left = y_left-0.1
        y_right = y_right+0.1
    y_midle = y_left + (y_right - y_left)/2
    while ( (y_right-y_left) > eps*abs(y_midle) + eps):
        if (func(x, y_left)*func(x, y_midle) > 0):
            y_left = y_midle
            y_midle = y_left + (y_right - y_left)/2
        elif (func(x, y_left)*func(x, y_midle) < 0):
            y_right = y_midle
            y_midle = y_left + (y_right - y_left)/2
    return y_midle

def search_boundaries(pol, n_o, lenth):
    if (lenth - pol) < 0:
        print('Недостаточно данных в таблице')
    else:
        #print(n_o)
        left_pol = n_o - round(pol/2) - 1
        dif = 0
        #print('left_pol = ',left_pol)
        if (left_pol < 0):
            dif = 0 - left_pol
            left_pol = 0
        #print()
        right_pol = n_o + (pol - (n_o - left_pol)) + dif
        if (right_pol >= lenth):
            #print('1')
            dif = right_pol - lenth
            right_pol = lenth - 1
            left_pol = left_pol - dif
    return left_pol, right_pol

def filling_table(K, index = 1):
    if (len(K[index]) >= 2):
        K.append([])
        #print(K)
        for i in range(len(K[index])-1):
            K[index+1].append((K[index][i] - K[index][i+1])/(K[0][i] - K[0][i+index]))
        K = filling_table(K, index+1)
    return K

        
        
    

############ Основная программа ############
pol = int(input('Введите степень полинома '))
pol += 1
MIN_LEFT = 0.7
MAX_RIGHT = 1.0
N = 50

eps = 1e-5
step = (MAX_RIGHT-MIN_LEFT)/N

X=[[],[]]
for i in range(N):
    X[1].append(MIN_LEFT)
    X[0].append(func2(MIN_LEFT,found_y(MIN_LEFT)))
    #print(MIN_LEFT, func2(MIN_LEFT,found_y(MIN_LEFT)))
    #print(X[0][i], X[1][i])
    MIN_LEFT += step
#print(X)
for i in range(len(X[0])):
    for j in range(len(X[0])):
        if (X[0][i] > X[0][j]):
            a = X[0][j]
            X[0][j] = X[0][i]
            X[0][i] = a
            a = X[1][j]
            X[1][j] = X[1][i]
            X[1][i] = a
#print(X[0])
'''for i in range(len(X[0])):
    print(X[0][i],X[1][i])'''
found = 0.0
n_o = len(X[0])
for i in range(1, len(X[0])):
    if (X[0][i-1] < found) and (X[0][i] > found):
        n_o = i
        break
left_pol, right_pol = search_boundaries(pol, n_o, len(X[0]))
#print(left_pol, right_pol)

#K - Конфигурация и таблица разделённых разностей
K = []
K.append([])
K.append([])
for i in range(left_pol, right_pol+1):
    K[0].append(X[0][i])
    K[1].append(X[1][i])

#заполнение таблицы К
K = filling_table(K)
#print(K)
y = 0.0
for i in range(len(K)-1, 1, -1):
    y = (K[i][0] +y) * (found - K[0][i-2])
y += K[1][0]
print('x={:.4f}'.format(y),'y={:.4f}'.format(found_y(y)))

print(func(y, found_y(y)))

#print(integrall(MIN_LEFT, MAX_RIGHT, eps))


