#ifndef __CLASSCONVERSIONVIRTUAL__H
#define __CLASSCONVERSIONVIRTUAL__H

namespace chapter6
{
    namespace classconversionvirtual
    {
        class CParent
        {
            public:
            int m_Parent;
        };


        class CChild : virtual public CParent
        {
            public:
            int m_Child;
        };

        void classconversionvirtual();

    }
}

#endif