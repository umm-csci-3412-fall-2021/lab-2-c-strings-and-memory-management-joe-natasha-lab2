#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
char * disemvowel_str = disemvowel((char*) "");
      	ASSERT_STREQ("", disemvowel_str);

  free(disemvowel_str);
}

TEST(Disemvowel, HandleNoVowels) {
char * disemvowel_str = disemvowel((char*) "pqrst");
      	ASSERT_STREQ("pqrst", disemvowel_str);

  free(disemvowel_str);
}

TEST(Disemvowel, HandleOnlyVowels) {
char * disemvowel_str = disemvowel((char*) "aeiouAEIOUAuiea");
  ASSERT_STREQ("", disemvowel_str);
  free(disemvowel_str);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
char * disemvowel_str = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", disemvowel_str);
  free(disemvowel_str);
}

TEST(Disemvowel, HandlePunctuation) {
char * disemvowel_str = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", 
		      disemvowel_str);
  free(disemvowel_str);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';  
char * disemvowel_str = disemvowel(str);
  ASSERT_STREQ("xyz", disemvowel_str);

  free(str);
  free(disemvowel_str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
