SET(gui_sources
    comboboxdelegate.h	comboboxdelegate.cpp
    bookform.h		bookform.cpp
    dictionaryform.h	dictionaryform.cpp
    dictionarymodel.h	dictionarymodel.cpp
    libraryform.h	libraryform.cpp
    librarymodel.h	librarymodel.cpp
    mainwindow.h	mainwindow.cpp
)

ADD_LIBRARY( gui ${gui_sources} )

target_link_libraries(gui ${Qt5Widgets_LIBRARIES} rti vul)

IF( BUILD_TESTING )
    add_subdirectory( tests )
ENDIF( BUILD_TESTING )
