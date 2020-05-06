#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>
#include <bits/stdc++.h>

using namespace std;

void handler(int sig);
int main()
{
    cout<<"start\n";
    int p = fork();
    //signal(SIGHUP, sighup);
    if(p == 0){
        signal(2, handler);
        cout<<"Child Process!\n";
        cout<<"Keeping child process to sleep for 2s\n";
        sleep(2);
        // cout<<getsid(getpid())<<" "<<get_current_dir_name()<<endl;
        //exit(2);
    } else{
        int ptr;
        //kill(p, SIGINT);
        int a = wait(&ptr);
        //cout<<kill(p, SIGINT);
        // wait(&ptr);
        cout<<"Parent process ends!\n";
    }
    return 0;
}

void handler(int sig){
    printf("Cild aborted %d\n", sig);
    //fflush(stdout);
}
