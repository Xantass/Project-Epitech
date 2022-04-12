##
## EPITECH PROJECT, 2021
## 109titration
## File description:
## main
##

import sys
from utils import *
from calc import *

def titration(data):
	derive = calc_deriv(data)
	calc_deriv_bis(derive, data)
	calc_deriv_bis_estimation(derive, data)

def main():
	check_arguments()
	data = load_csv_file()
	titration(data)