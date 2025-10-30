// 3.1 Write a function using refernce variables as arguments to swap the values of a integers.
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Election{
    int sb = 0;
    int count[5] = {0};
public:
    Election(){
        cout << "\t\t\tElection";
        cout << "\nPress 1 to VOTE for Candidate 1";
        cout << "\nPress 2 to VOTE for Candidate 2";
        cout << "\nPress 3 to VOTE for Candidate 3";
        cout << "\nPress 5 to VOTE for Candidate 4\n";
    }
    void castVote(){
        int vote;
        cout << "\nPlease cast your vote: ";
        cin >> vote;
        if(vote>=1 && vote<=5){
            count[vote-1]++;
        }
        else{
            sb++;
        }
    }
    void electionResults(){
        cout << "\n\t\t\tElection Results" << endl;
        for(int i =0; i<5; i++){
            cout << "\nCadidate" << i+1 << "got" << count[i] << "votes.";
        }
        cout<<"\n\nSpoilt Ballots: "<<sb<<"\n";
    }
};

void SwapValues(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
struct Player
{
    string name;
    int runs;
    int innings;
    int notOut;
    double average;
};


int main()
{
    // int x = 10, y = 20;
    // cout <<"X and Y before swaping "<< x << " "<< y<< "\n";
    // SwapValues(x,y);
    // cout << "After swaping...\n";
    // cout << "Value of X is "<< x << " Value of Y is "<< y<<"\n";

    // //3.2 Write a function that creates a vector of user-given size M using new operator.

    // int size;
    // cout << "Enter the size of array==> ";
    // cin >> size;

    // cout << "The size of array is "<< size<<"\n";

    // int *arr = new int[size];
    // for(int i = 0; i < size; i++){
    //     cout << "Enter the data=> ";
    //     cin >> arr[i];
    // }
    // for(int i = 0; i < size; i++){
    //     cout << arr[i]<<"\n";
    // }

    // cout << arr; //This is the address of the array and it is allocated in the heap memory

    // 3.3 Write a program to print the following output using for loops.
    /*
    1
    22
    333
    4444
    55555
    */
    //    int n = 5;

    //     for(int i = 1; i <= n ; i++){
    //         for (int j = 1; j <=i; j++)
    //         {
    //             cout <<i;
    //         }
    //         cout << "\n";

    //     }

    // 3.4 Write a program to evaluate the following investment equation
    /*
    V = P(1 +r)^n
        and print the tables which would give the value of V for various combination of the following values of P,r and n:
        P: 1000,2000,..10,000
        r: 0.10,0.11...0.20
        n: 1,2.............10

    */
    //     // Principal values: 1000 to 10000
    // for (int P = 1000; P <= 10000; P += 1000) {
    //     cout << "\nPrincipal = " << P << endl;

    //     // Print header (years)
    //     cout << "Rate | ";
    //     for (int n = 1; n <= 10; n++) {
    //         cout << setw(10) << n;  // column headers
    //     }

    //     cout << endl;
    //     cout << string(7 + 12 * 10, '-') << endl;

    //     // Interest rate: 0.10 to 0.20
    //     for (double r = 0.10; r <= 0.200001; r += 0.01) {
    //         cout << fixed << setprecision(2);
    //         cout << r << " | ";

    //         // compute value for years n = 1 to 10
    //         for (int n = 1; n <= 10; n++) {
    //             double V = P * pow((1 + r), n);
    //             cout << setw(10) << fixed << setprecision(2) << V;
    //         }
    //         cout << endl;
    //     }
    // }

    // 3.5 An election is contested by five candidates. The candidates are numbered 1 to 5 and the voting is done by marking the candidate number on the ballot paper. Write a program to read the ballots and count the votes cast should be considereed as a spoilt ballot, and the program should also count the number of spoil ballots.
    //  char choice;
    //  Election ele;
    //  do{
    //     ele.castVote();
    //     cout << "Anyone left?(y/n): ";
    //     cin >> choice;
    //  }while (toupper(choice)=='Y');
    //  ele.electionResults();

//3.6 Write a program to read the figures set out in the above from to calculate the batting averages and to print out the complete table including averages.

    const int n = 3;
    Player players[n];

    for(int i = 0; i < n; i++){
        cout << "Enter player's name: ";
        cin >> players[i].name;
        cout << "Runs: ";
        cin >> players[i].runs;
        cout << "Innings: ";
        cin >> players[i].innings;
        cout << "Times not out: ";
        cin >> players[i].notOut;

        players[i].average = (double)players[i].runs/(players[i].innings-players[i].notOut);
    }
    for(int i = 0; i <n; i++){
        cout << players[i].average<<"\n";
    }
     return 0;
}