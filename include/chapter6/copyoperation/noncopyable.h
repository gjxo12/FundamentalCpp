#ifndef __NONCOPYABLE__H
#define __NONCOPYABLE__H

class noncopyabble
{
    protected:
    noncopyabble() {}
    ~noncopyabble() {}

    private:
    noncopyabble(const noncopyabble& );
    const noncopyabble& operator= (const noncopyabble&);
};

class CTest : public noncopyabble
{
    public:
    int m_val;
};

#endif
