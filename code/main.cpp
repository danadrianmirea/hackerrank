#include <bits/stdc++.h>
#include <cctype>

using namespace std;


string decryptPassword(string s) 
{
    string d=s;
    
    bool lastUpper = false;
    
    for(int i=0; i<d.size(); i++)
    {
        if(isupper(d[i]))
        {
            lastUpper = true;
            continue;
        }
     
        if(isdigit(d[i]) && d[i] != '0')
        {
            for(int j=d.size()-1; j>i; j--)
            {
                if(d[j] == '0')
                {
                    swap(d[i], d[j]);
                    break;
                }
            }
        }      
        else if(lastUpper == true && islower(d[i]))
        {
            swap(d[i-1], d[i]);
        }
    }
    
    d.erase(std::remove(d.begin(), d.end(), '0'), d.end());
    d.erase(std::remove(d.begin(), d.end(), '*'), d.end());
  
    return d;
}


int main()
{
    //ofstream fout(getenv("OUTPUT_PATH"));

    string s = "51Pa*0Lp*0e";
   

    string result = decryptPassword(s);

    cout << result << "\n";


    return 0;
}
