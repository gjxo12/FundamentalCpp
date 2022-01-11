//extern int g_B;
int& GetB();
//int InitializeA(){return g_B +1;}

int InitializeA(){return GetB() + 1;}

int g_A = InitializeA();