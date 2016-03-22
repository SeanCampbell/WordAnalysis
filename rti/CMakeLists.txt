SET( rti_sources
 rti_utils.h						rti_utils.cpp
 rti_word.h 						rti_word.cxx
 rti_word_sptr.h
 rti_dictionary.h 					rti_dictionary.cxx
 rti_dictionary_sptr.h
 rti_book.h 						rti_book.cxx
 rti_book_sptr.h
 rti_literature.h 					rti_literature.cxx
 rti_literature_sptr.h
 rti_question.h 					rti_question.cxx
 rti_question_sptr.h
 rti_question_multiple_choice.h		rti_question_multiple_choice.cxx
 rti_examination.h 					rti_examination.cxx
 rti_examination_sptr.h
 rti_examination_complete.h 		rti_examination_complete.cxx
 rti_assessment.h 					rti_assessment.cxx
 rti_assessment_sptr.h
)

AUX_SOURCE_DIRECTORY( Templates rti_sources )

ADD_LIBRARY( rti ${rti_sources} )

TARGET_LINK_LIBRARIES(rti vbl vcl vnl TinyXML)

IF( BUILD_TESTING )
  add_subdirectory( tests )
ENDIF( BUILD_TESTING )
