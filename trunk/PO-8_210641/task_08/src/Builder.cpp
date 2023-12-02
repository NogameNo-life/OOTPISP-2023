#include "Builder.h"

ConcreteRobotBuilder::ConcreteRobotBuilder() : robot(new Robot()) {}

void ConcreteRobotBuilder::buildHead() {
    robot->setHead(new Head());
}

void ConcreteRobotBuilder::buildBody() {
    robot->setBody(new Body());
}

void ConcreteRobotBuilder::buildEngine() {
    robot->setEngine(new Engine());
}

Robot* ConcreteRobotBuilder::getRobot() {
    return robot;
}

void Director::buildRobot(RobotBuilder* builder) {
    builder->buildHead();
    builder->buildBody();
    builder->buildEngine();
}