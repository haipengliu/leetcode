public class Solution {
    public double findMedianSortedArrays(int A[], int B[]) {
        //2257
        if (A == null || B == null) {
            return 0;
        }
        
        int len = A.length + B.length;
        if (len % 2 == 0) {
            return (double)(dfs(A, B, 0, 0, len / 2) + dfs(A, B, 0, 0, len / 2 + 1)) / 2.0;
        } else {
            return dfs(A, B, 0, 0, len / 2 + 1);
        }
    }
    
    public double dfs(int A[], int B[], int aStart, int bStart, int k) {
        if (aStart >= A.length) {
            return B[bStart + k - 1];
        } else if (bStart >= B.length) {
            return A[aStart + k - 1];
        }
        
        if (k == 1) {
            return Math.min(A[aStart], B[bStart]);
        }
        
        // k = 4;
        // mid = 1;
        int mid = k / 2 - 1;
        
        if (aStart + mid >= A.length) {
            // drop the left side of B.
            return dfs(A, B, aStart, bStart + k / 2, k - k / 2);
        } else if (bStart + mid >= B.length) {
            // drop the left side of A.
            return dfs(A, B, aStart + k / 2, bStart, k - k / 2);
        } else if (A[aStart + mid] > B[bStart + mid]) {
            // drop the left side of B.
            return dfs(A, B, aStart, bStart + k / 2, k - k / 2);
        // 当2者相等，有2种情况：
        // 1. 当k为偶数，则kth存在于任何一个结尾处，其实也是可以丢弃一半的。
        // 2. 当k为奇数，则kth不存在于A,B的left side。也是可以丢弃任意一半。
        //} else if (A[aStart + mid] < B[bStart + mid]) {
        } else {
            return dfs(A, B, aStart + k / 2, bStart, k - k / 2);
        }
        
        //return A[aStart + mid];        
    }
    
    public double dfs(int A[], int B[], int aStart, int bStart, int k) {
        if (aStart >= A.length) {
            return B[bStart + k - 1];
        } else if (bStart >= B.length) {
            return A[aStart + k - 1];
        }
        
        if (k == 1) {
            return Math.min(A[aStart], B[bStart]);
        }
        
        // k = 4;
        // mid = 1;
        int mid = k / 2 - 1;
        
        if (aStart + mid >= A.length) {
            // drop the left side of B.
            return dfs(A, B, aStart, bStart + k / 2, k - k / 2);
        } else if (bStart + mid >= B.length) {
            // drop the left side of A.
            return dfs(A, B, aStart + k / 2, bStart, k - k / 2);
        } else if (A[aStart + mid] > B[bStart + mid]) {
            // drop the left side of B.
            return dfs(A, B, aStart, bStart + k / 2, k - k / 2);
        } else if (A[aStart + mid] < B[bStart + mid]) {
            return dfs(A, B, aStart + k / 2, bStart, k - k / 2);
        } else {
            // drop the left side of A.
            //return dfs(A, B, aStart + k / 2, bStart, k - k / 2);
            if (k % 2 == 0){
                return A[aStart + mid];
            }
            
            // can drop both sides.
            return dfs(A, B, aStart + k / 2, bStart + k / 2, 1);
        }
        
        //return A[aStart + mid];        
    }
}