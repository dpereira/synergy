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

#include "synergy/PlatformScreen.h"
#include "synergy/App.h"
#include "synergy/ArgsBase.h"

PlatformScreen::PlatformScreen(IEventQueue* events) :
	IPlatformScreen(events),
	m_draggingStarted(false),
	m_fakeDraggingStarted(false)
{
}

PlatformScreen::~PlatformScreen()
{
	// do nothing
}

void
PlatformScreen::updateKeyMap()
{
  if(getKeyState() != NULL)
	getKeyState()->updateKeyMap();
}

void
PlatformScreen::updateKeyState()
{
  if(getKeyState() != NULL) {
	getKeyState()->updateKeyState();
	updateButtons();
  }
}

void
PlatformScreen::setHalfDuplexMask(KeyModifierMask mask)
{
  if(getKeyState() != NULL) {
	getKeyState()->setHalfDuplexMask(mask);
  }
}

void
PlatformScreen::fakeKeyDown(KeyID id, KeyModifierMask mask,
				KeyButton button)
{
  if(getKeyState() != NULL)
	getKeyState()->fakeKeyDown(id, mask, button);
}

bool
PlatformScreen::fakeKeyRepeat(KeyID id, KeyModifierMask mask,
				SInt32 count, KeyButton button)
{
  if(getKeyState() != NULL)
	return getKeyState()->fakeKeyRepeat(id, mask, count, button);
  else return true;
}

bool
PlatformScreen::fakeKeyUp(KeyButton button)
{
  if(getKeyState() != NULL)
	return getKeyState()->fakeKeyUp(button);
  else return true;
}

void
PlatformScreen::fakeAllKeysUp()
{
  if(getKeyState() != NULL)
	getKeyState()->fakeAllKeysUp();
}

bool
PlatformScreen::fakeCtrlAltDel()
{
  if(getKeyState() != NULL)
	return getKeyState()->fakeCtrlAltDel();
  else return true;
}

bool
PlatformScreen::isKeyDown(KeyButton button) const
{
  if(getKeyState() != NULL)
	return getKeyState()->isKeyDown(button);
  else return true;
}

KeyModifierMask
PlatformScreen::getActiveModifiers() const
{
  if(getKeyState() != NULL)
	return getKeyState()->getActiveModifiers();
  else return 0;
}

KeyModifierMask
PlatformScreen::pollActiveModifiers() const
{
  if(getKeyState() != NULL)
	return getKeyState()->pollActiveModifiers();
  else return 0;
}

SInt32
PlatformScreen::pollActiveGroup() const
{
  if(getKeyState() != NULL)
	return getKeyState()->pollActiveGroup();
  else return 0;
}

void
PlatformScreen::pollPressedKeys(KeyButtonSet& pressedKeys) const
{
  if(getKeyState() != NULL)
	getKeyState()->pollPressedKeys(pressedKeys);
}

bool
PlatformScreen::isDraggingStarted()
{
	if (App::instance().argsBase().m_enableDragDrop) {
		return m_draggingStarted;
	}
	return false;
}
