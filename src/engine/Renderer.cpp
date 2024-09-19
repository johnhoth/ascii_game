#include "Renderer.hpp"
#include <iostream> // For std::cerr

// Constructor
Renderer::Renderer(int width, int height, int charWidth, int charHeight, SDL_Renderer* sdlRenderer)
    : width(width), height(height), charWidth(charWidth), charHeight(charHeight), sdlRenderer(sdlRenderer) {
    buffer.resize(height, std::string(width, ' ')); // Initialize buffer with spaces
    // Initialize TTF
    TTF_Init();
    // font = TTF_OpenFont("path/to/font.ttf", 24); // Load your font here
    font = TTF_OpenFont("C:/Windows/Fonts/Cour.ttf", 14);
    if (font == nullptr) {
        std::cerr << "Failed to load font! TTF_Error: " << TTF_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        exit(-1);
    }
}

// Destructor
Renderer::~Renderer() {
    TTF_CloseFont(font);
    TTF_Quit();
}

// Clear the screen (if needed)
void Renderer::clear() {
    SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255); // Black background
    SDL_RenderClear(sdlRenderer);
}

// Render text
void Renderer::render(const std::string& text) {
    buffer.clear(); // Clear the buffer before rendering
    buffer.resize(height, std::string(width, ' ')); // Initialize buffer with spaces

    // Simple logic to fill the buffer with text
    int currentRow = 0;
    int currentCol = 0;

    for (const char& c : text) {
        if (c == '\n' || currentCol >= width) { // New line or end of line
            currentRow++;
            currentCol = 0; // Reset column
        }

        if (currentRow >= height) {
            break; // Stop if we exceed the buffer height
        }

        buffer[currentRow][currentCol] = c; // Fill the buffer with characters
        currentCol++;
    }
}

// Display the rendered text
void Renderer::display() {
    // Clear the SDL renderer
    SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255); // Black background
    SDL_RenderClear(sdlRenderer);

    // Set the color for the text
    SDL_Color textColor = { 255, 255, 255, 255 }; // White text

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            char c = buffer[y][x];

            // Create a surface with the character
            std::string charStr(1, c);

            SDL_Surface* textSurface = TTF_RenderText_Solid(font, charStr.c_str(), textColor);
            if (!textSurface) {
                std::cerr << "Failed to create text surface: " << TTF_GetError() << std::endl;
                continue;
            }

            // Create texture from surface
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface(sdlRenderer, textSurface);
            if (!textTexture) {
                std::cerr << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
            }

            // Set the destination rectangle for rendering
            SDL_Rect dstRect;
            dstRect.x = x * charWidth; // Adjust position based on character width
            dstRect.y = y * charHeight; // Adjust position based on character height
            dstRect.w = charWidth; // Set width of character
            dstRect.h = charHeight; // Set height of character

            // Render the character
            SDL_RenderCopy(sdlRenderer, textTexture, NULL, &dstRect);

            // Clean up
            SDL_FreeSurface(textSurface);
            SDL_DestroyTexture(textTexture);
        }
    }

    // Present the rendered frame
    SDL_RenderPresent(sdlRenderer);
}

int Renderer::getWidth() const {
    return width;
}

int Renderer::getHeight() const {
    return height;
}
