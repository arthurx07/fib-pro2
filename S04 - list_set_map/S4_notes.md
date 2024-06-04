title: Session 4 - lists, maps and sets
date: 2024-03-09
author: Artur Leivar

# [%title]

## List `template \<class T> class list`
Linear structure containing T-type elements, which can start to be consulted
from the ends, where from each element it's possible to access the previous and
next element (if they exist), and that supports adding and removing elements
from it at any point.\
The time cost of all operations is constant, except for the copier, the destructor
and clear, which have linear cost with respect to the size of the original list
(in these, and in insert and erase, you must also take into account the cost of
copying or deleting each involved object of type T).\
**Pros of lists vs vectors:** With lists we can add elements in the middle of a
list with linear cost. The elements don't need to be contiguous in memory, and
it is not possible to use indexes, but with an iterator we can easily add
new elements to the middle of a list.

### **Push_back() and vectors:**
**Pros:** Solves the problem of the fixed capacity of vectors. Simplifies the use
of vectors. The access to a position of a vector has constant time in respect of
the size of the vector. The time cost of push_back is amortized constant.\
**Cons:** Though the time cost being amortized constant, in the worst case when
the allocated memory is full, the allocated space is augmented to the double
of the memory the vector takes up in memory. On these occasions, the operation
is very slow. And the vector may be useing more memory than what size() shows.\
**Abusing cases:** When using vectors to represent any type of sequence. When the
maximum capacity of the vector is known and it's not very big, and using push_back
instead of declaring it with a fixed size.

### Constructors:

* `list();`\
// Pre: True\
// Post: An empty list

* `list(const list& original);`\
// Pre: True\
// Post: A copy of the original list

### Destructor:
* `~list();`\
// Automatically cleans the local objects when leaving its visibility scope

### Modifiers:
* `void clear();`\
// Pre: True\
// Post: The implicit parameter is an empty list

* `void insert(iterator it, const T& x);`\
// Pre: It references some existing element in the implicit parameter or
    is equal to the end of this.\
// Post: The implicit parameter is like the original implicit parameter with x
    in front of the element referenced by it in the original implicit parameter.

* `iterator erase(iterator it);`\
// Pre: it references some existing element in the implicit parameter,
    which is not empty.\
// Post: The implicit parameter is like the original implicit parameter without
    the element referenced by the original it; the reference result
    the element following the one referred to by it in the i.p. original.\

**// Note:** If we want the it itself to refer to the next element
    to which he referred to the i.p. original of a list l, we must call
    it = l.erase(it).

* `void splice(iterator it, list& l);`\
// Pre: l=L, it references some element of the implicit parameter or
    is equal to the end of this, l and the i.p. they are not the same object.\
// Post: The elements of L, inserted, have been transferred to the implicit parameter
    before the element referenced by it; l is empty

Lists allow the usage of `push_back()`, `push_front()`, `pop_back()` and
`pop_front()` to add or remove elements from the extremes of the list, so that
using iterators is not always necessary.

### Consultants:
* `bool empty() const;`\
// Pre: True\
// Post: The result indicates if the implicit parameter has elements or not.

* `int size() const;`\
// Pre: True\
// Post: The result is the number of elements of the implicit parameter.

## Set `template \<class T> class set`
Set containing elements of type T; the elements are ordered ascending by the
order defined in T, which cannot be repeated; you can consult and modify
elements by the ends, where from each element can access the previous and
subsequent element (if exist), and that supports adding and removing elements
from it.\
The time cost of all operations is constant, except:

* searches, insert and erase without good position, which are logarithmic with
    respect to set size
* the copier, the destructor and clear, which have a linear cost with respect
    to the size of the original set (in these, and in insert and erase, you
    must also have en count the cost of copying or deleting each involved object of type T)

Lastly, though in theory sets are not ordered (and the uses sees them that way),
they are stored in memory in an ordered way. This is why all used data types
need to have the function 'less than <' defined to be used in a set. Thanks to
this, the access time can be logarithmic.

### Constructors:
* `set();`\
// Pre: true\
// Post: The result is a set with no elements

* `set(const set& original);`\
// Pre: true\
// Post: The result is a set copy of the original

### Destructor:
* `~set();`\
// Automatically clears local objects on exiting one scope of visibility

### Modifiers:
* `void clear();`\
// Pre: true\
// Post: The implicit parameter is an empty set

