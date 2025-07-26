#include "ImGuiActor.h"
#include <functional>
#include <map>

#if WITH_IMGUI

namespace
{

	// ImGuiのBegin/Endのテスト
	void TestImGuiBeginAndEnd()
	{
		static bool bOpen = true;

		// ImGui::Beginは新しいウィンドウを作成・表示し、そこにGUIパーツを配置するための関数です。
		// これに対応するImGui::Endで必ずウィンドウの描画処理を終了させる必要があります。
		// 内部でウィンドウ領域が作成され、その中にボタンやスライダー、テキストなどのウィジェットを追加します。
		ImGui::Begin(
			"ImGui Begin/End Test",				// ウィンドウのタイトル（識別名）
			bOpen ? &bOpen : nullptr,			// ウィンドウ右上の「×」ボタンで閉じるかどうかを管理するポインタ（nullptrは表示しない）
			ImGuiWindowFlags_AlwaysAutoResize	// ウィンドウの表示制御フラグ（タイトルバー非表示やリサイズ不可など）
		);

		if (ImGui::Button("bOpen")) {
			bOpen = !bOpen; // ボタンを押すとウィンドウの開閉状態を切り替える
		}

		// ImGui::End は、ImGui::Begin で開始したウィンドウの描画処理を終了するための関数です。
		// ImGuiウィンドウを作成・表示する際は、必ずペアで呼び出す必要があります。
		ImGui::End();
	}

    // ImGuiのBeginChild/EndChildのテスト
	void TestFuncBeginChild()
	{
		// ImGui::BeginChild は ImGui でサブ領域（「子ウィンドウ」）を作るときに使います。
		// スクロール領域の作成や、UIのレイアウト分割などにも便利です。

		ImGui::Begin("Parent Window");	// 親ウィンドウを開始
		{
			ImGui::Text("Parent Text");	// 親ウィンドウ内にテキストを表示

			ImGui::BeginChild(
				"Child1",				// 子ウィンドウの識別名
				ImVec2(300, 200),		// 子ウィンドウのサイズ（幅300、高さ200）
				true,					// スクロールバーを表示するかどうか
				ImGuiWindowFlags_None);	// 子ウィンドウの表示制御フラグ（特に指定なし）

			{
				ImGui::Text("Child1 Text");	// 子ウィンドウ内にテキストを表示
				ImGui::Button("Click Me!");	// 子ウィンドウ内にボタンを表示
			}
			ImGui::EndChild();	// 子ウィンドウの描画を終了
		}
		ImGui::End();	// 親ウィンドウの描画を終了
	}

