#ifndef __INITMEMBER__H
#define __INITMEMBER__H

namespace InitMember
{
    class CParent
    {
        public:
        int m_PValue;
    };
    class CChild : public CParent
    {
        public:
        CChild() : m_PValue(1) // ERROR: 선처리 영역에서 맴버가 클래스 타입일때 해당 클래스의 생성자를 호출한다는데..물려받은게 아닌것!
        {// 초기화 리스트는 생성자의 선처리 영역을 제어하기 위함

        }
    };

} // namespace name

#endif
