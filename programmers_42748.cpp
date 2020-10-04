#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (int x = 0; x < commands.size(); x++)
    {
        int temp;
        int bucket[100] = { 0 };
        int start = commands[x][0];
        int end = commands[x][1];
        int target = commands[x][2];

        for (int z = start - 1; z <= end - 1; z++)
        {
            bucket[z - (start - 1)] = array[z];
        }
        
        sort(bucket, bucket + end - start + 1);
        answer.push_back(bucket[target - 1]);

    }
    return answer;
}
