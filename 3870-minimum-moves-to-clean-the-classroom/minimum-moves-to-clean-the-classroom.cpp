#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int maxEnergy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startX = -1, startY = -1;
        vector<pair<int, int>> litters;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litters.push_back({i, j});
                }
            }
        }
        
        int K = litters.size();
        int targetMask = (1 << K) - 1;
        
        // Map litter coordinates to bit index
        auto getLitterIndex = [&](int r, int c) {
            for (int idx = 0; idx < K; ++idx) {
                if (litters[idx].first == r && litters[idx].second == c) {
                    return idx;
                }
            }
            return -1;
        };
        
        // bestEnergy[x][y][mask] stores max remaining energy seen for state (x, y, mask)
        vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << K, -1)));
        
        // Queue elements: {x, y, mask, remaining_energy, moves}
        queue<tuple<int, int, int, int, int>> q;
        
        // Initial state
        int initialMask = 0;
        if (classroom[startX][startY] == 'L') {
            int idx = getLitterIndex(startX, startY);
            if (idx != -1) initialMask |= (1 << idx);
        }
        
        q.push({startX, startY, initialMask, maxEnergy, 0});
        bestEnergy[startX][startY][initialMask] = maxEnergy;
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [x, y, mask, e, moves] = q.front();
            q.pop();
            
            if (mask == targetMask) {
                return moves;
            }
            
            for (auto& d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && classroom[nx][ny] != 'X') {
                    int ne = e - 1;
                    if (ne < 0) continue; // Out of energy
                    
                    int nmask = mask;
                    char cell = classroom[nx][ny];
                    
                    if (cell == 'L') {
                        int idx = getLitterIndex(nx, ny);
                        if (idx != -1) nmask |= (1 << idx);
                    } else if (cell == 'R') {
                        ne = maxEnergy; // Reset energy to max
                    }
                    
                    if (ne > bestEnergy[nx][ny][nmask]) {
                        bestEnergy[nx][ny][nmask] = ne;
                        q.push({nx, ny, nmask, ne, moves + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};