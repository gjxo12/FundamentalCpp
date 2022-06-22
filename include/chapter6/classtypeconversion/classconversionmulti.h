#ifndef __CLASSCONVERSIONMULTI__H
#define __CLASSCONVERSIONMULTI__H

namespace chapter6
{
    namespace classconversionmulti
    {
        class CParentA
        {
            public:
            CParentA()
            {

                m_Val = 1;
            }
            int m_Val;
        };


        class CParentB
        {
            public:
            CParentB()
            {

                m_Val = 2;
            }
            int m_Val;
        };

        class CChild : public CParentA, public CParentB
        {
            public:
            CChild()
            {

                m_Val = 3;
            }
            int m_Val;
        };


    }
}

#endif