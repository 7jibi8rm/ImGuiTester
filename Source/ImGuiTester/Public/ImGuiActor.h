#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/BitArray.h"
#include "ImGuiTester/ImGuiCommon.h"  // ImGui
#include "ImGuiActor.generated.h"

/**
 * ImGui�ɂ��f�o�b�OUI��e�X�g�@�\��񋟂���A�N�^�[�N���X�B
 * Unreal Engine��Tick��C�x���g�ɘA������ImGui�̃E�B���h�E��e�X�g�P�[�X���Ǘ����܂��B
 */
UCLASS()
class IMGUITESTER_API AImGuiActor : public AActor
{
	GENERATED_BODY()

public:

	/**
	 * AImGuiActor �N���X�̐V�����C���X�^���X�𐶐����܂��B
	 * ImGui�e�X�g�P�[�X�̏�������Tick�ݒ���s���܂��B
	 */
	AImGuiActor();

    /** �T���v���p�̃e�N�X�`���A�Z�b�g�BImGui�E�B���h�E�ŕ\�����邽�߂Ɏg�p����܂��B */
	UPROPERTY(EditAnywhere)
	UTexture2D* SampleTexture;

	/** �T���v���p�̃e�N�X�`���A�Z�b�g�BImGui�E�B���h�E�ŕ\�����邽�߂Ɏg�p����܂��B */
	UPROPERTY(EditAnywhere)
	UTexture2D* ButtonTexture;


#if WITH_IMGUI
protected:

	/**
	 * �Q�[���J�n���܂��̓A�N�^�[���X�|�[�����ꂽ�ۂɌĂяo����܂��B
	 * ImGui��Tick�֐����f���Q�[�g�Ƀo�C���h���܂��B
	 */
	virtual void BeginPlay() override;

	/**
	 * �A�N�^�[�̏I�����⃌�x���J�ڎ��ɌĂяo����܂��B
	 * ImGui��Tick�֐��̃f���Q�[�g�o�^���������܂��B
	 * @param EndPlayReason �I�����R
	 */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

	/**
	 * ���t���[���Ăяo�����Tick�֐��B
	 * �K�v�ɉ����ăA�N�^�[�̏�ԍX�V�Ȃǂ��s���܂��B
	 * @param DeltaTime �O�t���[������̌o�ߎ��ԁi�b�j
	 */
	virtual void Tick(float DeltaTime) override;

	/**
	 * ImGui�`��p��Tick�֐��B
	 * ImGui�̃E�B���h�E�\����e�X�g�P�[�X��UI����E���s���s���܂��B
	 */
	void ImGuiTick();




private:

	/**
	 * �e�X�g�P�[�X����ێ�����\���́B
	 * - FlagIndex: �e�X�g�P�[�X�̎��ʎq
	 * - TestFunction: ���s����e�X�g�֐�
	 * - Name: �e�X�g���iUI�\���p�j
	 * - Description: �e�X�g���e�̐���
	 */
	struct FtestCase
	{
		TFunction<void()> TestFunction{};   ///< �e�X�g���s�p�֐�
		FString Name{};                     ///< �e�X�g��
        bool bDisplayed{ false };			///< UI�\���t���O

		FtestCase(TFunction<void()> InTestFunction, const FString& InName)
			: TestFunction(InTestFunction), Name(InName) {
		}
	};

	/**
	 * �o�^����Ă���S�e�X�g�P�[�X�̃��X�g�B
	 * ImGui��UI�Ń{�^����������Ƃ��ė��p����܂��B
	 */
	TArray<FtestCase> TestCases{};

#endif // WITH_IMGUI
};