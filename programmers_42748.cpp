#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    vector<int> temp;

    for (int x = 0; x < commands.size(); x++)
    {
        int start = commands[x][0];
        int end = commands[x][1];
        int target = commands[x][2] - 1;

        for (int y = start - 1; y < end; y++)
        {
            temp.push_back(array[y]);
        }
        
        sort(temp.begin(), temp.end(), less<int>());
        answer.push_back(temp[target]);
        temp.clear();
    }
    return answer;
}
