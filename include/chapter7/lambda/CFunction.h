#ifndef __CFUNCTION__
#define __CFUNCTION__

namespace chapter7
{
    namespace CFunction
    {
        template <typename TEST> // 타입을 명시적으로 입력
        void Func(TEST arg)
        {
            TEST lambda = arg; // TEST 타입은 구현쪽에서 실제 대입된 타입으로 됨..
            lambda(1);
        }
        
        template <typename RT, typename... ATs>
        class CLammbdaInterface // 람다 인터페이스
        {
        public:
            RT Call(ATs... args) { return _Call(args...); }

            virtual RT _Call(ATs... args) = 0;
        };

        template <typename LAMBDA, typename RT, typename... ATs>
        class CLambda : public CLammbdaInterface<RT, ATs...>
        {
        public:
            CLambda(const LAMBDA &lambda) { m_pLambda = new LAMBDA(lambda); }
            ~CLambda()
            {
                if (m_pLambda)
                {
                    delete m_pLambda;
                }
            }
            virtual RT _Call(ATs... args)
            {
                return (*m_pLambda)(args...);
            }
            LAMBDA *m_pLambda;
        };

        template <typename T>
        class CFunction; // CFunction<T> 전방 선언, 아래에서 람다 시그니처가 템플릿 인자로 대입되는 클래스를 정의하기 위함

        template <typename RT, typename... ATs>
        class CFunction<RT(ATs...)>
        {
        public:
            CFunction() { m_pLambdaInterface = NULL; }

            template <typename LAMBDA>
            CFunction(const LAMBDA &lambda)
            {
                m_pLambdaInterface = new CLambda<LAMBDA, RT, ATs...>(lambda);
            }

            template <typename LAMBDA>
            CFunction<RT(ATs...)> &operator(const LAMBDA &lambda)
            {
                if (m_pLambdaInterface)
                {
                    delete m_pLambdaInterface;
                }

                m_pLambdaInterface = new CLambda<LAMBDA, RT, ATs...>(lambda);
                return *this;
            }

            RT operator()(ATs... args) { return m_pLambdaInterface->Call(args...); }

            CLammbdaInterface<RT, ATs...> *m_pLambdaInterface; // CFunction은 CLambdaInterface 포인터를 맴버로
            // 람다를 저장하기 위해.. CLambda*로는 직접 저장할수가 없음..
            // 람다 타입을 알아야하는데ㅔ.. CFunction을 정의하는 시점에 전달할 수 있는 템플릿 인자는..
            // 오직 함수의 시그니처 뿐..
        }

    }
}

#endif