* `pair<iterator,bool> insert(const T& x);`\
// Pre: true\
// Post: if x is in the i.p., the second() of the result is false, the i.p. doesn't change
    and the first() of the result points to the element of value x at p.i;
    otherwise, the second() of the result is true, x is added to the i.p. and the first() of
    result points to the new element of the i.p.

* `iterator insert(const_iterator it, const T& x);`\
// Pre: it references some existing element in the implicit parameter or
    is equal to the end of this\
// Post: if x is there at the i.p., the i.p. does not change and the result points to
    the value element x at p.i ; otherwise, x is added to the i.p. and the
    result points to the new element of the i.p.

* `int erase(const T& x);`\
// Pre: true\
// Post: if x is there at the i.p., the i.p. does not change and the result is 0;
    otherwise, the element with key cl is deleted from the i.p. and the.

* `iterator erase(const_iterator it);`\
// Pre: it references some existing element in the implicit parameter,
   which is not empty\
// Post: The implicit parameter is like the original implicit parameter without
   the element referenced by the original it; the reference result
   the element following the one referred to by it in the i.p. original

### Consultants:
* `bool empty() const;`\
// Pre: true\
// Post: The result indicates whether the implicit parameter has elements or not

* `const int size();`\
// Pre: true\
// Post: The result is the number of elements in the implicit parameter

* `size_type count (const value_type& val) const;`\
// Post: The result is 1 or 0, depending if val exists or not in the set.

* `iterator find(const K& cl); // + the const equivalent`\
// Pre: true\
// Post: if cl is in the i.p., the result points to this element; in case
    otherwise, point to end()

* `iterator lower_bound(const K& cl); // + the const equivalent`\
// Pre: true\
// Post: if cl is in the i.p., the result points to this element; in case
    opposite, points to the first element of the i.p. that would go after cl (if cl
    is greater than all elements of the i.p. would be the end()).


## Map `template \<class K class T> class map`
Dictionary containing <key, value> pairs of type <K, T>; the elements are ordered
by the order defined in K (keys may not be repeated); elements can be consulted
and modified by the ends, where from each element the previous and subsequent
element can be accessed (if the exist), and that supports adding and removing
elements from it.\
The time cost of all operations is constant, except:

* searches, operator [], insert and erase without good position, which are
    logarithmic with respect to the size of the map
