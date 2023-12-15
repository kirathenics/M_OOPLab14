#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <vector>
using namespace std;

// ����������� ������ ����������
class Shape
{
public:
    virtual unique_ptr<Shape> clone() = 0;
    virtual void draw() = 0;
};

class Rectangle : public Shape
{
public:
    unique_ptr<Shape> clone() override
    {
        return make_unique<Rectangle>(*this);
    }

    void draw() override
    {
        cout << "������������� ���������!" << endl;
    }
};

class Line : public Shape
{
public:
    unique_ptr<Shape> clone() override
    {
        return make_unique<Line>(*this);
    }

    void draw() override
    {
        cout << "����� ����������!" << endl;
    }
};

class Oval : public Shape
{
public:
    unique_ptr<Shape> clone() override
    {
        return make_unique<Oval>(*this);
    }

    void draw() override
    {
        cout << "���� ���������!" << endl;
    }
};

class Text : public Shape
{
public:
    unique_ptr<Shape> clone() override
    {
        return make_unique<Text>(*this);
    }

    void draw() override
    {
        cout << "����� ���������!" << endl;
    }
};

// ������������� ������� �����
class ThickRectangle : public Rectangle
{
public:
    unique_ptr<Shape> clone() override
    {
        return make_unique<ThickRectangle>(*this);
    }

    void draw() override
    {
        cout << "������� ������������� ���������!" << endl;
    }
};

class ThickLine : public Line
{
public:
    unique_ptr<Shape> clone() override
    {
        return make_unique<ThickLine>(*this);
    }

    void draw() override
    {
        cout << "������� ����� ����������!" << endl;
    }
};

class ThickOval : public Oval
{
public:
    unique_ptr<Shape> clone() override
    {
        return make_unique<ThickOval>(*this);
    }

    void draw() override
    {
        cout << "������� ���� ���������!" << endl;
    }
};

class ThickText : public Text
{
public:
    unique_ptr<Shape> clone() override
    {
        return make_unique<ThickText>(*this);
    }

    void draw() override
    {
        cout << "������� ����� ���������!" << endl;
    }
};

// ������������� ������ �����
class ThinRectangle : public Rectangle
{
public:
    unique_ptr<Shape> clone() override
    {
        return make_unique<ThinRectangle>(*this);
    }

    void draw() override
    {
        cout << "������ ������������� ���������!" << endl;
    }
};

class ThinLine : public Line
{
public:
    unique_ptr<Shape> clone() override
    {
        return make_unique<ThinLine>(*this);
    }

    void draw() override
    {
        cout << "������ ����� ����������!" << endl;
    }
};

class ThinOval : public Oval
{
public:
    unique_ptr<Shape> clone() override
    {
        return make_unique<ThinOval>(*this);
    }

    void draw() override
    {
        cout << "������ ���� ���������!" << endl;
    }
};

class ThinText : public Text
{
public:
    unique_ptr<Shape> clone() override
    {
        return make_unique<ThinText>(*this);
    }

    void draw() override
    {
        cout << "������ ����� ���������!" << endl;
    }
};

// ����������� �������
class AbstractFactoryTask1
{
public:
    virtual unique_ptr<Rectangle> createRectangle() = 0;
    virtual unique_ptr<Line> createLine() = 0;
    virtual unique_ptr<Oval> createOval() = 0;
    virtual unique_ptr<Text> createText() = 0;
};

// ������� � �������� ��������
class ThickShapeFactoryTask1 : public AbstractFactoryTask1
{
public:
    unique_ptr<Rectangle> createRectangle() override
    {
        return make_unique<ThickRectangle>();
    }

    unique_ptr<Line> createLine() override
    {
        return make_unique<ThickLine>();
    }

    unique_ptr<Oval> createOval() override
    {
        return make_unique<ThickOval>();
    }

    unique_ptr<Text> createText() override
    {
        return make_unique<ThickText>();
    }
};

// ������� � ������� ��������
class ThinShapeFactoryTask1 : public AbstractFactoryTask1
{
public:
    unique_ptr<Rectangle> createRectangle() override
    {
        return make_unique<ThinRectangle>();
    }

    unique_ptr<Line> createLine() override
    {
        return make_unique<ThinLine>();
    }

    unique_ptr<Oval> createOval() override
    {
        return make_unique<ThinOval>();
    }

    unique_ptr<Text> createText() override
    {
        return make_unique<ThinText>();
    }
};

// ����������� �������
class AbstractFactoryTask2
{
public:
    virtual unique_ptr<Rectangle> createRectangle() = 0;
    virtual unique_ptr<Line> createLine() = 0;
    virtual unique_ptr<Oval> createOval() = 0;
    virtual unique_ptr<Text> createText() = 0;

    static AbstractFactoryTask2* createInstance(string client)
    {
        return move(factoriesMap.at(client));
    }
private:
    typedef map<string, AbstractFactoryTask2*> FactoriesMap;
    static FactoriesMap factoriesMap;
protected:
    void RegisterFactory(string factory, AbstractFactoryTask2* factoryType)
    {
        factoriesMap.insert(FactoriesMap::value_type(factory, factoryType));
    }
};

