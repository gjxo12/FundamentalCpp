#ifndef __MULTIINHERITVIRTUAL__
#define __MULTIINHERITVIRTUAL__

/**
 * 다중 상속에는 vfptr이 여러개 있을수 있다.
 * 항상 main vfptr이 정해지고 이는 클래스 메모리 구조의 시작위치에 놓인다
 */

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

        class CParent1
        {
        public:
            int m_Parent1;
        };
        class CParent2
        {
        public:
            int m_Parent2;
            virtual void VFunc2() = 0;
        };
        class CParent3
        {
        public:
            int m_Parent3;
        };
        class CParent4
        {
        public:
            virtual void VFunc4() = 0;
            int m_Parent4;
        };
        class CChild2 : public CParent1, public CParent2, public CParent3, public CParent4
        {
        public:
            virtual void VFunc2() {}
            virtual void VFunc4() {}
            virtual void VFuncC() {}
            int m_Child;
        };
        // 상속순서와 메모리 위치는 상관관계가 있으나 일치하지는 않는다
        // 생성자의 호출 순서는 1 2 3 4 이지만 메모리 순서는 다를것
    }
}

#endif