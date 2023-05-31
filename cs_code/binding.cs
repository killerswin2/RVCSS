using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;
using System.Numerics;

namespace RV
{
	public class GameObject
	{
		[DllImport("rvcss_x64")]
		private static extern IntPtr CreateGameObject(string type, Vector3 position);

		[DllImport("rvcss_x64")]
		private static extern void DeleteGameObject(IntPtr gameObject);

		[DllImport("rvcss_x64")]
		private static extern Vector3 GetPos(IntPtr gameObject);

		[DllImport("rvcss_x64")]
		private static extern Vector3 GetPosASL(IntPtr gameObject);

		[DllImport("rvcss_x64")]
		private static extern Vector3 GetPosASLW(IntPtr gameObject);

		[DllImport("rvcss_x64")]
		private static extern Vector3 GetPosALT(IntPtr gameObject);

		[DllImport("rvcss_x64")]
		private static extern Vector3 GetPosWorld(IntPtr gameObject);

		[DllImport("rvcss_x64")]
		private static extern Vector3 GetRelPos(IntPtr gameObject, float distance, float direction);

		[DllImport("rvcss_x64")]
		private static extern Vector3 ModelToWorld(IntPtr gameObject, Vector3 position);

		[DllImport("rvcss_x64")]
		private static extern Vector3 ModelToWorldWorld(IntPtr gameObject, Vector3 position);

		[DllImport("rvcss_x64")]
		private static extern void SetPos(IntPtr gameObject, Vector3 position);

		[DllImport("rvcss_x64")]
		private static extern void SetPosASL(IntPtr gameObject, Vector3 position);

		[DllImport("rvcss_x64")]
		private static extern void SetPosASLW(IntPtr gameObject, Vector3 position);

		[DllImport("rvcss_x64")]
		private static extern void SetPosALT(IntPtr gameObject, Vector3 position);

		[DllImport("rvcss_x64")]
		private static extern void SetPosWorld(IntPtr gameObject, Vector3 position);

		[DllImport("rvcss_x64")]
		private static extern void WorldToModel(IntPtr gameObject, Vector3 position);

		[DllImport("rvcss_x64")]
		private static extern void WorldToModelVisual(IntPtr gameObject, Vector3 position);

		[DllImport("rvcss_x64")]
		private static extern bool IsKindOf(IntPtr gameObject, string typeName);

