#Многомерная интерполяция
from math import *

def func(x, y):
    z = x**2 + y**2
    return z

def search_boundaries(pol, n_o, lenth):
    if (lenth - pol) < 0:
        print('Недостаточно данных в таблице')
    else:
        left_pol = n_o - round(pol/2) - 1
        dif = 0
        if (left_pol < 0):
            dif = 0 - left_pol0
            left_pol = 0
        right_pol = n_o + (pol - (n_o - left_pol)) + dif
        if (right_pol >= lenth):
            dif = right_pol - lenth
            right_pol = lenth - 1
            left_pol = left_pol - dif
    return left_pol, right_pol

def filling_table(K, index = 1):
    if (len(K[index]) >= 2):
        K.append([])
        #print(K)
        for i in range(len(K[index])-1):
            '''print('i = ',i)
            print('index = ',index)'''
            K[index+1].append((K[index][i] - K[index][i+1])/(K[0][i] - K[0][i+index]))
        K = filling_table(K, index+1)
    return K
def interpol(X, found, pol):
    if (X[0].count(found)):
        for i in range(0, len(X[0])):
            if X[0][i] == found:
                return X[1][i]
    n_o = len(X[0])
    for i in range(1, len(X[0])):
        if (X[0][i-1] < found) and (X[0][i] > found):
            n_o = i
            break
    left_pol, right_pol = search_boundaries(pol, n_o, len(X[0]))
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
    return y


################# Основная программа #################
print('\t Значение для X ')
left_x = float(input("Ведите левую границу "))
right_x = float(input("Ведите правую границу "))
num_x = int(input("Ведите количество точек "))
pol_x = int(input("Ведите степень полинома "))

print('\t Значение для Y ')
left_y = float(input("Ведите левую границу "))
right_y = float(input("Ведите правую границу "))
num_y = int(input("Ведите количество точек "))
pol_y = int(input("Ведите степень полинома "))

print('\t Искомая точка ')

#found_y = float(input("Ведите ординату для поиска "))
found_x, found_y = map(float,input("Ведите точку для поиска ").split(' '))

'''left_x = -2
right_x = 2
num_x = 5
found_x = 0.5
pol_x = 2


left_y = -3
right_y = 3
num_y = 7
found_y = -0.9
pol_y = 3'''

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

#print(Z)
flag = 0

X = [[],[]]
Y = [[],[]]

for j in range(1, len(Z[0])):
    for i in range(1,len(Z)):
        X[0].append(Z[i][0])
        X[1].append(Z[i][j])
    #print(X)
    Y[1].append(interpol(X, found_x, pol_x))
    X = [[],[]]
#print(Y)

for i in range(1, len(Z[0])):
    Y[0].append(Z[0][i])
#print(Y)
otvet = interpol(Y, found_y, pol_y)
print('Значение интерполяции: {:.4f}'.format(otvet))
print('Точное значение: {:.4f}'.format(func(found_x,found_y)))
if func(found_x,found_y)!=0:
    print('Погрешность: {:.4f}'.format(abs((otvet-func(found_x,found_y))/(func(found_x,found_y)))))
