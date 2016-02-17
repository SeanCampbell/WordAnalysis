ADD_EXECUTABLE( rti_test_all
  test_driver.cxx

  test_word.cxx
  test_dictionary.cxx
  test_book.cxx
  test_examination.cxx
  test_assessment.cxx
)
TARGET_LINK_LIBRARIES( rti_test_all rti testlib vnl_algo vnl vil vul )

ADD_TEST( rti_word              ${EXECUTABLE_OUTPUT_PATH}/rti_test_all test_word )
ADD_TEST( rti_dictionary        ${EXECUTABLE_OUTPUT_PATH}/rti_test_all test_dictionary)
ADD_TEST( rti_book				${EXECUTABLE_OUTPUT_PATH}/rti_test_all test_book)
ADD_TEST( rti_examination		${EXECUTABLE_OUTPUT_PATH}/rti_test_all test_examination)
ADD_TEST( rti_assessment		${EXECUTABLE_OUTPUT_PATH}/rti_test_all test_assessment)

#ADD_EXECUTABLE( rgrl_test_include test_include.cxx )
#TARGET_LINK_LIBRARIES( rgrl_test_include rgrl )
#ADD_EXECUTABLE( rgrl_test_template_include test_template_include.cxx )
#TARGET_LINK_LIBRARIES( rgrl_test_template_include rgrl )
