#include <iostream>
using namespace std;
class Coordinates
{
private:
    int x,y;
public:
    Coordinates(int x,int y)
    {
        this->x = x;
        this->y = y;
    }
    int getXPos()
    {
        return x;
    }
    int getYPos()
    {
        return y;
    }
};
int main()
{
    int t;
    int x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        Coordinates scr(x,y);
        cin>>x>>y;
        Coordinates dest(x,y);
        if(scr.getXPos() == dest.getXPos())
        {
            if(scr.getYPos() < dest.getYPos())
                cout<<"up"<<endl;
            else
                cout<<"down"<<endl;
        }
        else if(scr.getYPos() == dest.getYPos())
        {
            if(scr.getXPos() < dest.getXPos())
                cout<<"right"<<endl;
            else
                cout<<"left"<<endl;
        }
        else
        {
            cout<<"sad"<<endl;
        }
    }
    return 0;
}
