## Recursivity
A subprogram is recursive when it contains a call to itself. Recursion can substitute
iteration in program design. Generally recursive solutions are simpler than (or as
simple as) iterative ones, but are usually slightly less efficient if the compiler
does not try to optimize the recursive calls. Also, there are natural recursive
solutions which can be extremely inefficient.

Steps to recursive design:
1. Search for the simplest possible input (base case). It's always an explicit answer.
2. Play around and visualize the given examples (find patterns).
3. Relate hard cases to simple cases.
4. Generalize the pattern, make sure the parameters of the call move closer to the
basic cases at each recursive call.
5. Write code by combining recursion + base case.

**Recursive leap of faith**: Assume simpler cases work out.
