#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int N;
    int x1,x2,x3;
    int y1,y2,y3;
    int s1,s2,s3;
    int counter=0;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        s1=(int)(pow(y1-y2,2)+pow(x1-x2,2));
        s2=(int)(pow(y1-y3,2)+pow(x1-x3,2));
        s3=(int)(pow(y2-y3,2)+pow(x2-x3,2));
        if(s1 >= s2 && s1 >= s3)
        {
            if(s2 + s3 == s1)
                counter++;
        }
        else if(s2 >= s1 && s2 >= s3)
        {
            if(s1 + s3 == s2)
                counter++;
        }
        else if(s3 >= s1 && s3 >= s2)
        {
            if(s1 + s2 == s3)
                counter++;
        }
    }
    cout<<counter<<endl;
    return 0;
}
