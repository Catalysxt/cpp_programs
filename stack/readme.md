A **stack** is a simple data structure consisting of a sandwich of values. We interact with the stack by adding and removing values from the top. 

We’ll use a **linked list** to implement the stack. It consists of cells, with each cell pointing to the next one. The final cell points to `nullptr`, signalling the end.

A `stack` will be defined as a collection of `Cell` objects

Future changes
- The program creates a stack of int's. Refactor program to create a stack of any data type
