#include <iostream>

using namespace std;

int w,h,t;
int p,q;

void solve(int dir){
    int dist;
    if(dir==0){
        if(w-p>h-q){
            dist=h-q;
            if(t<=dist){
                p+=t;
                q+=t;
                return;
            }
            t-=dist;
            p=p+dist;
            q=q+dist;
            solve(1);
        }
        else if(w-p<h-q){
            dist=w-p;
            if(t<=dist){
                p+=t;
                q+=t;
                return;
            }
            t-=dist;
            p=p+dist;
            q=q+dist;
            solve(1);
        }
    }
}
int main(){
    cin>>w>>h;
    cin>>p>>q;
    cin>>t;

}