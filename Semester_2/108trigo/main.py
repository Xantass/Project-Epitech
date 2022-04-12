##
## EPITECH PROJECT, 2021
## 108trigo
## File description:
## 108trigo
##

import sys
from check import *

def main():
    tab = []
    check_parameters()
    sqi = error_mngmt()
    for i in range(int(sqi)):
        tab.append([])
        for j in range(int(sqi)):
            tab[i].append(sys.argv[i * int(sqi) + j + 2])
    tab = launch_func(tab)
    print_matrix(tab)