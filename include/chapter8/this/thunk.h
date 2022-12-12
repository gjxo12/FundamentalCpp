#ifndef __THUNK__
#define __THUNK__

namespace chapter8
{
    namespace Thunk
    {
        class CParent1
        {
        public:
            virtual void VFunc() {}
            virtual void VFunc1() {}
        };
        class CParent2
        {
        public:
            virtual void VFunc() {}
            virtual void VFunc2() {}
        };
        class CChild : public CParent1, public CParent2
        {
        public:
            virtual void VFunc() { void *p = this; }
            virtual void VFunc1() {}
            virtual void VFunc2() {}
        };

    } // namespace thunk
} // namespace chapter8
#endif
