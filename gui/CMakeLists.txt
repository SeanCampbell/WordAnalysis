SET( gui_sources
    bookform.h      bookform.cpp
)

ADD_LIBRARY( gui ${gui_sources} )

target_link_libraries(gui ${Qt5Widgets_LIBRARIES} rti)


IF( BUILD_TESTING )
    add_subdirectory( tests )
ENDIF( BUILD_TESTING )
