#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/BitArray.h"
#include "ImGuiTester/ImGuiCommon.h"
#include "ImGuiActor.generated.h"

/**
 * ImGui�ɂ��f�o�b�OUI��e�X�g�@�\��񋟂���A�N�^�[�B
 * Unreal Engine��Tick�ɘA������ImGui�E�B���h�E��e�X�g�P�[�X�̎��s���Ǘ����܂��B
 */
UCLASS()
class IMGUITESTER_API AImGuiActor : public AActor
{
	GENERATED_BODY()

public:

	/** �R���X�g���N�^�FImGui�e�X�g�P�[�X�̏�������Tick�ݒ���s�� */
	AImGuiActor();

	/** ImGui�E�B���h�E�Ŏg�p����T���v���e�N�X�`�� */
	UPROPERTY(EditAnywhere, Category = "ImGui|Assets")
	UTexture2D* SampleTexture = nullptr;

	/** ImGui�E�B���h�E�Ŏg�p����{�^���p�̃e�N�X�`�� */
	UPROPERTY(EditAnywhere, Category = "ImGui|Assets")
	UTexture2D* ButtonTexture = nullptr;

protected:

	/** �A�N�^�[�����E�J�n���ɌĂяo����AImGui Tick�f���Q�[�g��o�^���� */
	virtual void BeginPlay() override;

	/** �A�N�^�[�I�����܂��̓��x���J�ڎ��ɌĂяo����AImGui Tick�f���Q�[�g���������� */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:

	/** ImGui�`��pTick�֐��BImGui��UI�\���E�e�X�g������s�� */
	void ImGuiTick();

	/**
	 * �e�X�g�P�[�X�̍\���́B
	 * - TestFunction: ���s����ImGui�e�X�g�֐�
	 * - Name: �e�X�g��
	 * - bDisplayed: ����UI��ɕ\������Ă��邩�̃t���O
	 */
	struct FTestCase
	{
        TFunction<void()> TestFunction;	// ImGui�e�X�g�֐�
        FString Name;					// �e�X�g��
        bool bDisplayed = false;		// UI��ɕ\������Ă��邩�̃t���O

		FTestCase() = default;
		FTestCase(TFunction<void()> InTestFunction, const FString& InName)
			: TestFunction(MoveTemp(InTestFunction))
			, Name(InName)
		{
		}
	};

	/** �o�^�ς݂��ׂẴe�X�g�P�[�X���X�g */
	TArray<FTestCase> TestCases;
};