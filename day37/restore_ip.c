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
        
        restore(s,4,res);
        return res;
    }
        restore(string s,int k,vector<string>& ret){

        }

                
            
    }

};
int main()
{
    return 0;
}
