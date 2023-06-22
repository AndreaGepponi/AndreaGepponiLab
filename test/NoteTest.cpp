#include "gtest/gtest.h"

#include "../Note.h"

TEST(Note,NoDate){
    string N="Name",D="Des",P="Low";
    Note Try(N,D,P);
    Try.eraseDate();
    ASSERT_EQ(Try.getDate(), nullptr);
}
