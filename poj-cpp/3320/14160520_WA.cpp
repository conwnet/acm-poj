#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int arr[1100000], N;

int main()
{
        int i, cnt, ans;
        set<int> st;
        map<int, int> mp;

        scanf("%d", &N);
        for(i=0; i<N; i++){
                scanf("%d", &arr[i]);
                st.insert(arr[i]);
        }
        cnt = st.size();
        int sum = 0;
        int s = 0;
        ans = N+1;
        i = s;
        while(1) {
               // int a = mp.size();
                for(; i<N; i++) {
                        mp[arr[i]]++;
                        if(mp.size()>=cnt) break;
                }
                if(mp.size()<cnt) break;
                ans = min(ans, i-s+1);
                mp[arr[s]]--;
                if(mp[arr[s]]==0)
                        mp.erase(arr[s]);
                s++;
                if(s>=N) break;
        }

        printf("%d\n", ans);

        return 0;
}

