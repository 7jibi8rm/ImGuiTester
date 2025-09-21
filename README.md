# ImGuiTester

[test](./Document/Document.md)

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

### 目次

<table>
  <tr>
    <td><img src="./Document/Image/TestSimpleWindow.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L118-L132">ウィンドウを作成する</a><br>
      <span style="font-size:small;color:#555;">シンプルなImGuiウィンドウを作成し、テキストを表示します。</span><br>
      <span style="font-size:small;color:#555;">ImGuiのウィンドウ生成・テキスト表示の基本的な使い方を確認できます。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestSimpleButton.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L139-L155">シンプルなImGuiウィンドウ内にボタンを表示するテスト関数。</a><br>
      <span style="font-size:small;color:#555;">ボタンを押すと「Buttonwasclicked!」というテキストが表示されます。</span><br>
      <span style="font-size:small;color:#555;">ImGuiのボタンウィジェットの基本的な使い方を確認できます。</span><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestShowText.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L159-L182">テキストを表示する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestCheckBox.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L187-L207">チェックボックスを作成する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestFloatSlider.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L212-L231">スライダーを操作する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestComboBox.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L236-L260">コンボボックスを作成</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestShowImage.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L265-L268">画像を表示する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestInputField.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L273-L294">ラベル付き入力フィールド</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestSimpleTable.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L299-L341">テーブルを表示する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestTreeNode.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L346-L383">ツリーノードを作成</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestShowTooltip.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L388-L409">ツールチップを表示</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestColorPicker.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L414-L435">カラー選択ダイアログを表示</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestProgressBar.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L440-L459">プログレスバーを表示</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestMenuBar.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L464-L502">メニューバーを作成する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestTabWidget.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L507-L537">タブを作成する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestFontChange.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L542-L545">フォントを変更</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestStyleControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L550-L579">スタイルを変更する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestFocusControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L584-L607">フォーカス制御</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestDragDrop.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L612-L661">ドラッグ&ドロップを実装する</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestChildWindow.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L666-L688">子ウィンドウ・領域を作る</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestInputMonitor.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L693-L726">入力状態を監視</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestImageButton.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L731-L734">画像ボタンを設置</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestLayoutAdjust.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L739-L762">レイアウトをスペースで調整</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestColumnLayout.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L767-L791">行や列を分割配置</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestModalDialog.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L796-L833">モーダルダイアログを表示</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestWindowPosition.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L838-L855">ウィンドウの位置・サイズ固定</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestClipboard.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L860-L896">データをコピー&ペースト</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestHelpNote.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L901-L917">ノートやヘルプウィンドウ</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestZoomPan.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L922-L963">ズーム/パン操作</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestReorderListBox.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L968-L1005">順序入替リストボックス</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestCanvasDraw.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1010-L1051">キャンバス描画</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestScrollSync.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1056-L1107">スクロール同期</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestTimelineBar.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1112-L1135">タイムライン（進捗付きバー）</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestFilterList.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1140-L1171">フィルタリングリスト</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestMultiSelectList.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1176-L1218">複数選択リストボックス</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestMultiLineInput.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1223-L1241">マルチライン入力</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestNumberStepper.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1246-L1265">数値ステッパー</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestColorEdit.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1270-L1289">色変更UI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestCancelDialog.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1294-L1297">キャンセル操作</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestTransformWidget.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1302-L1305">回転/スケールUI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestPanelLayout.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1310-L1313">パネル型UI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestCustomImage.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1318-L1321">画像描画カスタマイズ</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestAddSubwindow.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1326-L1329">サブウィンドウ追加</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestScreenShot.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1334-L1337">画面キャプチャ</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestPasswordInput.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1342-L1345">パスワード入力</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestNotification.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1350-L1353">イベント通知（トースト）</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestAccessibility.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1358-L1361">アクセシビリティ</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestOnHoverDetail.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1366-L1369">ホバー時詳細情報</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestBatchSwitch.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1374-L1377">バッチ切替UI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestLogWindow.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1382-L1385">ログ出力ウィンドウ</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestDragSlider.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1390-L1393">物理スライダー操作</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestMaterialEdit.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1398-L1401">マテリアル調整ウィンドウ</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestGPUAccelUse.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1406-L1409">GPUアクセラレーション使用</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestAudioControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1414-L1417">音声再生UI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestVideoEmbed.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1422-L1425">ビデオ埋め込みUI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestShowShortcuts.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1430-L1433">ショートカット表示</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestTagSelector.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1438-L1441">タグ選択UI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestHeaderCollapse.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1446-L1449">ヘッダーで折りたたみ</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestCrossPlatformUI.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1454-L1457">クロスプラットフォームUI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestBadgeNotify.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1462-L1465">通知バッジ表示</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestFlexibleTable.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1470-L1473">行数・カラム数変更可能テーブル</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestToolbar.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1478-L1481">ツールバー作成</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestChartEditor.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1486-L1489">インタラクティブチャート編集</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestThemeToggle.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1494-L1497">テーマ切替（複数テーマ対応）</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestResizableWin.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1502-L1505">リサイズ対応ウィンドウ</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestCursorCustom.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1510-L1513">マウスカーソルカスタマイズ</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestVisualEffect.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1518-L1521">ビジュアルエフェクト追加</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestRowSortControl.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1526-L1529">行の並び替え</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestMemoryStats.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1534-L1537">メモリ使用状況表示</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestInputCompletion.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1542-L1545">入力補完UI</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestValidation.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1550-L1553">バリデーション（値チェック）</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestConfigIO.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1558-L1561">設定ファイルの保存/読込</a><br>
    </td>
  </tr>
  <tr>
    <td><img src="./Document/Image/TestUndoRedo.png" width="128" height="128" /></td>
    <td style="vertical-align:middle; padding-left:10px;">
      <a href="https://github.com/7jibi8rm/ImGuiTester/blob/master/Source/ImGuiTester/Private/ImGuiActor.cpp#L1566-L1569">Undo/Redo対応UI</a><br>
    </td>
  </tr>
</table>
