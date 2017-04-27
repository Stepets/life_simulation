cmake_minimum_required (VERSION 2.6)

project (LifeSim)

option(HEADLESS "build project without visualisation" OFF)

add_definitions(-std=gnu++11)
if (NOT HEADLESS)
	add_definitions(-DUSE_OPENCV2)
else()
	add_definitions(-DHEADLESS)
endif()

file (GLOB LIFESIM_CORE ${PROJECT_SOURCE_DIR}/*.cpp)
file (GLOB LIFESIM_WORKERS ${PROJECT_SOURCE_DIR}/Workers/*.cpp)
file (GLOB LIFESIM_FACTORIES ${PROJECT_SOURCE_DIR}/Factories/*.cpp)
file (GLOB LIFESIM_ACTIONS ${PROJECT_SOURCE_DIR}/Actions/*.cpp)
file (GLOB LIFESIM_LOGICS ${PROJECT_SOURCE_DIR}/Logics/*.cpp)
file (GLOB LIFESIM_VISUALIZATION ${PROJECT_SOURCE_DIR}/Visualization/*.cpp)
file (GLOB LIFESIM_GENETICS ${PROJECT_SOURCE_DIR}/Genetics/*.cpp)
file (GLOB LIFESIM_MAP ${PROJECT_SOURCE_DIR}/Map/*.cpp)

if(HEADLESS)
	list(REMOVE_ITEM LIFESIM_WORKERS ${PROJECT_SOURCE_DIR}/Workers/VisualWorker.cpp)
endif()

include_directories(${PROJECT_SOURCE_DIR}
	${PROJECT_SOURCE_DIR}/Workers/
	${PROJECT_SOURCE_DIR}/Factories/
	${PROJECT_SOURCE_DIR}/Actions/
	${PROJECT_SOURCE_DIR}/Logics/
	${PROJECT_SOURCE_DIR}/Genetics/
	${PROJECT_SOURCE_DIR}/Map/
)
if (NOT HEADLESS)
	include_directories(${PROJECT_SOURCE_DIR}/Visualization/)
endif()


set (SOURCE "${LIFESIM_CORE};${LIFESIM_WORKERS};${LIFESIM_FACTORIES};${LIFESIM_ACTIONS};${LIFESIM_LOGICS};${LIFESIM_GENETICS};${LIFESIM_MAP};")
if (NOT HEADLESS)
	set (SOURCE "${SOURCE};${LIFESIM_VISUALIZATION};")
endif()
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g3")
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g3")

set (LIBS boost_program_options)
if (NOT HEADLESS)
	set (LIBS ${LIBS} opencv_core opencv_highgui opencv_video opencv_imgproc)
endif()

add_executable(LifeSim ${SOURCE})
target_link_libraries(LifeSim ${LIBS})

