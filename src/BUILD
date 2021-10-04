load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "sort",
    srcs = ["sort.cpp"],
    hdrs = ["sort.hpp", "data.hpp"],
    visibility = ["//test:__pkg__", "//examples:__pkg__"]
)

cc_library(
    name = "data",
    srcs = ["data.cpp"],
    hdrs = ["data.hpp"],
    deps = [":sort"],
    visibility = ["//test:__pkg__", "//examples:__pkg__"]
)
