#include <iostream>
using namespace std;
int main()
{
    string input;
    int max = 0;
    string output;
    string tempstr;
    while(cin>>input)
    {
        int i = 0;
        for( ;i < input.size();i++)
        {
            if(input[i] > '0' && input[i] < '9')
            {
                tempstr += input[i];
                while(input[i+1] > '0' && input[i+1] < '9')
                {
                    cout<<i<<endl;
                    tempstr += input[i+1];
                    i++;
                }
                if(tempstr.size() > max)
                {
                    max = tempstr.size();
                    output = tempstr;
                }
                else if(tempstr.size() == max)
                {
                    output += tempstr;
                }
            }
        }
        tempstr.clear();
    }
    cout<<max<<endl;
    int j = 0;
    for( ;j < output.size();j++)
    {
        cout<<output[j]<<endl;
        cout<<j<<endl;
    }

//    cout<<2<<endl;
    return 0;
}

