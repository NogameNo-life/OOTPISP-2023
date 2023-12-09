#include <QCoreApplication>
#include <iostream>
#include <QString>

class ReportBuilder {
public:
    virtual ~ReportBuilder() = default;
    virtual void buildHeader() = 0;
    virtual void buildBlock() = 0;
    virtual void buildEnding() = 0;
    virtual QString getReport() = 0;
};

class HtmlBuilder : public ReportBuilder {
public:
    void buildHeader() override {
        std::cout << "Create HTML Header" << std::endl;
    }

    void buildBlock() override {
        std::cout << "Create HTML Block" << std::endl;
    }

    void buildEnding() override {
        std::cout << "Create HTML Ending" << std::endl;
    }

    QString getReport() override {
        return "Create HTML report";
    }
};

class TxtBuilder : public ReportBuilder {
public:
    void buildHeader() override {
        std::cout << "Create TXT Header" << std::endl;
    }

    void buildBlock() override {
        std::cout << "Create TXT Block" << std::endl;
    }

    void buildEnding() override {
        std::cout << "Create TXT Ending" << std::endl;
    }

    QString getReport() override {
        return "Create TXT report";
    }
};

class XlsBuilder : public ReportBuilder {
public:
    void buildHeader() override {
        std::cout << "Create XLS Header" << std::endl;
    }

    void buildBlock() override {
        std::cout << "Create XLS Block" << std::endl;
    }

    void buildEnding() override {
        std::cout << "Create XLS Ending" << std::endl;
    }

    QString getReport() override {
        return "Create XLS report";
    }
};

class DocBuilder : public ReportBuilder {
public:
    void buildHeader() override {
        std::cout << "Create DOC Header" << std::endl;
    }

    void buildBlock() override {
        std::cout << "Create DOC Block" << std::endl;
    }

    void buildEnding() override {
        std::cout << "Create DOC Ending" << std::endl;
    }

    QString getReport() override {
        return "Create DOC report";
    }
};

class ReportDirector {
private:
    ReportBuilder *builder;

public:
    explicit ReportDirector(ReportBuilder *b) : builder(b) {}

    void constructReport() {
        builder->buildHeader();
        builder->buildBlock();
        builder->buildEnding();
    }
};

class Robot {
public:
    QString head;
    QString body;
    QString engine;
};

class RobotBuilder {
public:
    virtual ~RobotBuilder() = default;
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;
    virtual Robot getRobot() = 0;
};

class IronRobotBuilder : public RobotBuilder {
private:
    Robot robot;

public:
    void buildHead() override {
        robot.head = "Iron Head";
        std::cout << "Iron Head" << std::endl;
    }

    void buildBody() override {
        robot.body = "Iron Body";
        std::cout << "Iron Body" << std::endl;
    }

    void buildEngine() override {
        robot.engine = "New Engine";
        std::cout << "New Engine" << std::endl;
    }

    Robot getRobot() override {
        return robot;
    }
};

class Face {
public:
    QString eyes;
    QString nose;
    QString mouth;
    QString ears;
    QString hair;
};

class FaceBuilder {
public:
    virtual ~FaceBuilder() = default;
    virtual void buildEyes() = 0;
    virtual void buildNose() = 0;
    virtual void buildMouth() = 0;
    virtual void buildEars() = 0;
    virtual void buildHair() = 0;
    virtual Face getFace() = 0;
};

class PersonFaceBuilder : public FaceBuilder {
private:
    Face face;

public:
    void buildEyes() override {
        face.eyes = "Person's Eyes";
        std::cout << "Person's Eyes" << std::endl;
    }

    void buildNose() override {
        face.nose = "Person's Nose";
        std::cout << "Person's Nose" << std::endl;
    }

    void buildMouth() override {
        face.mouth = "Person's Mouth";
        std::cout << "Person's Mouth" << std::endl;
    }

    void buildEars() override {
        face.ears = "Person's Ears";
        std::cout << "Person's Ears" << std::endl;
    }

    void buildHair() override {
        face.hair = "Person's Hair";
        std::cout << "Person's Hair" << std::endl;
    }

    Face getFace() override {
        return face;
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    HtmlBuilder htmlBuilder;
    ReportDirector htmlDirector(&htmlBuilder);
    htmlDirector.constructReport();
    QString htmlReport = htmlBuilder.getReport();


    TxtBuilder txtBuilder;
    ReportDirector txtDirector(&txtBuilder);
    txtDirector.constructReport();
    QString txtReport = txtBuilder.getReport();

    XlsBuilder xlsBuilder;
    ReportDirector xlsDirector(&xlsBuilder);
    xlsDirector.constructReport();
    QString xlsReport = xlsBuilder.getReport();


    DocBuilder docBuilder;
    ReportDirector docDirector(&docBuilder);
    docDirector.constructReport();
    QString docReport = docBuilder.getReport();


    IronRobotBuilder robotBuilder;
    robotBuilder.buildHead();
    robotBuilder.buildBody();
    robotBuilder.buildEngine();
    Robot IronRobot = robotBuilder.getRobot();


    PersonFaceBuilder PersonFaceBuilder;
    PersonFaceBuilder.buildEyes();
    PersonFaceBuilder.buildNose();
    PersonFaceBuilder.buildMouth();
    PersonFaceBuilder.buildEars();
    PersonFaceBuilder.buildHair();
    Face personFace = PersonFaceBuilder.getFace();


    std::cout << "IronRobot details: " << std::endl;
    std::cout << "Head: " << IronRobot.head.toStdString() << std::endl;
    std::cout << "Body: " << IronRobot.body.toStdString() << std::endl;
    std::cout << "Engine: " << IronRobot.engine.toStdString() << std::endl;

    std::cout << "Person's Face details: " << std::endl;
    std::cout << "Eyes: " << personFace.eyes.toStdString() << std::endl;
    std::cout << "Nose: " << personFace.nose.toStdString() << std::endl;
    std::cout << "Mouth: " << personFace.mouth.toStdString() << std::endl;
    std::cout << "Ears: " << personFace.ears.toStdString() << std::endl;
    std::cout << "Hair: " << personFace.hair.toStdString() << std::endl;

    return a.exec();
}
