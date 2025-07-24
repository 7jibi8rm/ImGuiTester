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

};


/**
 * コンストラクタ
 * ImGuiテストケースの初期化やTick設定を行います。
 */
AImGuiActor::AImGuiActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// テストケース情報を追加
	TestCases.Add(FtestCase(TestImGuiBeginAndEnd, TEXT("BeginAndEnd"), TEXT("Test ImGui Begin/End functionality.")));
    TestCases.Add(FtestCase(TestFuncBeginChild, TEXT("BeginChild"), TEXT("Test ImGui BeginChild functionality.")));
	TestCases.Add(FtestCase(TestWindowFlags, TEXT("WindowFlags"), TEXT("Test ImGui Window Flags functionality.")));

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

	// アクターやワールド情報を表示
	ImGui::Text("Actor Tick: Actor = '%ls', World = '%ls', CurrentWorld = '%ls'",
		*GetNameSafe(this), *GetNameSafe(GetWorld()), *GetNameSafe(GWorld));

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