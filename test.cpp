// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin >> T;
//     while (T--) {
//         int N;
//         cin >> N;
//         int M = N * (N - 1) / 2;
//         vector<int> wt(M);
//         for (int i = 0; i < M; i++) cin >> wt[i];

//         sort(wt.begin(), wt.end()); 

//         long long mmst = 0;
//         for (int i = 0; i < N - 1; i++)
//             mmst += wt[i];

//         cout << mmst << "\n";
//     }

//     return 0;
// }
