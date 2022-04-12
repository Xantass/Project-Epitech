#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## bombix.py
## File description:
## function
##

import sys
import math
import numpy

argv = sys.argv

def first_m(n, k):
    i = 1
    print("{:} {:.2f}".format(i, n))
    i = i + 1
    while i <= 100:
        n = k * n *((1000 - n) / 1000)
        print("{:} {:.2f}".format(i, n))
        i = i + 1
    return 0

def second_m(n, i0, i1):
    k = 1.00
    i = 1
    while k <= 4:
        i = 1
        while i <= i1:
            while i < i0:
                n = k * n *((1000 - n) / 1000)
                i = i + 1
            n = k * n *((1000 - n) / 1000)
            print("{:.2f} {:.2f}".format(k, n))
            i = i + 1
        k = k + (1 / 100)
    return 0

def check_first(n, k):
    if (k < 1):
        print("invalid argument check the -h")
        exit(84)
    if (k > 4):
        print("invalid argument check the -h")
        exit (84)
    if (n < 0):
        print("invalid argument check the -h")
        exit (84)
    first_m(n, k)
    return 0

def check_second(n, i0, i1):
    if (n < 0):
        print("invalid argument check the -h")
        exit (84)
    if (i0 < 0):
        print("invalid argument check the -h")
        exit (84)
    if (i1 <= 0):
        print("invalid argument check the -h")
        exit (84)
    if (i1 < i0):
        print("invalid argument check the -h")
        exit (84)
    second_m(n, i0, i1)
    return 0
    
def main():
    i = len(sys.argv)
    if (i == 3):
        try:
            n = int(argv[1])
            k = float(argv[2])
        except:
            print("invalid argument check the -h")
            exit(84)
        check_first(n, k)
        return 0
    if (i == 4):
        try:
            n = int(argv[1])
            i1 = int(argv[3])
            i0 = int(argv[2])
        except:
            print("invalid argument check the -h")
            exit(84)
        check_second(n, i0, i1)
        return 0
    else:
        print("invalid argument check the -h")
        exit(84)
    return 0

main()
