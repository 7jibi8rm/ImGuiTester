#include "ImGuiActor.h"
#include <functional>
#include <map>

#if WITH_IMGUI

namespace
{

	// ImGui��Begin/End�̃e�X�g
	void TestImGuiBeginAndEnd()
	{
		static bool bOpen = true;

		// ImGui::Begin�͐V�����E�B���h�E���쐬�E�\�����A������GUI�p�[�c��z�u���邽�߂̊֐��ł��B
		// ����ɑΉ�����ImGui::End�ŕK���E�B���h�E�̕`�揈�����I��������K�v������܂��B
		// �����ŃE�B���h�E�̈悪�쐬����A���̒��Ƀ{�^����X���C�_�[�A�e�L�X�g�Ȃǂ̃E�B�W�F�b�g��ǉ����܂��B
		ImGui::Begin(
			"ImGui Begin/End Test",				// �E�B���h�E�̃^�C�g���i���ʖ��j
			bOpen ? &bOpen : nullptr,			// �E�B���h�E�E��́u�~�v�{�^���ŕ��邩�ǂ������Ǘ�����|�C���^�inullptr�͕\�����Ȃ��j
			ImGuiWindowFlags_AlwaysAutoResize	// �E�B���h�E�̕\������t���O�i�^�C�g���o�[��\���⃊�T�C�Y�s�Ȃǁj
		);

		if (ImGui::Button("bOpen")) {
			bOpen = !bOpen; // �{�^���������ƃE�B���h�E�̊J��Ԃ�؂�ւ���
		}

		// ImGui::End �́AImGui::Begin �ŊJ�n�����E�B���h�E�̕`�揈�����I�����邽�߂̊֐��ł��B
		// ImGui�E�B���h�E���쐬�E�\������ۂ́A�K���y�A�ŌĂяo���K�v������܂��B
		ImGui::End();
	}

    // ImGui��BeginChild/EndChild�̃e�X�g
	void TestFuncBeginChild()
	{
		// ImGui::BeginChild �� ImGui �ŃT�u�̈�i�u�q�E�B���h�E�v�j�����Ƃ��Ɏg���܂��B
		// �X�N���[���̈�̍쐬��AUI�̃��C�A�E�g�����Ȃǂɂ��֗��ł��B

		ImGui::Begin("Parent Window");	// �e�E�B���h�E���J�n
		{
			ImGui::Text("Parent Text");	// �e�E�B���h�E���Ƀe�L�X�g��\��

			ImGui::BeginChild(
				"Child1",				// �q�E�B���h�E�̎��ʖ�
				ImVec2(300, 200),		// �q�E�B���h�E�̃T�C�Y�i��300�A����200�j
				true,					// �X�N���[���o�[��\�����邩�ǂ���
				ImGuiWindowFlags_None);	// �q�E�B���h�E�̕\������t���O�i���Ɏw��Ȃ��j

			{
				ImGui::Text("Child1 Text");	// �q�E�B���h�E���Ƀe�L�X�g��\��
				ImGui::Button("Click Me!");	// �q�E�B���h�E���Ƀ{�^����\��
			}
			ImGui::EndChild();	// �q�E�B���h�E�̕`����I��
		}
		ImGui::End();	// �e�E�B���h�E�̕`����I��
	}

