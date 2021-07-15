#include <iostream>
#include <time.h>
#include <vector>
#include <windows.h>
#include <fstream>

using namespace std;

typedef struct cand{
    string name;
    string party;
} cd;

void load(int sec){
    int msec;
    msec = 1000 * sec;
    int cur_time = clock();
    while (clock() < cur_time + msec);
}

int main(){
    int numcad, cast, valid = 0, total = 0;
    time_t t;
    FILE *ptr = NULL;
    system("color e");
    time(&t);
    cout << "Welcome!\n";
    cout << "--------\n";
    cout << "Exit code is :- 8003\n\n";
    cout << "Enter number of candidates/parties: ";
    cin >> numcad;
    cd candInfo[numcad];
    vector<int> voteData(numcad, 0);
    cout << "\n";
    getchar();

    for (int i = 0; i < numcad; ++i){
        cout << "Enter name of Candidate " << i+1 << " : "; 
        getline(cin, candInfo[i].name);
        cout << "Enter name of " << candInfo[i].name <<" 's Party (Enter 'I' if Individual Candidate): ";
        getline(cin, candInfo[i].party);
        cout << "\n";
    }

    cout << "Analyzing & Loading Data. Please Wait....";
    load(2);
    while (1)
    {
        system("CLS");
        for (int i = 0; i < numcad; ++i)
            cout << i+1 << ". " << candInfo[i].name << "(" << candInfo[i].party << ")" << "\n\n";
        printf("Input number corresponding to your candidate and press enter: ");
        cin >> cast;
        if (cast == 8003)
            break;
        else if(cast >= 1 and cast <= numcad){
            voteData[cast - 1]++;
            total++;
            Beep(1000, 300);
            cout << "\nYour vote is casted successfully!!\n";
            load(3);
        }
        else{
            cout << "\nYour vote isn't casted. Please Try Again!\n";
            load(3);
        }
    }
    getchar();

    ofstream data;
    data.open("vote_data.txt", ios_base::app);
    data << "\nData of election conducted on " << ctime(&t);
    data << "-------------------------------------------\n";
    for (int i = 0; i < numcad; i++)
        data << i+1 << ". " << candInfo[i].name << "(" << candInfo[i].party << "): " << voteData[i] << " votes\n";        
    data << "Total votes casted - " << total << "\n";
    data.close();

    printf("\nThank You!\n");
    getchar();
    return 0;
}