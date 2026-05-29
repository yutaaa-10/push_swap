*This project has been created as part of the 42 curriculum by yukurosa,hdobashi.*

# push_swap

## 概要（Description）

push_swapは、与えられた整数列を限られたoperationのみを用いて昇順に並べ替えるアルゴリズム課題です。

このプロジェクトでは、単にソートを実装するだけではなく、
どのアルゴリズムを選択するべきか
どの程度の計算量になるのか
どのようにデータ構造を扱うべきか

を深く理解することが求められます。

特に、以下の内容を実践的に学ぶことを目的としています。
```text
ソートアルゴリズムの設計と実装
計算量（O(n²), O(n√n), O(n log n)）の理解
linked list を用いたstack構造の操作
rotate / reverse rotate を用いたデータ移動
限られたoperation内で最適化を行う考え方
入力状態に応じたアルゴリズム選択
```
また、push_swapでは「正しく並べること」だけではなく、いかに少ないoperation数で並べるかが重要になるため、アルゴリズムの効率性や戦略設計についても学ぶことができます。

### チーム貢献

- 両者で議論をしながら、大きな作業は以下のように役割分担をし、細かな作業は確認をしあいながら実装しました。
- yukurosa
    - 主に、operation,bench,simple_sortを担当
- hdobashi
    - 主に、medium_sort,complex-sort,listを担当

## 手順（Instructions）

### Makefile

* 静的ライブラリを含めてコンパイル

```bash
make
```

* オブジェクトファイル（`.o`）を削除

```bash
make clean
```

* 実行ファイル・オブジェクトファイルをすべて削除

```bash
make fclean
```

* プロジェクトを完全に再構築

```bash
make re
```

---

### 使用例

```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG
```

---

### 利用可能なstrategy

```bash
--simple
--medium
--complex
--adaptive
```

例：

```bash
./push_swap --simple 3 2 1
./push_swap --medium 3 2 1
./push_swap --complex 3 2 1
./push_swap --adaptive 3 2 1
```

---

### benchmark mode

benchmark情報を表示する場合：

```bash
./push_swap --bench --adaptive 3 2 1
```

以下の情報が stderr に出力されます。

* disorder score
* 使用されたstrategy
* theoretical complexity
* total operations
* 各operationの実行回数





## 詳細とアルゴリズム

## 詳細とアルゴリズム

本プロジェクトでは、入力された数列の状態に応じて、複数のソート戦略を使い分ける。

使用する主な戦略は以下の3つである。

| Strategy | Algorithm                 | Complexity |
| -------- | ------------------------- | ---------- |
| simple   | Selection sort adaptation | O(n²)      |
| medium   | Chunk sort                | O(n√n)     |
| complex  | Radix sort adaptation     | O(n log n) |

---

### Disorder score

`--adaptive` が指定された場合、または strategy が指定されなかった場合は、入力の乱れ具合を `disorder score` として計算する。

この実装では、数列内のすべての組み合わせを確認し、

```text
前にある値 > 後ろにある値
```

となる組を inversion として数える。

```text
disorder = inversion_count / total_pairs
```

disorder は `0.0` から `1.0` の値になる。

* `0.0` に近いほど、すでに昇順に近い
* `1.0` に近いほど、降順または大きく乱れている

---

### Threshold rationale

adaptive mode では、以下の閾値で strategy を選択する。

```text
disorder < 0.20          -> simple
0.20 <= disorder < 0.50  -> medium
0.50 <= disorder         -> complex
```

この閾値は、入力の乱れ具合に応じて、必要なソート戦略の強さを変えるために設定している。

#### simple を選ぶ理由

disorder が低い場合、数列はある程度整列されている。

この場合、大きく並べ替えるよりも、局所的に最小値を取り出していく simple algorithm の方が無駄な操作が少なくなる可能性がある。

#### medium を選ぶ理由

disorder が中程度の場合、1つずつ最小値を探すと operation 数が増えやすい。

そのため、index を一定範囲ごとの chunk に分け、範囲単位で整理する chunk sort を使用する。

#### complex を選ぶ理由

disorder が高い場合、入力は大きく乱れている。

この場合、局所的な修正では operation 数が増えやすいため、index の bit を利用して機械的に分類する radix sort を使用する。

---

### Simple strategy: Selection sort adaptation

simple strategy では、selection sort を push_swap 用に応用する。

処理の流れは以下の通り。

```text
1. stack a から最小値を探す
2. ra または rra で最小値をtopへ移動する
3. pb で stack b へ送る
4. stack a が空になるまで繰り返す
5. pa で stack b から stack a へ戻す
```

この方法では、毎回 stack 内を走査して最小値を探すため、探索に O(n) かかる。

これを n 回繰り返すため、operation model 上の上限は O(n²) とみなす。

Space complexity は、追加の stack b を使用するため O(n) である。

---

### Medium strategy: Chunk sort

medium strategy では、index を chunk に分割して処理する。

座標圧縮により、各 node は以下を持つ。

```text
value = 元の値
index = 昇順に並べたときの順位
```

Chunk sort では value ではなく index を使う。

処理の流れは以下の通り。

```text
1. n に対して chunk_size ≒ √n を決める
2. index の範囲を chunk ごとに分ける
3. 現在の chunk に含まれる値を stack b へ送る
4. stack b 内では、小さい index を rb で下へ送る
5. すべて stack b に送った後、最大 index を探して stack a に戻す
```

chunk を使うことで、selection sort のように1つずつ値を探すのではなく、範囲単位で値を処理できる。

chunk 数と chunk size をともに √n 程度にすることで、探索と整理のバランスを取っている。

このため、operation model 上の上限は O(n√n) とみなす。

Space complexity は、追加の stack b を使用するため O(n) である。

---

### Complex strategy: Radix sort adaptation

complex strategy では、index に対して radix sort を行う。

元の値は負数や大きな値を含む可能性があるため、そのまま bit 処理を行わず、座標圧縮された index を使用する。

処理の流れは以下の通り。

```text
1. 最大 index に必要な bit 数を求める
2. 下位 bit から順に確認する
3. 対象 bit が 0 なら pb
4. 対象 bit が 1 なら ra
5. stack b に送った要素を pa で stack a に戻す
6. 全bit分繰り返す
```

index は `0` から `n - 1` の範囲になるため、最大 bit 数はおよそ log n である。

各 bit に対して n 個の要素を処理するため、operation model 上の上限は O(n log n) とみなす。

Space complexity は、追加の stack b を使用するため O(n) である。

---

### Benchmark mode

`--bench` が指定された場合、ソート後に以下の情報を stderr に出力する。

```text
- computed disorder
- strategy name
- theoretical complexity
- total operation count
- count of each operation type
```

benchmark 情報は operation 出力と混ざらないように、stdout ではなく stderr に出力する。

通常の push_swap operation は stdout に出力される。

## 参考資料　（Resources）


### 参考文献

- 42 push_swap資料
- 工業大学生ももやまのうさぎ塾　プログラム計算量、オーダー表記O()の求め方
- ソートコード探検隊　選択ソート:アルゴリズム
- Qiita

### 参考文献 URL

- https://www.codereading.com/algo_and_ds/algo/selection_sort.html
- https://qiita.com/MoriP-K/items/54ee96dc634148cf40a8
- https://e-words.jp/w/%E5%9F%BA%E6%95%B0%E3%82%BD%E3%83%BC%E3%83%88.html
- https://www.momoyama-usagi.com/entry/calc-order#gsc.tab=0

## AIの使い方

AIは以下の目的で使用。：
- 計算量の理解
- 実装案の検討
- デバッグに関する議論
- Makefileの構造の理解