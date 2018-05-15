#pragma once

// IRenderContext is not threadsafe!
struct IRenderContext
{
	virtual ~IRenderContext() = 0;

	// Viewport
	virtual const Vector2& GetViewportSize() const = 0;
	virtual void SetViewportSize(const Vector2&) = 0;

	// Basic Drawing
	virtual void DrawRect(const Rect& rect, const RGBA& color) const = 0;
};