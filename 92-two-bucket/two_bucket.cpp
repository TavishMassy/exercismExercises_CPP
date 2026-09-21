#include "two_bucket.h"

namespace two_bucket {

// TODO: add your solution here
measure_result measure(int bucket1_capacity, int bucket2_capacity,
                       int target_volume, bucket_id start_bucket) {
    if (target_volume > std::max(bucket1_capacity, bucket2_capacity)) {
        throw std::invalid_argument("Target volume is too large");
    }
    if (target_volume % std::gcd(bucket1_capacity, bucket2_capacity) != 0) {
        throw std::invalid_argument("Target volume is mathematically impossible");
    }
    size_t num_moves{0};
    std::pair<bucket_capacity, bucket_capacity> buckets = {
        {0, bucket1_capacity}, 
        {0, bucket2_capacity}
    };
    bucket_capacity& start = (start_bucket == bucket_id::one) ? buckets.first : buckets.second;
    bucket_capacity& other = (start_bucket == bucket_id::one) ? buckets.second : buckets.first;
    start._fill();
    ++num_moves;
    if (other.capacity == target_volume) {
        other._fill();
        ++num_moves;
    }
    while (!(start.current_vol == target_volume || other.current_vol == target_volume)) {
        if (other.current_vol == other.capacity) {
            other._empty();
        } else if (start.current_vol == 0) {
            start._fill();
        } else {
            start._transfer_water_to(other);
        }
        ++num_moves;
    }
    measure_result result;
    if (start.current_vol == target_volume) {     
        result.goal_bucket = start_bucket;
        result.num_moves = num_moves;
        result.other_bucket_volume = other.current_vol;
    } else {
        result.goal_bucket = (start_bucket == bucket_id::one) ? bucket_id::two : bucket_id::one;
        result.num_moves = num_moves;
        result.other_bucket_volume = start.current_vol;
    }
    return result;
}

}  // namespace two_bucket