#define NUM 5
bool pthinking[NUM],phungry[NUM],peating[NUM]=false;
int forks[NUM] = -1;
proctype P(int i){
    int right=i; 
    int left=(i+1)%NUM;
    Think:
        atomic{pthinking[i]=true;peating[i]=false;printf("%d is thinking.\n",i);};
    Hungry:
        atomic{phungry[i]=true;pthinking[i]=false;printf("%d is hungry.\n",i);};
        if 
        :: left<right;
            atomic{forks[left] == -1 -> forks[left] = i;printf("%d grabbed left fork.\n",i);};
            atomic{forks[right] == -1 ->forks[right]=i;printf("%d grabbed right fork.\n",i);};
        :: right<left;
            atomic{forks[right]==-1->forks[right]=i;printf("%d grabbed right fork.\n",i);};
            atomic{forks[left] == -1 -> forks[left] = i;printf("%d grabbed left fork.\n",i);};
        fi;
    Eating: 
        atomic{peating[i]=true;phungry[i]=false;printf("%d is eating.\n",i);};
        
    Done: 
        forks[right]=-1;
        forks[left]=-1;
        printf("%d is done eating.\n",i);
        goto Think;
}


init {
    atomic{
        int i = 0;
        do
        :: i < NUM -> run P(i);i++;
        :: else break;
        od;
    }
    
}
/* To verify run:
spin -search -a ./1.pml 
./pan -D > pan.dot
dot -Tps pan.dot -o pan.ps
gs plot.ps
*/