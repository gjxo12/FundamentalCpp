#ifndef __ANIMAL__
#define __ANIMAL__

namespace chapter8
{
    namespace animal
    {
        class CAnimal
        {
            public:
            virtual void PlaySound() {}
        };
        
        class CDog : public CAnimal
        {
            public:
            virtual void PlaySound() {}

        };

        class CCat : public CAnimal
        {
            public:
            virtual void PlaySound() {}

        };

        class CPig : public CAnimal
        {
            public:
            virtual void PlaySound() {}
        };

        void PlayAnimalSound(CAnimal* pAnimal)
        {
            pAnimal->PlaySound();
        }

    }
}

#endif