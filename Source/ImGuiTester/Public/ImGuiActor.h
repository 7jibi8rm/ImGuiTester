#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/BitArray.h"
#include "ImGuiTester/ImGuiCommon.h"  // ImGui
#include "ImGuiActor.generated.h"

/**
 * ImGuiによるデバッグUIやテスト機能を提供するアクタークラス。
 * Unreal EngineのTickやイベントに連動してImGuiのウィンドウやテストケースを管理します。
 */
UCLASS()
class IMGUITESTER_API AImGuiActor : public AActor
{
	GENERATED_BODY()

public:

	/**
	 * AImGuiActor クラスの新しいインスタンスを生成します。
	 * ImGuiテストケースの初期化やTick設定を行います。
	 */
	AImGuiActor();

#if WITH_IMGUI
protected:

	/**
	 * ゲーム開始時またはアクターがスポーンされた際に呼び出されます。
	 * ImGuiのTick関数をデリゲートにバインドします。
	 */
	virtual void BeginPlay() override;

	/**
	 * アクターの終了時やレベル遷移時に呼び出されます。
	 * ImGuiのTick関数のデリゲート登録を解除します。
	 * @param EndPlayReason 終了理由
	 */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:

	/**
	 * 毎フレーム呼び出されるTick関数。
	 * 必要に応じてアクターの状態更新などを行います。
	 * @param DeltaTime 前フレームからの経過時間（秒）
	 */
	virtual void Tick(float DeltaTime) override;

	/**
	 * ImGui描画用のTick関数。
	 * ImGuiのウィンドウ表示やテストケースのUI制御・実行を行います。
	 */
	void ImGuiTick();

private:

	/**
	 * ImGuiで実行可能なテストケースの種類を定義する列挙型。
	 * 必要に応じてテスト項目を追加してください。
	 */
	enum class ETestCase : uint8
	{
		WindowFlags, ///< ImGuiウィンドウフラグのテスト
		Num,         ///< テストケース数（配列サイズ用）
	};

	/**
	 * テストケースごとの有効/無効状態を管理するビット配列。
	 * チェックボックスUIと連動して各テストのON/OFFを制御します。
	 */
	TBitArray<> TestCaseBits;

	/**
	 * テストケース情報を保持する構造体。
	 * - FlagIndex: テストケースの識別子
	 * - TestFunction: 実行するテスト関数
	 * - Name: テスト名（UI表示用）
	 * - Description: テスト内容の説明
	 */
	struct FtestCase
	{
		ETestCase FlagIndex{};              ///< テストケースの識別子
		TFunction<void()> TestFunction{};   ///< テスト実行用関数
		FString Name{};                     ///< テスト名
		FString Description{};              ///< テスト説明

		FtestCase(const ETestCase InTestCase, TFunction<void()> InTestFunction, const FString& InName, const FString& InDescription)
			: FlagIndex(InTestCase), TestFunction(InTestFunction), Name(InName), Description(InDescription) {
		}
	};

	/**
	 * 登録されている全テストケースのリスト。
	 * ImGuiのUIでボタンや説明文として利用されます。
	 */
	TArray<FtestCase> TestCases{};

	/**
	 * ImGuiウィンドウフラグのテストを実行します。
	 * ImGuiの各種ウィンドウフラグの動作確認用UIを表示します。
	 */
	void TestWindowFlags();

#endif // WITH_IMGUI
};