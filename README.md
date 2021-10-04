## revgrad : Reverse mode AD on DAGs

revgrad provides reverse mode automatic differentiation on directed acyclic graphs. At the heart of it
is a `value` class that stores the `data`, `grad` and backward pass function.

### Usage

1. bazel build //examples:main
2. bazel-bin/examples/main

### To do

1. Add more advanced examples
2. Matrix
3. Higher order differentials
4. Python bindings (maybe)
5. GPU
6. Optimize