		[DllImport("rvcss_x64")]
		private static extern float CurrentZeroing(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsAutoHoverOn(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetObjectScale(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr TriggerText(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetFatigue(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void FillWeaponsFromPool(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsObjectRTD(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr RoleDescription(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetAmmoCargo(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr FlagOwner(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float Speed(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool ReloadEnabled(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float Rating(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void HideObject(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr PrimaryWeapon(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float CuratorCameraAreaCeiling(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveVest(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool MoveToFailed(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float RankId(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveAllItemsWithMagazines(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetPlayerVoNVolume(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveBackpackGlobal(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Face(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr GetAttackTarget(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr AssignedTeam(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool TriggerActivated(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void UnassignVehicle(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float MoveTime(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetCustomSoundControllerCount(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr AnimationState(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsTurnedOut(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveAllSecondaryWeaponItems(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr CamTarget(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsSimpleObject(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float ScudState(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsAutoTrimOnRTD(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RopeDestroy(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsTouchingGround(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Vest(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Headgear(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float Fuel(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetForcedSpeed(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float Damage(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetBleedingRemaining(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Leader(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetCustomAimCoef(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float UnitRecoilCoefficient(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void UnassignCurator(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr ObjectParent(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void ClearMagazineCargo(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool CanMove(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetWingsOrientationRTD(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsStaminaEnabled(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr UnitBackpack(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void PickWeaponPool(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr GetSlingLoad(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void Reload(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Speaker(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool UnitIsUAV(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr AssignedTarget(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr AttachedTo(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr EffectiveCommander(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr LandResult(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void ClearWeaponCargoGlobal(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr AssignedDriver(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float FlagAnimationPhase(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr GetTowParent(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetDir(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr UniformContainer(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsPlayer(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool CamPreloaded(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool Local(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool Fleeing(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsCopilotEnabled(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float MaxLoad(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Uniform(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr WFSideText(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr FlagTexture(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetFuelCargo(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GroupID(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float CaptiveNum(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool CanUnloadInCombat(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr NetId(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveAllAssignedItems(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool RopeUnwound(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void AddSwitchableUnit(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float Owner(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Driver(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float LoadUniform(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsLaserOn(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool SomeAmmo(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsWeaponRested(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsAimPrecisionEnabled(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Commander(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr IncapacitatedState(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float CollectiveRTD(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float InsideBuilding(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetAnimAimPrecision(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool CanTriggerDynamicSimulation(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool WeaponLowered(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float HandsHit(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveAllCuratorCameraAreas(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr TriggerType(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void HideBody(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void TriggerAmmo(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr MissileTarget(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Behaviour(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr LifeState(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsSprintAllowed(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float TriggerInterval(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveAllContainers(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetObjectType(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr RopeAttachedTo(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool MoveToCompleted(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool CanStand(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr FormationLeader(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr GetPlateNumber(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsEngineOn(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr GetForcedFlagTexture(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float Skill(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Backpack(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void HcRemoveAllGroups(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetStamina(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetMass(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float Load(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float LoadAbs(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveSwitchableUnit(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool SimulationEnabled(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool VehicleReceiveRemoteTargets(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr CurrentMuzzle(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr CurrentWeaponMode(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetWingsPositionRTD(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Name(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool Captive(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsWeaponDeployed(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveAllWeapons(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr VehicleVarName(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float TriggerTimeoutCurrent(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr AssignedGunner(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr GetCorpse(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveUniform(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Faction(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveAllPrimaryWeaponItems(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool GetDiverState(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool CamCommitted(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsInRemainsCollector(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void SetPlayable(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveAllBinocularItems(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsAutonomous(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr HandgunMagazine(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetOxygenRemaining(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Vehicle(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveAllActions(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void StopEngineRTD(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Gunner(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr IsVehicleCargo(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void LightDetachObject(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr GetConnectedUAVUnit(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsAllowedCrewInImmobile(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr GetObjectID(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetRepairCargo(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Pitch(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsVehicleRadarOn(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float CameraInterest(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveHeadgear(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool LockedInventory(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr UnitCombatMode(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsFormationLeader(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float NumberOfEnginesRTD(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsHidden(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void ClearWeaponCargo(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float Precision(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr BackpackContainer(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void ClearBackpackCargoGlobal(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveAllHandgunItems(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool CuratorEditingAreaType(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void PutWeaponPool(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetObjectDLC(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool LockIdentity(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr TypeOf(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void DeleteVehicleCrew(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float Score(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsAwake(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr LaserTarget(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Stance(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float CuratorPoints(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool Alive(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr TriggerAttachedVehicle(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Rank(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetRotorBrakeRTD(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsBleeding(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr NameSound(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float Locked(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void ClearBackpackCargo(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float FormationDirection(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsAbleToBreathe(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr GetAssignedCuratorUnit(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool DynamicSimulationEnabled(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr CurrentCommand(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr UnitPos(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float AllowedService(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetAimingCoef(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool MineActive(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr HandgunWeapon(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool VehicleCargoEnabled(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void MoveOut(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetObjectFOV(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr AssignedVehicle(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Goggles(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveAllCuratorAddons(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsBurning(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr GetPlayerUID(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float AirplaneThrottle(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Binocular(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetWeaponSway(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveAllCuratorEditingAreas(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr SecondaryWeapon(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void DeleteCollection(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool CanDeployWeapon(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void CamDestroy(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float CuratorWaypointCost(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsMarkedForCollection(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr GetAssignedCuratorLogic(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void ResetSubgroupDirection(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void SwitchCamera(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr CurrentPilot(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool WaypointsEnabledUAV(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void Detach(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float NeedReload(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool BrakesDisabled(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsNull(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveBackpack(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void HideObjectGlobal(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr GestureState(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool RopeAttachEnabled(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr FirstBackpack(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetBurningValue(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float LoadBackpack(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void UnassignTeam(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveAllOwnedMines(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float RopeLength(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetAnimSpeedCoef(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr VestContainer(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool ConversationDisabled(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool Inflamed(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsDamageAllowed(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsForcedWalk(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float CurrentVisionMode(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool HasPilotCamera(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float Direction(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetSuppression(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr AssignedCommander(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void DeleteSite(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr NearestBuilding(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void ClearItemCargoGlobal(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveGoggles(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetPlayerChannel(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void ClearItemCargo(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsWalking(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Flag(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr FormLeader(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool Stopped(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void ClearAllItemsFromBackpack(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Hmd(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool CanFire(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr BinocularMagazine(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsObjectHidden(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool Underwater(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float Morale(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void SelectPlayer(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr CombatBehaviour(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsCollisionLightOn(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr FormationTask(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsManualFire(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void DeleteVehicle(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool IsUAVConnected(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr CurrentWeapon(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetDirVisual(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void ClearMagazineCargoGlobal(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float GetDammage(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern float LoadVest(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr Pose(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void RemoveAllItems(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool VehicleReportOwnPosition(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr GetPlayerID(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool DidJIPOwner(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr LightIsOn(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr CurrentMagazine(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool VehicleReportRemoteTargets(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern void ForceRespawn(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern IntPtr GetConnectedUAV(IntPtr gameObject);
		[DllImport("rvcss_x64")]
		private static extern bool LockedDriver(IntPtr gameObject);



		private readonly IntPtr _internalGameObject;
		public GameObject(string type, Vector3 position)
		{
			_internalGameObject = CreateGameObject(type, position);
		}
		private GameObject(IntPtr gamePointer)
		{
			_internalGameObject = gamePointer;
		}

		~GameObject()
		{
			DeleteGameObject(_internalGameObject);
		}

		public Vector3 GetPos()
		{
			return GetPos(_internalGameObject);
		}

		public Vector3 GetPosASL()
		{
			return GetPosASL(_internalGameObject);
		}

		public Vector3 GetPosASLW()
		{
			return GetPosASLW(_internalGameObject);
		}

		public Vector3 GetPosALT()
		{
			return GetPosALT(_internalGameObject);
		}

		public Vector3 GetPosWorld()
		{
			return GetPosWorld(_internalGameObject);
		}

		public Vector3 GetRelPos(float distance, float direction)
		{
			return GetRelPos(_internalGameObject, distance, direction);
		}

		public Vector3 ModelToWorld(Vector3 position)
		{
			return ModelToWorld(_internalGameObject, position);
		}

		public Vector3 ModelToWorldWorld(Vector3 position)
		{
			return ModelToWorldWorld(_internalGameObject, position);
		}

		public void SetPos(Vector3 position)
		{
			SetPos(_internalGameObject, position);
		}

		public void SetPosASL(Vector3 position)
		{
			SetPosASL(_internalGameObject, position);
		}

		public void SetPosASLW(Vector3 position)
		{
			SetPosASLW(_internalGameObject, position);
		}

		public void SetPosALT(Vector3 position)
		{
			SetPosALT(_internalGameObject, position);
		}

		public void SetPosWorld(Vector3 position)
		{
			SetPosWorld(_internalGameObject, position);
		}

		public void WorldToModel(Vector3 position)
		{
			WorldToModel(_internalGameObject, position);
		}

		public void WorldToModelVisual(Vector3 position)
		{
			WorldToModelVisual(_internalGameObject, position);
		}


		public bool IsKindOf(string typeName)
		{
			return IsKindOf(_internalGameObject, typeName);
		}

		public float CurrentZeroing()
		{
			return CurrentZeroing(_internalGameObject);
		}

		public bool IsAutoHoverOn()
		{
			return IsAutoHoverOn(_internalGameObject);
		}

		public float GetObjectScale()
		{
			return GetObjectScale(_internalGameObject);
		}

		public string TriggerText()
		{
			var pointer = TriggerText(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float GetFatigue()
		{
			return GetFatigue(_internalGameObject);
		}

		public void FillWeaponsFromPool()
		{
			FillWeaponsFromPool(_internalGameObject);
		}

		public bool IsObjectRTD()
		{
			return IsObjectRTD(_internalGameObject);
		}

		public string RoleDescription()
		{
			var pointer = RoleDescription(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float GetAmmoCargo()
		{
			return GetAmmoCargo(_internalGameObject);
		}

		public GameObject FlagOwner()
		{
			return new GameObject(FlagOwner(_internalGameObject));
		}

		public float Speed()
		{
			return Speed(_internalGameObject);
		}

		public bool ReloadEnabled()
		{
			return ReloadEnabled(_internalGameObject);
		}

		public float Rating()
		{
			return Rating(_internalGameObject);
		}

		public void HideObject()
		{
			HideObject(_internalGameObject);
		}

		public string PrimaryWeapon()
		{
			var pointer = PrimaryWeapon(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float CuratorCameraAreaCeiling()
		{
			return CuratorCameraAreaCeiling(_internalGameObject);
		}

		public void RemoveVest()
		{
			RemoveVest(_internalGameObject);
		}

		public bool MoveToFailed()
		{
			return MoveToFailed(_internalGameObject);
		}

		public float RankId()
		{
			return RankId(_internalGameObject);
		}

		public void RemoveAllItemsWithMagazines()
		{
			RemoveAllItemsWithMagazines(_internalGameObject);
		}

		public float GetPlayerVoNVolume()
		{
			return GetPlayerVoNVolume(_internalGameObject);
		}

		public void RemoveBackpackGlobal()
		{
			RemoveBackpackGlobal(_internalGameObject);
		}

		public string Face()
		{
			var pointer = Face(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public GameObject GetAttackTarget()
		{
			return new GameObject(GetAttackTarget(_internalGameObject));
		}

		public string AssignedTeam()
		{
			var pointer = AssignedTeam(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool TriggerActivated()
		{
			return TriggerActivated(_internalGameObject);
		}

		public void UnassignVehicle()
		{
			UnassignVehicle(_internalGameObject);
		}

		public float MoveTime()
		{
			return MoveTime(_internalGameObject);
		}

		public float GetCustomSoundControllerCount()
		{
			return GetCustomSoundControllerCount(_internalGameObject);
		}

		public string AnimationState()
		{
			var pointer = AnimationState(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool IsTurnedOut()
		{
			return IsTurnedOut(_internalGameObject);
		}

		public void RemoveAllSecondaryWeaponItems()
		{
			RemoveAllSecondaryWeaponItems(_internalGameObject);
		}

		public GameObject CamTarget()
		{
			return new GameObject(CamTarget(_internalGameObject));
		}

		public bool IsSimpleObject()
		{
			return IsSimpleObject(_internalGameObject);
		}

		public float ScudState()
		{
			return ScudState(_internalGameObject);
		}

		public bool IsAutoTrimOnRTD()
		{
			return IsAutoTrimOnRTD(_internalGameObject);
		}

		public void RopeDestroy()
		{
			RopeDestroy(_internalGameObject);
		}

		public bool IsTouchingGround()
		{
			return IsTouchingGround(_internalGameObject);
		}

		public string Vest()
		{
			var pointer = Vest(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public string Headgear()
		{
			var pointer = Headgear(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float Fuel()
		{
			return Fuel(_internalGameObject);
		}

		public float GetForcedSpeed()
		{
			return GetForcedSpeed(_internalGameObject);
		}

		public float Damage()
		{
			return Damage(_internalGameObject);
		}

		public float GetBleedingRemaining()
		{
			return GetBleedingRemaining(_internalGameObject);
		}

		public GameObject Leader()
		{
			return new GameObject(Leader(_internalGameObject));
		}

		public float GetCustomAimCoef()
		{
			return GetCustomAimCoef(_internalGameObject);
		}

		public float UnitRecoilCoefficient()
		{
			return UnitRecoilCoefficient(_internalGameObject);
		}

		public void UnassignCurator()
		{
			UnassignCurator(_internalGameObject);
		}

		public GameObject ObjectParent()
		{
			return new GameObject(ObjectParent(_internalGameObject));
		}

		public void ClearMagazineCargo()
		{
			ClearMagazineCargo(_internalGameObject);
		}

		public bool CanMove()
		{
			return CanMove(_internalGameObject);
		}

		public float GetWingsOrientationRTD()
		{
			return GetWingsOrientationRTD(_internalGameObject);
		}

		public bool IsStaminaEnabled()
		{
			return IsStaminaEnabled(_internalGameObject);
		}

		public GameObject UnitBackpack()
		{
			return new GameObject(UnitBackpack(_internalGameObject));
		}

		public void PickWeaponPool()
		{
			PickWeaponPool(_internalGameObject);
		}

		public GameObject GetSlingLoad()
		{
			return new GameObject(GetSlingLoad(_internalGameObject));
		}

		public void Reload()
		{
			Reload(_internalGameObject);
		}

		public string Speaker()
		{
			var pointer = Speaker(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool UnitIsUAV()
		{
			return UnitIsUAV(_internalGameObject);
		}

		public GameObject AssignedTarget()
		{
			return new GameObject(AssignedTarget(_internalGameObject));
		}

		public GameObject AttachedTo()
		{
			return new GameObject(AttachedTo(_internalGameObject));
		}

		public GameObject EffectiveCommander()
		{
			return new GameObject(EffectiveCommander(_internalGameObject));
		}

		public string LandResult()
		{
			var pointer = LandResult(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public void ClearWeaponCargoGlobal()
		{
			ClearWeaponCargoGlobal(_internalGameObject);
		}

		public GameObject AssignedDriver()
		{
			return new GameObject(AssignedDriver(_internalGameObject));
		}

		public float FlagAnimationPhase()
		{
			return FlagAnimationPhase(_internalGameObject);
		}

		public GameObject GetTowParent()
		{
			return new GameObject(GetTowParent(_internalGameObject));
		}

		public float GetDir()
		{
			return GetDir(_internalGameObject);
		}

		public GameObject UniformContainer()
		{
			return new GameObject(UniformContainer(_internalGameObject));
		}

		public bool IsPlayer()
		{
			return IsPlayer(_internalGameObject);
		}

		public bool CamPreloaded()
		{
			return CamPreloaded(_internalGameObject);
		}

		public bool Local()
		{
			return Local(_internalGameObject);
		}

		public bool Fleeing()
		{
			return Fleeing(_internalGameObject);
		}

		public bool IsCopilotEnabled()
		{
			return IsCopilotEnabled(_internalGameObject);
		}

		public float MaxLoad()
		{
			return MaxLoad(_internalGameObject);
		}

		public string Uniform()
		{
			var pointer = Uniform(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public string WFSideText()
		{
			var pointer = WFSideText(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public string FlagTexture()
		{
			var pointer = FlagTexture(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float GetFuelCargo()
		{
			return GetFuelCargo(_internalGameObject);
		}

		public float GroupID()
		{
			return GroupID(_internalGameObject);
		}

		public float CaptiveNum()
		{
			return CaptiveNum(_internalGameObject);
		}

		public bool CanUnloadInCombat()
		{
			return CanUnloadInCombat(_internalGameObject);
		}

		public string NetId()
		{
			var pointer = NetId(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public void RemoveAllAssignedItems()
		{
			RemoveAllAssignedItems(_internalGameObject);
		}

		public bool RopeUnwound()
		{
			return RopeUnwound(_internalGameObject);
		}

		public void AddSwitchableUnit()
		{
			AddSwitchableUnit(_internalGameObject);
		}

		public float Owner()
		{
			return Owner(_internalGameObject);
		}

		public GameObject Driver()
		{
			return new GameObject(Driver(_internalGameObject));
		}

		public float LoadUniform()
		{
			return LoadUniform(_internalGameObject);
		}

		public bool IsLaserOn()
		{
			return IsLaserOn(_internalGameObject);
		}

		public bool SomeAmmo()
		{
			return SomeAmmo(_internalGameObject);
		}

		public bool IsWeaponRested()
		{
			return IsWeaponRested(_internalGameObject);
		}

		public bool IsAimPrecisionEnabled()
		{
			return IsAimPrecisionEnabled(_internalGameObject);
		}

		public GameObject Commander()
		{
			return new GameObject(Commander(_internalGameObject));
		}

		public string IncapacitatedState()
		{
			var pointer = IncapacitatedState(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float CollectiveRTD()
		{
			return CollectiveRTD(_internalGameObject);
		}

		public float InsideBuilding()
		{
			return InsideBuilding(_internalGameObject);
		}

		public float GetAnimAimPrecision()
		{
			return GetAnimAimPrecision(_internalGameObject);
		}

		public bool CanTriggerDynamicSimulation()
		{
			return CanTriggerDynamicSimulation(_internalGameObject);
		}

		public bool WeaponLowered()
		{
			return WeaponLowered(_internalGameObject);
		}

		public float HandsHit()
		{
			return HandsHit(_internalGameObject);
		}

		public void RemoveAllCuratorCameraAreas()
		{
			RemoveAllCuratorCameraAreas(_internalGameObject);
		}

		public string TriggerType()
		{
			var pointer = TriggerType(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public void HideBody()
		{
			HideBody(_internalGameObject);
		}

		public void TriggerAmmo()
		{
			TriggerAmmo(_internalGameObject);
		}

		public GameObject MissileTarget()
		{
			return new GameObject(MissileTarget(_internalGameObject));
		}

		public string Behaviour()
		{
			var pointer = Behaviour(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public string LifeState()
		{
			var pointer = LifeState(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool IsSprintAllowed()
		{
			return IsSprintAllowed(_internalGameObject);
		}

		public float TriggerInterval()
		{
			return TriggerInterval(_internalGameObject);
		}

		public void RemoveAllContainers()
		{
			RemoveAllContainers(_internalGameObject);
		}

		public float GetObjectType()
		{
			return GetObjectType(_internalGameObject);
		}

		public GameObject RopeAttachedTo()
		{
			return new GameObject(RopeAttachedTo(_internalGameObject));
		}

		public bool MoveToCompleted()
		{
			return MoveToCompleted(_internalGameObject);
		}

		public bool CanStand()
		{
			return CanStand(_internalGameObject);
		}

		public GameObject FormationLeader()
		{
			return new GameObject(FormationLeader(_internalGameObject));
		}

		public string GetPlateNumber()
		{
			var pointer = GetPlateNumber(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool IsEngineOn()
		{
			return IsEngineOn(_internalGameObject);
		}

		public string GetForcedFlagTexture()
		{
			var pointer = GetForcedFlagTexture(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float Skill()
		{
			return Skill(_internalGameObject);
		}

		public string Backpack()
		{
			var pointer = Backpack(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public void HcRemoveAllGroups()
		{
			HcRemoveAllGroups(_internalGameObject);
		}

		public float GetStamina()
		{
			return GetStamina(_internalGameObject);
		}

		public float GetMass()
		{
			return GetMass(_internalGameObject);
		}

		public float Load()
		{
			return Load(_internalGameObject);
		}

		public float LoadAbs()
		{
			return LoadAbs(_internalGameObject);
		}

		public void RemoveSwitchableUnit()
		{
			RemoveSwitchableUnit(_internalGameObject);
		}

		public bool SimulationEnabled()
		{
			return SimulationEnabled(_internalGameObject);
		}

		public bool VehicleReceiveRemoteTargets()
		{
			return VehicleReceiveRemoteTargets(_internalGameObject);
		}

		public string CurrentMuzzle()
		{
			var pointer = CurrentMuzzle(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public string CurrentWeaponMode()
		{
			var pointer = CurrentWeaponMode(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float GetWingsPositionRTD()
		{
			return GetWingsPositionRTD(_internalGameObject);
		}

		public string Name()
		{
			var pointer = Name(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool Captive()
		{
			return Captive(_internalGameObject);
		}

		public bool IsWeaponDeployed()
		{
			return IsWeaponDeployed(_internalGameObject);
		}

		public void RemoveAllWeapons()
		{
			RemoveAllWeapons(_internalGameObject);
		}

		public string VehicleVarName()
		{
			var pointer = VehicleVarName(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float TriggerTimeoutCurrent()
		{
			return TriggerTimeoutCurrent(_internalGameObject);
		}

		public GameObject AssignedGunner()
		{
			return new GameObject(AssignedGunner(_internalGameObject));
		}

		public GameObject GetCorpse()
		{
			return new GameObject(GetCorpse(_internalGameObject));
		}

		public void RemoveUniform()
		{
			RemoveUniform(_internalGameObject);
		}

		public string Faction()
		{
			var pointer = Faction(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public void RemoveAllPrimaryWeaponItems()
		{
			RemoveAllPrimaryWeaponItems(_internalGameObject);
		}

		public bool GetDiverState()
		{
			return GetDiverState(_internalGameObject);
		}

		public bool CamCommitted()
		{
			return CamCommitted(_internalGameObject);
		}

		public bool IsInRemainsCollector()
		{
			return IsInRemainsCollector(_internalGameObject);
		}

		public void SetPlayable()
		{
			SetPlayable(_internalGameObject);
		}

		public void RemoveAllBinocularItems()
		{
			RemoveAllBinocularItems(_internalGameObject);
		}

		public bool IsAutonomous()
		{
			return IsAutonomous(_internalGameObject);
		}

		public string HandgunMagazine()
		{
			var pointer = HandgunMagazine(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float GetOxygenRemaining()
		{
			return GetOxygenRemaining(_internalGameObject);
		}

		public GameObject Vehicle()
		{
			return new GameObject(Vehicle(_internalGameObject));
		}

		public void RemoveAllActions()
		{
			RemoveAllActions(_internalGameObject);
		}

		public void StopEngineRTD()
		{
			StopEngineRTD(_internalGameObject);
		}

		public GameObject Gunner()
		{
			return new GameObject(Gunner(_internalGameObject));
		}

		public GameObject IsVehicleCargo()
		{
			return new GameObject(IsVehicleCargo(_internalGameObject));
		}

		public void LightDetachObject()
		{
			LightDetachObject(_internalGameObject);
		}

		public GameObject GetConnectedUAVUnit()
		{
			return new GameObject(GetConnectedUAVUnit(_internalGameObject));
		}

		public bool IsAllowedCrewInImmobile()
		{
			return IsAllowedCrewInImmobile(_internalGameObject);
		}

		public string GetObjectID()
		{
			var pointer = GetObjectID(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float GetRepairCargo()
		{
			return GetRepairCargo(_internalGameObject);
		}

		public string Pitch()
		{
			var pointer = Pitch(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool IsVehicleRadarOn()
		{
			return IsVehicleRadarOn(_internalGameObject);
		}

		public float CameraInterest()
		{
			return CameraInterest(_internalGameObject);
		}

		public void RemoveHeadgear()
		{
			RemoveHeadgear(_internalGameObject);
		}

		public bool LockedInventory()
		{
			return LockedInventory(_internalGameObject);
		}

		public string UnitCombatMode()
		{
			var pointer = UnitCombatMode(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool IsFormationLeader()
		{
			return IsFormationLeader(_internalGameObject);
		}

		public float NumberOfEnginesRTD()
		{
			return NumberOfEnginesRTD(_internalGameObject);
		}

		public bool IsHidden()
		{
			return IsHidden(_internalGameObject);
		}

		public void ClearWeaponCargo()
		{
			ClearWeaponCargo(_internalGameObject);
		}

		public float Precision()
		{
			return Precision(_internalGameObject);
		}

		public GameObject BackpackContainer()
		{
			return new GameObject(BackpackContainer(_internalGameObject));
		}

		public void ClearBackpackCargoGlobal()
		{
			ClearBackpackCargoGlobal(_internalGameObject);
		}

		public void RemoveAllHandgunItems()
		{
			RemoveAllHandgunItems(_internalGameObject);
		}

		public bool CuratorEditingAreaType()
		{
			return CuratorEditingAreaType(_internalGameObject);
		}

		public void PutWeaponPool()
		{
			PutWeaponPool(_internalGameObject);
		}

		public float GetObjectDLC()
		{
			return GetObjectDLC(_internalGameObject);
		}

		public bool LockIdentity()
		{
			return LockIdentity(_internalGameObject);
		}

		public string TypeOf()
		{
			var pointer = TypeOf(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public void DeleteVehicleCrew()
		{
			DeleteVehicleCrew(_internalGameObject);
		}

		public float Score()
		{
			return Score(_internalGameObject);
		}

		public bool IsAwake()
		{
			return IsAwake(_internalGameObject);
		}

		public GameObject LaserTarget()
		{
			return new GameObject(LaserTarget(_internalGameObject));
		}

		public string Stance()
		{
			var pointer = Stance(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float CuratorPoints()
		{
			return CuratorPoints(_internalGameObject);
		}

		public bool Alive()
		{
			return Alive(_internalGameObject);
		}

		public GameObject TriggerAttachedVehicle()
		{
			return new GameObject(TriggerAttachedVehicle(_internalGameObject));
		}

		public string Rank()
		{
			var pointer = Rank(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float GetRotorBrakeRTD()
		{
			return GetRotorBrakeRTD(_internalGameObject);
		}

		public bool IsBleeding()
		{
			return IsBleeding(_internalGameObject);
		}

		public string NameSound()
		{
			var pointer = NameSound(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float Locked()
		{
			return Locked(_internalGameObject);
		}

		public void ClearBackpackCargo()
		{
			ClearBackpackCargo(_internalGameObject);
		}

		public float FormationDirection()
		{
			return FormationDirection(_internalGameObject);
		}

		public bool IsAbleToBreathe()
		{
			return IsAbleToBreathe(_internalGameObject);
		}

		public GameObject GetAssignedCuratorUnit()
		{
			return new GameObject(GetAssignedCuratorUnit(_internalGameObject));
		}

		public bool DynamicSimulationEnabled()
		{
			return DynamicSimulationEnabled(_internalGameObject);
		}

		public string CurrentCommand()
		{
			var pointer = CurrentCommand(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public string UnitPos()
		{
			var pointer = UnitPos(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float AllowedService()
		{
			return AllowedService(_internalGameObject);
		}

		public float GetAimingCoef()
		{
			return GetAimingCoef(_internalGameObject);
		}

		public bool MineActive()
		{
			return MineActive(_internalGameObject);
		}

		public string HandgunWeapon()
		{
			var pointer = HandgunWeapon(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool VehicleCargoEnabled()
		{
			return VehicleCargoEnabled(_internalGameObject);
		}

		public void MoveOut()
		{
			MoveOut(_internalGameObject);
		}

		public float GetObjectFOV()
		{
			return GetObjectFOV(_internalGameObject);
		}

		public GameObject AssignedVehicle()
		{
			return new GameObject(AssignedVehicle(_internalGameObject));
		}

		public string Goggles()
		{
			var pointer = Goggles(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public void RemoveAllCuratorAddons()
		{
			RemoveAllCuratorAddons(_internalGameObject);
		}

		public bool IsBurning()
		{
			return IsBurning(_internalGameObject);
		}

		public string GetPlayerUID()
		{
			var pointer = GetPlayerUID(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float AirplaneThrottle()
		{
			return AirplaneThrottle(_internalGameObject);
		}

		public string Binocular()
		{
			var pointer = Binocular(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float GetWeaponSway()
		{
			return GetWeaponSway(_internalGameObject);
		}

		public void RemoveAllCuratorEditingAreas()
		{
			RemoveAllCuratorEditingAreas(_internalGameObject);
		}

		public string SecondaryWeapon()
		{
			var pointer = SecondaryWeapon(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public void DeleteCollection()
		{
			DeleteCollection(_internalGameObject);
		}

		public bool CanDeployWeapon()
		{
			return CanDeployWeapon(_internalGameObject);
		}

		public void CamDestroy()
		{
			CamDestroy(_internalGameObject);
		}

		public float CuratorWaypointCost()
		{
			return CuratorWaypointCost(_internalGameObject);
		}

		public bool IsMarkedForCollection()
		{
			return IsMarkedForCollection(_internalGameObject);
		}

		public GameObject GetAssignedCuratorLogic()
		{
			return new GameObject(GetAssignedCuratorLogic(_internalGameObject));
		}

		public void ResetSubgroupDirection()
		{
			ResetSubgroupDirection(_internalGameObject);
		}

		public void SwitchCamera()
		{
			SwitchCamera(_internalGameObject);
		}

		public GameObject CurrentPilot()
		{
			return new GameObject(CurrentPilot(_internalGameObject));
		}

		public bool WaypointsEnabledUAV()
		{
			return WaypointsEnabledUAV(_internalGameObject);
		}

		public void Detach()
		{
			Detach(_internalGameObject);
		}

		public float NeedReload()
		{
			return NeedReload(_internalGameObject);
		}

		public bool BrakesDisabled()
		{
			return BrakesDisabled(_internalGameObject);
		}

		public bool IsNull()
		{
			return IsNull(_internalGameObject);
		}

		public void RemoveBackpack()
		{
			RemoveBackpack(_internalGameObject);
		}

		public void HideObjectGlobal()
		{
			HideObjectGlobal(_internalGameObject);
		}

		public string GestureState()
		{
			var pointer = GestureState(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool RopeAttachEnabled()
		{
			return RopeAttachEnabled(_internalGameObject);
		}

		public GameObject FirstBackpack()
		{
			return new GameObject(FirstBackpack(_internalGameObject));
		}

		public float GetBurningValue()
		{
			return GetBurningValue(_internalGameObject);
		}

		public float LoadBackpack()
		{
			return LoadBackpack(_internalGameObject);
		}

		public void UnassignTeam()
		{
			UnassignTeam(_internalGameObject);
		}

		public void RemoveAllOwnedMines()
		{
			RemoveAllOwnedMines(_internalGameObject);
		}

		public float RopeLength()
		{
			return RopeLength(_internalGameObject);
		}

		public float GetAnimSpeedCoef()
		{
			return GetAnimSpeedCoef(_internalGameObject);
		}

		public GameObject VestContainer()
		{
			return new GameObject(VestContainer(_internalGameObject));
		}

		public bool ConversationDisabled()
		{
			return ConversationDisabled(_internalGameObject);
		}

		public bool Inflamed()
		{
			return Inflamed(_internalGameObject);
		}

		public bool IsDamageAllowed()
		{
			return IsDamageAllowed(_internalGameObject);
		}

		public bool IsForcedWalk()
		{
			return IsForcedWalk(_internalGameObject);
		}

		public float CurrentVisionMode()
		{
			return CurrentVisionMode(_internalGameObject);
		}

		public bool HasPilotCamera()
		{
			return HasPilotCamera(_internalGameObject);
		}

		public float Direction()
		{
			return Direction(_internalGameObject);
		}

		public float GetSuppression()
		{
			return GetSuppression(_internalGameObject);
		}

		public GameObject AssignedCommander()
		{
			return new GameObject(AssignedCommander(_internalGameObject));
		}

		public void DeleteSite()
		{
			DeleteSite(_internalGameObject);
		}

		public GameObject NearestBuilding()
		{
			return new GameObject(NearestBuilding(_internalGameObject));
		}

		public void ClearItemCargoGlobal()
		{
			ClearItemCargoGlobal(_internalGameObject);
		}

		public void RemoveGoggles()
		{
			RemoveGoggles(_internalGameObject);
		}

		public float GetPlayerChannel()
		{
			return GetPlayerChannel(_internalGameObject);
		}

		public void ClearItemCargo()
		{
			ClearItemCargo(_internalGameObject);
		}

		public bool IsWalking()
		{
			return IsWalking(_internalGameObject);
		}

		public GameObject Flag()
		{
			return new GameObject(Flag(_internalGameObject));
		}

		public GameObject FormLeader()
		{
			return new GameObject(FormLeader(_internalGameObject));
		}

		public bool Stopped()
		{
			return Stopped(_internalGameObject);
		}

		public void ClearAllItemsFromBackpack()
		{
			ClearAllItemsFromBackpack(_internalGameObject);
		}

		public string Hmd()
		{
			var pointer = Hmd(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool CanFire()
		{
			return CanFire(_internalGameObject);
		}

		public string BinocularMagazine()
		{
			var pointer = BinocularMagazine(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool IsObjectHidden()
		{
			return IsObjectHidden(_internalGameObject);
		}

		public bool Underwater()
		{
			return Underwater(_internalGameObject);
		}

		public float Morale()
		{
			return Morale(_internalGameObject);
		}

		public void SelectPlayer()
		{
			SelectPlayer(_internalGameObject);
		}

		public string CombatBehaviour()
		{
			var pointer = CombatBehaviour(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool IsCollisionLightOn()
		{
			return IsCollisionLightOn(_internalGameObject);
		}

		public string FormationTask()
		{
			var pointer = FormationTask(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool IsManualFire()
		{
			return IsManualFire(_internalGameObject);
		}

		public void DeleteVehicle()
		{
			DeleteVehicle(_internalGameObject);
		}

		public bool IsUAVConnected()
		{
			return IsUAVConnected(_internalGameObject);
		}

		public string CurrentWeapon()
		{
			var pointer = CurrentWeapon(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public float GetDirVisual()
		{
			return GetDirVisual(_internalGameObject);
		}

		public void ClearMagazineCargoGlobal()
		{
			ClearMagazineCargoGlobal(_internalGameObject);
		}

		public float GetDammage()
		{
			return GetDammage(_internalGameObject);
		}

		public float LoadVest()
		{
			return LoadVest(_internalGameObject);
		}

		public string Pose()
		{
			var pointer = Pose(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public void RemoveAllItems()
		{
			RemoveAllItems(_internalGameObject);
		}

		public bool VehicleReportOwnPosition()
		{
			return VehicleReportOwnPosition(_internalGameObject);
		}

		public string GetPlayerID()
		{
			var pointer = GetPlayerID(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool DidJIPOwner()
		{
			return DidJIPOwner(_internalGameObject);
		}

		public string LightIsOn()
		{
			var pointer = LightIsOn(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public string CurrentMagazine()
		{
			var pointer = CurrentMagazine(_internalGameObject);
			string message = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
			? Marshal.PtrToStringUni(pointer) : Marshal.PtrToStringUTF8(pointer);
			return message;
		}

		public bool VehicleReportRemoteTargets()
		{
			return VehicleReportRemoteTargets(_internalGameObject);
		}

		public void ForceRespawn()
		{
			ForceRespawn(_internalGameObject);
		}

		public GameObject GetConnectedUAV()
		{
			return new GameObject(GetConnectedUAV(_internalGameObject));
		}

		public bool LockedDriver()
		{
			return LockedDriver(_internalGameObject);
		}
	}
}