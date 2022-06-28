#ifndef __DYNAMICCAST2__H
#define __DYNAMICCAST2__H

namespace chapter6
{
    namespace dynamiccast2
    {
        class CParentA
        {
        public:
            virtual ~CParentA() {}
        };

        class CParentB
        {
        public:
            virtual ~CParentB() {}
        };

        class CChild : public CParentA, public CParentB
        {
        public:
        };

    }
}

#endif