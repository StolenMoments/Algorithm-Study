// Greedy, Deque
// 가장 무거운 것과 가장 가벼운 것을 보트에 태우기
// 무게를 초과하면 무거운 것을 보트 하나에 태우기
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
      int ans = 0;
      sort(people.begin(), people.end());
      deque<int> q;
      for (int x : people) q.push_front(x);
      while (!q.empty()) {
        if (limit < q.front() + q.back()) {
          ans++;
          q.pop_front();
        }
        else {
          ans++;
          q.pop_back();
          if (!q.empty()) q.pop_front();
        }
      }
      return ans;

}
