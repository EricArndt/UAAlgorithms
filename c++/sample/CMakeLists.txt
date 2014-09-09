# ---------------------------------------------------------------------------- #
# Setup

include_directories(.)

project(sample CXX)

add_library(sample sample.cpp)

add_unit_test(sample increment)

make_manifest(
  sample.cpp
  readme.markdown
)
