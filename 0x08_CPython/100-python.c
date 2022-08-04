#include <stdio.h>
#include <Python.h>

#ifdef _LP64
#define DECIMAL_SHIFT  9
#define DECIMAL_BASE   ((digit)1000000000)
#else
#define DECIMAL_SHIFT  4
#define DECIMAL_BASE   ((digit)10000)
#endif

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define SSIZE_T_MAX ((Py_ssize_t)(((size_t)-1) >> 1)) /* LONG_MAX on 64-bit */



/**
* _PyLongBaseToBase10 - helper to print_python_int
* @size: array size
* @arr_in: array
* @arr_out: array of base 10 digits
* Return: size array
*/
static Py_ssize_t _PyLongBaseToBase10(Py_ssize_t size,
				      digit *arr_in, digit *arr_out)
{
	Py_ssize_t new_size, i, j;
	digit hi;
	twodigits z;

	new_size = 0;
	for (i = size; --i >= 0; )
	{
		hi = arr_in[i];
		for (j = 0; j < new_size; j++)
		{
			z = (twodigits)arr_out[j] << PyLong_SHIFT | hi;
			hi = (digit)(z / DECIMAL_BASE);
			arr_out[j] = (digit)(z - (twodigits)hi * DECIMAL_BASE);
		}
		while (hi)
		{
			arr_out[new_size++] = hi % DECIMAL_BASE;
			hi /= DECIMAL_BASE;
		}
	}

	if (new_size == 0)
		arr_out[new_size++] = 0;

	return (new_size);
}


/**
* _printPyLong - helper to print_python_int
* @b10_size: array size
* @b10_arr: array of values
* @strlen: buffer length
* @negative: positive flag
* Return: 0 on success, 1 on failure
*/
static int _printPyLong(Py_ssize_t b10_size, digit *b10_arr,
			Py_ssize_t strlen, int negative)
{
	char *str = NULL, *pr = NULL;
	Py_ssize_t i, j;
	digit rem;

	str = malloc(sizeof(char) * (strlen + 1));
	if (!str)
		return (1);
	str[strlen] = '\0';

	pr = str + strlen;

	for (i = 0; i < b10_size - 1; i++)
	{
		rem = b10_arr[i];
		for (j = 0; j < DECIMAL_SHIFT; j++)
		{
			*--pr = '0' + rem % 10;
			rem /= 10;
		}
	}

	rem = b10_arr[i];
	do {
		*--pr = '0' + rem % 10;
		rem /= 10;
	} while (rem != 0);
	if (negative)
		*--pr = '-';

	if (pr != str)
	{
		free(str);
		return (1);
	}
	puts(str);
	free(str);
	return (0);
}


/**
* print_python_int - prints int object
* @p: PyObject *-castable struct pointer
*/
void print_python_int(PyObject *p)
{
	PyLongObject *pl;
	Py_ssize_t b10_size, strlen, size_pl;
	digit rem, tenpow, *b10_digit = NULL;
	int negative, d;

	pl = (PyLongObject *)p;
	if (!pl || !PyLong_Check(pl))
	{
		printf("Invalid Int Object\n");
		return;
	}
	negative = ((PyVarObject *)p)->ob_size < 0;
	size_pl = ABS(((PyVarObject *)p)->ob_size);
	if (size_pl >= SSIZE_T_MAX / 2)
	{
		fprintf(stderr, "size_pl over limit of SSIZE_T_MAX / 2\n");
		return;
	}

	d = (33 * DECIMAL_SHIFT) / (10 * PyLong_SHIFT - 33 * DECIMAL_SHIFT);
	b10_size = 1 + size_pl + size_pl / d;
	b10_digit = malloc(sizeof(digit) * b10_size);
	if (b10_digit == NULL)
	{
		fprintf(stderr, "b10_digit malloc failure\n");
		return;
	}
	b10_size = _PyLongBaseToBase10(size_pl, pl->ob_digit, b10_digit);

	strlen = negative + 1 + (b10_size - 1) * DECIMAL_SHIFT;
	tenpow = 10;
	rem = b10_digit[b10_size - 1];
	while (rem >= tenpow)
	{
		tenpow *= 10;
		strlen++;
	}

	if (_printPyLong(b10_size, b10_digit, strlen, negative) == 1)
		fprintf(stderr, "_printPyLong err\n");
}