	/**
	 * ImGuiウィンドウフラグのテストを実行します。
	 * ImGuiの各種ウィンドウフラグの動作確認用UIを表示します。
	 */
	void TestWindowFlags()
	{
		// ImGuiWindowFlagsは、ウィンドウの挙動や見た目を制御するためのビットフラグです。
		// ウィンドウのタイトルバーの有無、サイズ変更や移動の可否、スクロールバーの表示設定など、さまざまなウィンドウの属性を細かく指定できます。

		static std::map<ImGuiWindowFlags, std::string> WindowFlagNames = {
			{ ImGuiWindowFlags_NoTitleBar, "ImGuiWindowFlags_NoTitleBar" },               // タイトルバーを表示しない
			{ ImGuiWindowFlags_NoResize, "ImGuiWindowFlags_NoResize" },                   // ウィンドウのサイズ変更を禁止
			{ ImGuiWindowFlags_NoMove, "ImGuiWindowFlags_NoMove" },                       // ウィンドウの移動を禁止
			{ ImGuiWindowFlags_NoScrollbar, "ImGuiWindowFlags_NoScrollbar" },             // スクロールバーを表示しない
			{ ImGuiWindowFlags_NoScrollWithMouse, "ImGuiWindowFlags_NoScrollWithMouse" }, // マウスホイールによるスクロールを禁止
			{ ImGuiWindowFlags_NoCollapse, "ImGuiWindowFlags_NoCollapse" },               // ウィンドウの折りたたみ（最小化）を禁止
			{ ImGuiWindowFlags_AlwaysAutoResize, "ImGuiWindowFlags_AlwaysAutoResize" },   // ウィンドウサイズを内容に合わせて自動調整
			{ ImGuiWindowFlags_NoBackground, "ImGuiWindowFlags_NoBackground" },           // ウィンドウの背景を描画しない
			{ ImGuiWindowFlags_NoSavedSettings, "ImGuiWindowFlags_NoSavedSettings" },     // ウィンドウの設定（位置やサイズなど）を保存しない
			//{ ImGuiWindowFlags_NoMouseInputs, "ImGuiWindowFlags_NoMouseInputs" },         // ウィンドウ内でマウス入力を無効化
			{ ImGuiWindowFlags_MenuBar, "ImGuiWindowFlags_MenuBar" },                     // メニューバーを表示
			{ ImGuiWindowFlags_HorizontalScrollbar, "ImGuiWindowFlags_HorizontalScrollbar" }, // 水平スクロールバーを表示
			{ ImGuiWindowFlags_NoFocusOnAppearing, "ImGuiWindowFlags_NoFocusOnAppearing" },   // ウィンドウ表示時にフォーカスを取得しない
			{ ImGuiWindowFlags_NoBringToFrontOnFocus, "ImGuiWindowFlags_NoBringToFrontOnFocus" }, // フォーカス時にウィンドウを最前面にしない
			{ ImGuiWindowFlags_AlwaysVerticalScrollbar, "ImGuiWindowFlags_AlwaysVerticalScrollbar" }, // 常に垂直スクロールバーを表示
			{ ImGuiWindowFlags_AlwaysHorizontalScrollbar, "ImGuiWindowFlags_AlwaysHorizontalScrollbar" }, // 常に水平スクロールバーを表示
			{ ImGuiWindowFlags_NoNavInputs, "ImGuiWindowFlags_NoNavInputs" },             // ナビゲーション入力（キーボード/ゲームパッド）を無効化
			{ ImGuiWindowFlags_NoNavFocus, "ImGuiWindowFlags_NoNavFocus" },               // ナビゲーションによるフォーカスを無効化
			{ ImGuiWindowFlags_UnsavedDocument, "ImGuiWindowFlags_UnsavedDocument" },     // 未保存ドキュメントとして表示（タブにアスタリスク等）
		};

		static uint64 WindowFlags = ImGuiWindowFlags_AlwaysAutoResize;

		ImGui::Begin("Window Flags Test", nullptr, WindowFlags);
		ImGui::Text("Current WindowFlags: %llu", WindowFlags);

		// 各ウィンドウフラグのボタンを表示
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
	/// ウィンドウを作成する
	/// シンプルなImGuiウィンドウを作成し、テキストを表示します。
	/// ImGuiのウィンドウ生成・テキスト表示の基本的な使い方を確認できます。
	/// </summary>
	void TestSimpleWindow()
	{
		// 初回のみウィンドウサイズを300x200に設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(300, 200), ImGuiCond_Once);

		// "Simple Window" というタイトルのウィンドウを開始します。
		ImGui::Begin("Simple Window");

		// ウィンドウ内にテキストを1行表示します。
		ImGui::Text("Hello ImGui!");

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// シンプルなImGuiウィンドウ内にボタンを表示するテスト関数。
	/// ボタンを押すと「Button was clicked!」というテキストが表示されます。
	/// ImGuiのボタンウィジェットの基本的な使い方を確認できます。
	/// </summary>
	void TestSimpleButton()
	{
		// 初回のみウィンドウサイズを200x100に設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiCond_Once);
		// "Button Window" というタイトルのウィンドウを開始します。
		ImGui::Begin("Button Window");
		// ボタンを表示し、押された場合はテキストを表示します。
		if (ImGui::Button("Click Me"))
		{
			// ボタンが押されたときのみ表示されるテキスト
			ImGui::Text("Button was clicked!");
		}
		// ウィンドウの描画を終了します。
		ImGui::End();
	}
	/// <summary>
	/// テキストを表示する
	/// </summary>
	void TestShowText()
	{
		// 初回のみウィンドウサイズを200x200に設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// "Text Window" というタイトルのウィンドウを開始します。
		ImGui::Begin("Text Window");

		// 整数値を埋め込んだテキストを表示します。
		int value = 42;
		ImGui::Text("Value: %d", value);

		// 赤色でテキストを表示します。
		ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "This is red text");

		// Push/PopStyleColorで一時的にテキスト色を変更して表示します。
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.7f, 0.0f, 1.0f));
		ImGui::Text("This is green text using Push/PopStyleColor");
		ImGui::PopStyleColor();

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// チェックボックスを作成する
	/// </summary>
	void TestCheckBox()
	{
		return;
	}

