/**
 * vim: set ts=4 :
 * =============================================================================
 * SourceMod Sample Extension
 * Copyright (C) 2004-2008 AlliedModders LLC.  All rights reserved.
 * =============================================================================
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License, version 3.0, as published by the
 * Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * As a special exception, AlliedModders LLC gives you permission to link the
 * code of this program (as well as its derivative works) to "Half-Life 2," the
 * "Source Engine," the "SourcePawn JIT," and any Game MODs that run on software
 * by the Valve Corporation.  You must obey the GNU General Public License in
 * all respects for all other code used.  Additionally, AlliedModders LLC grants
 * this exception to all derivative works.  AlliedModders LLC defines further
 * exceptions, found in LICENSE.txt (as of this writing, version JULY-31-2007),
 * or <http://www.sourcemod.net/license.php>.
 *
 * Version: $Id$
 */

#ifndef _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_
#define _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_

/**
 * @file extension.h
 * @brief Sample extension code header.
 */

#include "sdk/smsdk_ext.h"
#include "CDetour/detours.h"

#ifndef DETOUR_DECL_STATIC5
#define DETOUR_DECL_STATIC5(name, ret, p1type, p1name, p2type, p2name, p3type, p3name, p4type, p4name, p5type, p5name) \
ret (*name##_Actual)(p1type, p2type, p3type, p4type, p5type) = NULL; \
ret name(p1type p1name, p2type p2name, p3type p3name, p4type p4name, p5type p5name)
#endif

#ifndef DETOUR_DECL_STATIC6
#define DETOUR_DECL_STATIC6(name, ret, p1type, p1name, p2type, p2name, p3type, p3name, p4type, p4name, p5type, p5name, p6type, p6name) \
ret (*name##_Actual)(p1type, p2type, p3type, p4type, p5type, p6type) = NULL; \
ret name(p1type p1name, p2type p2name, p3type p3name, p4type p4name, p5type p5name, p6type p6name)
#endif

#ifndef DETOUR_DECL_STATIC7
#define DETOUR_DECL_STATIC7(name, ret, p1type, p1name, p2type, p2name, p3type, p3name, p4type, p4name, p5type, p5name, p6type, p6name, p7type, p7name) \
ret (*name##_Actual)(p1type, p2type, p3type, p4type, p5type, p6type, p7type) = NULL; \
ret name(p1type p1name, p2type p2name, p3type p3name, p4type p4name, p5type p5name, p6type p6name, p7type p7name)
#endif

#ifndef DETOUR_DECL_STATIC8
#define DETOUR_DECL_STATIC8(name, ret, p1type, p1name, p2type, p2name, p3type, p3name, p4type, p4name, p5type, p5name, p6type, p6name, p7type, p7name, p8type, p8name) \
ret (*name##_Actual)(p1type, p2type, p3type, p4type, p5type, p6type, p7type, p8type) = NULL; \
ret name(p1type p1name, p2type p2name, p3type p3name, p4type p4name, p5type p5name, p6type p6name, p7type p7name, p8type p8name)
#endif

#ifndef DETOUR_CREATE_STATIC_FIXED
#define DETOUR_CREATE_STATIC_FIXED(name, address) CDetourManager::CreateDetour(GET_STATIC_CALLBACK(name), GET_STATIC_TRAMPOLINE(name), address);
#endif

#include "isteamgameserver.h"
#include "steam_gameserver.h"

#include "swgameserver.h"
#include "swgamedata.h"

#include "swforwards.h"
#include "gsnatives.h"
#include "swgshooks.h"
#include "swgchooks.h"
#include "ssnatives.h"
#include "gcnatives.h"
#include "swgsdetours.h"
#include "swhttp.h"

/**
 * @brief Sample implementation of the SDK Extension.
 * Note: Uncomment one of the pre-defined virtual functions in order to use it.
 */
class SteamWorks :
	public SDKExtension
{
public:
	/**
	 * @brief This is called after the initial loading sequence has been processed.
	 *
	 * @param error		Error message buffer.
	 * @param maxlength	Size of error message buffer.
	 * @param late		Whether or not the module was loaded after map load.
	 * @return			True to succeed loading, false to fail.
	 */
	virtual bool SDK_OnLoad(char *error, size_t maxlength, bool late);
	
	/**
	 * @brief This is called right before the extension is unloaded.
	 */
	virtual void SDK_OnUnload();

	/**
	 * @brief This is called once all known extensions have been loaded.
	 * Note: It is is a good idea to add natives here, if any are provided.
	 */
	//virtual void SDK_OnAllLoaded();

	/**
	 * @brief Called when the pause state is changed.
	 */
	//virtual void SDK_OnPauseChange(bool paused);

	/**
	 * @brief this is called when Core wants to know if your extension is working.
	 *
	 * @param error		Error message buffer.
	 * @param maxlength	Size of error message buffer.
	 * @return			True if working, false otherwise.
	 */
	//virtual bool QueryRunning(char *error, size_t maxlength);
public:
#if defined SMEXT_CONF_METAMOD
	/**
	 * @brief Called when Metamod is attached, before the extension version is called.
	 *
	 * @param error			Error buffer.
	 * @param maxlength		Maximum size of error buffer.
	 * @param late			Whether or not Metamod considers this a late load.
	 * @return				True to succeed, false to fail.
	 */
	//virtual bool SDK_OnMetamodLoad(ISmmAPI *ismm, char *error, size_t maxlength, bool late);

	/**
	 * @brief Called when Metamod is detaching, after the extension version is called.
	 * NOTE: By default this is blocked unless sent from SourceMod.
	 *
	 * @param error			Error buffer.
	 * @param maxlength		Maximum size of error buffer.
	 * @return				True to succeed, false to fail.
	 */
	//virtual bool SDK_OnMetamodUnload(char *error, size_t maxlength);

	/**
	 * @brief Called when Metamod's pause state is changing.
	 * NOTE: By default this is blocked unless sent from SourceMod.
	 *
	 * @param paused		Pause state being set.
	 * @param error			Error buffer.
	 * @param maxlength		Maximum size of error buffer.
	 * @return				True to succeed, false to fail.
	 */
	//virtual bool SDK_OnMetamodPauseChange(bool paused, char *error, size_t maxlength);
#endif
	//public: /* IClientListener */
	//virtual void OnClientDisconnecting(int client);
public:
	CSteamID CreateCommonCSteamID(IGamePlayer *pPlayer, const cell_t *params, unsigned char universeplace, unsigned char typeplace);
	CSteamID CreateCommonCSteamID(uint32_t authid, const cell_t *params, unsigned char universeplace, unsigned char typeplace);

public:
	SteamWorksForwards *pSWForward;
	SteamWorksGameData *pSWGameData;
	SteamWorksGameServer *pSWGameServer;
	SteamWorksGSNatives *pGSNatives;
	SteamWorksGSHooks *pGSHooks;
	SteamWorksSSNatives *pSSNatives;
	SteamWorksGSDetours *pGSDetours;
	SteamWorksHTTP *pSWHTTP;
	SteamWorksHTTPNatives *pSWHTTPNatives;
	SteamWorksGCHooks *pGCHooks;
	SteamWorksGCNatives *pGCNatives;
};

extern SteamWorks g_SteamWorks;
#endif // _INCLUDE_SOURCEMOD_EXTENSION_PROPER_H_
