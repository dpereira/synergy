/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2012 Synergy Si Ltd.
 * Copyright (C) 2004 Chris Schoeneman
 * 
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 * 
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "platform/IOSScreen.h"
#include "synergy/KeyState.h"
#include "base/Log.h"


IOSScreen::IOSScreen(IEventQueue* events) :
  PlatformScreen(events)
{
}

IOSScreen::~IOSScreen()
{
}

void*
IOSScreen::getEventTarget() const
{
	return const_cast<IOSScreen*>(this);
}

bool
IOSScreen::getClipboard(ClipboardID, IClipboard* dst) const
{
	return true;
}

void
IOSScreen::getShape(SInt32& x, SInt32& y, SInt32& w, SInt32& h) const
{
}

void
IOSScreen::getCursorPos(SInt32& x, SInt32& y) const
{
}

void
IOSScreen::reconfigure(UInt32)
{
}

void
IOSScreen::warpCursor(SInt32 x, SInt32 y)
{
}

void
IOSScreen::fakeInputBegin()
{
}

void
IOSScreen::fakeInputEnd()
{
}

SInt32
IOSScreen::getJumpZoneSize() const
{
	return 1;
}

bool
IOSScreen::isAnyMouseButtonDown(UInt32& buttonID) const
{
  return false;
}

void
IOSScreen::getCursorCenter(SInt32& x, SInt32& y) const
{
}

UInt32
IOSScreen::registerHotKey(KeyID key, KeyModifierMask mask)
{
	return 0;
}

void
IOSScreen::unregisterHotKey(UInt32 id)
{
}
/*
void
IOSScreen::constructMouseButtonEventMap()
{
}*/

//void
//IOSScreen::postMouseEvent(CGPoint& pos) const
//{
//}

void
IOSScreen::fakeMouseButton(ButtonID id, bool press)
{
}

//void
//IOSScreen::getDropTargetThread(void*)
//{
//}

void
IOSScreen::fakeMouseMove(SInt32 x, SInt32 y)
{
}

void
IOSScreen::fakeMouseRelativeMove(SInt32 dx, SInt32 dy) const
{
}

void
IOSScreen::fakeMouseWheel(SInt32 xDelta, SInt32 yDelta) const
{
}

//void
//IOSScreen::showCursor()
//{
//}

//void
//IOSScreen::hideCursor()
//{
//}
//
void
IOSScreen::enable()
{
}

void
IOSScreen::disable()
{
}

void
IOSScreen::enter()
{
}

bool
IOSScreen::leave()
{
	return true;
}

bool
IOSScreen::setClipboard(ClipboardID, const IClipboard* src)
{
	return true;
}

void
IOSScreen::checkClipboards()
{
}

void
IOSScreen::openScreensaver(bool notify)
{
}

void
IOSScreen::closeScreensaver()
{
}

void
IOSScreen::screensaver(bool activate)
{
}

void
IOSScreen::resetOptions()
{
	// no options
}

void
IOSScreen::setOptions(const OptionsList&)
{
	// no options
}

void
IOSScreen::setSequenceNumber(UInt32 seqNum)
{
}

bool
IOSScreen::isPrimary() const
{
	return true;
}

//void
//IOSScreen::sendEvent(Event::Type type, void* data) const
//{
//}

//void
//IOSScreen::sendClipboardEvent(Event::Type type, ClipboardID id) const
//{
//}

void
IOSScreen::handleSystemEvent(const Event& event, void*)
{
}

//bool 
//IOSScreen::onMouseMove(SInt32 mx, SInt32 my)
//{
//	return true;
//}

//bool				
//IOSScreen::onMouseButton(bool pressed, UInt16 macButton)
//{
//	return true;
//}

//bool
//IOSScreen::onMouseWheel(SInt32 xDelta, SInt32 yDelta) const
//{
//	return true;
//}

//void
//IOSScreen::handleClipboardCheck(const Event&, void*)
//{
//}

//void 
//IOSScreen::displayReconfigurationCallback(CGDirectDisplayID displayID, CGDisplayChangeSummaryFlags flags, void* inUserData)
//{
//}

//bool
//IOSScreen::onKey(CGEventRef event)
//{
//	return true;
//}

//bool
//IOSScreen::onHotKey(EventRef event) const
//{
//	return true;
//}
//
//ButtonID 
//IOSScreen::mapMacButtonToSynergy(UInt16 macButton) const
//{
//	return static_cast<ButtonID>(macButton);
//}
//
//SInt32
//IOSScreen::mapScrollWheelToSynergy(SInt32 x) const
//{
//	return static_cast<SInt32>(120.0);
//}
//
//SInt32
//IOSScreen::mapScrollWheelFromSynergy(SInt32 x) const
//{
//	return static_cast<SInt32>(3.0 * x / 120.0);
//}

//double
//IOSScreen::getScrollSpeed() const
//{
//	double scaling = 1.0;
//	return scaling;
//}
//
//double
//IOSScreen::getScrollSpeedFactor() const
//{
//	return pow(10.0, getScrollSpeed());
//}
//
//void
//IOSScreen::enableDragTimer(bool enable)
//{
//}
//
//void
//IOSScreen::handleDrag(const Event&, void*)
//{
//}
//
void
IOSScreen::updateButtons()
{
}

IKeyState*
IOSScreen::getKeyState() const
{
	return NULL;
}

//void
//IOSScreen::updateScreenShape(const CGDirectDisplayID, const CGDisplayChangeSummaryFlags flags)
//{
//}

//void
//IOSScreen::updateScreenShape()
//{
//}

//
// SLEEP/WAKEUP NOTIFICATION SUPPORT
//
// IOSScreen::watchSystemPowerThread(void*)
// 
// main of thread monitoring system power (sleep/wakup) using a CFRunLoop
//

//void
//IOSScreen::watchSystemPowerThread(void*)
//{
//}
//
//void
//IOSScreen::powerChangeCallback(void* refcon, io_service_t service,
//						  natural_t messageType, void* messageArg)
//{
//}
//
//void
//IOSScreen::handlePowerChangeRequest(natural_t messageType, void* messageArg)
//{
//}
//
//void
//IOSScreen::handleConfirmSleep(const Event& event, void*)
//{
//}
//
//char*
//IOSScreen::CFStringRefToUTF8String(CFStringRef aString)
//{
//	return NULL;
//}
//

/*String&
IOSScreen::getDraggingFilename()
{
}*/


void
setZeroSuppressionInterval()
{
}

void
avoidSupression()
{
}

void
logCursorVisibility()
{
}

void
avoidHesitatingCursor()
{
}

