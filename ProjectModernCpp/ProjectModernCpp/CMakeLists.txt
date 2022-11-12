# CMakeList.txt : CMake project for ProjectModernCpp, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (ProjectModernCpp "ProjectModernCpp.cpp" "ProjectModernCpp.h"  )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ProjectModernCpp PROPERTY CXX_STANDARD 20)
endif()


# find_package(SqliteOrm REQUIRED)

# target_link_libraries(main PRIVATE sqlite_orm::sqlite_orm)

# TODO: Add tests and install targets if needed.

target_link_libraries(ProjectModernCpp PRIVATE sqlite_orm::sqlite_orm)

target_sources(ProjectModernCpp 
    PRIVATE 
        ProjectModernCpp.cpp
)