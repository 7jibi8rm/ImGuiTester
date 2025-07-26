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
		// ImGuiWindowFlags�́A�E�B���h�E�̋����〈���ڂ𐧌䂷�邽�߂̃r�b�g�t���O�ł��B
		// �E�B���h�E�̃^�C�g���o�[�̗L���A�T�C�Y�ύX��ړ��̉ہA�X�N���[���o�[�̕\���ݒ�ȂǁA���܂��܂ȃE�B���h�E�̑������ׂ����w��ł��܂��B

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

	/// <summary>
	/// �E�B���h�E���쐬����
	/// �V���v����ImGui�E�B���h�E���쐬���A�e�L�X�g��\�����܂��B
	/// ImGui�̃E�B���h�E�����E�e�L�X�g�\���̊�{�I�Ȏg�������m�F�ł��܂��B
	/// </summary>
	void TestSimpleWindow()
	{
		// ����̂݃E�B���h�E�T�C�Y��300x200�ɐݒ肵�܂��iImGuiCond_Once�ň�x�����K�p�j�B
		ImGui::SetNextWindowSize(ImVec2(300, 200), ImGuiCond_Once);

		// "Simple Window" �Ƃ����^�C�g���̃E�B���h�E���J�n���܂��B
		ImGui::Begin("Simple Window");

		// �E�B���h�E���Ƀe�L�X�g��1�s�\�����܂��B
		ImGui::Text("Hello ImGui!");

		// �E�B���h�E�̕`����I�����܂��B
		ImGui::End();
		return;
	}

	/// <summary>
	/// �V���v����ImGui�E�B���h�E���Ƀ{�^����\������e�X�g�֐��B
	/// �{�^���������ƁuButton was clicked!�v�Ƃ����e�L�X�g���\������܂��B
	/// ImGui�̃{�^���E�B�W�F�b�g�̊�{�I�Ȏg�������m�F�ł��܂��B
	/// </summary>
	void TestSimpleButton()
	{
		// ����̂݃E�B���h�E�T�C�Y��200x100�ɐݒ肵�܂��iImGuiCond_Once�ň�x�����K�p�j�B
		ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiCond_Once);
		// "Button Window" �Ƃ����^�C�g���̃E�B���h�E���J�n���܂��B
		ImGui::Begin("Button Window");
		// �{�^����\�����A�����ꂽ�ꍇ�̓e�L�X�g��\�����܂��B
		if (ImGui::Button("Click Me"))
		{
			// �{�^���������ꂽ�Ƃ��̂ݕ\�������e�L�X�g
			ImGui::Text("Button was clicked!");
		}
		// �E�B���h�E�̕`����I�����܂��B
		ImGui::End();
	}
	/// <summary>
	/// �e�L�X�g��\������
	/// </summary>
	void TestShowText()
	{
		// ����̂݃E�B���h�E�T�C�Y��200x200�ɐݒ肵�܂��iImGuiCond_Once�ň�x�����K�p�j�B
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// "Text Window" �Ƃ����^�C�g���̃E�B���h�E���J�n���܂��B
		ImGui::Begin("Text Window");

		// �����l�𖄂ߍ��񂾃e�L�X�g��\�����܂��B
		int value = 42;
		ImGui::Text("Value: %d", value);

		// �ԐF�Ńe�L�X�g��\�����܂��B
		ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "This is red text");

		// Push/PopStyleColor�ňꎞ�I�Ƀe�L�X�g�F��ύX���ĕ\�����܂��B
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.7f, 0.0f, 1.0f));
		ImGui::Text("This is green text using Push/PopStyleColor");
		ImGui::PopStyleColor();

		// �E�B���h�E�̕`����I�����܂��B
		ImGui::End();
		return;
	}

	/// <summary>
	/// �`�F�b�N�{�b�N�X���쐬����
	/// </summary>
	void TestCheckBox()
	{
		return;
	}

	/// <summary>
	/// �X���C�_�[�𑀍삷��
	/// </summary>
	void TestFloatSlider()
	{
		return;
	}

	/// <summary>
	/// �h���b�v�_�E�����X�g���쐬
	/// </summary>
	void TestComboBox()
	{
		return;
	}

	/// <summary>
	/// �摜��\������
	/// </summary>
	void TestShowImage()
	{
		return;
	}

	/// <summary>
	/// ���x���t�����̓t�B�[���h
	/// </summary>
	void TestInputField()
	{
		return;
	}

	/// <summary>
	/// �e�[�u����\������
	/// </summary>
	void TestSimpleTable()
	{
		return;
	}

	/// <summary>
	/// ���X�g�{�b�N�X���쐬
	/// </summary>
	void TestListBox()
	{
		return;
	}

	/// <summary>
	/// �c���[�m�[�h���쐬
	/// </summary>
	void TestTreeNode()
	{
		return;
	}

	/// <summary>
	/// �c�[���`�b�v��\��
	/// </summary>
	void TestShowTooltip()
	{
		return;
	}

	/// <summary>
	/// �J���[�I���_�C�A���O��\��
	/// </summary>
	void TestColorPicker()
	{
		return;
	}

	/// <summary>
	/// �v���O���X�o�[��\��
	/// </summary>
	void TestProgressBar()
	{
		return;
	}

	/// <summary>
	/// ���j���[���쐬����
	/// </summary>
	void TestMenuBar()
	{
		return;
	}

	/// <summary>
	/// �X�e�[�^�X�o�[���쐬����
	/// </summary>
	void TestStatusBar()
	{
		return;
	}

	/// <summary>
	/// �^�u���쐬����
	/// </summary>
	void TestTabWidget()
	{
		return;
	}

	/// <summary>
	/// �t�H���g��ύX
	/// </summary>
	void TestFontChange()
	{
		return;
	}

	/// <summary>
	/// �X�^�C����ύX����
	/// </summary>
	void TestStyleControl()
	{
		return;
	}

	/// <summary>
	/// �t�H�[�J�X����
	/// </summary>
	void TestFocusControl()
	{
		return;
	}

	/// <summary>
	/// �h���b�O&�h���b�v����������
	/// </summary>
	void TestDragDrop()
	{
		return;
	}

	/// <summary>
	/// �q�E�B���h�E�E�̈�����
	/// </summary>
	void TestChildWindow()
	{
		return;
	}

	/// <summary>
	/// ���͏�Ԃ��Ď�
	/// </summary>
	void TestInputMonitor()
	{
		return;
	}

	/// <summary>
	/// �摜�{�^����ݒu
	/// </summary>
	void TestImageButton()
	{
		return;
	}

	/// <summary>
	/// ���C�A�E�g���X�y�[�X�Œ���
	/// </summary>
	void TestLayoutAdjust()
	{
		return;
	}

	/// <summary>
	/// �s���𕪊��z�u
	/// </summary>
	void TestColumnLayout()
	{
		return;
	}

	/// <summary>
	/// ���[�_���_�C�A���O��\��
	/// </summary>
	void TestModalDialog()
	{
		return;
	}

	/// <summary>
	/// �C�x���g�n���h�����O
	/// </summary>
	void TestEventInput()
	{
		return;
	}

	/// <summary>
	/// �E�B���h�E�̈ʒu�E�T�C�Y�Œ�
	/// </summary>
	void TestWindowPosition()
	{
		return;
	}

	/// <summary>
	/// �A�j���[�V�������쐬
	/// </summary>
	void TestSimpleAnimation()
	{
		return;
	}

	/// <summary>
	/// �t�@�C���p�X����
	/// </summary>
	void TestFileInput()
	{
		return;
	}

	/// <summary>
	/// �X�N���[������
	/// </summary>
	void TestScrollControl()
	{
		return;
	}

	/// <summary>
	/// �f�o�b�O�E�B���h�E�\��
	/// </summary>
	void TestDebugWindow()
	{
		return;
	}

	/// <summary>
	/// �V���[�g�J�b�g�L�[�w��
	/// </summary>
	void TestHotKeySupport()
	{
		return;
	}

	/// <summary>
	/// �f�[�^���R�s�[&�y�[�X�g
	/// </summary>
	void TestClipboard()
	{
		return;
	}

	/// <summary>
	/// �����E�B�W�F�b�g�A��
	/// </summary>
	void TestWidgetGroup()
	{
		return;
	}

	/// <summary>
	/// �m�[�g��w���v�E�B���h�E
	/// </summary>
	void TestHelpNote()
	{
		return;
	}

	/// <summary>
	/// ���͗����Ǘ�
	/// </summary>
	void TestInputHistory()
	{
		return;
	}

	/// <summary>
	/// �ȈՃh�b�L���OUI
	/// </summary>
	void TestDockingUI()
	{
		return;
	}

	/// <summary>
	/// ���o�C���^�b�`�W�F�X�`���[
	/// </summary>
	void TestTouchGesture()
	{
		return;
	}

	/// <summary>
	/// �Y�[��/�p������
	/// </summary>
	void TestZoomPan()
	{
		return;
	}

	/// <summary>
	/// �������փ��X�g�{�b�N�X
	/// </summary>
	void TestReorderListBox()
	{
		return;
	}

	/// <summary>
	/// �L�����o�X�`��
	/// </summary>
	void TestCanvasDraw()
	{
		return;
	}

	/// <summary>
	/// �t���X�N���[���E�B���h�E
	/// </summary>
	void TestFullScreenWindow()
	{
		return;
	}

	/// <summary>
	/// �����_�[���C���[�Ǘ�
	/// </summary>
	void TestRenderLayer()
	{
		return;
	}

	/// <summary>
	/// �X�N���[������
	/// </summary>
	void TestScrollSync()
	{
		return;
	}

	/// <summary>
	/// ���X�|���V�u�f�U�C��
	/// </summary>
	void TestResponsiveWindow()
	{
		return;
	}

	/// <summary>
	/// �_�[�N/���C�g�؂�ւ�
	/// </summary>
	void TestDarkModeToggle()
	{
		return;
	}

	/// <summary>
	/// �\����\����؂�ւ�
	/// </summary>
	void TestVisibilityToggle()
	{
		return;
	}

	/// <summary>
	/// �O���[�v�����Ĉꊇ����
	/// </summary>
	void TestWidgetGrouping()
	{
		return;
	}

	/// <summary>
	/// �^�C�����C���i�i���t���o�[�j
	/// </summary>
	void TestTimelineBar()
	{
		return;
	}

	/// <summary>
	/// �J�X�^���|�b�v�A�b�v
	/// </summary>
	void TestCustomPopup()
	{
		return;
	}

	/// <summary>
	/// �����\��
	/// </summary>
	void TestHighlightText()
	{
		return;
	}

	/// <summary>
	/// �t�B���^�����O���X�g
	/// </summary>
	void TestFilterList()
	{
		return;
	}

	/// <summary>
	/// �����I�����X�g�{�b�N�X
	/// </summary>
	void TestMultiSelectList()
	{
		return;
	}

	/// <summary>
	/// �I�[�o�[���C�\��
	/// </summary>
	void TestOverlayText()
	{
		return;
	}

	/// <summary>
	/// �}���`���C������
	/// </summary>
	void TestMultiLineInput()
	{
		return;
	}

	/// <summary>
	/// ���l�X�e�b�p�[
	/// </summary>
	void TestNumberStepper()
	{
		return;
	}

	/// <summary>
	/// �F�ύXUI
	/// </summary>
	void TestColorEdit()
	{
		return;
	}

	/// <summary>
	/// �L�����Z������
	/// </summary>
	void TestCancelDialog()
	{
		return;
	}

	/// <summary>
	/// ��]/�X�P�[��UI
	/// </summary>
	void TestTransformWidget()
	{
		return;
	}

	/// <summary>
	/// �p�l���^UI
	/// </summary>
	void TestPanelLayout()
	{
		return;
	}

	/// <summary>
	/// �摜�`��J�X�^�}�C�Y
	/// </summary>
	void TestCustomImage()
	{
		return;
	}

	/// <summary>
	/// �T�u�E�B���h�E�ǉ�
	/// </summary>
	void TestAddSubwindow()
	{
		return;
	}

	/// <summary>
	/// ��ʃL���v�`��
	/// </summary>
	void TestScreenShot()
	{
		return;
	}

	/// <summary>
	/// �p�X���[�h����
	/// </summary>
	void TestPasswordInput()
	{
		return;
	}

	/// <summary>
	/// �C�x���g�ʒm�i�g�[�X�g�j
	/// </summary>
	void TestNotification()
	{
		return;
	}

	/// <summary>
	/// �A�N�Z�V�r���e�B
	/// </summary>
	void TestAccessibility()
	{
		return;
	}

	/// <summary>
	/// �z�o�[���ڍ׏��
	/// </summary>
	void TestOnHoverDetail()
	{
		return;
	}

	/// <summary>
	/// �o�b�`�ؑ�UI
	/// </summary>
	void TestBatchSwitch()
	{
		return;
	}

	/// <summary>
	/// ���O�o�̓E�B���h�E
	/// </summary>
	void TestLogWindow()
	{
		return;
	}

	/// <summary>
	/// �����X���C�_�[����
	/// </summary>
	void TestDragSlider()
	{
		return;
	}

	/// <summary>
	/// �}�e���A�������E�B���h�E
	/// </summary>
	void TestMaterialEdit()
	{
		return;
	}

	/// <summary>
	/// GPU�A�N�Z�����[�V�����g�p
	/// </summary>
	void TestGPUAccelUse()
	{
		return;
	}

	/// <summary>
	/// �����Đ�UI
	/// </summary>
	void TestAudioControl()
	{
		return;
	}

	/// <summary>
	/// �r�f�I���ߍ���UI
	/// </summary>
	void TestVideoEmbed()
	{
		return;
	}

	/// <summary>
	/// �V���[�g�J�b�g�\��
	/// </summary>
	void TestShowShortcuts()
	{
		return;
	}

	/// <summary>
	/// �^�O�I��UI
	/// </summary>
	void TestTagSelector()
	{
		return;
	}

	/// <summary>
	/// �w�b�_�[�Ő܂肽����
	/// </summary>
	void TestHeaderCollapse()
	{
		return;
	}

	/// <summary>
	/// �N���X�v���b�g�t�H�[��UI
	/// </summary>
	void TestCrossPlatformUI()
	{
		return;
	}

	/// <summary>
	/// �ʒm�o�b�W�\��
	/// </summary>
	void TestBadgeNotify()
	{
		return;
	}

	/// <summary>
	/// �s���E�J�������ύX�\�e�[�u��
	/// </summary>
	void TestFlexibleTable()
	{
		return;
	}

	/// <summary>
	/// �c�[���o�[�쐬
	/// </summary>
	void TestToolbar()
	{
		return;
	}

	/// <summary>
	/// �C���^���N�e�B�u�`���[�g�ҏW
	/// </summary>
	void TestChartEditor()
	{
		return;
	}

	/// <summary>
	/// �e�[�}�ؑցi�����e�[�}�Ή��j
	/// </summary>
	void TestThemeToggle()
	{
		return;
	}

	/// <summary>
	/// ���T�C�Y�Ή��E�B���h�E
	/// </summary>
	void TestResizableWin()
	{
		return;
	}

	/// <summary>
	/// �}�E�X�J�[�\���J�X�^�}�C�Y
	/// </summary>
	void TestCursorCustom()
	{
		return;
	}

	/// <summary>
	/// �r�W���A���G�t�F�N�g�ǉ�
	/// </summary>
	void TestVisualEffect()
	{
		return;
	}

	/// <summary>
	/// �s�̕��ёւ�
	/// </summary>
	void TestRowSortControl()
	{
		return;
	}

	/// <summary>
	/// �������g�p�󋵕\��
	/// </summary>
	void TestMemoryStats()
	{
		return;
	}

	/// <summary>
	/// ���͕⊮UI
	/// </summary>
	void TestInputCompletion()
	{
		return;
	}

	/// <summary>
	/// �o���f�[�V�����i�l�`�F�b�N�j
	/// </summary>
	void TestValidation()
	{
		return;
	}

	/// <summary>
	/// �ݒ�t�@�C���̕ۑ�/�Ǎ�
	/// </summary>
	void TestConfigIO()
	{
		return;
	}

	/// <summary>
	/// Undo/Redo�Ή�UI
	/// </summary>
	void TestUndoRedo()
	{
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
	TestCases.Add(FtestCase(TestImGuiBeginAndEnd, TEXT("BeginAndEnd"))); // ImGui��Begin/End�̃e�X�g
	TestCases.Add(FtestCase(TestFuncBeginChild, TEXT("BeginChild")));    // ImGui��BeginChild/EndChild�̃e�X�g
	TestCases.Add(FtestCase(TestWindowFlags, TEXT("WindowFlags")));      // ImGui�E�B���h�E�t���O�̃e�X�g
	TestCases.Add(FtestCase(TestSimpleWindow, TEXT("SimpleWindow")));    // �E�B���h�E���쐬����
	TestCases.Add(FtestCase(TestSimpleButton, TEXT("SimpleButton")));    // �{�^����\������
	TestCases.Add(FtestCase(TestShowText, TEXT("ShowText")));            // �e�L�X�g��\������
	TestCases.Add(FtestCase(TestCheckBox, TEXT("CheckBox")));            // �`�F�b�N�{�b�N�X���쐬����
	TestCases.Add(FtestCase(TestFloatSlider, TEXT("FloatSlider")));      // �X���C�_�[�𑀍삷��
	TestCases.Add(FtestCase(TestComboBox, TEXT("ComboBox")));            // �h���b�v�_�E�����X�g���쐬
	TestCases.Add(FtestCase(TestShowImage, TEXT("ShowImage")));          // �摜��\������
	TestCases.Add(FtestCase(TestInputField, TEXT("InputField")));        // ���x���t�����̓t�B�[���h
	TestCases.Add(FtestCase(TestSimpleTable, TEXT("SimpleTable")));      // �e�[�u����\������
	TestCases.Add(FtestCase(TestListBox, TEXT("ListBox")));              // ���X�g�{�b�N�X���쐬
	TestCases.Add(FtestCase(TestTreeNode, TEXT("TreeNode")));            // �c���[�m�[�h���쐬
	TestCases.Add(FtestCase(TestShowTooltip, TEXT("ShowTooltip")));      // �c�[���`�b�v��\��
	TestCases.Add(FtestCase(TestColorPicker, TEXT("ColorPicker")));      // �J���[�I���_�C�A���O��\��
	TestCases.Add(FtestCase(TestProgressBar, TEXT("ProgressBar")));      // �v���O���X�o�[��\��
	TestCases.Add(FtestCase(TestMenuBar, TEXT("MenuBar")));              // ���j���[���쐬����
	TestCases.Add(FtestCase(TestStatusBar, TEXT("StatusBar")));          // �X�e�[�^�X�o�[���쐬����
	TestCases.Add(FtestCase(TestTabWidget, TEXT("TabWidget")));          // �^�u���쐬����
	TestCases.Add(FtestCase(TestFontChange, TEXT("FontChange")));        // �t�H���g��ύX
	TestCases.Add(FtestCase(TestStyleControl, TEXT("StyleControl")));    // �X�^�C����ύX����
	TestCases.Add(FtestCase(TestFocusControl, TEXT("FocusControl")));    // �t�H�[�J�X����
	TestCases.Add(FtestCase(TestDragDrop, TEXT("DragDrop")));            // �h���b�O&�h���b�v����������
	TestCases.Add(FtestCase(TestChildWindow, TEXT("ChildWindow")));      // �q�E�B���h�E�E�̈�����
	TestCases.Add(FtestCase(TestInputMonitor, TEXT("InputMonitor")));    // ���͏�Ԃ��Ď�
	TestCases.Add(FtestCase(TestImageButton, TEXT("ImageButton")));      // �摜�{�^����ݒu
	TestCases.Add(FtestCase(TestLayoutAdjust, TEXT("LayoutAdjust")));    // ���C�A�E�g���X�y�[�X�Œ���
	TestCases.Add(FtestCase(TestColumnLayout, TEXT("ColumnLayout")));    // �s���𕪊��z�u
	TestCases.Add(FtestCase(TestModalDialog, TEXT("ModalDialog")));      // ���[�_���_�C�A���O��\��
	TestCases.Add(FtestCase(TestEventInput, TEXT("EventInput")));        // �C�x���g�n���h�����O
	TestCases.Add(FtestCase(TestWindowPosition, TEXT("WindowPosition"))); // �E�B���h�E�̈ʒu�E�T�C�Y�Œ�
	TestCases.Add(FtestCase(TestSimpleAnimation, TEXT("SimpleAnimation"))); // �A�j���[�V�������쐬
	TestCases.Add(FtestCase(TestFileInput, TEXT("FileInput")));          // �t�@�C���p�X����
	TestCases.Add(FtestCase(TestScrollControl, TEXT("ScrollControl")));  // �X�N���[������
	TestCases.Add(FtestCase(TestDebugWindow, TEXT("DebugWindow")));      // �f�o�b�O�E�B���h�E�\��
	TestCases.Add(FtestCase(TestHotKeySupport, TEXT("HotKeySupport")));  // �V���[�g�J�b�g�L�[�w��
	TestCases.Add(FtestCase(TestClipboard, TEXT("Clipboard")));          // �f�[�^���R�s�[&�y�[�X�g
	TestCases.Add(FtestCase(TestWidgetGroup, TEXT("WidgetGroup")));      // �����E�B�W�F�b�g�A��
	TestCases.Add(FtestCase(TestHelpNote, TEXT("HelpNote")));            // �m�[�g��w���v�E�B���h�E
	TestCases.Add(FtestCase(TestInputHistory, TEXT("InputHistory")));    // ���͗����Ǘ�
	TestCases.Add(FtestCase(TestDockingUI, TEXT("DockingUI")));          // �ȈՃh�b�L���OUI
	TestCases.Add(FtestCase(TestTouchGesture, TEXT("TouchGesture")));    // ���o�C���^�b�`�W�F�X�`���[
	TestCases.Add(FtestCase(TestZoomPan, TEXT("ZoomPan")));              // �Y�[��/�p������
	TestCases.Add(FtestCase(TestReorderListBox, TEXT("ReorderListBox"))); // �������փ��X�g�{�b�N�X
	TestCases.Add(FtestCase(TestCanvasDraw, TEXT("CanvasDraw")));        // �L�����o�X�`��
	TestCases.Add(FtestCase(TestFullScreenWindow, TEXT("FullScreenWindow"))); // �t���X�N���[���E�B���h�E
	TestCases.Add(FtestCase(TestRenderLayer, TEXT("RenderLayer")));      // �����_�[���C���[�Ǘ�
	TestCases.Add(FtestCase(TestScrollSync, TEXT("ScrollSync")));        // �X�N���[������
	TestCases.Add(FtestCase(TestResponsiveWindow, TEXT("ResponsiveWindow"))); // ���X�|���V�u�f�U�C��
	TestCases.Add(FtestCase(TestDarkModeToggle, TEXT("DarkModeToggle"))); // �_�[�N/���C�g�؂�ւ�
	TestCases.Add(FtestCase(TestVisibilityToggle, TEXT("VisibilityToggle"))); // �\����\����؂�ւ�
	TestCases.Add(FtestCase(TestWidgetGrouping, TEXT("WidgetGrouping"))); // �O���[�v�����Ĉꊇ����
	TestCases.Add(FtestCase(TestTimelineBar, TEXT("TimelineBar")));      // �^�C�����C���i�i���t���o�[�j
	TestCases.Add(FtestCase(TestCustomPopup, TEXT("CustomPopup")));      // �J�X�^���|�b�v�A�b�v
	TestCases.Add(FtestCase(TestHighlightText, TEXT("HighlightText")));  // �����\��
	TestCases.Add(FtestCase(TestFilterList, TEXT("FilterList")));        // �t�B���^�����O���X�g
	TestCases.Add(FtestCase(TestMultiSelectList, TEXT("MultiSelectList"))); // �����I�����X�g�{�b�N�X
	TestCases.Add(FtestCase(TestOverlayText, TEXT("OverlayText")));      // �I�[�o�[���C�\��
	TestCases.Add(FtestCase(TestMultiLineInput, TEXT("MultiLineInput"))); // �}���`���C������
	TestCases.Add(FtestCase(TestNumberStepper, TEXT("NumberStepper")));  // ���l�X�e�b�p�[
	TestCases.Add(FtestCase(TestColorEdit, TEXT("ColorEdit")));          // �F�ύXUI
	TestCases.Add(FtestCase(TestCancelDialog, TEXT("CancelDialog")));    // �L�����Z������
	TestCases.Add(FtestCase(TestTransformWidget, TEXT("TransformWidget"))); // ��]/�X�P�[��UI
	TestCases.Add(FtestCase(TestPanelLayout, TEXT("PanelLayout")));      // �p�l���^UI
	TestCases.Add(FtestCase(TestCustomImage, TEXT("CustomImage")));      // �摜�`��J�X�^�}�C�Y
	TestCases.Add(FtestCase(TestAddSubwindow, TEXT("AddSubwindow")));    // �T�u�E�B���h�E�ǉ�
	TestCases.Add(FtestCase(TestScreenShot, TEXT("ScreenShot")));        // ��ʃL���v�`��
	TestCases.Add(FtestCase(TestPasswordInput, TEXT("PasswordInput")));  // �p�X���[�h����
	TestCases.Add(FtestCase(TestNotification, TEXT("Notification")));    // �C�x���g�ʒm�i�g�[�X�g�j
	TestCases.Add(FtestCase(TestAccessibility, TEXT("Accessibility")));  // �A�N�Z�V�r���e�B
	TestCases.Add(FtestCase(TestOnHoverDetail, TEXT("OnHoverDetail")));  // �z�o�[���ڍ׏��
	TestCases.Add(FtestCase(TestBatchSwitch, TEXT("BatchSwitch")));      // �o�b�`�ؑ�UI
	TestCases.Add(FtestCase(TestLogWindow, TEXT("LogWindow")));          // ���O�o�̓E�B���h�E
	TestCases.Add(FtestCase(TestDragSlider, TEXT("DragSlider")));        // �����X���C�_�[����
	TestCases.Add(FtestCase(TestMaterialEdit, TEXT("MaterialEdit")));    // �}�e���A�������E�B���h�E
	TestCases.Add(FtestCase(TestGPUAccelUse, TEXT("GPUAccelUse")));      // GPU�A�N�Z�����[�V�����g�p
	TestCases.Add(FtestCase(TestAudioControl, TEXT("AudioControl")));    // �����Đ�UI
	TestCases.Add(FtestCase(TestVideoEmbed, TEXT("VideoEmbed")));        // �r�f�I���ߍ���UI
	TestCases.Add(FtestCase(TestShowShortcuts, TEXT("ShowShortcuts")));  // �V���[�g�J�b�g�\��
	TestCases.Add(FtestCase(TestTagSelector, TEXT("TagSelector")));      // �^�O�I��UI
	TestCases.Add(FtestCase(TestHeaderCollapse, TEXT("HeaderCollapse"))); // �w�b�_�[�Ő܂肽����
	TestCases.Add(FtestCase(TestCrossPlatformUI, TEXT("CrossPlatformUI"))); // �N���X�v���b�g�t�H�[��UI
	TestCases.Add(FtestCase(TestBadgeNotify, TEXT("BadgeNotify")));      // �ʒm�o�b�W�\��
	TestCases.Add(FtestCase(TestFlexibleTable, TEXT("FlexibleTable")));  // �s���E�J�������ύX�\�e�[�u��
	TestCases.Add(FtestCase(TestToolbar, TEXT("Toolbar")));              // �c�[���o�[�쐬
	TestCases.Add(FtestCase(TestChartEditor, TEXT("ChartEditor")));      // �C���^���N�e�B�u�`���[�g�ҏW
	TestCases.Add(FtestCase(TestThemeToggle, TEXT("ThemeToggle")));      // �e�[�}�ؑցi�����e�[�}�Ή��j
	TestCases.Add(FtestCase(TestResizableWin, TEXT("ResizableWin")));    // ���T�C�Y�Ή��E�B���h�E
	TestCases.Add(FtestCase(TestCursorCustom, TEXT("CursorCustom")));    // �}�E�X�J�[�\���J�X�^�}�C�Y
	TestCases.Add(FtestCase(TestVisualEffect, TEXT("VisualEffect")));    // �r�W���A���G�t�F�N�g�ǉ�
	TestCases.Add(FtestCase(TestRowSortControl, TEXT("RowSortControl"))); // �s�̕��ёւ�
	TestCases.Add(FtestCase(TestMemoryStats, TEXT("MemoryStats")));      // �������g�p�󋵕\��
	TestCases.Add(FtestCase(TestInputCompletion, TEXT("InputCompletion"))); // ���͕⊮UI
	TestCases.Add(FtestCase(TestValidation, TEXT("Validation")));        // �o���f�[�V�����i�l�`�F�b�N�j
	TestCases.Add(FtestCase(TestConfigIO, TEXT("ConfigIO")));            // �ݒ�t�@�C���̕ۑ�/�Ǎ�
	TestCases.Add(FtestCase(TestUndoRedo, TEXT("UndoRedo")));            // Undo/Redo�Ή�UI
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