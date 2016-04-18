SET(gui_sources
    comboboxdelegate.h	        comboboxdelegate.cpp
    bookform.h		        bookform.cpp
    libraryform.h	        libraryform.cpp
    librarymodel.h	        librarymodel.cpp
    dictionaryform.h	        dictionaryform.cpp
    dictionarymodel.h	        dictionarymodel.cpp
    wordfrequencyform.h		wordfrequencyform.cpp
    wordfrequencymodel.h	wordfrequencymodel.cpp
    mainwindow.h	        mainwindow.cpp
    wautils.h		        wautils.cpp
)

ADD_LIBRARY( gui ${gui_sources} )

target_link_libraries(gui ${Qt5Widgets_LIBRARIES} rti vul)

IF( BUILD_TESTING )
    add_subdirectory( tests )
ENDIF( BUILD_TESTING )
