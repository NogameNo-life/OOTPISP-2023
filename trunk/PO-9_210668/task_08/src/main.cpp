#include <QCoreApplication>
#include <iostream>
#include <QString>

// Интерфейс Строителя для отчета
class ReportBuilder {
public:
    virtual ~ReportBuilder() = default;
    virtual void buildHeader() = 0;
    virtual void buildBlock() = 0;
    virtual void buildEnding() = 0;
    virtual QString getReport() = 0;
};

// Конкретные строители отчета
class HtmlBuilder : public ReportBuilder {
public:
    void buildHeader() override {
        std::cout << "Building HTML Header" << std::endl;
    }

    void buildBlock() override {
        std::cout << "Building HTML Block" << std::endl;
    }

    void buildEnding() override {
        std::cout << "Building HTML Ending" << std::endl;
    }

    QString getReport() override {
        return "Generated HTML report";
    }
};

class TxtBuilder : public ReportBuilder {
public:
    void buildHeader() override {
        std::cout << "Building TXT Header" << std::endl;
    }

    void buildBlock() override {
        std::cout << "Building TXT Block" << std::endl;
    }

    void buildEnding() override {
        std::cout << "Building TXT Ending" << std::endl;
    }

    QString getReport() override {
        return "Generated TXT report";
    }
};

class XlsBuilder : public ReportBuilder {
public:
    void buildHeader() override {
        std::cout << "Building XLS Header" << std::endl;
    }

    void buildBlock() override {
        std::cout << "Building XLS Block" << std::endl;
    }

    void buildEnding() override {
        std::cout << "Building XLS Ending" << std::endl;
    }

    QString getReport() override {
        return "Generated XLS report";
    }
};

class DocBuilder : public ReportBuilder {
public:
    void buildHeader() override {
        std::cout << "Building DOC Header" << std::endl;
    }

    void buildBlock() override {
        std::cout << "Building DOC Block" << std::endl;
    }

    void buildEnding() override {
        std::cout << "Building DOC Ending" << std::endl;
    }

    QString getReport() override {
        return "Generated DOC report";
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
    virtual ~RobotBuilder() = default;
    virtual void buildHead() = 0;
    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;
    virtual Robot getRobot() = 0;
};

class SimpleRobotBuilder : public RobotBuilder {
private:
    Robot robot;

public:
    void buildHead() override {
        robot.head = "Simple Head";
        std::cout << "Simple Head" << std::endl;
    }

    void buildBody() override {
        robot.body = "Simple Body";
        std::cout << "Simple Body" << std::endl;
    }

    void buildEngine() override {
        robot.engine = "Simple Engine";
        std::cout << "Simple Engine" << std::endl;
    }

    Robot getRobot() override {
        return robot;
    }
};

// Представление лица с параметрами: Eyes, Nose, Mouth, Ears, Hair
class Face {
public:
    QString eyes;
    QString nose;
    QString mouth;
    QString ears;
    QString hair;
};

// Конкретные строители лица
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

class UglyFaceBuilder : public FaceBuilder {
private:
    Face face;

public:
    void buildEyes() override {
        face.eyes = "Ugly Eyes";
        std::cout << "Ugly Eyes" << std::endl;
    }

    void buildNose() override {
        face.nose = "Ugly Nose";
        std::cout << "Ugly Nose" << std::endl;
    }

    void buildMouth() override {
        face.mouth = "Ugly Mouth";
        std::cout << "Ugly Mouth" << std::endl;
    }

    void buildEars() override {
        face.ears = "Ugly Ears";
        std::cout << "Ugly Ears" << std::endl;
    }

    void buildHair() override {
        face.hair = "Ugly Hair";
        std::cout << "Ugly Hair" << std::endl;
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
    SimpleRobotBuilder robotBuilder;
    robotBuilder.buildHead();
    robotBuilder.buildBody();
    robotBuilder.buildEngine();
    Robot simpleRobot = robotBuilder.getRobot();

    // Создание лица героя
    UglyFaceBuilder uglyFaceBuilder;
    uglyFaceBuilder.buildEyes();
    uglyFaceBuilder.buildNose();
    uglyFaceBuilder.buildMouth();
    uglyFaceBuilder.buildEars();
    uglyFaceBuilder.buildHair();
    Face uglyFace = uglyFaceBuilder.getFace();

    Q_UNUSED(htmlReport)
    Q_UNUSED(txtReport)
    Q_UNUSED(xlsReport)
    Q_UNUSED(docReport)
    Q_UNUSED(simpleRobot)
    Q_UNUSED(uglyFace)

    return a.exec();
}
