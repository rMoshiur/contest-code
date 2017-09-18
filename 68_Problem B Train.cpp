#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,sto,cont;
    scanf("%d %d %d\n",&n,&sto,&cont);


    string s;
    char way;
    getline(cin,s);
    if(s=="to head")way='h';
    else way='t';

    cin >> s;
    int i;

    for(i=0;i<s.length();i++)
    {
        if(s[i]=='0')
        {
            if(way=='h')
            {
                if(sto!=1)sto--;
            }
            else
            {
                if(sto!=n)sto++;
            }
                if(way=='h')
                {
                    cont--;
                    if(cont==1)way='l';
                }
                else
                {
                    cont++;
                    if(cont==n)way='h';
                }
        }
        else if(s[i]=='1')
        {
            if(way=='h')
                {
                    cont--;
                    if(cont==1)way='l';
                }
                else
                {
                    cont++;
                    if(cont==n)way='h';
                }


            if(way=='h')
            {
                sto=n;
                if(cont==n)sto=1;
            }
            else
            {
                sto=1;
                if(cont==1)sto=n;
            }
        }


        if(cont==sto)
        {
            printf("Controller %d\n",i+1);
            return 0;
        }
    }
    cout << "Stowaway"<<endl;

    return 0;

}
