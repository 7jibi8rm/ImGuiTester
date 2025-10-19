#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Containers/BitArray.h"
#include "ImGuiTester/ImGuiCommon.h"
#include "ImGuiActor.generated.h"

/**
 * ImGuiによるデバッグUIやテスト機能を提供するアクター。
 * Unreal EngineのTickに連動してImGuiウィンドウやテストケースの実行を管理します。
 */
UCLASS()
class IMGUITESTER_API AImGuiActor : public AActor
{
	GENERATED_BODY()

public:

	/** コンストラクタ：ImGuiテストケースの初期化やTick設定を行う */
	AImGuiActor();

	/** ImGuiウィンドウで使用するサンプルテクスチャ */
	UPROPERTY(EditAnywhere, Category = "ImGui|Assets")
	UTexture2D* SampleTexture = nullptr;

	/** ImGuiウィンドウで使用するボタン用のテクスチャ */
	UPROPERTY(EditAnywhere, Category = "ImGui|Assets")
	UTexture2D* ButtonTexture = nullptr;

protected:

	/** アクター生成・開始時に呼び出され、ImGui Tickデリゲートを登録する */
	virtual void BeginPlay() override;

	/** アクター終了時またはレベル遷移時に呼び出され、ImGui Tickデリゲートを解除する */
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:

	/** ImGui描画用Tick関数。ImGuiのUI表示・テスト制御を行う */
	void ImGuiTick();

	/**
	 * テストケースの構造体。
	 * - TestFunction: 実行するImGuiテスト関数
	 * - Name: テスト名
	 * - bDisplayed: 現在UI上に表示されているかのフラグ
	 */
	struct FTestCase
	{
        TFunction<void()> TestFunction;	// ImGuiテスト関数
        FString Name;					// テスト名
        bool bDisplayed = false;		// UI上に表示されているかのフラグ

		FTestCase() = default;
		FTestCase(TFunction<void()> InTestFunction, const FString& InName)
			: TestFunction(MoveTemp(InTestFunction))
			, Name(InName)
		{
		}
	};

	/** 登録済みすべてのテストケースリスト */
	TArray<FTestCase> TestCases;
};