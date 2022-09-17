
#ifndef LAB2_1_1_ROBOT_H
#define LAB2_1_1_ROBOT_H


class Robot {
public:

    int amountOfArms;
    bool abilityToSpeak;
    char gender;

public:

    Robot(int amountOfArms = 0, bool abilityToSpeak = false, char gender = 'N') {

        this->amountOfArms = amountOfArms;
        this->abilityToSpeak = abilityToSpeak;
        this->gender = gender;
    }

    friend std::ostream& operator<<(std::ostream& out, const Robot& robot) {

        out << "Robot: " << robot.amountOfArms << " " << robot.abilityToSpeak << " " << robot.gender;

        return out;
    }
};


#endif
