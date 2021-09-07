proctype Hello() {
    printf("Hello World!\nPID : %d\n",_pid);
}

init {
    int last_pid;
    printf("Initialisation Process\nPID : %d\n", _pid);
    last_pid = run Hello();
    printf("Last PID : %d\n", last_pid);
}