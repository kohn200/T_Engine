#pragma once
#include "TD_Component.h"

class ScriptComponent : public Component
{
public:
	ScriptComponent();
	~ScriptComponent();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;

private:

};

