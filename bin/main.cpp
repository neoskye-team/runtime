#include "SDL_main.h"
#include "bin/Backend.hpp"
#include "bin/EngineOptions.hpp"
#include "bin/IWindow.hpp"
#include "bin/SdlGLWindow.hpp"

int main(int argc, char** argv) {
    // heap alloc because we dont know exactly what type we have yet
    IWindow* win;
    neoskye::EngineOptions opts(argc, argv);
    const Backend backend = Backend::SDL2WithOpenGL;
    switch (backend) {

    case SDL2WithOpenGL:
        win = new SdlGLWindow();
        break;
    }
    return 0;
}