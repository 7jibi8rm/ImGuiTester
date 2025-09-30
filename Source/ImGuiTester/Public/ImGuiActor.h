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

    /** サンプル用のテクスチャアセット。ImGuiウィンドウで表示するために使用されます。 */
	UPROPERTY(EditAnywhere)
	UTexture2D* SampleTexture;

	/** サンプル用のテクスチャアセット。ImGuiウィンドウで表示するために使用されます。 */
	UPROPERTY(EditAnywhere)
	UTexture2D* ButtonTexture;


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
	 * テストケース情報を保持する構造体。
	 * - FlagIndex: テストケースの識別子
	 * - TestFunction: 実行するテスト関数
	 * - Name: テスト名（UI表示用）
	 * - Description: テスト内容の説明
	 */
	struct FtestCase
	{
		TFunction<void()> TestFunction{};   ///< テスト実行用関数
		FString Name{};                     ///< テスト名
        bool bDisplayed{ false };			///< UI表示フラグ

		FtestCase(TFunction<void()> InTestFunction, const FString& InName)
			: TestFunction(InTestFunction), Name(InName) {
		}
	};

	/**
	 * 登録されている全テストケースのリスト。
	 * ImGuiのUIでボタンや説明文として利用されます。
	 */
	TArray<FtestCase> TestCases{};

#endif // WITH_IMGUI
};