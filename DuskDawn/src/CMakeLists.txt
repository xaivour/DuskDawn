set(DIR ${CMAKE_CURRENT_SOURCE_DIR})

################################################
# Core Sources 
################################################

target_sources(DuskDawn
    PRIVATE
        ${DIR}/Core/Core.h
        ${DIR}/Core/Log.h
		${DIR}/Core/Macros.h
		${DIR}/Core/Log.cpp
)
