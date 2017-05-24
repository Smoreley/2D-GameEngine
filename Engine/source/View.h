#pragma once

class View {
public:
	View();
	virtual ~View();

	virtual bool Init();
	virtual void Update() = 0;


private:

};