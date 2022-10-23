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

        // std::function의 인터페이스를 구현
        template <typename RT, typename... ATs>
        class CLammbdaInterface // 람다 인터페이스
        {
        public:
            RT Call(ATs... args) { return _Call(args...); }

            virtual RT _Call(ATs... args) = 0;
        };

        // 2) 실제 람다가 저장될 클래스
        template <typename LAMBDA, typename RT, typename... ATs>
        class CLambda : public CLammbdaInterface<RT, ATs...>
        {
        public:
            CLambda(const LAMBDA &lambda) { m_pLambda = new LAMBDA(lambda); }
            // 복사 생성자: 명시적 클래스가 아니므로 기본 생성자가 없고
            // 암시적 복사 생성자는 사용가능
            // stack에 생성되는 임시 객체이니 new를 통한 복사 생성을 통해 힙에 저장하도록 함
            // 이것으로 CFunction에서 람다를 저장할수 있음..
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
            LAMBDA *m_pLambda; // 실제로 저장하는 클래스이니 LAMDA 타입이 꼭 필요
        };

        // 1) 대표 클래스
        template <typename T>
        class CFunction; // CFunction<T> 전방 선언, 아래에서 람다 시그니처가 템플릿 인자로 대입되는 클래스를 정의(CFunction<RT(ATs...)>)하기 위함

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
            CFunction<RT(ATs...)>&operator=(const LAMBDA &lambda)
            {
                if (m_pLambdaInterface)
                {
                    delete m_pLambdaInterface;
                }

                m_pLambdaInterface = new CLambda<LAMBDA, RT, ATs...>(lambda);
                return *this;
            }
            // 복사 생성자나 복사 대입 연산자를 통해 CFunction 객체에 LAMBDA가 대입되는 순간 람다타입 알수있음..

            RT operator()(ATs... args) { return m_pLambdaInterface->Call(args...); }
            // CFunction 클래스는 람다 객체를 내부에 저장하고 있는 함수 객체(functor)인것..

            CLammbdaInterface<RT, ATs...> *m_pLambdaInterface; // CFunction은 CLambdaInterface 포인터를 맴버로
            // 람다를 저장하기 위해.. CLambda*로는 직접 저장할수가 없음..
            // 람다 타입을 알아야하는데ㅔ.. CFunction을 정의하는 시점에 전달할 수 있는 템플릿 인자는..
            // 오직 함수의 시그니처 뿐..
        };

    }
}

#endif