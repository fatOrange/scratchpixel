load("@rules_cc//cc:defs.bzl", "cc_binary")
load("@rules_cc//cc:defs.bzl", "cc_test")

cc_binary(
    name = "testgeometry",
    srcs = ["testgeometry.cpp","geometry.h"],
    deps = ["@com_github_google_glog//:glog"],
)

cc_test(
  name = "test",
  size = "small",
  srcs = ["test.cpp","vec.h","mat.h"],
  deps = ["@com_google_googletest//:gtest_main"],
)

cc_binary(
    name = "tinyraytracer",
    srcs = ["tinyraytracer.cpp","geometry.h"],
    deps = ["@com_github_google_glog//:glog"],
)

cc_binary(
    name = "sample_distribution",
    srcs = ["sample_distribution.cpp"]
)