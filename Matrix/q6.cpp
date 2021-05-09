// O(n^3)
int maxArea(int M[MAX][MAX], int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=1; j<m; j++) {
            if (M[i][j]) {
                M[i][j] = M[i][j-1]+1;
            }
        }
    }
    int rect = 0;
    for (int i=0; i<m; i++) {
        for (int val = 1; val<=i+1; val++) {
            int count = 0, final_count=0; 
            for (int j=0; j<n; j++) {
                if (M[j][i]>=val) {
                    count++;
                    final_count = max (final_count, count);
                } else {
                    final_count = max (final_count, count);
                    count = 0;
                }
            }
            
            rect = max (rect, val*final_count);
        }
    }
    return rect;
}

// O(n^2) : using - largest rectange in a histogram
int maxArea(int M[MAX][MAX], int n, int m) {
    for (int i=0; i<n; i++) {
        for (int j=1; j<m; j++) {
            if (M[i][j]) {
                M[i][j] = M[i][j-1]+1;
            }
        }
    }
    int rect = 0;
    int height, right, left;
    for (int i=0; i<m; i++) {
        stack<int> s;
        for (int j=0; j<n; j++) {
            while (!s.empty() && M[s.top()][i] > M[j][i]) {
                right = j;
                height = M[s.top()][i];
                s.pop();
                left = s.empty() ? -1 : s.top();
                rect = max (rect, height * (right-left-1));
            }
            s.push(j);
        }
        while (!s.empty()) {
            height = M[s.top()][i];
            s.pop();
            right = n;
            left = s.empty() ? -1 : s.top();
            rect = max (rect, height * (right-left-1));
        }
    }
    return rect;
}
