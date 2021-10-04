## revgrad : Reverse mode AD on DAGs

revgrad provides reverse mode automatic differentiation on directed acyclic graphs. At the heart of it
is a `value` class that stores the `data`, `grad` and backward pass function.

### Usage

1. bazel build //examples:main
2. bazel-bin/examples/main

### To do

- Tests
- Add more advanced examples
- Matrix
- Higher order differentials
- Python bindings (maybe)
- GPU
- Optimize