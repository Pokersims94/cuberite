
#pragma once

#include "Monster.h"
#include "Behaviors/BehaviorAttackerRanged.h"
#include "Behaviors/BehaviorWanderer.h"
#include "Behaviors/BehaviorAggressive.h"
#include "Behaviors/BehaviorDayLightBurner.h"


class cSkeleton :
	public cMonster
{
	typedef cMonster super;

public:
	cSkeleton(bool IsWither);

	CLASS_PROTODEF(cSkeleton)

	virtual void GetDrops(cItems & a_Drops, cEntity * a_Killer = nullptr) override;
	/*virtual bool Attack(std::chrono::milliseconds a_Dt) override;*/
	virtual void SpawnOn(cClientHandle & a_ClientHandle) override;

	virtual bool IsUndead(void) override { return true; }

	bool IsWither(void) const { return m_bIsWither; }

private:

	bool m_bIsWither;

	// tick behaviors
	cBehaviorAttackerRanged m_BehaviorAttackerRanged;
	cBehaviorWanderer m_BehaviorWanderer;

	// other behaviors
	cBehaviorAggressive m_BehaviorAggressive;
	cBehaviorDayLightBurner m_BehaviourDayLightBurner;
} ;




