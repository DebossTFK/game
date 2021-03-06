#pragma once

#include "cbase.h"
#include <run/mom_entity_run_data.h>
#include <run/run_stats.h>
#include <../interpolatedvar.h>

class C_MomentumReplayGhostEntity : public C_BaseAnimating
{
    DECLARE_CLASS(C_MomentumReplayGhostEntity, C_BaseAnimating);
    DECLARE_CLIENTCLASS();
    DECLARE_INTERPOLATION()

  public:
    C_MomentumReplayGhostEntity();

    CMOMRunEntityData m_RunData;
    CMomRunStats m_RunStats;

    float m_flTickRate;

    int m_nReplayButtons;
    // These are stored here because run stats already has the ones obtained from the run
    int m_iTotalStrafes;
    int m_iTotalJumps;
    bool m_bIsPaused;

    int m_iTotalTimeTicks; // The total tick count of the playback
    int m_iCurrentTick;    // The current tick of playback

    char m_pszPlayerName[MAX_PLAYER_NAME_LENGTH];
    bool ShouldInterpolate() OVERRIDE { return true; }
    CInterpolatedVar<Vector> m_iv_vecViewOffset;
};