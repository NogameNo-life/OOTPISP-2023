#include <QCoreApplication>
#include <iostream>
#include <QString>

// Интерфейс Строителя для отчета
class ReportBuilder {
public:
    virtual void buildHeader() = 0;
    virtual void buildBlock() = 0;
    virtual void buildEnding() = 0;
    virtual QString getReport() = 0;
};

// Конкретные строители отчета
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

// Интерфейс Директора
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

// Представление робота с частями: Head, Body, Engine
class Robot {
public:
    QString head;
    QString body;
    QString engine;
};

// Конкретные строители робота
class RobotBuilder {
public:
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

    // Создание отчета в формате HTML
    HtmlBuilder htmlBuilder;
    ReportDirector htmlDirector(&htmlBuilder);
    htmlDirector.constructReport();
    QString htmlReport = htmlBuilder.getReport();

    // Создание отчета в формате TXT
    TxtBuilder txtBuilder;
    ReportDirector txtDirector(&txtBuilder);
    txtDirector.constructReport();
    QString txtReport = txtBuilder.getReport();

    // Создание отчета в формате XLS
    XlsBuilder xlsBuilder;
    ReportDirector xlsDirector(&xlsBuilder);
    xlsDirector.constructReport();
    QString xlsReport = xlsBuilder.getReport();

    // Создание отчета в формате DOC
    DocBuilder docBuilder;
    ReportDirector docDirector(&docBuilder);
    docDirector.constructReport();
    QString docReport = docBuilder.getReport();

    // Создание робота
    IronRobotBuilder robotBuilder;
    robotBuilder.buildHead();
    robotBuilder.buildBody();
    robotBuilder.buildEngine();

    // Создание лица героя
    PersonFaceBuilder personFaceBuilder;
    personFaceBuilder.buildEyes();
    personFaceBuilder.buildNose();
    personFaceBuilder.buildMouth();
    personFaceBuilder.buildEars();
    personFaceBuilder.buildHair();

    return a.exec();
}
