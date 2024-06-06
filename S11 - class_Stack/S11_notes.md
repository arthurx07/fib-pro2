## Static functions
```c++
static T function();
```
Static functions are those which are declared inside a class but
do not use the implicit parameter. Thus they could be declared outside
but in a manner it makes sense to be declared in the class.
Example: a function which calculates the gcd given two numbers.

## Const functions
```c++
const T function();
```
Is a function which returns a const element which cannot be changed.
If it makes sense or not depends on the context.

## function() const
```c++
T function() const;
```
This is a function which doesn't modify the implicit parameter. It's
a restriction made upon the programmer, to be safer and reduce errors.
They are usually used in consultors.

## friend function()
```c++
friend T function();
```
Some functions can be declared inside a class as friends functions. Though
they do not belong to the class, the class permits this function to access
and modify its private and protected members.

## Operators
If we want to define operators for a certain class those need to be
placed outside of the class and may be made as friends.

```c++
class Test {
private:
    friend bool operator<(const Test &t1, const Test &t2);
    friend istream &operator>>(istream& is, const Test &t);
    friend ostream &operator<<(ostream& os, const Test &t);
};

bool operator<(const Test &t1, const Test &t2)
{
    return t1.example < t2.example;
}

std::istream &operator>>(std::istream& is, const Test &t)
{
    is >> ...
    return is;
}

std::ostream &operator<<(std::ostream& os, const Test &t)
{
    os << ...
    return os;
}
```

## This identifier
If we have two variables with the same name in the function of a
certain class we can use this-> to access the variable of the implicit
parameter. **this** is is a keyword which points to the implicit parameter,
and thus we can also desreference it if we want (***this**).

```c++
Test::Test(int a, int b)
{
    this->a = a;
    this->b = b;
}
```

## Class constructor
We can define the constructor of a class, that is, the default values
of the members of the class when it's initialized.

```c++
Test::Test()
{
    a = 0;
}
```
We can also take arguments from the constructor (look for the previous example).

## Why can templates only be implemented in the header file?
Remember:

1. A template is not a class or a function. A template is a "pattern" that the compiler uses to generate
a family of classes or functions.

2. In order for the compiler to generate the code, it must see both the template definition 
(not just declaration) and the specific types/whatever used to “fill in” the template. For example, 
if you’re trying to use a Foo<int>, the compiler must see both the Foo template and the fact that 
you’re trying to make a specific Foo<int>.

3. Your compiler probably doesn’t remember the details of one .cpp file while it is compiling another .cpp file.
It could, but most do not and if you are reading this FAQ, it almost definitely does not. BTW this is called
the “separate compilation model.”

Then:

When instantiating a template, the compiler creates a new class with the given template argument. For example:

```c++
template<typename T>
struct Foo
{
    T bar;
    void doSomething(T param) {/* do stuff using T */}
};

// somewhere in a .cpp
Foo<int> f; 
```
When reading this line, the compiler will create a new class (let's call it FooInt), which is equivalent to the following:

```c++
struct FooInt
{
    int bar;
    void doSomething(int param) {/* do stuff using int */}
};

```
Consequently, the compiler needs to have access to the implementation of the methods, to instantiate them with
the template argument (in this case int). If these implementations were not in the header, they wouldn't be
accessible, and therefore the compiler wouldn't be able to instantiate the template.

This is to say:

If the define the template separately from the implementation, when the implementation is compiled it won't
know that another file will require an instance of the template, let alone which specific instance would that
be.

For more info see: https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

## Difference between template<typename T> and template<class T>
There is no difference. typename and class are interchangeable in the declaration of a type template parameter.

You do, however, have to use class (and not typename) when declaring a template template parameter:

```c++
template <template <typename> class    T> class C { }; // valid!
template <template <typename> typename T> class C { }; // invalid!  o noez!
```

(note: I think there could be more differences, not sure)

## Prevent to include the same class multiple times
We need to add this lines of code to prevent multiple includes of the same class in certain source code, as
just one would be necessary.

```c++
#ifndef TEST_HH
#define TEST_HH 
class Test() {

};
#endif
```

## Small notes on pointer usage
```c++
int a = 3;
int *pa = &a;
cout << a << ' ' << *pa << endl; // 3 3
*pa = 2; // a = 2

int *pb = new int(); // creates a pointer to a new int element
*pb = 4;
cout << *pb << endl; // 4
delete pb; // frees memory which pb points to

int *pc = pa; // pc = &a
cout << *pc << endl; // 2
```