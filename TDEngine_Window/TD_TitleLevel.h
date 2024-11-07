#pragma once
#include "..\\TDEngine_SOURCE\\TD_Level.h"

class TitleLevel : public Level
{
public:
	TitleLevel();
	~TitleLevel();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;

	virtual void OnEnter() override;
	virtual void OnExit() override;

private:

};

