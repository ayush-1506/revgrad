## revgrad : Reverse mode AD on DAGs

revgrad provides reverse mode automatic differentiation on directed acyclic graphs. At the heart of it
is a `value` class that stores the `data`, `grad` and backward pass function.

### Usage

1. bazel build //examples:main
2. bazel-bin/examples/main

### To do

1. Add more advanced examples
2. Higher order differentials
3. Python bindings (maybe)
4. GPU
5. Optimize