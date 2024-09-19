#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>

class Renderer {
public:
    Renderer(int width, int height, int charWidth, int charHeight, SDL_Renderer* sdlRenderer);
    ~Renderer();
    void clear();
    void render(const std::string& text);
    void display();
    int getWidth() const;
    int getHeight() const;

private:
    int width, height;
    int charWidth, charHeight;
    SDL_Renderer* sdlRenderer;
    TTF_Font* font;
    std::vector<std::string> buffer;
};

#endif // RENDERER_HPP
