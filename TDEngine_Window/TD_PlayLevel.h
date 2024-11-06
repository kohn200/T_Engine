#pragma once
#include "..\\TDEngine_SOURCE\\TD_Level.h"

class PlayLevel : public Level
{
public:
	PlayLevel();
	~PlayLevel();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;

private:

};

