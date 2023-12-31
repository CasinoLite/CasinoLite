#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Texture.hpp"

#include <memory>

class Renderer {
public:
    static void Init();

    static void BeginScene();
    static void EndScene();
    static void Flush();

    static void ClearColor(const glm::vec4& color);

    // Primitives
    static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color);
    static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& color);
    static void DrawQuad(const glm::mat4& transform, const glm::vec4& color);

    static void DrawTexturedQuad(const glm::vec2& position, const glm::vec2& size, const std::shared_ptr<Texture>& texture,
                                 float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
    static void DrawRotatedTexturedQuad(const glm::vec2& position, const glm::vec2& size, float rotation,const std::shared_ptr<Texture>& texture,
                                        float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
    static void DrawTexturedQuad(const glm::mat4& transform, const std::shared_ptr<Texture>& texture,
                                 float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
private:
    static void StartBatch();
    static void NextBatch();
};
