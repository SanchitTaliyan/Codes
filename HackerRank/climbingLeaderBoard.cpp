#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int binarySearch (vector<int> s, int target, int &low, int &high) {
    int id;
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if(target == s[mid]) {
            high = mid;
            return mid + 1;
        }else if(target > s[mid] && target < s[mid - 1]) {
            high = mid;
            return mid + 1;
        }else if (target < s[mid] && target >= s[mid + 1]) {
            high = mid + 1;
            return mid + 2;
        }else if(target > s[mid]) {
            high = mid - 1;
            return binarySearch(s, target, low, high);
        }else if(target < s[mid]) {
            id = mid + 1;
            return binarySearch(s, target, id, high);
        }
    }
    return -1;
}

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {

    vector <int> distinct;
    int n, m;
    n = scores.size();
    m = alice.size();

    vector<int> ans;
    int i = 0;

    while(i < n) {
        distinct.push_back(scores[i]);

        while(i < n-1 && scores[i] == scores[i + 1]) {
            i++;
        }
        i++;
    }

    int high = distinct.size() - 1;
    int low = 0;
    for(i = 0; i < m; i++) {
        int alSc = alice[i];
        if(alSc >= distinct[0]) {
            ans.push_back(1);
        }else if(alSc < distinct[high]) {
            ans.push_back(high + 2);
        }else {
            ans.push_back(binarySearch(distinct, alice[i], low, high));

        }
    }

    return ans;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
