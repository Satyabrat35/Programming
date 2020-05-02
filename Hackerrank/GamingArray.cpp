#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

string gamingArray(vector<int> arr) {
    // write code here
    int x = arr.size();
    int high[x];
    high[0]=arr[0];
    unordered_set<int> ss;
    ss.insert(high[0]);
    for(int i=1;i<x;i++){
        if(arr[i]>high[i-1]){
            high[i]=arr[i];
        } else {
            high[i]=high[i-1];
        }
        ss.insert(high[i]);
    }
    int p = ss.size();
    if(p%2==0){
        return "ANDY";
    } else {
        return "BOB";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string arr_count_temp;
        getline(cin, arr_count_temp);

        int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(arr_count);

        for (int i = 0; i < arr_count; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        string result = gamingArray(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
