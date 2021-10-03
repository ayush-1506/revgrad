load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "sort",
    srcs = ["sort.cpp"],
    hdrs = ["sort.hpp"],
    visibility = ["//test:__pkg__"]
)

cc_library(
    name = "data",
    srcs = ["data.cpp"],
    hdrs = ["data.hpp", "sort.hpp"],
    visibility = ["//test:__pkg__"]
)

cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [
        ":data",
        ":sort",
    ],
)
