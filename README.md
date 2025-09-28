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
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L71-L98">No.3 様々なテキスト表示</a><br>
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
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L200-L215">No.7 テクスチャ表示</a><br>
      <span style="font-size:small;color:#555;">コンテンツブラウザの画像を参照して表示する例です。</span><br>
      <span style="font-size:small;color:#555;">外部データ利用にはFImGuiModuleが必要。詳細はAImGuiActor::BeginPlayを確認。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestInputField.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L222-L248">No.8 ラベル付き入力フィールド</a><br>
      <span style="font-size:small;color:#555;">ユーザー入力可能なテキストフィールドを表示する例です。</span><br>
      <span style="font-size:small;color:#555;">３つの入力フィールドを配置、通常・数字のみ・読み取り専用の３種類。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestSimpleTable.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L255-L295">No.9 テーブル</a><br>
      <span style="font-size:small;color:#555;">テーブル表示の例です。</span><br>
      <span style="font-size:small;color:#555;">3列5行のテーブルを作成し、各セルに行列番号を表示します。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestTreeNode.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L302-L335">No.10 ツリーノード</a><br>
      <span style="font-size:small;color:#555;">ツリーノード表示の例です。</span><br>
      <span style="font-size:small;color:#555;">親ツリーと２つの子ツリー配置。ツリーノードは階層的なデータ構造の表現が可能。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestShowTooltip.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L342-L363">No.11 ツールチップ表示</a><br>
      <span style="font-size:small;color:#555;">ツールチップを表示させる例です。</span><br>
      <span style="font-size:small;color:#555;">アイテムにマウスホバーでツールチップを表示。別名ポップアップヒント。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestColorPicker.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L368-L389">No.12 カラー選択ダイアログを表示</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestProgressBar.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L394-L413">No.13 プログレスバーを表示</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestMenuBar.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L418-L456">No.14 メニューバーを作成する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestTabWidget.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L461-L491">No.15 タブを作成する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestStyleControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L497-L526">No.16 スタイルを変更する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestFocusControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L531-L554">No.17 フォーカス制御</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestDragDrop.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L559-L608">No.18 ドラッグ&ドロップを実装する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestChildWindow.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L613-L635">No.19 子ウィンドウ・領域を作る</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestInputMonitor.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L640-L673">No.20 入力状態を監視</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestImageButton.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L678-L681">No.21 画像ボタンを設置</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestLayoutAdjust.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L686-L709">No.22 レイアウトをスペースで調整</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestColumnLayout.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L714-L738">No.23 行や列を分割配置</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestModalDialog.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L743-L780">No.24 モーダルダイアログを表示</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestWindowPosition.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L785-L802">No.25 ウィンドウの位置・サイズ固定</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestClipboard.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L807-L843">No.26 データをコピー&ペースト</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestHelpNote.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L848-L864">No.27 ノートやヘルプウィンドウ</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestZoomPan.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L869-L910">No.28 ズーム/パン操作</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestReorderListBox.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L915-L952">No.29 順序入替リストボックス</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestCanvasDraw.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L957-L998">No.30 キャンバス描画</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestScrollSync.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1003-L1054">No.31 スクロール同期</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestTimelineBar.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1059-L1082">No.32 タイムライン（進捗付きバー）</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestFilterList.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1087-L1118">No.33 フィルタリングリスト</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestMultiSelectList.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1123-L1165">No.34 複数選択リストボックス</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestMultiLineInput.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1170-L1188">No.35 マルチライン入力</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestNumberStepper.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1193-L1212">No.36 数値ステッパー</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestColorEdit.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1217-L1236">No.37 色変更UI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestTransformWidget.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1241-L1289">No.38 回転/スケールUI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestPasswordInput.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1294-L1313">No.39 パスワード入力</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestOnHoverDetail.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1318-L1341">No.40 ホバー時詳細情報</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestDragSlider.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1346-L1365">No.41 物理スライダー操作</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestAudioControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1370-L1373">No.42 音声再生UI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestVideoEmbed.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1378-L1381">No.43 ビデオ埋め込みUI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestTagSelector.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1386-L1431">No.44 タグ選択UI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestHeaderCollapse.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1436-L1458">No.45 ヘッダーで折りたたみ</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestFlexibleTable.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1463-L1505">No.46 行数・カラム数変更可能テーブル</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestToolbar.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1510-L1514">No.47 ツールバー作成</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestLineGraph.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1521-L1561">No.48 折れ線グラフ</a><br>
      <span style="font-size:small;color:#555;">ImDrawListを使ってウィンドウ内に折れ線グラフを描画します。</span><br>
      <span style="font-size:small;color:#555;">カスタム描画の工夫によりグラフを実現しています。グラフ機能が存在するわけではありません。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestThemeToggle.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1568-L1609">No.49 テーマ切替</a><br>
      <span style="font-size:small;color:#555;">テーマ切り替え用メソッドのテストです。</span><br>
      <span style="font-size:small;color:#555;">ダーク・ライト・クラシック・カスタムテーマの4種類への切り替えを行います。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestCursorCustom.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1617-L1643">No.50 マウスカーソルカスタマイズ</a><br>
      <span style="font-size:small;color:#555;">マウスカーソルの形を変更する方法の例です。</span><br>
      <span style="font-size:small;color:#555;">ホバー時は左右リサイズ用のカーソル、通常時は矢印カーソルを表示します。</span><br>
      <span style="font-size:small;color:#555;">ImGui::SetMouseCursor()によりカーソル形状を変更しています。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Image/TestRowSortControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1651-L1720">No.51 行の並び替え</a><br>
      <span style="font-size:small;color:#555;">テーブルソート機能を利用したシンプルなサンプル。</span><br>
      <span style="font-size:small;color:#555;">ソート可能なテーブルで行データ（ID・名前・値）を表示します。</span><br>
      <span style="font-size:small;color:#555;">ヘッダークリックで昇順・降順の並び替えができます。</span><br>
    </td>
  </tr>
</table>