AbstractFactoryTask2::FactoriesMap AbstractFactoryTask2::factoriesMap;

// ������� � ���������� ��������
class ThickShapeFactoryTask2 : public AbstractFactoryTask2
{
public:
    unique_ptr<Rectangle> createRectangle() override
    {
        return make_unique<ThickRectangle>();
    }

    unique_ptr<Line> createLine() override
    {
        return make_unique<ThickLine>();
    }

    unique_ptr<Oval> createOval() override
    {
        return make_unique<ThickOval>();
    }

    unique_ptr<Text> createText() override
    {
        return make_unique<ThickText>();
    }
private:
    ThickShapeFactoryTask2()
    {
        RegisterFactory("ThickShapeFactoryTask2", this);
    }
    ThickShapeFactoryTask2(const ThickShapeFactoryTask2& obj) = delete;
    static ThickShapeFactoryTask2 thickFactory;
};

ThickShapeFactoryTask2 ThickShapeFactoryTask2::thickFactory;

// ������� � ���������� ��������
class ThinShapeFactoryTask2 : public AbstractFactoryTask2
{
public:
    unique_ptr<Rectangle> createRectangle() override
    {
        return make_unique<ThinRectangle>();
    }

    unique_ptr<Line> createLine() override
    {
        return make_unique<ThinLine>();
    }

    unique_ptr<Oval> createOval() override
    {
        return make_unique<ThinOval>();
    }

    unique_ptr<Text> createText() override
    {
        return make_unique<ThinText>();
    }
private:
    ThinShapeFactoryTask2()
    {
        RegisterFactory("ThinShapeFactoryTask2", this);
    }
    ThinShapeFactoryTask2(const ThinShapeFactoryTask2& obj) = delete;
    static ThinShapeFactoryTask2 thinFactory;
};

ThinShapeFactoryTask2 ThinShapeFactoryTask2::thinFactory;

// ����������� ����� ��� ������ ����� ������
class ReportPart
{
public:
    explicit ReportPart(const string& body) : body(body) {}

    virtual string getContent() const
    {
        return body;
    }

protected:
    string body;
};

// ��������� ������
class Header : public ReportPart
{
public:
    explicit Header(const string& body) : ReportPart(body) {}
};

// ���� ������ ������
class Block : public ReportPart
{
public:
    explicit Block(const string& body) : ReportPart(body) {}
};

// �������� ������
class Ending : public ReportPart
{
public:
    explicit Ending(const string& body) : ReportPart(body) {}
};

// ����������� ���������
class ReportBuilder
{
public:
    virtual void buildHeader(const string& body) = 0;
    virtual void buildBlock(const string& body) = 0;
    virtual void buildEnding(const string& body) = 0;
    virtual string getResult() const = 0;

protected:
    vector<ReportPart*> parts;
};

// ���������� ��������� - ��������� HTML-������
class HtmlBuilder : public ReportBuilder
{
public:
    void buildHeader(const string& body) override
    {
        parts.push_back(new Header("<html><head><title>" + body + "</title></head><body>"));
    }

    void buildBlock(const string& body) override
    {
        parts.push_back(new Block("<div>" + body + "</div>"));
    }

    void buildEnding(const string& body) override
    {
        parts.push_back(new Ending("<div>" + body + "</div></body></html>"));
    }

    string getResult() const override
    {
        string result;
        for (const auto& part : parts)
        {
            result += part->getContent() + "\n";
        }
        return result;
    }
};

// ���������� ��������� - ��������� ���������� (TXT) ������
class TxtBuilder : public ReportBuilder
{
public:
    void buildHeader(const string& body) override
    {
        parts.push_back(new Header(body));
    }

    void buildBlock(const string& body) override
    {
        parts.push_back(new Block(body));
    }

    void buildEnding(const string& body) override
    {
        parts.push_back(new Ending(body));
    }

    string getResult() const override
    {
        string result;
        for (const auto& part : parts)
        {
            result += part->getContent() + "\n";
        }
        return result;
    }
};

// ���������� ��������� - ��������� ������ � ������� XLS
class XlsBuilder : public ReportBuilder
{
public:
    void buildHeader(const string& body) override
    {
        parts.push_back(new Header("<header info>" + body));
    }

    void buildBlock(const string& body) override
    {
        parts.push_back(new Block("<data>" + body));
    }

    void buildEnding(const string& body) override
    {
        parts.push_back(new Ending("<footer info>" + body));
    }

    string getResult() const override
    {
        string result;
        for (const auto& part : parts)
        {
            result += part->getContent() + "\n";
        }
        return result;
    }
};

// ���������� ��������� - ��������� ������ � ������� DOC
class DocBuilder : public ReportBuilder
{
public:
    void buildHeader(const string& body) override
    {
        parts.push_back(new Header("<header>" + body));
    }

