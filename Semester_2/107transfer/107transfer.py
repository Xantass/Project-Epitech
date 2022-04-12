#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## 107transfer
## File description:
## 107transfer
##

import sys
import math
import numpy
from numpy import zeros, array

argv = sys.argv

def calc(tab, x):
    try:
        i = len(tab) - 1
        res = 0
        while i >= 0:
            if (i != 0):
                res = res + (tab[i] * pow(x, i))
            else:
                res = res + tab[i]
            i = i - 1
    except:
        exit(84)
    return res

def calc_main(argv):
    res = 1
    x = 0.000
    nb_1 = 0
    nb_2 = 0
    div = 0

    while x <= 1.001:
        for i in range(0, len(argv), 2):
            nb_1 = calc(argv[i], x)
            nb_2 = calc(argv[i + 1], x)
            if (nb_2 == 0):
                exit(84)
            div = nb_1 / nb_2
            res = res * div
            print("{:.3f} -> {:.5f}".format(x, res))
            res = 1
            x = x + 0.001
    return 0

def argument(argv):
    try:
        del argv[0]
        for i in range(0, len(argv)):
            argv[i] = argv[i].replace("*", "")
        for i in range(0, len(argv), 1):
            a = zeros(len(argv[i]) - argv[i].count('-'), int)
            h = 0
            j = 0
            while j < len(argv[i]):
                if (argv[i][j] != '-'):
                    a[h] = int(argv[i][j])
                if (argv[i][j] == '-'):
                    j = j + 1
                    a[h] = int(argv[i][j])
                    a[h] = a[h] * -1
                j = j + 1
                h = h + 1
            argv[i] = a
    except:
        exit(84)
    calc_main(argv)
    return 0

def argv_h():
    print("USAGE")
    print("    ./107transfer [num den]*")
    print()
    print("DESCRIPTION")
    print("    num     polynomial numerator defined by its coefficients")
    print("    den     polynomial denominator defined by its coefficients")

def main():
    i = len(sys.argv)
    if (i == 1):
        exit(84)
    if (argv[1] == "-h"):
        argv_h()
        exit(0)
    if (i % 2 == 0):
        exit(84)
    argument(argv)
    return 0

main()