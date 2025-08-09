class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> sMap, tMap;

        for(char c: t){
            tMap[c]++;
        }
        int count = 0;
        int start = 0;
        int bestStart = 0;
        int len = INT_MAX;
        string ans = "";

        for(int ind = 0; ind < s.size(); ind++){
            // add
            // increment count of sMap
            sMap[s[ind]]++;
            if (tMap.count(s[ind]) && sMap[s[ind]] <= tMap[s[ind]]) count++;

            // remove
            // we need to get minimum substring so we can remove unwanted chars
            while(sMap[s[start]] > tMap[s[start]]){
                sMap[s[start]]--;
                if (sMap[s[start]] == 0) sMap.erase(s[start]);
                start++;
            }
            // did we find a match
            if (count == t.size()){
                if (1+ind-start < len){
                    len = 1+ind-start;
                    bestStart = start;
                }
            }

        }
        return (len == INT_MAX) ? "" : s.substr(bestStart, len);
    }
};
