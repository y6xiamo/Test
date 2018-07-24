#include <iostream>
class A{
public:
    //void testModifyConst(const int x)
    //{
    //    x = _x;
    //}
    void testModifyConst(int x)const
    {
        _x = x;;
        modify_x(x);
    }
    void modify_x(int x)c    {
        x = _x;
    }
private:
    int _x;
};
int main()
{
    return 0;
}
