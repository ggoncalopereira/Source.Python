/**
* =============================================================================
* Source Python
* Copyright (C) 2014 Source Python Development Team.  All rights reserved.
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
* As a special exception, the Source Python Team gives you permission
* to link the code of this program (as well as its derivative works) to
* "Half-Life 2," the "Source Engine," and any Game MODs that run on software
* by the Valve Corporation.  You must obey the GNU General Public License in
* all respects for all other code used.  Additionally, the Source.Python
* Development Team grants this exception to all derivative works.
*/

//---------------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------------
#include "eiface.h"
#include "ispsharedmemory.h"
#include "modules/usermessage/usermessage.h"
#include "engine/IEngineSound.h"
#include "engine/IEngineTrace.h"


// Externals
extern IEngineTrace* enginetrace;


//---------------------------------------------------------------------------------
// IVEngineServer
//---------------------------------------------------------------------------------
// Overloads
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(get_single_player_shared_memory_space_overload, GetSinglePlayerSharedMemorySpace, 1, 2);

// Visitor function
template<class T>
void IVEngineServer_Visitor(T cls)
{
	cls
		.def("get_launch_options",
			&IVEngineServer::GetLaunchOptions,
			"Returns abitrary launch options",
			reference_existing_object_policy()
		)

		.def("is_userid_in_use",
			&IVEngineServer::IsUserIDInUse,
			"Returns whether the user ID is in use.",
			args("userid")
		)

		.def("get_loading_process_for_userid",
			&IVEngineServer::GetLoadingProgressForUserID,
			args("userid")
		)

		.def("send_user_message",
			&IVEngineServer::SendUserMessage,
			args("filter", "message_type", "message")
		)

		.def("is_log_enabled",
			&IVEngineServer::IsLogEnabled,
			"Returns whether logging is enabled."
		)

		.def("get_timescale",
			&IVEngineServer::GetTimescale
		)

		.def("is_level_main_menu_background",
			&IVEngineServer::IsLevelMainMenuBackground,
			"Returns whether the engine is running a background map."
		)

		.def("is_any_client_low_violence",
			&IVEngineServer::IsAnyClientLowViolence,
			args("ent_num")
		)

		.def("is_split_screen_player",
			&IVEngineServer::IsSplitScreenPlayer,
			args("ent_num")
		)

		.def("get_split_screen_player_attack_to_edict",
			&IVEngineServer::GetSplitScreenPlayerAttachToEdict,
			args("ent_num"),
			reference_existing_object_policy()
		)

		.def("get_num_split_screen_users_attached_to_edict",
			&IVEngineServer::GetNumSplitScreenUsersAttachedToEdict,
			args("ent_num")
		)

		.def("get_split_screen_player_for_edict",
			&IVEngineServer::GetSplitScreenPlayerForEdict,
			args("ent_num", "slot"),
			reference_existing_object_policy()
		)

		.def("is_override_load_game_ents_on",
			&IVEngineServer::IsOverrideLoadGameEntsOn
		)

		.def("force_flush_entity",
			&IVEngineServer::ForceFlushEntity,
			args("entity")
		)

		.def("get_single_player_shared_memory_space",
			&IVEngineServer::GetSinglePlayerSharedMemorySpace,
			get_single_player_shared_memory_space_overload(
				"Finds or creates a shared memory_space.",
				args("name", "ent_num")
			)[reference_existing_object_policy()]
		)

		/*
		// TODO: void*
		.def("alloc_level_specific_data",
			&IVEngineServer::AllocLevelStaticData,
			"Allocates hunk memory.",
			args("bytes"),
			reference_existing_object_policy()
		)
		*/

		.def("is_creating_reslist",
			&IVEngineServer::IsCreatingReslist
		)

		.def("is_creating_xbox_reslist",
			&IVEngineServer::IsCreatingXboxReslist
		)

		.def("is_dedicated_server_for_xbox",
			&IVEngineServer::IsDedicatedServerForXbox
		)

		.def("is_dedicated_server_for_ps3",
			&IVEngineServer::IsDedicatedServerForPS3
		)

		.def("pause",
			&IVEngineServer::Pause,
			args("pause", "force")
		)

		.def("set_timescale",
			&IVEngineServer::SetTimescale,
			args("timescale")
		)

		.def("host_validated_session",
			&IVEngineServer::HostValidateSession,
			"Validates session."
		)

		.def("refresh_screen_if_necessary",
			&IVEngineServer::RefreshScreenIfNecessary,
			"Update the 360 pacifier/spinner."
		)

		.def("has_paint_map",
			&IVEngineServer::HasPaintmap,
			"Tells the engine to allocate paint surfaces."
		)
		/*
		.def("sphere_paint_surface",
			&IVEngineServer::SpherePaintSurface,
			args("model", "vector", "uchar", "float", "float")
		)

		.def("sphere_trace_paint_surface",
			&IVEngineServer::SphereTracePaintSurface,
			args("model", "vector", "vector", "float", "CUtlVector<unsigned char>")
		)
		*/

		.def("remove_all_paint",
			&IVEngineServer::RemoveAllPaint
		)

		.def("paint_all_surfaces",
			&IVEngineServer::PaintAllSurfaces,
			args("uchar")
		)

		/*
		.def("remove_paint",
			&IVEngineServer::RemovePaint,
			args("model")
		)
		*/

		.def("get_client_xuid",
			&IVEngineServer::GetClientXUID,
			args("edict")
		)

		.def("is_active_app",
			&IVEngineServer::IsActiveApp
		)

		.def("set_noclip_enabled",
			&IVEngineServer::SetNoClipEnabled
		)

		.def("get_paint_map_data_rle",
			&IVEngineServer::GetPaintmapDataRLE,
			args("mapdata")
		)

		.def("load_paint_map_data_rle",
			&IVEngineServer::LoadPaintmapDataRLE,
			args("mapdata")
		)

		.def("send_paint_map_data_to_client",
			&IVEngineServer::SendPaintmapDataToClient,
			args("edict")
		)

		.def("get_latency_for_choreo_sounds",
			&IVEngineServer::GetLatencyForChoreoSounds
		)

		.def("get_client_cross_player_platform",
			&IVEngineServer::GetClientCrossPlayPlatform,
			args("ent_num")
		)

		.def("ensure_instance_baseline",
			&IVEngineServer::EnsureInstanceBaseline,
			args("ent_num")
		)

		.def("reserve_server_for_queued_game",
			&IVEngineServer::ReserveServerForQueuedGame,
			args("reservation_payload")
		)
		
		/*
		.def("get_engine_hltv_info",
			&IVEngineServer::GetEngineHltvInfo,
			args("out")
		)
		*/
	;
}


