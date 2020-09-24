#include <iostream>
#include <string.h>
using namespace std;


long long S(int n, int k, long long **arr)
{
    if (n == 0) return arr[n][k] = 1;
    else if (k == 0) return arr[n][k] = n;
    else if (arr[n][k] > 0) return arr[n][k];
    else
    {
        arr[n][k] = arr[n][k - 1] * arr[n - 1][k];
        return S(n, k - 1, arr) * S(n - 1, k, arr);
    }

}

int main()
{
    int n, k;
    long long result;
    int cnt = 0;
    cin >> n >> k;
    
    long long ** arr = new long long* [n + 1];

    for (long x = 0; x < n + 1; ++x)
    {
        arr[x] = new long long[k + 1];
        memset(arr[x], 0, sizeof(long long) * (k + 1));
    }
    
    result = S(n, k, arr);

    for (int i = 1; i * i <= result; i++) 
    { 
        if (result % i == 0) 
        { 
            cnt++; 
            if (i * i < result) 
            { 
                cnt++; 
            }
        } 
    }
    
    cout << cnt;

    return 0;
}
