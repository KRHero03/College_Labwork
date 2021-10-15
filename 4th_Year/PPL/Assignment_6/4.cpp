#include <bits/stdc++.h>

using namespace std;

class ResourceStatus
{
private:
    vector<vector<int>> statusRef;

public:
    ResourceStatus()
    {
        statusRef = vector<vector<int>>(3, vector<int>(3, 0));
    }
    ResourceStatus(vector<vector<int>> s)
    {
        statusRef = s;
        this->processStatusCount();
    }

    void processStatusCount()
    {
        try
        {
            vector<int> cnt(3, 0);
            for (auto i : statusRef)
                for (auto j : i)
                    cnt[j]++;
            cout << "Process Status Count: " << endl;
            cout << "No. of Free Resources : " << cnt[0] << endl;
            cout << "No. of Occupied Resources : " << cnt[1] << endl;
            cout << "No. of Inaccessible Resources : " << cnt[2] << endl;
            if (cnt[1] > cnt[0])
                throw -1;
        }
        catch (int x)
        {
            if (x == -1)
            {
                cout << "Exception : Occupied Resources exceed available free resources!" << endl;
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        if (this->statusRef[i][j] == 2)
                            this->statusRef[i][j] = 0;
            }
        }
    }
};

int main(int argc, char **argv)
{
    if (argc != 10)
    {
        cout << "Invalid Arguments. 9 arguments are required. Each argument must have value either 0,1,2 based on resource status." << endl;
        return 0;
    }
    vector<vector<int>> status(3, vector<int>(3, 0));
    for (int i = 1; i < 10; i++)
    {
        int row = (i - 1) / 3;
        int col = (i - 1) % 3;
        int val = atoi(argv[i]);
        if(val<0 || val>2){
            cout<<"Invalid Arguments. Each argument must have value either 0,1,2 based on resource status."<<endl;
            return 0;
        }
        status[row][col] = val;
    }
    ResourceStatus *rs = new ResourceStatus(status);
}