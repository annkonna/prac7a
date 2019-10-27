Pointer Arithmetic to get records from a data structure - Practice
===

In this practice, you will implement a function to get records
from an Employee data structure.

Requirements
---

You must implement the `get_emps()` function in `empget.c`.  This
function will be passed a data structure of type `void *` 
called 'data' and a 'char *' named 'table' that you will fill with
comma-separated lines containing the records from the data structure.

The data structure holds the following information as a set of records:

Employee_ID, Name, Title, Boss, Department, Salary

The format of the data structure that stores the details of a particular
employee record is as follows:

| long | char[50] | char[50] | char[50] | char[50] | long |

The structure above is repeated for each row in the table. End of data
is indicated by an Employee_id value of 0. 

You will need to validate the following about the employee information in
the data structure:

 1. Employee_ID should be between 1 and MAX_EMP_ID (inclusive)
 2. All character data should be less than MAX_STRING_SIZE
 3. Salary should be between MIN_SALARY and MAX_SALARY (inclusive)


Building, Running, and Testing
---

The command `make` will build a binary called `empget` that you can
run using the command:

./empget < employees.out > employees.txt

If your function works correctly, employees.txt would show four rows.
Each row will be a comma-separated sequence of 6 columns containing a
particular employee's details. 


Hints
---

Although there are different ways to convert a long column to a string,
the easiest will be to use the function sprintf. Seem 'man 3 sprintf'
for details. This will be useful when copying the first and last columns
which are of type 'long'. The other columns are strings (type 'char *')
that are null terminated and so 'strcpy' can be used to copy.

Notice that unlike in the data structure, you need to separate each column
with a comma (',') and each row with a line terminator ('\n'). Also once
the table is copied, you will need to terminate it with a line
terminator ('\0'). 

Remember that pointer math on a `void *` pointer is in terms of _bytes_,
while many data types (such as `size_t`!) are larger than one byte.  You
can add increments of `sizeof(type)` to adjust a `void` pointer by the
size of another type.

Pointer casting works like casting of any other type.  For example:

```C
int readptr(void *ptr) {
    return *(int *)ptr;
}
```

This function accepts a `void` pointer argument, but interprets the data
stored at the pointer as an `int` pointer.  A `void` pointer _cannot be
directly dereferenced_, you will _have_ to cast it in order to read the
data to which it points.

