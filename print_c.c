#include "main.h"
/**
 * print_c - prints a character
 * @symbol: conversion specifier symbol to match
 * Return: func pointer to func matched by symbol
 */

void print_c(va_list list)
{
	char *ch_point;
	char ch;

	ch = va_arg(list, int);
	ch_point = &ch;
	write(1, ch_point, 1);
}
