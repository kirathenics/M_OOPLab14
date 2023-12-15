#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <vector>
using namespace std;

// Абстрактные классы прототипов
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
        cout << "Прямоугольник нарисован!" << endl;
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
        cout << "Линия нарисована!" << endl;
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
        cout << "Овал нарисован!" << endl;
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
        cout << "Текст нарисован!" << endl;
    }
};

// Специализация толстых фигур
class ThickRectangle : public Rectangle
{
public:
    unique_ptr<Shape> clone() override
    {
        return make_unique<ThickRectangle>(*this);
    }

    void draw() override
    {
        cout << "Толстый прямоугольник нарисован!" << endl;
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
        cout << "Толстая линия нарисована!" << endl;
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
        cout << "Толстый овал нарисован!" << endl;
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
        cout << "Толстый текст нарисован!" << endl;
    }
};

// Специализация тонких фигур
class ThinRectangle : public Rectangle
{
public:
    unique_ptr<Shape> clone() override
    {
        return make_unique<ThinRectangle>(*this);
    }

    void draw() override
    {
        cout << "Тонкий прямоугольник нарисован!" << endl;
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
        cout << "Тонкая линия нарисована!" << endl;
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
        cout << "Тонкий овал нарисован!" << endl;
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
        cout << "Тонкий текст нарисован!" << endl;
    }
};

// Абстрактная фабрика
class AbstractFactoryTask1
{
public:
    virtual unique_ptr<Rectangle> createRectangle() = 0;
    virtual unique_ptr<Line> createLine() = 0;
    virtual unique_ptr<Oval> createOval() = 0;
    virtual unique_ptr<Text> createText() = 0;
};

// Фабрика с толстыми фигурами
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

// Фабрика с тонкими фигурами
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

// Абстрактная фабрика
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

// Фабрика с векторными фигурами
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

// Фабрика с растровыми фигурами
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

// Абстрактный класс для каждой части отчета
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

// Заголовок отчета
class Header : public ReportPart
{
public:
    explicit Header(const string& body) : ReportPart(body) {}
};

// Блок данных отчета
class Block : public ReportPart
{
public:
    explicit Block(const string& body) : ReportPart(body) {}
};

// Концевик отчета
class Ending : public ReportPart
{
public:
    explicit Ending(const string& body) : ReportPart(body) {}
};

// Абстрактный строитель
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

// Конкретный строитель - строитель HTML-отчета
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

// Конкретный строитель - строитель текстового (TXT) отчета
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

// Конкретный строитель - строитель отчета в формате XLS
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

// Конкретный строитель - строитель отчета в формате DOC
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

// Фабричный метод для создания конкретного строителя
class ReportBuilderCreator
{
public:
    virtual ReportBuilder* createBuilder() const = 0;
};

// Фабричный метод для создания конкретного строителя в HTML-формате
class HtmlBuilderCreator : public ReportBuilderCreator
{
public:
    ReportBuilder* createBuilder() const override
    {
        return new HtmlBuilder();
    }
};

// Фабричный метод для создания конкретного строителя в формате TXT
class TxtBuilderCreator : public ReportBuilderCreator
{
public:
    ReportBuilder* createBuilder() const override
    {
        return new TxtBuilder();
    }
};

// Фабричный метод для создания конкретного строителя в формате XLS
class XlsBuilderCreator : public ReportBuilderCreator
{
public:
    ReportBuilder* createBuilder() const override
    {
        return new XlsBuilder();
    }
};

// Фабричный метод для создания конкретного строителя в формате DOC
class DocBuilderCreator : public ReportBuilderCreator
{
public:
    ReportBuilder* createBuilder() const override
    {
        return new DocBuilder();
    }
};

// Клиентский код, использующий фабричный метод
void client(const ReportBuilderCreator& builderCreator)
{
    ReportBuilder* builder = builderCreator.createBuilder();

    builder->buildHeader("Заголовок отчета");
    builder->buildBlock("Блок отчета");
    builder->buildEnding("Концевик отчета");

    string reportResult = builder->getResult();
    cout << "Generated report:\n" << reportResult;

    delete builder;
}

int main()
{
    setlocale(0, "");

    cout << "Задание 1" << endl;
    // Создание фабрики толстых фигур
    unique_ptr<AbstractFactoryTask1> thickFactory = make_unique<ThickShapeFactoryTask1>();

    // Создание объектов с помощью фабрики и клонирование прототипов
    unique_ptr<Shape> thickRectangle = thickFactory->createRectangle()->clone();
    unique_ptr<Shape> thickLine = thickFactory->createLine()->clone();
    unique_ptr<Shape> thickOval = thickFactory->createOval()->clone();
    unique_ptr<Shape> thickText = thickFactory->createText()->clone();

    // Отображение объектов
    thickRectangle->draw();
    thickLine->draw();
    thickOval->draw();
    thickText->draw();

    // Создание фабрики тонких фигур
    unique_ptr<AbstractFactoryTask1> thinFactory = make_unique<ThinShapeFactoryTask1>();

    // Создание объектов с помощью фабрики и клонирование прототипов
    unique_ptr<Shape> thinRectangle = thinFactory->createRectangle()->clone();
    unique_ptr<Shape> thinLine = thinFactory->createLine()->clone();
    unique_ptr<Shape> thinOval = thinFactory->createOval()->clone();
    unique_ptr<Shape> thinText = thinFactory->createText()->clone();

    // Отображение объектов
    thinRectangle->draw();
    thinLine->draw();
    thinOval->draw();
    thinText->draw();

    cout << endl << "Задание 2" << endl;
    // Создание фабрики векторных фигур
    AbstractFactoryTask2* thickFactorySingleton = AbstractFactoryTask2::createInstance("ThickShapeFactoryTask2");

    // Создание объектов с помощью фабрики и клонирование прототипов
    thickRectangle = thickFactorySingleton->createRectangle()->clone();
    thickLine = thickFactorySingleton->createLine()->clone();
    thickOval = thickFactorySingleton->createOval()->clone();
    thickText = thickFactorySingleton->createText()->clone();

    // Отображение объектов
    thickRectangle->draw();
    thickLine->draw();
    thickOval->draw();
    thickText->draw();

    // Создание фабрики растровых фигур
    AbstractFactoryTask2* thinFactorySingleton = AbstractFactoryTask2::createInstance("ThinShapeFactoryTask2");

    // Создание объектов с помощью фабрики и клонирование прототипов
    thinRectangle = thinFactorySingleton->createRectangle()->clone();
    thinLine = thinFactorySingleton->createLine()->clone();
    thinOval = thinFactorySingleton->createOval()->clone();
    thinText = thinFactorySingleton->createText()->clone();

    // Отображение объектов
    thinRectangle->draw();
    thinLine->draw();
    thinOval->draw();
    thinText->draw();

    cout << endl << "Задание 3" << endl;
    cout << "Создание HTML отчета:\n";
    client(HtmlBuilderCreator());

    cout << "\nСоздание TXT отчета:\n";
    client(TxtBuilderCreator());

    cout << "\nСоздание XLS отчета:\n";
    client(XlsBuilderCreator());

    cout << "\nСоздание DOC отчета:\n";
    client(DocBuilderCreator());

    return 0;
}