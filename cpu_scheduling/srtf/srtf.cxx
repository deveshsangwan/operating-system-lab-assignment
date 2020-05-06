#include<bits/stdc++.h>
using namespace std ;

class Job {
	public:
	int p; //process
	int a; // arrival time
	int b ; //burst time
	int ct ; // completion time
	int com ; //if completed 1 else 0
	int tt; // turnaround time
	int wt ; // waiting time
	int rt ; //remaining time
};

bool compar(Job j1,Job j2){
    return j1.a<j2.a ;
}
bool compare2(Job j1,Job j2){
    return j1.p<j2.p;
}

void Srjf(Job j[] , int n ,int T ){
    int t = 0 , k = -1 ,Min = INT_MAX ;
    while(t<=T){
        for(int i = 0 ; i < n ; i++){
            if(j[i].a<=t&&j[i].com==0&&j[i].rt!=0){
                if(j[i].rt<Min){
                    k = i ;
                    Min = j[i].rt ;
                }
            }
            if(j[i].a>t)
                break ;
        }
        t++;
        if(j[k].com==0&&k!=-1)
           {
                j[k].rt--;
                if(j[k].rt==0){
                    j[k].com=0 ;
                    j[k].ct=t ;
                }
           }
        k = -1 ;
        Min = INT_MAX;
    }
}


int main(){
int n ;
cout<<"Enter no of jobs: ";
cin>>n;
	cout<<"ProcessID\tArrival Time\tBurst Time\n";
	Job j[n] ;
	int totaltime = 0 ;
	for(int i =0 ; i < n ;i++){
		//cout<<i+1<<"";
		cin>>j[i].a>>j[i].b;
		j[i].ct =  0 ;
		j[i].com = 0 ;
		j[i].p = i+1 ;
		j[i].rt = j[i].b ;
		totaltime+=j[i].b ;
	}
    sort(j,j+n,compar) ;

    Srjf(j,n,totaltime) ;
    //cout<<totaltime <<endl;

    int avgtt = 0,avgwt = 0;
   cout<<"Process time arrival time burst time turnaround time waiting time completion time \n";
    for(int i = 0 ;i<n;i++){
            j[i].tt=j[i].ct - j[i].a  ;
            j[i].wt = j[i].tt - j[i].b ;
        avgtt+=j[i].tt;
        avgwt+=j[i].wt ;
       // cout<<j[i].p<<"\t\t"<<j[i].a<<"\t\t"<<j[i].b<<"\t\t"<<j[i].tt<<"\t\t"<<j[i].wt<<"\t\t"<<j[i].ct<<endl;
    }

    sort(j,j+n ,compare2);
    for(int i = 0 ; i < n ;i++){
        cout<<j[i].p<<"\t\t"<<j[i].a<<"\t\t"<<j[i].b<<"\t\t"<<j[i].tt<<"\t\t"<<j[i].wt<<"\t\t"<<j[i].ct<<endl;
    }
cout<<"Avg waiting time "<<avgwt/(float)n<<endl;
cout<<"Avg Turnaround time "<<avgtt/(float)n<<endl;
}
