#if defined _dodhooks_included
 #endinput
#endif
#define _dodhooks_included

enum
{
	RoundState_RoudInit = 0,
	RoundState_PreGame,
	RoundState_StartGame,
	RoundState_PreRound,
	RoundState_RoundRunning,
	RoundState_AlliesWin,
	RoundState_AxisWin,
	RoundState_Restart,
	RoundState_GameOver,
}

enum
{
	PlayerState_Active = 0,
	PlayerState_Welcome = 1,
	PlayerState_PickingTeam = 2,
	PlayerState_PickingClass = 3,
	PlayerState_DeathAnim = 4,
	PlayerState_ObserverMode = 6,
}

enum
{
	BombTargetState_Inactive = 0,
	BombTargetState_Active,
	BombTargetState_Armed,
}

/**
 * @brief Precaches a control point icon.
 *
 * @param materialName		Name of the material to precache.
 * @return				Returns the material index, 0 for error.
 */
native PrecacheCPIcon(const String:materialName[]);

/**
 * @brief Sets the different icons on the control point specified.
 *
 * @param cpindex			Control point index.
 * @param iconAllies		Allies captured/owning icon.
 * @param iconAxis		Axis captured/owning icon.
 * @param iconUnsigned		Unasigned icon.
 * @param timerCapIcon		Background icon shown while being captured/planted.
 * @param bombedIcon		Bombed Icon.
 * @noreturn
 */
native SetCPIcons(cpindex, iconAllies, iconAxis, iconUnsigned, timerCapIcon, bombedIcon);

/**
 * @brief Sets the amount of control points to show on HUD.
 *
 * @param amount			Number of control points.
 * @noreturn
 */
native SetNumControlPoints(amount);

/**
 * @brief Shows or hides a control point on HUD.
 *
 * @param cpindex			Control point index.
 * @param visible			True to show the control point on HUD, false otherwise.
 * @noreturn
 */
native SetCPVisible(cpindex, bool:visible);

/**
 * @brief Pauses the round timer specified.
 *
 * @param roundtimer		Entity index.
 * @noreturn
 */
native PauseTimer(roundtimer);

/**
 * @brief Resumes the round timer specified.
 *
 * @param roundtimer		Entity index.
 * @noreturn
 */
native ResumeTimer(roundtimer);

/**
 * @brief Sets time remaining on the round timer specified.
 *
 * @param roundtimer		Entity index.
 * @param time			Time in seconds.
 * @noreturn
 */
native SetTimeRemaining(roundtimer, time);

/**
 * @brief Returns time remaining on the round timer specified.
 *
 * @param roundtimer		Entity index.
 * @return				Time remaining in seconds.
 */
native Float:GetTimeRemaining(roundtimer);

/**
 * @brief Respawns a player.
 *
 * @param client			Client index.
 * @param classcheck		Auto check if the players class is valid. (Prevents possible craches)
 * @noreturn
 */
native RespawnPlayer(client, bool:classcheck = true);

/**
 * @brief Makes the specified team to win the round.
 *
 * @param index			Team index.
 * @noreturn
 */
native SetWinningTeam(index);

/**
 * @brief Adds wave time to the team specified.
 *
 * @param index			Team index.
 * @param delay			Wave time delay.
 * @noreturn
 */
native AddWaveTime(index, Float:delay);

/**
 * @brief Sets the current round state.
 *
 * @param State			Round state.
 * @noreturn
 */
native SetRoundState(roundstate);

/**
 * @brief Sets the player state on a specific client.
 *
 * @param client			Client index.
 * @param roundstate			Player state.
 * @noreturn
 */
native SetPlayerState(client, playerstate);

/**
 * @brief Sets the bomb target state on a bomb target.
 *
 * @param bombtarget		Entity index.
 * @param playerstate		Bomb target state.
 * @noreturn
 */
native SetBombTargetState(bombtarget, bombtargetstate);

/**
 * @brief Called when a players helmet is about to drop.
 *
 * @param client			Client index.
 * @return				Plugin_Handled to block, Plugin_Continue otherwise.
 */
forward Action:OnPopHelmet(client);

/**
 * @brief Called when a player respawn is being called.
 *
 * @param client			Client index.
 * @return				Plugin_Handled to block, Plugin_Continue otherwise.
 */
forward Action:OnPlayerRespawn(client);

/**
 * @brief Called when wave time is being added.
 *
 * @param index			Team index.
 * @param delay			Wave time.
 * @return				Plugin_Handled to block, Plugin_Continue otherwise.
 */
forward Action:OnAddWaveTime(index, Float:delay);

/**
 * @brief Called when a team is about to win.
 *
 * @param index			Team index.
 * @return				Plugin_Handled to block, Plugin_Continue otherwise.
 */
forward Action:OnSetWinningTeam(index);

/**
 * @brief Called when round state is being entered.
 *
 * @param roundstate		Round state.
 * @return				Plugin_Handled to block, Plugin_Continue otherwise.
 */
forward Action:OnEnterRoundState(roundstate);

/**
 * @brief Called when a player state is being entered.
 *
 * @param client			Client index.
 * @param playerstate		Player state.
 * @return				Plugin_Handled to block, Plugin_Continue otherwise.
 */
forward Action:OnEnterPlayerState(client, playerstate);

/**
 * @brief Called when a bomb target state is being entered.
 *
 * @param bombtarget		Entity index.
 * @param bombtargetstate	Bomb target state.
 * @return				Plugin_Handled to block, Plugin_Continue otherwise.
 */
forward Action:OnEnterBombTargetState(bombtarget, bombtargetstate);

public Extension:__ext_dodhooks =
{
	name = "DoD Hooks",
	file = "dodhooks.ext",
#if defined AUTOLOAD_EXTENSIONS
	autoload = 1,
#else
	autoload = 0,
#endif
#if defined REQUIRE_EXTENSIONS
	required = 1,
#else
	required = 0,
#endif
};
