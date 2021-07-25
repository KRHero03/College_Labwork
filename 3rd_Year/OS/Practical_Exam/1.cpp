#include <bits/stdc++.h>
#define ll long long int
#define MAX_SIZE 100
using namespace std;

int main()
{
    cout << "Operating System Practical Exam" << endl;
    cout << "Sequential Memory Allocation" << endl;
    unordered_map<ll, ll> memory;

    ll moreFiles = 1;
    ll allocatedMemory = 0;
    ll fileIdx = 0;
    while (moreFiles)
    {
        cout << "Do you want to Allocate Memory for Files? (Y-1, N-0): ";
        cin >> moreFiles;
        if (!moreFiles)
            break;
        if (moreFiles != 1)
        {
            cout << "Invalid Option" << endl;
            continue;
        }
        ll startingBlock, fileSize;
        cout << "Please enter File starting Block(in Units): ";
        cin >> startingBlock;
        cout << "Please ener File Size(in Units): ";
        cin >> fileSize;
        ll pass = 0;
        for (int i = startingBlock; i < startingBlock + fileSize; i++)
        {
            if (memory.find(i) != memory.end() || i < 0 || i >= MAX_SIZE)
            {
                cout << "Unable to occupy Memory! Either Memory is occupied or exceeds Main Memory Size!" << endl;
                pass = 1;
                break;
            }
        }
        if (!pass)
        {
            for (int i = startingBlock; i < startingBlock + fileSize; i++)
            {
                memory[i] = fileIdx;
            }
            fileIdx++;
        }
    }
    srand(time(NULL));
    ll randomLocation = rand() % MAX_SIZE;
    string ans = memory.find(randomLocation)==memory.end()?"No File Occupies this Unit":to_string(memory[randomLocation]) ;
    cout << "Chosen Random Unit: " << randomLocation << endl;
    cout << "File Index that occupies Unit: " << ans << endl;
}