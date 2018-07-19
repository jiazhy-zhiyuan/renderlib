#pragma once
#include "D3D11Renderer.h"
#include "D3D11RenderTexture.h"

class D3D11RenderTarget : public IRenderTarget
{
	ID3D11Texture2D* m_pRenderTexture = nullptr;
    ID3D11RenderTargetView* m_pRenderTargetView = nullptr;

	ID3D11ShaderResourceView* m_pShaderResourceView = nullptr;
	ID3D11DepthStencilView* m_pDepthStencilView = nullptr;

	bool m_bBackbuffer = false;

public:
	D3D11RenderTarget() = default;
	virtual ~D3D11RenderTarget() override;

    virtual bool Initialize(IRenderer* pRenderer, const Vector2&) override;
	bool InitializeBackbuffer(D3D11Renderer*);
	
    virtual bool IsBackbuffer() const override { return m_bBackbuffer; };

	virtual void Apply(IRenderContext*) override;
	virtual void Clear(IRenderContext*, const RGBA& col) override;
	virtual void ClearStencil(IRenderContext*) override;

	virtual bool CopyTexture(IRenderContext*, IRenderTexture* pTexture) override;
};