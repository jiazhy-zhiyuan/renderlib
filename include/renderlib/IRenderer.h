#pragma once

// IRenderer is threadsafe
struct IRenderer
{
	virtual ~IRenderer() = default;
	virtual void Shutdown() = 0;

	// Resources
	virtual IRenderFont* GetFont(const std::string& name) = 0;
    virtual IRenderTexture* CreateTexture() = 0;

	// Shader
	virtual IRenderShader* CreateShader(const ShaderType) = 0;

	// Render Target
	virtual IRenderTarget* CreateRenderTarget(const Vector2& size) = 0;
};
