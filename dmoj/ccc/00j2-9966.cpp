#include <iostream>
#include <algorithm>
bool isFlip(std::string num)
{
    if(num.length()==1 && !(num=="0"||num=="1"||num=="8"))
        return 0;
    std::string flipped="", pali=num;
    std::reverse(pali.begin(),pali.end());
    for(int i = 0; i < num.length(); i++)
    {
        char c = num[i];
        if(c == '6')
            flipped += '9';
        else if(c=='9')
            flipped += '6';
        else if(!(c=='1'||c=='0'||c=='8'))
            return 0;
        else
            flipped+=c;
    }
    return flipped == pali;
}

int main() {
    int a,b,c=0;
    scanf("%d\n%d", &a,&b);
    for(int i = a; i <= b; i++)
    {
        if(isFlip(std::to_string(i)))
        {
            c++;
        }

    }
    printf("%d", c);
    return 0;
}