
set(RUST_TARGET_DIR ${CMAKE_CURRENT_BINARY_DIR}/target)

# default to Release build
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(RUST_OUT_DIR ${RUST_TARGET_DIR}/thumbv7em-none-eabihf/debug)
else()
  set(RUST_RELEASE_FLAG "--release")
  set(RUST_OUT_DIR ${RUST_TARGET_DIR}/thumbv7em-none-eabihf/release)
endif()

add_custom_command(
  OUTPUT
  ${RUST_OUT_DIR}/liboxidation.a
  COMMAND
  CARGO_TARGET_DIR=${RUST_TARGET_DIR} cargo build ${RUST_RELEASE_FLAG} -Z build-std=core --target thumbv7em-none-eabihf.json
  WORKING_DIRECTORY
  ${CMAKE_CURRENT_SOURCE_DIR}
  VERBATIM
)

add_custom_target(rust_target DEPENDS ${RUST_OUT_DIR}/liboxidation.a)

add_library(oxidation STATIC IMPORTED GLOBAL)
add_dependencies(oxidation rust_target)

set_target_properties(oxidation
        PROPERTIES
        IMPORTED_LOCATION ${RUST_OUT_DIR}/liboxidation.a)