#include "RealSensePluginPrivatePCH.h"
#include "ExpressionComponent.h"

UExpressionComponent::UExpressionComponent(const class FObjectInitializer& ObjInit)
	: Super(ObjInit)
{
	m_feature = RealSenseFeature::HEAD_TRACKING;
}

void UExpressionComponent::InitializeComponent()
{
	Super::InitializeComponent();

	HeadCount = 0;
	HeadPosition = FVector(0.0f, 0.0f, 0.0f);
	HeadRotation = FRotator(0.0f, 0.0f, 0.0f);
}

void UExpressionComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction *ThisTickFunction)
{
	if (globalRealSenseSession->IsCameraRunning() == false) {
		return;
	}

	HeadCount = globalRealSenseSession->GetHeadCount();
	HeadPosition = globalRealSenseSession->GetHeadPosition();
	HeadRotation = globalRealSenseSession->GetHeadRotation();
	EyesDirection = globalRealSenseSession->GetEyesDirection();
	EyebrowLeft = globalRealSenseSession->GetEyebrowLeft();
	EyebrowRight = globalRealSenseSession->GetEyebrowRight();
	EyeClosedLeft = globalRealSenseSession->GetEyeClosedLeft();
	EyeClosedRight = globalRealSenseSession->GetEyeClosedRight();
	MouthOpen = globalRealSenseSession->GetMouthOpen();
	MouthKiss = globalRealSenseSession->GetMouthKiss();
	MouthSmile = globalRealSenseSession->GetMouthSmile();
	MouthThunge = globalRealSenseSession->GetMouthThunge();
}