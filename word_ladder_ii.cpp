// Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,

// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]

// Return

//   [
//     ["hit","hot","dot","dog","cog"],
//     ["hit","hot","lot","log","cog"]
//   ]
// Note:

// All words have the same length.
// All words contain only lowercase alphabetic characters.

#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ladders;
        int word_len = start.length(), dict_size = dict.size();
        queue<vector<string> > to_transform;
        unordered_set<string> transformed;
        vector<string> current_step_transformed;

        to_transform.push(vector<string> (1, start));
        int current_step_wordcount = 1, next_step_wordcount = 0, step = 0;

        while (!to_transform.empty())
        {
            vector<string> transform = to_transform.front();
            string word = transform.back();
            to_transform.pop();

            for (int i = 0; i < word_len; ++i)
            {
                for (int j = 0; j < 26; ++j)
                {
                    string candidate_word = word;
                    candidate_word[i] = 'a' + j;

                    if (candidate_word == end)
                    {
                        vector<string> ladder(transform);
                        ladder.push_back(end);
                        ladders.push_back(ladder);
                    }

                    if (dict.find(candidate_word) != dict.end() && transformed.find(candidate_word) == transformed.end())
                    {
                        current_step_transformed.push_back(candidate_word);

                        vector<string> appended_transform(transform);
                        appended_transform.push_back(candidate_word);
                        to_transform.push(appended_transform);

                        next_step_wordcount++;
                    }
                }
            }

            if (--current_step_wordcount == 0)
            {
                if (!ladders.empty()) break;

                transformed.insert(current_step_transformed.begin(), current_step_transformed.end());
                current_step_transformed.clear();

                current_step_wordcount = next_step_wordcount;
                next_step_wordcount = 0;
                step++;
            }
        }

        return ladders;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    unordered_set<string> dict0, dict1;
    string dict_strings0[] = {"hot", "dot", "dog", "lot", "log"};
    string dict_strings1[] = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};

    for (int i = 0, len = 5; i < len; ++i) dict0.insert(dict_strings0[i]);
    for (int i = 0, len = 8; i < len; ++i) dict1.insert(dict_strings1[i]);

    vector<vector<string> > ladders0 = solution.findLadders("hit", "cog", dict0);
    vector<vector<string> > ladders1 = solution.findLadders("red", "tax", dict1);
    
    for (int i = 0, p = ladders0.size(); i < p; ++i)
    {
        for (int j = 0, q = ladders0[i].size(); j < q; ++j) cout << ladders0[i][j] <<  " ";
        cout << endl;
    }
    for (int i = 0, p = ladders1.size(); i < p; ++i)
    {
        for (int j = 0, q = ladders1[i].size(); j < q; ++j) cout << ladders1[i][j] <<  " ";
        cout << endl;
    }

    return 0;
}
// compile `g++ -std=c++0x`
