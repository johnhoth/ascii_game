#include <vector>

class Renderer {
    private:
    int some_test_value;
    public:
    Renderer(int value) : some_test_value(value) {}
    int get_value() { return some_test_value; }
};
