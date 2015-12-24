#pragma once

#include "vstgui/standalone/iwindow.h"
#include "vstgui/standalone/iwindowcontroller.h"
#include "vstgui/standalone/icommand.h"

//------------------------------------------------------------------------
namespace MyApp {

//------------------------------------------------------------------------
class WindowController : public VSTGUI::Standalone::WindowControllerAdapter, public VSTGUI::Standalone::ICommandHandler
{
public:
	using WindowPtr = VSTGUI::Standalone::WindowPtr;
	using IWindow = VSTGUI::Standalone::IWindow;
	using Command = VSTGUI::Standalone::Command;
	using CPoint = VSTGUI::CPoint;
	
	static WindowPtr makeWindow ();

	WindowController ();

	CPoint constraintSize (const IWindow& window, const CPoint& newSize) override;
	void onClosed (const IWindow& window) override;
	bool canClose (const IWindow& window) const override;

	bool canHandleCommand (const Command& command) override;
	bool handleCommand (const Command& command) override;
private:
	struct Impl;
	struct EditImpl;
	std::unique_ptr<Impl> impl;
};

//------------------------------------------------------------------------
} // MyApp