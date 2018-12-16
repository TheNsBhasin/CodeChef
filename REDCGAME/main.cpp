#include <bits/stdc++.h>
using namespace std;
#define ll long long

main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        ll sum = 0;
        vector<ll> V;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k)
                sum += arr[i];
            else {
                V.push_back(arr[i] - k);
                sum += k;
            }
        }
        if (V.size() == 0) {
            // sum+=arr[n-1];
        } else if (V.size() == 1) {
            sum += V[0];
        } else if (V.size() == 2) {
            sum += V[1] - V[0];
        } else {
            ll temp = 0;
            for (int j = 0; j < V.size() - 2; j++) {
                temp += V[j];
            }
            ll s = V.size();
            if (temp < V[s - 2]) {
                V[s - 2] -= temp;
                sum += V[s - 1] - V[s - 2];
            } else {
                temp += V[s - 2];
                if (temp % 2 == 0) {
                    sum += V[s - 1];
                } else {
                    sum += V[s - 1] - 1;
                }
            }
        }
        cout << sum << "\n";
    }
}