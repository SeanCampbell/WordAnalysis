# executables for imaging processing
ADD_EXECUTABLE(generate_simple_mask_images generate_simple_mask_images.cxx)
TARGET_LINK_LIBRARIES(generate_simple_mask_images vul vil vcl)

#executables for Response-to-Intervention project

ADD_EXECUTABLE(expand_literature expand_literature.cxx)
TARGET_LINK_LIBRARIES(expand_literature vul vcl rti TinyXML)

ADD_EXECUTABLE(build_dictionary build_dictionary.cxx)
TARGET_LINK_LIBRARIES(build_dictionary vul vcl rti TinyXML)

ADD_EXECUTABLE(annotate_test annotate_test.cxx)
TARGET_LINK_LIBRARIES(annotate_test vul vcl rti TinyXML)

ADD_EXECUTABLE(class_assessment class_assessment.cxx)
TARGET_LINK_LIBRARIES(class_assessment vul vcl rti TinyXML)

#ADD_EXECUTABLE(update_dictionary update_dictionary.cxx)
#TARGET_LINK_LIBRARIES(update_dictionary vul vcl rti TinyXML)

ADD_EXECUTABLE(generate_test_template generate_test_template.cxx)
TARGET_LINK_LIBRARIES(generate_test_template vul vcl rti TinyXML)

ADD_EXECUTABLE(generate_complete_test_template generate_complete_test_template.cxx)
TARGET_LINK_LIBRARIES(generate_complete_test_template vul vcl rti TinyXML)

ADD_EXECUTABLE(add_test_field add_test_field.cxx)
TARGET_LINK_LIBRARIES(add_test_field vul vcl rti TinyXML)

ADD_EXECUTABLE(class_assessment_template class_assessment_template.cxx)
TARGET_LINK_LIBRARIES(class_assessment_template vul vcl rti TinyXML)

ADD_EXECUTABLE(main_gui gui.cpp)
# The Qt5Widgets_LIBRARIES variable also includes QtGui and QtCore
SET_TARGET_PROPERTIES(main_gui PROPERTIES OUTPUT_NAME "Word Analysis")
TARGET_LINK_LIBRARIES(main_gui gui ${Qt5Widgets_LIBRARIES} rti)
