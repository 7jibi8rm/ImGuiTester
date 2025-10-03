#include "ImGuiActor.h"
#include <functional>
#include <map>

#if WITH_IMGUI

namespace
{

	/// <summary>
	/// ウィンドウ表示
	/// 一番単純なウィンドウを表示するだけの例です。
	/// ウィンドウを１つ作成し、３行分のテキストを表示します。
	/// </summary>
	void TestSimpleWindow()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestSimpleWindow");

		// テキストを表示。
		ImGui::Text("テキストを表示した１行目");
		ImGui::Text("テキストを表示した２行目");
		ImGui::Text("テキストを表示した３行目");

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// ボタン作成
	/// 単純なボタン配置の例です。
	/// ウィンドウ１つにボタンを３つ配置、ボタンクリックで対応した値が変化します。
	/// </summary>
	void TestSimpleButton()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestSimpleButton");

		// ボタンを表示し、押された瞬間テキストを表示します。
        static bool value[3] = { false, false, false };

		if (ImGui::Button("ボタンA 押してください")){
            value[0] = !value[0];
		}
		if (ImGui::Button("ボタンB 押してください")) {
			value[1] = !value[1];
		}
		if (ImGui::Button("ボタンC 押してください")) {
			value[2] = !value[2];
		}
		ImGui::Text("ボタンA:%d ボタンB:%d  ボタンC:%d", value[0], value[1], value[2]);

