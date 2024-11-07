#pragma once
#include "..\\TDEngine_SOURCE\\TD_ScriptComponent.h"

class PlayerScript : public ScriptComponent
{
public:
	PlayerScript();
	~PlayerScript();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;

private:

};