# ImGuiTester

ImGuiTesterは、UE5上でImGuiのテスト・流用を目的としたサンプルコード集です。

<img src="./Image/Top.png" width="640" height="360"/>


## 動作環境
- Unreal Engine 5.5.4
- VisualStudio 2022

### 使用しているImGuiについて
- [Unreal ImGuiプラグイン (benui-dev/UnrealImGui)：MIT License](https://github.com/benui-dev/UnrealImGui)  
  Unreal Engine 5 向けに Dear ImGui を統合するプラグイン。ImPlotなどの拡張にも対応。

- [Dear ImGui (Omar Cornut)：MIT License](https://github.com/ocornut/imgui)  
  軽量で移植性の高い即時モードGUIライブラリ。Unreal ImGuiはこのライブラリをUnreal Engineに対応させたもの。
 
## 主要ファイル
- `Source/ImGuiTester/Private/ImGuiActor.cpp`  
  ImGuiテスト用アクターの実装。サンプルコードは全てここに入っています。
- `Plugins/ImGui/`  
  ImGuiプラグイン本体。日本語化対応のため一部変更を加えています。

## サンプルコード解説
- タイトルリンクからサンプルコードの場所に移動できます。


<table>
  <tr>
    <td><img src="./Image/TestSimpleWindow.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L15-L31">No.1 ウィンドウ表示</a><br>
      <span style="font-size:small;color:#555;">一番単純なウィンドウを表示するだけの例です。</span><br>
      <span style="font-size:small;color:#555;">ウィンドウを１つ作成し、３行分のテキストを表示します。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestSimpleButton.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L38-L63">No.2 ボタン作成</a><br>
      <span style="font-size:small;color:#555;">単純なボタン配置の例です。</span><br>
      <span style="font-size:small;color:#555;">ウィンドウ１つにボタンを３つ配置、ボタンクリックで対応した値が変化します。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestShowText.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L69-L96">No.3 様々なテキスト表示</a><br>
      <span style="font-size:small;color:#555;">色変え等の特殊なテキストの例です。</span><br>
      <span style="font-size:small;color:#555;">変数の値埋め込み、グレーアウト、色指定のテキスト表示を行います。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestCheckBox.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L103-L127">No.4 チェックボックス</a><br>
      <span style="font-size:small;color:#555;">チェックボックス配置の例です。</span><br>
      <span style="font-size:small;color:#555;">チェックボックスを３つ配置、状態を変数で管理し、その状態表示。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestSlider.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L134-L159">No.5 スライダー</a><br>
      <span style="font-size:small;color:#555;">スライダー配置の例です。</span><br>
      <span style="font-size:small;color:#555;">スライダーを３つ配置、浮動小数版・整数版・度数版の三種類。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestComboBox.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L167-L191">No.6 コンボボックス</a><br>
      <span style="font-size:small;color:#555;">コンボボックス配置の例です。</span><br>
      <span style="font-size:small;color:#555;">3項目設定したコンボボックスを１つ配置。</span><br>
      <span style="font-size:small;color:#555;">補足、コンボボックスはプルダウン・ドロップダウンリストとも呼ばれる。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestShowImage.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L197-L212">No.7 テクスチャ表示</a><br>
      <span style="font-size:small;color:#555;">コンテンツブラウザの画像を参照して表示する例です。</span><br>
      <span style="font-size:small;color:#555;">外部データ利用にはFImGuiModuleが必要。詳細はAImGuiActor::BeginPlayを確認。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestInputField.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L219-L245">No.8 ラベル付き入力フィールド</a><br>
      <span style="font-size:small;color:#555;">ユーザー入力可能なテキストフィールドを表示する例です。</span><br>
      <span style="font-size:small;color:#555;">３つの入力フィールドを配置、通常・数字のみ・読み取り専用の３種類。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestSimpleTable.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L252-L292">No.9 テーブル</a><br>
      <span style="font-size:small;color:#555;">テーブル表示の例です。</span><br>
      <span style="font-size:small;color:#555;">3列5行のテーブルを作成し、各セルに行列番号を表示します。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestTreeNode.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L298-L331">No.10 ツリーノード</a><br>
      <span style="font-size:small;color:#555;">ツリーノード表示の例です。</span><br>
      <span style="font-size:small;color:#555;">親ツリーと２つの子ツリー配置。ツリーノードは階層的なデータ構造の表現が可能。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestShowTooltip.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L338-L359">No.11 ツールチップ表示</a><br>
      <span style="font-size:small;color:#555;">ツールチップを表示させる例です。</span><br>
      <span style="font-size:small;color:#555;">アイテムにマウスホバーでツールチップを表示。別名ポップアップヒント。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestColorPicker.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L366-L392">No.12 カラーピッカー</a><br>
      <span style="font-size:small;color:#555;">カラー選択メニューの例です。</span><br>
      <span style="font-size:small;color:#555;">RGBA各成分を調整可能なカラーピッカー・プレビュー表示を配置。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestProgressBar.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L399-L419">No.13 プログレスバー</a><br>
      <span style="font-size:small;color:#555;">プログレスバー表示の例です。</span><br>
      <span style="font-size:small;color:#555;">進捗率を表すプログレスバーを配置、進捗率は0.0〜1.0の範囲で指定。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestMenuBar.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L427-L465">No.14 メニューバー追加</a><br>
      <span style="font-size:small;color:#555;">ウィンドウにメニューバーを追加する例です。</span><br>
      <span style="font-size:small;color:#555;">ImGui::Beginにて、ImGuiWindowFlags_MenuBarを指定することでメニューバーを有効化。</span><br>
      <span style="font-size:small;color:#555;">メニューバーに「File」を追加し、その中に複数のアイテムを配置。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestTabWidget.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L472-L502">No.15 タブバー</a><br>
      <span style="font-size:small;color:#555;">タブ付きウィンドウを作成する例です。</span><br>
      <span style="font-size:small;color:#555;">タブバーを追加し２つのタブを配置。それぞれ内容を変化。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestStyleControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L510-L539">No.16 スタイル変更</a><br>
      <span style="font-size:small;color:#555;">ImGui内の様々なスタイルを変更する例です。</span><br>
      <span style="font-size:small;color:#555;">テキストカラーの変更を行います。他にも色々出来そうだが深追いしきれず…。要調査。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestFocusControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L547-L571">No.17 フォーカス制御</a><br>
      <span style="font-size:small;color:#555;">片方の入力フィールドを優先フォーカスする例です。</span><br>
      <span style="font-size:small;color:#555;">フォーカス関数は多々あるため、一番単純なキーボードのフォーカス制御を対応。</span><br>
      <span style="font-size:small;color:#555;">その他の応用的な制御は要調査。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestDragDrop.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L578-L627">No.18 ドラッグ&ドロップ</a><br>
      <span style="font-size:small;color:#555;">ドラッグ&ドロップの実装例です。</span><br>
      <span style="font-size:small;color:#555;">アイテムリストをドラッグ&ドロップで並び替え可能にしています。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestChildWindow.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L634-L656">No.19 子ウィンドウ作成</a><br>
      <span style="font-size:small;color:#555;">ウィンドウの中に子ウィンドウを作成する例です。</span><br>
      <span style="font-size:small;color:#555;">子ウィンドウはスクロール操作や、その中でUI要素を独立して管理できます。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestInputMonitor.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L663-L696">No.20 キーボード・マウス入力監視</a><br>
      <span style="font-size:small;color:#555;">入力状態を監視する例です。</span><br>
      <span style="font-size:small;color:#555;">マウス位置、ボタン状態、キー押下状態を取得し表示します。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestImageButton.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L703-L732">No.21 画像ボタン</a><br>
      <span style="font-size:small;color:#555;">画像付きボタンを配置する例です。</span><br>
      <span style="font-size:small;color:#555;">コンテンツブラウザの画像をテクスチャとして登録し、それをボタンに割り当てます。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestLayoutAdjust.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L739-L764">No.22 スペース調整</a><br>
      <span style="font-size:small;color:#555;">ウィンドウ内のスペース調整の例です。</span><br>
      <span style="font-size:small;color:#555;">縦横のスペース調整、同一ライン配置を行います。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestColumnLayout.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L771-L801">No.23 行や列を分割配置</a><br>
      <span style="font-size:small;color:#555;">カラムレイアウトの例です。</span><br>
      <span style="font-size:small;color:#555;">ウィンドウ内に3列レイアウトを作成し、各列にテキストを配置します。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestModalDialog.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L808-L845">No.24 モーダルダイアログ</a><br>
      <span style="font-size:small;color:#555;">ポップアップで出現するダイアログの例です。</span><br>
      <span style="font-size:small;color:#555;">ボタンを押すと優先フォーカスされたダイアログが表示されます。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestClipboard.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L852-L888">No.25 コピー&ペースト</a><br>
      <span style="font-size:small;color:#555;">クリップボードを利用したコピー&ペーストの例です。</span><br>
      <span style="font-size:small;color:#555;">入力フィールドの文字列をクリップボードにコピーします。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestHelpNote.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L895-L913">No.26 ユーザーガイド表示</a><br>
      <span style="font-size:small;color:#555;">ImGuiのユーザーガイドを表示する例です。</span><br>
      <span style="font-size:small;color:#555;">ヘルプメニューとして利用可能。ImGuiの基本的な操作方法が記載されています。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestZoomPan.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L921-L962">No.27 ズーム/パン操作</a><br>
      <span style="font-size:small;color:#555;">ズームとパン操作の例です。</span><br>
      <span style="font-size:small;color:#555;">マウスホイールでズームイン・ズームアウト、右ドラッグでパン操作が可能です。</span><br>
      <span style="font-size:small;color:#555;">描画領域に円を描画し、ズームとパンを反映します。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestCanvasDraw.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L969-L1010">No.28 キャンバス描画</a><br>
      <span style="font-size:small;color:#555;">ウィンドウ上にラインを描画する例です。</span><br>
      <span style="font-size:small;color:#555;">マウスクリックでポイントを追加し、ポイントを直線で結びます。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestScrollSync.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1017-L1068">No.29 スクロー位置操作</a><br>
      <span style="font-size:small;color:#555;">スクロール位置を直接設定する例です。</span><br>
      <span style="font-size:small;color:#555;">２つのChildウィンドウを横並びに配置し、スクロール位置を同期させます。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestFilterList.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1075-L1106">No.30 フィルタリングリスト</a><br>
      <span style="font-size:small;color:#555;">フィルタ操作可能なアイテムリストの例です。</span><br>
      <span style="font-size:small;color:#555;">テキスト入力でフィルタを指定し、マッチするアイテムのみ表示します。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestMultiSelectList.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1112-L1154">No.31 複数選択リストボックス</a><br>
      <span style="font-size:small;color:#555;">複数選択可能なリストボックスの例です。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestMultiLineInput.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1161-L1179">No.32 マルチライン入力</a><br>
      <span style="font-size:small;color:#555;">マルチラインテキスト入力フィールドの例です。</span><br>
      <span style="font-size:small;color:#555;">ImGui::InputTextMultilineを使用して複数行のテキスト入力を可能にします。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestNumberStepper.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1186-L1211">No.33 数値ステッパー</a><br>
      <span style="font-size:small;color:#555;">値を増減できる入力フィールドの例です。</span><br>
      <span style="font-size:small;color:#555;">＋－ボタン、マウスドラッグ型の入力フィールドを2種類配置します。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestTransformWidget.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1218-L1266">No.34 図形描画</a><br>
      <span style="font-size:small;color:#555;">回転とスケールを適用した四角形描画の例です。</span><br>
      <span style="font-size:small;color:#555;">スライダーで回転角度とスケールを調整し、四角形を変形して描画します。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestPasswordInput.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1273-L1292">No.35 パスワード入力</a><br>
      <span style="font-size:small;color:#555;">パスワード入力フィールドの例です。</span><br>
      <span style="font-size:small;color:#555;">入力内容を'*'で表示される入力フィールドを配置します。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestAudioControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1300-L1303">No.36 音声再生UI</a><br>
      <span style="font-size:small;color:#555;">残念ながらImGui自体に音声再生機能はない…。</span><br>
      <span style="font-size:small;color:#555;">音声再生する際はプラットフォーム側の再生機能を使用する必要があります。</span><br>
      <span style="font-size:small;color:#555;">ImGuiとUEのサウンド再生を組み合わせた例です。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestVideoEmbed.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1308-L1311">No.37 動画再生UI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestTagSelector.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1318-L1358">No.38 タグ選択風UI</a><br>
      <span style="font-size:small;color:#555;">SmallButtonを利用したタグ選択風UIの例です。</span><br>
      <span style="font-size:small;color:#555;">複数のタグボタンを配置し、選択状態をトグルで判定しています。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestHeaderCollapse.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1365-L1389">No.39 ヘッダーで折りたたみ</a><br>
      <span style="font-size:small;color:#555;">折りたたみ可能なブロックを配置する例です。</span><br>
      <span style="font-size:small;color:#555;">ヘッダー部分をクリックすると内容が展開・折りたたまれます。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestFlexibleTable.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1396-L1438">No.40 行数・カラム数変更可能テーブル</a><br>
      <span style="font-size:small;color:#555;">ImGuiのテーブル機能を応用した例です。</span><br>
      <span style="font-size:small;color:#555;">スライダーで行数・カラム数を動的に変更し、テーブルの内容を更新します。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestLineGraph.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1445-L1485">No.41 折れ線グラフ</a><br>
      <span style="font-size:small;color:#555;">ImDrawListを使ってウィンドウ内に折れ線グラフを描画します。</span><br>
      <span style="font-size:small;color:#555;">カスタム描画の工夫によりグラフを実現しています。グラフ機能が存在するわけではありません。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestThemeToggle.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1492-L1533">No.42 テーマ切替</a><br>
      <span style="font-size:small;color:#555;">テーマ切り替え用メソッドのテストです。</span><br>
      <span style="font-size:small;color:#555;">ダーク・ライト・クラシック・カスタムテーマの4種類への切り替えを行います。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestCursorCustom.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1541-L1567">No.43 マウスカーソルカスタマイズ</a><br>
      <span style="font-size:small;color:#555;">マウスカーソルの形を変更する方法の例です。</span><br>
      <span style="font-size:small;color:#555;">ホバー時は左右リサイズ用のカーソル、通常時は矢印カーソルを表示します。</span><br>
      <span style="font-size:small;color:#555;">ImGui::SetMouseCursor()によりカーソル形状を変更しています。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestRowSortControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1575-L1644">No.44 行の並び替え</a><br>
      <span style="font-size:small;color:#555;">テーブルソート機能を利用したシンプルなサンプル。</span><br>
      <span style="font-size:small;color:#555;">ソート可能なテーブルで行データ（ID・名前・値）を表示します。</span><br>
      <span style="font-size:small;color:#555;">ヘッダークリックで昇順・降順の並び替えができます。</span><br>
    </td>
  </tr>
</table>

## ライセンス
This project is licensed under the MIT License. See the LICENSE file for details.

