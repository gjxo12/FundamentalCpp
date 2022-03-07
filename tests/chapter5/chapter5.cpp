#include "chapter5.h"
#include "gtest/gtest.h"

namespace chapter5{
    int Func(int arg[]){
        arg[0] = 1;
        arg[1] = 2;
        arg[3] = 3;
        arg[4] = 4;
        return sizeof(arg);
    }
    int Func2(int (&arg)[4]){
        arg[0] = 1;
        arg[1] = 2;
        arg[3] = 3;
        arg[4] = 4;
        return sizeof(arg);
    }
    int CustomRand(int count){
        int arr[count];
        for(int i=0;i<count;i++)
        {
            arr[i] = rand();
        }
        return arr[rand() % count];
    }
}

TEST(chapter5Test, Array1){
    int arr[4] = {0};
    int arr2[10] = {0};
#ifdef ENV64
    ASSERT_EQ(8, chapter5::Func(arr));
    ASSERT_EQ(8, chapter5::Func(arr2));
#endif
#ifdef ENV32
    ASSERT_EQ(4, chapter5::Func(arr));
    ASSERT_EQ(4, chapter5::Func(arr2));
#endif

    ASSERT_EQ(16, chapter5::Func2(arr));
}

TEST(chapter5Test, Rand){
    
}