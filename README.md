# ImGuiTester

## 概要
ImGuiTesterは、Unreal Engine 5プロジェクト上で[Dear ImGui](https://github.com/ocornut/imgui)のテスト・デモ表示するためのサンプルプロジェクトです。  
ImGuiの描画・入力制御をUE5アクター経由で行い、ウィンドウ・子ウィンドウ・各種フラグの動作確認ができます。

## 主な機能
- ImGuiウィンドウの表示・制御
- Begin/Endによるウィンドウ作成テスト
- BeginChild/EndChildによる子ウィンドウテスト
- ImGuiWindowFlagsの各種フラグ動作確認
- テストケースのON/OFF切り替えUI

## 対応環境
- Unreal Engine 5.5 以降
- Visual Studio 2022

## インストール方法
1. UE5プロジェクトの`Plugins`フォルダにImGuiプラグインを配置してください。
2. 本プロジェクトのソースを`Source/ImGuiTester`に配置します。
3. UE5エディタでプロジェクトを開き、C++ビルドを実行してください。

## 使い方
1. エディタまたはゲーム内で`AImGuiActor`をレベルに配置します。
2. 実行すると「TestMenu」ウィンドウが表示され、各テストケースのON/OFFボタンが操作できます。
3. 有効化したテストケースのウィンドウがImGui上に表示されます。

## 主要ファイル
- `Source/ImGuiTester/Private/ImGuiActor.cpp`  
  ImGuiテスト用アクターの実装
- `Source/ImGuiTester/Public/ImGuiActor.h`  
  ImGuiテスト用アクターのヘッダ
- `Plugins/ImGui/`  
  Dear ImGuiプラグイン本体

## 備考
- ImGuiプラグインの導入・設定方法は各プラグインのREADMEを参照してください。
- UE5のバージョンやプラグインの互換性にご注意ください。

### 目次

<table>
  <tr>
    <td><img src="./Image/TestSimpleWindow.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L16-L32">No.1 ウィンドウ表示</a><br>
      <span style="font-size:small;color:#555;">一番単純なウィンドウを表示するだけの例です。</span><br>
      <span style="font-size:small;color:#555;">ウィンドウを１つ作成し、３行分のテキストを表示します。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestSimpleButton.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L39-L64">No.2 ボタン作成</a><br>
      <span style="font-size:small;color:#555;">単純なボタン配置の例です。</span><br>
      <span style="font-size:small;color:#555;">ウィンドウ１つにボタンを３つ配置、ボタンクリックで対応した値が変化します。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestShowText.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L71-L98">No.3 様々なテキスト表示。</a><br>
      <span style="font-size:small;color:#555;">色変え等の特殊なテキストの例です。</span><br>
      <span style="font-size:small;color:#555;">変数の値埋め込み、グレーアウト、色指定のテキスト表示を行います。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestCheckBox.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L105-L129">No.4 チェックボックス</a><br>
      <span style="font-size:small;color:#555;">チェックボックス配置の例です。</span><br>
      <span style="font-size:small;color:#555;">チェックボックスを３つ配置、状態を変数で管理し、その状態表示。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestSlider.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L136-L161">No.5 スライダー</a><br>
      <span style="font-size:small;color:#555;">スライダー配置の例です。</span><br>
      <span style="font-size:small;color:#555;">スライダーを３つ配置、浮動小数版・整数版・度数版の三種類。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestComboBox.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L169-L193">No.6 コンボボックス</a><br>
      <span style="font-size:small;color:#555;">コンボボックス配置の例です。</span><br>
      <span style="font-size:small;color:#555;">3項目設定したコンボボックスを１つ配置。</span><br>
      <span style="font-size:small;color:#555;">補足、コンボボックスはプルダウン・ドロップダウンリストとも呼ばれる。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestShowImage.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L198-L201">No.7 画像を表示する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestInputField.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L206-L227">No.8 ラベル付き入力フィールド</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestSimpleTable.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L232-L274">No.9 テーブルを表示する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestTreeNode.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L279-L316">No.10 ツリーノードを作成</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestShowTooltip.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L321-L342">No.11 ツールチップを表示</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestColorPicker.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L347-L368">No.12 カラー選択ダイアログを表示</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestProgressBar.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L373-L392">No.13 プログレスバーを表示</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestMenuBar.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L397-L435">No.14 メニューバーを作成する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestTabWidget.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L440-L470">No.15 タブを作成する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestFontChange.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L475-L478">No.16 フォントを変更</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestStyleControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L483-L512">No.17 スタイルを変更する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestFocusControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L517-L540">No.18 フォーカス制御</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestDragDrop.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L545-L594">No.19 ドラッグ&ドロップを実装する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestChildWindow.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L599-L621">No.20 子ウィンドウ・領域を作る</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestInputMonitor.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L626-L659">No.21 入力状態を監視</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestImageButton.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L664-L667">No.22 画像ボタンを設置</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestLayoutAdjust.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L672-L695">No.23 レイアウトをスペースで調整</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestColumnLayout.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L700-L724">No.24 行や列を分割配置</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestModalDialog.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L729-L766">No.25 モーダルダイアログを表示</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestWindowPosition.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L771-L788">No.26 ウィンドウの位置・サイズ固定</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestClipboard.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L793-L829">No.27 データをコピー&ペースト</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestHelpNote.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L834-L850">No.28 ノートやヘルプウィンドウ</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestZoomPan.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L855-L896">No.29 ズーム/パン操作</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestReorderListBox.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L901-L938">No.30 順序入替リストボックス</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestCanvasDraw.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L943-L984">No.31 キャンバス描画</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestScrollSync.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L989-L1040">No.32 スクロール同期</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestTimelineBar.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1045-L1068">No.33 タイムライン（進捗付きバー）</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestFilterList.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1073-L1104">No.34 フィルタリングリスト</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestMultiSelectList.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1109-L1151">No.35 複数選択リストボックス</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestMultiLineInput.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1156-L1174">No.36 マルチライン入力</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestNumberStepper.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1179-L1198">No.37 数値ステッパー</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestColorEdit.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1203-L1222">No.38 色変更UI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestTransformWidget.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1227-L1275">No.39 回転/スケールUI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestPasswordInput.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1280-L1299">No.40 パスワード入力</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestOnHoverDetail.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1304-L1327">No.41 ホバー時詳細情報</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestDragSlider.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1332-L1351">No.42 物理スライダー操作</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestAudioControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1356-L1359">No.43 音声再生UI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestVideoEmbed.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1364-L1367">No.44 ビデオ埋め込みUI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestTagSelector.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1372-L1417">No.45 タグ選択UI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestHeaderCollapse.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1422-L1444">No.46 ヘッダーで折りたたみ</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestFlexibleTable.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1449-L1491">No.47 行数・カラム数変更可能テーブル</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestToolbar.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1496-L1500">No.48 ツールバー作成</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestLineGraph.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1507-L1547">No.49 折れ線グラフ</a><br>
      <span style="font-size:small;color:#555;">ImDrawListを使ってウィンドウ内に折れ線グラフを描画します。</span><br>
      <span style="font-size:small;color:#555;">カスタム描画の工夫によりグラフを実現しています。グラフ機能が存在するわけではありません。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestThemeToggle.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1554-L1595">No.50 テーマ切替</a><br>
      <span style="font-size:small;color:#555;">テーマ切り替え用メソッドのテストです。</span><br>
      <span style="font-size:small;color:#555;">ダーク・ライト・クラシック・カスタムテーマの4種類への切り替えを行います。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestCursorCustom.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1603-L1629">No.51 マウスカーソルカスタマイズ</a><br>
      <span style="font-size:small;color:#555;">マウスカーソルの形を変更する方法の例です。</span><br>
      <span style="font-size:small;color:#555;">ホバー時は左右リサイズ用のカーソル、通常時は矢印カーソルを表示します。</span><br>
      <span style="font-size:small;color:#555;">ImGui::SetMouseCursor()によりカーソル形状を変更しています。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestRowSortControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1637-L1706">No.52 行の並び替え</a><br>
      <span style="font-size:small;color:#555;">テーブルソート機能を利用したシンプルなサンプル。</span><br>
      <span style="font-size:small;color:#555;">ソート可能なテーブルで行データ（ID・名前・値）を表示します。</span><br>
      <span style="font-size:small;color:#555;">ヘッダークリックで昇順・降順の並び替えができます。</span><br>
    </td>
  </tr>
</table>