	/// <summary>
	/// スライダーを操作する
	/// </summary>
	void TestFloatSlider()
	{
		return;
	}

	/// <summary>
	/// ドロップダウンリストを作成
	/// </summary>
	void TestComboBox()
	{
		return;
	}

	/// <summary>
	/// 画像を表示する
	/// </summary>
	void TestShowImage()
	{
		return;
	}

	/// <summary>
	/// ラベル付き入力フィールド
	/// </summary>
	void TestInputField()
	{
		return;
	}

	/// <summary>
	/// テーブルを表示する
	/// </summary>
	void TestSimpleTable()
	{
		return;
	}

	/// <summary>
	/// リストボックスを作成
	/// </summary>
	void TestListBox()
	{
		return;
	}

	/// <summary>
	/// ツリーノードを作成
	/// </summary>
	void TestTreeNode()
	{
		return;
	}

	/// <summary>
	/// ツールチップを表示
	/// </summary>
	void TestShowTooltip()
	{
		return;
	}

	/// <summary>
	/// カラー選択ダイアログを表示
	/// </summary>
	void TestColorPicker()
	{
		return;
	}

	/// <summary>
	/// プログレスバーを表示
	/// </summary>
	void TestProgressBar()
	{
		return;
	}

	/// <summary>
	/// メニューを作成する
	/// </summary>
	void TestMenuBar()
	{
		return;
	}

	/// <summary>
	/// ステータスバーを作成する
	/// </summary>
	void TestStatusBar()
	{
		return;
	}

	/// <summary>
	/// タブを作成する
	/// </summary>
	void TestTabWidget()
	{
		return;
	}

	/// <summary>
	/// フォントを変更
	/// </summary>
	void TestFontChange()
	{
		return;
	}

	/// <summary>
	/// スタイルを変更する
	/// </summary>
	void TestStyleControl()
	{
		return;
	}

	/// <summary>
	/// フォーカス制御
	/// </summary>
	void TestFocusControl()
	{
		return;
	}

	/// <summary>
	/// ドラッグ&ドロップを実装する
	/// </summary>
	void TestDragDrop()
	{
		return;
	}

	/// <summary>
	/// 子ウィンドウ・領域を作る
	/// </summary>
	void TestChildWindow()
	{
		return;
	}

	/// <summary>
	/// 入力状態を監視
	/// </summary>
	void TestInputMonitor()
	{
		return;
	}

	/// <summary>
	/// 画像ボタンを設置
	/// </summary>
	void TestImageButton()
	{
		return;
	}

	/// <summary>
	/// レイアウトをスペースで調整
	/// </summary>
	void TestLayoutAdjust()
	{
		return;
	}

	/// <summary>
	/// 行や列を分割配置
	/// </summary>
	void TestColumnLayout()
	{
		return;
	}

	/// <summary>
	/// モーダルダイアログを表示
	/// </summary>
	void TestModalDialog()
	{
		return;
	}

	/// <summary>
	/// イベントハンドリング
	/// </summary>
	void TestEventInput()
	{
		return;
	}

	/// <summary>
	/// ウィンドウの位置・サイズ固定
	/// </summary>
	void TestWindowPosition()
	{
		return;
	}

	/// <summary>
	/// アニメーションを作成
	/// </summary>
	void TestSimpleAnimation()
	{
		return;
	}

	/// <summary>
	/// ファイルパス入力
	/// </summary>
	void TestFileInput()
	{
		return;
	}

	/// <summary>
	/// スクロール制御
	/// </summary>
	void TestScrollControl()
	{
		return;
	}

	/// <summary>
	/// デバッグウィンドウ表示
	/// </summary>
	void TestDebugWindow()
	{
		return;
	}

	/// <summary>
	/// ショートカットキー指定
	/// </summary>
	void TestHotKeySupport()
	{
		return;
	}

	/// <summary>
	/// データをコピー&ペースト
	/// </summary>
	void TestClipboard()
	{
		return;
	}

	/// <summary>
	/// 複数ウィジェット連動
	/// </summary>
	void TestWidgetGroup()
	{
		return;
	}

	/// <summary>
	/// ノートやヘルプウィンドウ
	/// </summary>
	void TestHelpNote()
	{
		return;
	}

