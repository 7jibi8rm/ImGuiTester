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
		ImGui::Begin("TestSimpleWindowテスト");

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
		// 初回のみウィンドウサイズを100x100に設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(100, 100), ImGuiCond_Once);

		// "Button Window" というタイトルのウィンドウを開始します。
		ImGui::Begin("TestSimpleButton");

		// ボタンを表示し、押された場合はテキストを表示します。
		if (ImGui::Button("ButtonA")){
			// ボタンが押されたときのみ表示されるテキスト（一瞬）
			ImGui::Text("ButtonA was clicked!");
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
        // チェックボックスの状態を保持する変数
		static bool isChecked;

        // 初回のみウィンドウサイズを150x70に設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(150, 70), ImGuiCond_Once);

        // "TestCheckBox" というタイトルのウィンドウを開始します。
		ImGui::Begin("TestCheckBox");

        // チェックボックスを表示し、状態をisChecked変数で管理します。
		ImGui::Checkbox("Checkbox!", &isChecked);
		if (isChecked) {
			ImGui::Text("Checked!!!!");
		}

		// ウィンドウの描画を終了します。
		ImGui::End(); 
		return;
	}

	/// <summary>
	/// スライダーを操作する
	/// </summary>
	void TestFloatSlider()
	{
		static float SliderValue = 0.0f;

		// 初回のみウィンドウサイズを220x100に設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(220, 100), ImGuiCond_Once);

		// "Sample Window" というタイトルのウィンドウを開始します。
		ImGui::Begin("TestFloatSlider");

        // スライダーを表示し、値を0.0から100.0の範囲で調整します。
		ImGui::SliderFloat("Slider", &SliderValue, 0.0f, 100.0f);

		// 整数値を埋め込んだテキストを表示します。
		ImGui::Text("SliderValue: %f", SliderValue);

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// コンボボックスを作成
	/// </summary>
	void TestComboBox()
	{
        // コンボボックスの選択状態を保持する変数
		static int ComboBoxValue = 0;

        // コンボボックスアイテムを定義します。
		const char* items[] = { "Apple", "Banana", "Cherry" };

		// 初回のみウィンドウサイズを220x100に設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiCond_Once);

		// ウィンドウの描画を開始します。
		ImGui::Begin("TestComboBox");

        // コンボボックスを表示し、選択されたアイテムのインデックスをComboBoxValueで管理します。
		if (ImGui::Combo("Fruits", &ComboBoxValue, items, IM_ARRAYSIZE(items)))
		{
            // コンボボックスの選択が変更された場合、選択されたアイテムのインデックスをログに出力します。
			UE_LOG(LogTemp, Log, TEXT("ComboBoxValue: %d"), ComboBoxValue);
		}

		// ウィンドウの描画を終了します。
		ImGui::End();
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

		static char InputText[128] = "default";

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 70), ImGuiCond_Once);

		// ウィンドウの描画を開始します。
		ImGui::Begin("TestInputField");

        // 入力フィールドを表示します。ユーザーがテキストを入力できるようになります。
		ImGui::InputText("Label", InputText, IM_ARRAYSIZE(InputText));

		// 整数値を埋め込んだテキストを表示します。
		ImGui::Text("Text: %s", InputText);

		// ウィンドウの描画を終了します。
		ImGui::End();

		return;
	}

	/// <summary>
	/// テーブルを表示する
	/// </summary>
	void TestSimpleTable()
	{
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_Once);

		// ウィンドウの描画を開始します。
		ImGui::Begin("TestSimpleTable");

        // テーブルを開始します。3列のテーブルで、境界線と行背景を有効にしています。
		if (ImGui::BeginTable("Table1", 3, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg))
		{
            // テーブルの列を設定します。ここでは3つの列を定義しています。
			ImGui::TableSetupColumn("COL 1");
			ImGui::TableSetupColumn("COL 2");
			ImGui::TableSetupColumn("COL 3");

            // テーブルのヘッダー行を描画します。
			ImGui::TableHeadersRow();

            // テーブルの行をループして、各セルにテキストを表示します。
			for (int row = 0; row < 5; ++row)
			{
                // 新しい行を開始します。
				ImGui::TableNextRow();

                // 各列にテキストを表示します。
				for (int column = 0; column < 3; ++column)
				{
                    // 列を設定し、テキストを表示します。
					ImGui::TableSetColumnIndex(column);
					ImGui::Text("%d-%d", row, column);
				}
			}

            // テーブルの描画を終了します。
			ImGui::EndTable();
		}

		// ウィンドウの描画を終了します。
		ImGui::End();

		return;
	}

	/// <summary>
	/// ツリーノードを作成
	/// </summary>
	void TestTreeNode()
	{
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(150, 150), ImGuiCond_Once);

		// ウィンドウの描画を開始します。
		ImGui::Begin("TestSimpleTable");

        // ツリーノードを作成します。ツリーノードは階層的なデータ構造を表現するために使用されます。
		if (ImGui::TreeNode("Root Node"))
		{
            // ツリーノードの子ノードを作成します。ここでは2つの子ノードを持つ例です。
			if (ImGui::TreeNode("Child Node A"))
			{
                // 子ノード内にテキストを表示します。
				ImGui::BulletText("Text");
                // 子ノードの描画を終了します。
				ImGui::TreePop();
			}

            // もう1つの子ノードを作成します。
			if (ImGui::TreeNode("Child Node B"))
			{
                // 子ノード内にテキストを表示します。
				ImGui::BulletText("Text");
                // 子ノードの描画を終了します。
				ImGui::TreePop();
            }

            // ツリーノードの描画を終了します。
			ImGui::TreePop();
		}

		// ウィンドウの描画を終了します。
		ImGui::End();

		return;
	}

	/// <summary>
	/// ツールチップを表示
	/// </summary>
	void TestShowTooltip()
	{
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(150, 75), ImGuiCond_Once);

		// ウィンドウの描画を開始します。
		ImGui::Begin("TestShowTooltip");

		// 何らかのアイテムを表示（例：テキスト）
		ImGui::Text("Hover over me");

		// マウスがこのアイテムにホバーされているか判定してツールチップを表示
		if (ImGui::IsItemHovered())
		{
			ImGui::SetTooltip("This is a tooltip");
		}

		// ウィンドウの描画を終了します。
		ImGui::End();

		return;
	}

	/// <summary>
	/// カラー選択ダイアログを表示
	/// </summary>
	void TestColorPicker()
	{

		// カラーを保存する変数
		static ImVec4 color = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(350, 100), ImGuiCond_Once);

		// ImGuiウィンドウ開始
		ImGui::Begin("TestColorPicker");

		// 色の選択ウィジェット。colorの内容がユーザー操作で変更される
		ImGui::ColorEdit4("RGBA", (float*)&color);

        // 選択された色の値を表示
		ImGui::Text("SelectColor - R: %.2f, G: %.2f, B: %.2f, A: %.2f", color.x, color.y, color.z, color.w);

        // ウィンドウの描画を終了します。	
		ImGui::End();
		return;
	}

	/// <summary>
	/// プログレスバーを表示
	/// </summary>
	void TestProgressBar()
	{
        static float fraction = 0.7f;

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(350, 100), ImGuiCond_Once);

		// ImGuiウィンドウ開始
		ImGui::Begin("TestProgressBar");

		// プログレスバーの表示。fractionは0.0(0%)〜1.0(100%)の範囲で進捗を表す
		ImGui::ProgressBar(fraction, ImVec2(0.0f, 0.0f)); // サイズ(0,0)は自動的に幅いっぱいで高さは規定値

		// 進捗率をテキスト表示（%表記）
		ImGui::Text("Progress: %.1f%%", fraction * 100.0f);

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// メニューバーを作成する
	/// </summary>
	void TestMenuBar()
	{
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ImGuiウィンドウ開始
		ImGui::Begin("TestMenuBar", nullptr, ImGuiWindowFlags_MenuBar);

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

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// タブを作成する
	/// </summary>
	void TestTabWidget()
	{
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

        // ImGuiウィンドウ開始
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

		// ウィンドウの描画を終了します。
		ImGui::End();
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
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(100, 100), ImGuiCond_Once);

		// ImGuiウィンドウ開始
		ImGui::Begin("TestStyleControl");

		// ImGuiのスタイルを変更するための関数です。
		ImGuiStyle& style = ImGui::GetStyle();

        // スタイルの色を取得します。
        const ImVec4 styleColor = style.Colors[ImGuiCol_Text];

        // スタイルの色を変更します。
		style.Colors[ImGuiCol_Text] = ImVec4(1.0f, 0.5f, 0.5f, 1.0f); 
		ImGui::Text("Text A");
		style.Colors[ImGuiCol_Text] = ImVec4(0.5f, 1.0f, 0.5f, 1.0f);
		ImGui::Text("Text B");
		style.Colors[ImGuiCol_Text] = ImVec4(0.5f, 0.5f, 1.0f, 1.0f);
		ImGui::Text("Text C");

        // スタイルの色を元に戻します。
		style.Colors[ImGuiCol_Text] = styleColor;

		// ウィンドウの描画を終了します。
		ImGui::End();

		return;
	}

	/// <summary>
	/// フォーカス制御
	/// </summary>
	void TestFocusControl()
	{
		static char buf1[128] = "First";
		static char buf2[128] = "Second";

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 100), ImGuiCond_Once);

		// ImGuiウィンドウ開始
		ImGui::Begin("TestFocusControl");

        // 1つ目の入力フィールドを作成します。
		ImGui::InputText("First", buf1, 128);

        // 1つ目の入力フィールドがフォーカスされている場合、次のInputTextにフォーカスを移動します。
		ImGui::SetKeyboardFocusHere();

        // 2つ目の入力フィールドを作成します。
		ImGui::InputText("Second", buf2, 128);

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// ドラッグ&ドロップを実装する
	/// </summary>
	void TestDragDrop()
	{
        // ドラッグ&ドロップのテスト用のアイテムリスト
		static std::vector<std::string> items = { "Item 1", "Item 2", "Item 3", "Item 4" };

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(150, 200), ImGuiCond_Once);

        // ImGuiウィンドウ開始
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

        // ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// 子ウィンドウ・領域を作る
	/// </summary>
	void TestChildWindow()
	{
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(220, 170), ImGuiCond_Once);

        // 親ウィンドウを開始します。
		ImGui::Begin("TestChildWindow");

		// 子ウィンドウ開始（サイズは (width=200, height=150)）
		ImGui::BeginChild("ChildWindowID", ImVec2(200, 150), true); // 第3引数はボーダー表示の有無

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
	/// 入力状態を監視
	/// </summary>
	void TestInputMonitor()
	{
		ImGuiIO& io = ImGui::GetIO();

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(250, 170), ImGuiCond_Once);

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

		// ウィンドウの描画を終了します。
		ImGui::End();
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
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(250, 170), ImGuiCond_Once);

		// ウィンドウを開始します。
		ImGui::Begin("TestLayoutAdjust");


		// 縦のスペース調整
		ImGui::Text("Text above spacing");
		ImGui::Spacing();  // 標準スペース
		ImGui::Dummy(ImVec2(0.0f, 20.0f));  // 20pxの空白
		ImGui::Text("Text below custom spacing");

		// 横のスペース調整
		ImGui::Button("Button A");
		ImGui::SameLine(150, 10);  // 150pxから開始、10pxの間隔を空ける
		ImGui::Button("Button B");

		// 親ウィンドウ終了
		ImGui::End();
		return;
	}

	/// <summary>
	/// 行や列を分割配置
	/// </summary>
	void TestColumnLayout()
	{
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

		// ウィンドウを開始します。
		ImGui::Begin("TestColumnLayout");

        // 3列レイアウトを開始します。
		ImGui::Columns(3, nullptr, false);

        // 各列にテキストを表示します。
		ImGui::Text("Column 1");
		ImGui::NextColumn();
		ImGui::Text("Column 2");
		ImGui::NextColumn();
		ImGui::Text("Column 3");

		// 列終了（元に戻す）
		ImGui::Columns(1);

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// モーダルダイアログを表示
	/// </summary>
	void TestModalDialog()
	{
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(150, 65), ImGuiCond_Once);

		// ウィンドウを開始します。
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
			ImGui::Text("Are you sure you want to continue?");

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

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// ウィンドウの位置・サイズ固定
	/// </summary>
	void TestWindowPosition()
	{
        // ウィンドウ位置を(100,100)に固定（ImGuiCond_Alwaysで毎フレーム適用）    
		ImGui::SetNextWindowPos(ImVec2(100, 100), ImGuiCond_Always);

        // ウィンドウサイズを(400,300)に固定（ImGuiCond_Alwaysで毎フレーム適用）
		ImGui::SetNextWindowSize(ImVec2(400, 300), ImGuiCond_Always);

        // ウィンドウを開始します。リサイズと移動を禁止するフラグを指定。
		ImGui::Begin("TestWindowPosition", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

        // 固定位置・サイズの説明テキスト
		ImGui::Text("This window has fixed position and size.");

        // ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// データをコピー&ペースト
	/// </summary>
	void TestClipboard()
	{
		static char buf[256] = "";

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 70), ImGuiCond_Once);

		// ウィンドウ開始
		ImGui::Begin("TestClipboard");

		// テキスト入力
		ImGui::InputText("Input", buf, sizeof(buf));

		// コピー ボタンが押されたらクリップボードにテキストをセット
		if (ImGui::Button("Copy"))
		{
			ImGui::SetClipboardText(buf);
		}

		// ペースト ボタンが押されたらクリップボードからテキストを取得してバッファにセット
		if (ImGui::Button("Paste"))
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

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// ノートやヘルプウィンドウ
	/// </summary>
	void TestHelpNote()
	{
		static bool show_help = true;

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(500, 400), ImGuiCond_Once);

		// ウィンドウを開始します。
		ImGui::Begin("TestHelpNote");

        // ImGuiのユーザーガイドを表示します。
		ImGui::ShowUserGuide();

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// ズーム/パン操作
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

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(300, 300), ImGuiCond_Once);

		// ウィンドウを開始します。
		ImGui::Begin("TestHelpNote");

        // ズームとパンの情報を表示
		ImGui::Text("Zoom: %.2f Pan: (%.1f, %.1f)", zoom, pan.x, pan.y);

        // 描画領域の開始位置を取得
		ImVec2 p = ImGui::GetCursorScreenPos();

        // 描画リストを取得
		ImDrawList* dl = ImGui::GetWindowDrawList();

        // ズームとパンを反映した円を描画
		dl->AddCircleFilled(ImVec2(p.x + pan.x, p.y + pan.y), 50 * zoom, IM_COL32(255, 0, 0, 255));

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// 順序入替リストボックス
	/// </summary>
	void TestReorderListBox()
	{
        // ドラッグ&ドロップで順序を入れ替え可能なリストボックスの例
		static std::vector<std::string> items = { "Item 1", "Item 2", "Item 3", "Item 4" };
		static int dragged_item = -1;

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(100, 100), ImGuiCond_Once);

		// ウィンドウを開始します。
		ImGui::Begin("TestReorderListBox");

        // リストボックス内の各アイテムを表示
		for (int i = 0; i < items.size(); i++) 
		{
            // アイテムを選択可能なリストとして表示
			ImGui::Selectable(items[i].c_str());

            // ドラッグ開始判定
			if (ImGui::IsItemActive() && ImGui::IsMouseDragging(0)) {
                dragged_item = i; // ドラッグ中のアイテムインデックスを保存
			}

			// ドロップ位置判定
			if (dragged_item >= 0 && dragged_item != i && ImGui::IsItemHovered())
 {
                // ここにドロップされた場合の処理
				if (ImGui::IsMouseReleased(0)) {
                    std::swap(items[dragged_item], items[i]); // アイテムの順序を入れ替え
                    dragged_item = -1; // ドラッグ状態をリセット
				}
			}
		}

        // ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// キャンバス描画
	/// </summary>
	void TestCanvasDraw()
	{
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

        // ImGuiウィンドウ開始
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

        // ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// スクロール同期
	/// </summary>
	void TestScrollSync()
	{
		static float synced_scroll = 0.0f; // 同期するスクロール位置

        // ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
        ImGui::SetNextWindowSize(ImVec2(450, 200), ImGuiCond_Once);

        // ウィンドウ開始
		ImGui::Begin("TestScrollSync");

        // Child 1
		{
            // Childウィンドウ開始（サイズは (width=200, height=150)）
			ImGui::BeginChild("Child1", ImVec2(200, 150), true, ImGuiWindowFlags_HorizontalScrollbar);
			for (int i = 0; i < 100; i++){
				ImGui::Text("Item %d", i);
			}
			// フォーカスまたはホバーされている場合、スクロール位置を取得
			if (ImGui::IsWindowFocused() || ImGui::IsWindowHovered()){
				synced_scroll = ImGui::GetScrollY();             // スクロール位置取得
			}
			else{
				ImGui::SetScrollY(synced_scroll);                // 他方の値に合わせる
			}
            // Childウィンドウ終了	
			ImGui::EndChild();
		}

        // 同じラインに配置
		ImGui::SameLine();

		// Child 2
		{
            // Childウィンドウ開始（サイズは (width=200, height=150)）
			ImGui::BeginChild("Child2", ImVec2(200, 150), true, ImGuiWindowFlags_HorizontalScrollbar);
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
	/// タイムライン（進捗付きバー）
	/// </summary>
	void TestTimelineBar()
	{
		// 進捗バーを描画するシンプルな例
		static float progress = 0.0f;

        // ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
        ImGui::SetNextWindowSize(ImVec2(250, 100), ImGuiCond_Once);

        // ウィンドウを開始します。
        ImGui::Begin("TestTimelineBar");

		// 毎フレームで進捗を更新（例として時間経過でループ）
		progress += 0.01f;
		if (progress > 1.0f) progress = 0.0f;

        // 進捗バーを表示
		ImGui::Text("Timeline Progress Bar Example");
		ImGui::ProgressBar(progress, ImVec2(200, 20), "Progress");
		ImGui::Text("Progress: %.1f%%", progress * 100.0f);

        // ウィンドウの描画を終了します。
        ImGui::End();
		return;
	}

	/// <summary>
	/// フィルタリングリスト
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

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 250), ImGuiCond_Once);

		// ウィンドウを開始します。
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

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// 複数選択リストボックス
	/// </summary>
	void TestMultiSelectList()
	{
        // 選択肢の配列
		static const char* items[] = { "Item 1", "Item 2", "Item 3", "Item 4", "Item 5" };
		// 選択中のインデックス
		static ImVector<int> selected_indices;

        // ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
        ImGui::SetNextWindowSize(ImVec2(150, 200), ImGuiCond_Once);

        // ウィンドウを開始します。
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

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// マルチライン入力
	/// </summary>
	void TestMultiLineInput()
	{
		static char buf[1024] = "default text";

        // ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
        ImGui::SetNextWindowSize(ImVec2(450, 300), ImGuiCond_Once);

        // ウィンドウを開始します。
        ImGui::Begin("TestMultiLineInput");

        // マルチラインテキスト入力フィールドを表示
		ImGui::InputTextMultiline("##multiline", buf, IM_ARRAYSIZE(buf),ImVec2(400, 200), ImGuiInputTextFlags_None);

		// ウィンドウの描画を終了します。
		ImGui::End();

		return;

	}

	/// <summary>
	/// 数値ステッパー
	/// </summary>
	void TestNumberStepper()
	{
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 150), ImGuiCond_Once);

		// ウィンドウを開始します。
		ImGui::Begin("TestNumberStepper");

		// ステップサイズ付きInputInt（+-ボタン付き）
		static int stepValue = 0;
		ImGui::InputInt("Step Int", &stepValue, 1, 10);

		// マウスドラッグで値を増減
		static int dragValue = 50;
		ImGui::DragInt("Drag Int", &dragValue, 1.0f, 0, 100);

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// 色変更UI
	/// </summary>
	void TestColorEdit()
	{
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 150), ImGuiCond_Once);

		// ウィンドウを開始します。
		ImGui::Begin("TestColorEdit");

		// RGBカラーの編集（アルファなし）
		static float color[3] = { 1.0f, 0.0f, 0.0f };  // 初期色：赤
		ImGui::ColorEdit3("Color", color);

		// RGBAカラーの編集（アルファあり）
		static float colorAlpha[4] = { 0.0f, 1.0f, 0.0f, 1.0f };  // 初期色：緑、不透明
		ImGui::ColorEdit4("Color with Alpha", colorAlpha);

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// キャンセル操作
	/// </summary>
	void TestCancelDialog()
	{
		// 没
		return;
	}

	/// <summary>
	/// 回転/スケールUI
	/// </summary>
	void TestTransformWidget()
	{
		static float angle = 0.0f;
		static float scale = 1.0f;

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(400, 400), ImGuiCond_Once);

        // ウィンドウを開始します。
		ImGui::Begin("TestTransformWidget");

		ImGui::SliderFloat("Angle", &angle, 0.0f, 360.0f);
		ImGui::SliderFloat("Scale", &scale, 0.1f, 3.0f);

		ImVec2 center = ImGui::GetCursorScreenPos();
		ImVec2 size = ImVec2(100 * scale, 100 * scale);

		// 中心位置を画面内にオフセットして調整
		center.x += 150;
		center.y += 100;

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
	/// </summary>
	void TestPasswordInput()
	{
		static char password[64] = ""; // パスワード入力用バッファ

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

        // ウィンドウを開始します。
		ImGui::Begin("TestPasswordInput");

        // パスワード入力フィールド（入力内容は'*'で表示）
		ImGui::InputText("Password", password, sizeof(password), ImGuiInputTextFlags_Password);

        // 入力されたパスワードを表示（デバッグ用、実際は安全管理に注意）
		ImGui::Text("You entered: %s", password); // デバッグ用表示（実際は安全管理に注意）

        // ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// ホバー時詳細情報
	/// </summary>
	void TestOnHoverDetail()
	{
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(200, 200), ImGuiCond_Once);

        // ウィンドウを開始します。
		ImGui::Begin("TestOnHoverDetail");

        // 説明テキスト
		ImGui::Text("ホバーしてください");

        // ホバー対象のUI要素（例：ボタン）
		if (ImGui::IsItemHovered())
		{
			ImGui::TextColored(ImVec4(1, 1, 0, 1), "詳細情報:");
			ImGui::BulletText("項目1の説明");
			ImGui::BulletText("項目2の説明");
		}

        // ウィンドウの描画を終了します。
		ImGui::End();

		return;
	}

	/// <summary>
	/// 物理スライダー操作
	/// </summary>
	void TestDragSlider()
	{
		static float value = 0.5f; // スライダーの制御変数

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(250, 100), ImGuiCond_Once);

        // ウィンドウを開始します。
		ImGui::Begin("TestDragSlider");

		// DragFloat : ラベル、変数へのポインタ、ドラッグ速度、最小値、最大値
		ImGui::DragFloat("Drag Float", &value, 0.01f, 0.0f, 1.0f);

		// 現在の値を表示
		ImGui::Text("Current Value: %.3f", value);

        // ウィンドウの描画を終了します。
		ImGui::End();
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
	/// タグ選択UI
	/// </summary>
	void TestTagSelector()
	{
		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(250, 100), ImGuiCond_Once);

		// ウィンドウを開始します。
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
			// 選択されているボタンに色を付ける例
			if (selected[i]) {
				ImGui::SameLine();
				ImGui::TextColored(ImVec4(0, 1, 0, 1), "[Selected]");
			}
			// ボタン間にスペースを入れる
			ImGui::SameLine();
		}
		ImGui::NewLine();

		// 選択されたタグを表示
		ImGui::Text("Selected Tags:");
		for (int i = 0; i < numTags; ++i) {
			if (selected[i]) {
				ImGui::Text("%s", tags[i]);
			}
		}

		// ウィンドウの描画を終了します。
		ImGui::End();

		return;
	}

	/// <summary>
	/// ヘッダーで折りたたみ
	/// </summary>
	void TestHeaderCollapse()
	{
		// 折りたたみヘッダーの状態を保持するbool変数
		static bool open = true;

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(250, 150), ImGuiCond_Once);

		// ウィンドウを開始します。
		ImGui::Begin("TestHeaderCollapse");

		// CollapsingHeader: 折りたたみ可能なヘッダーを作成
		if (ImGui::CollapsingHeader("折りたたみヘッダー"))
		{
			// ヘッダーが開かれている時だけ表示される内容
			ImGui::Text("ここに折りたたみ内部の内容を記述します。");
			ImGui::Button("ボタン");
		}

		// ウィンドウの描画を終了します。
		ImGui::End();
		return;
	}

	/// <summary>
	/// 行数・カラム数変更可能テーブル
	/// </summary>
	void TestFlexibleTable()
	{
		// 動的に変える行数・カラム数（内部変数）
		static int rows = 5;
		static int columns = 3;

		// ウィンドウサイズを設定します（ImGuiCond_Onceで一度だけ適用）。
		ImGui::SetNextWindowSize(ImVec2(400, 400), ImGuiCond_Once);

		// ウィンドウを開始します。
		ImGui::Begin("TestHeaderCollapse");

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

        // ウィンドウの描画を終了します。
        ImGui::End();
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
	TestCases.Add(FtestCase(TestSimpleWindow, TEXT("SimpleWindow")));    // ウィンドウを作成する
	TestCases.Add(FtestCase(TestSimpleButton, TEXT("SimpleButton")));    // ボタンを表示する
	TestCases.Add(FtestCase(TestShowText, TEXT("ShowText")));            // テキストを表示する
	TestCases.Add(FtestCase(TestCheckBox, TEXT("CheckBox")));            // チェックボックスを作成する
	TestCases.Add(FtestCase(TestFloatSlider, TEXT("FloatSlider")));      // スライダーを操作する
	TestCases.Add(FtestCase(TestComboBox, TEXT("ComboBox")));            // ドロップダウンリストを作成
	///TestCases.Add(FtestCase(TestShowImage, TEXT("ShowImage")));          // 画像を表示する
	TestCases.Add(FtestCase(TestInputField, TEXT("InputField")));        // ラベル付き入力フィールド
	TestCases.Add(FtestCase(TestSimpleTable, TEXT("SimpleTable")));      // テーブルを表示する
	///TestCases.Add(FtestCase(TestListBox, TEXT("ListBox")));              // リストボックスを作成
	TestCases.Add(FtestCase(TestTreeNode, TEXT("TreeNode")));            // ツリーノードを作成
	TestCases.Add(FtestCase(TestShowTooltip, TEXT("ShowTooltip")));      // ツールチップを表示
	TestCases.Add(FtestCase(TestColorPicker, TEXT("ColorPicker")));      // カラー選択ダイアログを表示
	TestCases.Add(FtestCase(TestProgressBar, TEXT("ProgressBar")));      // プログレスバーを表示
	TestCases.Add(FtestCase(TestMenuBar, TEXT("MenuBar")));              // メニューを作成する
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
	TestCases.Add(FtestCase(TestWindowPosition, TEXT("WindowPosition"))); // ウィンドウの位置・サイズ固定
	TestCases.Add(FtestCase(TestClipboard, TEXT("Clipboard")));          // データをコピー&ペースト
	TestCases.Add(FtestCase(TestHelpNote, TEXT("HelpNote")));            // ノートやヘルプウィンドウ
	TestCases.Add(FtestCase(TestZoomPan, TEXT("ZoomPan")));              // ズーム/パン操作
	TestCases.Add(FtestCase(TestReorderListBox, TEXT("ReorderListBox"))); // 順序入替リストボックス
	TestCases.Add(FtestCase(TestCanvasDraw, TEXT("CanvasDraw")));        // キャンバス描画
	TestCases.Add(FtestCase(TestScrollSync, TEXT("ScrollSync")));        // スクロール同期
	TestCases.Add(FtestCase(TestTimelineBar, TEXT("TimelineBar")));      // タイムライン（進捗付きバー）
	TestCases.Add(FtestCase(TestFilterList, TEXT("FilterList")));        // フィルタリングリスト
	TestCases.Add(FtestCase(TestMultiSelectList, TEXT("MultiSelectList"))); // 複数選択リストボックス
	TestCases.Add(FtestCase(TestMultiLineInput, TEXT("MultiLineInput"))); // マルチライン入力
	TestCases.Add(FtestCase(TestNumberStepper, TEXT("NumberStepper")));  // 数値ステッパー
	TestCases.Add(FtestCase(TestColorEdit, TEXT("ColorEdit")));          // 色変更UI
	TestCases.Add(FtestCase(TestCancelDialog, TEXT("CancelDialog")));    // キャンセル操作
	TestCases.Add(FtestCase(TestTransformWidget, TEXT("TransformWidget"))); // 回転/スケールUI
	TestCases.Add(FtestCase(TestPasswordInput, TEXT("PasswordInput")));  // パスワード入力
	TestCases.Add(FtestCase(TestOnHoverDetail, TEXT("OnHoverDetail")));  // ホバー時詳細情報
	TestCases.Add(FtestCase(TestDragSlider, TEXT("DragSlider")));        // 物理スライダー操作
	TestCases.Add(FtestCase(TestAudioControl, TEXT("AudioControl")));    // 音声再生UI
	TestCases.Add(FtestCase(TestVideoEmbed, TEXT("VideoEmbed")));        // ビデオ埋め込みUI
	TestCases.Add(FtestCase(TestTagSelector, TEXT("TagSelector")));      // タグ選択UI
	TestCases.Add(FtestCase(TestHeaderCollapse, TEXT("HeaderCollapse"))); // ヘッダーで折りたたみ
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