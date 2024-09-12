# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Assignment1\\Assignment1_autogen"
  "Assignment1\\CMakeFiles\\Assignment1_autogen.dir\\AutogenUsed.txt"
  "Assignment1\\CMakeFiles\\Assignment1_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\CS106_library_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CS106_library_autogen.dir\\ParseCache.txt"
  "CS106_library_autogen"
  "SPL-unit-tests\\CMakeFiles\\SPL-unit-tests_autogen.dir\\AutogenUsed.txt"
  "SPL-unit-tests\\CMakeFiles\\SPL-unit-tests_autogen.dir\\ParseCache.txt"
  "SPL-unit-tests\\SPL-unit-tests_autogen"
  "SimpleTestGuide\\CMakeFiles\\SimpleTestGuide_autogen.dir\\AutogenUsed.txt"
  "SimpleTestGuide\\CMakeFiles\\SimpleTestGuide_autogen.dir\\ParseCache.txt"
  "SimpleTestGuide\\SimpleTestGuide_autogen"
  "Welcome\\CMakeFiles\\Welcome_autogen.dir\\AutogenUsed.txt"
  "Welcome\\CMakeFiles\\Welcome_autogen.dir\\ParseCache.txt"
  "Welcome\\Welcome_autogen"
  )
endif()
