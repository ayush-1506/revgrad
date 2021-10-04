# revgrad
Reverse mode AD on DAGs

# Usage

1. bazel build //src:main

# steps:

[] Figure out design of single `Data` type

    struct data{
        value
        grad
        backward function
    }

[] Add suport for basic add, sub, mul, div operators
