#include "renderer.h"
#include <QOpenGLFunctions>

bool Renderer::Initialize(QOpenGLFunctions* gl)
{
    if (!m_shader.LoadFromFile(
            "Assets/Shaders/Triangle.vert",
            "Assets/Shaders/Triangle.frag"))
    {
        return false;
    }

    return m_cube.Create();
}

void Renderer::Render(
    QOpenGLFunctions* gl,
    const Transform& transform,
    const Camera& camera,
    int width,
    int height)
{
    //-----------------------------------------
    // Build Model Matrix
    //-----------------------------------------
    QMatrix4x4 model;

    model.translate(transform.Position);

    model.rotate(transform.Rotation.x(), 1, 0, 0);
    model.rotate(transform.Rotation.y(), 0, 1, 0);
    model.rotate(transform.Rotation.z(), 0, 0, 1);

    model.scale(transform.Scale);

    //-----------------------------------------
    // Camera
    //-----------------------------------------
    QMatrix4x4 view =
        camera.GetViewMatrix();

    QMatrix4x4 projection =
        camera.GetProjectionMatrix(
            float(width) / float(height));

    //-----------------------------------------
    // Clear
    //-----------------------------------------
    gl->glClearColor(
        0.08f,
        0.08f,
        0.10f,
        1.0f);

    gl->glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT);

    //-----------------------------------------
    // Shader
    //-----------------------------------------
    m_shader.Bind();

    auto& program = m_shader.Program();

    program.setUniformValue("uModel", model);
    program.setUniformValue("uView", view);
    program.setUniformValue("uProjection", projection);

    //-----------------------------------------
    // Mesh
    //-----------------------------------------
    m_cube.Draw(gl);

    m_shader.Release();
}
