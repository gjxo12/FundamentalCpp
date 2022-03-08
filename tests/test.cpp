#include "test.h"
#include <gtest/gtest.h>

int TypeOfTryangle(int a,int b,int c)
{
    if(a < 0 || b < 0 || c < 0) return -1;
    if(!(a + b > c && b + c > a && a + c > b)) return 0;
    else if(a == b && b == c) return 1;
    else if(a == b || b == c || c == a) return 1;
    else return 3;
}

TEST(TypeOfTryangle, first){
    EXPECT_EQ(-1, TypeOfTryangle(-10,20,30));
    EXPECT_EQ(-1, TypeOfTryangle(10,-20,30));
    EXPECT_EQ(-1, TypeOfTryangle(3,4,-8));
}
TEST(TypeOfTryangle, second){
    EXPECT_EQ(0, TypeOfTryangle(10,20,30));
    EXPECT_EQ(0, TypeOfTryangle(3,4,8));
}