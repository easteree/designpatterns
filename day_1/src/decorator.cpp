#include <iostream> 
#include <string>

class Window
{
public:
    virtual void draw() = 0;
    virtual std::string getDescription() const = 0;
    virtual ~Window() {};
};

class SimpleWindow : public Window
{
public:
    SimpleWindow() = default;
    SimpleWindow(const std::string& desc) :m_desc{ desc } {}

    virtual void draw() override
    {
        // if this was a gui app draw window 
    }
    virtual std::string getDescription() const override
    {
        return m_desc;
    }

private:
    std::string m_desc{ "Simple Window" };
};

class WindowDecorator : public Window
{

public:
    WindowDecorator(Window& decoratedWindow) : m_decoratedWindow{ decoratedWindow } {
    }

protected:
    constexpr auto window() -> Window& { return m_decoratedWindow; }
    constexpr auto window() const -> const Window& { return m_decoratedWindow; }

private:
    Window& m_decoratedWindow;
};

class VerticalScrollBarDecorator : public WindowDecorator
{
public:
    VerticalScrollBarDecorator(Window& decoratedWindow)
        : WindowDecorator(decoratedWindow)
    {

    }

    void draw() override
    {
        drawVerticalScrollBar();
        window().draw();
    }

    std::string getDescription() const override
    {
        return window().getDescription() + "\n  - vertical scrollbar";
    }

private:
    void drawVerticalScrollBar()
    {
        // if this was a gui app draw vertical scrollbar
        // cout...
    }
};

class HorizontalScrollBarDecorator : public WindowDecorator
{
public:
    HorizontalScrollBarDecorator(Window& decoratedWindow)
        : WindowDecorator(decoratedWindow)
    {

    }

    void draw() override
    {
        drawHorizontalScrollBar();
        window().draw();
    }

    std::string getDescription() const override
    {
        return window().getDescription() + "\n  - horizontal scrollbar";
    }

private:
    void drawHorizontalScrollBar()
    {
        // if this was a gui app draw horizontal scrollbar
        // cout...
    }
};

int main()
{
    SimpleWindow simple{};
    std::cout << simple.getDescription() << std::endl;

    SimpleWindow base_window("Window with");
    VerticalScrollBarDecorator vert(base_window);
    HorizontalScrollBarDecorator horiz(vert);
    Window& decorated_window = horiz;

    std::cout << decorated_window.getDescription() << std::endl;

    return 0;
}
