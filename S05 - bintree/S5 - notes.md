title: Session 5 - bintree
date: 2024-04-05
author: Artur Leivar

\# [%title]
# Session 5 - bintree

## BinTree `template <class T> class BinTree`
A BinTree is a binary tree, that is to say, is a tree graph were each node is
connected to its parent (with exception of the root) and can have none, one or
two childs.\
<pre>
                        a
                        |
                    ---- ----
                    |       |
                    b       c
                      .etc.             same as: a(b,c)
</pre>

To use it, we need to:\
`#include "BinTree.hh"`

### Constructors and consultors:
#### Declaration (is the empty tree):
`BinTree<T> t`; or `BinTree<T> t();`

#### To initialize a non-empty tree:
- Method 1: `BinTree<T> t(int value);`
- Method 2: `BinTree<T> t(int value, BinTree<T> left_tree, BinTree<T> right_tree);`
- Method 3: `BinTree<T> t = a;` // (a is a tree)

#### To consult the values of a tree:
`t.value();` // value of root (top node)\
`t.left();` // left tree of t\
`t.right();` // right tree of t\
`t.empty();` // returns false if empty, true otherwise\
We can concatenate this consultors: t.left().right().value() etc.

**BE CAREFUL:**\
If t.left() is empty, t.left().value() will give errors.

**BE CAREFUL:**\
BinTrees are IMMUTABLE, we cannot modify them. We can, though, create a new
binary tree with parts from others.\
For example:
```c++
    // Wrong:
    t.left() = BinTree<T>(a);
    // Instead:
    t = BinTree<T> (t.value(), BinTree<T>(a), t.right());
```

`t.setOutputFormat(BinTree<int>::INLINEFORMAT);` // efficient format with parenthesis\
`t.setOutputFormat(BinTree<int>::VISUALFORMAT);` // visual pretty format\
// there also are `t.setInputFormat();` and `t.setInputOutputFormat();`\
// `cout << t;` works for common data types (int, double, string, char, etc.)

### Recursion
Solving bintree problems with recursion is easy and straightforward, as you
usually need to define:
```c++
left = recursive_function(t.left();
right = recursive_function(t.right());
return BinTree<T>(value, left, right);
```
where left and right are the modified trees and value is whatever the problem
asks for.
