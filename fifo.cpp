#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{

    int n;
    cout << "PENJADWALAN CPU\n";
    cout << "Masukkan banyak proses: "; cin >> n;
    string name[n + 1], tmpName;
    int avTime[n + 1], brTime[n + 1], tmp, time[100], waitTime[100], turnAround[100];
    int sumWT = 0,sumTA = 0;
    float avWT = 0, avTA = 0;

    for(int i = 0; i < n; i++){
        cout << "Nama Proses: "; cin >> name[i];
        cout << "Arrival Time: "; cin >> avTime[i];
        cout << "Brust Time: "; cin >> brTime[i];
        cout << "\n";
    }

    cout << "Algoritma FIFO\n";

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(avTime[i] > avTime[j]){
                tmpName = name[i];
                name[i] = name[j];
                name[j] = tmpName;

                tmp = avTime[i];
                avTime[i] = avTime[j];
                avTime[j] = tmp;

                tmp = brTime[i];
                brTime[i] = brTime[j];
                brTime[j] = tmp;
            }
        }
    }

    time[0] = avTime[0];

    cout << "<== Tabel Proses ==>\n";
    cout << "==========================================\n";
    cout << "| no | proses\t | time arrival\t | burst |\n";
    cout << "=========================================\n"; 
    for (int i=0; i<n; i++){
        cout << "| " << i + 1 << " | " << name[i] << "\t | \t "<< avTime[i] <<"\t | " << brTime[i] <<"\t |\n";
        time[i+1]=time[i]+brTime[i]; //menghitung time pada ganchart
        waitTime[i]=time[i]-avTime[i];
        turnAround[i]=time[i+1]-avTime[i];
        sumWT+=waitTime[i];
        sumTA+=turnAround[i];
    }

    puts("\n\t.:: Gant-Chart ::.\n");
    for(int i=0; i<n; i++){
        cout << name[i] << "\t";
    }
    cout << endl;
    for(int i=0; i<n; i++){
        printf("|=========");
    }
    printf("|\n");
    for(int i=0; i<=n; i++){
        cout << time[i] << "\t ";
    }

    cout << "\ndiperoleh dari penjumlahan Burst\n";
    avWT=(float)sumWT/n; //average waiting time
    avTA=(float)sumTA/n; //average turn arround time
    cout << "Average Waiting Time :" << avWT << endl;  
    cout << "Average Turn Arround TIme :" << avTA << endl;


    cout << "\n\n====Algoritama SJF====\n";
    int startTime[100], endTime[100],waitTimeSjf[100], sum = 0;
    float avg = 0;
    // sort burst time
    for(int i = 0; i < n; i ++){
        for(int j = i + 1; j < n; j++){
            if(brTime[i] > brTime[j]){
                tmp = brTime[i];
                brTime[i] = brTime[j];
                brTime[j] = tmp;
            }
        }
        if(i == 0){
            startTime[0] = 0;
            endTime[0] = brTime[0];
            waitTimeSjf[0] = 0;
        }else{
            startTime[i] = endTime[i - 1];
            endTime[i] = startTime[i] + brTime[i];
            waitTimeSjf[i] = startTime[i];
        }
    }

    cout << "\n\n BURST TIME \t STARTING TIME \t END TIME \t WAIT TIME\n" << endl;
    cout << "\n ********************************************************\n" << endl;
    for(int i=0;i<n;i++){
        cout << "\t" << brTime[i] << "\t\t" << startTime[i] << "\t\t" << endTime[i] << "\t\t" << waitTimeSjf[i] << endl;
    }
    cout << "\n ********************************************************\n" << endl;
    
    for(int i=0;i<n;i++) sum+=waitTimeSjf[i];
    avg=(float)sum / (float) n;
    sum = 0;
    cout << "\n\n\n AVERAGE WAITING TIME= " << avg << endl;

    for(int i=0;i<n;i++) sum+=endTime[i];
    avg=(float)sum / (float) n;
    sum = 0;
    cout << "\n\n AVERAGE TURNAROUND TIME= " << avg << endl;

    for(int i=0;i<n;i++) sum+=startTime[i];
    avg=(float)sum / (float) n;
    sum  = 0;
    cout << "\n\n AVERAGE RESPONSE TIME= " << avg << endl << endl;

    return 0;
}