	/// <summary>
	/// 入力履歴管理
	/// </summary>
	void TestInputHistory()
	{
		return;
	}

	/// <summary>
	/// 簡易ドッキングUI
	/// </summary>
	void TestDockingUI()
	{
		return;
	}

	/// <summary>
	/// モバイルタッチジェスチャー
	/// </summary>
	void TestTouchGesture()
	{
		return;
	}

	/// <summary>
	/// ズーム/パン操作
	/// </summary>
	void TestZoomPan()
	{
		return;
	}

	/// <summary>
	/// 順序入替リストボックス
	/// </summary>
	void TestReorderListBox()
	{
		return;
	}

	/// <summary>
	/// キャンバス描画
	/// </summary>
	void TestCanvasDraw()
	{
		return;
	}

	/// <summary>
	/// フルスクリーンウィンドウ
	/// </summary>
	void TestFullScreenWindow()
	{
		return;
	}

	/// <summary>
	/// レンダーレイヤー管理
	/// </summary>
	void TestRenderLayer()
	{
		return;
	}

	/// <summary>
	/// スクロール同期
	/// </summary>
	void TestScrollSync()
	{
		return;
	}

	/// <summary>
	/// レスポンシブデザイン
	/// </summary>
	void TestResponsiveWindow()
	{
		return;
	}

	/// <summary>
	/// ダーク/ライト切り替え
	/// </summary>
	void TestDarkModeToggle()
	{
		return;
	}

	/// <summary>
	/// 表示非表示を切り替え
	/// </summary>
	void TestVisibilityToggle()
	{
		return;
	}

	/// <summary>
	/// グループ化して一括操作
	/// </summary>
	void TestWidgetGrouping()
	{
		return;
	}

	/// <summary>
	/// タイムライン（進捗付きバー）
	/// </summary>
	void TestTimelineBar()
	{
		return;
	}

	/// <summary>
	/// カスタムポップアップ
	/// </summary>
	void TestCustomPopup()
	{
		return;
	}

	/// <summary>
	/// 強調表示
	/// </summary>
	void TestHighlightText()
	{
		return;
	}

	/// <summary>
	/// フィルタリングリスト
	/// </summary>
	void TestFilterList()
	{
		return;
	}

	/// <summary>
	/// 複数選択リストボックス
	/// </summary>
	void TestMultiSelectList()
	{
		return;
	}

	/// <summary>
	/// オーバーレイ表示
	/// </summary>
	void TestOverlayText()
	{
		return;
	}

	/// <summary>
	/// マルチライン入力
	/// </summary>
	void TestMultiLineInput()
	{
		return;
	}

	/// <summary>
	/// 数値ステッパー
	/// </summary>
	void TestNumberStepper()
	{
		return;
	}

	/// <summary>
	/// 色変更UI
	/// </summary>
	void TestColorEdit()
	{
		return;
	}

	/// <summary>
	/// キャンセル操作
	/// </summary>
	void TestCancelDialog()
	{
		return;
	}

	/// <summary>
	/// 回転/スケールUI
	/// </summary>
	void TestTransformWidget()
	{
		return;
	}

	/// <summary>
	/// パネル型UI
	/// </summary>
	void TestPanelLayout()
	{
		return;
	}

	/// <summary>
	/// 画像描画カスタマイズ
	/// </summary>
	void TestCustomImage()
	{
		return;
	}

	/// <summary>
	/// サブウィンドウ追加
	/// </summary>
	void TestAddSubwindow()
	{
		return;
	}

	/// <summary>
	/// 画面キャプチャ
	/// </summary>
	void TestScreenShot()
	{
		return;
	}

	/// <summary>
	/// パスワード入力
	/// </summary>
	void TestPasswordInput()
	{
		return;
	}

	/// <summary>
	/// イベント通知（トースト）
	/// </summary>
	void TestNotification()
	{
		return;
	}

	/// <summary>
	/// アクセシビリティ
	/// </summary>
	void TestAccessibility()
	{
		return;
	}

	/// <summary>
	/// ホバー時詳細情報
	/// </summary>
	void TestOnHoverDetail()
	{
		return;
	}

	/// <summary>
	/// バッチ切替UI
	/// </summary>
	void TestBatchSwitch()
	{
		return;
	}

	/// <summary>
	/// ログ出力ウィンドウ
	/// </summary>
	void TestLogWindow()
	{
		return;
	}

