#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size());
    map<string, int> id;
    
    for (int i = 0; i < id_list.size(); i++)
    {
        id[id_list[i]] = i;        
    }
    
    vector<vector<string>> repo_vec(id_list.size());
    map<string, int> repo_cnt;
    
    for (int i = 0; i < report.size(); i++)
    {
        string repo = report[i];
        string user1 = repo.substr(0, repo.find(" "));
        string user2 = repo.substr(repo.find(" ") + 1);
        
        int user2_id = id[user2];
        if (find(repo_vec[user2_id].begin(), repo_vec[user2_id].end(), user1) != repo_vec[user2_id].end())
            continue;
        
        repo_vec[id[user2]].push_back(user1);
        repo_cnt[user2]++;
    }
        
    for (string user : id_list)
    {
        if (repo_cnt[user] < k)
            continue;
        
        vector<string> repo_list = repo_vec[id[user]];
        for (int i = 0; i < repo_list.size(); i++)
        {
            answer[id[repo_list[i]]]++;
        }
    }
    
    return answer;
}