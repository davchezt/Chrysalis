#pragma once

#include <ICryMannequin.h>


namespace Chrysalis
{
class CProceduralContextLook
	: public IProceduralContext
{
public:
	PROCEDURAL_CONTEXT(CProceduralContextLook, "ProceduralContextLook", "{6B360860-DCE8-4AD9-BA74-F9464671C4AD}"_cry_guid);

	CProceduralContextLook();
	virtual ~CProceduralContextLook() {}

	// IProceduralContext
	virtual void Initialise(IEntity& entity, IActionController& actionController) override;
	virtual void Update(float timePassedSeconds) override;
	// ~IProceduralContext

	void UpdateGameLookingRequest(const bool lookRequest);
	void UpdateGameLookTarget(const Vec3& lookTarget);
	void UpdateProcClipLookingRequest(const bool lookRequest);

	void SetBlendInTime(const float blendInTime);
	void SetBlendOutTime(const float blendOutTime);
	void SetFovRadians(const float fovRadians);

private:
	void InitialisePoseBlenderLook();
	void InitialiseGameLookTarget();

private:
	IAnimationPoseBlenderDir* m_pPoseBlenderLook;

	bool m_gameRequestsLooking;
	bool m_procClipRequestsLooking;
	Vec3 m_gameLookTarget;
};
}