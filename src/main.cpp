#include <iostream>
#include <memory>
#include <vector>
#include <expected>
#include <thread>
#include <chrono>
#include <print>
#include <fstream>
#include <filesystem>
#include <source_location>
#include <optional>
#include <functional>

#define SK_GANESH
#define SK_GL
#include "include/gpu/ganesh/GrBackendSurface.h"
#include "include/gpu/ganesh/GrDirectContext.h"
#include "include/gpu/ganesh/gl/GrGLInterface.h"
#include "include/gpu/ganesh/gl/GrGLAssembleInterface.h"
#include "include/gpu/ganesh/SkSurfaceGanesh.h"
#include "include/gpu/ganesh/gl/GrGLBackendSurface.h"
#include "include/gpu/ganesh/gl/GrGLDirectContext.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkColorSpace.h"
#include "include/core/SkSurface.h"

#include "glfw/glfw3.h"
#define GLFW_EXPOSE_NATIVE_WIN32
#include <windows.h>
#include <gl/GL.h>
#include "glfw/glfw3native.h"

GLFWwindow* window;

constexpr uint32_t width = 1366;
constexpr uint32_t height = 768;

int main()
{
    // glfw initialization
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(width, height, "RPG DEMO", NULL, NULL);

    glfwMakeContextCurrent(window);

    // create skia draw contexts
    auto glInterface = GrGLMakeNativeInterface();
    auto context = GrDirectContexts::MakeGL(glInterface);

    GrGLFramebufferInfo framebufferInfo;
    framebufferInfo.fFBOID = 0;
    framebufferInfo.fFormat = GL_RGBA8;

    auto colorType = kRGBA_8888_SkColorType;
    auto backendRenderTarget = GrBackendRenderTargets::MakeGL(width, height, 0, 0, framebufferInfo);
    auto surface = SkSurfaces::WrapBackendRenderTarget(context.get(), backendRenderTarget, kBottomLeft_GrSurfaceOrigin, colorType, nullptr, nullptr);

    context->flush();
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        auto canvas = surface->getCanvas();

        SkPaint paint;
        paint.setColor(SkColors::kRed);
        canvas->drawPaint(paint);
        // acá se dibuja
        ///////////////////////////////////
        
        ///////////////////////////////////
        context->flush();
        glfwSwapBuffers(window);
    }

    // glfw end
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}