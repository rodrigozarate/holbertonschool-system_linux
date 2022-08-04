#include <stdio.h>
#include <Python.h>
#include <wchar.h>
#include <locale.h>


/**
* print_python_string - prints basic object info
* @p: object
*/
void print_python_string(PyObject *p)
{
	wchar_t *wchar_buf = NULL;

	printf("[.] string object info\n");

	if (!PyUnicode_Check(p) || !((PyASCIIObject *)p)->state.ready)
	{
		printf("  [ERROR] Invalid String Object\n");
		return;
	}

	printf("  type: %s%s\n",
	       ((PyASCIIObject *)p)->state.compact ? "compact " : "",
	       ((PyASCIIObject *)p)->state.ascii ? "ascii" : "unicode object");

	printf("  length: %li\n",
	       ((PyASCIIObject *)(p))->length);

	wchar_buf = PyUnicode_AsWideCharString(p, NULL);
	if (wchar_buf != NULL)
	{
		printf("  value: %ls\n", wchar_buf);
		PyMem_Free(wchar_buf);
	}
}
