#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>
#include <string>

class Head {
public:
    std::string getInfo() const {
        return "Robot Head";
    }
};

class Body {
public:
    std::string getInfo() const {
        return "Robot Body";
    }
};

class Engine {
public:
    std::string getInfo() const {
        return "Robot Engine";
    }
};

class Robot {
private:
    Head* head{nullptr};
    Body* body{nullptr};
    Engine* engine{nullptr};
public:
    Head* getHead() const {
        return head;
    }

    Body* getBody() const {
        return body;
    }

    Engine* getEngine() const {
        return engine;
    }
    void setHead(Head* newHead) {
        head = newHead;
    }

    void setBody(Body* newBody) {
        body = newBody;
    }

    void setEngine(Engine* newEngine) {
        engine = newEngine;
    }
};

class RobotBuilder {
public:
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;
    virtual ~RobotBuilder() {}
};

class ConcreteRobotBuilder : public RobotBuilder {
private:
    Robot* robot;

public:
    ConcreteRobotBuilder() {
        robot = new Robot();
    }

    void buildHead() override {
        robot->setHead(new Head());
    }

    void buildBody() override {
        robot->setBody(new Body());
    }

    void buildEngine() override {
        robot->setEngine(new Engine());
    }

    Robot* getRobot() {
        return robot;
    }

    ~ConcreteRobotBuilder() {
        delete robot;
    }
};

class Director {
public:
    void buildRobot(RobotBuilder* builder) {
        builder->buildHead();
        builder->buildBody();
        builder->buildEngine();
    }
};

#endif // BUILDER_H
