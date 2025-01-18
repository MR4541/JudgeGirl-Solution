typedef struct locks {
    int n;
    int sensor[100][3];
} Locks;
 
Locks* init(int lockSeq[][3], int n);
 
int numUnlocked(Locks *locks, bool lights[], int m);