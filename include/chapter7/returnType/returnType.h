#ifndef __RETURNTYPE__
#define __RETURNTYPE__

namespace chapter7
{
    namespace returnType
    {
        class CTest
        {
            public:
            int m_E;
            int m_V;
        };

        CTest Func();

        __declspec(align(1)) class CTest2{
            public:
            int m_E[8];
            int m_V;
        };
        CTest2 Func2();


    }
}

#endif