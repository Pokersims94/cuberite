
#pragma once

#include "Monster.h"





class cCreeper :
	public cMonster
{
	typedef cMonster super;

public:
	cCreeper(void);

	CLASS_PROTODEF(cCreeper)

	virtual void GetDrops(cItems & a_Drops, cEntity * a_Killer = nullptr) override;
	virtual bool DoTakeDamage(TakeDamageInfo & a_TDI) override;
	virtual void OnRightClicked(cPlayer & a_Player) override;

	bool IsBlowing(void) const {return m_bIsBlowing; }
	bool IsCharged(void) const {return m_bIsCharged; }
	bool IsBurnedWithFlintAndSteel(void) const {return m_BurnedWithFlintAndSteel; }

private:

	bool m_bIsBlowing, m_bIsCharged, m_BurnedWithFlintAndSteel;
	int m_ExplodingTimer;

} ;




