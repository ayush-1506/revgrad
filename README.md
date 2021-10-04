![CI Build](https://github.com/ayush-1506/revgrad/actions/workflows/main.yml/badge.svg)

## revgrad : Reverse mode AD on DAGs

revgrad is a minimal C++ library that provides [reverse mode automatic differentiation](https://en.wikipedia.org/wiki/Automatic_differentiation#Reverse_accumulation) on directed acyclic graphs. At the heart of it
is a `value` class that stores the `data`, `grad` and backward pass function.

### Example:

Check out the random _computation graph_ in `examples/function.cpp`. 

1. `bazel build //examples:function`
2. `bazel-bin/examples/function`

Output:

```
current loss 1746.4
current loss 1608.81
current loss 1476.87
current loss 1350.56
current loss 1229.91
current loss 1114.89
current loss 1005.53
current loss 901.804
current loss 803.726
current loss 711.292
current loss 624.504
current loss 543.36
current loss 467.861
```
:100: loss decreases

### To do (in order of priority)

- Add definition for basic layers (relu, leaky-relu etc)
- Tests
- Add more advanced examples
- Matrix
- GPU
- Optimize
- Higher order differentials
- Python bindings (maybe)

### Notes

Writing CPP after a long time, which means there _might_ be places where the code could be optimized or made
better.