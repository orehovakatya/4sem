from math import *

def func(x, y):
    z = x**2 + y**2
    return z

def search_boundaries(pol, n_o, lenth):
    if (lenth - pol) < 0:
        print('Недостаточно данных в таблице')
    else:
        #print(n_o)
        left_pol = n_o - round(pol/2)
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
################# Основная программа #################
'''print('\t Значение для X ')
left_x = float(input("Ведите левую границу "))
right_x = float(input("Ведите правую границу "))
num_x = int(input("Ведите количество точек "))
found_x = float(input("Ведите ординату для поиска "))
pol_x = int(input("Ведите степень полинома "))

print('\t Значение для Y ')
left_y = float(input("Ведите левую границу "))
right_y = float(input("Ведите правую границу "))
num_y = int(input("Ведите количество точек "))
found_y = float(input("Ведите ординату для поиска "))
pol_y = int(input("Ведите степень полинома "))'''

left_x = -2
right_x = 2
num_x = 5
found_x = 0.5
pol_x = 2


left_y = -3
right_y = 3
num_y = 7
found_y = -0.9
pol_y = 3

step_x = (right_x-left_x)/(num_x-1)
x = left_x
step_y = (right_y-left_y)/(num_y-1)
y = left_y

Z = []
Z.append([])
for i in range(1,num_x+1):
    Z.append([])
    Z[i].append(x)
    x += step_x
Z[0].append(0)
for j in range(1,num_y+1):
    Z[0].append(y)
    y += step_y

for i in range(1,num_x+1):
    for j in range(1, num_y+1):
        Z[i].append(func(Z[i][0], Z[0][j]))

print(Z)
flag = 0

X = []
X.append([])
X.append([])
for j in range(1, len(Z[0])):
    for i in range(1,len(Z)):
        X[0].append(Z[i][0])
        X[1].append(Z[i][j])
    print(X)
    X = []
    X.append([])
    X.append([])
    

'''if (X[0].count(found)):
    print('Искомое значение нашлось в таблице\n')
else:
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
    zn = func(found)
    print('Результат интерполяци:',y)
    print('Точное значение:',zn)
    if (zn != 0):
        print('Погрешность: ','{:g}'.format(abs(zn - y)/zn))'''
