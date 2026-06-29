class Solution {
public:
    struct Node {
        Node* links[2];

        Node() {
            links[0] = links[1] = NULL;
        }

        bool containsKey(int bit) {
            return links[bit] != NULL;
        }

        void put(int bit, Node* node) {
            links[bit] = node;
        }

        Node* get(int bit) {
            return links[bit];
        }
    };

    class Trie {
    private:
        Node* root;

    public:
        Trie() {
            root = new Node();
        }

        void insert(int num) {
            Node* node = root;

            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;

                if (!node->containsKey(bit))
                    node->put(bit, new Node());

                node = node->get(bit);
            }
        }

        int getMaxXor(int num) {
            Node* node = root;
            int ans = 0;

            for (int i = 31; i >= 0; i--) {
                int bit = (num >> i) & 1;

                // Prefer opposite bit to maximize XOR
                if (node->containsKey(1 - bit)) {
                    ans |= (1 << i);
                    node = node->get(1 - bit);
                } else {
                    node = node->get(bit);
                }
            }

            return ans;
        }
    };

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        sort(nums.begin(), nums.end());

        // {mi, xi, originalIndex}
        vector<vector<int>> offline;

        for (int i = 0; i < queries.size(); i++) {
            offline.push_back({queries[i][1], queries[i][0], i});
        }

        sort(offline.begin(), offline.end());

        Trie trie;

        vector<int> ans(queries.size());

        int i = 0;

        for (auto &q : offline) {

            int mi = q[0];
            int xi = q[1];
            int idx = q[2];

            // Insert all eligible numbers
            while (i < nums.size() && nums[i] <= mi) {
                trie.insert(nums[i]);
                i++;
            }

            // No valid number exists
            if (i == 0)
                ans[idx] = -1;
            else
                ans[idx] = trie.getMaxXor(xi);
        }

        return ans;
    }
};