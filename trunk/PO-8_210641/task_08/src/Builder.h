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
    Head* head{ nullptr };
    Body* body{ nullptr };
    Engine* engine{ nullptr };

public:
    void setHead(Head* newHead) {
        head = newHead;
    }

    void setBody(Body* newBody) {
        body = newBody;
    }

    void setEngine(Engine* newEngine) {
        engine = newEngine;
    }

    Head* getHead() const {
        return head;
    }

    Body* getBody() const {
        return body;
    }

    Engine* getEngine() const {
        return engine;
    }
};

class RobotBuilder {
public:
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;
    virtual ~RobotBuilder() {}
    virtual Robot* getRobot() = 0;
};

class ConcreteRobotBuilder : public RobotBuilder {
private:
    Robot* robot;

public:
    ConcreteRobotBuilder();
    void buildHead() override;
    void buildBody() override;
    void buildEngine() override;
    Robot* getRobot() override;
};

class Director {
public:
    void buildRobot(RobotBuilder* builder);
};

#endif // BUILDER_H
