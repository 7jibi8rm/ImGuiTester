# ImGuiTester

## 概要
ImGuiTesterは、[Dear ImGui](https://github.com/ocornut/imgui) を利用したデバッグや各種テスト機能を実装・検証するためのサンプル集です。  

## 特徴
- Unreal Engine 5.5 使用
- ImGuiを利用したリアルタイムUIテスト
- テストケースの追加・切り替えが容易

## 使い方

### 1. プロジェクトのビルド
通常のUnreal Engineプロジェクトと同様に、Visual Studio 2022でプロジェクトを開き、ビルドしてください。

### 2. ImGuiプラグインの有効化
`Plugins/ImGui` ディレクトリにImGuiのサードパーティ実装が含まれています。  
プロジェクト設定でImGuiプラグインが有効になっていることを確認してください。

### 3. アクターの配置
`AImGuiActor` をレベルに配置することで、ゲーム実行中にImGuiベースのデバッグUIが利用可能になります。

### 4. テストケースの追加
`AImGuiActor` クラスの `ETestCase` 列挙体と `TestCases` 配列に新しいテストケースを追加することで、独自のImGuiテストUIを拡張できます。

### 5. 実行
エディタまたはパッケージ化したアプリケーションでレベルを再生し、ImGuiウィンドウが表示されることを確認してください。
