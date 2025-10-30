#include <iostream>
using namespace std;

void TOH(int d, char src, char destion, char aux)
{
    if(d==1){
        cout << "Disk 1 is move from " << src << "to " << destion << "\n";
        return;
    }
    TOH(d-1,src,aux,destion);
    cout << "Move disk" << d << "from" << src << "to" << destion <<'\n';
    TOH(d-1,aux,destion,src);
}

int main(){
    int disk;
    cout << "The number of disk is: ";
    cin >> disk;

    if(disk<1){
        cout << "There is no disk for shift";
    }
    else{
        cout << "There are " << disk << "diks in tower1\n\n";
        TOH(4,'A','B','C');
    }
}