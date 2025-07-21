#include "ImGuiActor.h"
#include <functional>

#if WITH_IMGUI

/**
 * コンストラクタ
 * ImGuiテストケースの初期化やTick設定を行います。
 */
AImGuiActor::AImGuiActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// テストケースのビット配列を初期化（全て無効で開始）
	TestCaseBits.Init(false, static_cast<uint8>(ETestCase::Num));

	// テストケース情報を追加
	TestCases.Add(FtestCase(ETestCase::WindowFlags, std::bind(&AImGuiActor::TestWindowFlags, this), TEXT("WindowFlags"), TEXT("Test ImGui Window Flags functionality.")));
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
	for (const FtestCase& TestCase : TestCases)
	{
		std::string NameStr = TCHAR_TO_UTF8(*TestCase.Name);
		if (ImGui::Button(NameStr.c_str()))
		{
			// ボタン押下でテストケースの有効/無効を切り替え
			TestCaseBits[static_cast<uint8>(TestCase.FlagIndex)] = !TestCaseBits[static_cast<uint8>(TestCase.FlagIndex)];
		}
		ImGui::SameLine();
		ImGui::TextUnformatted(TCHAR_TO_UTF8(*TestCase.Description));
	}

	ImGui::End();

	// 有効なテストケースを実行
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
 * ImGuiウィンドウフラグのテストを実行します。
 * ImGuiの各種ウィンドウフラグの動作確認用UIを表示します。
 */
void AImGuiActor::TestWindowFlags()
{
	static uint64 WindowFlags = ImGuiWindowFlags_None;

	ImGui::Begin("WindowFlags Test", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
	ImGui::Text("Current Window Flags: %llu", WindowFlags);

	// ここで各種ウィンドウフラグの切り替えUIを追加可能
	//ImGui::Button("Toggle No Title Bar");

	ImGui::End();
	return;
}

#endif // WITH_IMGUI