#include <iostream>
class A{
public:
    //void testModifyConst(const int x)
    //{
    //    x = _x;
    //}
   // void testModifyConst(int x)const
   // {
   //     _x = x;;
   //     modify_x(x);
   // }
   // void modify_x(int x)c    {
   //     x = _x;
   // }
   
    const int * TestReturn()
    {
        // num = 20;
        int *a = new int();
        return a;
    }
private:
    int _x;
};
int main()
{
    A a1;
   int *p = a1.TestReturn();
   (void)p;
    return 0;
}