	/// <summary>
	/// 物理スライダー操作
	/// </summary>
	void TestDragSlider()
	{
		return;
	}

	/// <summary>
	/// マテリアル調整ウィンドウ
	/// </summary>
	void TestMaterialEdit()
	{
		return;
	}

	/// <summary>
	/// GPUアクセラレーション使用
	/// </summary>
	void TestGPUAccelUse()
	{
		return;
	}

	/// <summary>
	/// 音声再生UI
	/// </summary>
	void TestAudioControl()
	{
		return;
	}

	/// <summary>
	/// ビデオ埋め込みUI
	/// </summary>
	void TestVideoEmbed()
	{
		return;
	}

	/// <summary>
	/// ショートカット表示
	/// </summary>
	void TestShowShortcuts()
	{
		return;
	}

	/// <summary>
	/// タグ選択UI
	/// </summary>
	void TestTagSelector()
	{
		return;
	}

	/// <summary>
	/// ヘッダーで折りたたみ
	/// </summary>
	void TestHeaderCollapse()
	{
		return;
	}

	/// <summary>
	/// クロスプラットフォームUI
	/// </summary>
	void TestCrossPlatformUI()
	{
		return;
	}

	/// <summary>
	/// 通知バッジ表示
	/// </summary>
	void TestBadgeNotify()
	{
		return;
	}

	/// <summary>
	/// 行数・カラム数変更可能テーブル
	/// </summary>
	void TestFlexibleTable()
	{
		return;
	}

	/// <summary>
	/// ツールバー作成
	/// </summary>
	void TestToolbar()
	{
		return;
	}

	/// <summary>
	/// インタラクティブチャート編集
	/// </summary>
	void TestChartEditor()
	{
		return;
	}

	/// <summary>
	/// テーマ切替（複数テーマ対応）
	/// </summary>
	void TestThemeToggle()
	{
		return;
	}

	/// <summary>
	/// リサイズ対応ウィンドウ
	/// </summary>
	void TestResizableWin()
	{
		return;
	}

	/// <summary>
	/// マウスカーソルカスタマイズ
	/// </summary>
	void TestCursorCustom()
	{
		return;
	}

	/// <summary>
	/// ビジュアルエフェクト追加
	/// </summary>
	void TestVisualEffect()
	{
		return;
	}

	/// <summary>
	/// 行の並び替え
	/// </summary>
	void TestRowSortControl()
	{
		return;
	}

	/// <summary>
	/// メモリ使用状況表示
	/// </summary>
	void TestMemoryStats()
	{
		return;
	}

	/// <summary>
	/// 入力補完UI
	/// </summary>
	void TestInputCompletion()
	{
		return;
	}

	/// <summary>
	/// バリデーション（値チェック）
	/// </summary>
	void TestValidation()
	{
		return;
	}

	/// <summary>
	/// 設定ファイルの保存/読込
	/// </summary>
	void TestConfigIO()
	{
		return;
	}

	/// <summary>
	/// Undo/Redo対応UI
	/// </summary>
	void TestUndoRedo()
	{
		return;
	}


};


/**
 * コンストラクタ
 * ImGuiテストケースの初期化やTick設定を行います。
 */
