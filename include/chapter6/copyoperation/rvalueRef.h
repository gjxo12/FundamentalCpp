#ifndef __RVALUEREF__H
#define __RVALUEREF__H

#include<string.h>

class CText
{
    public:
    CText(const char* Text){
        m_Len = strlen(Text);
        m_Text = new char[m_Len+1];
        strcpy(m_Text,Text);
    }
    CText(const CText& obj){ // 원본 객체가 소멸되더라도 새로 생성된 객체가 영향 안받게끔 깊은복사
        m_Text = new char[obj.m_Len + 1];
        strcpy(m_Text, obj.m_Text); // 대게의 STL이 이렇게 깊은 복사
        m_Len = obj.m_Len;
    }
    CText(CText&& obj){ //우측 값 참조 복사 생성자: 소멸될 임시 객체가 들어옴!!
        m_Text = obj.m_Text;  // 그냥 포인터 대입으로 얕은 복사
        m_Len = obj.m_Len;
        obj.m_Text = NULL;
        obj.m_Len = 0;
    }
    ~CText(){
        if(m_Text){
            delete [] m_Text;
            m_Len = 0;
        }
    }
    char* m_Text;
    int m_Len = 0;
};

CText GetText();
#endif
