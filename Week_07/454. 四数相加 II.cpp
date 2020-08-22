class Solution {
public:
    int fourSumCount2(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if (A.empty() || B.empty() || C.empty() || D.empty())
            return 0;
        
        unordered_multiset<int> DSet(D.begin(), D.end());
        int N = A.size();
        int result = 0;
        int sameCount = 0;
        for (int ia = 0; ia < N; ++ia) {
            for (int ib = 0; ib < N; ++ib) {
                for (int ic = 0; ic < N; ++ic) {
                    // for (int id = 0; id < N; ++id) {
                    //     if (A[ia] + B[ib] + C[ic] + D[id] == 0) {
                    //         cout << ia << " " << ib << " " << ic << " " << id << endl;
                    //         result += 1;
                    //     }
                    // }
                  
                    if (DSet.find(n) != DSet.end()) {
                        cout << ia << " " << ib << " " << ic << " " << n << endl;
                        result += DSet.count(n);
                    }
                }
            }
        }
        return result;
    }

    // 已通过
    int fourSumCount4map (vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if (A.empty() || B.empty() || C.empty() || D.empty())
            return 0;

        int N = A.size();
        int result = 0;
        unordered_map<int, int> sumAB;
        
        for (int ia = 0; ia < N; ++ia) {
            for (int ib = 0; ib < N; ++ib) {
                sumAB[A[ia] + B[ib]] += 1;
            }
        }

        for (int ic = 0; ic < N; ++ic) {
            for (int id = 0; id < N; ++id) {
                int n = -(C[ic] + D[id]);
                result += sumAB[n];
            }
        }
        return result;
    }

    // multiset中使用桶做存储(实质是个链表)，
    // sumABSet桶中n^2个元素，而使用map，只有在极端情况下有n^2个元素
    // 
    int fourSumCount (vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if (A.empty() || B.empty() || C.empty() || D.empty())
            return 0;

        int N = A.size();
        int result = 0;
        unordered_multiset<int> sumABCount;

        for (int ia = 0; ia < N; ++ia) {
            for (int ib = 0; ib < N; ++ib) {
                sumABCount.insert(A[ia] + B[ib]);
            }
        }
        cout << "N: " << N << " ------------" << endl;
        cout << "bucket id: " << sumABCount.bucket(0) << " bucket size: " << sumABCount.bucket_size(sumABCount.bucket(0)) << endl;
        for (int ic = 0; ic < N; ++ic) {
            for (int id = 0; id < N; ++id) {
                int n = -(C[ic] + D[id]);
                result += sumABCount.count(n);
            }
        }
        return result;
    }
};

