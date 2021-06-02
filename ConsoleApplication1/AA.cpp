int& GetB();
int InitializeA() { return GetB() + 1; }
extern int g_A = InitializeA();