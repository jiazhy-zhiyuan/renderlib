#pragma once

namespace _detail
{
	struct IRenderCommand
	{
		virtual ~IRenderCommand() = default;

		// Render
		virtual void Render(IRenderer*, IRenderContext*) = 0;
	};
}

struct IRenderQueue
{
	virtual ~IRenderQueue() = default;

	// Lock
	virtual void Lock() = 0;
	virtual void Unlock() = 0;

	// Queue
	virtual void Clear() = 0;
	virtual void AddCommand(_detail::IRenderCommand* pCommand) = 0;

	// Render
	virtual void Render(IRenderContext*) = 0;

	// Offset
	virtual void SetRenderOffset(const math::Vector2& = math::Vector2()) = 0;
	virtual void AddRenderOffset(const math::Vector2&) = 0;
	virtual const math::Vector2& GetRenderOffset() = 0;

	// Render Target
	// nullptr = backbuffer
	virtual void SetRenderTarget(IRenderTarget*) = 0;
	virtual void ClearRenderTarget(IRenderTarget*, const math::RGBA&) = 0;

	// Draw
	virtual void DrawRect(const math::Rect& rect, const math::RGBA&) = 0;
	virtual void DrawTexture(const math::Vector2& position, IRenderTexture* pTexture) = 0;

	// Text
	virtual void SetFont(const std::string& name, float size, const math::RGBA& color) = 0;
	virtual void SetFont(IRenderFont*) = 0;

	virtual void TextDrawString(const math::Vector2& position, const std::string& str) = 0;
	virtual void TextDrawStringEx(const math::Vector2& position, const math::Vector2& size, const std::string& str, FontRenderFlags::Enum eFlags) = 0;
};