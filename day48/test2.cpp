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
   
    const int * TestReturn(int num)
    {
         num = 20;
        int *a = &num;
        return a;
    }
private:
    int _x;
};
int main()
{
    int *p = TestReturn(10);
    return 0;
}
