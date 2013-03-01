#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

class SRMRoomAssignmentPhase
{
      public:
      int countCompetitors(vector <int> ratings, int K)
      {
          int cnt = 0;
          for (int i=1; i<ratings.size(); i++)
          if (ratings[i] > ratings[0]) cnt++;
          return cnt / K;          
      }
     
      };
