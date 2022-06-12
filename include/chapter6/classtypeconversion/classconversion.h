#ifndef __CLASSCONVERSION__H
#define __CLASSCONVERSION__H

namespace chapter6
{
    namespace classconversion
    {
        class CParent
        {
        public:
            int m_Parent;
        };

        class CChild : public CParent
        {
        public:
            int m_Child;
        };
    }
}

#endif