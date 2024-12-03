add_executable(utils-tests)
include(Sources.cmake)

include(FetchContent)
FetchContent_Declare(google.test
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(google.test)

target_link_libraries(utils-tests
  PRIVATE
  gtest_main
  utils
)
