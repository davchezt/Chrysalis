#pragma once

#include <ICryMannequin.h>


namespace Chrysalis
{
class CProceduralContextLook
	: public IProceduralContext
{
public:
	PROCEDURAL_CONTEXT(CProceduralContextLook, "ProceduralContextLook", "{6B360860-DCE8-4AD9-BA74-F9464671C4AD}"_cry_guid);

	virtual ~CProceduralContextLook() {}

	// IProceduralContext
	virtual void Initialise(IEntity& entity, IActionController& actionController) override;
	virtual void Update(float timePassedSeconds) override;
	// ~IProceduralContext

	void SetIsLookingGame(const bool isLooking) { m_isLookingGame = isLooking; }
	void SetIsLookingProcClip(const bool isLooking) { m_isLookingProcClip = isLooking; }
	void SetLookTarget(const Vec3& lookTarget) { m_gameLookTarget = lookTarget; }

	void SetBlendInTime(const float blendInTime);
	void SetBlendOutTime(const float blendOutTime);
	void SetFovRadians(const float fovRadians);

private:
	void InitialisePoseBlenderLook();
	void InitialiseGameLookTarget();

	IAnimationPoseBlenderDir* m_pPoseBlenderLook { nullptr };
	bool m_isLookingGame { true };
	bool m_isLookingProcClip { false };
	Vec3 m_gameLookTarget { ZERO };
};
}