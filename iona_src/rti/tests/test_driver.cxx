#include <testlib/testlib_register.h>

DECLARE( test_word );
DECLARE( test_dictionary );
DECLARE( test_book );
DECLARE( test_examination );
DECLARE( test_assessment );

void
register_tests()
{
  REGISTER( test_word );
  REGISTER( test_dictionary );
  REGISTER( test_book );
  REGISTER( test_examination );
  REGISTER( test_assessment );
}

DEFINE_MAIN;
