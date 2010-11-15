/* -*- mode: C -*-  */
/* vim: set ts=2 sw=2 sts=2 et: */

/* 
   IGraph library.
   Copyright (C) 2006-2010  Gabor Csardi <csardi@rmki.kfki.hu>
   MTA RMKI, Konkoly-Thege Miklos st. 29-33, Budapest 1121, Hungary
   
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc.,  51 Franklin Street, Fifth Floor, Boston, MA 
   02110-1301 USA

*/

#include <Python.h>

#if PY_MAJOR_VERSION >= 3

/* Python 3.x-specific part follows here */
#define IGRAPH_PYTHON3

#define PyBaseString_Check(o) PyUnicode_Check(o)

PyObject* PyFile_FromObject(PyObject* filename, const char* mode);

#define PyIntObject    PyLongObject
#define PyInt_AsLong   PyLong_AsLong
#define PyInt_Check    PyLong_Check
#define PyInt_FromLong PyLong_FromLong

#define PyNumber_Int   PyNumber_Long

#define PyString_AS_STRING  PyUnicode_AS_UNICODE
#define PyString_Check      PyUnicode_Check
#define PyString_FromFormat PyUnicode_FromFormat
#define PyString_FromString PyUnicode_FromString
#define PyString_Type       PyUnicode_Type
#define PyString_IsEqualToASCIIString(uni, string) \
        (PyUnicode_CompareWithASCIIString(uni, string) == 0)

#ifndef PyVarObject_HEAD_INIT
#define PyVarObject_HEAD_INIT(type, size)            \
        PyObject_HEAD_INIT(type) size,
#endif

int PyString_IsEqualToUTF8String(PyObject* py_string,
    const char* c_string);

#else

/* Python 2.x-specific part follows here */

#define PyBaseString_Check(o) (PyString_Check(o) || PyUnicode_Check(o))
#define PyString_IsEqualToASCIIString(pystr, cstr) \
        (PyString_Check(pystr) && strcmp(PyString_AS_STRING(pystr), (cstr)) == 0)

#endif

char* PyObject_ConvertToCString(PyObject* string);
char* PyString_CopyAsString(PyObject* string);

