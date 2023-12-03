#ifndef BUILDER_H
#define BUILDER_H

#include <iostream>
#include <string>

class Head {
public:
    std::string getInfo() const;
};

class Body {
public:
    std::string getInfo() const;
};

class Engine {
public:
    std::string getInfo() const;
};

class Robot {
private:
    Head* head{ nullptr };
    Body* body{ nullptr };
    Engine* engine{ nullptr };

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

    void setHead(Head* newHead);
    void setBody(Body* newBody);
    void setEngine(Engine* newEngine);
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
    ~ConcreteRobotBuilder();

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
