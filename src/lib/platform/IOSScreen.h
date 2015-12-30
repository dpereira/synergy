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

#pragma once

#include "synergy/PlatformScreen.h"
#include "synergy/DragInformation.h"
#include "common/stdexcept.h"

//! Base screen implementation
/*!
This screen implementation is the superclass of all other screen
implementations.  It implements a handful of methods and requires
subclasses to implement the rest.
*/
class IOSScreen : public PlatformScreen {
public:
	IOSScreen(IEventQueue* events);
	virtual ~IOSScreen();

	// IScreen overrides
	virtual void*		getEventTarget() const;
	virtual bool		getClipboard(ClipboardID id, IClipboard*) const;
	virtual void		getShape(SInt32& x, SInt32& y,
							SInt32& width, SInt32& height) const;
	virtual void		getCursorPos(SInt32& x, SInt32& y) const;

	// IPrimaryScreen overrides
	virtual void		reconfigure(UInt32 activeSides);
	virtual void		warpCursor(SInt32 x, SInt32 y);
	virtual UInt32		registerHotKey(KeyID key,
							KeyModifierMask mask);
	virtual void		unregisterHotKey(UInt32 id);
	virtual void		fakeInputBegin();
	virtual void		fakeInputEnd();
	virtual SInt32		getJumpZoneSize() const;
	virtual bool		isAnyMouseButtonDown(UInt32& buttonID) const;
	virtual void		getCursorCenter(SInt32& x, SInt32& y) const;

	// ISecondaryScreen overrides
	virtual void		fakeMouseButton(ButtonID id, bool press);
	virtual void		fakeMouseMove(SInt32 x, SInt32 y);
	virtual void		fakeMouseRelativeMove(SInt32 dx, SInt32 dy) const;
	virtual void		fakeMouseWheel(SInt32 xDelta, SInt32 yDelta) const;

	// IKeyState overrides
  /*
	virtual void		updateKeyMap();
	virtual void		updateKeyState();
	virtual void		setHalfDuplexMask(KeyModifierMask);
	virtual void		fakeKeyDown(KeyID id, KeyModifierMask mask,
							KeyButton button);
	virtual bool		fakeKeyRepeat(KeyID id, KeyModifierMask mask,
							SInt32 count, KeyButton button);
	virtual bool		fakeKeyUp(KeyButton button);
	virtual void		fakeAllKeysUp();
	virtual bool		fakeCtrlAltDel();
	virtual bool		isKeyDown(KeyButton) const;
	virtual KeyModifierMask
						getActiveModifiers() const;
	virtual KeyModifierMask
						pollActiveModifiers() const;
	virtual SInt32		pollActiveGroup() const;
	virtual void		pollPressedKeys(KeyButtonSet& pressedKeys) const;

	virtual void		setDraggingStarted(bool started) { m_draggingStarted = started; }
	virtual bool		isDraggingStarted();
	virtual bool		isFakeDraggingStarted() { return m_fakeDraggingStarted; }
	virtual String&	getDraggingFilename() { return m_draggingFilename; }
	virtual void		clearDraggingFilename() { }
*/
	// IPlatformScreen overrides
	virtual void		enable();
	virtual void		disable();
	virtual void		enter();
	virtual bool		leave();
	virtual bool		setClipboard(ClipboardID, const IClipboard*);
	virtual void		checkClipboards();
	virtual void		openScreensaver(bool notify);
	virtual void		closeScreensaver();
	virtual void		screensaver(bool activate);
	virtual void		resetOptions();
	virtual void		setOptions(const OptionsList& options);
	virtual void		setSequenceNumber(UInt32);
	virtual bool		isPrimary() const;
	
	virtual void		fakeDraggingFiles(DragFileList fileList) { throw std::runtime_error("fakeDraggingFiles not implemented"); }
	virtual const String&
						getDropTarget() const { throw std::runtime_error("getDropTarget not implemented"); }

protected:
	//! Update mouse buttons
	/*!
	Subclasses must implement this method to update their internal mouse
	button mapping and, if desired, state tracking.
	*/
	virtual void		updateButtons();

	//! Get the key state
	/*!
	Subclasses must implement this method to return the platform specific
	key state object that each subclass must have.
	*/
	virtual IKeyState*	getKeyState() const;

	// IPlatformScreen overrides
	virtual void		handleSystemEvent(const Event& event, void*);

protected:
	String				m_draggingFilename;
	bool				m_draggingStarted;
	bool				m_fakeDraggingStarted;
};
