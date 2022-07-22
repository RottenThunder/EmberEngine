#pragma once
#include "EmberEngine/Core/Base.h"
#include "RenderCommand.h"
#include "OrthographicCamera.h"
#include "Shader.h"

namespace EmberEngine
{
	class Renderer
	{
	private:
		struct SceneData
		{
			Matrix4x4 ViewProjectionMatrix;
		};

		static SceneData* sceneData;
	public:
		inline static API GetAPI() { return RendererAPI::GetAPI(); }

		static void Init();

		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void ClearScreen(float red, float green, float blue);
		static void ClearScreen(const Colour& colour);
		static void OnWindowResize(int32_t width, int32_t height);
		static void DrawVertexArray(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray);
	};
}