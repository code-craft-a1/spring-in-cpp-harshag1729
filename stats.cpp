#include "stats.h"
#include <limits>
#include <algorithm>

Statistics::Stats Statistics::ComputeStatistics(const std::vector<double>& params) {
    if (params.empty()) {
        double nan = std::numeric_limits<double>::quiet_NaN();
        return Statistics::Stats(nan, nan, nan);
    }
    
    double sum = 0.0;
    double minVal = params[0];
    double maxVal = params[0];
    
    for (auto val : params) {
        sum += val;
        minVal = std::min(minVal, val);
        maxVal = std::max(maxVal, val);
    }
    
    double avg = sum / params.size();
    return Statistics::Stats(avg, minVal, maxVal);
}