		// ウィンドウ描画終了。
		ImGui::End();
        return;
	}

	/// <summary>
	/// 様々なテキスト表示
	/// 色変え等の特殊なテキストの例です。
    /// 変数の値埋め込み、グレーアウト、色指定のテキスト表示を行います。
	/// </summary>
	void TestShowText()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestShowText");

		// 整数値を埋め込んだテキスト表示。
		int value = 42;
		ImGui::Text("Value: %d", value);

		// 色指定してテキスト表示。
		ImGui::TextColored(ImVec4(1.0f, 0.0f, 0.0f, 1.0f), "赤色指定テキスト");

		// グレーアウトなテキスト表示。
        ImGui::TextDisabled("グレーアウトテキスト");

		// 一時的にテキストの色変え。
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.7f, 0.0f, 1.0f));
		ImGui::Text("一時的な色変え１");
		ImGui::Text("一時的な色変え２");
		ImGui::PopStyleColor();

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// チェックボックス
    /// チェックボックス配置の例です。
	/// チェックボックスを３つ配置、状態を変数で管理し、その状態表示。
	/// </summary>
	void TestCheckBox()
	{
        // チェックボックスの状態を保持する変数
		static bool isCheckedA{ false };
		static bool isCheckedB{ false };
		static bool isCheckedC{ false };

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestCheckBox");

        // チェックボックスを表示し、状態を変数で管理。
		ImGui::Checkbox("チェックボックスA", &isCheckedA);
		ImGui::Checkbox("チェックボックスB", &isCheckedB);
		ImGui::Checkbox("チェックボックスC", &isCheckedC);

        // チェックボックスの状態表示。
		ImGui::Text("A:%d B:%d  C:%d", isCheckedA, isCheckedB, isCheckedC);

		// ウィンドウ描画終了。
		ImGui::End(); 
		return;
	}

	/// <summary>
	/// スライダー
    /// スライダー配置の例です。
    /// スライダーを３つ配置、浮動小数版・整数版・度数版の三種類。
	/// </summary>
	void TestSlider()
	{
		static float sliderValueF = 0.0f;
		static int sliderValueI = 0.0f;
		static float sliderValueA = 0.0f;

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(230, 230), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestSlider");

        // スライダーを表示し、値を0.0から100.0の範囲で調整します。
		ImGui::SliderFloat("SliderFloat", &sliderValueF, 0.0f, 1.0f);
		ImGui::SliderInt("SliderInt",  &sliderValueI, 0, 100);
		ImGui::SliderAngle("SliderAngle", &sliderValueA);

		// 整数値を埋め込んだテキストを表示します。
		ImGui::Text("SliderFloat: %f", sliderValueF);
		ImGui::Text("SliderInt: %d", sliderValueI);
		ImGui::Text("SliderAngle: %f", sliderValueA);

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// コンボボックス
	/// コンボボックス配置の例です。
	/// 3項目設定したコンボボックスを１つ配置。
    /// 補足、コンボボックスはプルダウン・ドロップダウンリストとも呼ばれる。
	/// </summary>
	void TestComboBox()
	{
        // コンボボックスの選択状態管理。
		static int ComboBoxValue = 0;

        // コンボボックスアイテムを定義。
		const char* items[] = { "Apple", "Banana", "Cherry" };

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestComboBox");

        // コンボボックスを表示、選択されたインデックスをComboBoxValueで管理。
		if (ImGui::Combo("Fruits", &ComboBoxValue, items, IM_ARRAYSIZE(items)))
		{
            // 変更された際、インデックスをログに出力。
			UE_LOG(LogTemp, Log, TEXT("ComboBoxValue: %d"), ComboBoxValue);
		}

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// テクスチャ表示
	/// コンテンツブラウザの画像を参照して表示する例です。
	/// 外部データ利用にはFImGuiModuleが必要。詳細はAImGuiActor::BeginPlayを確認。
	/// </summary>
	void TestShowImage()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestShowImage");

        // 登録済みテクスチャを呼び出し、ImGuiで表示。
		FImGuiTextureHandle TextureHandle = FImGuiModule::Get().FindTextureHandle("SampleTexture");
		ImGui::Image(TextureHandle, ImVec2(200, 200));

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// ラベル付き入力フィールド
    /// ユーザー入力可能なテキストフィールドを表示する例です。
	/// ３つの入力フィールドを配置、通常・数字のみ・読み取り専用の３種類。
	/// </summary>
	void TestInputField()
	{
		static char InputTextA[128] = "文字列入力";
		static char InputTextB[16] = "123456789";
		static char InputTextC[128] = "読み取り専用";

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestInputField");

        // 入力フィールド表示、ユーザーがテキストを入力できるようになる
		ImGui::InputText("LabelA", InputTextA, IM_ARRAYSIZE(InputTextA));
        ImGui::InputText("LabelB", InputTextB, IM_ARRAYSIZE(InputTextB), ImGuiInputTextFlags_CharsDecimal); // 数字のみ入力可能
        ImGui::InputText("LabelC", InputTextC, IM_ARRAYSIZE(InputTextC), ImGuiInputTextFlags_ReadOnly); // 読み取り専用

		// 入力済みテキスト表示。。
		ImGui::Text("TextA: %s", InputTextA);
		ImGui::Text("TextB: %s", InputTextB);
		ImGui::Text("TextC: %s", InputTextC);

		// ウィンドウ描画終了。
		ImGui::End();

		return;
	}

	/// <summary>
	/// テーブル
	/// テーブル表示の例です。
	/// 3列5行のテーブルを作成し、各セルに行列番号を表示します。
	/// </summary>
	void TestSimpleTable()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestSimpleTable");

        // テーブル開始。3列のテーブル、境界線と行背景を有効化。
		if (ImGui::BeginTable("Table1", 3, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg))
		{
            // テーブルの列を設定します。3つの列を定義。
			ImGui::TableSetupColumn("COL 1");
			ImGui::TableSetupColumn("COL 2");
			ImGui::TableSetupColumn("COL 3");

            // テーブルのヘッダー行を定義。
			ImGui::TableHeadersRow();

            // テーブルの行をループ、各セルにテキスト設定。
			for (int row = 0; row < 5; ++row)
			{
                // 新しい行開始。
				ImGui::TableNextRow();

                // 各列にテキスト設定。
				for (int column = 0; column < 3; ++column)
				{
                    ImGui::TableSetColumnIndex(column); // 列を選択。
					ImGui::Text("%d-%d", row, column);
				}
			}
            // テーブル終了。
			ImGui::EndTable();
		}

		// ウィンドウ描画終了。
		ImGui::End();

		return;
	}

	/// <summary>
	/// ツリーノード
	/// ツリーノード表示の例です。
	/// 親ツリーと２つの子ツリー配置。ツリーノードは階層的なデータ構造の表現が可能。
	/// </summary>
	void TestTreeNode()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestTreeNode");

        // 親ノード開始。
		if (ImGui::TreeNode("Root Node"))
		{
            // 子ノードその１開始。
			if (ImGui::TreeNode("Child Node A"))
			{
				ImGui::BulletText("Text");
                ImGui::TreePop(); // 子ノードその１終了。
			}

			// 子ノードその２開始。
			if (ImGui::TreeNode("Child Node B"))
			{
				ImGui::BulletText("Text");
                ImGui::TreePop(); // 子ノードその２終了。
            }

            // 親ノード終了。
			ImGui::TreePop();
		}

		// ウィンドウ描画終了。
		ImGui::End();

		return;
	}

	/// <summary>
	/// ツールチップ表示
	/// ツールチップを表示させる例です。
    /// アイテムにマウスホバーでツールチップを表示。別名ポップアップヒント。
	/// </summary>
	void TestShowTooltip()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(150, 100), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestShowTooltip");

		// 何らかのアイテムを表示（例：テキスト）
		ImGui::Text("マウスホバーで");

		// マウスが直前のアイテムにホバーされているか判定してツールチップを表示
		if (ImGui::IsItemHovered())
		{
			ImGui::SetTooltip("ツールチップ表示");
		}

		// ウィンドウ描画終了。
		ImGui::End();

		return;
	}

	/// <summary>
	/// カラーピッカー
	/// カラー選択メニューの例です。
	/// RGBA各成分を調整可能なカラーピッカー・プレビュー表示を配置。
	/// </summary>
	void TestColorPicker()
	{
		// カラーを保存する変数
		static ImVec4 color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestColorPicker");

        // カラーピッカーを表示。RGBA各成分を調整可能。
		ImGui::ColorEdit4("RGBA", (float*)&color);

        // カラーピッカー（大きい版）を表示。ウィンドウに収めるのが難しいのでコメントアウト。
		// ImGui::ColorPicker4("RGBA", (float*)&color);

        // 選択された色の値を表示
		ImGui::Text("R: %.2f, G: %.2f, B: %.2f, A: %.2f", color.x, color.y, color.z, color.w);

        // 選択された色のプレビューを表示
		ImGui::ColorButton("RGBA", color);

        // ウィンドウ描画終了。	
		ImGui::End();
		return;
	}

	/// <summary>
	/// プログレスバー
    /// プログレスバー表示の例です。
    /// 進捗率を表すプログレスバーを配置、進捗率は0.0〜1.0の範囲で指定。
	/// </summary>
	void TestProgressBar()
	{
        static float fraction = 0.7f;

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestProgressBar");

        // プログレスバーの表示。0.0から1.0の範囲で進捗率を指定。
        // 自動的に0～100%の範囲で表示される。
		ImGui::ProgressBar(fraction, ImVec2(0.0f, 0.0f)); // サイズ(0,0)は自動的に幅いっぱいで高さは規定値

		// 進捗率をテキスト表示（%表記）
		ImGui::Text("Progress: %f", fraction);

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// メニューバー追加
    /// ウィンドウにメニューバーを追加する例です。
    /// ImGui::Beginにて、ImGuiWindowFlags_MenuBarを指定することでメニューバーを有効化。
	/// メニューバーに「File」を追加し、その中に複数のアイテムを配置。
	/// </summary>
	void TestMenuBar()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_Once);

		// ウィンドウ描画開始。
        ImGui::Begin("TestMenuBar", nullptr, ImGuiWindowFlags_MenuBar); // メニューバーを有効化するフラグを指定。

        // メニューバーを開始します。ウィンドウの上部にメニューバーが表示されます。
		if (ImGui::BeginMenuBar()) 
		{
            // メニューバーに「File」メニューを追加します。
			if (ImGui::BeginMenu("File")) 
			{
                // メニューアイテムを追加します。
				if (ImGui::MenuItem("Open")) {
				}
				if (ImGui::MenuItem("Save")) {
				}

                // メニューの区切り線を追加します。	
				ImGui::Separator();

                // メニューアイテムをさらに追加します。
				if (ImGui::MenuItem("Exit", "Alt+F4")) {
				}

                // メニューの終了
				ImGui::EndMenu();
			}

            // メニューバーを終了します。
			ImGui::EndMenuBar();
		}

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// タブバー
    /// タブ付きウィンドウを作成する例です。
	/// タブバーを追加し２つのタブを配置。 それぞれ内容を変化。
	/// </summary>
	void TestTabWidget()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_Once);

        // ウィンドウ描画開始。
		ImGui::Begin("TestTabWidget");

        // タブバーを開始します。
		if (ImGui::BeginTabBar("##tabs"))
		{
            // タブ1を開始します。
			if (ImGui::BeginTabItem("Tab1"))
			{
				ImGui::Text("Tab 1");
				ImGui::EndTabItem();
			}
            // タブ2を開始します。
			if (ImGui::BeginTabItem("Tab2"))
			{
				ImGui::Text("Tab 2");
				ImGui::EndTabItem();
			}
            // タブバーを終了します。
			ImGui::EndTabBar();
		}

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}


	/// <summary>
	/// スタイル変更
	/// ImGui内の様々なスタイルを変更する例です。
	/// テキストカラーの変更を行います。他にも色々出来そうだが深追いしきれず…。要調査。
	/// </summary>
	void TestStyleControl()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestStyleControl");

		// ImGuiのスタイルを変更するための関数です。
		ImGuiStyle& style = ImGui::GetStyle();

        // スタイルの色を取得します。
        const ImVec4 styleColor = style.Colors[ImGuiCol_Text];

        // スタイルの色を変更します。
		style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 0.5f, 0.5f, 1.0f); 
		ImGui::Text("テキストカラー変更 赤");
		style.Colors[ImGuiCol_Text] = ImVec4(0.5f, 1.0f, 0.5f, 1.0f);
		ImGui::Text("テキストカラー変更 緑");
		style.Colors[ImGuiCol_Text] = ImVec4(0.5f, 0.5f, 1.0f, 1.0f);
		ImGui::Text("テキストカラー変更 青");

        // スタイルの色を元に戻します。
		style.Colors[ImGuiCol_Text] = styleColor;

		// ウィンドウ描画終了。
		ImGui::End();

		return;
	}

	/// <summary>
	/// フォーカス制御
	/// 片方の入力フィールドを優先フォーカスする例です。
    /// フォーカス関数は多々あるため、一番単純なキーボードのフォーカス制御を対応。
	/// その他の応用的な制御は要調査。
	/// </summary>
	void TestFocusControl()
	{
        // 入力フィールド用のバッファ
		static char buf1[128] = "First";
		static char buf2[128] = "Second";

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestFocusControl");

        // 1つ目の入力フィールドを作成。
		ImGui::InputText("無効", buf1, 128);

        // 次のアイテム（2つ目の入力フィールド）を優先フォーカスにします。
		ImGui::SetKeyboardFocusHere();

        // 2つ目の入力フィールドを作成。
		ImGui::InputText("優先", buf2, 128);

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// ドラッグ&ドロップ
    /// ドラッグ&ドロップの実装例です。
	/// アイテムリストをドラッグ&ドロップで並び替え可能にしています。
	/// </summary>
	void TestDragDrop()
	{
        // ドラッグ&ドロップのテスト用のアイテムリスト
		static std::vector<std::string> items = { "Item 1", "Item 2", "Item 3", "Item 4", "Item 5","Item 6","Item 7", "Item 8" };

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

        // ウィンドウ描画開始。
		ImGui::Begin("TestDragDrop");

		for (int i = 0; i < items.size(); i++)
		{
            // アイテムを選択可能なリストとして表示します。
			ImGui::Selectable(items[i].c_str());

			// ドラッグの開始
			if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_SourceAllowNullID))
			{
                // ドラッグ&ドロップのペイロードを設定します。
				ImGui::SetDragDropPayload("DND_DEMO_ITEM", &i, sizeof(int));

                // ドラッグ&ドロップのソースを終了します。
				ImGui::EndDragDropSource();
			}

            // ドラッグ&ドロップのターゲットを設定します。
			if (ImGui::BeginDragDropTarget())
			{
                // ドラッグ&ドロップのペイロードを受け入れます。
				if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("DND_DEMO_ITEM"))
				{
                    // ペイロードからドラッグ元のアイテムインデックスを取得します。
					const int source_idx = *(const int*)payload->Data;
					if (source_idx != i)
					{
						// ドラッグ元とドロップ先を入れ替える
						std::swap(items[source_idx], items[i]);
					}
				}

                // ドラッグ&ドロップのターゲットを終了します。
				ImGui::EndDragDropTarget();
			}
		}

        // ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// 子ウィンドウ作成
    /// ウィンドウの中に子ウィンドウを作成する例です。
	/// 子ウィンドウはスクロール操作や、その中でUI要素を独立して管理できます。
	/// </summary>
	void TestChildWindow()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

        // 親ウィンドウを開始します。
		ImGui::Begin("TestChildWindow");

		// 子ウィンドウ開始（サイズは (width=200, height=150)）
		ImGui::BeginChild("ChildWindowID", ImVec2(160, 160), true); // 第3引数はボーダー表示の有無

        // 子ウィンドウ内にテキストを表示します。
		for (int i = 0; i < 20; i++) {
			ImGui::Text("ChildWindowText %d", i);
		}

		// 子ウィンドウ終了
		ImGui::EndChild();

		// 親ウィンドウ終了
		ImGui::End();
		return;
	}

	/// <summary>
	/// キーボード・マウス入力監視
	/// 入力状態を監視する例です。
	/// マウス位置、ボタン状態、キー押下状態を取得し表示します。
	/// </summary>
	void TestInputMonitor()
	{
		ImGuiIO& io = ImGui::GetIO();

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// 親ウィンドウを開始します。
		ImGui::Begin("TestInputMonitor");

		// マウスの位置取得
		ImVec2 mousePos = io.MousePos;
		ImGui::Text("Mouse Position: (%.1f, %.1f)", mousePos.x, mousePos.y);

		// マウスボタンの状態
		bool mouseLeftDown = io.MouseDown[0];
		ImGui::Text("Left Mouse Button: %s", mouseLeftDown ? "Down" : "Up");

		// キーの押下状態監視（例：スペースキー）
		bool spacePressed = ImGui::IsKeyPressed(ImGuiKey_Space);
		ImGui::Text("Space Key: %s", spacePressed ? "Pressed" : "Released");

		// ImGuiがキーボード入力を受け付け中か判定
		if (io.WantCaptureKeyboard)
			ImGui::Text("ImGui is capturing keyboard input");

		// ImGuiがマウス入力を受け付け中か判定
		if (io.WantCaptureMouse)
			ImGui::Text("ImGui is capturing mouse input");

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// 画像ボタン
	/// 画像付きボタンを配置する例です。
	/// コンテンツブラウザの画像をテクスチャとして登録し、それをボタンに割り当てます。
	/// </summary>
	void TestImageButton()
	{

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_Once);

		// 親ウィンドウを開始します。
		ImGui::Begin("TestImageButton");

		// 登録済みテクスチャを呼び出し、ImGuiで表示。
		FImGuiTextureHandle TextureHandle = FImGuiModule::Get().FindTextureHandle("ButtonTexture");
		if (ImGui::ImageButton("Chawan",TextureHandle, ImVec2(100, 100))) {
			// 確認用ダイアログを開く
			ImGui::OpenPopup("PushDialog");
		}

		// 確認用ダイアログ
		if (ImGui::BeginPopupModal("PushDialog", NULL, ImGuiWindowFlags_AlwaysAutoResize))
		{
			ImGui::Text("画像ボタンを押した");
			if (ImGui::Button("OK")) {
				ImGui::CloseCurrentPopup();
			}
			ImGui::EndPopup();
		}

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// スペース調整
    /// ウィンドウ内のスペース調整の例です。
    /// 縦横のスペース調整、同一ライン配置を行います。
	/// </summary>
	void TestLayoutAdjust()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestLayoutAdjust");

		// 縦のスペース調整
		ImGui::Text("テキスト上（間に20pxの余白指定）");
		ImGui::Spacing();  // 標準スペース
		ImGui::Dummy(ImVec2(0.0f, 20.0f));  // 20pxの空白
		ImGui::Text("テキスト下");

        // さらに縦のスペース調整
		ImGui::Dummy(ImVec2(0.0f, 20.0f));

		// 横のスペース調整
		ImGui::Button("左ボタン");
		ImGui::SameLine(100, 10);  // 50pxから開始、10pxの間隔を空ける
		ImGui::Button("右ボタン");

		// 親ウィンドウ終了
		ImGui::End();
		return;
	}

	/// <summary>
	/// 行や列を分割配置
    /// カラムレイアウトの例です。
	/// ウィンドウ内に3列レイアウトを作成し、各列にテキストを配置します。
	/// </summary>
	void TestColumnLayout()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestColumnLayout");

        // 3列レイアウトを開始します。
		ImGui::Columns(3, nullptr, false);

        // 各列にテキストを表示します。
		ImGui::Text("Column1-1");
		ImGui::Text("Column1-2");
		ImGui::Text("Column1-2");
        ImGui::NextColumn(); // 次の列へ移動
		ImGui::Text("Column2-1");
		ImGui::Text("Column2-2");
		ImGui::Text("Column2-3");
        ImGui::NextColumn(); // 次の列へ移動
		ImGui::Text("Column3-3");
		ImGui::Text("Column3-3");
		ImGui::Text("Column3-3");

		// 列終了（元に戻す）
		ImGui::Columns(1);

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// モーダルダイアログ
	/// ポップアップで出現するダイアログの例です。
	/// ボタンを押すと優先フォーカスされたダイアログが表示されます。
	/// </summary>
	void TestModalDialog()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestModalDialog");

        // ボタンを押すとモーダルダイアログが開きます。
		if (ImGui::Button("Open Dialog"))
		{
            // モーダルダイアログを開く
			ImGui::OpenPopup("Modal Dialog");
		}

        // モーダルダイアログの内容を定義します。
		if (ImGui::BeginPopupModal("Modal Dialog", NULL, ImGuiWindowFlags_AlwaysAutoResize))
		{
            // ダイアログ内のテキスト
			ImGui::Text("モーダルなダイアログ");

            // OKとCancelボタン。ひとまず閉じるだけ。
			if (ImGui::Button("OK")) {
                ImGui::CloseCurrentPopup();
			}
			ImGui::SameLine();
			if (ImGui::Button("Cancel")) {
                ImGui::CloseCurrentPopup();
			}

            // モーダルダイアログの描画を終了します。
			ImGui::EndPopup();
		}

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// コピー&ペースト
	/// クリップボードを利用したコピー&ペーストの例です。
    /// 入力フィールドの文字列をクリップボードにコピーします。
	/// </summary>
	void TestClipboard()
	{
		static char buf[256] = "";

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_Once);

		// ウィンドウ開始
		ImGui::Begin("TestClipboard");

		// テキスト入力
		ImGui::InputText("Input", buf, sizeof(buf));

		// コピー ボタンが押されたらクリップボードにテキストをセット
		if (ImGui::Button("コピー"))
		{
			ImGui::SetClipboardText(buf);
		}

		// ペースト ボタンが押されたらクリップボードからテキストを取得してバッファにセット
		if (ImGui::Button("ペースト"))
		{
			const char* clipboard = ImGui::GetClipboardText();
			if (clipboard)
			{
				strncpy_s(buf, clipboard, sizeof(buf) - 1);
				buf[sizeof(buf) - 1] = '\0'; // 念のため終端を保証
			}
		}

		// テキストを表示する
		ImGui::Text("Buffer: %s", buf);

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// ユーザーガイド表示
	/// ImGuiのユーザーガイドを表示する例です。
    /// ヘルプメニューとして利用可能。ImGuiの基本的な操作方法が記載されています。
	/// </summary>
	void TestHelpNote()
	{
		static bool show_help = true;

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestHelpNote");

        // ヘルプ表示いろいろ
		ImGui::ShowUserGuide();      // ImGuiのユーザーガイドを表示します。
		ImGui::ShowAboutWindow();    // ImGuiのバージョン、クレジットなど概要情報を表示します。
        ImGui::ShowMetricsWindow();  // ImGuiの内部状態、メモリ使用量、ウィンドウ情報などの詳細なメトリクスを表示します。

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// ズーム/パン操作
	/// ズームとパン操作の例です。
	/// マウスホイールでズームイン・ズームアウト、右ドラッグでパン操作が可能です。
    /// 描画領域に円を描画し、ズームとパンを反映します。
	/// </summary>
	void TestZoomPan()
	{
        // ズームとパンの状態を保持する変数
		static float zoom = 1.0f;
		static ImVec2 pan = { 0,0 };

		ImGuiIO& io = ImGui::GetIO();

        // マウスホイールでズームイン・ズームアウト
		if (io.MouseWheel != 0)
		{
			 zoom *= (io.MouseWheel > 0) ? 1.1f : 0.9f;
		}

        // 右ドラッグでパン操作
		if (ImGui::IsMouseDragging(ImGuiMouseButton_Right))
		{
			pan = ImVec2(pan.x + io.MouseDelta.x, pan.y + io.MouseDelta.y);
		}

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestZoomPan");

        // ズームとパンの情報を表示
		ImGui::Text("Zoom: %.2f Pan: (%.1f, %.1f)", zoom, pan.x, pan.y);

        // 描画領域の開始位置を取得
		ImVec2 p = ImGui::GetCursorScreenPos();

        // 描画リストを取得
		ImDrawList* dl = ImGui::GetWindowDrawList();

        // ズームとパンを反映した円を描画
		dl->AddCircleFilled(ImVec2(p.x + pan.x, p.y + pan.y), 50 * zoom, IM_COL32(255, 0, 0, 255));

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// キャンバス描画
	/// ウィンドウ上にラインを描画する例です。
	/// マウスクリックでポイントを追加し、ポイントを直線で結びます。
	/// </summary>
	void TestCanvasDraw()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

        // ウィンドウ描画開始。
		ImGui::Begin("TestCanvasDraw");

		// キャンバスのサイズを指定
		ImVec2 canvas_size = ImVec2(200, 190);
		ImGui::Text("Canvas Area");
		ImGui::InvisibleButton("canvas", canvas_size);

		// 描画リスト取得
		ImDrawList* draw_list = ImGui::GetWindowDrawList();
		ImVec2 origin = ImGui::GetItemRectMin();  // キャンバス左上の座標

		// マウス位置（キャンバス座標系）
		ImVec2 mouse_pos_in_canvas = ImGui::GetIO().MousePos - origin;

		// ポイント配列（staticで保持）
		static ImVector<ImVec2> points;

		// キャンバス内にマウスがあるかつ左クリックがあればポイント追加
		if (ImGui::IsItemHovered())
		{
			if (ImGui::IsMouseClicked(0))
			{
				points.push_back(mouse_pos_in_canvas);
			}
		}

		// 既存のポイントを直線で結ぶ
		for (int i = 0; i < points.Size - 1; i++)
		{
			draw_list->AddLine(origin + points[i], origin + points[i + 1], IM_COL32(255, 0, 0, 255), 2.0f);
		}

        // ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// スクロー位置操作
	/// スクロール位置を直接設定する例です。
	/// ２つのChildウィンドウを横並びに配置し、スクロール位置を同期させます。
	/// </summary>
	void TestScrollSync()
	{
		static float synced_scroll = 0.0f; // 同期するスクロール位置

        // 直近１つのウィンドウサイズ指定。
        ImGui::SetNextWindowSize(ImVec2(250, 250), ImGuiCond_Once);

        // ウィンドウ開始
		ImGui::Begin("TestScrollSync");

        // Child 1
		{
            // Childウィンドウ開始
			ImGui::BeginChild("Child1", ImVec2(100, 200), true, ImGuiWindowFlags_HorizontalScrollbar);
			for (int i = 0; i < 100; i++){
				ImGui::Text("Item %d", i);
			}
			// フォーカスまたはホバーされている場合、スクロール位置を取得
			if (ImGui::IsWindowFocused() || ImGui::IsWindowHovered()){
				synced_scroll = ImGui::GetScrollY(); // スクロール位置取得
			}
			else{
				ImGui::SetScrollY(synced_scroll); // 他方の値に合わせる
			}
            // Childウィンドウ終了	
			ImGui::EndChild();
		}

        // 同じラインに配置
		ImGui::SameLine();

		// Child 2
		{
            // Childウィンドウ開始
			ImGui::BeginChild("Child2", ImVec2(100, 200), true, ImGuiWindowFlags_HorizontalScrollbar);
			for (int i = 0; i < 100; i++){
				ImGui::Text("Item %d", i);
			}
            // フォーカスまたはホバーされている場合、スクロール位置を取得
			if (ImGui::IsWindowFocused() || ImGui::IsWindowHovered()){
				synced_scroll = ImGui::GetScrollY();
			}
			else{
				ImGui::SetScrollY(synced_scroll);
            }
            // Childウィンドウ終了
			ImGui::EndChild();
		}

		ImGui::End();
		return;
	}

	/// <summary>
	/// フィルタリングリスト
    /// フィルタ操作可能なアイテムリストの例です。
    /// テキスト入力でフィルタを指定し、マッチするアイテムのみ表示します。
	/// </summary>
	void TestFilterList()
	{
		const char* items[] = {
			"Apple",
			"Banana",
			"Orange",
			"Grapefruit",
			"Pineapple",
			"Mango"
		};

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestFilterList");

        // フィルタ入力ボックスを表示
		static ImGuiTextFilter filter;
		filter.Draw("Filter");

		// フィルタにマッチするアイテムのみ表示
		for (int i = 0; i < IM_ARRAYSIZE(items); i++) {
			if (filter.PassFilter(items[i])) {
				ImGui::Text("%s", items[i]);
			}
		}

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// 複数選択リストボックス
	/// 複数選択可能なリストボックスの例です。
	/// </summary>
	void TestMultiSelectList()
	{
        // 選択肢の配列
		static const char* items[] = { "Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7", "Item 8" };
		// 選択中のインデックス
		static ImVector<int> selected_indices;

        // 直近１つのウィンドウサイズ指定。
        ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

        // ウィンドウ描画開始。
		ImGui::Begin("TestMultiSelectList");

        // 複数選択可能なリストボックスを表示
		for (int i = 0; i < IM_ARRAYSIZE(items); i++)
		{
            // 選択状態を判定
			bool is_selected = selected_indices.contains(i);
			if (ImGui::Selectable(items[i], is_selected))
			{
				if (!is_selected)
				{
					selected_indices.push_back(i); // 選択追加
				}
				else
				{
					// 選択解除のためにselected_indicesからiを削除
					for (int j = 0; j < selected_indices.Size; j++)
					{
						if (selected_indices[j] == i)
						{
							selected_indices.erase(selected_indices.begin() + j);
							break;
						}
					}
				}
			}
		}

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// マルチライン入力
	/// マルチラインテキスト入力フィールドの例です。
    /// ImGui::InputTextMultilineを使用して複数行のテキスト入力を可能にします。
	/// </summary>
	void TestMultiLineInput()
	{
		static char buf[1024] = "default text";

        // 直近１つのウィンドウサイズ指定。
        ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

        // ウィンドウ描画開始。
        ImGui::Begin("TestMultiLineInput");

        // マルチラインテキスト入力フィールドを表示
		ImGui::InputTextMultiline("##multiline", buf, IM_ARRAYSIZE(buf),ImVec2(180, 100), ImGuiInputTextFlags_None);

		// ウィンドウ描画終了。
		ImGui::End();

		return;

	}

	/// <summary>
	/// 数値ステッパー
    /// 値を増減できる入力フィールドの例です。
    /// ＋－ボタン、マウスドラッグ型の入力フィールドを2種類配置します。
	/// </summary>
	void TestNumberStepper()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestNumberStepper");

		// ステップサイズ付きInputInt（+-ボタン付き）
		static int stepValue = 0;
		ImGui::InputInt("Step Int", &stepValue, 1, 10);

		static float stepValueF = 0.0;
		ImGui::InputFloat("Step Float", &stepValueF, 1.0f, 10.0f);


		// マウスドラッグで値を増減
		static int dragValue = 50;
		ImGui::DragInt("Drag Int", &dragValue, 1.0f, 0, 100);
		static float dragValueF = 50;
		ImGui::DragFloat("Drag Float", &dragValueF, 1.0f, 0.0f, 100.0f);

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// 図形描画
	/// 回転とスケールを適用した四角形描画の例です。
    /// スライダーで回転角度とスケールを調整し、四角形を変形して描画します。
	/// </summary>
	void TestTransformWidget()
	{
		static float angle = 0.0f;
		static float scale = 1.0f;

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(250, 250), ImGuiCond_Once);

        // ウィンドウ描画開始。
		ImGui::Begin("TestTransformWidget");

		ImGui::SliderFloat("Angle", &angle, 0.0f, 360.0f);
		ImGui::SliderFloat("Scale", &scale, 0.1f, 3.0f);

		ImVec2 center = ImGui::GetCursorScreenPos();
		ImVec2 size = ImVec2(100 * scale, 100 * scale);

		// 中心位置を画面内にオフセットして調整
		center.x += 100;
		center.y += 80;

		// 回転計算用ラジアンに変換
		float rad = angle * 3.14159265f / 180.0f;
		float cos_a = cosf(rad);
		float sin_a = sinf(rad);

		// 4頂点の座標（中心(0,0)で計算後、centerオフセット）
		ImVec2 points[4] = {
			ImVec2(-size.x * 0.5f, -size.y * 0.5f),
			ImVec2(+size.x * 0.5f, -size.y * 0.5f),
			ImVec2(+size.x * 0.5f, +size.y * 0.5f),
			ImVec2(-size.x * 0.5f, +size.y * 0.5f)
		};

		for (int i = 0; i < 4; i++) {
			float x = points[i].x, y = points[i].y;
			points[i].x = center.x + x * cos_a - y * sin_a;
			points[i].y = center.y + x * sin_a + y * cos_a;
		}

		ImDrawList* draw_list = ImGui::GetWindowDrawList();
		ImU32 col = IM_COL32(255, 100, 100, 255);

		// 回転・スケールした四角形を描画
		draw_list->AddPolyline(points, 4, col, true, 3.0f);

		ImGui::End();
		return;
	}

	/// <summary>
	/// パスワード入力
	/// パスワード入力フィールドの例です。
    /// 入力内容を'*'で表示される入力フィールドを配置します。
	/// </summary>
	void TestPasswordInput()
	{
		static char password[64] = ""; // パスワード入力用バッファ

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_Once);

        // ウィンドウ描画開始。
		ImGui::Begin("TestPasswordInput");

        // パスワード入力フィールド（入力内容は'*'で表示）
		ImGui::InputText("Password", password, sizeof(password), ImGuiInputTextFlags_Password);

        // 入力されたパスワードを表示（デバッグ用、実際は安全管理に注意）
		ImGui::Text("You entered: %s", password); // デバッグ用表示（実際は安全管理に注意）

        // ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// 音声再生UI
	/// 残念ながらImGui自体に音声再生機能はない…。
	/// 音声再生する際はプラットフォーム側の再生機能を使用する必要があります。
    /// ImGuiとUEのサウンド再生を組み合わせた例です。
	/// </summary>
	void TestAudioControl()
	{
		return;
	}

	/// <summary>
	/// 動画再生UI
	/// </summary>
	void TestVideoEmbed()
	{
		return;
	}

	/// <summary>
	/// タグ選択風UI
    /// SmallButtonを利用したタグ選択風UIの例です。
    /// 複数のタグボタンを配置し、選択状態をトグルで判定しています。
	/// </summary>
	void TestTagSelector()
	{
		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestTagSelector");

		// タグの数
		const int numTags = 4;

		// タグの配列
		const char* tags[numTags] = { "Tag1", "Tag2", "Tag3", "Tag4" };

		// 選択状態を保持する配列
		static bool selected[numTags] = { false, false, false, false };

		// タグボタンを表示
		for (int i = 0; i < numTags; ++i) {
			// ボタンが押されたら選択状態をトグル
			if (ImGui::SmallButton(tags[i])) {
				selected[i] = !selected[i];
			}
			// ボタン間にスペースを入れる
			ImGui::SameLine();
		}
		ImGui::NewLine();

		// 選択されたタグを表示
		ImGui::Text("Selected Tags:");
		for (int i = 0; i < numTags; ++i) {
			if (selected[i]) {
				ImGui::TextColored(ImVec4(0.0f, 1.0f, 0.0f, 1.0f), "%s", tags[i]);
			}
		}

		// ウィンドウ描画終了。
		ImGui::End();

		return;
	}

	/// <summary>
	/// ヘッダーで折りたたみ
	/// 折りたたみ可能なブロックを配置する例です。
    /// ヘッダー部分をクリックすると内容が展開・折りたたまれます。	
	/// </summary>
	void TestHeaderCollapse()
	{
		// 折りたたみヘッダーの状態を保持するbool変数
		static bool open = true;

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestHeaderCollapse");

		// CollapsingHeader: 折りたたみ可能なヘッダーを作成
		if (ImGui::CollapsingHeader("折りたたみヘッダー"))
		{
			// ヘッダーが開かれている時だけ表示される内容
			ImGui::Text("折りたたまれ文字列１");
			ImGui::Text("折りたたまれ文字列２");
			ImGui::Text("折りたたまれ文字列３");
			ImGui::Button("ボタン");
		}

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// 行数・カラム数変更可能テーブル
	/// ImGuiのテーブル機能を応用した例です。
    /// スライダーで行数・カラム数を動的に変更し、テーブルの内容を更新します。
	/// </summary>
	void TestFlexibleTable()
	{
		// 動的に変える行数・カラム数（内部変数）
		static int rows = 5;
		static int columns = 3;

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestFlexibleTable");

		// 行数・カラム数を変更するUI（スライダーなど）
		ImGui::SliderInt("Rows", &rows, 1, 20);
		ImGui::SliderInt("Columns", &columns, 1, 10);

        // テーブルの開始
		if (ImGui::BeginTable("DynamicTable", columns, ImGuiTableFlags_Resizable | ImGuiTableFlags_RowBg | ImGuiTableFlags_Borders))
		{
            // ヘッダー行を作成
			ImGui::TableHeadersRow();

            // 各セルにデータを配置
			for (int row = 0; row < rows; row++)
			{
                // 新しい行を開始
				ImGui::TableNextRow();

                // 各カラムにデータをセット	
				for (int col = 0; col < columns; col++){
					ImGui::TableSetColumnIndex(col);
					ImGui::Text("Row %d Col %d", row + 1, col + 1);
				}
			}

            // テーブルの描画を終了
			ImGui::EndTable();
		}

        // ウィンドウ描画終了。
        ImGui::End();
		return;
	}

	/// <summary>
	/// 折れ線グラフ
	///	ImDrawListを使ってウィンドウ内に折れ線グラフを描画します。
	/// カスタム描画の工夫によりグラフを実現しています。グラフ機能が存在するわけではありません。
	/// </summary>
	void TestLineGraph()
	{

		ImGui::Begin("TestLineGraph");

        // 描画リストと位置・サイズの設定
		ImDrawList* dl = ImGui::GetWindowDrawList();
		ImVec2 pos = ImGui::GetCursorScreenPos();
		ImVec2 size(300, 100);

        // 背景の四角形を描画
		dl->AddRect(pos, ImVec2(pos.x + size.x, pos.y + size.y), IM_COL32(255, 255, 255, 255));

        // サンプルデータ（固定配列）
		float data[] = { 10, 20, 15, 30, 25 };
		float minv = data[0], maxv = data[0];

        // データの最小値・最大値を計算
		for (float v : data){
			if (v < minv) minv = v;
			if (v > maxv) maxv = v;
		}
        // 最小値と最大値が同じ場合の対策
		if (minv == maxv) maxv = minv + 1;

        // 折れ線グラフを描画
		for (int i = 0; i < (int)(sizeof(data) / sizeof(data[0])) - 1; i++){
            // データポイントの位置を計算
			float x1 = pos.x + size.x * i / 4;
			float y1 = pos.y + size.y * (1.0f - (data[i] - minv) / (maxv - minv));
			float x2 = pos.x + size.x * (i + 1) / 4;
			float y2 = pos.y + size.y * (1.0f - (data[i + 1] - minv) / (maxv - minv));
			dl->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), IM_COL32(0, 255, 0, 255), 2.0f); // 線描画を利用してグラフ作成。
		}
        // 描画領域の確保
		ImGui::Dummy(size);

        // ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// テーマ切替
	///	テーマ切り替え用メソッドのテストです。
	/// ダーク・ライト・クラシック・カスタムテーマの4種類への切り替えを行います。
	/// </summary>
	void TestThemeToggle()
	{
		// 初期化時にスタイルを保存
		ImGuiStyle original_style = ImGui::GetStyle();

		// テーマ切り替え用フラグ
		static int theme_type = 0;

        // 直近１つのウィンドウサイズ指定。
        ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

        // ウィンドウ描画開始。
		ImGui::Begin("TestThemeToggle");

        // テーマ切替ボタン
        // ボタンが押されたら対応するテーマに切り替え
		if (ImGui::Button("Dark Theme")) {
			theme_type = 0;
            ImGui::StyleColorsDark(); // ダークテーマに切り替え
		}
		if (ImGui::Button("Light Theme")) {
			theme_type = 1;
            ImGui::StyleColorsLight(); // ライトテーマに切り替え
		}
		if (ImGui::Button("Classic Theme")) {
			theme_type = 2;
            ImGui::StyleColorsClassic(); // クラシックテーマに切り替え
		}
		if (ImGui::Button("Custom Theme")) {
			theme_type = 3;
			ImGuiStyle& style = ImGui::GetStyle();
			style.Colors[ImGuiCol_WindowBg] = ImVec4(0.1f, 0.1f, 0.2f, 1.0f);
			style.Colors[ImGuiCol_Button] = ImVec4(0.2f, 0.5f, 0.7f, 1.0f);
			style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.4f, 0.6f, 0.9f, 1.0f);
			style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.4f, 0.5f, 0.9f, 1.0f);
			// 自由なテーマカラー指定、他にも必要に応じて色を設定
		}

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// マウスカーソルカスタマイズ
    /// マウスカーソルの形を変更する方法の例です。
	/// ホバー時は左右リサイズ用のカーソル、通常時は矢印カーソルを表示します。
    /// ImGui::SetMouseCursor()によりカーソル形状を変更しています。
	/// </summary>
	void TestCursorCustom()
	{
		ImGuiIO& io = ImGui::GetIO();

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(200, 150), ImGuiCond_Once);

		// ウィンドウ描画開始。
		ImGui::Begin("TestCursorCustom");

		// 通常のボタン
		if (ImGui::Button("カーソルを合わせると形変更")) {
			// ボタン処理（今回は使わない）
		}

		// マウスカーソルを変更
		if (ImGui::IsItemHovered()) {
			ImGui::SetMouseCursor(ImGuiMouseCursor_ResizeEW); // 手形カーソルに変更
		}
		else {
			ImGui::SetMouseCursor(ImGuiMouseCursor_Arrow); // 通常の矢印カーソル
		}

		// ウィンドウ描画終了。
		ImGui::End();
		return;
	}

	/// <summary>
	/// 行の並び替え
	/// テーブルソート機能を利用したシンプルなサンプル。
	/// ソート可能なテーブルで行データ（ID・名前・値）を表示します。
	/// ヘッダークリックで昇順・降順の並び替えができます。
	/// </summary>
	void TestRowSortControl()
	{
        // 行データ構造
		struct SimpleRow {
			 int id;
			 std::string name;
			 float val;
		};

		// サンプルデータ
		static std::vector<SimpleRow> rows = {
			{1, "Apple", 9.5f},
			{2, "Banana", 3.2f},
			{3, "Cherry", 5.1f},
			{4, "Date", 7.8f}
		};

		// 直近１つのウィンドウサイズ指定。
		ImGui::SetNextWindowSize(ImVec2(300, 200), ImGuiCond_Once);
        // ウィンドウ描画開始。
        ImGui::Begin("TestRowSortControl");

		// テーブル開始（3列、ソート可能）
		if (ImGui::BeginTable("SimpleSortTable", 3, ImGuiTableFlags_Sortable))
		{
            // 列ヘッダー設定
			ImGui::TableSetupColumn("ID");
			ImGui::TableSetupColumn("Name");
			ImGui::TableSetupColumn("Value");
			ImGui::TableHeadersRow();

			// ソート条件取得
			if (ImGuiTableSortSpecs* sortSpecs = ImGui::TableGetSortSpecs())
			{
                // ソートが必要な場合、行データを並べ替え
				if (sortSpecs->SpecsDirty && sortSpecs->SpecsCount > 0)
				{
                    // 最初のソート条件のみ使用（複数条件は未対応）
					const ImGuiTableColumnSortSpecs& spec = sortSpecs->Specs[0];
                    // 比較関数をラムダで定義
					auto compare = [&](const SimpleRow& a, const SimpleRow& b) {
						bool less = false;
                        if (spec.ColumnIndex == 0)      less = a.id < b.id; // ID列
                        else if (spec.ColumnIndex == 1) less = a.name.compare(b.name)<0; // Name列
                        else if (spec.ColumnIndex == 2) less = a.val < b.val; // Value列
                        return (spec.SortDirection == ImGuiSortDirection_Ascending) ? less : !less; // 昇順/降順
						};
                    // 行データをソート
					std::sort(rows.begin(), rows.end(), compare);
                    // ソート完了フラグをクリア
					sortSpecs->SpecsDirty = false;
				}
			}

			// 行描画
			for (const auto& r : rows)
			{
				ImGui::TableNextRow();
				ImGui::TableSetColumnIndex(0); ImGui::Text("%d", r.id);
				ImGui::TableSetColumnIndex(1); ImGui::Text("%s", r.name.c_str());
				ImGui::TableSetColumnIndex(2); ImGui::Text("%.2f", r.val);
			}

            // テーブル終了
			ImGui::EndTable();
		}
        // ウィンドウ描画終了。
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
	TestCases.Add(FtestCase(TestSimpleWindow, TEXT("SimpleWindow")));    // ウィンドウを作成する
	TestCases.Add(FtestCase(TestSimpleButton, TEXT("SimpleButton")));    // ボタンを表示する
	TestCases.Add(FtestCase(TestShowText, TEXT("ShowText")));            // テキストを表示する
	TestCases.Add(FtestCase(TestCheckBox, TEXT("CheckBox")));            // チェックボックスを作成する
	TestCases.Add(FtestCase(TestSlider, TEXT("Slider")));				 // スライダーを操作する
	TestCases.Add(FtestCase(TestComboBox, TEXT("ComboBox")));            // ドロップダウンリストを作成
	TestCases.Add(FtestCase(TestShowImage, TEXT("ShowImage")));          // 画像を表示する
	TestCases.Add(FtestCase(TestInputField, TEXT("InputField")));        // ラベル付き入力フィールド
	TestCases.Add(FtestCase(TestSimpleTable, TEXT("SimpleTable")));      // テーブルを表示する
	TestCases.Add(FtestCase(TestTreeNode, TEXT("TreeNode")));            // ツリーノードを作成
	TestCases.Add(FtestCase(TestShowTooltip, TEXT("ShowTooltip")));      // ツールチップを表示
	TestCases.Add(FtestCase(TestColorPicker, TEXT("ColorPicker")));      // カラー選択ダイアログを表示
	TestCases.Add(FtestCase(TestProgressBar, TEXT("ProgressBar")));      // プログレスバーを表示
	TestCases.Add(FtestCase(TestMenuBar, TEXT("MenuBar")));              // メニューを作成する
	TestCases.Add(FtestCase(TestTabWidget, TEXT("TabWidget")));          // タブを作成する
	TestCases.Add(FtestCase(TestStyleControl, TEXT("StyleControl")));    // スタイルを変更する
	TestCases.Add(FtestCase(TestFocusControl, TEXT("FocusControl")));    // フォーカス制御
	TestCases.Add(FtestCase(TestDragDrop, TEXT("DragDrop")));            // ドラッグ&ドロップを実装する
	TestCases.Add(FtestCase(TestChildWindow, TEXT("ChildWindow")));      // 子ウィンドウ・領域を作る
	TestCases.Add(FtestCase(TestInputMonitor, TEXT("InputMonitor")));    // 入力状態を監視
	TestCases.Add(FtestCase(TestImageButton, TEXT("ImageButton")));      // 画像ボタンを設置
	TestCases.Add(FtestCase(TestLayoutAdjust, TEXT("LayoutAdjust")));    // レイアウトをスペースで調整
	TestCases.Add(FtestCase(TestColumnLayout, TEXT("ColumnLayout")));    // 行や列を分割配置
	TestCases.Add(FtestCase(TestModalDialog, TEXT("ModalDialog")));      // モーダルダイアログを表示
	TestCases.Add(FtestCase(TestClipboard, TEXT("Clipboard")));          // データをコピー&ペースト
	TestCases.Add(FtestCase(TestHelpNote, TEXT("HelpNote")));            // ノートやヘルプウィンドウ
	TestCases.Add(FtestCase(TestZoomPan, TEXT("ZoomPan")));              // ズーム/パン操作
	TestCases.Add(FtestCase(TestCanvasDraw, TEXT("CanvasDraw")));        // キャンバス描画
	TestCases.Add(FtestCase(TestScrollSync, TEXT("ScrollSync")));        // スクロール同期
	TestCases.Add(FtestCase(TestFilterList, TEXT("FilterList")));        // フィルタリングリスト
	TestCases.Add(FtestCase(TestMultiSelectList, TEXT("MultiSelectList"))); // 複数選択リストボックス
	TestCases.Add(FtestCase(TestMultiLineInput, TEXT("MultiLineInput"))); // マルチライン入力
	TestCases.Add(FtestCase(TestNumberStepper, TEXT("NumberStepper")));  // 数値ステッパー
	TestCases.Add(FtestCase(TestTransformWidget, TEXT("TransformWidget"))); // 回転/スケールUI
	TestCases.Add(FtestCase(TestPasswordInput, TEXT("PasswordInput")));  // パスワード入力
	TestCases.Add(FtestCase(TestAudioControl, TEXT("AudioControl")));    // 音声再生UI
	TestCases.Add(FtestCase(TestVideoEmbed, TEXT("VideoEmbed")));        // ビデオ埋め込みUI
	TestCases.Add(FtestCase(TestTagSelector, TEXT("TagSelector")));      // タグ選択UI
	TestCases.Add(FtestCase(TestHeaderCollapse, TEXT("HeaderCollapse"))); // ヘッダーで折りたたみ
	TestCases.Add(FtestCase(TestFlexibleTable, TEXT("FlexibleTable")));  // 行数・カラム数変更可能テーブル
	TestCases.Add(FtestCase(TestLineGraph, TEXT("LineGraph")));			// 折れ線グラフ
	TestCases.Add(FtestCase(TestThemeToggle, TEXT("ThemeToggle")));      // テーマ切替（複数テーマ対応）
	TestCases.Add(FtestCase(TestCursorCustom, TEXT("CursorCustom")));    // マウスカーソルカスタマイズ
	TestCases.Add(FtestCase(TestRowSortControl, TEXT("RowSortControl"))); // 行の並び替え
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

    // サンプル画像をロードしてテクスチャとして登録
	FImGuiModule::Get().RegisterTexture("SampleTexture", SampleTexture);
	FImGuiModule::Get().RegisterTexture("ButtonTexture", ButtonTexture);
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

    // 登録したテクスチャを解除
	FImGuiTextureHandle TextureHandle = FImGuiModule::Get().FindTextureHandle("SampleTexture");
	FImGuiModule::Get().ReleaseTexture(TextureHandle);
	FImGuiTextureHandle ButtonTextureHandle = FImGuiModule::Get().FindTextureHandle("ButtonTexture");
	FImGuiModule::Get().ReleaseTexture(ButtonTextureHandle);
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