//---------------------------------------------------------------------------------
// IEngineSound
//---------------------------------------------------------------------------------
inline void IEngineSound_EmitSound(IEngineSound* pEngineSound, IRecipientFilter& filter, int iEntIndex, int iChannel, const char *pSample, 
		float flVolume, float flAttenuation, int iFlags = 0, int iPitch = PITCH_NORM, const Vector *pOrigin = NULL, const Vector *pDirection = NULL,
		tuple origins = tuple(), bool bUpdatePositions = true, float soundtime = 0.0f, int speakerentity = -1)
{
	CUtlVector< Vector > pUtlVecOrigins;
	for(int i=0; i < len(origins); i++)
	{
		pUtlVecOrigins.AddToTail(extract<Vector>(origins[i]));
	}

	pEngineSound->EmitSound(filter, iEntIndex, iChannel, pSample, -1, pSample, flVolume, flAttenuation, 0, iFlags, iPitch, pOrigin, pDirection, &pUtlVecOrigins, bUpdatePositions, soundtime, speakerentity);
}

// Visitor function
template<class T>
void IEngineSound_Visitor(T cls)
{
	cls
		.def("is_looping_sound",
			&IEngineSound::IsLoopingSound,
			args("sample"),
			"Returns True if the given sample is looping."
		)
	;
	
	scope().attr("CONTENTS_BLOCKLIGHT") = CONTENTS_BLOCKLIGHT;

	scope().attr("SURF_NOPAINT") = SURF_NOPAINT;

	scope().attr("MASK_NPCFLUID") = MASK_NPCFLUID;
	scope().attr("MASK_SHOT_BRUSHONLY") = MASK_SHOT_BRUSHONLY;
	scope().attr("MASK_NPCWORLDSTATIC_FLUID") = MASK_NPCWORLDSTATIC_FLUID;
}


//---------------------------------------------------------------------------------
// IEngineTrace
//---------------------------------------------------------------------------------
inline int GetPointContents(const Vector &vecAbsPosition, IHandleEntity** ppEntity)
{
	return enginetrace->GetPointContents(vecAbsPosition, MASK_ALL, ppEntity);
}