#include "Builder.h"

std::string Head::getInfo() const {
    return "Robot Head";
}

std::string Body::getInfo() const {
    return "Robot Body";
}

std::string Engine::getInfo() const {
    return "Robot Engine";
}

void Robot::setHead(Head* newHead) {
    head = newHead;
}

void Robot::setBody(Body* newBody) {
    body = newBody;
}

void Robot::setEngine(Engine* newEngine) {
    engine = newEngine;
}

ConcreteRobotBuilder::ConcreteRobotBuilder() {
    robot = new Robot();
}

ConcreteRobotBuilder::~ConcreteRobotBuilder() {
    delete robot;
}

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
