int InitializeB() {return 1;}

int& GetB(){
    static int s_B = InitializeB();
    return s_B;
}

//int g_B = InitializeB();