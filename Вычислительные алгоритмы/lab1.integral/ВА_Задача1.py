#Интеграл от неявнозаданной функции
from math import *

def func(x, y): #Неявнозаданная функция
    f = exp(x**3)-(exp(y))*(x**6 - 2*(x**3)*y - 2*(x**3) + y**2 + 2*y +2)
    return f

def found_y(x, eps = 1e-8):
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

def integrall(x_left, x_right, eps = 1e-8):
    S1 = ((found_y(x_left, eps)+found_y(x_right, eps))/2*(x_right - x_left))
    step = 1
    while 1:
        step *= 2
        h = (x_right - x_left)/step
        left = x_left
        S2 = (found_y(x_left,eps)+found_y(x_right,eps))/2
        for i in range(1, step-1):
            left += h
            S2 += found_y(left,eps)
        S2 = S2*h
        if (abs(S2-S1) < eps*S1 + eps):
            break
        S1 = S2
    print(step)
    return S2
            
        
        
        
    

############ Основная программа ############
MIN_LEFT = 0
MAX_RIGHT = 2

eps = 1e-4

print(integrall(MIN_LEFT, MAX_RIGHT, eps))

