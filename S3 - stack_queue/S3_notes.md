title: Session 3 - Stack and Queue
date: March 2024

# [%title]

## flag D_GLIBCXX_DEBUG
If a program that uses the stack or queue classes executes primitive operations 
in wrong cases, mainly querying or removing an element from an empty stack or 
queue, it may happen that the program continues its execution, but working in 
unpredictable ways.\
Using the D_GLIBCXX_DEBUG flag, it is achieved that when such an error occurs, 
execution will be interrupted and an informational message will be provided.
If we know exactly the operation “culprit” of the error and the class of the 
objects involved it will be easier for us to find and correct it.

## Makefile
(see info_Makefile.txt)

## Stack `template <class T> class stack`
Linear structure containing T-type elements and which allows you to query and 
remove only the last added element. The time cost of all operations is constant,
except for the copy and the destructor, which have linear cost with respect to the
size of the original stack (in these, and in push, pop and top, you must also
take into account the cost of the copy or delete each object).\

### Constructors:
* `stack();`\
// Pre: True\
// Post: An empty stack
* `stack(const stack<T>& original);`\
// Pre: True\
// Post: A copy of the original stack

### Destructor:
* `~stack();`\
// Deletes automatically the local objects when leaving its scope of visibility.

### Modifiers:
* `void push(const T& x);`\
// Pre: True\
// Post: The implicit parameter is like the original implicit parameter with x 
//  added as the last element.
* `void pop();`\
// Pre: Implicit parameter is not empty\
// Post: The implicit parameter is like the original implicit parameter but 
//  without the last element added to the original implicit parameter

### Consultants:
* `T top() const;`\
// Pre: The implicit parameter is not empty\
// Post: The result is the last value added to the implicit parameter
* `bool empty() const;`\
// Pre: True\
// Post: The result shows if the implicit parameter is empty or not
* `inst size() const;`\
// Pre: True\
// Post: The result is the number of elements of the implicit parameter

## Queue `template <class T> class queue`
Linear structure containing T-type elements and which allows you to query and
delete only the first element added. The time cost of all operations is constant,
except for the copy and the destructor, which have linear cost with respect to the
size of the original queue (in these, and in push, pop and front, you also need
to take into account the cost of the copy or delete each object)

### Constructors:
* `queue();`\
// Pre: true\
// Post: The result is a queue with no elements
* `queue(const queue<T>& original);`\
// Pre: true\
// Post: The result is a queue copy of original

### Destructor:
* `~queue();`\
// Automatically clears local objects on exit of a scope of visibility

### Modifiers:
* `void push(const T& x);`\
// Pre: true\
// Post: The implicit parameter is like the original implicit parameter
//  with x added as last element
* `void pop();`\
// Pre: Implicit parameter is not empty\
// Post: The implicit parameter is like the original implicit parameter
//  but without the first element added to the original implicit parameter

### Consultants:
* `T front() const;`\
// Pre: Implicit parameter is not empty\
// Post: The result is the oldest value added to the implicit parameter
* `bool empty() const;`\
// Pre: true\
// Post: The result indicates whether the implicit parameter is empty or not
* `const int size();`\
// Pre: true\
// Post: The result is the number of elements in the implicit parameter

## Tar archive
```sh
tar -cvf files.tar file1 file2
tar -tvf files.tar
```

**-A**, Append to an archive\
**-c**, Create a new archive. Arguments supply the names of the files to be archived.
    Directories are archived recursively, unless the --no-recursion option is given.\
**-f**, Specify archive file or device\
**-t**, List the contents of an archive\
**-u**, Update archive\
**-v**, Verbosely list files processed. The maximum verbosity level is 3.\
**-x**, Extract files from an archive
