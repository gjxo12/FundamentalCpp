#ifndef __MULTIINHERITVIRTUAL__
#define __MULTIINHERITVIRTUAL__

namespace chapter8
{
    namespace multiinheritvirtual
    {
        class CParent
        {
        public:
            int m_Parent;
        };
        class CChild : public CParent
        {
        public:
            virtual void VFunc() {}
            int m_Child;
        };
        // 컴파일러가 메모리 구조를 어떻게 나타낼까..?

    }
}

#endif