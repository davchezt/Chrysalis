#pragma once

#include <ICryMannequin.h>
#include "ProceduralContextHelpers.h"


namespace Chrysalis
{
class CProceduralContextAim
	: public IProceduralContext
{
public:
	PROCEDURAL_CONTEXT(CProceduralContextAim, "ProceduralContextAim", "{3ED38A0B-DECB-40E6-BF2E-B2D6380EDDEF}"_cry_guid);

	virtual ~CProceduralContextAim() {}

	// IProceduralContext
	virtual void Initialise(IEntity& entity, IActionController& actionController) override;
	virtual void Update(float timePassedSeconds) override;
	// ~IProceduralContext

	void SetIsAimingGame(const bool isAiming) { m_isAimingGame = isAiming; }
	void SetIsAimingProcClip(const bool isAiming) { m_isAimingProcClip = isAiming; }
	void SetAimTarget(const Vec3& aimTarget) { m_aimTarget = aimTarget; }

	void SetBlendInTime(const float blendInTime);
	void SetBlendOutTime(const float blendOutTime);

	uint32 RequestPolarCoordinatesSmoothingParameters(const Vec2& maxSmoothRateRadiansPerSecond, const float smoothTimeSeconds);
	void CancelPolarCoordinatesSmoothingParameters(const uint32 requestId);

private:
	struct SPolarCoordinatesSmoothingParametersRequest
	{
		uint32 id;
		Vec2 maxSmoothRateRadiansPerSecond;
		float smoothTimeSeconds;
	};

	typedef ProceduralContextHelpers::CRequestList<SPolarCoordinatesSmoothingParametersRequest> TPolarCoordinatesSmoothingParametersRequestList;
	TPolarCoordinatesSmoothingParametersRequestList m_polarCoordinatesSmoothingParametersRequestList;

	void InitialisePoseBlenderAim();
	void InitialiseGameAimTarget();
	void UpdatePolarCoordinatesSmoothingParameters();

	IAnimationPoseBlenderDir* m_pPoseBlenderAim { nullptr };
	bool m_isAimingGame { true };
	bool m_isAimingProcClip { false };
	Vec3 m_aimTarget { ZERO };

	Vec2 m_defaultPolarCoordinatesMaxSmoothRateRadiansPerSecond { DEG2RAD(360), DEG2RAD(360) };
	float m_defaultPolarCoordinatesSmoothTimeSeconds { 0.1f };
};
}