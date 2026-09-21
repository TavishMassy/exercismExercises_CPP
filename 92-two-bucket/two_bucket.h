#pragma once
#include <map>
#include <numeric>
#include <stdexcept>

namespace two_bucket {

enum class bucket_id { one, two };
struct bucket_capacity {
    int current_vol;
    int capacity;

    void _transfer_water_to(bucket_capacity& water_to) {
        int space_avalable{water_to.capacity - water_to.current_vol};
        if (this->current_vol >= space_avalable) {
            this->current_vol -= space_avalable;
            water_to._fill();
        } else {
            water_to.current_vol += this->current_vol;
            this->_empty();
        }
    }

    void _empty() {
        this->current_vol = 0;
    }

    void _fill() {
        this->current_vol= this->capacity;
    }
};

struct measure_result {
    int num_moves;
    bucket_id goal_bucket;
    int other_bucket_volume;
};

measure_result measure(int bucket1_capacity, int bucket2_capacity,
                       int target_volume, bucket_id start_bucket);

}  // namespace two_bucket