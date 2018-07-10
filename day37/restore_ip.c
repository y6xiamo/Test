#include <iostream>
//给一串数字，返回这些数字组成的所有有效的ip地址
//例如：给25525511135 返回{"255.255.11.135", "255.255.111.35"}
//ip地址是四段，
//1.先把字符串分成四段，用三个点.
//2.然后判断每一段的合法性，每一段范围<=255,可能有一位、两位和三位
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;//保存还原的ip地址
        
        restore(s,4,"",res);
        return res;
    }
    //k表示要分割的段数，如果k==0,表示分割完成
    //借助递归，k!=0,继续分割
    void restore(string s,int k,string out,vector<string>& res){
        if (k == 0)
        {
           if (s.empty())
           {
               res.push_back(out);
           }
        }
        else
        {
            //每一段有三位数字
            for (int i = 1; i <= 3; ++i)
            {
                //调用substr函数在原串中取出指定长度的子串
                //调用isValid()然后判断该字串是否合法
                if (s.size() >= i && isValid(s.substr(0, i)))
                {
                     if (k == 1) 
                     {
                         //
                          restore(s.substr(i), k - 1, out + s.substr(0, i), res);
                      }
                     else
                     {
                         //剩下不只一段需要分割，用.隔开
                         restore(s.substr(i), k - 1, out + s.substr(0, i) + ".", res);
                     }
                }
            }
        }
 }

    //对每一段进行合法性检验
    bool isValid(string s){
        if(s.empty()||s.size()>3||(s.size()>1 && s[0] == 0))
        {
            //1.输入字符串不能为空
            //2.每一段至少有一位，总长至少大于3
            //3.第一位不能为0
            //如果上面有一条不满足，则不合法
            return false;
        }
        //将字符串转换成整数，看其是否满足>=0并且<=255
        int res = atoi(s.c_str());
        if(res > 255 || res < 0)
        {
            return false;
        }
        return true;
    }
            
};
int main()
{
    return 0;
}