* the copier, the destructor and clear, which have a linear cost with 
    respect to the size of the original map (in these, and in insert and
    erase, you must also have en count the cost of copying or deleting each
    involved object of type <K,T>

### Constructors:
* `map();`\
// Pre: true\
// Post: The result is a map without any elements

* `map(const map& original);`\
// Pre: true\
// Post: The result is a map copy of the original

### Destructor:
* `~map();`\
// Automatically clears local objects on exiting one scope of visibility

### Modifiers
* `void clear();`\
// Pre: true\
// Post: The implicit parameter is an empty map

* `pair<iterator,bool> insert(const pair<K,T>& x);`\
// Pre: true\
// Post: if x.first is there in the i.p., the second() of the result is false, 
    the i.p. doesn't change and result first() points to key element x.first in i.p.; 
    otherwise, the second() of the result is true, x is added to the i.p. and the first()
    of the result points to the new element of the i.p.

    We use as: `m.insert(make_pair(x,y));` or `m.insert(pair<K,T>(x,y));`

* `iterator insert(const_iterator it, const pair<K,T>&  x);`\
// Pre: it references some existing element in the implicit parameter or
    is equal to the end of this\
// Post: if x.first is there at the i.p., the i.p. does not change and the result points to
    key element x.first in i.p; otherwise, x is added to the i.p. and the
    result points to the new element of the i.p.

* `size_type erase(const K& cl);`\
// Pre: True\
// Post: if cl is at the i.p., the i.p. doesn't change and the result is 0,
    otherwise, the element with key cl is deleted from the i.p. and the result
    is 1.

* `iterator erase(const_iterator it);`\
// Pre: it references some existing element in the implicit parameter,
   which is not empty\
// Post: The implicit parameter is like the original implicit parameter without
   the element referenced by the original it; the reference result
   the element following the one referred to by it in the i.p. original

* `void erase (iterator first, iterator last);`
// Pre: ¿similar as above?
// Post:  Removes from the map container either a single element or a range of elements ([first,last)).

* `T& operator[] (const K& cl);`\
    If cl is a key of a map m, m[cl] returns the corresponding value
    otherwise, inserts into m the pair <cl, elem. neutral of T>.\
    If we make m[cl]=val, the value of cl becomes val, if cl was there in m;
    otherwise, inserts to m the pair <cl, val>.\
    You can do things like m[cl]++ or m[cl]+=x as in vectors (if cl is not there
    to m, an insertion occurs), but the cost is logarithmic, not constant.\
    There is the alternative operation "at" that does the same if cl is in the map
    and throws an exception if it's not.

### Consultants: 
* `bool empty() const;`\
// Pre: true\
// Post: The result indicates whether the implicit parameter has elements or not

* `const int size();`\
// Pre: true\
// Post: The result is the number of elements in the implicit parameter

* `size_type count(const K& cl);`\
// Pre: true\
// Post: Searches the container for elements with a key equivalent to cl and returns the number of matches.
 
* `iterator find(const K& cl);` // + the const equivalent\
// Pre: true\
// Post: if cl is in the i.p., the result points to this element;
   otherwise, points to end()

* `iterator lower_bound(const K& cl);` // + the const equivalent\
// Pre: true\
// Post: if cl is in the i.p., the result points to this element;
   otherwise, points to the first element of the i.p. that would go after cl (if cl
   is greater than all elements of the i.p. would be the end())

### Passing parameters
An operation which uses the method [...] of a map passed as a parameters needs a
modifiable reference of the map. So, although in any moment we modify the map
in the procedure passing it as `const` will give a *compilation error*.\
This is **not** correct: `void procedure(const map<K, T> &m);`\
This is **correct**: `void procedure(map<K, T> &m);`

### Additional parameters of the class (also works with sets)
We can change the ordering criteria with:\
`map<K, T, greater<K> > m;`, which produces a decreasing ordering\
`map<K, T, less<K> > m;`, which produces an increasing ordering (default)

## Iterators guide
Iterators are defined as a sublcass of the class which contains it.\
See code from class to see implementations with them.\
Constant iterators permit the acces to the elements of the class, but not their
modification.

### Typical iterators:
* `iterator begin();`\
// Pre: True\
// Post: The result is an iterator at the start of the implicit parameter

* `const_iterator begin() const;`\
// Pre: True\
// Post: The result is a const_iterator at the start of the implicit parameter

* `iterator end();`\
// Pre: True\
// Post: The result is an iterator at the fictional element immediately after
    the last element of the implicit paramter

* `const_iterator end() const;`\
// Pre: True\
// Post: The result is a const_iterator at the fictional element immediately after
    the last element of the implicit paramter

**Notes:**

1. If l is empty, l.begin() is the same as l.end().\
2. If l qualifies as a const, l.begin() and l.end() return a const_iterator;
    otherwise, return an iterator.\
3. Elements in a list/set: {1=begin(), 2, 3, ..., k-1, k, end()}. When the 
    iterator points to end(), it is pointing to the k+1 element of the list/set.

### Operations with iterators:
* `++it`: Goes to the next element, not valid at end(). [it's +1 the last element]
* `--it`: Goes to the previous element, not valid at begin();
* `*it`: Designates the element referenced by it; not valid for end() or for
    iterators that reference nothing; if the list of it comes qualified
    as const or if it is a const_iterator then *it is "read-only"
* `it1=it2`: Assign iterator it2 to it1; a const_iterator cannot be assigned to
an iterator
* `it1==it2`: True if iterators it1 and it2 are equal; false if not
* `it1!=it2`: True if iterators it1 and it2 are different; false if not
* `it->first`: ex: if its a map<int, x> returns an int value of .first of the 
current position of the iterator

## Random shuffle
`random_shuffle(v.begin(), v.end())` // function which orders randomly a vector

## Define operations with a certain type T (useful for maps/sets):
**Example 1:** How to define < operator (less than)

```c++
   bool operator < (T t1, T t2)
   {
       if (t1.y != t2.y) return t1.y < t2.y;
       return t1.x < t2.x;
   }
```
**Example 2:** How to define << operator (shift left, or conversion function to a
    string printed to the console in the case of cout)

```c++
    ostream operator << (ostream &os, T t)
    {
        os << "(" << t.x << ", " << p.y << ")";
        return os;
    }
```

## Using pair class
`pair` allows to form pairs of a value of tipe T1 and a value of type T2. Note
that T1 could be equal to T2.\
pair<T1,T2> is equivalent to:\

```c++
struct pair {
    T1 first;
    T2 second;
};
```
To declare a pair: `pair<T1, T2> a(x, y);`\
Or also, to initialize it if its already declared: `a = make_pair(x, y);`
