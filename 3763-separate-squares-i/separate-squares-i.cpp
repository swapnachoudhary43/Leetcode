class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e9, high = -1e9;

        // Find search range
        for (auto &sq : squares) {
            low = min(low, (double)sq[1]);
            high = max(high, (double)(sq[1] + sq[2]));
        }

        // Binary search
        for (int i = 0; i < 100; i++) { // precision ke liye
            double mid = (low + high) / 2.0;
            double below = 0, above = 0;

            for (auto &sq : squares) {
                double y = sq[1];
                double l = sq[2];
                double top = y + l;

                if (top <= mid) {
                    below += l * l;
                } 
                else if (y >= mid) {
                    above += l * l;
                } 
                else {
                    below += l * (mid - y);
                    above += l * (top - mid);
                }
            }

            if (below >= above)
                high = mid;
            else
                low = mid;
        }

        return high;
    }
};
