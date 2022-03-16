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

