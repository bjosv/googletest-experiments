#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::AtLeast;
using ::testing::NiceMock;

class Turtle {
public:
    virtual ~Turtle() {}
    virtual void PenUp() = 0;
    virtual void PenDown() = 0;
    virtual void Forward(int distance) = 0;
    virtual void Turn(int degrees) = 0;
    virtual void GoTo(int x, int y) = 0;
    virtual int GetX() const = 0;
    virtual int GetY() const = 0;
};

class Painter
{
    Turtle *turtle;

public:
    Painter(Turtle *turtle) : turtle(turtle) {}
    bool DrawCircle(int, int, int)
    {
        turtle->PenDown();
        return true;
    }
};

class MockTurtle : public Turtle
{
public:
    MOCK_METHOD0(PenUp, void());
    MOCK_METHOD0(PenDown, void());
    MOCK_METHOD1(Forward, void(int distance));
    MOCK_METHOD1(Turn, void(int degrees));
    MOCK_METHOD2(GoTo, void(int x, int y));
    MOCK_CONST_METHOD0(GetX, int());
    MOCK_CONST_METHOD0(GetY, int());
};

//-------------------------------------

TEST(PainterTest, CanDrawSomething)
{
    MockTurtle turtle;

    EXPECT_CALL(turtle, PenDown())
        .Times(AtLeast(1));

    Painter painter(&turtle);

    EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
}

TEST(NiceMockTest, CanDrawSomething)
{
    NiceMock<MockTurtle> turtle;

    EXPECT_CALL(turtle, PenDown())
        .Times(AtLeast(1));

    Painter painter(&turtle);

    EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
}
