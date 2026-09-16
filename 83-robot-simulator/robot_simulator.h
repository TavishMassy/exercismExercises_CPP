#pragma once
#include <vector>
#include <string>

namespace robot_simulator {

// TODO: add your solution here
enum Bearing {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Robot {
private:
    std::pair<int, int> _position;
    Bearing _bearing;

public:
    Robot(std::pair<int , int> position = {0, 0}, Bearing bearing = Bearing::NORTH) : _position(position), _bearing(bearing) {}

    std::pair<int, int> get_position() const {
        return _position;
    }

    Bearing get_bearing() const {
        return _bearing;
    }

    void turn_right() {
        switch (_bearing)
        {
        case Bearing::NORTH:
            _bearing = Bearing::EAST;
            break;
        
        case Bearing::EAST:
            _bearing = Bearing::SOUTH;
            break;

        case Bearing::SOUTH:
            _bearing = Bearing::WEST;
            break;

        case Bearing::WEST:
            _bearing = Bearing::NORTH;
            break;
        }
    }

    void turn_left() {
        switch (_bearing)
        {
        case Bearing::NORTH:
            _bearing = Bearing::WEST;
            break;
        
        case Bearing::EAST:
            _bearing = Bearing::NORTH;
            break;

        case Bearing::SOUTH:
            _bearing = Bearing::EAST;
            break;

        case Bearing::WEST:
            _bearing = Bearing::SOUTH;
            break;
        }
    }

    void advance() {
        switch (_bearing)
        {
        case Bearing::NORTH:
            ++_position.second;
        break;
        
        case Bearing::EAST:
            ++_position.first;
        break;

        case Bearing::SOUTH:
            --_position.second;
        break;

        case Bearing::WEST:
            --_position.first;
        break;
        }
    }

    void execute_sequence(std::string sequence) {
        for (char c : sequence) {
            switch (c) 
            {
            case 'A':
                this->advance();
                break;
            
            case 'R':
                this->turn_right();
                break;

            case 'L':
                this->turn_left();
                break;
            }
        }
    }
};

}  // namespace robot_simulator