AImGuiActor::AImGuiActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// テストケース情報を追加
	TestCases.Add(FtestCase(TestImGuiBeginAndEnd, TEXT("BeginAndEnd"))); // ImGuiのBegin/Endのテスト
	TestCases.Add(FtestCase(TestFuncBeginChild, TEXT("BeginChild")));    // ImGuiのBeginChild/EndChildのテスト
	TestCases.Add(FtestCase(TestWindowFlags, TEXT("WindowFlags")));      // ImGuiウィンドウフラグのテスト
	TestCases.Add(FtestCase(TestSimpleWindow, TEXT("SimpleWindow")));    // ウィンドウを作成する
	TestCases.Add(FtestCase(TestSimpleButton, TEXT("SimpleButton")));    // ボタンを表示する
	TestCases.Add(FtestCase(TestShowText, TEXT("ShowText")));            // テキストを表示する
	TestCases.Add(FtestCase(TestCheckBox, TEXT("CheckBox")));            // チェックボックスを作成する
	TestCases.Add(FtestCase(TestFloatSlider, TEXT("FloatSlider")));      // スライダーを操作する
	TestCases.Add(FtestCase(TestComboBox, TEXT("ComboBox")));            // ドロップダウンリストを作成
	TestCases.Add(FtestCase(TestShowImage, TEXT("ShowImage")));          // 画像を表示する
	TestCases.Add(FtestCase(TestInputField, TEXT("InputField")));        // ラベル付き入力フィールド
	TestCases.Add(FtestCase(TestSimpleTable, TEXT("SimpleTable")));      // テーブルを表示する
	TestCases.Add(FtestCase(TestListBox, TEXT("ListBox")));              // リストボックスを作成
	TestCases.Add(FtestCase(TestTreeNode, TEXT("TreeNode")));            // ツリーノードを作成
	TestCases.Add(FtestCase(TestShowTooltip, TEXT("ShowTooltip")));      // ツールチップを表示
	TestCases.Add(FtestCase(TestColorPicker, TEXT("ColorPicker")));      // カラー選択ダイアログを表示
	TestCases.Add(FtestCase(TestProgressBar, TEXT("ProgressBar")));      // プログレスバーを表示
	TestCases.Add(FtestCase(TestMenuBar, TEXT("MenuBar")));              // メニューを作成する
	TestCases.Add(FtestCase(TestStatusBar, TEXT("StatusBar")));          // ステータスバーを作成する
	TestCases.Add(FtestCase(TestTabWidget, TEXT("TabWidget")));          // タブを作成する
	TestCases.Add(FtestCase(TestFontChange, TEXT("FontChange")));        // フォントを変更
	TestCases.Add(FtestCase(TestStyleControl, TEXT("StyleControl")));    // スタイルを変更する
	TestCases.Add(FtestCase(TestFocusControl, TEXT("FocusControl")));    // フォーカス制御
	TestCases.Add(FtestCase(TestDragDrop, TEXT("DragDrop")));            // ドラッグ&ドロップを実装する
	TestCases.Add(FtestCase(TestChildWindow, TEXT("ChildWindow")));      // 子ウィンドウ・領域を作る
	TestCases.Add(FtestCase(TestInputMonitor, TEXT("InputMonitor")));    // 入力状態を監視
	TestCases.Add(FtestCase(TestImageButton, TEXT("ImageButton")));      // 画像ボタンを設置
	TestCases.Add(FtestCase(TestLayoutAdjust, TEXT("LayoutAdjust")));    // レイアウトをスペースで調整
	TestCases.Add(FtestCase(TestColumnLayout, TEXT("ColumnLayout")));    // 行や列を分割配置
	TestCases.Add(FtestCase(TestModalDialog, TEXT("ModalDialog")));      // モーダルダイアログを表示
	TestCases.Add(FtestCase(TestEventInput, TEXT("EventInput")));        // イベントハンドリング
	TestCases.Add(FtestCase(TestWindowPosition, TEXT("WindowPosition"))); // ウィンドウの位置・サイズ固定
	TestCases.Add(FtestCase(TestSimpleAnimation, TEXT("SimpleAnimation"))); // アニメーションを作成
	TestCases.Add(FtestCase(TestFileInput, TEXT("FileInput")));          // ファイルパス入力
	TestCases.Add(FtestCase(TestScrollControl, TEXT("ScrollControl")));  // スクロール制御
	TestCases.Add(FtestCase(TestDebugWindow, TEXT("DebugWindow")));      // デバッグウィンドウ表示
	TestCases.Add(FtestCase(TestHotKeySupport, TEXT("HotKeySupport")));  // ショートカットキー指定
	TestCases.Add(FtestCase(TestClipboard, TEXT("Clipboard")));          // データをコピー&ペースト
	TestCases.Add(FtestCase(TestWidgetGroup, TEXT("WidgetGroup")));      // 複数ウィジェット連動
	TestCases.Add(FtestCase(TestHelpNote, TEXT("HelpNote")));            // ノートやヘルプウィンドウ
	TestCases.Add(FtestCase(TestInputHistory, TEXT("InputHistory")));    // 入力履歴管理
	TestCases.Add(FtestCase(TestDockingUI, TEXT("DockingUI")));          // 簡易ドッキングUI
	TestCases.Add(FtestCase(TestTouchGesture, TEXT("TouchGesture")));    // モバイルタッチジェスチャー
	TestCases.Add(FtestCase(TestZoomPan, TEXT("ZoomPan")));              // ズーム/パン操作
	TestCases.Add(FtestCase(TestReorderListBox, TEXT("ReorderListBox"))); // 順序入替リストボックス
	TestCases.Add(FtestCase(TestCanvasDraw, TEXT("CanvasDraw")));        // キャンバス描画
	TestCases.Add(FtestCase(TestFullScreenWindow, TEXT("FullScreenWindow"))); // フルスクリーンウィンドウ
	TestCases.Add(FtestCase(TestRenderLayer, TEXT("RenderLayer")));      // レンダーレイヤー管理
	TestCases.Add(FtestCase(TestScrollSync, TEXT("ScrollSync")));        // スクロール同期
	TestCases.Add(FtestCase(TestResponsiveWindow, TEXT("ResponsiveWindow"))); // レスポンシブデザイン
	TestCases.Add(FtestCase(TestDarkModeToggle, TEXT("DarkModeToggle"))); // ダーク/ライト切り替え
	TestCases.Add(FtestCase(TestVisibilityToggle, TEXT("VisibilityToggle"))); // 表示非表示を切り替え
	TestCases.Add(FtestCase(TestWidgetGrouping, TEXT("WidgetGrouping"))); // グループ化して一括操作
	TestCases.Add(FtestCase(TestTimelineBar, TEXT("TimelineBar")));      // タイムライン（進捗付きバー）
	TestCases.Add(FtestCase(TestCustomPopup, TEXT("CustomPopup")));      // カスタムポップアップ
	TestCases.Add(FtestCase(TestHighlightText, TEXT("HighlightText")));  // 強調表示
	TestCases.Add(FtestCase(TestFilterList, TEXT("FilterList")));        // フィルタリングリスト
	TestCases.Add(FtestCase(TestMultiSelectList, TEXT("MultiSelectList"))); // 複数選択リストボックス
	TestCases.Add(FtestCase(TestOverlayText, TEXT("OverlayText")));      // オーバーレイ表示
	TestCases.Add(FtestCase(TestMultiLineInput, TEXT("MultiLineInput"))); // マルチライン入力
	TestCases.Add(FtestCase(TestNumberStepper, TEXT("NumberStepper")));  // 数値ステッパー
	TestCases.Add(FtestCase(TestColorEdit, TEXT("ColorEdit")));          // 色変更UI
	TestCases.Add(FtestCase(TestCancelDialog, TEXT("CancelDialog")));    // キャンセル操作
	TestCases.Add(FtestCase(TestTransformWidget, TEXT("TransformWidget"))); // 回転/スケールUI
	TestCases.Add(FtestCase(TestPanelLayout, TEXT("PanelLayout")));      // パネル型UI
	TestCases.Add(FtestCase(TestCustomImage, TEXT("CustomImage")));      // 画像描画カスタマイズ
	TestCases.Add(FtestCase(TestAddSubwindow, TEXT("AddSubwindow")));    // サブウィンドウ追加
	TestCases.Add(FtestCase(TestScreenShot, TEXT("ScreenShot")));        // 画面キャプチャ
	TestCases.Add(FtestCase(TestPasswordInput, TEXT("PasswordInput")));  // パスワード入力
	TestCases.Add(FtestCase(TestNotification, TEXT("Notification")));    // イベント通知（トースト）
	TestCases.Add(FtestCase(TestAccessibility, TEXT("Accessibility")));  // アクセシビリティ
	TestCases.Add(FtestCase(TestOnHoverDetail, TEXT("OnHoverDetail")));  // ホバー時詳細情報
	TestCases.Add(FtestCase(TestBatchSwitch, TEXT("BatchSwitch")));      // バッチ切替UI
	TestCases.Add(FtestCase(TestLogWindow, TEXT("LogWindow")));          // ログ出力ウィンドウ
	TestCases.Add(FtestCase(TestDragSlider, TEXT("DragSlider")));        // 物理スライダー操作
	TestCases.Add(FtestCase(TestMaterialEdit, TEXT("MaterialEdit")));    // マテリアル調整ウィンドウ
	TestCases.Add(FtestCase(TestGPUAccelUse, TEXT("GPUAccelUse")));      // GPUアクセラレーション使用
	TestCases.Add(FtestCase(TestAudioControl, TEXT("AudioControl")));    // 音声再生UI
	TestCases.Add(FtestCase(TestVideoEmbed, TEXT("VideoEmbed")));        // ビデオ埋め込みUI
	TestCases.Add(FtestCase(TestShowShortcuts, TEXT("ShowShortcuts")));  // ショートカット表示
	TestCases.Add(FtestCase(TestTagSelector, TEXT("TagSelector")));      // タグ選択UI
	TestCases.Add(FtestCase(TestHeaderCollapse, TEXT("HeaderCollapse"))); // ヘッダーで折りたたみ
	TestCases.Add(FtestCase(TestCrossPlatformUI, TEXT("CrossPlatformUI"))); // クロスプラットフォームUI
	TestCases.Add(FtestCase(TestBadgeNotify, TEXT("BadgeNotify")));      // 通知バッジ表示
	TestCases.Add(FtestCase(TestFlexibleTable, TEXT("FlexibleTable")));  // 行数・カラム数変更可能テーブル
	TestCases.Add(FtestCase(TestToolbar, TEXT("Toolbar")));              // ツールバー作成
	TestCases.Add(FtestCase(TestChartEditor, TEXT("ChartEditor")));      // インタラクティブチャート編集
	TestCases.Add(FtestCase(TestThemeToggle, TEXT("ThemeToggle")));      // テーマ切替（複数テーマ対応）
	TestCases.Add(FtestCase(TestResizableWin, TEXT("ResizableWin")));    // リサイズ対応ウィンドウ
	TestCases.Add(FtestCase(TestCursorCustom, TEXT("CursorCustom")));    // マウスカーソルカスタマイズ
	TestCases.Add(FtestCase(TestVisualEffect, TEXT("VisualEffect")));    // ビジュアルエフェクト追加
	TestCases.Add(FtestCase(TestRowSortControl, TEXT("RowSortControl"))); // 行の並び替え
	TestCases.Add(FtestCase(TestMemoryStats, TEXT("MemoryStats")));      // メモリ使用状況表示
	TestCases.Add(FtestCase(TestInputCompletion, TEXT("InputCompletion"))); // 入力補完UI
	TestCases.Add(FtestCase(TestValidation, TEXT("Validation")));        // バリデーション（値チェック）
	TestCases.Add(FtestCase(TestConfigIO, TEXT("ConfigIO")));            // 設定ファイルの保存/読込
	TestCases.Add(FtestCase(TestUndoRedo, TEXT("UndoRedo")));            // Undo/Redo対応UI
}

