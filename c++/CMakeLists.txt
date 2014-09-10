# Shamlessly stolen and modified from Dr. Sutton

# ---------------------------------------------------------------------------- #
# CMake configuration

cmake_minimum_required(VERSION 2.8)

# ---------------------------------------------------------------------------- #
# Project configuration

# Define the top-level project
project(UAAlgorithms CXX)
enable_testing()

# Compiler config
set(CMAKE_CXX_FLAGS "-Wall")

# ---------------------------------------------------------------------------- #
# Testing

# This needs work, link against arbitrary libraries and number of libraries,
# not complicated, just lazy.

# This macro will create unit tests for a module.
macro(add_unit_test mod file)
  file(COPY ${mod}.test/
        DESTINATION ${CMAKE_BINARY_DIR}/${mod} FILES_MATCHING REGEX .*in)
  file(COPY ${mod}.test/
        DESTINATION ${CMAKE_BINARY_DIR}/${mod} FILES_MATCHING REGEX .*out)
  set(tgt ${mod}.${file})
  add_executable(${tgt} ${mod}.test/${file}.cpp)
  target_link_libraries(${tgt} ${mod})
  add_test(test.${tgt} ${tgt})
endmacro()

# ---------------------------------------------------------------------------- #
# Manifest

# The make_manifest macro creates targets that generate a PDF of your code.
macro(make_manifest)
  # Complete the paths to all files
  set(src "")
  set(doc "")
  foreach(i ${ARGV})
    # Make sure the file has its absolute path.
    set(f ${CMAKE_CURRENT_SOURCE_DIR}/${i})

    # What kind of file are we talking about?
    # We're going to process them a little differently.
    get_filename_component(ext ${i} EXT)
    if (${ext} STREQUAL ".md")
      list(APPEND doc ${f})
    else()
      list(APPEND src ${f})
    endif()
  endforeach()

  # Generate the manifest target
  set(outdoc "${CMAKE_CURRENT_BINARY_DIR}/doc.html")
  add_custom_target(manifest
    COMMAND pandoc ${doc} -o ${outdoc}
    COMMAND a2ps -Afill -o manifest.ps ${outdoc} ${src}
    COMMAND ps2pdf manifest.ps)
endmacro()

# ---------------------------------------------------------------------------- #
# Setup directory

include_directories(.)
add_subdirectory(sample)