	/**
	 * ImGui�E�B���h�E�t���O�̃e�X�g�����s���܂��B
	 * ImGui�̊e��E�B���h�E�t���O�̓���m�F�pUI��\�����܂��B
	 */
	void TestWindowFlags()
	{
		static std::map<ImGuiWindowFlags, std::string> WindowFlagNames = {
			{ ImGuiWindowFlags_NoTitleBar, "ImGuiWindowFlags_NoTitleBar" },               // �^�C�g���o�[��\�����Ȃ�
			{ ImGuiWindowFlags_NoResize, "ImGuiWindowFlags_NoResize" },                   // �E�B���h�E�̃T�C�Y�ύX���֎~
			{ ImGuiWindowFlags_NoMove, "ImGuiWindowFlags_NoMove" },                       // �E�B���h�E�̈ړ����֎~
			{ ImGuiWindowFlags_NoScrollbar, "ImGuiWindowFlags_NoScrollbar" },             // �X�N���[���o�[��\�����Ȃ�
			{ ImGuiWindowFlags_NoScrollWithMouse, "ImGuiWindowFlags_NoScrollWithMouse" }, // �}�E�X�z�C�[���ɂ��X�N���[�����֎~
			{ ImGuiWindowFlags_NoCollapse, "ImGuiWindowFlags_NoCollapse" },               // �E�B���h�E�̐܂肽���݁i�ŏ����j���֎~
			{ ImGuiWindowFlags_AlwaysAutoResize, "ImGuiWindowFlags_AlwaysAutoResize" },   // �E�B���h�E�T�C�Y����e�ɍ��킹�Ď�������
			{ ImGuiWindowFlags_NoBackground, "ImGuiWindowFlags_NoBackground" },           // �E�B���h�E�̔w�i��`�悵�Ȃ�
			{ ImGuiWindowFlags_NoSavedSettings, "ImGuiWindowFlags_NoSavedSettings" },     // �E�B���h�E�̐ݒ�i�ʒu��T�C�Y�Ȃǁj��ۑ����Ȃ�
			//{ ImGuiWindowFlags_NoMouseInputs, "ImGuiWindowFlags_NoMouseInputs" },         // �E�B���h�E���Ń}�E�X���͂𖳌���
			{ ImGuiWindowFlags_MenuBar, "ImGuiWindowFlags_MenuBar" },                     // ���j���[�o�[��\��
			{ ImGuiWindowFlags_HorizontalScrollbar, "ImGuiWindowFlags_HorizontalScrollbar" }, // �����X�N���[���o�[��\��
			{ ImGuiWindowFlags_NoFocusOnAppearing, "ImGuiWindowFlags_NoFocusOnAppearing" },   // �E�B���h�E�\�����Ƀt�H�[�J�X���擾���Ȃ�
			{ ImGuiWindowFlags_NoBringToFrontOnFocus, "ImGuiWindowFlags_NoBringToFrontOnFocus" }, // �t�H�[�J�X���ɃE�B���h�E���őO�ʂɂ��Ȃ�
			{ ImGuiWindowFlags_AlwaysVerticalScrollbar, "ImGuiWindowFlags_AlwaysVerticalScrollbar" }, // ��ɐ����X�N���[���o�[��\��
			{ ImGuiWindowFlags_AlwaysHorizontalScrollbar, "ImGuiWindowFlags_AlwaysHorizontalScrollbar" }, // ��ɐ����X�N���[���o�[��\��
			{ ImGuiWindowFlags_NoNavInputs, "ImGuiWindowFlags_NoNavInputs" },             // �i�r�Q�[�V�������́i�L�[�{�[�h/�Q�[���p�b�h�j�𖳌���
			{ ImGuiWindowFlags_NoNavFocus, "ImGuiWindowFlags_NoNavFocus" },               // �i�r�Q�[�V�����ɂ��t�H�[�J�X�𖳌���
			{ ImGuiWindowFlags_UnsavedDocument, "ImGuiWindowFlags_UnsavedDocument" },     // ���ۑ��h�L�������g�Ƃ��ĕ\���i�^�u�ɃA�X�^���X�N���j
		};

		static uint64 WindowFlags = ImGuiWindowFlags_AlwaysAutoResize;

		ImGui::Begin("Window Flags Test", nullptr, WindowFlags);
		ImGui::Text("Current WindowFlags: %llu", WindowFlags);

		// �e�E�B���h�E�t���O�̃{�^����\��
		for (auto& FlagName : WindowFlagNames) {
			if (ImGui::Button(FlagName.second.c_str())) {
				WindowFlags ^= FlagName.first;
			}
			ImGui::SameLine();
			if ((WindowFlags & FlagName.first) != 0) {
				ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "ON");
			}
			else {
				ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), "OFF");
			}
		}

		ImGui::End();
		return;
	}

};


/**
 * �R���X�g���N�^
 * ImGui�e�X�g�P�[�X�̏�������Tick�ݒ���s���܂��B
 */
AImGuiActor::AImGuiActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// �e�X�g�P�[�X����ǉ�
	TestCases.Add(FtestCase(TestImGuiBeginAndEnd, TEXT("BeginAndEnd"), TEXT("Test ImGui Begin/End functionality.")));
    TestCases.Add(FtestCase(TestFuncBeginChild, TEXT("BeginChild"), TEXT("Test ImGui BeginChild functionality.")));
	TestCases.Add(FtestCase(TestWindowFlags, TEXT("WindowFlags"), TEXT("Test ImGui Window Flags functionality.")));

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

    // ImGui�̓��̓��[�h��L����
	FImGuiModule& ImGuiModule = FImGuiModule::Get();
	ImGuiModule.SetInputMode(true);
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

	// ImGui�̓��̓��[�h�𖳌���
	FImGuiModule& ImGuiModule = FImGuiModule::Get();
	ImGuiModule.SetInputMode(false);
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
	for (FtestCase& TestCase : TestCases)
	{
		std::string NameStr = TCHAR_TO_UTF8(*TestCase.Name);
		if (ImGui::Button(NameStr.c_str()))
		{
			// �{�^�������Ńe�X�g�P�[�X�̗L��/������؂�ւ�
			TestCase.bDisplayed = !TestCase.bDisplayed;
		}
		ImGui::SameLine();
		ImGui::TextUnformatted(TCHAR_TO_UTF8(*TestCase.Description));

		ImGui::SameLine();
		if (TestCase.bDisplayed) {
			ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "ON");
		}
		else {
			ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.0f), "OFF");
		}
	}

	ImGui::End();

	// �L���ȃe�X�g�P�[�X�����s
	for (const FtestCase& TestCase : TestCases)
	{
		if (TestCase.bDisplayed)
		{
			if (TestCase.TestFunction)
			{
				TestCase.TestFunction();
			}
		}
	}
}

#endif // WITH_IMGUI