    void buildBlock(const string& body) override
    {
        parts.push_back(new Block("<body>" + body));
    }

    void buildEnding(const string& body) override
    {
        parts.push_back(new Ending("<footer>" + body));
    }

    string getResult() const override
    {
        string result;
        for (const auto& part : parts)
        {
            result += part->getContent() + "\n";
        }
        return result;
    }
};

// ��������� ����� ��� �������� ����������� ���������
class ReportBuilderCreator
{
public:
    virtual ReportBuilder* createBuilder() const = 0;
};

// ��������� ����� ��� �������� ����������� ��������� � HTML-�������
class HtmlBuilderCreator : public ReportBuilderCreator
{
public:
    ReportBuilder* createBuilder() const override
    {
        return new HtmlBuilder();
    }
};

// ��������� ����� ��� �������� ����������� ��������� � ������� TXT
class TxtBuilderCreator : public ReportBuilderCreator
{
public:
    ReportBuilder* createBuilder() const override
    {
        return new TxtBuilder();
    }
};

// ��������� ����� ��� �������� ����������� ��������� � ������� XLS
class XlsBuilderCreator : public ReportBuilderCreator
{
public:
    ReportBuilder* createBuilder() const override
    {
        return new XlsBuilder();
    }
};

// ��������� ����� ��� �������� ����������� ��������� � ������� DOC
class DocBuilderCreator : public ReportBuilderCreator
{
public:
    ReportBuilder* createBuilder() const override
    {
        return new DocBuilder();
    }
};

// ���������� ���, ������������ ��������� �����
void client(const ReportBuilderCreator& builderCreator)
{
    ReportBuilder* builder = builderCreator.createBuilder();

    builder->buildHeader("��������� ������");
    builder->buildBlock("���� ������");
    builder->buildEnding("�������� ������");

    string reportResult = builder->getResult();
    cout << "Generated report:\n" << reportResult;

    delete builder;
}

int main()
{
    setlocale(0, "");

    cout << "������� 1" << endl;
    // �������� ������� ������� �����
    unique_ptr<AbstractFactoryTask1> thickFactory = make_unique<ThickShapeFactoryTask1>();

    // �������� �������� � ������� ������� � ������������ ����������
    unique_ptr<Shape> thickRectangle = thickFactory->createRectangle()->clone();
    unique_ptr<Shape> thickLine = thickFactory->createLine()->clone();
    unique_ptr<Shape> thickOval = thickFactory->createOval()->clone();
    unique_ptr<Shape> thickText = thickFactory->createText()->clone();

    // ����������� ��������
    thickRectangle->draw();
    thickLine->draw();
    thickOval->draw();
    thickText->draw();

    // �������� ������� ������ �����
    unique_ptr<AbstractFactoryTask1> thinFactory = make_unique<ThinShapeFactoryTask1>();

    // �������� �������� � ������� ������� � ������������ ����������
    unique_ptr<Shape> thinRectangle = thinFactory->createRectangle()->clone();
    unique_ptr<Shape> thinLine = thinFactory->createLine()->clone();
    unique_ptr<Shape> thinOval = thinFactory->createOval()->clone();
    unique_ptr<Shape> thinText = thinFactory->createText()->clone();

    // ����������� ��������
    thinRectangle->draw();
    thinLine->draw();
    thinOval->draw();
    thinText->draw();

    cout << endl << "������� 2" << endl;
    // �������� ������� ��������� �����
    AbstractFactoryTask2* thickFactorySingleton = AbstractFactoryTask2::createInstance("ThickShapeFactoryTask2");

    // �������� �������� � ������� ������� � ������������ ����������
    thickRectangle = thickFactorySingleton->createRectangle()->clone();
    thickLine = thickFactorySingleton->createLine()->clone();
    thickOval = thickFactorySingleton->createOval()->clone();
    thickText = thickFactorySingleton->createText()->clone();

    // ����������� ��������
    thickRectangle->draw();
    thickLine->draw();
    thickOval->draw();
    thickText->draw();

    // �������� ������� ��������� �����
    AbstractFactoryTask2* thinFactorySingleton = AbstractFactoryTask2::createInstance("ThinShapeFactoryTask2");

    // �������� �������� � ������� ������� � ������������ ����������
    thinRectangle = thinFactorySingleton->createRectangle()->clone();
    thinLine = thinFactorySingleton->createLine()->clone();
    thinOval = thinFactorySingleton->createOval()->clone();
    thinText = thinFactorySingleton->createText()->clone();

    // ����������� ��������
    thinRectangle->draw();
    thinLine->draw();
    thinOval->draw();
    thinText->draw();

    cout << endl << "������� 3" << endl;
    cout << "�������� HTML ������:\n";
    client(HtmlBuilderCreator());

    cout << "\n�������� TXT ������:\n";
    client(TxtBuilderCreator());

    cout << "\n�������� XLS ������:\n";
    client(XlsBuilderCreator());

    cout << "\n�������� DOC ������:\n";
    client(DocBuilderCreator());

    return 0;
}