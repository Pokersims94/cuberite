
#include "Globals.h"  // NOTE: MSVC stupidness requires this to be the same across all modules

#include "Skeleton.h"
#include "../World.h"
#include "../Entities/ArrowEntity.h"
#include "ClientHandle.h"




cSkeleton::cSkeleton(bool IsWither) :
	super(mtSkeleton, "entity.skeleton.hurt", "entity.skeleton.death", 0.6, 1.8),
	m_bIsWither(IsWither)
{
	m_EMPersonality = AGGRESSIVE;
	m_BehaviorAttackerRanged.AttachToMonster(*this);
	m_BehaviorWanderer.AttachToMonster(*this);
	m_BehaviorAggressive.AttachToMonster(*this);
	m_BehaviourDayLightBurner.AttachToMonster(*this);
	GetMonsterConfig("Skeleton");
}





void cSkeleton::GetDrops(cItems & a_Drops, cEntity * a_Killer)
{
	unsigned int LootingLevel = 0;
	if (a_Killer != nullptr)
	{
		LootingLevel = a_Killer->GetEquippedWeapon().m_Enchantments.GetLevel(cEnchantments::enchLooting);
	}
	if (IsWither())
	{
		AddRandomUncommonDropItem(a_Drops, 33.0f, E_ITEM_COAL);
		cItems RareDrops;
		RareDrops.Add(cItem(E_ITEM_HEAD, 1, 1));
		AddRandomRareDropItem(a_Drops, RareDrops, LootingLevel);
	}
	else
	{
		AddRandomDropItem(a_Drops, 0, 2 + LootingLevel, E_ITEM_ARROW);

	}
	AddRandomDropItem(a_Drops, 0, 2 + LootingLevel, E_ITEM_BONE);
	AddRandomArmorDropItem(a_Drops, LootingLevel);
	AddRandomWeaponDropItem(a_Drops, LootingLevel);
}





void cSkeleton::SpawnOn(cClientHandle & a_ClientHandle)
{
	super::SpawnOn(a_ClientHandle);
	a_ClientHandle.SendEntityEquipment(*this, 0, cItem(E_ITEM_BOW));
}




