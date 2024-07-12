#include <iostream>

class IRenderer {
    public:
        virtual void Draw() = 0;    // pure virtual function
        virtual void Update() = 0;  // pure virtual function
        virtual void DrawOptimized() = 0;  // pure virtual function
};
class OpenGL : public IRenderer {
    public:
        void Draw() override{
            std::cout << "OpenGL::Draw()\n";
        }
        void DrawOptimized() override {
        }
};
class Vulkan : public IRenderer{
    public:
        void Draw() override {
            std::cout << "Vulcan::Draw()\n";
        }
        void Update() override {
        } // enough to satisfy the compiler
        void DrawOptimized() override {
        }
};


int main(){

    IRenderer* myRenderer = new IRenderer;  // pure
    IRenderer* myRenderer = new OpenGL;  // This also doesn't work if update() is pure, because we dont have any impltion of Update in OpenGL
    myRenderer-> Update();
    myRenderer-> Draw();

    return 0;
}

// Abstract class - interfaces

