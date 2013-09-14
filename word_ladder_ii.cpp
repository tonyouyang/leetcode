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
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void buildLadders(
        const string end,
        unordered_map<string, vector<string> > prev_words,
        vector<string>  &ladder,
        vector<vector<string> > &ladders)
    {
        ladder.push_back(end);
        if (prev_words[end].empty())
        {
            vector<string> l(ladder);
            reverse(l.begin(), l.end());
            ladders.push_back(l);
        }
        else
        {
            for (string prev_word : prev_words[end])
            {
                buildLadders(prev_word, prev_words, ladder, ladders);
            }
        }
        ladder.pop_back();
    }

    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int word_len = start.length();
        int curr = 0, next = 1; // index fo transforming words & to-tranform words
        vector<unordered_set<string> > words(2);
        unordered_map<string, vector<string> > prev_words; // prev words in ladders

        dict.insert(end);
        for (string word : dict) prev_words[word] = vector<string> ();
        words[curr].insert(start);

        for ( ; !words[curr].empty() && words[curr].find(end) == words[curr].end(); curr = !curr, next = !next)
        {
            // cout << "curr = "; for (string word : words[curr]) cout << word << " "; cout << endl;
            for (string word : words[curr]) dict.erase(word);
            // cout << "dict = "; for (string word : dict) cout << word << " "; cout << endl;
            words[next].clear();

            for (string word : words[curr])
            {
                for (int i = 0; i < word_len; ++i)
                {
                    for (int j = 0; j < 26; ++j)
                    {
                        if (word[i] != 'a' + j)
                        {
                            string candidate_word = word;
                            candidate_word[i] = 'a' + j;

                            if (dict.find(candidate_word) != dict.end())
                            {
                                words[next].insert(candidate_word);
                                prev_words[candidate_word].push_back(word);
                            }
                        }
                    }
                }
            }
            // cout << "next = "; for (string word : words[next]) cout << word << " "; cout << endl;
        }

        // for (unordered_map<string, vector<string> >::iterator itr = prev_words.begin(); itr != prev_words.end(); ++itr)
        // {
        //     cout << itr->first << " <-";
        //     for (string word : itr->second) cout << word << " ";
        //     cout << endl;
        // }

        vector<vector<string> > ladders;
        vector<string> ladder;
        if (!prev_words[end].empty()) buildLadders(end, prev_words, ladder, ladders);

        return ladders;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    unordered_set<string> dict0, dict1, dict2;
    string dict_strings0[] = {"hot", "dot", "dog", "lot", "log"};
    string dict_strings1[] = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};

    for (int i = 0, len = 5; i < len; ++i) dict0.insert(dict_strings0[i]);
    for (int i = 0, len = 8; i < len; ++i) dict1.insert(dict_strings1[i]);

    vector<vector<string> > ladders0 = solution.findLadders("hit", "cog", dict0);
    vector<vector<string> > ladders1 = solution.findLadders("red", "tax", dict1);
    vector<vector<string> > ladders2 = solution.findLadders("red", "tax", dict2);

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
    cout << ladders2.size() << endl;

    return 0;
}
// compile `g++ -std=c++0x`