/**
 * ゲーム開始時またはアクターがスポーンされた際に呼び出されます。
 * ImGuiのTick関数をデリゲートにバインドします。
 */
void AImGuiActor::BeginPlay()
{
	Super::BeginPlay();

	// ImGuiTick関数をOnWorldDebugデリゲートにバインド
	FImGuiDelegates::OnWorldDebug().AddUObject(this, &AImGuiActor::ImGuiTick);

    // ImGuiの入力モードを有効化
	FImGuiModule& ImGuiModule = FImGuiModule::Get();
	ImGuiModule.SetInputMode(true);
}

/**
 * アクターの終了時やレベル遷移時に呼び出されます。
 * ImGuiのTick関数のデリゲート登録を解除します。
 * @param EndPlayReason 終了理由
 */
void AImGuiActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	// ImGuiTick関数のデリゲート登録を解除
	FImGuiDelegates::OnWorldDebug().RemoveAll(this);

	// ImGuiの入力モードを無効化
	FImGuiModule& ImGuiModule = FImGuiModule::Get();
	ImGuiModule.SetInputMode(false);
}

/**
 * 毎フレーム呼び出されるTick関数。
 * 必要に応じてアクターの状態更新などを行います。
 * @param DeltaTime 前フレームからの経過時間（秒）
 */
void AImGuiActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/**
 * ImGui描画用のTick関数。
 * ImGuiのウィンドウ表示やテストケースのUI制御・実行を行います。
 */
void AImGuiActor::ImGuiTick()
{
	// ImGuiのウィンドウを開始
	ImGui::Begin("TestMenu", nullptr, ImGuiWindowFlags_AlwaysAutoResize);

	// テストケースごとにボタンと説明を表示
	for (FtestCase& TestCase : TestCases)
	{
		std::string NameStr = TCHAR_TO_UTF8(*TestCase.Name);
		if (ImGui::Button(NameStr.c_str()))
		{
			// ボタン押下でテストケースの有効/無効を切り替え
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

	// 有効なテストケースを実行
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