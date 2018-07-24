#include <iostream>
class A{
public:
    void testModifyConst(const int x)
    {
        x = _x;
    }
private:
    int _x;
};
int mian()
{
    return 0;
}
