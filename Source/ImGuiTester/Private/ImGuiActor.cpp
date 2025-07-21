#include "ImGuiActor.h"
#include <functional>

#if WITH_IMGUI

/**
 * �R���X�g���N�^
 * ImGui�e�X�g�P�[�X�̏�������Tick�ݒ���s���܂��B
 */
AImGuiActor::AImGuiActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// �e�X�g�P�[�X�̃r�b�g�z����������i�S�Ė����ŊJ�n�j
	TestCaseBits.Init(false, static_cast<uint8>(ETestCase::Num));

	// �e�X�g�P�[�X����ǉ�
	TestCases.Add(FtestCase(ETestCase::WindowFlags, std::bind(&AImGuiActor::TestWindowFlags, this), TEXT("WindowFlags"), TEXT("Test ImGui Window Flags functionality.")));
}

/**
 * �Q�[���J�n���܂��̓A�N�^�[���X�|�[�����ꂽ�ۂɌĂяo����܂��B
 * ImGui��Tick�֐����f���Q�[�g�Ƀo�C���h���܂��B
 */
void AImGuiActor::BeginPlay()
{
	Super::BeginPlay();

	// ImGuiTick�֐���OnWorldDebug�f���Q�[�g�Ƀo�C���h
	FImGuiDelegates::OnWorldDebug().AddUObject(this, &AImGuiActor::ImGuiTick);
}

/**
 * �A�N�^�[�̏I�����⃌�x���J�ڎ��ɌĂяo����܂��B
 * ImGui��Tick�֐��̃f���Q�[�g�o�^���������܂��B
 * @param EndPlayReason �I�����R
 */
void AImGuiActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// ImGuiTick�֐��̃f���Q�[�g�o�^������
	FImGuiDelegates::OnWorldDebug().RemoveAll(this);
}

/**
 * ���t���[���Ăяo�����Tick�֐��B
 * �K�v�ɉ����ăA�N�^�[�̏�ԍX�V�Ȃǂ��s���܂��B
 * @param DeltaTime �O�t���[������̌o�ߎ��ԁi�b�j
 */
void AImGuiActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/**
 * ImGui�`��p��Tick�֐��B
 * ImGui�̃E�B���h�E�\����e�X�g�P�[�X��UI����E���s���s���܂��B
 */
void AImGuiActor::ImGuiTick()
{
	// ImGui�̃E�B���h�E���J�n
	ImGui::Begin("TestMenu", nullptr, ImGuiWindowFlags_AlwaysAutoResize);

	// �A�N�^�[�⃏�[���h����\��
	ImGui::Text("Actor Tick: Actor = '%ls', World = '%ls', CurrentWorld = '%ls'",
		*GetNameSafe(this), *GetNameSafe(GetWorld()), *GetNameSafe(GWorld));

	// �e�X�g�P�[�X���ƂɃ{�^���Ɛ�����\��
	for (const FtestCase& TestCase : TestCases)
	{
		std::string NameStr = TCHAR_TO_UTF8(*TestCase.Name);
		if (ImGui::Button(NameStr.c_str()))
		{
			// �{�^�������Ńe�X�g�P�[�X�̗L��/������؂�ւ�
			TestCaseBits[static_cast<uint8>(TestCase.FlagIndex)] = !TestCaseBits[static_cast<uint8>(TestCase.FlagIndex)];
		}
		ImGui::SameLine();
		ImGui::TextUnformatted(TCHAR_TO_UTF8(*TestCase.Description));
	}

	ImGui::End();

	// �L���ȃe�X�g�P�[�X�����s
	for (const FtestCase& TestCase : TestCases)
	{
		if (TestCaseBits[static_cast<uint8>(TestCase.FlagIndex)])
		{
			if (TestCase.TestFunction)
			{
				TestCase.TestFunction();
			}
		}
	}
}

/**
 * ImGui�E�B���h�E�t���O�̃e�X�g�����s���܂��B
 * ImGui�̊e��E�B���h�E�t���O�̓���m�F�pUI��\�����܂��B
 */
void AImGuiActor::TestWindowFlags()
{
	static uint64 WindowFlags = ImGuiWindowFlags_None;

	ImGui::Begin("WindowFlags Test", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::Text("Current Window Flags: %llu", WindowFlags);

	// �����Ŋe��E�B���h�E�t���O�̐؂�ւ�UI��ǉ��\
	//ImGui::Button("Toggle No Title Bar");

	ImGui::End();
	return;
}

#endif // WITH_IMGUI