// Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

// Only one letter can be changed at a time
// Each intermediate word must exist in the dictionary
// For example,

// Given:
// start = "hit"
// end = "cog"
// dict = ["hot","dot","dog","lot","log"]

// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.

// Note:

// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.

#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
public:
    int ladderLength(string start, string end, unordered_set<string> &dict)
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int word_len = start.length(), dict_size = dict.size();
        queue<string> to_transform;
        unordered_set<string> transformed;

        unordered_set<char> char_set;
        vector<char> chars;
        for (unordered_set<string>::iterator itr = dict.begin(); itr != dict.end(); ++itr)
            for (int i = 0; i < word_len; ++i) char_set.insert((*itr)[i]);
        for (int i = 0; i < word_len; ++i) char_set.insert(end[i]);
        for (unordered_set<char>::iterator itr = char_set.begin(); itr != char_set.end(); ++itr)
            chars.push_back(*itr);

        to_transform.push(start);
        int current_step_wordcount = 1, next_step_wordcount = 0, step = 0;

        while (!to_transform.empty())
        {
            string word = to_transform.front();
            to_transform.pop();

            for (int i = 0; i < word_len; ++i)
            {
                for (int j = 0, len = chars.size(); j < len; ++j)
                {
                    string candidate_word = word;
                    candidate_word[i] = chars[j];

                    if (candidate_word == end) return step + 2;

                    if (dict.find(candidate_word) != dict.end() && transformed.find(candidate_word) == transformed.end())
                    {
                        transformed.insert(candidate_word);
                        to_transform.push(candidate_word);
                        next_step_wordcount++;
                    }
                }
            }

            if (--current_step_wordcount == 0)
            {
                current_step_wordcount = next_step_wordcount;
                next_step_wordcount = 0;
                step++;
            }
        }

        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    unordered_set<string> dict;
    string dict_strings[] = {"hot", "dot", "dog", "lot", "log"};

    for (int i = 0, len = 5; i < len; ++i) dict.insert(dict_strings[i]);
    cout << solution.ladderLength("hit", "cog", dict) << endl;

    return 0;
}
// compile `g++ -std=c++0x`
